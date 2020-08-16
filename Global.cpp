#pragma once

#include "stdafx.h"
#include "Global.h"
#include <windows.h>
#include <iostream>
#include <shlobj.h>


wstring Global::BASEURL = L"https://aztralmenu.com"_Secure;
wstring Global::INI_FILE = L"login.ini"_Secure;
wstring Global::AUTH = L"/6e6f7468696e6720746f207365652068657265/"_Secure;
wstring Global::AUTH2 = L"/6e6f7468696e6720746f207365652068657265/1234/"_Secure;


std::string input20 = "gweiofqnidfqwndiqdoq";
std::string hash20 = sw::sha512::calculate(input20);


class Global::Ini
{
private:
	std::string inifile;
public:
	Global::Ini(std::string file)
	{
		this->inifile = file;
	}

	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	DWORD GetString(std::string app, std::string key)
	{
		const size_t ArraySize = 256;
		char *buf = new char[ArraySize];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "VK_NOTHING", buf, ArraySize, this->inifile.c_str());
		return (DWORD)buf;
	}
	int GetInt(std::string app, std::string key)
	{
		const size_t ArraySize = 256;
		return GetPrivateProfileIntA(app.c_str(), key.c_str(), ArraySize, this->inifile.c_str());
	}

};

string target = Global::target();

Global::Ini* ini = new Global::Ini(target);
int Global::cgodmode = ini->GetInt("Config"_Secure, "Godmode"_Secure);
int Global::ctpwaypoint = ini->GetInt("Config"_Secure, "TP to Waypoint"_Secure);
int Global::ctpobj = ini->GetInt("Config"_Secure, "TP to Objective"_Secure);
int Global::cinvisible = ini->GetInt("Config"_Secure, "Invisible"_Secure);
int Global::csuperjump = ini->GetInt("Config"_Secure, "Super Jump"_Secure);
int Global::cfastrun = ini->GetInt("Config"_Secure, "Fast Run"_Secure);
int Global::cfastswim = ini->GetInt("Config"_Secure, "Fast Swim"_Secure);
int Global::cnoragdoll = ini->GetInt("Config"_Secure, "No Rag Doll"_Secure);
int Global::cnoclip = ini->GetInt("Config"_Secure, "No Clip"_Secure);
int Global::cesp = ini->GetInt("Config"_Secure, "ESP"_Secure);
int Global::cshowcoords = ini->GetInt("Config"_Secure, "Show Coordinates"_Secure);
int Global::csavecoords = ini->GetInt("Config"_Secure, "Save Coordinates"_Secure);
int Global::cgodvehicle = ini->GetInt("Config"_Secure, "God Vehicle"_Secure);
int Global::crepairvehicle = ini->GetInt("Config"_Secure, "Repair Vehicle"_Secure);
int Global::cmaxvehicle = ini->GetInt("Config"_Secure, "Max Vehicle"_Secure);
int Global::cselfdrive = ini->GetInt("Config"_Secure, "Self Drive"_Secure);
int Global::ccarsuperman = ini->GetInt("Config"_Secure, "Car Superman"_Secure);
int Global::ctpintolastvehicle = ini->GetInt("Config"_Secure, "TP into Last Vehicle"_Secure);
int Global::ctpintoclosestvehicle = ini->GetInt("Config"_Secure, "TP into Closest Vehicle"_Secure);
int Global::cflipcar = ini->GetInt("Config"_Secure, "Flip Car"_Secure);
int Global::cspeedometerMPH = ini->GetInt("Config"_Secure, "MPH Speedometer"_Secure);
int Global::cspeedometerKMPH = ini->GetInt("Config"_Secure, "KMPH Speedometer"_Secure);
int Global::cbulletprooftires = ini->GetInt("Config"_Secure, "Bulletproof Tires"_Secure);
int Global::chornboost = ini->GetInt("Config"_Secure, "Horn Boost"_Secure);
int Global::cdriveonwater = ini->GetInt("Config"_Secure, "Drive on Water"_Secure);
int Global::cenginealwayson = ini->GetInt("Config"_Secure, "Engine always On"_Secure);
int Global::cnofallfrombike = ini->GetInt("Config"_Secure, "No Fall from Bike"_Secure);

string target1 = Global::target1();

