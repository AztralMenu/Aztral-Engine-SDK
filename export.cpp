#pragma once

#include "stdafx.h"
#include "export.h"
#include "Hooking/Pools.h"
#include "Global.h"
#include "Hooking/Hook.h"

#define DLL_EXPORT __declspec( dllexport )


ScriptManagerThread g_ScriptManagerThread;
HANDLE                      g_MainFiber;
static Script*				currentScript;

std::uint32_t g_ThreadHash = "main_persistent"_joaat;

std::deque<std::function<void()>> g_Stack;

DX11Hook g_D3DHook;

/* ####################### SCRIPT #######################*/

void handle_exception_ptr(std::exception_ptr exception_ptr)
{
	try
	{
		if (exception_ptr)
		{
			std::rethrow_exception(exception_ptr);
		}
	}
	catch (const std::exception& e)
	{
		SwitchToFiber(g_MainFiber);
		Log::Msg("ScriptError", FMT("Caught exception [%s]", e.what()));
	}
}

void Script::Tick()
{
	if (!g_MainFiber)
	{
		g_MainFiber = IsThreadAFiber() ? GetCurrentFiber() : ConvertThreadToFiber(nullptr);
	}
	else
	{
		if (timeGetTime() < wakeAt)
		{
			if (GetCurrentFiber() != g_MainFiber) SwitchToFiber(g_MainFiber); return;
		}

		if (scriptFiber)
		{
			currentScript = this;
			SwitchToFiber(scriptFiber);
			currentScript = nullptr;
		}

		else
		{
			scriptFiber = CreateFiber(NULL, [](LPVOID handler)
			{
				std::exception_ptr exception_ptr;
				try
				{
					reinterpret_cast<Script*>(handler)->Run();
				}
				catch (...)
				{
					SwitchToFiber(g_MainFiber);
					exception_ptr = std::current_exception();
				}	handle_exception_ptr(exception_ptr);
			}, this);
		}
	}
}

void Script::Run()
{
	callbackFunction();
}

void Script::Wait(uint32_t time)
{
	wakeAt = timeGetTime() + time;
	if (g_MainFiber) SwitchToFiber(g_MainFiber);
}

void ScriptManagerThread::DoRun()
{
	static bool Pressed[5] = { false };

	if (KeyPressedOnce(Pressed[0], VK_END))
	{
		g_ScriptManagerThread.RemoveAllScripts();
	}

	if (g_MainFiber && KeyDown(VK_CONTROL))
	{
		if (KeyPressedOnce(Pressed[1], VK_END))
		{
			Hooking::Cleanup();
		}
		if (KeyPressedOnce(Pressed[2], 0x52)) g_ScriptManagerThread.Reset();
	}

	scriptMap thisIterScripts(m_scripts);
	for (auto & pair : thisIterScripts) { pair.second->Tick(); }

	scriptMap thisIterAdditional(m_additional);
	for (auto & pair : thisIterScripts) { pair.second->Tick(); }

	while (!g_Stack.empty())
	{
		g_Stack.front()();
		g_Stack.pop_front();
	}
}

void ScriptManagerThread::Reset()
{
	g_ScriptManagerThread.RemoveAllScripts();
	wchar_t path[MAX_PATH];
	char target[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result != S_OK)
		Log::Msg("Folder not found");
	else
		wcstombs(target, path, MAX_PATH);
	string folder = target;
	Global::LoadPlugin(folder + "\\asi");
}

void ScriptManagerThread::AddScript(HMODULE module, void(*fn)())
{
	const std::string moduleName = GetModuleNameWithoutExtension(module);

	if (m_scripts.find(module) != m_scripts.end())
	{
		Log::Msg("Script '%s' is already registered", moduleName.c_str()); return;
	}
	else
	{
		Log::Msg("Registering script '%s' (0x%p)", moduleName.c_str(), fn);
		m_scripts[module] = std::make_shared<Script>(fn);
	}
}

void ScriptManagerThread::AddAdditional(HMODULE module, void(*fn)())
{
	const std::string moduleName = GetModuleNameWithoutExtension(module);

	if (m_additional.find(module) != m_additional.end())
	{
		Log::Msg("Additional Thread for '%s' is already registered", moduleName.c_str()); return;
	}
	else
	{
		Log::Msg("Registering Additional Thread for '%s' (0x%p)", moduleName.c_str(), fn);
		m_additional[module] = std::make_shared<Script>(fn);
	}
}

void ScriptManagerThread::RemoveScript(void(*fn)())
{
	for (auto it = m_scripts.begin(); it != m_scripts.end(); it++)
	{
		auto pair = *it;
		if (pair.second->GetCallbackFunction() == fn)
		{
			RemoveScript(pair.first);
		}
	}
}

void ScriptManagerThread::RemoveScript(HMODULE module)
{
	const std::string name = GetModuleNameWithoutExtension(module);

	auto main_script = m_scripts.find(module);

	auto add_script = m_additional.find(module);

	if (add_script != m_additional.end())
	{
		m_additional.erase(add_script);
		Log::Msg("Removed '%s' additional thread module 0x%p", name.c_str(), module);
	}

	if (main_script != m_scripts.end())
	{
		m_scripts.erase(main_script);
		Log::Msg("Unregistered script '%s'", name.c_str());
	}
}

void ScriptManagerThread::RemoveAllScripts()
{
	if (g_MainFiber) SwitchToFiber(g_MainFiber);

	for (auto && pair : m_additional)
	{
		RemoveScript(pair.first);
		FreeLibrary(pair.first);
	}	m_additional.clear();

	for (auto && pair : m_scripts)
	{
		RemoveScript(pair.first);
		FreeLibrary(pair.first);
	}	m_scripts.clear();

	if (std::size(m_scripts) == 0)
		PlaySound(L"C:\\WINDOWS\\Media\\Windows Default.wav", NULL, SND_ASYNC);
}

