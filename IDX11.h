#ifndef DX11_INCLUDE
#define DX11_INCLUDE

#pragma once

#include "stdafx.h"
//#define V64_2015DBG
//#define YAMLDBG

#define V64_2015
//#define DEBUG_CONSOLE
//#define SC_VERSION
#define STEAM_VERSION

#if defined(V64_2015)
#pragma comment (lib, "DirectXTK.lib")
#elif defined(V32_2015)
#pragma comment (lib, "DirectXTK32_2015.lib")
#elif defined(V64_2013)
#pragma comment (lib, "DirectXTK_2.lib")
#elif defined(V64_2015DBG)
#pragma comment (lib, "DirectXTK_64_Debug.lib")
#endif


#pragma comment (lib, "DXGI.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "dwmapi.lib")
//#pragma comment (lib, "libyaml-cppmd.lib")

#include <mutex>
#include <DbgHelp.h>
#include <string>
#include <vector>
#include <stdarg.h>
#include <CommonStates.h>
#include <DDSTextureLoader.h>
#include <Effects.h>
#include <GeometricPrimitive.h>
#include <Model.h>
#include <PrimitiveBatch.h>
#include <ScreenGrab.h>
#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <SpriteFont.h>
#include <VertexTypes.h>
#include <DDSTextureLoader.h>
#include <D3DX11tex.h>
#include <DXGI.h>
#include <D3D11.h>
#include <D3DCompiler.h>
#include <DWrite.h>
#include <d3d9.h>
#include <d3d11.h>
#include <d3dx9.h>
#include <d3dx10.h>
#include <d3dx11.h>
#include <directxcolors.h>
#include <dwmapi.h>
#include <SimpleMath.h>
#include <limits>

#include <ctime>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <thread>
#include <map>
#include <exception>
#include "Capstone/include/capstone.h"
#include "PolyHook.h"
#include "Game.h"
#include "Global.h"


#ifndef GUI_INCLUDE
#define GUI_INCLUDE

#pragma once

#include "stdafx.h"

using namespace DirectX::SimpleMath;

extern GID TWindows;
extern GID TCheckboxes;
extern GID TTabs;
extern GID TProgressBars;
extern GID TLabels;
extern GID TDropMenus;
extern GID TButtons;


struct Rect
{
	float x, y, sx, sy;
	Rect() {}
	Rect(float _x, float _y, float _sx, float _sy) { x = _x; y = _y; sx = _sx; sy = _sy; }
	Rect operator - (Rect vec) const
	{
		return Rect(x - vec.x, y - vec.y, sx, sy);
	}
	Rect operator + (Rect vec) const
	{
		return Rect(x + vec.x, y + vec.y, sx, sy);
	}
};

class CButton;
class CCheckBox;
class CDropMenu;

class CGUI
{
public:

	static Vector2 CursorPos;
	Vector2 LatestCursorPos;
	static INT LastClick;
	static INT LastTick;
	static INT CurrentTick;
	GID ElementSelected = 0;
	bool MouseLeftPressed = false;

	static bool OnClick();
	static void ButtonEvents(CButton* btn);
	static void CheckboxEvents(CCheckBox* checkbox);
	static void OnDropMenuItemClick(CDropMenu* DropMenu, GID index);
	static void OnWheelMove(short Dir);
	static void OnLeftMouseButtonDown();
	static void OnLeftMouseButtonUp();
	void OnProgressBarMove(GID ProgressBar);
	void RefreshCursor();
	static bool IsCursorHover(Rect rect, bool IsActive);
	static CCheckBox* GetCheckboxFromName(const char* _Name);
	static CDropMenu* GetDropMenuFromName(const char* _Name);
	//static CProgressBar* GetProgressBarFromName(const char* _Name);
	std::string StrVars(const char* _text, ...);
	static void SaveInClipBoard(const std::string &s);