Global::Ini* ini1 = new Global::Ini(target1);
int Global::acgodmode = ini1->GetInt("AutoOnConfig"_Secure, "Godmode"_Secure);
int Global::acinvisible = ini1->GetInt("AutoOnConfig"_Secure, "Invisible"_Secure);
int Global::acsuperjump = ini1->GetInt("AutoOnConfig"_Secure, "Super Jump"_Secure);
int Global::acfastrun = ini1->GetInt("AutoOnConfig"_Secure, "Fast Run"_Secure);
int Global::acfastswim = ini1->GetInt("AutoOnConfig"_Secure, "Fast Swim"_Secure);
int Global::acnoragdoll = ini1->GetInt("AutoOnConfig"_Secure, "No Rag Doll"_Secure);
int Global::acnoclip = ini1->GetInt("AutoOnConfig"_Secure, "No Clip"_Secure);
int Global::acesp = ini1->GetInt("AutoOnConfig"_Secure, "ESP"_Secure);
int Global::acshowcoords = ini1->GetInt("AutoOnConfig"_Secure, "Show Coordinates"_Secure);
int Global::acgodvehicle = ini1->GetInt("AutoOnConfig"_Secure, "God Vehicle"_Secure);
int Global::accarsuperman = ini1->GetInt("AutoOnConfig"_Secure, "Car Superman"_Secure);
int Global::acspeedometerMPH = ini1->GetInt("AutoOnConfig"_Secure, "MPH Speedometer"_Secure);
int Global::acspeedometerKMPH = ini1->GetInt("AutoOnConfig"_Secure, "KMPH Speedometer"_Secure);
int Global::acbulletprooftires = ini1->GetInt("AutoOnConfig"_Secure, "Bulletproof Tires"_Secure);
int Global::achornboost = ini1->GetInt("AutoOnConfig"_Secure, "Horn Boost"_Secure);
int Global::acdriveonwater = ini1->GetInt("AutoOnConfig"_Secure, "Drive on Water"_Secure);
int Global::acenginealwayson = ini1->GetInt("AutoOnConfig"_Secure, "Engine always On"_Secure);
int Global::acnofallfrombike = ini1->GetInt("AutoOnConfig"_Secure, "No Fall from Bike"_Secure);




bool Global::FileExists(const char* filename)
{
	FILE* fp = NULL;

	fp = fopen(filename, "rb");
	if (fp == NULL)
		return false;

	fclose(fp);
	return true;
}


void Global::CheckCfig()
{
	string target = Global::target();
	const char* file = target.c_str();
	if (Global::FileExists(file))
	{
		Global::Ini* ini = new Global::Ini(target);
		Global::cgodmode = ini->GetInt("Config"_Secure, "Godmode"_Secure);
		Global::ctpwaypoint = ini->GetInt("Config"_Secure, "TP to Waypoint"_Secure);
		Global::ctpobj = ini->GetInt("Config"_Secure, "TP to Objective"_Secure);
		Global::cinvisible = ini->GetInt("Config"_Secure, "Invisible"_Secure);
		Global::csuperjump = ini->GetInt("Config"_Secure, "Super Jump"_Secure);
		Global::cfastrun = ini->GetInt("Config"_Secure, "Fast Run"_Secure);
		Global::cfastswim = ini->GetInt("Config"_Secure, "Fast Swim"_Secure);
		Global::cnoragdoll = ini->GetInt("Config"_Secure, "No Rag Doll"_Secure);
		Global::cnoclip = ini->GetInt("Config"_Secure, "No Clip"_Secure);
		Global::cesp = ini->GetInt("Config"_Secure, "ESP"_Secure);
		Global::cshowcoords = ini->GetInt("Config"_Secure, "Show Coordinates"_Secure);
		Global::csavecoords = ini->GetInt("Config"_Secure, "Save Coordinates"_Secure);
		Global::cgodvehicle = ini->GetInt("Config"_Secure, "God Vehicle"_Secure);
		Global::crepairvehicle = ini->GetInt("Config"_Secure, "Repair Vehicle"_Secure);
		Global::cmaxvehicle = ini->GetInt("Config"_Secure, "Max Vehicle"_Secure);
		Global::cselfdrive = ini->GetInt("Config"_Secure, "Self Drive"_Secure);
		Global::ccarsuperman = ini->GetInt("Config"_Secure, "Car Superman"_Secure);
		Global::ctpintolastvehicle = ini->GetInt("Config"_Secure, "TP into Last Vehicle"_Secure);
		Global::ctpintoclosestvehicle = ini->GetInt("Config"_Secure, "TP into Closest Vehicle"_Secure);
		Global::cflipcar = ini->GetInt("Config"_Secure, "Flip Car"_Secure);
		Global::cspeedometerMPH = ini->GetInt("Config"_Secure, "MPH Speedometer"_Secure);
		Global::cspeedometerKMPH = ini->GetInt("Config"_Secure, "KMPH Speedometer"_Secure);
		Global::cbulletprooftires = ini->GetInt("Config"_Secure, "Bulletproof Tires"_Secure);
		Global::chornboost = ini->GetInt("Config"_Secure, "Horn Boost"_Secure);
		Global::cdriveonwater = ini->GetInt("Config"_Secure, "Drive on Water"_Secure);
		Global::cenginealwayson = ini->GetInt("Config"_Secure, "Engine always On"_Secure);
		Global::cnofallfrombike = ini->GetInt("Config"_Secure, "No Fall from Bike"_Secure);
	}
}

