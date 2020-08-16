//Hooking.cpp
#pragma once
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include <mmsystem.h> //PlaySound
#include "MinHook.h"
#include "Global.h"
#include "Detour.h"
#include "detours/include/detours.h"
#include "D3d11Hook.h"
#include "Hooking/Pools.h"
#include "Hooking/Hook.h"

#pragma comment(lib, "shell32.lib")





std::string input1 = "data";
std::string hash1 = sw::sha512::calculate(input1);

/*
//Init static public members
*/
std::vector<LPVOID>					Hooking::m_hooks;
uint64_t*							Hooking::m_frameCount;
fpIsDLCPresent                      Hooking::is_DLC_present;
fpDrawNotification					Hooking::draw_notification;
fpGetNetworkTime					Hooking::get_network_time;
CPlayers*							Hooking::m_players;
fpStatSetInt						Hooking::stat_set_int;
fpStatSetFloat						Hooking::stat_set_float;
fpStatSetBool						Hooking::stat_set_bool;
fpStatSetDate						Hooking::stat_set_date;
fpStatGetInt						Hooking::stat_get_int;
fpNetworkIsSessionStarted			Hooking::network_is_session_started;
fpSetMobileRadio					Hooking::set_mobile_radio;
fpRequestModel						Hooking::request_model;
fpHasModelLoaded					Hooking::has_model_loaded;
fpSetVehicleForwardSpeed			Hooking::set_vehicle_forward_speed;
fpIsModelValid						Hooking::is_model_valid;
fpIsModelInCdimage					Hooking::is_model_in_cdimage;
fpIsModelAVehicle					Hooking::is_model_a_vehicle;
fpClearPedTasksImmediately			Hooking::clear_ped_tasks_immediately;
fpPtrToHandle						Hooking::ptr_to_handle;
fpTriggerScriptEvent				Hooking::trigger_script_event;
fpNetworkHasControlOfEntity			Hooking::network_has_control_of_entity;
fpNetworkRequestControlOfEntity		Hooking::network_request_control_of_entity;
fpNetworkGetNetworkIdFromEntity		Hooking::network_get_network_id_from_entity;
fpNetworkHasControlOfNetworkId		Hooking::network_has_control_of_network_id;
fpNetworkRequestControlOfNetworkId	Hooking::network_request_control_of_network_id;
fpSetNetworkIdCanMigrate			Hooking::set_network_id_can_migrate;
fpNetworkCreateSynchronisedScene	Hooking::network_create_synchronised_scene;
fpNetworkAddPedToSynchronisedScene	Hooking::network_add_ped_to_synchronised_scene;
fpNetworkStartSynchronisedScene		Hooking::network_start_synchronised_scene;
MemoryPool**						Hooking::m_entityPool;
MemoryPool**						Hooking::m_pedPool;
fpNetworkOverrideClockTime			Hooking::network_override_clock_time;
queue_int							CHack::m_nearbyPed;
queue_int							CHack::m_nearbyVehicle;
queue_int							CHack::m_entityCleanup;
fpAddTextCompSubstrPlayerName		Hooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText				Hooking::end_text_cmd_display_text;
fpBeginTextCmdDisplayText			Hooking::begin_text_cmd_display_text;


std::string input2 = "hhwgwgfwes";
std::string hash2 = sw::sha512::calculate(input2);
/*
//CPatternResult
*/
CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}
std::string input3 = "lyuhjthsg";
std::string hash3 = sw::sha512::calculate(input3);
/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern."_Secure, name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}
std::string input4 = "urhegwshghn";
std::string hash4 = sw::sha512::calculate(input4);
/*
//CMetaData
*/
uint64_t	CMetaData::m_begin = 0;
uint64_t	CMetaData::m_end = 0;
DWORD		CMetaData::m_size = 0;

uint64_t	CMetaData::begin()
{
	return m_begin;
}
uint64_t	CMetaData::end()
{
	return m_end;
}
DWORD		CMetaData::size()
{
	return m_size;
}

void		CMetaData::init()
{
	if (m_begin && m_size)
		return;

	m_begin = (uint64_t)GetModuleHandleA(nullptr);
	const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
	const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
	m_size = headerNt->OptionalHeader.SizeOfCode;
	m_end = m_begin + m_size;
	return;
}

