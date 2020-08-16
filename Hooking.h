#pragma once



enum eThreadState
{
	ThreadStateIdle = 0x0,
	ThreadStateRunning = 0x1,
	ThreadStateKilled = 0x2,
	ThreadState3 = 0x3,
	ThreadState4 = 0x4,
};

struct scrThreadContext
{
	int ThreadID;
	int ScriptHash;
	eThreadState State;
	int _IP;
	int FrameSP;
	int _SPP;
	float TimerA;
	float TimerB;
	int TimerC;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int _f50;
	int pad1;
	int pad2;
	int pad3;
	int _set1;
	int pad[17];
};

struct scrThread
{
	void *vTable;
	scrThreadContext m_ctx;
	void *m_pStack;
	void *pad;
	void *pad2;
	const char *m_pszExitMessage;
};

struct ScriptThread : scrThread
{
	const char Name[64];
	void *m_pScriptHandler;
	const char gta_pad2[40];
	const char flag1;
	const char m_networkFlag;
	bool bool1;
	bool bool2;
	bool bool3;
	bool bool4;
	bool bool5;
	bool bool6;
	bool bool7;
	bool bool8;
	bool bool9;
	bool bool10;
	bool bool11;
	bool bool12;
	const char gta_pad3[10];
};

/*
//CPatternResult
*/

class CPatternResult
{
public:
	CPatternResult(void* pVoid);
	CPatternResult(void* pVoid, void* pBegin, void* pEnd);
	~CPatternResult();

	template <typename rT>
	rT*	get(int offset = 0)
	{
		rT*	ret = nullptr;
		if (m_pVoid != nullptr)
			ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
		return ret;
	}

	template <typename rT>
	rT* get_rel(int offset = 0)
	{
		rT*		result = nullptr;
		int32_t	rel;
		char*	ptr = get<char>(offset);

		if (ptr == nullptr)
			goto LABEL_RETURN;

		rel = *(int32_t*)ptr;
		result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

	LABEL_RETURN:
		return result;
	}

	template <typename rT>
	rT*	section_begin()
	{
		return reinterpret_cast<rT*>(m_pBegin);
	}

	template <typename rT>
	rT*	section_end()
	{
		return reinterpret_cast<rT*>(m_pEnd);
	}

protected:
	void*	m_pVoid = nullptr;
	void*	m_pBegin = nullptr;
	void*	m_pEnd = nullptr;
};

/*
//CPattern
*/

typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
public:
	CPattern(char* szByte, char* szMask);
	~CPattern();

	CPattern&		find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
	CPattern&		virtual_find(int i = 0, uint64_t startAddress = 0);
	CPatternResult	get(int i);				//returns result i

protected:
	char*			m_szByte;
	char*			m_szMask;
	bool			m_bSet;
	vec_result		m_result;

	bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
	bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
	uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE *btMask, char *szMask);
	uint64_t	virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask);
};

struct screenReso
{
	uint32_t	w, h;
};

struct objectHash
{
	DWORD*	ptr;
	DWORD	hash;
};

struct clockTime
{
	int hour;
	int minute;
	int second;
};

class CWorld;
class CPed;
class CPlayers;
class CNavigation;
class CWorld_Wrap;
class CAttacker;
class CVehicle;
class CPlayerInfo;
class CWeaponManager;
class CWeapon;
class CAmmoInfo;
//class CVehicleColors;
//class CVehicleColorOptions;
class CVehicleHandling;
class CWantedData;
class CItemInfo;
class CAmmo;
class CViewPort;
class CVehicleMods;
class CVehicleModsVisual;
class CTireInfo;
class CLicencePlateInfo;
class CColor;
class CTextInfo;
class CPedStyle;
class CCameraInterface;
class CVehicleInterface;
class CPedInterface;
class CPickupInterface;
class CPickupList;
class CPickupHandle;
class CPickup;
class CPedList;
class CPedHandle;
class CVehList;
class CVehHandle;
class CObjectInterface;
class CObjectList;
class CObjectHandle;
class CObject;
class CPlayerInfo
{
public:
	char pad_0x0000[0x34]; //0x0000
	__int32 iInternalIP; //0x0034 
	__int16 iInternalPort; //0x0038 
	char pad_0x003A[0x2]; //0x003A
	__int32 iRelayIP; //0x003C 
	__int16 iRelayPort; //0x0040 
	char pad_0x0042[0x2]; //0x0042
	__int32 iExternalIP; //0x0044 
	__int16 iExternalPort; //0x0048 
	char pad_0x004A[0x32]; //0x004A
	char sName[20]; //0x007C 
	char pad_0x0090[0x4]; //0x0090
	__int32 iTeam; //0x0094 
	char pad_0x0098[0x4C]; //0x0098
	float fSwimSpeed; //0x00E4 
	float fRunSpeed; //0x00E8 
	char pad_0x00EC[0x74]; //0x00EC
	CPed* pCPed; //0x0160 
	char pad_0x0168[0x29]; //0x0168
	BYTE btFrameFlags; //0x0191 
	char pad_0x0192[0x56E]; //0x0192
	void* CWantedData; //0x0700 
	char pad_0x079C[0x464]; //0x079C
	float fStamina; //0x0C00 
	float fStaminaMax; //0x0C04 

