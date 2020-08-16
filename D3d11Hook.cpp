// DX11Hook.cpp
#include "stdafx.h"
#include "D3d11Hook.h"
#include "Hooking/Hook.h"
#include "Global.h"

DX11Hook g_D3DHook;

//texture declariations
std::unordered_map<int, std::wstring> CreateTextureArray;
struct ScriptTex { DXTEXTURE2D tex; int id; };
struct ReloadTex { int id; std::wstring name; };
std::vector<ScriptTex> DrawTextureArray;
std::vector<ReloadTex> ReloadArray;
int DrawTextureArrayIndex = 0;
static Vector2 windowSize;


template <typename T>
inline void SafeRelease(T *&p)
{
	if (nullptr != p)
	{
		p->Release();
		p = nullptr;
	}
}

//====================================================================================================================================================================
// SwapChain Vtable Lookup
LRESULT CALLBACK DXGIMsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hwnd, uMsg, wParam, lParam); }
void** GetSwapChainVtable()
{
	WNDCLASSEXA wc = { sizeof(WNDCLASSEX), CS_CLASSDC, DXGIMsgProc, 0L, 0L, GetModuleHandleA(NULL), NULL, NULL, NULL, NULL, "DX", NULL };
	RegisterClassExA(&wc);
	HWND hWnd = CreateWindowA("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, NULL, NULL, wc.hInstance, NULL);
	//Temporary device pointers
	ID3D11Device* pTempDevice = nullptr;
	ID3D11DeviceContext* pTempContext = nullptr;
	IDXGISwapChain* pTempSwapChain = nullptr;

	DXGI_SWAP_CHAIN_DESC SwapChainDesc;
	ZeroMemory(&SwapChainDesc, sizeof(SwapChainDesc));

	SwapChainDesc.BufferCount = 1;
	SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	SwapChainDesc.OutputWindow = hWnd;
	SwapChainDesc.SampleDesc.Count = 1;
	SwapChainDesc.Windowed = ((GetWindowLongPtr(hWnd, GWL_STYLE) & WS_POPUP) != 0) ? false : true;
	SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	D3D_FEATURE_LEVEL requestedLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1 };
	D3D_FEATURE_LEVEL obtainedLevel;
	UINT createFlags = 0;
	// This flag gives you some quite wonderful debug text. Not wonderful for performance, though!
	//createFlags |= D3D11_CREATE_DEVICE_DEBUG;
	if (FAILED(D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		createFlags,
		requestedLevels,
		sizeof(requestedLevels) / sizeof(D3D_FEATURE_LEVEL),
		D3D11_SDK_VERSION,
		&SwapChainDesc,
		&pTempSwapChain,
		&pTempDevice,
		&obtainedLevel,
		&pTempContext)))
	{
		MessageBox(hWnd, L"Failed to create directX device and swapchain!", L"Error", MB_ICONERROR);
		return NULL;
	}

	void** pVtable = *(void***)pTempSwapChain;

	//Unload temporary devices
	pTempSwapChain->Release();
	pTempContext->Release();
	pTempDevice->Release();
	DestroyWindow(hWnd);
	return pVtable;
}

//====================================================================================================================================================================
// Function hook stubs

// IDXGISwapChain::Present()
PVOID m_SwapChainPresentOrig = NULL;
DETOUR_TRAMPOLINE* m_SwapChainPresentTrampoline;
LPVOID SwapChainPresentHook(IDXGISwapChain *chain, UINT SyncInterval, UINT Flags)
{
	g_D3DHook.SetSwapChain(chain);
	g_D3DHook.InitializeDevices();
	g_D3DHook.Draw();
    if (g_D3DHook.GetSwapChain() == nullptr)
	{
		g_D3DHook.SetSwapChain(chain);
		g_D3DHook.InitializeDevices();
		Log::Msg("Get SwapChain == nullptr");
	}
	else
	{
		if (!g_D3DHook.IsResizing()) g_D3DHook.Draw();
		else g_D3DHook.SetResizing(windowSize.x != g_D3DHook.GetResolution().x && windowSize.y != g_D3DHook.GetResolution().y);
		
		Log::Msg("Get SwapChain != nullptr");
	}
	Log::Msg("SwapChainHook End");
	return reinterpret_cast<decltype(&SwapChainPresentHook)>(m_SwapChainPresentTrampoline)(chain, SyncInterval, Flags);
}