	template <class vType>
	vType GetDataFromDropMenuName(const char* _Name)
	{
		CDropMenu* DM = GetDropMenuFromName(_Name);
		if (DM->ItemsInside->UsingData)
			return (vType)DM->GetMainItemData<vType>();
		return 0;
	}
};

class CDropMenuElements
{
public:
	const char* text[200];
	std::string strText[200];
	const char* StorageName;
	const char* VarType = "init";
	float MovementPos[200];

	//STORAGE DATA
	DWORD iData[200];
	Vector3 vecData[200];
	BOOLEAN UsingData = FALSE;
	BOOLEAN UsingStrText[200];

	//TOTAL ITEMS
	GID Items = 0;

	CDropMenuElements() {}
	CDropMenuElements(const char* _StorageName) { StorageName = _StorageName; }

	GID InsertItem(const char* _text, DWORD _iData = 0)
	{
		if (_iData != 0)
		{
			if (!UsingData) UsingData = TRUE;
			iData[Items] = _iData;
			if (!strcmp("init", VarType))
				VarType = "DWORD";
		}
		text[Items] = _text;
		UsingStrText[Items] = FALSE;
		Items++;
		return Items - 1;
	}
	GID InsertItem(std::string _text, Vector3 _vecData, BOOLEAN bUsingStrText = FALSE)
	{
		if (!std::isnan(_vecData.x) && !std::isnan(_vecData.y) && !std::isnan(_vecData.z))
		{
			if (!UsingData) UsingData = TRUE;
			vecData[Items] = _vecData;
			if (!strcmp("init", VarType))
				VarType = "Vector3";
			char* nszStr;

			if (bUsingStrText)
			{
				UsingStrText[Items] = bUsingStrText;
				strText[Items] = _text;
			}
			else
			{
				UsingStrText[Items] = FALSE;
				text[Items] = _text.c_str();
			}

			Items++;
			return Items - 1;
		}
		return -1;
	}
	void InsertIntData(DWORD* Data)
	{
		memcpy(iData, Data, sizeof(Data));
	}
	CDropMenuElements* GetCopy()
	{
		CDropMenuElements* newStorage = new CDropMenuElements();
		memcpy(newStorage, this, sizeof(CDropMenuElements));
		return newStorage;
	}
};

class CWindow
{
public:
	Rect rect;
	Rect EventRect;
	Vector2 TabSize;
	Color color;
	Color border;
	GID Tabs[5];
	float borderPx;
	GID parent;
	GID ActiveTab;
	const char* parentType;
	const char* title;

	CWindow() {}
	CWindow(Rect _rect, const char* _title, Vector2 _TabSize, float _borderPx, Color _color, Color _border, GID _ActiveTab, GID _parent, const char* _parentType)
	{
		rect = _rect;
		title = _title;
		TabSize = _TabSize;
		borderPx = _borderPx;
		color = _color;
		border = _border;
		parent = _parent;
		parentType = _parentType;
		ActiveTab = _ActiveTab;
	}
};

extern CWindow* GUIWindows[40];

class CCheckBox
{
public:
	Rect rect;
	Rect EventRect;
	Color TextColor;
	Color IsChecked;
	Color IsNotChecked;
	GID parent;
	const char* Name;
	const char* text;
	const char* parentType;
	BOOLEAN state;
	BOOLEAN IsActive;

	CCheckBox() {}
	CCheckBox(Rect _rect, const char* _text, const char* _Name, bool _state, Color _TextColor, Color _IsChecked, Color _IsNotChecked, GID _parent, const char* _parentType)
	{
		rect = _rect;
		text = _text;
		state = _state;
		Name = _Name;
		TextColor = _TextColor;
		IsChecked = _IsChecked;
		IsNotChecked = _IsNotChecked;
		parent = _parent;
		parentType = _parentType;
		IsActive = FALSE;
	}
	void Toggle()
	{
		state = !state;
	}
	void ToggleWithValue(BOOLEAN& bValue)
	{
		bValue = !(bValue);
		state = bValue;
	}
	void DisableWithValue(BOOLEAN& bValue)
	{
		bValue = FALSE;
		state = FALSE;
	}
};