	void removeWanted()
	{
		//if (CWantedData.dwWantedLevel > 0)
			//CWantedData.dwWantedLevel = 0;
	}
}; //Size=0x0C08
class CNavigation
{
public:
	char pad_0x0000[0x20]; //0x0000
	float fHeading; //0x0020 
	float fHeading2; //0x0024 
	char pad_0x0028[0x8]; //0x0028
	Vector3 v3Rotation; //0x0030 
	char pad_0x003C[0x14]; //0x003C
	Vector3 v3Pos; //0x0050 

}; //Size=0x005C
class CWeaponManager;
class CWeapon;
class CAmmoInfo;
//class CVehicleColors;
//class CVehicleColorOptions;
class CVehicleHandling;
class CWantedData
{
public:
	char pad_0x0000[0x1C]; //0x0000
	float fWantedCanChange; //0x001C 
	char pad_0x0020[0x10]; //0x0020
	Vector3 v3WantedCenterPos; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	Vector3 v3WantedCenterPos2; //0x0040 
	char pad_0x004C[0x38]; //0x004C
	BYTE btFlag0; //0x0084 
	BYTE btFlag1; //0x0085 
	BYTE btFlag2; //0x0086 
	BYTE btFlag3; //0x0087 
	char pad_0x0088[0xC]; //0x0088
	DWORD dwWantedLevelFake; //0x0094 
	DWORD dwWantedLevel; //0x0098 

}; //Size=0x00AC
class CItemInfo;
class CAmmo;
class CViewPort;
class CVehicleMods;
class CVehicleModsVisual;
class CTireInfo;
class CLicencePlateInfo;
class CColor;
class CTextInfo;
class CPedStyle;
class CCameraInterface;
class CPickupList;
class CPickupHandle;
class CPickup;
class CObjectInterface;
class CObjectList;
class CObjectHandle;
class CObject;

class CBlip
{
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	Vector3_t v3Pos;
	char _0x001C[6];
	BYTE btFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE btInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE btZIndex; //0x0057 
	BYTE btDisplay; //0x0058  Also Visibility 0010
	BYTE btAlpha; //0x0059
};//Size=0x005A

class CBlipList
{
public:
	CBlip * m_Blips[0x400]; //0x0000 

};

class CCameraInterface
{
public:
	char pad_0x0000[0x248]; //0x0000

}; //Size=0x0248

class CObjectInterface
{
public:
	char pad_0x0000[0x158]; //0x0000
	CObjectList* pCObjectList; //0x0158 
	__int32 iMaxObjects; //0x0160 
	char pad_0x0164[0x4]; //0x0164
	__int32 iCurObjects; //0x0168 
	char pad_0x016C[0x5C]; //0x016C

}; //Size=0x01C8

class CVehicle
{
public:
	char pad_0x0000[0x30]; //0x0000
	CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CVehicleMods* pCVehicleMods; //0x0048 
	char pad_0x0050[0x40]; //0x0050
	Vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3C]; //0x009C
	BYTE btState; //0x00D8 
	char pad_0x00D9[0xB0]; //0x00D9
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x6A]; //0x02B0
	BYTE btVolticRocketState; //0x031A 
	char pad_0x031B[0x1]; //0x031B
	float fVolticRocketEnergy; //0x031C 
	char pad_0x0320[0x430]; //0x0320
	Vector3 v3Velocity; //0x0750 
	char pad_0x075C[0xF0]; //0x075C
	float fHealth2; //0x084C 
	char pad_0x0850[0x28]; //0x0850
	CVehicleHandling* pCVehicleHandling; //0x0878 
	char pad_0x0880[0x3]; //0x0880
	BYTE btBulletproofTires; //0x0883 
	char pad_0x0884[0x4]; //0x0884
	BYTE btStolen; //0x0888 
	char pad_0x0889[0x11]; //0x0889
	BYTE N00000954; //0x089A 
	char pad_0x089B[0x41]; //0x089B
	float N0000081E; //0x08DC 
	char pad_0x08E0[0x58]; //0x08E0
	float fDirtLevel; //0x0938			max = 15.f
	char pad_0x093C[0xA8]; //0x093C
	DWORD dwCarAlarmLength; //0x09E4 
	char pad_0x09E8[0x148]; //0x09E8
	BYTE btOpenableDoors; //0x0B30 
	char pad_0x0B31[0x4B]; //0x0B31
	float fGravity; //0x0B7C
	BYTE btMaxPassengers; //0x0B80 
	char pad_0x0B81[0x1]; //0x0B81
	BYTE btNumOfPassengers; //0x0B82 
	char pad_0x0B83[0x3D]; //0x0B83

	bool isGod()
	{
		return (btGodMode & 0x01) ? true : false;
	}

	bool hasBulletproofTires()
	{
		return (btBulletproofTires & 0x20) ? true : false;
	}

	bool disabledDoors()
	{
		return (btOpenableDoors == 0) ? true : false;
	}

	void giveHealth()
	{
		if (fHealth < fHealthMax)
			fHealth = fHealthMax;
		if (fHealth2 < fHealthMax)
			fHealth2 = fHealthMax;
	}

	//btState & 7    0 = inside of vehicle, 2 = outside of vehicle, 3 = vehicle blown up
	bool isVehicleDestroyed()
	{
		return (btState & 7) == 3;
	}

	void set_stolen(bool toggle)
	{
		this->btStolen &= 0xFEu;
		this->btStolen |= toggle & 1;
	}
}; //Size=0x0BC0