int FrameCount = 0;
typedef bool(*pIsDlcPresent)(Hash);
pIsDlcPresent OG_IS_DLC_PRESENT = nullptr;
BOOL HK_IS_DLC_PRESENT(Hash hash)
{
	if (FrameCount < *Hooking::m_frameCount) {
		FrameCount = *Hooking::m_frameCount;
		Hooking::onTickInit();
	}
	Hash DlcHash = hash;

	if (DlcHash == 2532323046 || DlcHash == -1762644250) { // DEV
								 // game requested dev dlc -> return true;
		return true;
	}
	else
	{
		return OG_IS_DLC_PRESENT(hash);
	}
	
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
unitptr_t FindPattern
*/

struct ScriptHeader
{
	char padding1[16];					//0x0
	unsigned char** codeBlocksOffset;	//0x10
	char padding2[4];					//0x18
	int codeLength;						//0x1C
	char padding3[4];					//0x20
	int localCount;						//0x24
	char padding4[4];					//0x28
	int nativeCount;					//0x2C
	__int64* localOffset;				//0x30
	char padding5[8];					//0x38
	__int64* nativeOffset;				//0x40
	char padding6[16];					//0x48
	int nameHash;						//0x58
	char padding7[4];					//0x5C
	char* name;							//0x60
	char** stringsOffset;				//0x68
	int stringSize;						//0x70
	char padding8[12];					//0x74
										//END_OF_HEADER

	bool IsValid() const { return codeLength > 0; }
	int CodePageCount() const { return (codeLength + 0x3FFF) >> 14; }
	int GetCodePageSize(int page) const
	{
		return (page < 0 || page >= CodePageCount() ? 0 : (page == CodePageCount() - 1) ? codeLength & 0x3FFF : 0x4000);
	}
	unsigned char* GetCodePageAddress(int page) const { return codeBlocksOffset[page]; }
	unsigned char* GetCodePositionAddress(int codePosition) const
	{
		return codePosition < 0 || codePosition >= codeLength ? NULL : &codeBlocksOffset[codePosition >> 14][codePosition & 0x3FFF];
	}
	char* GetString(int stringPosition)const
	{
		return stringPosition < 0 || stringPosition >= stringSize ? NULL : &stringsOffset[stringPosition >> 14][stringPosition & 0x3FFF];
	}

};
struct ScriptTableItem
{
	ScriptHeader* Header;
	char padding[4];
	int hash;

	inline bool IsLoaded() const
	{
		return Header != NULL;
	}
};

struct ScriptTable
{
	ScriptTableItem* TablePtr;
	char padding[16];
	int count;
	ScriptTableItem* FindScript(int hash)
	{
		if (TablePtr == NULL)
		{
			return NULL;//table initialisation hasnt happened yet
		}
		for (int i = 0; i<count; i++)
		{
			if (TablePtr[i].hash == hash)
			{
				return &TablePtr[i];
			}
		}
		return NULL;
	}
};

struct GlobalTable
{
	__int64** GlobalBasePtr;
	__int64* AddressOf(int index) const { return &GlobalBasePtr[index >> 18 & 0x3F][index & 0x3FFFF]; }
	bool IsInitialised()const { return *GlobalBasePtr != NULL; }
};
struct HashPair
{
	int modelHash;
	int DispHash;
};

std::vector<HashPair> CarHashes;
ScriptTable* scriptTable;
GlobalTable globalTable;
ScriptHeader* cheatController;
ScriptHeader* shopController;
std::string input5 = "hfdhjdrhhws";
std::string hash5 = sw::sha512::calculate(input5);
__int64(*GetModelInfo)(int, __int64);//used to extract display names without actually calling natives
int displayNameOffset;//the offset where the display name is stored relative to the address received above changes per game build, so its safer to read the offset from a signature
int(*GetHashKey)(char*, unsigned int);//just use the in game hashing function to save writing my own
uintptr_t FindPattern(const char *pattern, const char *mask, const char* startAddress, size_t size)
{
	const char* address_end = startAddress + size;
	const auto mask_length = static_cast<size_t>(strlen(mask) - 1);

	for (size_t i = 0; startAddress < address_end; startAddress++)
	{
		if (*startAddress == pattern[i] || mask[i] == '?')
		{
			if (mask[i + 1] == '\0')
			{
				return reinterpret_cast<uintptr_t>(startAddress) - mask_length;
			}

			i++;
		}
		else
		{
			i = 0;
		}
	}

	return 0;
}

uintptr_t FindPattern(const char *pattern, const char *mask)
{
	MODULEINFO module = {};
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(nullptr), &module, sizeof(MODULEINFO));
	std::string input6 = "nfjrthwshgsw";
	std::string hash6 = sw::sha512::calculate(input6);
	return FindPattern(pattern, mask, reinterpret_cast<const char *>(module.lpBaseOfDll), module.SizeOfImage);
}
void Hooking::FindScriptAddresses()
{

	while (*(__int64*)scriptTable == 0)
	{
		Sleep(100);
	}
	DEBUGMSG("Found script base pointer %llX"_Secure, (__int64)scriptTable);
	ScriptTableItem* Item = scriptTable->FindScript(0x39DA738B);
	if (Item == NULL)
	{
		Log::Msg("ERROR: finding address 2"_Secure);
		Log::Msg("Aborting..."_Secure);
		exit(0);
	}
	while (!Item->IsLoaded())
	{
		Sleep(100);
	}
	shopController = Item->Header;

	Item = scriptTable->FindScript(0xAFD9916D);
	if (Item == NULL)
	{
		Log::Msg("ERROR: finding address 3"_Secure);
		Log::Msg("Aborting..."_Secure);
		exit(0);
	}
	while (!Item->IsLoaded())
	{
		Sleep(100);
	}
	cheatController = Item->Header;
}
void Hooking::FindPattern2() {
	__int64 patternAddr = FindPattern("\x4C\x8D\x05\x00\x00\x00\x00\x4D\x8B\x08\x4D\x85\xC9\x74\x11", "xxx????xxxxxxxx");
	if (!patternAddr)
	{
		Log::Msg("ERROR: finding address 0"_Secure);
		Log::Msg("Aborting..."_Secure);
		exit(0);
	}
	globalTable.GlobalBasePtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	DoASM();
	patternAddr = FindPattern("\x48\x03\x15\x00\x00\x00\x00\x4C\x23\xC2\x49\x8B\x08", "xxx????xxxxxx");
	if (!patternAddr)
	{
		Log::Msg("ERROR: finding address 1"_Secure);
		Log::Msg("Aborting..."_Secure);
		exit(0);
	}
	scriptTable = (ScriptTable*)(patternAddr + *(int*)(patternAddr + 3) + 7);
	DoASM();

	patternAddr = FindPattern("\x80\xF9\x05\x75\x08\x48\x05\x00\x00\x00\x00", "xxxxxxx????");
	GetModelInfo = (__int64(*)(int, __int64))(*(int*)(patternAddr - 0x12) + patternAddr - 0x12 + 0x4);
	displayNameOffset = *(int*)(patternAddr + 0x7);
	__int64 getHashKeyPattern = FindPattern("\x48\x8B\x0B\x33\xD2\xE8\x00\x00\x00\x00\x89\x03", "xxxxxx????xx");
	GetHashKey = reinterpret_cast<int(*)(char*, unsigned int)>(*reinterpret_cast<int*>(getHashKeyPattern + 6) + getHashKeyPattern + 10);
	std::string input7 = "nygktyjegws";
	std::string hash7 = sw::sha512::calculate(input7);
	while (!globalTable.IsInitialised())Sleep(100);//Wait for GlobalInitialisation before continuing
	DEBUGMSG("Found global base pointer %llX"_Secure, (__int64)globalTable.GlobalBasePtr);
}