/* ####################### EXPORTS #######################*/

/*Input*/
typedef void(*KeyboardHandler)(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);

typedef void(*TWndProcFn)(UINT uMsg, WPARAM wParam, LPARAM lParam);

static std::set<KeyboardHandler> g_keyboardFunctions;

static std::set<TWndProcFn> g_WndProcCb;

DLL_EXPORT void WndProcHandlerRegister(TWndProcFn function)
{
	g_WndProcCb.insert(function);
}

DLL_EXPORT void WndProcHandlerUnregister(TWndProcFn function)
{
	g_WndProcCb.erase(function);
}

void ScriptManager::WndProc(HWND /*hwnd*/, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	for (auto & function : g_WndProcCb) function(uMsg, wParam, lParam);

	if (uMsg == WM_KEYDOWN || uMsg == WM_KEYUP || uMsg == WM_SYSKEYDOWN || uMsg == WM_SYSKEYUP)
	{
		for (auto & function : g_keyboardFunctions) function((DWORD)wParam, lParam & 0xFFFF, (lParam >> 16) & 0xFF, (lParam >> 24) & 1, (uMsg == WM_SYSKEYDOWN || uMsg == WM_SYSKEYUP), (lParam >> 30) & 1, (uMsg == WM_SYSKEYUP || uMsg == WM_KEYUP));
	}
}

/* keyboard */
DLL_EXPORT void keyboardHandlerRegister(KeyboardHandler function)
{
	g_keyboardFunctions.insert(function);
}

DLL_EXPORT void keyboardHandlerUnregister(KeyboardHandler function)
{
	g_keyboardFunctions.erase(function);
}

/* D3d SwapChain */
DLL_EXPORT void presentCallbackRegister(PresentCallback cb)
{
	g_D3DHook.AddCallback(cb);
}

DLL_EXPORT void presentCallbackUnregister(PresentCallback cb)
{
	g_D3DHook.RemoveCallback(cb);
}

/* textures */
DLL_EXPORT int createTexture(const char *texFileName)
{
	return g_D3DHook.CreateTexture(texFileName);
}

DLL_EXPORT void drawTexture(int id, int index, int level, int time, float sizeX, float sizeY, float centerX, float centerY, float posX, float posY, float rotation, float screenHeightScaleFactor, float r, float g, float b, float a)
{
	g_D3DHook.DrawTexture(id, index, level, time, sizeX, sizeY, centerX, centerY, posX, posY, rotation, screenHeightScaleFactor, r, g, b, a);
}

/* scripts */
DLL_EXPORT void changeScriptThread(UINT32 hash)
{
	if (g_ThreadHash != hash)
		g_ThreadHash = hash;
}

DLL_EXPORT void scriptWait(DWORD time)
{
	currentScript->Wait(time);
}

DLL_EXPORT void scriptRegister(HMODULE module, void(*function)())
{
	g_ScriptManagerThread.AddScript(module, function);
}

DLL_EXPORT void scriptRegisterAdditionalThread(HMODULE module, void(*function)())
{
	g_ScriptManagerThread.AddAdditional(module, function);
}

DLL_EXPORT void scriptUnregister(HMODULE module)
{
	g_ScriptManagerThread.RemoveScript(module);
}

DLL_EXPORT void scriptUnregister(void(*function)())
{
	// deprecated
	g_ScriptManagerThread.RemoveScript(function);
}

/* natives */
/*
DLL_EXPORT void nativeInit(UINT64 hash)
{
	g_hash = hash;

	g_context.Reset();
}

DLL_EXPORT void nativePush64(UINT64 val)
{
	nativePush64(val);
}

DLL_EXPORT uint64_t* nativeCall()
{
	invoke<Void>(g_hash, &g_context);
	return g_Returns.getRawPtr();
}*/

/* global variables */
/*DLL_EXPORT UINT64 *getGlobalPtr(int globalId)
{
	return ScriptEngine::getGlobal(globalId);
}*/

/* world pools */
DLL_EXPORT int worldGetAllPeds(int *arr, int arrSize)
{
	return internal::worldGetAllPedIntArray(arr, arrSize);
}

DLL_EXPORT int worldGetAllVehicles(int *arr, int arrSize)
{
	return internal::worldGetAllVehicleIntArray(arr, arrSize);
}

DLL_EXPORT int worldGetAllObjects(int *arr, int arrSize)
{
	return internal::worldGetAllObjectIntArray(arr, arrSize);
}

DLL_EXPORT int worldGetAllPickups(int *arr, int arrSize)
{
	return internal::worldGetAllPickupIntArray(arr, arrSize);
}

/* game version */
/*DLL_EXPORT eGameVersion getGameVersion()
{
	return static_cast<eGameVersion>(g_GameVersion);
}*/

/* misc */
DLL_EXPORT BYTE* getScriptHandleBaseAddress(int handle)
{
	return (BYTE*)rage::GetEntityAddress(handle);
}

DLL_EXPORT UINT32 registerRawStreamingFile(const char* fileName, const char* registerAs, bool errorIfFailed)
{
	UINT32 textureID;
	return rage::FileRegister(&textureID, fileName, true, registerAs, errorIfFailed) ? textureID : 0;
}

/*DLL_EXPORT PVOID createDetour(PVOID* pTarget, PVOID pHandler, const char* name = nullptr)
{
	return Hook::CreateDetour(pTarget, pHandler, name);
}

DLL_EXPORT void removeDetour(PVOID* ppTarget, PVOID pHandler)
{
	Hook::RemoveDetour(ppTarget, pHandler);
}*/