class CVehHandle
{
public:
	CVehicle * pCVehicle; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CVehList
{
public:
	CVehHandle vehs[300]; //0x0000 

}; //Size=0x1000

class CVehicleInterface
{
public:
	char pad_0x0000[0x180]; //0x0000
	CVehList* VehList; //0x0180 
	__int32 iMaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 iCurVehicles; //0x0190 
	char pad_0x0194[0x74]; //0x0194

	CVehicle* get_vehicle(const int& index)
	{
		if (index < iMaxVehicles)
			return VehList->vehs[index].pCVehicle;
		return nullptr;
	}
}; //Size=0x0208

class CPed
{
public:
	char pad_0x0000[0x28]; //0x0000
	BYTE btEntityType; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	BYTE btInvisible; //0x002C 
	char pad_0x002D[0x1]; //0x002D
	BYTE btFreezeMomentum; //0x002E 
	char pad_0x002F[0x1]; //0x002F
	CNavigation* pCNavigation; //0x0030 
	char pax_0x0038[0x10]; //0x0038
	CPedStyle*	pCPedStyle; //0x0048
	char pad_0x0038[0x40]; //0x0050
	Vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0xED]; //0x009C
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x70]; //0x02B0
	Vector3 v3Velocity; //0x0320 
	char pad_0x032C[0x9FC]; //0x032C
	CVehicle* pCVehicleLast; //0x0D28 
	char pad_0x0D30[0x378]; //0x0D30
	BYTE btNoRagdoll; //0x10A8 
	char pad_0x10A9[0xF]; //0x10A9
	CPlayerInfo* pCPlayerInfo; //0x10B8 
	char pad_0x10C0[0x8]; //0x10C0
	CWeaponManager* pCWeaponManager; //0x10C8 
	char pad_0x10D0[0x31C]; //0x10D0
	BYTE btSeatBelt; //0x13EC 
	char pad_0x13ED[0xB]; //0x13ED
	BYTE btSeatbeltWindshield; //0x13F8 
	char pad_0x13F9[0x1]; //0x13F9
	BYTE btCanSwitchWeapons;
	char pad_0x13FB[0x5];
	BYTE btForcedAim; //0x1400 
	BYTE N00000936; //0x1401 
	BYTE N00000939; //0x1402 
	BYTE N00000937; //0x1403 
	char pad_0x1404[0x67]; //0x1404
	BYTE btIsInVehicle; //0x146B 
	char pad_0x146C[0x44]; //0x146C
	float fArmor; //0x14B0 
	char pad_0x14B4[0x20]; //0x14B4
	float fFatiguedHealthThreshold; //0x14D4 
	float fInjuredHealthThreshold; //0x14D8 
	float fDyingHealthThreshold; //0x14DC 
	float fHurtHealthThreshold; //0x14E0 
	char pad_0x14E4[0xC]; //0x14E4
	CVehicle* pCVehicleLast2; //0x14F0 
	char pad_0x14F8[0xDC]; //0x14F8
	__int32 iCash; //0x15D4 

				   //entity type 3 = car, 4 = ped
	bool isGod()
	{
		return((btGodMode & 0x01)
			//||	fFatiguedHealthThreshold < 0.f
			//||	fInjuredHealthThreshold < 0.f
			//||	fDyingHealthThreshold < 0.f
			|| fHurtHealthThreshold < 0.f);
	}

	bool isInvisible()
	{
		return (btInvisible & 0x01) ? true : false;
	}

	bool hasFrozenMomentum()
	{
		return (btFreezeMomentum & 0x02) ? true : false;
	}

	bool canBeRagdolled()
	{
		return (btNoRagdoll & 0x20) ? false : true;
	}

	bool hasSeatbelt()
	{
		return (btSeatBelt & 0x01) ? true : false;
	}

	bool hasSeatbeltWindshield()
	{
		return (btSeatbeltWindshield & 0x10) ? true : false;
	}

	bool isInVehicle()
	{
		return (btIsInVehicle & 0x10) ? false : true;
	}

	void giveHealth()
	{
		if (fHealth	< fHealthMax)
			fHealth = fHealthMax;
		if (fArmor < 50.f)
			fArmor = 50.f;
	}

	void giveHealth(float value)
	{
		value += fHealth;
		if (value <= fHealthMax)
			fHealth = value;
		else if (fHealth	< fHealthMax)
			fHealth = fHealthMax;
	}

	void setForcedAim(bool toggle)
	{
		btForcedAim ^= (btForcedAim ^ -(char)toggle) & 0x20;
	}
}; //Size=0x15D8