// IDXGISwapChain::ResizeBuffers()
PVOID m_SwapChainResizeBuffersOrig = NULL;
DETOUR_TRAMPOLINE* m_SwapChainResizeBuffersTrampoline;
LPVOID SwapChainResizeBuffersHook(IDXGISwapChain *chain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	g_D3DHook.SetResizing(true);

	windowSize = Vector2((float)Width, (float)Width);

	Log::Msg("Screen Resized new Resoloution is %u x %u", windowSize.x, windowSize.y);

	return reinterpret_cast<decltype(&SwapChainResizeBuffersHook)>(m_SwapChainResizeBuffersTrampoline)(chain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

//====================================================================================================================================================================
//Ensure SwapChain Vtable and perform function hooks

enum eSwapChainVtableIndices : int
{
	SC_QUERYINTERFACE,
	SC_ADDREF,
	SC_RELEASE,
	SC_SETPRIVATEDATA,
	SC_SETPRIVATEDATAINTERFACE,
	SC_GETPRIVATEDATA,
	SC_GETPARENT,
	SC_GETDEVICE,
	SC_PRESENT,
	SC_GETBUFFER,
	SC_SETFULLSCREENSTATE,
	SC_GETFULLSCREENSTATE,
	SC_GETDESC,
	SC_RESIZEBUFFERS,
	SC_RESIZETARGET,
	SC_GETCONTAININGOUTPUT,
	SC_GETFRAMESTATISTICS,
	SC_GETLASTPRESENTCOUNT,
};

bool DX11Hook::InitializeHooks()
{
	HMODULE hD3D11DLL = 0;
	do
	{
		hD3D11DLL = GetModuleHandleA("d3d11.dll");
		Sleep(100);
	} while (!hD3D11DLL);

	if (auto pVtable = GetSwapChainVtable())
	{
		m_SwapChainPresentOrig = pVtable[SC_PRESENT];
		m_SwapChainPresentTrampoline = Hook::CreateDetour(&m_SwapChainPresentOrig, &SwapChainPresentHook, "D3D11SwapChainPresent");

		m_SwapChainResizeBuffersOrig = pVtable[SC_RESIZEBUFFERS];
		m_SwapChainResizeBuffersTrampoline = Hook::CreateDetour(&m_SwapChainResizeBuffersOrig, &SwapChainResizeBuffersHook, "D3D11SwapChainResizeBuffers");

		return true;
	}

	return false;
}

//====================================================================================================================================================================
//Device Initialization and drawing functions

void DX11Hook::InitializeDevices()
{
	Log::Msg("DX Init Devices");
	if (m_pSwapchain)
	{
		//get device and context
		if (SUCCEEDED(m_pSwapchain->GetDevice(__uuidof(ID3D11Device), (void **)&m_pDevice)))
		{
			m_pSwapchain->GetDevice(__uuidof(m_pDevice), (void**)&m_pDevice);
			m_pDevice->GetImmediateContext(&m_pContext);

			m_pCommonState.reset(new CommonStates(m_pDevice));
			m_pSpriteBatch.reset(new SpriteBatch(m_pContext));
			m_pBatch.reset(new PrimitiveBatch<VertexPositionColor>(m_pContext));
			m_stateSaver.reset(new StateSaver());
		}

		// use the back buffer address to create the render target
		if (SUCCEEDED(m_pSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_pRenderTargetTexture)))
		{
			m_pDevice->CreateRenderTargetView(m_pRenderTargetTexture, NULL, &m_pRenderTargetView);
			m_pRenderTargetTexture->Release();
			ReloadTextures();
		}

		windowSize = GetResolution();
	}
}

void DX11Hook::Draw()
{
	Log::Msg("DX Draw");
	if (m_pSwapchain)
	{
		CreateTextures();

		if (!DrawTextureArray.empty())
		{
			m_pSpriteBatch->Begin(SpriteSortMode::SpriteSortMode_BackToFront, m_pCommonState->NonPremultiplied());
			m_restoreState = m_stateSaver->saveCurrentState(m_pContext);
			m_pBatch->Begin();

			for (auto& t : DrawTextureArray) {
                if (t.tex.bEnabled) t.tex.Draw(*m_pSpriteBatch);
            }

			m_pBatch->End();
			m_pSpriteBatch->End();

			if (m_restoreState)
                m_stateSaver->restoreSavedState();
		}

		for (auto & function : m_PresentCallbacks) {
			m_restoreState = m_stateSaver->saveCurrentState(m_pContext);
			function(m_pSwapchain);
			if (m_restoreState)
				m_stateSaver->restoreSavedState();
		}
	}
}

Vector2 DX11Hook::GetResolution()
{
	D3D11_VIEWPORT vp;
	UINT nvp = 1;
	m_pContext->RSGetViewports(&nvp, &vp);
	return Vector2(vp.Width, vp.Height);
}

//====================================================================================================================================================================
//Custom Texture loading via WIC

void DX11Hook::CreateTextures()
{
	for (auto it = CreateTextureArray.begin(); it != CreateTextureArray.end(); ++it)
	{
		DXTEXTURE2D t;
		if (SUCCEEDED(CreateWICTextureFromFile(m_pDevice, it->second.c_str(), t.resource.GetAddressOf(), t.view.GetAddressOf(), 0)))
		{
			t.resource.As(&t.texture);
			t.texture->GetDesc(&t.desc);
			ScriptTex Temptex;
			Temptex.id = it->first;
			Temptex.tex = t;
			DrawTextureArray.push_back(Temptex);
			ReloadTex tempR;
			tempR.id = it->first;
			tempR.name = it->second;
			ReloadArray.push_back(tempR);
			Log::Msg("DX Created Textures");
		}
		else
		{
			std::string string = wstr_to_str(it->second);
			Log::Msg("Unable to Load Texture %s = %d", string.c_str(), it->first);
		}
	}

	CreateTextureArray.clear();
}

void DX11Hook::ReloadTextures()
{
	for (auto it : ReloadArray)
	{
		DXTEXTURE2D t;
		if (SUCCEEDED(CreateWICTextureFromFile(m_pDevice, it.name.c_str(), t.resource.GetAddressOf(), t.view.GetAddressOf(), 0)))
		{
			t.resource.As(&t.texture);
			t.texture->GetDesc(&t.desc);
			ScriptTex Temptex;
			Temptex.id = it.id;
			Temptex.tex = t;
			DrawTextureArray.push_back(Temptex);
			Log::Msg("DX Reloaded Textures");
		}
		else
		{
			std::string string = wstr_to_str(it.name);
			Log::Msg("Unable to Load Texture %s = %d", string.c_str(), it.id);
		}
	}
}

int DX11Hook::CreateTexture(const char *texFileName)
{
	// convert the filename from UTF-8...
	std::string fileNameStr = texFileName;
	std::wstring passedFileName = str_to_wstr(fileNameStr);
	std::wstring retFileName = passedFileName;

	// then, try finding the requested file.
	bool found = false;

	// absolute path
	if (fileNameStr[1] == L':' || fileNameStr[0] == '\\')
	{
		Log::Msg("File found %s", fileNameStr.c_str());
		found = true;
	}

	// not found at all?
	if (!found)
	{
		Log::Msg("File not found %s", fileNameStr.c_str());
		return -1;
	}

	

	DrawTextureArrayIndex++;
	CreateTextureArray[DrawTextureArrayIndex] = retFileName;
	return DrawTextureArrayIndex;
}

void DX11Hook::DrawTexture(int id, int index, int level, int time, float sizeX, float sizeY, float centerX, float centerY, float posX, float posY, float rotation, float screenHeightScaleFactor, float r, float g, float b, float a)
{
	for (auto& t : DrawTextureArray)
	{
		if (t.id == id)
		{
			t.tex.SetProperties(id, index, level, time, sizeX, sizeY, centerX, centerY, posX, posY, rotation, screenHeightScaleFactor, r, g, b, a);
			Log::Msg("DX Draw Texture");
		}
	}
}

//====================================================================================================================================================================
//State Saver Class

// Construct
StateSaver::StateSaver() :
	m_savedState(false),
	m_featureLevel(D3D_FEATURE_LEVEL_11_0),
	m_pContext(NULL),
	m_primitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED),
	m_pInputLayout(NULL),
	m_pBlendState(NULL),
	m_sampleMask(0xffffffff),
	m_pDepthStencilState(NULL),
	m_stencilRef(0),
	m_pRasterizerState(NULL),
	m_pPSSRV(NULL),
	m_pSamplerState(NULL),
	m_pVS(NULL),
	m_numVSClassInstances(0),
	m_pVSConstantBuffer(NULL),
	m_pGS(NULL),
	m_numGSClassInstances(0),
	m_pGSConstantBuffer(NULL),
	m_pGSSRV(NULL),
	m_pPS(NULL),
	m_numPSClassInstances(0),
	m_pHS(NULL),
	m_numHSClassInstances(0),
	m_pDS(NULL),
	m_numDSClassInstances(0),
	m_pVB(NULL),
	m_vertexStride(0),
	m_vertexOffset(0),
	m_pIndexBuffer(NULL),
	m_indexFormat(DXGI_FORMAT_UNKNOWN),
	m_indexOffset(0)
{
	for (int i = 0; i < 4; ++i)
	{
		m_blendFactor[i] = 0.0f;
	}
	for (int i = 0; i < 256; ++i)
	{
		m_pVSClassInstances[i] = NULL;
		m_pGSClassInstances[i] = NULL;
		m_pPSClassInstances[i] = NULL;
		m_pHSClassInstances[i] = NULL;
		m_pDSClassInstances[i] = NULL;
	}
}