extern CCheckBox* GUICheckBoxes[40];

class CTab
{
public:
	Rect rect;
	Rect EventRect;
	Color TabColor;
	Color TextColor;
	Color DefaultBoxColor;
	Color BoxColor;
	Color BorderColor;
	float SizeX;
	float PosSize;
	GID windowTabID;
	GID parent;
	const char* parentType;
	const char* text;

	CTab() {}
	CTab(Rect _rect, const char* _text, Color _TabColor, Color _TextColor, Color _BorderColor, GID _parent, const char* _parentType, GID _windowTabID)
	{
		rect = _rect;
		text = _text;
		TabColor = _TabColor;
		TextColor = _TextColor;
		BorderColor = _BorderColor;
		BoxColor = Color(0, 0, 0, 0);
		DefaultBoxColor = Color(0, 0, 0, 0);
		parent = _parent;
		parentType = _parentType;
		windowTabID = _windowTabID;
	}
};

extern CTab* GUITabs[40];

class CProgressBar
{
public:
	Rect rect;
	Rect EventRect;
	Color TextColor;
	Color BarColor;
	GID parent;
	bool Active;
	float Progress;
	float Defect;
	float LimitLeft;
	float TextSize;
	const char* Name;
	const char* parentType;
	std::string p_text;

	CProgressBar() {}
	template <class vType>
	CProgressBar(const char* _Name, Rect _rect, const char* _p_text, vType _Progress, Color _TextColor, Color _BarColor, GID _parent, const char* _parentType)
	{
		Name = _Name;
		rect = _rect;
		p_text = _p_text;
		Progress = 20; //((100 * rect.sx) / _Progress)
		TextColor = _TextColor;
		BarColor = _BarColor;
		parent = _parent;
		parentType = _parentType;
		SetProgressValue(_p_text, (vType)_Progress);
	}

	void SetText(std::string szText)
	{
		p_text = szText;
	}

	void SetProgressValue(const char* _NewText, ...)
	{
		std::string NewText;
		char TempBuff[512] = { '\0' };
		va_list VAL;
		va_start(VAL, _NewText);
		vsprintf_s(TempBuff, _NewText, VAL);
		va_end(VAL);

		p_text = TempBuff;
	}
};

extern CProgressBar* GUIProgressBars[40];


class CLabel
{
public:
	Rect rect;
	Color TextColor;
	GID parent;
	const char* parentType;
	bool Active;
	const char* text;

	CLabel() {}
	CLabel(Rect _rect, const char* _text, float _Progress, Color _TextColor, Color _BarColor, GID _parent, const char* _parentType)
	{
		rect = _rect;
		text = _text;
		TextColor = _TextColor;
		parent = _parent;
		parentType = _parentType;
	}
};

extern CLabel* GUILabels[40];

class CDropMenu
{
public:
	struct ItemInfo
	{
	public:
		const char* Name;
		std::string StrName;
		GID ID;
		BOOLEAN bUsingStrText;
		ItemInfo() {}
		ItemInfo(const char* _Name, GID _ID, BOOLEAN _bUsingStrText = FALSE, std::string _StrName = "")
		{
			Name = _Name;
			ID = _ID;
			bUsingStrText = _bUsingStrText;
			StrName = _StrName;
		}
	};
	Rect rect;
	Rect EventRect;
	CDropMenuElements* ItemsInside;
	const char* text;
	const char* text_2;
	const char* Name;
	const char* parentType;
	Color TextColor;
	Color DefaultBoxColor;
	Color BoxColor;
	Color HighlightColor;
	ItemInfo ItemSelected;
	ItemInfo MainItem;
	float TextSize;
	float TextSizeY;
	float ExpandLimit;
	float ArrowRotation;
	int RollPage;
	GID parent;
	bool IsActive;
	bool IsOpening;
	bool IsClosing;
	bool IsOpened;