class CPedHandle
{
public:
	CPed * pCPed; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CPedList
{
public:
	CPedHandle peds[256]; //0x0000 

}; //Size=0x1000

class CPedInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPedList* PedLIst; //0x0100 
	__int32 iMaxPeds; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPeds; //0x0110 
	char pad_0x0114[0x34]; //0x0114
	CPed* get_ped(const int& index)
	{
		if (index < iMaxPeds)
			return PedLIst->peds[index].pCPed;
		return nullptr;
	}
}; //Size=0x0148

class CPickupInterface
{
public:
	char pad_0x0000[0x100]; //0x0000
	CPickupList* pCPickupList; //0x0100 
	__int32 iMaxPickups; //0x0108 
	char pad_0x010C[0x4]; //0x010C
	__int32 iCurPickups; //0x0110 

}; //Size=0x0114

class CReplayInterface
{
public:
	void* N000006F5; //0x0000 
	CCameraInterface* pCCameraInterface; //0x0008 
	CVehicleInterface* pCVehicleInterface; //0x0010 
	CPedInterface* pCPedInterface; //0x0018 
	CPickupInterface* pCPickupInterface; //0x0020 
	CObjectInterface* pCObjectInterface; //0x0028 

};

class CObjectWrapper
{
public:
	char _0x0000[168];
	CPlayerInfo* playerInfo; //0x00A8 

};

class CPlayers
{
public:
	char _0x0000[376];
	__int32 numPlayersOnline; //0x0178 
	char _0x017C[4];
	CObjectWrapper* ObjectWrapperList[256]; //0x0180 
};

class CHack
{
public:
	static queue_int			m_nearbyPed;
	static queue_int			m_nearbyVehicle;
	static queue_int			m_entityCleanup;
};

