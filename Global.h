#pragma once

#include "stdafx.h"
#include "resource1.h"

class Global
{
private:
	Global() { };
	
	// Static class constructors are *always* private
	static Global *instance;


public:
	static string target()
	{
		wchar_t path[MAX_PATH];
		char target[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
		if (result == S_OK)
			wcstombs(target, path, MAX_PATH);
		strcat(target, "\\AztralFiles\\Config.ini"_Secure);
		return target;
	}

	static string target1()
	{
		wchar_t path[MAX_PATH];
		char target1[MAX_PATH];
		HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
		if (result == S_OK)
			wcstombs(target1, path, MAX_PATH);
		strcat(target1, "\\AztralFiles\\AutoOnConfig.ini"_Secure);
		return target1;
	}

	static wstring BASEURL;
	static wstring INI_FILE;
	static wstring AUTH;
	static wstring AUTH2;

	class Ini;
	static bool FileExists(const char* filename);
	static void CheckCfig();
	
	static int cgodmode;
	static int ctpwaypoint;
	static int ctpobj;
	static int cinvisible;
	static int csuperjump;
	static int cfastrun;
	static int cfastswim;
	static int cnoragdoll;
	static int cnoclip;
	static int cgiveallweapons;
	static int cesp;
	static int cshowcoords;
	static int csavecoords;
	static int cgodvehicle;
	static int crepairvehicle;
	static int cmaxvehicle;
	static int cselfdrive;
	static int ccarsuperman;
	static int ctpintolastvehicle;
	static int ctpintoclosestvehicle;
	static int cflipcar;
	static int cspeedometerMPH;
	static int cspeedometerKMPH;
	static int cbulletprooftires;
	static int chornboost;
	static int cdriveonwater;
	static int cenginealwayson;
	static int cnofallfrombike;	


	static int acgodmode;
	static int acinvisible;
	static int acsuperjump;
	static int acfastrun;
	static int acfastswim;
	static int acnoragdoll;
	static int acnoclip;
	static int acesp;
	static int acshowcoords;
	static int acgodvehicle;
	static int accarsuperman;
	static int acspeedometerMPH;
	static int acspeedometerKMPH;
	static int acbulletprooftires;
	static int achornboost;
	static int acdriveonwater;
	static int acenginealwayson;
	static int acnofallfrombike;

	static wstring Widen(const string& source);

	static string Narrow(const wstring& source);

	static char* WstringToChar(std::wstring source);


	static char* Global::cprintf(const char* fmt, ...);

	static void LoadPlugin(const std::string& asiSearchFolder);

	static BYTE rawData[];

	static Global *getInstance();
};

static unsigned char VLogo[319528];

static unsigned char PuristaFont[319528];