	CDropMenu() {}
	CDropMenu(Rect _rect, const char* _Name, const char* _text, CDropMenuElements* _ItemsInside, Color _TextColor, Color _BoxColor, Color _HighlightColor, GID _parent, const char* _parentType, const char* _Text_2 = "")
	{
		ItemSelected = ItemInfo("", -1);
		MainItem = ItemInfo("", -1);
		rect = _rect;
		Name = _text;
		text = _text;
		text_2 = _Text_2;
		ItemsInside = _ItemsInside;
		TextColor = _TextColor;
		BoxColor = _BoxColor;
		DefaultBoxColor = _BoxColor;
		HighlightColor = _HighlightColor;
		parent = _parent;
		parentType = _parentType;
		IsOpening = false;
		IsClosing = false;
		IsOpened = false;
		IsActive = false;
		RollPage = 0;
	}
	void DeleteAllItems()
	{
		this->ItemsInside = new CDropMenuElements("DELETED");
	}

	void SetMainItem(const char* _Name)
	{
		for (GID i = 0; i < ItemsInside->Items; i++)
		{
			if (!strcmp(ItemsInside->text[i], _Name))
				this->MainItem = ItemInfo(ItemsInside->text[i], i);
		}
	}

	template <class vType>
	BOOLEAN IsUsingDataAndRead(vType &_Data)
	{
		if (this->MainItem.ID >= 0)
		{
			if (this->ItemsInside->UsingData) //check items that contains data in each item 
			{
				if ((_Data = this->ItemsInside->iData[this->MainItem.ID]))
					return TRUE;
			}
		}
		return FALSE;
	}

	template <class vType>
	vType GetMainItemData()
	{
		return (vType)this->ItemsInside->iData[this->MainItem.ID];
	}

	template <class vType>
	vType GetItemDataFromName(const char* _Data)
	{
		auto CompareData = [](const char* _VarType, CDropMenu* _this, int i)
		{
			if (_VarType == "DWORD")
				return (vType)_this->ItemsInside->iData[i];
			else if (_VarType == "Vector3")
				return (vType)_this->ItemsInside->vecData[i];
		};

		for (GID i = 0; i < ItemsInside->Items; i++)
		{
			if (!this->ItemsInside->UsingStrText)
			{
				if (!strcmp(this->ItemsInside->text[i], _Data))
					return CompareData(this->ItemsInside->VarType, this, i);
			}
			else
			{
				if (!strcmp(this->ItemsInside->strText[i].c_str(), _Data))
					return CompareData(this->ItemsInside->VarType, this, i);
			}
		}
		return vType();
	}
};

extern CDropMenu* GUIDropMenus[40];


class CButton
{
public:
	Rect rect;
	Rect EventRect;
	const char* Name;
	const char* text;
	const char* parentType;
	Color TextColor;
	Color BorderColor;
	Color DefaultBoxColor;
	Color BoxColor;
	Color HighlightColor;
	GID LinkedDropMenu;
	GID parent;
	BOOLEAN IsActive;
	BOOLEAN IsClicked;

	CButton() {}
	CButton(const char* _Name, Rect _rect, const char* _text, Color _TextColor, Color _BorderColor, Color _BoxColor, Color _HighlightColor, GID _LinkedDropMenu, GID _parent, const char* _parentType)
	{
		Name = _Name;
		rect = _rect;
		text = _text;
		TextColor = _TextColor;
		BorderColor = _BorderColor;
		BoxColor = _BoxColor;
		DefaultBoxColor = _BoxColor;
		HighlightColor = _HighlightColor;
		LinkedDropMenu = _LinkedDropMenu;
		parent = _parent;
		parentType = _parentType;
		IsActive = FALSE;
		IsClicked = FALSE;
	}
};

extern CButton* GUIButtons[40];

class GUIElements
{
public:
	static BOOLEAN Initialized;

	static void InitGUIElements();