typedef bool(__cdecl* fpIsDLCPresent)();
typedef BOOL(__cdecl*	fpIsPlayerPlaying)(Player player);
typedef Player(__cdecl*	fpPlayerId)();
typedef Ped(__cdecl*	fpGetPlayerPed)(Player player);
typedef int(__cdecl*	fpGetPlayerTeam)(Player player);
typedef Vehicle(__cdecl*	fpGetVehiclePedIsUsing)(Ped ped);
typedef Ped(__cdecl*	fpGetPedInVehicleSeat)(Vehicle vehicle, int index);
typedef BOOL(__cdecl*	fpIsAimCamActive)();
typedef BOOL(__cdecl*	fpGetEntityPlayerIsFreeAimingAt)(Player player, Entity* entity);
typedef BOOL(__cdecl*	fpNetworkIsSessionStarted)();
typedef float(__cdecl*	fpGetEntitySpeed)(Vehicle vehicle);
typedef char*	(__cdecl*	fpGetPlayerName)(Player player);
typedef void(__cdecl*	fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
typedef void(__cdecl*	fpDrawLine)(Vector3_t* pos1, Vector3_t* pos2, int r, int g, int b, int a);
typedef BOOL(__cdecl*	fpGetGroundZFor3dCoord)(Vector3_t* pos, float* out, int64_t unk1, BOOL unk2);
typedef Vehicle(__cdecl*	fpCreateVehicle)(Hash model, Vector3_t* pos, float heading, BOOL networked, BOOL unk2);
typedef void(__cdecl*	fpSetEntityCoordsNoOffset)(Entity entity, Vector3_t* pos, BOOL x, BOOL y, BOOL z);
typedef float(__cdecl*	fpGetEntityHeading)(Entity entity);
typedef Vector3_t*(__cdecl*	fpGetGameplayCamRot)(Vector3_t* out, uint32_t unk1);
typedef Vector3_t*(__cdecl*	fpGetGameplayCamCoord)(Vector3_t* out);
typedef int(__cdecl*	fpGetPlayerGroup)(Player player);
typedef int(__cdecl*	fpSetPlayerModel)(Player player, Hash model);
typedef int(__cdecl*	fpSetPedRandomComponentVariatian)(Ped ped);
typedef int(__cdecl*	fpSetPedDefaultComponentVariation)(Ped ped);
typedef bool(__cdecl*	fpIsPedInAnyVehicle)(Ped ped, BOOL atGetIn);
typedef Ped(__cdecl*	fpCreatePed)(int type, Hash model, Vector3_t* pos, float heading, bool isNetworked, bool unk1);
typedef int(__cdecl*	fpSetPedIntoVehicle)(Ped ped, Vehicle vehicle, int seat);
typedef BOOL(__cdecl*	fpSetPedConfigFlag)(Ped ped, int flag, bool value);
typedef int(__cdecl*	fpClearPedBloodDamage)(Ped* ped);
typedef int(__cdecl*	fpClearPedWetness)(Ped ped);
typedef BOOL(__cdecl*	fpCreateObject)(Hash model, float x, float y, float z, bool offset, int unk0, int unk1, Object* out, bool isNetworked, bool unk2, bool dynamic);	//unk0 = 1; unk1 = -1
																																											//typedef uint32_t(__cdecl*	fpGetPedNearbyVehicles)(Ped ped, int* sizeAndVehs);
																																											//typedef uint32_t(__cdecl*	fpGetPedNearbyPeds)(Ped ped, int* sizeAndPeds, int ignore);
typedef BOOL(__cdecl*	fpNetworkShopBeginService)(DWORD* transID, int p1, int p2, int p3, int p4, int p5);
typedef int(__cdecl*	fpGetPedGroupIndex)(Ped ped);
typedef Ped(__cdecl*	fpClonePed)(Ped ped, float heading, BOOL isNetworked, BOOL unk0);
typedef BOOL(__cdecl*	fpNetworkShopBeginService)(DWORD* transID, int p1, int p2, int p3, int p4, int p5);
typedef BOOL(__cdecl*	fpStatSetInt)(DWORD hash, int value, BOOL save);
typedef BOOL(__cdecl*	fpStatSetFloat)(DWORD hash, float value, BOOL save);
typedef BOOL(__cdecl*	fpStatSetBool)(DWORD hash, BOOL value, BOOL save);
typedef BOOL(__cdecl*	fpStatSetDate)(DWORD hash, DWORD* value, int size, BOOL save);
typedef BOOL(__cdecl*	fpStatGetInt)(DWORD hash, int* out, int unk0);
typedef void(__cdecl*	fpAddExplosion)(Vector3_t* pos, int type, float damage, bool audible, bool invis, float shake, bool nodmg);
typedef void(__cdecl*	fpGiveDelayedWeaponToPed)(Ped ped, DWORD hash, int time, BOOL equipNow);
typedef BOOL(__cdecl*	fpRemoveAllPedWeapons)(Ped ped);
typedef BOOL(__cdecl*	fpRemoveWeaponFromPed)(Ped ped, DWORD hash);
typedef BOOL(__cdecl*	fpSetMobileRadio)(BOOL toggle);	//SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY
typedef int(__cdecl*	fpGetPlayerRadioStationIndex)();
typedef char*	(__cdecl*	fpGetRadioStationName)(int id);
typedef bool(__cdecl*	fpNetworkHasControlOfEntity)(Entity entity);
typedef bool(__cdecl*	fpNetworkRequestControlOfEntity)(Entity entity);
typedef int(__cdecl*	fpNetworkGetNetworkIdFromEntity)(Entity entity);
typedef bool(__cdecl*	fpNetworkHasControlOfNetworkId)(int netId);
typedef bool(__cdecl*	fpNetworkRequestControlOfNetworkId)(int netId);
typedef void(__cdecl*	fpSetNetworkIdCanMigrate)(int netId, bool toggle);
typedef int(__cdecl*	fpNetworkCreateSynchronisedScene)(Vector3_t* pos, Vector3_t* rot, int unk0, int unk1, int unk2, float unk3, float unk4, float unk5);
typedef int(__cdecl*	fpNetworkAddPedToSynchronisedScene)(Ped ped, int scene, char* dict, char* anim, float speed, float speedMult, int duration, int flag, float playRate, int unk1, int unk2);
typedef int(__cdecl*	fpNetworkStartSynchronisedScene)(int scene);
typedef int(__cdecl*	fpClearPedTasksImmediately)(Ped ped);
typedef int(__cdecl*	fpSetEntityVisible)(Entity e, bool toggle, bool unk0);
typedef bool(__cdecl*	fpSetPedAsGroupMember)(Ped ped, int group);
typedef bool(__cdecl*	fpIsPedGroupMember)(Ped ped, int group);
typedef void(__cdecl*	fpSetPedGravity)(Ped ped, bool toggle);
typedef BOOL(__cdecl*	fpSetEntityHasGravity)(Entity entity, bool toggle);
typedef bool(__cdecl*	fpIsVehicleDrivable)(Vehicle vehicle, bool unk0);
typedef bool(__cdecl*	fpIsModelAHeli)(DWORD hash);
typedef bool(__cdecl*	fpIsModelAPlane)(DWORD hash);
typedef bool(__cdecl*	fpIsModelACar)(DWORD hash);
typedef BOOL(__cdecl*	fpSetHeliBladesFullSpeed)(Vehicle vehicle, float speed);	//speed 0.f - 1.f
typedef BOOL(__cdecl*	fpSetVehicleForwardSpeed)(Vehicle vehicle, float speed);
typedef bool(__cdecl*	fpSetVehicleNumberPlateText)(Vehicle vehicle, char* text);
typedef bool(__cdecl*	fpSetPedToRagdoll)(Ped ped, int time1, int time2, int type, bool unk0, bool unk1, bool unk2);
typedef void(__cdecl*	fpGetPedBoneCoords)(Vector3_t* out, Ped ped, DWORD boneId, Vector3_t* offset);
typedef bool(__cdecl*	fpSetEntityAsMissionEntity)(Entity entity, bool unk0, bool owned);
typedef bool(__cdecl*	fpApplyForceToEntity)(Entity entity, int forceType, Vector3_t* pos, Vector3_t* rot, int unk0, bool isRel, bool unk2, bool highForce, bool unk3, bool unk4);
typedef BOOL(__cdecl*	fpSetEntityRotation)(Entity entity, Vector3_t* rot, int unk0);
typedef bool(__cdecl*	fpSetEntityHeading)(Entity entity, float heading);
typedef BOOL(__cdecl*	fpFreezeEntityPosition)(Entity entity, bool toggle);
typedef BOOL(__cdecl*	fpShootSingleBulletBetweenCoords)(Vector3_t* pos1, Vector3_t* pos2, int damage, bool unk0, DWORD hash, Ped owner, bool isAudible, bool isVisible, float speed, int unk1, bool unk2, bool unk3, int unk4);
typedef void(__cdecl*	fpSetPedNeverLeavesGroup)(Ped ped, bool toggle);
typedef BOOL(__cdecl*	fpSetGroupFormation)(int group, int formation);
typedef int(__cdecl*	fpGetPedBoneIndex)(Ped ped, int boneId);
typedef BOOL(__cdecl*	fpSetPedComponentVariation)(Ped ped, int componentId, int drawableId, int textureId, int paletteId);
typedef BOOL(__cdecl*	fpClearAllPedProps)(Ped ped);
typedef BOOL(__cdecl*	fpSetPedPropIndex)(Ped ped, int componentId, int drawableId, int textureId, bool attach);
typedef bool(__cdecl*	fpIsEntityInAir)(Entity entity);
typedef BOOL(__cdecl*	fpSetEntityVelocity)(Entity entity, Vector3_t* velocity);
typedef Entity(__cdecl*	fpGetEntityAttachedTo)(Entity entity);
typedef bool(__cdecl*	fpDetachEntity)(Entity entity, bool unk0, bool collision);
typedef bool(__cdecl*	fpDeleteEntity)(Entity* entity);
typedef bool(__cdecl*	fpIsEntityAttached)(Entity entity);
typedef BOOL(__cdecl*	fpSetEntityAsNoLongerNeeded)(Entity* entity);
typedef BOOL(__cdecl*	fpGetEntityVelocity)(Vector3_t* out, Entity entity);
typedef BOOL(__cdecl*	fpGetEntityRotation)(Vector3_t* out, Entity entity, int rotationOrder);
typedef DWORD(__cdecl*	fpGetEntityModel)(Entity entity);
typedef bool(__cdecl*	fpSetVehicleOnGroundProperly)(Vehicle vehicle, int unk0);
typedef void(__cdecl*	fpSetVehicleUndriveable)(Vehicle vehicle, bool toggle);
typedef void(__cdecl*	fpSetVehicleFixed)(Vehicle vehicle);
typedef void(__cdecl*	fpSetVehicleDeformationFixed)(Vehicle* pVehicle);
typedef bool(__cdecl*	fpIsVehicleSeatFree)(Vehicle vehicle, int seatId, bool unk0);
typedef bool(__cdecl*	fpSetVehicleModKit)(Vehicle vehicle, int modKit);
typedef void(__cdecl*	fpSetVehicleNumberPlateIndex)(Vehicle* vehicle, int plateId);
typedef BOOL(__cdecl*	fpToggleVehicleMod)(Vehicle vehicle, int modType, bool toggle);
typedef BOOL(__cdecl*	fpSetVehicleMod)(Vehicle vehicle, int modType, int modIndex, bool customTires);
typedef BOOL(__cdecl*	fpSetVehicleWheelType)(Vehicle vehicle, int wheelType);
typedef int(__cdecl*	fpGetNumVehicleMod)(Vehicle vehicle, int modType);
typedef BOOL(__cdecl*	fpAddTextCompSubstrPlayerName)(char* text);
typedef BOOL(__cdecl*	fpEndTextCmdDisplayText)(float x, float y);
typedef BOOL(__cdecl*	fpBeginTextCmdDisplayText)(char* text);
typedef BOOL(__cdecl*	fpSetNotificationTextEntiry)(char* text);
typedef BOOL(__cdecl*	fpDrawNotification)(bool blink, bool unk0, bool unk1);
typedef BOOL(__cdecl*	fpSetWeatherTypeNowPersist)(char* weather);
typedef BOOL(__cdecl*	fpDisplayOnscreenKeyboard)(int64_t unk0, char* title, char* unk1, char* defaultText, char* defConcat, char* defConCat2, char* defConcat3, int maxLength);
typedef BOOL(__cdecl*	fpUpdateOnscreenKeyboard)();
typedef BOOL(__cdecl*	fpSetLocalPlayerVisibleLocally)(bool unk0);
typedef BOOL(__cdecl*	fpNetworkOverrideClockTime)(int hour, int minute, int second);
typedef uint64_t(__cdecl*	fpGetNetworkTime)();
typedef BOOL(__cdecl*	fpAiTaskWanderStandard)(Ped ped, float unk0, bool unk1);
typedef BOOL(__cdecl*	fpAiTaskPlayAnim)(Ped ped, char* dict, char* anim, float speed, float speedMult, int duration, int flg, float playRate, bool unk0, BOOL lockX, BOOL lockY, BOOL lockZ, bool unk1);
typedef bool(__cdecl*	fpIsModelInCdimage)(DWORD hash);
typedef bool(__cdecl*	fpIsModelValid)(DWORD hash);
typedef bool(__cdecl*	fpIsModelAVehicle)(DWORD hash);
typedef BOOL(__cdecl*	fpRequestModel)(DWORD hash);
typedef bool(__cdecl*	fpHasModelLoaded)(DWORD hash);
typedef BOOL(__cdecl*	fpRequestAnimDict)(char* dict);
typedef bool(__cdecl*	fpHasAnimDictLoaded)(char* dict);
typedef void(__cdecl*	fpDecorRegister)(char* name, int type);
typedef bool(__cdecl*	fpDecorSetInt)(Entity entity, char* name, int value);
typedef BOOL(__cdecl*	fpCreateAmbientDrop)(DWORD pickupHash, Vector3_t* pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
typedef	BOOL(__cdecl*	fpIsPlayerFreeAiming)(Player player);
typedef bool(__cdecl*	fpGetPedLastWeaponImpactCoord)(Ped ped, Vector3_t* out);
typedef int(__cdecl*	fpStartRayCast)(Vector3_t* pos1, Vector3_t* pos2, int flags, Entity entity, bool unk0);	//_START_SHAPE_TEST_RAY
typedef int(__cdecl*	fpGetRayCast)(int handle, BOOL* hit, Vector3_t* end, Vector3_t* surface, Hash* material, Entity* entity);
typedef Entity(__cdecl*	fpPtrToHandle)(void* entity);
typedef BOOL(__cdecl*	fpNetworkSetInSpectatorMode)(bool toggle, Ped ped);
typedef BOOL(__cdecl*	fpSetPedCombatAbility)(Ped* pPed, BYTE ability);
typedef BOOL(__cdecl*	fpAiTaskCombatPed)(Ped ped, Ped target, int unk0, int unk1);
typedef int(__cdecl*	fpTriggerScriptEvent)(bool unk0, uint64_t* args, int argCount, int bitFlags);
typedef BOOL(__cdecl*	fpApplyVehicleColors)(Vehicle* vehicle, bool unk0);	//unk0 = 1;
typedef BOOL(__cdecl*	fpSetPedRelationshipGroupHash)(Ped ped, DWORD hash);
typedef BOOL(__cdecl*	fpSetPlayerVisibleLocally)(Player player, bool toggle);
typedef BOOL(__cdecl*	fpSetModelAsNoLongerNeeded)(DWORD hash);
typedef BOOL(__cdecl*	fpSetRadioToStationName)(void* gameInfo, char* station);
typedef void(__cdecl*	fpSetVehicleEngineOn)(Vehicle vehicle, bool unk0, bool instant, bool unk1);
typedef BOOL(__cdecl*	fpAttachEntityToEntity)(Entity subject, Entity target, int boneIndex, Vector3_t* offset, Vector3_t* rot, bool unk0, bool softPinning, bool collision, bool isPed, int vertexIndex, bool fixedRot, bool unk1);
typedef BOOL(__cdecl*	fpSetEntityCollision)(Entity entity, bool toggle, bool physics, bool unk0);
typedef uint32_t(__cdecl*	fpGetPedNearbyVehicles)(Ped ped, int* sizeAndVehs);
typedef uint32_t(__cdecl*	fpGetPedNearbyPeds)(Ped ped, int* sizeAndPeds, int ignore);

class CMetaData
{
public:
	static uint64_t	begin();
	static uint64_t	end();
	static DWORD	size();
	static void		init();
private:
	static uint64_t	m_begin;
	static uint64_t	m_end;
	static DWORD	m_size;
};




class Hooking
{
public:
	
	static std::vector<LPVOID>		m_hooks;
	static uint64_t*				m_frameCount;
	static fpIsDLCPresent           is_DLC_present;
	static fpDrawNotification		draw_notification;
	static fpGetNetworkTime			get_network_time;
	static fpTriggerScriptEvent		trigger_script_event;
	static fpAddTextCompSubstrPlayerName		add_text_comp_substr_playername;
	static fpEndTextCmdDisplayText				end_text_cmd_display_text;
	static fpBeginTextCmdDisplayText			begin_text_cmd_display_text;
	static MemoryPool**				m_entityPool;
	static MemoryPool**				m_pedPool;
	static CPlayers*				m_players;
	static void Start(HMODULE hmoduleDLL);
	static void Cleanup();
	static eGameState GetGameState();
	static uint64_t getWorldPtr();
	static void onTickInit();
	static bool HookNatives();
	static __int64** getGlobalPtr();
	static void defuseEvent(eRockstarEvent e, bool toggle);
	static fpStatSetInt							stat_set_int;
	static fpStatSetFloat						stat_set_float;
	static fpStatSetBool						stat_set_bool;
	static fpStatSetDate						stat_set_date;
	static fpStatGetInt							stat_get_int;
	static fpNetworkIsSessionStarted			network_is_session_started;
	static fpSetMobileRadio						set_mobile_radio;
	static BlipList*                            GetBlipList();
	static fpNetworkShopBeginService			network_shop_begin_service;
	static fpRequestModel						request_model;
	static fpHasModelLoaded						has_model_loaded;
	static fpSetVehicleForwardSpeed				set_vehicle_forward_speed;
	static fpIsModelValid						is_model_valid;
	static fpIsModelInCdimage					is_model_in_cdimage;
	static fpIsModelAVehicle					is_model_a_vehicle;
	static fpClearPedTasksImmediately			clear_ped_tasks_immediately;
	static fpPtrToHandle						ptr_to_handle;
	static fpNetworkHasControlOfEntity			network_has_control_of_entity;
	static fpNetworkRequestControlOfEntity		network_request_control_of_entity;
	static fpNetworkGetNetworkIdFromEntity		network_get_network_id_from_entity;
	static fpNetworkHasControlOfNetworkId		network_has_control_of_network_id;
	static fpNetworkRequestControlOfNetworkId	network_request_control_of_network_id;
	static fpSetNetworkIdCanMigrate				set_network_id_can_migrate;
	static fpNetworkCreateSynchronisedScene		network_create_synchronised_scene;
	static fpNetworkAddPedToSynchronisedScene	network_add_ped_to_synchronised_scene;
	static fpNetworkStartSynchronisedScene		network_start_synchronised_scene;
	static fpNetworkOverrideClockTime			network_override_clock_time;


	

	// Native function handler type
	typedef void(__cdecl * NativeHandler)(scrNativeCallContext * context);
	struct NativeRegistration {
		uint64_t nextRegistration1;
		uint64_t nextRegistration2;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries1;
		uint32_t numEntries2;
		uint64_t hashes;

		inline NativeRegistration* getNextRegistration() {
			uintptr_t result;
			auto v5 = reinterpret_cast<uintptr_t>(&nextRegistration1);
			auto v12 = 2i64;
			auto v13 = v5 ^ nextRegistration2;
			auto v14 = (char *)&result - v5;
			do
			{
				*(DWORD*)&v14[v5] = v13 ^ *(DWORD*)v5;
				v5 += 4i64;
				--v12;
			} while (v12);

			return reinterpret_cast<NativeRegistration*>(result);
		}

		inline uint32_t getNumEntries() {
			return ((uintptr_t)&numEntries1) ^ numEntries1 ^ numEntries2;
		}

		inline uint64_t getHash(uint32_t index) {

			auto naddr = 16 * index + reinterpret_cast<uintptr_t>(&nextRegistration1) + 0x54;
			auto v8 = 2i64;
			uint64_t nResult;
			auto v11 = (char *)&nResult - naddr;
			auto v10 = naddr ^ *(DWORD*)(naddr + 8);
			do
			{
				*(DWORD *)&v11[naddr] = v10 ^ *(DWORD*)(naddr);
				naddr += 4i64;
				--v8;
			} while (v8);

			return nResult;
		}
	};

	/*
	struct NativeRegistration
	{
		NativeRegistration * nextRegistration;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries;
		uint64_t hashes[7];
	};
	*/

	static NativeHandler GetNativeHandler(uint64_t origHash);




private:
	static BOOL InitializeHooks();
	static void FindPatterns();
	static void FailPatterns(const char* name);
	static void FindScriptAddresses();
	static void FindPattern2();
	static void EnableCarsGlobal();
	static void PatchCheatController();
};	void WAIT(DWORD ms);

