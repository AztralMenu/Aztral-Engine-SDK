// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define VMP_

#define WINVER 0x0A00  
#define _WIN32_WINNT 0x0A00 

#pragma warning(push)
#pragma warning (disable: 4305)
#pragma warning (disable: 4805)
#pragma warning (disable: 4244)
#pragma warning(disable : 4088)
#pragma warning(disable : 4098)





#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

// Windows Header Files:

#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>
#include <minwindef.h>
#include <shlobj.h>
#include <queue>

/*
#include <d3d9.h>
#include <D3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "D3dx9.lib")
*/
//#include <d2d1.h>




// Additional Header Files:
#include "Log.h"
#include "Memory.h"
#include "types.h"
#include "enums.h"
#include "InputHook.h"
#include "keyboard.h"
#include "CrossMapping.h"
#include "NativeInvoker.h"
#include "nativeCaller.h"
#include "natives.h"
#include "Structs.h"
#include "menu.h"
#include "inifile.h"



// Menu Files:
#include "GUI.h"
#include "subs.h"
//#include "Global.h"
#include "database.h"
#include "props.h"
#include "propplacement.h"
#include "data_props.h"

#include "Hooking.h"
#include "Functions.h"





using namespace std;



#include <locale>
#include <codecvt>
#include <stdio.h>
#include "Auth/Networking/sha512.hh"
#include "Auth/Networking/StringProcess.h"
#include "Auth/Networking/Auth.h"
#include "Auth/Networking/Web2.0.h"
#include "Auth/Networking/WinHttpClient.h"
#include <wincrypt.h>



#ifdef VMP
#include "VMProtect\include\VMProtectSDK.h"
#pragma comment(lib, "VMProtectSDK64.lib")
#endif

#pragma warning(pop)
#pragma warning(push)

#pragma warning(error: 4714) 
__forceinline const char* operator""_Secure(const char* str, std::size_t) {
#ifdef VMP
	return VMProtectDecryptStringA(str);
#else
	return str;
#endif
}

__forceinline const wchar_t* operator""_Secure(const wchar_t* str, std::size_t) {
#ifdef VMP
	return VMProtectDecryptStringW(str);
#else
	return str;
#endif
}

class globalHandle
{
private:
	void* _handle;

public:
	globalHandle(int index)
		: _handle(&Hooking::getGlobalPtr()[index >> 0x12 & 0x3F][index & 0x3FFFF])
	{ }

	globalHandle(void* p)
		: _handle(p)
	{ }

	globalHandle(const globalHandle& copy)
		: _handle(copy._handle)
	{ }

	globalHandle At(int index)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
	}

	globalHandle At(int index, int size)
	{
		// Position 0 = Array Size
		return this->At(1 + (index * size));
	}

	template <typename T>
	T* Get()
	{
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As()
	{
		return *this->Get<T>();
	}
};

template <typename T> void set_tuneable_value(unsigned int offset, T value)
{
	*(T*)globalHandle(262145 + offset) = value;
}

template <typename T> T get_tuneable_value(unsigned int offset)
{
	return *(T*)globalHandle(262145 + offset);
}