	static GID GUICreateWindow(CWindow* data);
	static GID GUICreateCheckBox(CCheckBox* data);
	static GID GUICreateTab(CTab* data);
	static GID GUICreateProgressBar(CProgressBar* data);
	static GID GUICreateLabel(CLabel* data);
	static GID GUICreateDropMenu(CDropMenu* data);
	static GID GUICreateButton(CButton* data);
};



extern CGUI GUI;


#endif

using namespace DirectX;
using namespace DirectX::SimpleMath;

typedef __int16 GID;

class DXTKStateSaver;

struct LogData
{
public:
	Color LogColor;
	std::string Text;
	LogData() {}
	LogData(Color _Color, std::string _Text)
	{
		LogColor = _Color;
		Text = _Text;
	}
	void RemoveLog()
	{
		LogColor = Color(0, 0, 0, 0);
		Text = "";
	}
};


class GUI2
{
public:
	static SimpleMath::Vector2 LastMousePosition;
	static SimpleMath::Vector2 MousePosition;

	static void OnMouseMove(short x, short y);

};

class DX11Renderer : public GUI2
{
private:

	ID3D11Device*			 DX11Device = NULL;
	ID3D11DeviceContext*	 DX11DeviceContext = NULL;
	ID3D11RenderTargetView*  DX11RenderTargetView = NULL;
	ID3D11Texture2D*		 DX11BackBuffer;

	DWORD_PTR* SwapChainVtable = NULL;
	DWORD_PTR* DeviceContextVTable = NULL;

	ID3D11InputLayout*  InputLayout;

	D3D11_BLEND_DESC BlendStateDesc;
	ID3D11BlendState* AlphaOnBlendState;
	
	std::unique_ptr<PrimitiveBatch<VertexPositionColor>> DX11Batch;
	std::unique_ptr<BasicEffect>						 DX11BatchEffects;
	std::unique_ptr<EffectFactory>						 DX11FXFactory;
	std::unique_ptr<CommonStates>						 DX11CommonStates;
	std::unique_ptr<SpriteBatch>						 DX11SpriteBatch;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> LogoTexture;
	Microsoft::WRL::ComPtr<ID3D11Resource>			 LogoResource;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			 Logo;
	CD3D11_TEXTURE2D_DESC						     LogoDesc;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> CursorTexture;
	Microsoft::WRL::ComPtr<ID3D11Resource>			 CursorResource;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			 CursorGame;
	CD3D11_TEXTURE2D_DESC						     CursorDesc;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> UCIconTexture;
	Microsoft::WRL::ComPtr<ID3D11Resource>			 UCIconResource;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			 UCIcon;
	CD3D11_TEXTURE2D_DESC						     UCIconDesc;

	HMODULE DllModule = NULL;

	const char* Target;

	BOOLEAN RestoreState = FALSE;
	BOOLEAN Initialized = FALSE;
	BOOLEAN Closing = FALSE;

	DXTKStateSaver* StateSaver;

	void DX11Begin();
	void DX11End();

	void CleanupDevice();

	void Log(const char* error, BOOLEAN close, ...);

public:

	DX11Renderer() {}

	std::unique_ptr<SpriteFont>							 DX11Purista;

	static float ScreenX, ScreenY;
	static float ScreenSX, ScreenSY;

	float TestVar = 1.0f;

	DWORD InitDevice(HMODULE _DllModule, const char* HWNDTarget);
	BOOLEAN InitDX11RenderStuff(IDXGISwapChain* _SwapChain);

	void DX11RenderScene();

	std::wstring ConvertToWStr(const std::string& s);

	void DrawBox(float x, float y, float x1, float y1, Color color);
	void DrawEmptyBox(float x, float y, float x1, float y1, float px, Color color);
	void DrawEmptyBoxTab(float x, float y, float x1, float y1, float px, Color color);
	void DrawEmptyBoxTab_2(float x, float y, float x1, float y1, float from, float to, float px, Color color);
	void DrawDXText(float x, float y, float scale, bool center, float rot, Color color, bool shadow, const char* Format, ...);
	void DrawUnicodeText(float x, float y, float scale, bool center, float rot, Color color, bool shadow, std::wstring Format);

