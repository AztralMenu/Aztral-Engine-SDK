// dllmain.cpp : Defines the entry point for the DLL application.
//=====================================================================================
#pragma once
#include "stdafx.h"
#include "main.h"
#include "IDX11.h"

//=====================================================================================
HMODULE TempModule = NULL;



DWORD WINAPI ControlThread(LPVOID lpParam)
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	DX11.reset(new DX11Renderer());
	

	Hooking::Start((HMODULE)lpParam);

	DX11->InitDevice(TempModule, "Grand Theft Auto V");
	return 0;
}

void ThreadStart()
{
	ControlThread;
}

//=====================================================================================

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		TempModule = hModule;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		Hooking::Cleanup();
		break;
	}
	return TRUE;
}

//=====================================================================================