void Hooking::EnableCarsGlobal()
{
	DoASM();
	for (int i = 0; i < shopController->CodePageCount(); i++)
	{
		__int64 sigAddress = FindPattern("\x28\x26\xCE\x6B\x86\x39\x03", "xxxxxxx", (const char*)shopController->GetCodePageAddress(i), shopController->GetCodePageSize(i));
		if (!sigAddress)
		{
			continue;
		}
		DEBUGMSG("Pattern Found in codepage %d at memory address %llX"_Secure, i, sigAddress);
		int RealCodeOff = (int)(sigAddress - (__int64)shopController->GetCodePageAddress(i) + (i << 14));
		for (int j = 0; j < 2000; j++)
		{
			if (*(int*)shopController->GetCodePositionAddress(RealCodeOff - j) == 0x0008012D)
			{
				int funcOff = *(int*)shopController->GetCodePositionAddress(RealCodeOff - j + 6) & 0xFFFFFF;
				DEBUGMSG("found Function codepage address at %x"_Secure, funcOff);
				for (int k = 0x5; k < 0x40; k++)
				{
					if ((*(int*)shopController->GetCodePositionAddress(funcOff + k) & 0xFFFFFF) == 0x01002E)
					{
						for (k = k + 1; k < 30; k++)
						{
							if (*(unsigned char*)shopController->GetCodePositionAddress(funcOff + k) == 0x5F)
							{
								int globalindex = *(int*)shopController->GetCodePositionAddress(funcOff + k + 1) & 0xFFFFFF;
								DEBUGMSG("Found Global Variable %d, address = %llX"_Secure, globalindex, (__int64)globalTable.AddressOf(globalindex));
								Log::Msg("Setting Global Variable %d to true"_Secure, globalindex);
								*globalTable.AddressOf(globalindex) = 1;
								Log::Msg("MP Cars enabled"_Secure);
								return;
							}
						}
						break;
					}
				}
				break;
			}
		}
		break;
	}
	Log::Msg("Global Variable not found, check game version >= 1.0.678.1"_Secure);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace Memory;

ScriptThread*(*GetActiveThread)() = nullptr;
HMODULE _hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;

static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static BlipList*											m_blipList;
static Hooking::NativeRegistration**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;



static void* EventPtr[REVENT_END] = { nullptr };
static unsigned char EventRestore[REVENT_END] = { 0 };





/* Start Hooking */
void Hooking::Start(HMODULE hmoduleDLL)
{
	DoASM();
	_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	DoASM();
	std::string input9 = "brdhrtejgg";
	std::string hash9 = sw::sha512::calculate(input9);
	DoASM();
	printf("MH Init \n");
	if (MH_Initialize() != MH_OK) {
		Log::Error("MinHook failed to initialize"_Secure);
	}
	DoASM();
	FindPatterns();
	DoASM();
	FindPattern2();
	DoASM();
	FindScriptAddresses();
	DoASM();
	EnableCarsGlobal();
	DoASM();
	if (!InitializeHooks()) {
		printf("Init Hooks Failed \n");
		Cleanup();
	}
	printf("Init Pools Start \n");
	DoASM();
	internal::InitPools();
	printf("Init Pools End \n");
	PlaySound(L"C:\\WINDOWS\\Media\\tada.wav", NULL, SND_ASYNC);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Ini
{
private:
	std::string inifile;
public:
	Ini(std::string file)
	{
		this->inifile = file;
	}

	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	std::string GetString(std::string app, std::string key)
	{
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());
		return (std::string)buf;
	}

	void WriteInt(int value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	int GetInt(std::string app, std::string key)
	{
		return std::stoi(GetString(app, key));
	}

	void WriteFloat(float value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	float GetFloat(std::string app, std::string key)
	{
		return std::stof(GetString(app, key));
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;
	printf("Auth \n");
	std::string input10 = "htrjrtjwv";
	std::string hash10 = sw::sha512::calculate(input10);
	wchar_t path[MAX_PATH];
	char target[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result != S_OK)
		returnVal = FALSE;
	else
		wcstombs(target, path, MAX_PATH);
	string folder = target;
	strcat(target, "\\AztralFiles\\login.ini"_Secure);
	DoASM();
	Ini *settingsINI = new Ini(target);
	string name = settingsINI->GetString("Login"_Secure, "User"_Secure);
	string pw = settingsINI->GetString("Login"_Secure, "Pass"_Secure);
	string ver = ("Legacy"_Secure);
	string ver3 = ("DEVELOPER"_Secure);

	//is_user_authed(name, pw, ver);
	DoASM();
	if (!is_user_authed(name, pw, ver) && !is_user_authed(name, pw, ver3)) {
		Global::BASEURL = L"https://elysianmenu.com"_Secure;
		//is_user_authed(name, pw, ver);
		if (!is_user_authed(name, pw, ver) && !is_user_authed(name, pw, ver3)) {
			Log::Fatal("Contact an Aztral admin on Discord"_Secure);
			exit(0);
		}
	}
	DoASM();
	std::string input11 = "gewrngiownfqinwigw";
	std::string hash11 = sw::sha512::calculate(input11);

	
	printf("iHook \n");
	DoASM();
	if (!iHook.Initialize()) {

		Log::Error("Failed to initialize InputHook"_Secure);
		returnVal = FALSE;
	}
	DoASM();
	printf("Hook Natives \n");
	if (!HookNatives()) {

		Log::Error("Failed to initialize NativeHooks"_Secure);
		returnVal = FALSE;
	}
	DoASM();
	//Global::LoadPlugin(folder);
	return returnVal;
}

template <typename T>

bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
		return true;
	auto originalFunction = Hooking::GetNativeHandler(hash);
	if (originalFunction != 0) {
		MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
		if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
		{
			m_hookedNative.push_back((LPVOID)originalFunction);
			printf("Hooked Native 0x%#p  \n"_Secure, hash);
			return true;
		}
	}

	return false;
}


Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext *cxt)
{
	static int lastThread = 0;
	int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
	if (!lastThread)
	{
		char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
		if (strcmp(name, "main_persistent") == 0)
		{
			lastThread = threadId;
			printf("Hooked Script NAME: %s ID: %i", name, threadId);
		}
	}
	if (threadId == lastThread) Hooking::onTickInit();
	ORIG_WAIT(cxt);
	return cxt;
}

Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->GetArgument<int>(0);
	if (player == PLAYER::PLAYER_ID())
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->GetArgument<Ped>(0) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}

BlipList* Hooking::GetBlipList()
{
	return m_blipList;
}




typedef BOOL(*pDrawNotification)(bool blink, bool unk0, bool unk1);
pDrawNotification ORIG_DRAW_NOTIFICATION = nullptr;
BOOL HK_DRAW_NOTIFICATION(bool blink, bool unk0, bool unk1)
{
	if (FrameCount < *Hooking::m_frameCount) {
		FrameCount = *Hooking::m_frameCount;
		Hooking::onTickInit();
	}
	
	return ORIG_DRAW_NOTIFICATION(blink, unk0, unk1);

}

typedef uint64_t(*pGetNetworkTime)();
pGetNetworkTime ORIG_GET_NETWORK_TIME = nullptr;
uint64_t HK_GET_NETWORK_TIME()
{
	int gamecount = *Hooking::m_frameCount;
	printf("HK Get Net Time \n");
	if (FrameCount < gamecount) {
		FrameCount = gamecount;
		printf("Frame Count IF");
		Hooking::onTickInit();
	}

	return ORIG_GET_NETWORK_TIME();
}


bool Hooking::HookNatives()
{
	DoASM();
	printf("%s called, Hooking::is_DLC_present: 0x%llx\n", __FUNCTION__, Hooking::is_DLC_present);
	MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
	DoASM();
	MH_STATUS returnstatus = MH_EnableHook(Hooking::is_DLC_present);
	if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || returnstatus != MH_OK)
	{
		printf("MH Enable Hook Failed \n");
		return false;
	}
	DoASM();
	printf("MH Enable Hook Succeded \n");
	Hooking::m_hooks.push_back(Hooking::is_DLC_present);
	DoASM();
	return true;
		//&& Native(0x4EDE34FBADD967A6, &MY_WAIT, &ORIG_WAIT);
}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	printf("Script Function \n");
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		Log::Fatal("Failed scriptFiber");
	}
}