	void DrawLine(float x1, float y1, float x2, float y2, Color color);
	void DrawCircle(float x, float y, Color color, float radius, int _s);
	void DrawTriangle(float x, float y, Color color);
	void Draw3DBox(float x, float y, float x1, float y1, float movement, Color color);
	void DrawCursor(float x, float y, float size);

	void FillRGB(float x, float y, float x1, float y1, Color color);

	
	//GUI DEPENDENT FUNCTIONS
	//GUI DEPENDENT FUNCTIONS
	//GUI DEPENDENT FUNCTIONS


	void DrawWindow(GID ID);
	void DrawCheckBox(GID ID);
	void DrawTab(GID ID);
	void DrawProgressBar(GID ID);
	void DrawDropMenu(GID ID);
	void DrawButton(GID ID);
};

class DXTKStateSaver
{
private:
	bool m_savedState;
	D3D_FEATURE_LEVEL m_featureLevel;
	ID3D11DeviceContext* m_pContext;
	D3D11_PRIMITIVE_TOPOLOGY m_primitiveTopology;
	ID3D11InputLayout* m_pInputLayout;
	ID3D11BlendState* m_pBlendState;
	float m_blendFactor[4];
	UINT m_sampleMask;
	ID3D11DepthStencilState* m_pDepthStencilState;
	UINT m_stencilRef;
	ID3D11RasterizerState* m_pRasterizerState;
	ID3D11ShaderResourceView* m_pPSSRV;
	ID3D11SamplerState* m_pSamplerState;
	ID3D11VertexShader* m_pVS;
	ID3D11ClassInstance* m_pVSClassInstances[256];
	UINT m_numVSClassInstances;
	ID3D11Buffer* m_pVSConstantBuffer;
	ID3D11GeometryShader* m_pGS;
	ID3D11ClassInstance* m_pGSClassInstances[256];
	UINT m_numGSClassInstances;
	ID3D11Buffer* m_pGSConstantBuffer;
	ID3D11ShaderResourceView* m_pGSSRV;
	ID3D11PixelShader* m_pPS;
	ID3D11ClassInstance* m_pPSClassInstances[256];
	UINT m_numPSClassInstances;
	ID3D11HullShader* m_pHS;
	ID3D11ClassInstance* m_pHSClassInstances[256];
	UINT m_numHSClassInstances;
	ID3D11DomainShader* m_pDS;
	ID3D11ClassInstance* m_pDSClassInstances[256];
	UINT m_numDSClassInstances;
	ID3D11Buffer* m_pVB;
	UINT m_vertexStride;
	UINT m_vertexOffset;
	ID3D11Buffer* m_pIndexBuffer;
	DXGI_FORMAT m_indexFormat;
	UINT m_indexOffset;

	DXTKStateSaver(const DXTKStateSaver&);
	//DXTKStateSaver& operator=(const DXTKStateSaver&);

public:
	DXTKStateSaver();
	~DXTKStateSaver();

	HRESULT saveCurrentState(ID3D11DeviceContext* pContext);
	HRESULT restoreSavedState();
	void ZeroShaders(ID3D11DeviceContext* pContext);
	void releaseSavedState();
};

template<class T> inline void SAFE_DELETE(T *&p)
{
	if (p)
	{
		delete p;
		p = NULL;
	}
}

template<class T> inline void SAFE_DELETE_ARRAY(T *&p)
{
	if (p)
	{
		delete[] p;
		p = NULL;
	}
}

template<class T> inline void SAFE_RELEASE(T *&p)
{
	if (p)
	{
		p->Release();
		p = NULL;
	}
}

extern std::unique_ptr<DX11Renderer> DX11;

#endif DX11_INCLUDE