// Destruct
StateSaver::~StateSaver()
{
	releaseSavedState();
}


// Save all states that are changed by the font-wrapper when drawing a string
bool StateSaver::saveCurrentState(ID3D11DeviceContext *pContext)
{
	if (m_savedState) releaseSavedState();
	if (pContext == NULL) return false;

	ID3D11Device *pDevice;
	pContext->GetDevice(&pDevice);
	if (pDevice != NULL) {
		m_featureLevel = pDevice->GetFeatureLevel();
		pDevice->Release();
	}

	pContext->AddRef();
	m_pContext = pContext;

	m_pContext->IAGetPrimitiveTopology(&m_primitiveTopology);
	m_pContext->IAGetInputLayout(&m_pInputLayout);

	m_pContext->OMGetBlendState(&m_pBlendState, m_blendFactor, &m_sampleMask);
	m_pContext->OMGetDepthStencilState(&m_pDepthStencilState, &m_stencilRef);

	m_pContext->RSGetState(&m_pRasterizerState);

	m_numVSClassInstances = 256;
	m_pContext->VSGetShader(&m_pVS, m_pVSClassInstances, &m_numVSClassInstances);
	m_pContext->VSGetConstantBuffers(0, 1, &m_pVSConstantBuffer);

	m_numPSClassInstances = 256;
	m_pContext->PSGetShader(&m_pPS, m_pPSClassInstances, &m_numPSClassInstances);
	m_pContext->PSGetShaderResources(0, 1, &m_pPSSRV);
	pContext->PSGetSamplers(0, 1, &m_pSamplerState);

	if (m_featureLevel >= D3D_FEATURE_LEVEL_10_0)
	{
		m_numGSClassInstances = 256;
		m_pContext->GSGetShader(&m_pGS, m_pGSClassInstances, &m_numGSClassInstances);
		m_pContext->GSGetConstantBuffers(0, 1, &m_pGSConstantBuffer);

		m_pContext->GSGetShaderResources(0, 1, &m_pGSSRV);

		if (m_featureLevel >= D3D_FEATURE_LEVEL_11_0)
		{
			m_numHSClassInstances = 256;
			m_pContext->HSGetShader(&m_pHS, m_pHSClassInstances, &m_numHSClassInstances);

			m_numDSClassInstances = 256;
			m_pContext->DSGetShader(&m_pDS, m_pDSClassInstances, &m_numDSClassInstances);
		}
	}

	m_pContext->IAGetVertexBuffers(0, 1, &m_pVB, &m_vertexStride, &m_vertexOffset);

	m_pContext->IAGetIndexBuffer(&m_pIndexBuffer, &m_indexFormat, &m_indexOffset);

	m_savedState = true;

	return true;
}