void Hooking::onTickInit()
{
	if (mainFiber == nullptr)
		mainFiber = ConvertThreadToFiber(nullptr);

	if (timeGetTime() < wakeAt)
		return;

	static HANDLE scriptFiber;
	if (scriptFiber)
		SwitchToFiber(scriptFiber);
	else
		scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s"_Secure, name);
	Log::Error(buf);
	Cleanup();
}

void Hooking::FindPatterns()
{
	Log::Msg("FP Start");
	HANDLE steam = GetModuleHandleA("steam_api64.dll"_Secure);

	HANDLE Base = GetModuleHandleA("GTA5.exe"_Secure);

	//Sleep(15000);

	//auto p_D3D11CreateDevice = pattern("48 8D 15 ? ? ? ? 48 8B C8 FF 15 ? ? ? ? B9 ? ? ? ? 48 85 C0 0F 45 D9 48 8B CF FF 15 ? ? ? ? 81 FB ? ? ? ? 75 39 48 8D 0D ? ? ? ? FF 15 ? ? ? ? 48 8B F8 48 85 C0 74 24");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//if (!g_D3DHook.InitializeHooks())
	//{
	//	Log::Error("Failed to Initialize Direct3d Hooks");
	//}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	DoASM();
	std::string input12 = "gwskgnweifnfiqfqnfifn";
	std::string hash12 = sw::sha512::calculate(input12);
	DoASM();
	auto p_activeThread = pattern("8B 15 ? ? ? ? 48 8B 05 ? ? ? ? FF ? 48");//E8 ? ? ? ? 48 8B 88 10 01 00 00
	DoASM();
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	DoASM();
	auto p_fixVector3Result = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
	DoASM();
	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	//p_gameLegals.nop(2);



	DoASM();
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	DoASM();
	auto p_gameState = pattern("83 3D ? ? ? ? ? 8A D9 74 0A");
	DoASM();
	auto p_modelCheck = pattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	DoASM();
	auto p_modelSpawn = pattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	DoASM();
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D"); 
	DoASM();
	//auto p_nativeTable = pattern("76 61 49 8B 7A 40 48 8D 0D");
	auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	DoASM();
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	DoASM();
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ?");
	DoASM();
	//auto p_is_DLC_present = pattern("8B 15 ? ? ? ? ? ? ? ? 41 FF CF");

	//frame count
	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);
	DoASM();
	//replay interface
	setPat<CReplayInterface>("replay interface",
		"\x48\x8D\x05\x00\x00\x00\x00\x48\x8D\x8F\x00\x00\x00\x00\x48\x89\x07\x48\x89\x9F\x00\x00\x00\x00\x48\x89\x9F\x00\x00\x00\x00\x48\x89\x9F\x00\x00\x00\x00",
		"xxx????xxx????xxxxxx????xxx????xxx????",
		&m_replayIntf,
		true,
		3,
		1);
	DoASM();
	//player list
	setPat<CPlayers>("player list",
		"\x48\x8D\x0D\x00\x00\x00\x00\x48\x89\x78\x08\x48\x89\x08\x89\x58\x10",
		"xxx????xxxxxxxxxx",
		&Hooking::m_players,
		true,
		3);
	DoASM();

	//useless book native for hooking
	setFn<fpIsDLCPresent>("is_DLC_present",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
		"xxxx?xxxxxxx????",
		&Hooking::is_DLC_present);

	/////////////////////////////////////////////////////////////////////////
	/*HOOKING NATIVE*/
	/////////////////////////////////////////////////////////////////////////

	//draw_notification
	setFn<fpDrawNotification>("draw_notification",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
		"xxxx?xxxx?xxxx????xx?????xxx",
		&Hooking::draw_notification);

	//get_network_time
	setFn<fpGetNetworkTime>("get_network_time",
		"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19",
		"xxxxxxxxx????x????xxxx",
		&Hooking::get_network_time);

	//add_text_comp_substr_playername
	setFn<fpAddTextCompSubstrPlayerName>("add_text_comp_substr_playername",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
		"xxxx?xxxx?xxxx?xxxxxxx????xxx",
		&Hooking::add_text_comp_substr_playername);

	//end_text_cmd_display_text
	setFn<fpEndTextCmdDisplayText>("end_text_cmd_display_text",
		"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
		"xxxxxxxxxx?xxxx?xxx",
		&Hooking::end_text_cmd_display_text);

	//begin_text_cmd_display_text
	setFn<fpBeginTextCmdDisplayText>("begin_text_cmd_display_text",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
		"xxxxx????x????xxxxx",
		&Hooking::begin_text_cmd_display_text);

	/////////////////////////////////////////////////////////////////////////


	DoASM();
	//stat_set_int
	setFn<fpStatSetInt>("stat_set_int",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x89\x54\x24\x10\x55\x57\x41\x57",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::stat_set_int);
	DoASM();
	//stat_set_float
	setFn<fpStatSetFloat>("stat_set_float",
		"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
		"xxxx?xxxxx?xxxxx",
		&Hooking::stat_set_float);

	DoASM();
	//stat_set_bool
	setFn<fpStatSetBool>("stat_set_bool",
		"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
		"xxxx?xxxxxxxxx",
		&Hooking::stat_set_bool);
	DoASM();
	//stat_set_date
	setFn<fpStatSetDate>("stat_set_date",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x60\x48\x8B\xDA\x8B\xF9",
		"xxxx?xxxx?xxxxxxxxxx",
		&Hooking::stat_set_date);
	DoASM();
	//stat_get_int
	setFn<fpStatGetInt>("stat_get_int",
		"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
		"xxxxxxxxxxxxxxxxxxx",
		&Hooking::stat_get_int);
	DoASM();
	//network_is_session_started
	setFn<fpNetworkIsSessionStarted>("network_is_session_started",
		"\x48\x8B\x0D\x00\x00\x00\x00\x33\xC0\x48\x85\xC9\x74\x0E\x83\xB9\x00\x00\x00\x00\x00\x75\x05",
		"xxx????xxxxxxxxx?????xx",
		&Hooking::network_is_session_started);
	DoASM();
	//set_mobile_radio
	setFn<fpSetMobileRadio>("set_mobile_radio",
		"\x40\x53\x48\x83\xEC\x20\x8A\xD9\x48\x8D\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8D\x0D\x00\x00\x00\x00\x8B\xD0\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x10",
		"xxxxxxxxxxx????x????xxx????xxx????xxxxx",
		&Hooking::set_mobile_radio);
	DoASM();
	//request_model
	setFn<fpRequestModel>("request_model",
		"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
		"xxxx?xxxx?xxxxxxxxxxx",
		&Hooking::request_model);
	DoASM();
	//has_model_loaded
	setFn<fpHasModelLoaded>("has_model_loaded",
		"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
		"xxxx?xxxxxxxxxxxx",
		&Hooking::has_model_loaded);
	DoASM();
	//set_vehicle_forward_speed
	setFn<fpSetVehicleForwardSpeed>("set_vehicle_forward_speed",
		"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x48\x8B\xD9\x0F\x28\xF1\xE8\x00\x00\x00\x00\x48\x8B\x03",
		"xxxxxxxxxx?xxxxxxx????xxx",
		&Hooking::set_vehicle_forward_speed);
	DoASM();
	//is_model_valid
	setFn<fpIsModelValid>("is_model_valid",
		"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x0F\xB7\xC8",
		"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxx",
		&Hooking::is_model_valid);
	DoASM();
	//is_model_in_cdimage
	setFn<fpIsModelInCdimage>("is_model_in_cdimage",
		"\x48\x83\xEC\x28\x8B\x44\x24\x38\x48\x8D\x54\x24\x00\xC7\x44\x24\x00\x00\x00\x00\x00\x0D\x00\x00\x00\x00\x25\x00\x00\x00\x00\x89\x44\x24\x38\xE8\x00\x00\x00\x00\x0F\xB7\x44\x24\x00\x66\x89\x44\x24\x00\x8B\x44\x24\x38\x0D\x00\x00\x00\x00\x0F\xBA\xF0\x1C\x89\x44\x24\x38",
		"xxxxxxxxxxxx?xxx?????x????x????xxxxx????xxxx?xxxx?xxxxx????xxxxxxxx",
		&Hooking::is_model_in_cdimage);
	DoASM();
	//is_model_a_vehicle
	setFn<fpIsModelAVehicle>("is_model_a_vehicle",
		"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0",
		"xxxxxxxxxx?xxxxx?????x????xxx",
		&Hooking::is_model_a_vehicle);
	DoASM();
	//clear_ped_tasks_immediately
	setFn<fpClearPedTasksImmediately>("clear_ped_tasks_immediately",
		"\x40\x53\x48\x83\xEC\x30\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x0F\x84",
		"xxxxxxx????xxxxxxxx",
		&Hooking::clear_ped_tasks_immediately);
	DoASM();
	//ptr_to_handle
	setFn<fpPtrToHandle>("ptr_to_handle",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
		"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
		&Hooking::ptr_to_handle);
	DoASM();
	//trigger_script_event
	setFn<fpTriggerScriptEvent>("trigger_script_event",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",
		"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx",
		&Hooking::trigger_script_event);
	DoASM();
	//entity pool
	setPat<MemoryPool*>("entity pool",
		"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
		"xxx????xxxxxxx",
		&Hooking::m_entityPool,
		true,
		3);
	DoASM();
	//ped pool
	setPat<MemoryPool*>("ped pool",
		"\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10",
		"xxx????xxxxxxxx",
		&Hooking::m_pedPool,
		true,
		3);
	DoASM();
	//network_has_control_of_entity
	setFn<fpNetworkHasControlOfEntity>("network_has_control_of_entity",
		"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1F\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x0F",
		"xxxxx????xxxxxxxx????xxxxx",
		&Hooking::network_has_control_of_entity);
	DoASM();
	//network_request_control_of_entity
	setFn<fpNetworkHasControlOfEntity>("network_request_control_of_entity",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
		"xxxx?xxxxxxxx????xx",
		&Hooking::network_request_control_of_entity);
	DoASM();
	std::string input13 = "gfwhfgiohfiwifoqoq";
	std::string hash13 = sw::sha512::calculate(input13);
	DoASM();
	//network_get_network_id_from_entity
	setFn<fpNetworkGetNetworkIdFromEntity>("network_get_network_id_from_entity",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x33\xDB\x48\x8B\xF8\x48\x85\xC0\x74\x16",
		"xxxx?xxxxxx????xxxxxxxxxx",
		&Hooking::network_get_network_id_from_entity);
	DoASM();
	//network_request_control_of_network_id
	setFn<fpNetworkRequestControlOfNetworkId>("network_request_control_of_network_id",
		"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x8B\xD3\x48\x8B\xC8\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2C",
		"xxxxxxxxx????xxxxxx????xxxxx",
		&Hooking::network_request_control_of_network_id);
	DoASM();
	//set_network_id_can_migrate
	setFn<fpSetNetworkIdCanMigrate>("set_network_id_can_migrate",
		"\x85\xC9\x0F\x8E\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8A\xDA",
		"xxxx????xxxx?xxxxxxx",
		&Hooking::set_network_id_can_migrate);
	DoASM();
	//network_create_synchronised_scene
	setFn<fpNetworkCreateSynchronisedScene>("network_create_synchronised_scene",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1",
		"xxxxxxxxxxxxxxxxxxxx",
		&Hooking::network_create_synchronised_scene);
	DoASM();
	//network_add_ped_to_synchronised_scene
	setFn<fpNetworkAddPedToSynchronisedScene>("network_add_ped_to_synchronised_scene",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9",
		"xxxx?xxxx?xxxxxxxx",
		&Hooking::network_add_ped_to_synchronised_scene);
	DoASM();
	//network_start_synchronised_scene
	setFn<fpNetworkStartSynchronisedScene>("network_start_synchronised_scene",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12",
		"xxxxx????xxxxxxxx????xxxx?x????xxxx",
		&Hooking::network_start_synchronised_scene);
	DoASM();
	//network_override_clock_time
	setFn<fpNetworkOverrideClockTime>("network_override_clock_time",
		"\x80\x3D\x00\x00\x00\x00\x00\x75\x37\x8B\x05\x00\x00\x00\x00\xC6",
		"xx?????xxxx????x",
		&Hooking::network_override_clock_time);

	//network_shop_begin_service
	/*setFn<fpNetworkShopBeginService>("network_shop_begin_service",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x50\x48\x8B\xF1\x48\x8B\x0D\x00\x00\x00\x00",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxxx????",
		&Hooking::network_shop_begin_service);*/

	//network_shop_checkout_start
	/*setFn<fpNetworkShopCheckoutStart>("network_shop_checkout_start",
		"\x40\x53\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0\x75\x06",
		"xxxxxxxxx????xxxx",
		&Hooking::network_shop_checkout_start);*/




	DoASM();
	std::string input14 = "gwseofgnwoignwfoqfmqofqo";
	std::string hash14 = sw::sha512::calculate(input14);
	DoASM();
	char * c_location = nullptr;
	void * v_location = nullptr;
	DoASM();
	Sleep(5000);
	DoASM();
	Log::Msg("Getting Game State..."_Secure);
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);
	DoASM();
	Log::Msg("Getting vector3 result fixer func..."_Secure);
	v_location = p_fixVector3Result.count(1).get(0).get<void>(0);
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);
	DoASM();
	Log::Msg("Grabbing natives"_Secure);
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);
	DoASM();
	Log::Msg("Converting to sigs"_Secure);
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;
	DoASM();
	Log::Msg("Conversion complete"_Secure);
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);
	DoASM();
	std::string input15 = "qofognreinqfoqoq";
	std::string hash15 = sw::sha512::calculate(input15);
	DoASM();
	if (steam != NULL)
	{
		//model bypass
		char*	ptr = nullptr;
		DoASM();
		CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
		ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
		ptr == nullptr ? Log::Msg("Failed to find online model requests bypass pattern") : Memory::nop(ptr, 24);
		DoASM();
		CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
		ptr = pattern_modelSpawn.find(0).get(0).get<char>(8);
		ptr == nullptr ? Log::Msg("Failed to find is player model allowed to spawn bypass pattern") : Memory::nop(ptr, 2);
	}
	else
	{
		Log::Msg("Bypassing Some shit"_Secure);
		DoASM();
		if (p_modelCheck.size() > 0) {
			DoASM();
			v_location = p_modelCheck.count(1).get(0).get<void>(0);
			Memory::nop(v_location, 24);
		}
		DoASM();
		Log::Msg("Bypassing Some shit 2"_Secure);
		DoASM();
		if (p_modelSpawn.size() > 0) {
			DoASM();
			v_location = p_modelSpawn.count(1).get(0).get<void>(8);
			Memory::nop(v_location, 2);
		}
	}
	Log::Msg("Getting active script thread..."_Secure);
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);
	DoASM();
	Log::Msg("Getting World Pointer..."_Secure);
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);
	DoASM();
	std::string input16 = "fgwngoiewgiuwnqodqq";
	std::string hash16 = sw::sha512::calculate(input16);
	DoASM();
	Log::Msg("Eventhook shit"_Secure);
	c_location = p_eventHook.count(1).get(0).get<char>(0);
	DoASM();
	if (c_location != nullptr)
	{
		DoASM();
		uint32_t i = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		for (uint32_t i = 0, match = 0, found = 0; found < REVENT_END; ++c_location)
		{
			if (*c_location == pattern[i])
			{
				if (++matches < 3)
				{
					++i;
					continue;
				}
				++c_location;
				EventPtr[found] = (void*)(c_location + *(int32_t*)c_location + 4); //((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
				++found;
			}
			else
				i = matches = 0;
		}
	}

	DoASM();
	Log::Msg("Initializing natives..."_Secure);
	CrossMapping::initNativeMap();
	DoASM();
	Log::Msg("Finishing up some things"_Secure);
	while (*m_gameState != GameStatePlaying)
		Sleep(200);
	DoASM();
	std::string input17 = "gfnweifgwnfifioqjowqjfqi";
	std::string hash17 = sw::sha512::calculate(input17);


	//Log::Msg("Getting Direct X..."_Secure);
	//c_location = p_Direct3DCreate9.count(1).get(0).get<char>(0);
	//c_location == nullptr ? FailPatterns("Direct3DCreate9") : m_Direct3DCreate9 = reinterpret_cast<decltype(m_Direct3DCreate9)>(c_location + *(int32_t*)c_location + 5);


	DoASM();
	CloseHandle(steam);
	DoASM();
	Log::Msg("Done"_Secure);
}