wstring Global::Widen(const string& source)
{
	wostringstream target;
	const ctype<wchar_t>& ctfacet = use_facet<ctype<wchar_t>>(target.getloc());

	for (size_t i = 0; i < source.size(); ++i)
		target << ctfacet.widen(source[i]);

	return target.str();
}

string Global::Narrow(const wstring& source)
{
	ostringstream target;
	const ctype<char>& ctfacet = use_facet<ctype<char>>(target.getloc());

	for (size_t i = 0; i < source.size(); ++i)
		target << ctfacet.narrow(source[i], 0);

	return target.str();
}

char* Global::WstringToChar(std::wstring source)
{
	wstring s2(source);
	char *target = new char[0x1000];
	sprintf(target, "%ls", s2.c_str());

	return target;
}

char* Global::cprintf(const char* fmt, ...)
{
	char cprintfBuffer[0x2000];
	memset(cprintfBuffer, 0, 0x2000);
	va_list ap;
	va_start(ap, fmt);
	vsprintf(cprintfBuffer, fmt, ap);
	va_end(ap);

	return cprintfBuffer;
}

Global* Global::instance = 0;
Global* Global::getInstance() {
	if (!instance)
		instance = new Global();

	return instance;
}

void Global::LoadPlugin(const std::string& asiSearchFolder) 
{
	wchar_t path[MAX_PATH];
	char target2[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result == S_OK)
		wcstombs(target2, path, MAX_PATH);
	strcat(target2, "\\AztralFiles\\asi\\*.asi"_Secure);
	wstring asiSearchQuery = Global::Widen(target2);
	WIN32_FIND_DATAW ffd;
	HANDLE hFind = FindFirstFileW(asiSearchQuery.c_str(), &ffd);
	if (hFind != INVALID_HANDLE_VALUE)
	{

		do {

			std::wstring pluginPath = ffd.cFileName;

			Log::Msg(Global::Narrow(pluginPath).c_str());

			// Load Image
			HMODULE module = LoadLibrary(pluginPath.c_str());
			if (module) 
			{
				Log::Msg("\tLoaded \"%s\" => 0x%p", ffd.cFileName, module);
				PlaySound(L"C:\\WINDOWS\\Media\\ding.wav", NULL, SND_ASYNC);
			}
			else 
			{
				DWORD errorMessageID = ::GetLastError();
				if (errorMessageID)
				{
					LPSTR messageBuffer = nullptr;
					size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
					std::string message(messageBuffer, size);
					//Free the buffer.
					LocalFree(messageBuffer);
					Log::Msg("\tFailed to load: %s", message.c_str());
				}
				else Log::Msg("\tFailed to load");
				PlaySound(L"C:\\WINDOWS\\Media\\chord.wav", NULL, SND_ASYNC);
			}

		} while (FindNextFileW(hFind, &ffd));

		FindClose(hFind);
	}
	else
		Log::Msg("INVALID FOLDER!");
}



/*
===========================================================
Custom Headers
===========================================================
*/