// Restore state
bool StateSaver::restoreSavedState()
{
	if (!m_savedState) return false;

	m_pContext->IASetPrimitiveTopology(m_primitiveTopology);
	m_pContext->IASetInputLayout(m_pInputLayout);

	m_pContext->OMSetBlendState(m_pBlendState, m_blendFactor, m_sampleMask);
	m_pContext->OMSetDepthStencilState(m_pDepthStencilState, m_stencilRef);

	m_pContext->RSSetState(m_pRasterizerState);

	m_pContext->VSSetShader(m_pVS, m_pVSClassInstances, m_numVSClassInstances);
	m_pContext->VSSetConstantBuffers(0, 1, &m_pVSConstantBuffer);

	m_pContext->PSSetShader(m_pPS, m_pPSClassInstances, m_numPSClassInstances);
	m_pContext->PSSetShaderResources(0, 1, &m_pPSSRV);
	m_pContext->PSSetSamplers(0, 1, &m_pSamplerState);

	if (m_featureLevel >= D3D_FEATURE_LEVEL_10_0)
	{
		m_pContext->GSSetShader(m_pGS, m_pGSClassInstances, m_numGSClassInstances);
		m_pContext->GSSetConstantBuffers(0, 1, &m_pGSConstantBuffer);

		m_pContext->GSSetShaderResources(0, 1, &m_pGSSRV);

		if (m_featureLevel >= D3D_FEATURE_LEVEL_11_0)
		{
			m_pContext->HSSetShader(m_pHS, m_pHSClassInstances, m_numHSClassInstances);

			m_pContext->DSSetShader(m_pDS, m_pDSClassInstances, m_numDSClassInstances);
		}
	}

	m_pContext->IASetVertexBuffers(0, 1, &m_pVB, &m_vertexStride, &m_vertexOffset);

	m_pContext->IASetIndexBuffer(m_pIndexBuffer, m_indexFormat, m_indexOffset);

	return true;
}