static Hooking::NativeHandler _Handler(uint64_t origHash) {

	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
		return nullptr;

	Hooking::NativeRegistration * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->NativeRegistration::getNextRegistration())
	{
		for (uint32_t i = 0; i < table->NativeRegistration::getNumEntries(); i++)
		{
			if (newHash == table->NativeRegistration::getHash(i))
				return table->handlers[i];
		}
	}

	return nullptr;

};

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
		handler = _Handler(origHash);

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

uint64_t Hooking::getWorldPtr()
{
	return m_worldPtr;
}

void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

/*void Hooking::Cleanup()
{
Log::Msg("Cleaning up Menu"_Secure);
for (int i = 0; i < m_hooks.size(); i++)
if (MH_DisableHook(m_hooks[i]) != MH_OK && MH_RemoveHook(m_hooks[i]) != MH_OK)
Log::Error("Failed to unhook %p"_Secure, (void*)m_hooks[i]);

MH_Uninitialize();
}*/

void Hooking::Cleanup()
{
	Log::Msg("CleanUp...");
	bool b = (MH_DisableHook(&ResetWriteWatch) == MH_OK && MH_RemoveHook(&ResetWriteWatch) == MH_OK);
	for (int i = 0; i < m_hookedNative.size(); i++)
		b = (MH_DisableHook(m_hookedNative[i]) != MH_OK && MH_RemoveHook(m_hookedNative[i]) != MH_OK);
}

void Hooking::defuseEvent(eRockstarEvent e, bool toggle)
{
	static const BYTE retn = 0xC3;
	BYTE* p = (BYTE*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}