// Release state
void StateSaver::releaseSavedState()
{
	m_primitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
	SafeRelease(m_pInputLayout);
	SafeRelease(m_pBlendState);
	for (int i = 0; i < 4; ++i)
		m_blendFactor[i] = 0.0f;
	m_sampleMask = 0xffffffff;
	SafeRelease(m_pDepthStencilState);
	m_stencilRef = 0;
	SafeRelease(m_pRasterizerState);
	SafeRelease(m_pPSSRV);
	SafeRelease(m_pSamplerState);
	SafeRelease(m_pVS);
	for (UINT i = 0; i < m_numVSClassInstances; ++i)
		SafeRelease(m_pVSClassInstances[i]);
	m_numVSClassInstances = 0;
	SafeRelease(m_pVSConstantBuffer);
	SafeRelease(m_pGS);
	for (UINT i = 0; i < m_numGSClassInstances; ++i)
		SafeRelease(m_pGSClassInstances[i]);
	m_numGSClassInstances = 0;
	SafeRelease(m_pGSConstantBuffer);
	SafeRelease(m_pGSSRV);
	SafeRelease(m_pPS);
	for (UINT i = 0; i < m_numPSClassInstances; ++i)
		SafeRelease(m_pPSClassInstances[i]);
	m_numPSClassInstances = 0;
	SafeRelease(m_pHS);
	for (UINT i = 0; i < m_numHSClassInstances; ++i)
		SafeRelease(m_pHSClassInstances[i]);
	m_numHSClassInstances = 0;
	SafeRelease(m_pDS);
	for (UINT i = 0; i < m_numDSClassInstances; ++i)
		SafeRelease(m_pDSClassInstances[i]);
	m_numDSClassInstances = 0;
	SafeRelease(m_pVB);
	m_vertexStride = 0;
	m_vertexOffset = 0;
	SafeRelease(m_pIndexBuffer);
	m_indexFormat = DXGI_FORMAT_UNKNOWN;
	m_indexOffset = 0;

	SafeRelease(m_pContext);
	m_featureLevel = D3D_FEATURE_LEVEL_11_0;

	m_savedState = false;
}
