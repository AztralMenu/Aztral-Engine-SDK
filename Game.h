#pragma once

#ifndef GAME_H
#define GAME_H

#include "stdafx.h"

void MainThread();

class Game
{
private:

public:

	static BOOLEAN ThreadState[2];
	static BOOLEAN Initialized;

	typedef DWORD64 Player;
	typedef DWORD64 Vehicle;
	typedef DWORD64 Ped;
	typedef DWORD64 Entity;
	typedef DWORD Hash;


	typedef unsigned int(__fastcall* GetPlayerPed_t)(unsigned int ID);
	typedef unsigned int(__fastcall* GetPlayerID_t)();
	typedef unsigned int(__fastcall* GetVehiclePedIsIn_t)(Player Ped, BOOLEAN LastVehicle);
	typedef void(__fastcall* SetEntityInvincible_t)(unsigned int Entity, BOOL toggle);
	typedef void(__fastcall* SetVehicleForwardSpeed_t)(Vehicle vehicle, float Speed);
	typedef void(__fastcall* SetPedAmmo_t) (Ped ped, Hash WeaponHash, int ammo);
	typedef void(__fastcall* GiveWeaponToPed_t)(Player ped, Hash WeaponHash, int Ammo, BOOL unk, BOOL EquiNow);
	typedef void(__fastcall* SetEntityVelocity_t)(Entity entity, PVector3 Velocity);
	typedef void(__fastcall* SetEntityVisible_t)(Entity entity, BOOLEAN toggle, BOOLEAN unk);
	typedef void(__fastcall* SetEntityProof_t)(Entity entity, BOOLEAN BulletProof, BOOLEAN FireProof, BOOLEAN ExplosionProof, BOOLEAN CollisionProof, BOOLEAN MeleeProof, BOOLEAN p6, BOOLEAN p7, BOOLEAN DrownProof);
	typedef void(__fastcall* SetPedCanRagdoll_t)(Ped ped, BOOLEAN toggle);
	typedef void(__fastcall* SetPedCanRagdollOnCollision_t)(Ped ped, BOOLEAN toggle);
	typedef void(__fastcall* SetPedConfigFlag_t)(Ped ped, int Flag, BOOLEAN toggle);
	typedef void(__fastcall* DisableAllControls_t)(unsigned int index);
	typedef Player(__fastcall* GetPlayerByIndex_t)(unsigned int i); //USING G = ETC
	typedef Ped(__fastcall* SetPedCanBeKnockedOffVehicle_t) (Ped ped, int state);
	typedef BOOLEAN(__fastcall* GetPedMaxAmmo_t) (Ped ped, Hash WeaponHash, int* ammo);
	typedef BOOLEAN(__fastcall* WorldToScreen_t)(Vector3 WorldPos, float* x, float* y);
	typedef BOOLEAN(__fastcall* HasPedGotWeapon_t)(Ped ped, Hash WeaponHash, BOOLEAN OnHand);
	
	
	static WorldToScreen_t World2Screen;
	static GetPlayerByIndex_t GetPlayerByIndex;
	static SetVehicleForwardSpeed_t SetVehicleForwardSpeed;
	static GetPlayerPed_t GetPlayerPed;
	static GetVehiclePedIsIn_t GetVehiclePedIsIn;
	static GetPlayerID_t GetPlayerID;
	static SetEntityInvincible_t SetEntityInvincible;
	static SetPedAmmo_t SetPedAmmo;
	static GetPedMaxAmmo_t GetPedMaxAmmo;
	static HasPedGotWeapon_t HasPedGotWeapon;
	static GiveWeaponToPed_t GiveWeaponToPed;
	static SetEntityVelocity_t SetEntityVelocity;
	static SetEntityVisible_t SetEntityVisible;
	static SetPedCanRagdoll_t SetPedCanRagdoll;
	static SetPedCanRagdollOnCollision_t SetPedCanRagdollOnCollision;
	static SetPedCanBeKnockedOffVehicle_t SetPedCanBeKnockedOffVehicle;
	static SetPedConfigFlag_t SetPedConfigFlag;
	static DisableAllControls_t DisableAllControls;
	static SetEntityProof_t SetEntityProof;

	static void InitNativeFunctions()
	{
#ifdef SC_VERSION
		World2Screen = (WorldToScreen_t)(Mem::GetBase() + 0x9D5850); //done \x48\x89\x5C\x24\x00\x55\x56\x57\x48\x83\xEC\x70\x65\x4C\x8B\x0C\x25\x00\x00\x00\x00
		GetPlayerByIndex = (GetPlayerByIndex_t)(Mem::GetBase() + 0x9D3924); //done \x74\x1C\x83\xF9\x1F
		/*sit*/SetVehicleForwardSpeed = (SetVehicleForwardSpeed_t)(Mem::GetBase() + 0xCB4C04); //done \x48\x83\xEC\x38\x0F\x29\x74\x24\x00\x0F\x28\xF1
		GetPlayerPed = (GetPlayerPed_t)(Mem::GetBase() + 0xC5C40C); //done \x40\x53\x48\x83\xEC\x20\x33\xDB\x83\xF9\xFF\x74\x09\xB2\x01\xE8\x00\x00\x00\x00\xEB\x16
		GetVehiclePedIsIn = (GetVehiclePedIsIn_t)(Mem::GetBase() + 0xC5D834); //done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xF2\x33\xDB\xE8\x00\x00\x00
		GetPlayerID = (GetPlayerID_t)(Mem::GetBase() + 0xC5C2DC); //done \x48\x83\xEC\x28\x80\x3D\x00\x00\x00\x00\x00\x74\x12\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00 
		SetPedAmmo = (SetPedAmmo_t)(Mem::GetBase() + 0xCB5464); //done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00
		GetPedMaxAmmo = (GetPedMaxAmmo_t)(Mem::GetBase() + 0xCA5F50); //done \x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x8B\xDA
		HasPedGotWeapon = (HasPedGotWeapon_t)(Mem::GetBase() + 0xCA9C7C); //done \x74\x25\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x19\x48\x83\xC1\x18
		GiveWeaponToPed = (GiveWeaponToPed_t)(Mem::GetBase() + 0xCA9A80); //done \x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9
		SetEntityVisible = (SetEntityVisible_t)(Mem::GetBase() + 0xA212C8); //done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xFA\xE8\x00\x00
		SetPedCanRagdoll = (SetPedCanRagdoll_t)(Mem::GetBase() + 0xC70C50); //done \x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x40\x8A\xFA\xE8\x00\x00\x00\x00
		//SetPedCanRagdollOnCollision = (SetPedCanRagdollOnCollision_t)(Mem::GetBase() + 0xC6F230); //done \x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1E
		//SetPedCanBeKnockedOffVehicle = (SetPedCanBeKnockedOffVehicle_t)(Mem::GetBase() + 0xC6CE80); //done \x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2A
		//SetPedConfigFlag = (SetPedConfigFlag_t)(Mem::GetBase() + 0xC6D644); //done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x8B\xFA\xE8\x00\x00\x00
		DisableAllControls = (DisableAllControls_t)(Mem::GetBase() + 0xC56E48); //done \x40\x53\x48\x83\xEC\x20\x33\xDB\x85\xC9\x75\x09
		SetEntityProof = (SetEntityProof_t)(Mem::GetBase() + 0xA20E08); //done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xD9\x41\x8A\xF8
#elif defined(STEAM_VERSION)
		World2Screen = (WorldToScreen_t)(Mem::GetBase() + 0x9D6384); //done \x48\x89\x5C\x24\x00\x55\x56\x57\x48\x83\xEC\x70\x65\x4C\x8B\x0C\x25\x00\x00\x00\x00
		GetPlayerByIndex = (GetPlayerByIndex_t)(Mem::GetBase() + 0x9D4440); // done \x74\x1C\x83\xF9\x1F
		SetVehicleForwardSpeed = (SetVehicleForwardSpeed_t)(Mem::GetBase() + 0xCB88B8); // done \x48\x83\xEC\x38\x0F\x29\x74\x24\x00\x0F\x28\xF1
		GetPlayerPed = (GetPlayerPed_t)(Mem::GetBase() + 0xC5CD08); // done \x40\x53\x48\x83\xEC\x20\x33\xDB\x83\xF9\xFF\x74\x09\xB2\x01\xE8\x00\x00\x00\x00\xEB\x16
		GetVehiclePedIsIn = (GetVehiclePedIsIn_t)(Mem::GetBase() + 0xC5E130); // done \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x40\x8A\xF2\x33\xDB\xE8\x00\x00\x00
		GetPlayerID = (GetPlayerID_t)(Mem::GetBase() + 0xC5CBD8); // done \x48\x83\xEC\x28\x80\x3D\x00\x00\x00\x00\x00\x74\x12\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00 
		SetPedAmmo = (SetPedAmmo_t)(Mem::GetBase() + 0xCB5D18); // \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8B\xF0\x8B\xFA\xE8\x00\x00\x00
		GetPedMaxAmmo = (GetPedMaxAmmo_t)(Mem::GetBase() + 0xCA6804); // \x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x8B\xDA
		HasPedGotWeapon = (HasPedGotWeapon_t)(Mem::GetBase() + 0xCAA530); // \x74\x25\x48\x8B\x88\x00\x00\x00\x00\x48\x85\xC9\x74\x19\x48\x83\xC1\x18
		GiveWeaponToPed = (GiveWeaponToPed_t)(Mem::GetBase() + 0xCAA334); // \x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x41\x8A\xE9
		SetEntityVisible = (SetEntityVisible_t)(Mem::GetBase() + 0xA21CB4); // \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x40\x8A\xFA\xE8\x00\x00
		SetPedCanRagdoll = (SetPedCanRagdoll_t)(Mem::GetBase() + 0xC7154C); // \x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x40\x8A\xFA\xE8\x00\x00\x00\x00
		SetPedCanRagdollOnCollision = (SetPedCanRagdollOnCollision_t)(Mem::GetBase() + 0xC7357C); // \x40\x53\x48\x83\xEC\x20\x8A\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1E
		SetPedCanBeKnockedOffVehicle = (SetPedCanBeKnockedOffVehicle_t)(Mem::GetBase() + 0xC7113C); // \x40\x53\x48\x83\xEC\x20\x8B\xDA\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x2A
		SetPedConfigFlag = (SetPedConfigFlag_t)(Mem::GetBase() + 0xC71900); // \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xF0\x8B\xFA\xE8\x00\x00\x00
		DisableAllControls = (DisableAllControls_t)(Mem::GetBase() + 0xC57744); // \x40\x53\x48\x83\xEC\x20\x33\xDB\x85\xC9\x75\x09
		SetEntityProof = (SetEntityProof_t)(Mem::GetBase() + 0xA217F4); // \x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x41\x8A\xD9\x41\x8A\xF8
#endif
		Initialized = TRUE;
		//SetEntityVelocity = (SetEntityVelocity_t)(Mem::GetBase() + 0xA18EFC);
		
	}
	
	//world: 2280E80

	static BOOLEAN W2S(const Vector3& WorldPos, Vector3* ScrPos)
	{
		float x, y;
		if (World2Screen(WorldPos, &ScrPos->x, &ScrPos->y))
		{
			ScrPos->x *= DX11->ScreenSX;
			ScrPos->y *= DX11->ScreenSY;

			return TRUE;
		}
		return FALSE;
	}

	static void GiveWeaponsToPlayer(Ped Player, Hash dwWeapon = 0)
	{
		static Game::Hash Weapons[] = { WEAPON_ADVANCEDRIFLE, WEAPON_APPISTOL, WEAPON_ASSAULTRIFLE, WEAPON_ASSAULTSHOTGUN, WEAPON_ASSAULTSMG, WEAPON_BALL, WEAPON_BAT, WEAPON_BOTTLE,
			WEAPON_BULLPUPSHOTGUN, WEAPON_CARBINERIFLE, WEAPON_COMBATMG, WEAPON_COMBATPDW, WEAPON_COMBATPISTOL, WEAPON_CROWBAR, WEAPON_DAGGER, WEAPON_FIREEXTINGUISHER,
			WEAPON_FIREWORK, WEAPON_FLAREGUN, WEAPON_GOLFCLUB, WEAPON_GRENADE, WEAPON_GRENADELAUNCHER, WEAPON_GUSENBERG, WEAPON_HAMMER, WEAPON_HEAVYPISTOL,
			WEAPON_HEAVYSHOTGUN, WEAPON_HEAVYSNIPER, WEAPON_HOMINGLAUNCHER, WEAPON_KNIFE, WEAPON_KNUCKLE, WEAPON_MARKSMANPISTOL, WEAPON_MARKSMANRIFLE,
			WEAPON_MG, WEAPON_MICROSMG, WEAPON_MOLOTOV, WEAPON_MUSKET, WEAPON_NIGHTSTICK, WEAPON_PETROLCAN, WEAPON_PISTOL, WEAPON_PISTOL50, WEAPON_PROXMINE,
			WEAPON_PUMPSHOTGUN, WEAPON_RPG, WEAPON_SAWNOFFSHOTGUN, WEAPON_SMG, WEAPON_SMOKEGRENADE, WEAPON_SNIPERRIFLE, WEAPON_SNOWBALL, WEAPON_SNSPISTOL,
			WEAPON_SPECIALCARBINE, WEAPON_STICKYBOMB, WEAPON_STUNGUN, WEAPON_VINTAGEPISTOL, WEAPON_MINIGUN };


		auto GiveWeaponFunc = [](Ped _Player, Hash dwWeaponf)
		{
			int MaxAmmo = 0;
			GiveWeaponToPed(_Player, dwWeaponf, ((GetPedMaxAmmo(_Player, dwWeaponf, &MaxAmmo)) ? MaxAmmo : 9999), FALSE, TRUE);
		};

		if (dwWeapon == 0)
		{
			for each (Hash weapon in Weapons)
				GiveWeaponFunc(Player, weapon);
		}
		else GiveWeaponFunc(Player, dwWeapon);
	}

	static Vector3 GetWaypointPosition()
	{
#ifdef SC_VERSION
		QWORD RadarBase = 0x1ECC4F8;
#else
		QWORD RadarBase = 0x1ECF8D0 + 0x38;
#endif
		if (Mem::IsValid(((QWORD*)(Mem::GetBase() + RadarBase))))
		{
			Vector3 Pos = Mem::Read<Vector3>(Mem::GetBase() + RadarBase);
			Pos.z = -210.f;
			return Pos;
		}
		return Vector3();
	}

	static float Distance(const Vector3& v1, const Vector3& v2)
	{
		return sqrtf(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	}

};



class Features
{
public:

	static float fDamageMod;
	static float fVehImpulse;
	static float fMeleeDamage;
	static float fVehGravity;
	static float fAimingFOV;
	static float fESPMaxDistance;
	static float fDeformation;
	static float fRPMultiplier;
	static float fSurvivalCash;

	static BOOLEAN MenuOpened;
	static BOOLEAN IsGodMode;
	static BOOLEAN IsFullGodMode;
	static BOOLEAN FallFromVehicle;
	static BOOLEAN InvisiblePlayer;
	static BOOLEAN InvisibleVehicle;
	static BOOLEAN SuperJump;
	static BOOLEAN ExplosiveMelee;
	static BOOLEAN FireAmmo;
	static BOOLEAN ExplosiveAmmo;
	static BOOLEAN FastSwimSprint;
	static BOOLEAN NeverWanted;
	static BOOLEAN AlwaysWanted;

	static BOOLEAN SuperReload;
	static BOOLEAN SuperImpulse;
	static BOOLEAN UltraPenetration;
	static BOOLEAN NoSpread;
	static BOOLEAN NoRecoil;

	static BOOLEAN ESP;
	static BOOLEAN Boxes3D;
	static BOOLEAN ShowPeds;
	static BOOLEAN ShowPlayers;


};



//GAME CLASSES
//GAME CLASSES
//GAME CLASSES

class CNavigation
{
public:
	char pad_0[0x20];
	Vector4 Rotation;
	char pad_1[0x20];
	Vector3 Position;

};

class CPlayerWantedData
{
public:
	char _pad0[0x40];						// 0000 - 0040
	Vector3 vecWantedCentrePosition;		// 0040 - 004C
	float fUnknown;							// 004C - 0050
	Vector3 vecWantedCentrePosition2;		// 0050 - 005C
	float fUnknown2;                        // 005C - 0060
	char _pad1[0x34];
	BYTE bFlags1;                           // 0094 - 0095
	BYTE bFlags2;                           // 0095 - 0096
	BYTE bFlags3;                           // 0096 - 0097	(|= 1u; ignore player, &= 0xFEu; don't ignore player)
	BYTE bFlags4;                           // 0097 - 0098
	char _pad2[0xC];
	int WantedLevelFake;				// 00A4 - 00A8
	int WantedLevel;					// 00A8 - 00AC
};

class CPlayerInfo
{
public:
	char _pad0[0x7C];                       // 0000 - 007C
	char PlayerName[32];					// 007C - 009C
	char _pad1[0x48];						// 009C - 00E4
	float SwimSpeed;				// 00E4 - 00E8
	float SprintSpeed;			// 00E8 - 00EC
	char _pad2[0x38];						// 0128 - 0160
	DWORD dPlayerState;						// 0124 - 0128
	char _pad3[0x38];						// 0128 - 0160
	//CPed* pPlayerPed;						// 0160 - 0168
	DWORD64* pPlayerPed;
	char _pad4[0x28];						// 0168 - 0190
	int FrameFlags;					// 0190 - 0194
	char _pad5[0x55C];						// 0194 - 06F0
	CPlayerWantedData wantedLevelData;		// 06F0 - 0798
	char _pad6[0x47C];
	float fDamageMultiplier;                // C18  - C1c    
	char _pad7[0x4];       // 0C1C - 0C20
	float     fMeleeDamageMod;      // 0C20 - 0C24
	char     _pad8[0x4];       // 0C24 - 0C28
	float     fVehicleDamageMod;     // 0C28 - 0C2C
};

class CWeaponName
{
public:
	char Name[16];

};

class CAmmoInfo
{
public:
	char pad_0[0x28];		// 0000 - 0028
	int MaxAmmo;		// 0028 - 002C
};

class CHandling
{
public:
	char pad_0[0xF8];
	float fDeformationFactor;

};

class CVehicle
{
public:
		char pad_0x0000[0x30]; //0x0000
		CNavigation* Navigation; //0x0030 
		char pad_0x0038[0x58]; //0x0038
		Vector3 VisualPosition; //0x0090 
		char pad_0x009C[0x770]; //0x009C
		float health; //0x080C 
		char pad_0x0810[0x20]; //0x0810
		CHandling* Handling; //0x0830 
		char pad_0x0838[0x2E4]; //0x0838
		float Gravity; //0x0B1C 
		char pad_0x0B20[0x380]; //0x0B20

	};//Size=0x0EA0

class CWeaponInfo
{
public:
	char _0x0000[16];
	WORD N02F58D74; //0x0010 
	WORD N0179C4DA; //0x0012 
	WORD N0179A86F; //0x0014 
	WORD N0179DE56; //0x0016 
	WORD N02F58D75; //0x0018 
	WORD N0179DE58; //0x001A 
	WORD N0179A871; //0x001C 
	char _0x001E[2];
	BYTE bDamageType; //0x0020 
	char _0x0021[27];
	__int32 iAmmoType; //0x003C - 1 = no am 1->no ammo, 2->ar/pistol/sub machine/shotgun/heavy, 3->sniper, 4->projectile
	__int32 iWeaponWheelSlot; //0x0040 
	WORD wGroupHash; //0x0044 
	WORD haskUnknown; //0x0046 
	CAmmoInfo* AmmoInfo; //0x0048 
	//CAimingInfo* pAimingInfo; //0x0050 
	DWORD64* pAimingInfo;
	__int32 iRoundPerMagazine; //0x0058 
	float fAccurateModeAccuracyModifier; //0x005C
	float fRunAndGunAccuracyModifier; //0x0060 
	float fRunAndGunAccuracyMaxModifier; //0x0064 
	float fRecoilAccuracyMax; //0x0068 
	float fSpread; //0x006C 0->no spread       ----------fu
	float fRecoilErrorTime; //0x0070 
	float fRecoilRecoveryRate; //0x0074 
	float fRecoilAccuracyToAllowHeadShotAI; //0x0078 
	float fMinHeadShotDistanceAI; //0x007C 
	float fMaxHeadShotDistanceAI; //0x0080 
	float fHeadShotDamageModifierAI; //0x0084 
	float fRecoilAccuracyToAllowHeadShotPlayer; //0x0088 
	float fMinHeadShotDistancePlayer; //0x008C 
	float fMaxHeadShotDistancePlayer; //0x0090 
	float fHeadShotDamageModifierPlayer; //0x0094 
	float fBulletDamage; //0x0098 
	float fDamageTime; //0x009C 
	float fDamageTimeInVehicle; //0x00A0 
	float fDamageTimeInVehicleHeadShot; //0x00A4 
	float fHitLimbsDamageModifier; //0x00A8 
	float fNetworkHitLimbsDamageModifier; //0x00AC 
	float fLightlyArmouredDamageModifier; //0x00B0 
	float fForce; //0x00B4 
	float fForce2; //0x00B8 
	float fForceHitPed; //0x00BC 
	float fForceHitVehicle; //0x00C0
	float fForceHitFlyingHeli; //0x00C4 
	//CBoneForces* pBoneForces; //0x00C8 
	DWORD64* pBoneForces;
	__int16 iBoneForceFrontCount; //0x00D0 
	__int16 iBoneForceBackCount; //0x00D2 
	char _0x00D4[4];
	float fForceMaxStrengthMult; //0x00D8 
	float fForceFalloffRangeStart; //0x00DC 
	float fForceFalloffRangeEnd; //0x00E0 
	float fForceFalloffMin; //0x00E4 
	float fProjectileForce; //0x00E8 
	float fFragImpulse; //0x00EC 
	float fPenetration; //0x00F0 
	float fVerticalLaunchAdjustment; //0x00F4 
	float fDropForwardVelocity; //0x00F8 
	float fMuzzleVelocity; //0x00FC bullet speed
	__int32 iBulletsInBatch; //0x0100 bullet per shoot
	float fMultyBulletShootSpread; //0x0104 0 - 1 (0 no spread)
	float fReloadTimeMP; //0x0108 
	float fReloadTimeSP; //0x010C 
	float fVehicleReloadTime; //0x0110 
	float fReloadTimeMultiplier; //0x0114 
	__int32 iBulletsPerAnimLoop; //0x0118 
	float fTimeBetweenShots; //0x011C 
	float fTimeLeftBetweenShotsWhereShouldFireIsCached; //0x0120 
	char _0x0124[380];
	__int32 iMinTimeBetweenRecoilShakes; //0x02A0 
	float fRecoilMultiplier; //0x02A4 no recoil
	float fExplosionShakeAmplitude; //0x02A8 
	float fFirstPersonAimFovMin; //0x02AC 
	float fFirstPersonAimFovMax; //0x02B0 
	float fFirstPersonScopeFov; //0x02B4 
	float fFirstPersonScopeAttachmentFov; //0x02B8
	float fCameraFov; //0x02AC 
	char _0x02C0[0x2C8];
	CWeaponName* WeaponType; //0x0588

};


class CPedWeaponManager
{
public:
	char pad_0[0x20];
	CWeaponInfo* ActiveWeapon;

};

class CPed
{
public:
	char pad_0[0x30]; //0x0000
	CNavigation* Navigation; //0x0030 
	char pad_1[0x58]; //0x0038
	Vector3 VisualPosition; // 0x90
	char pad_11[0xEC]; //0x009c
	DWORD GodMode; //0x0188 
	char pad_2[0xF4]; //0x018C
	float Health; //0x0280 
	float MaxHealth; //0x0284 
	char pad_3[0xE00]; //0x0288
	CPlayerInfo* PlayerInfo; //0x1088 
	char pad_4[0x8]; //0x1090
	CPedWeaponManager* WeaponManager; //0x1098 
	char pad_5[0x3D4]; //0x10A0
	float Armor; //0x1474 
	char pad_6[0x20]; //0x1478
	CVehicle* CurrentVehicle; //0x1498
	char pad_7[0x8C];						// 14A0 - 152C
	BYTE IsVisible;					// 152C - 1530


	BOOLEAN IsInvincible()
	{
		if (GodMode == 4194316) return FALSE;
		else return TRUE;
	}

};

//\x48\x8B\x8C\xC2\x00\x00\x00\x00\x48\x85\xC9\x74\x19
//damage mod: F3 0F 11 B0 ? ? ? ? 0F 28 74 24 ? 48 83 C4 38 C3 90 C3
class CTuneables
{
public:
	char _pad0[0x10];								// 0000 - 0010
	float fRPMultiplier;							// 0010 - 0014
	char _pad1[0x2A4];								// 0014 - 02B8
	__int32 iIdleKickWarning1;						// 02B8 - 02BC
	char _pad2[0x4];								// 02BC - 02C0
	__int32 iIdleKickWarning2;						// 02C0 - 02C4
	char _pad3[0x4];								// 02C4 - 02C8
	__int32 iIdleKickWarning3;						// 02C8 - 02CC
	char _pad4[0x4];								// 02CC - 02D0
	__int32 iIdleKick;								// 02D0 - 02D4
	char _pad5[0x234];								// 02D4 - 0508
	__int32 iImpromptuRaceCashAwardCap;				// 0508 - 050C
	char _pad6[0xC];								// 050C - 0518
	float iImpromptuRaceExpensesMultiplier;			// 0518 - 051C
	char _pad7[0x92AC];								// 051C - 97C8
	__int32 iTurnSnowOnOff;							// 97C8 - 97CC
	char _pad8[0x2C];								// 97CC - 97F8
	__int32 iEnableXMasContent;						// 97F8 - 97FC
	char _pad9[0x4964];								// 97FC - E160
	__int32 iDisableSnowballs;						// E160 - E164
	char _pad10[0x4];								// E164 - E168
	__int32 iDisableXMasTreePS;						// E168 - E16C
	char _pad11[0x4];								// E16C - E170
	__int32 iDisableXMasTreeApt;					// E170 - E174
	char _pad12[0x4];								// E174 - E178
	__int32 iDisableXMasClothing;					// E178 - E17C
};

class LocalPlayer
{
public:
	struct CWeaponData
	{
	public:
		QWORD qwWepPTR;
		std::string Name;
		float fReloadMultiplier;
		float fRecoil;
		float fSpread;
		float fPenetration;
		float fImpulsePed;
		float fImpulseVeh;
		float fImpulseHeli;
	};

	static INT CTick;
	static INT LTick;

	static BOOLEAN IsDead;

	static std::map<std::string, CWeaponData> WeaponData;

	static void SetInvincible(BOOLEAN bState) { Features::IsGodMode = bState; }


	static void SetPedAmount(float fAmount) 
	{
#ifdef SC_VERSION
		DWORD PedAddress = 0x1BACAF0;
#elif defined(STEAM_VERSION)
		DWORD PedAddress = 0x1BB7C78;
#endif
		if (Mem::IsValid((QWORD*)(Mem::GetBase() + PedAddress)))
			Mem::Write<float>(Mem::GetBase() + PedAddress, fAmount);
	}

	static void SetVehicleAmount(float fAmount)
	{
#ifdef SC_VERSION
		DWORD VehicleAddress = 0x1C50FDC;
#elif defined(STEAM_VERSION)
		DWORD VehicleAddress = 0x1C56DE0;
#endif
		if (Mem::IsValid((QWORD*)(Mem::GetBase() + VehicleAddress)))
			Mem::Write<float>(Mem::GetBase() + VehicleAddress, fAmount);
	}

	static float GetPedAmount() // \xF3\x0F\x59\x05\x00\x00\x00\x00\xF3\x0F\x2C\xC0\xC3\x90\x48\x83\xEC\x38 steam
								// \xF3\x0F\x59\x05\x00\x00\x00\x00\xF3\x0F\x2C\xC0\xC3\xCC\x48\x83\xEC\x38 sc
	{
#ifdef SC_VERSION
		DWORD PedAddress = 0x1BACAF0;
#elif defined(STEAM_VERSION)
		DWORD PedAddress = 0x1BB7C78;
#endif
		if (Mem::IsValid((QWORD*)(Mem::GetBase() + PedAddress)))
			return Mem::Read<float>(Mem::GetBase() + PedAddress);
	}

	static float GetVehicleAmount() // \xF3\x0F\x11\x05\x00\x00\x00\x00\xC3\x90\x48\x89\x5C\x24\x00 steam / sc
	{
#ifdef SC_VERSION
		DWORD VehicleAddress = 0x1C50FDC;
#elif defined(STEAM_VERSION)
		DWORD VehicleAddress = 0x1C56DE0;
#endif
		if (Mem::IsValid((QWORD*)(Mem::GetBase() + VehicleAddress)))
			return Mem::Read<float>(Mem::GetBase() + VehicleAddress);
	}

	static BOOLEAN IsFullySpawned() // \x88\x1D\x00\x00\x00\x00\x89\x05\x00\x00\x00\x00\xEB\x06
	{
#ifdef SC_VERSION
		return Mem::Read<BOOLEAN>(Mem::GetBase() + 0x23B1460); 
#elif defined(STEAM_VERSION)
		return Mem::Read<BOOLEAN>(Mem::GetBase() + 0x23B48E0);
#endif
	}

	static float GetVehicleDeformation()
	{
		CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
		if (Mem::IsValid(MyPlayer))
		{
			if (Mem::IsValid(MyPlayer->CurrentVehicle))
			{
				if (Mem::IsValid(MyPlayer->CurrentVehicle->Handling))
					return MyPlayer->CurrentVehicle->Handling->fDeformationFactor;
			}
		}
		return 0;
	}

	static void SetVehicleDeformation(float fFactor)
	{
		CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
		if (Mem::IsValid(MyPlayer))
		{
			if (Mem::IsValid(MyPlayer->CurrentVehicle))
			{
				if (Mem::IsValid(MyPlayer->CurrentVehicle->Handling))
					MyPlayer->CurrentVehicle->Handling->fDeformationFactor = fFactor;
			}
		}
	}

	static void ToogleSwimSprintVel()
	{
		CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
		if (Mem::IsValid(MyPlayer))
		{
			if (Mem::IsValid(MyPlayer->PlayerInfo))
			{
				if (Features::FastSwimSprint)
				{
					MyPlayer->PlayerInfo->SwimSpeed = 2.f;
					MyPlayer->PlayerInfo->SprintSpeed = 10.f;
				}
				else
				{
					MyPlayer->PlayerInfo->SwimSpeed = 1.f;
					MyPlayer->PlayerInfo->SprintSpeed = 1.f;
				}
			}
		}
	}

	static void Teleport(Vector3 destination)
	{
		CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
		if (Mem::IsValid(MyPlayer))
		{
			if (Mem::IsValid(MyPlayer->Navigation))
			{
				if (Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), FALSE))
				{
					MyPlayer->CurrentVehicle->VisualPosition = destination;
					MyPlayer->CurrentVehicle->Navigation->Position = destination;
				}
				MyPlayer->VisualPosition = destination;
				MyPlayer->Navigation->Position = destination;
			}
		}
	}

	static Game::Ped GetPlayerPedFromName(const char* PlayerName)
	{
		for (int i = 0; i < 0x1E; i++)
		{
			CPed* Player = (CPed*)Game::GetPlayerByIndex(i);
			if (Mem::IsValid(Player))
			{
				if (Mem::IsValid(Player->PlayerInfo))
				{
					if (!strcmp(PlayerName, Player->PlayerInfo->PlayerName))
						return Game::GetPlayerPed(i);
				}
			}
		}
		return Game::GetPlayerPed(Game::GetPlayerID());
	}

	static CPed* GetPlayerPTRFromName(const char* PlayerName)
	{
		for (int i = 0; i < 0x1E; i++)
		{
			CPed* Player = (CPed*)Game::GetPlayerByIndex(i);
			if (Mem::IsValid(Player))
			{
				if (Mem::IsValid(Player->PlayerInfo))
				{
					if (!strcmp(PlayerName, Player->PlayerInfo->PlayerName))
						return (CPed*)Player;
				}
			}
		}
		return nullptr;
	}

	static void GiveHealthArmor()
	{
		CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
		if (Mem::IsValid(MyPlayer))
		{
			MyPlayer->Health = MyPlayer->MaxHealth;
			MyPlayer->Armor = 50;
		}
	}

	/*static void ToggleASMGodMode() //EDIT THIS IF U HAVE A FUNCTION HOOK LIBRARY
	{
		if (Features::IsGodMode)
		{
#ifdef SC_VERSION
			QWORD FuncStart = (QWORD)GetModuleHandle("GTA5.exe") + 0x8A5C08;
			QWORD Address = (QWORD)GetModuleHandle("GTA5.exe") + 0x8A5CD5;
#elif defined(STEAM_VERSION)
			QWORD FuncStart = (QWORD)GetModuleHandle("GTA5.exe") + 0x8A5F6C;
			QWORD Address = (QWORD)GetModuleHandle("GTA5.exe") + 0x8A6039;
#endif
			std::vector<BYTE> originalBytes = { 0xF3, 0x0F, 0x58, 0xB6, 0x80, 0x02, 0x00, 0x00, 0xB9, 0x04, 0x00, 0x00, 0x00, 0xF3, 0x0F, 0x11, 0xB6, 0x80, 0x02, 0x00, 0x00 };

			RA_Damage = Address + originalBytes.size();

			ASMGodMode.SetupHook(Address, (QWORD)(DisableDamage), originalBytes, true, FuncStart, 274);
			ASMGodMode.Hook();
		}
		else
		{
			ASMGodMode.UnHook(true);
		}
	}*/

	/*static void SetRPMultiplier(float fFactor)			//tuneables address here
	{
#ifdef SC_VERSION
		QWORD Tuneables = Mem::Read<QWORD>(Mem::GetBase() + 0x2B5FCD8);
#elif defined(STEAM_VERSION)
		QWORD Tuneables = Mem::Read<QWORD>(Mem::GetBase() + 0x2B641E8);
#endif
		if (Mem::IsValid((QWORD*)Tuneables))
			Mem::Write<float>(Tuneables + 0x10, fFactor);
	}*/

	/*static void SetSurvivalCashMultiplier(float fFactor)
	{
#ifdef SC_VERSION
		QWORD Tuneables = Mem::Read<QWORD>(Mem::GetBase() + 0x2B5FCD8);
#elif defined(STEAM_VERSION)
		QWORD Tuneables = Mem::Read<QWORD>(Mem::GetBase() + 0x2B641E8);
#endif
		Mem::Write<float>(Tuneables + 0x9CB8, fFactor);
	}*/

	static void KillAllPeds()
	{
#ifdef SC_VERSION
		DWORD NPCList = 0x2C54D90 + 0x30;
#elif defined(STEAM_VERSION)
		DWORD NPCList = 0x2C59490 + 0x30;
#endif
		for (int i = 0; i < Mem::Read<int>(Mem::Read<QWORD>(Mem::GetBase() + NPCList) + 0x8); i++) // sig \x4C\x8D\x05\x00\x00\x00\x00\x49\x8B\xCA\xE8\x00\x00\x00\x00
		{
			QWORD Base = Mem::Read<QWORD>(Mem::GetBase() + NPCList);
			CPed* Ped = Mem::Read<CPed*>(Base + 0x860 + (i * 0x8));
			if (Mem::IsValid(Ped))
			{
				if (Ped != ((CPed*)Game::GetPlayerByIndex(Game::GetPlayerID())))
				{
					if (Ped->Health > 0 && Ped->Health <= 200)
						Ped->Health = 0;
				}
			}
		}
	}

	static void ToggleFallFromVehicle(Game::Ped LocalPed)
	{
		Game::SetPedCanRagdoll(LocalPed, Features::FallFromVehicle);
		Game::SetPedCanRagdollOnCollision(LocalPed, Features::FallFromVehicle);
		Game::SetPedCanBeKnockedOffVehicle(LocalPed, !Features::FallFromVehicle);
		Game::SetPedConfigFlag(LocalPed, 32, Features::FallFromVehicle);
	}

	static void SetActualVehicleGravity(CPed* myPlayer, float fGravity)
	{
		if (Mem::IsValid(myPlayer->CurrentVehicle) && myPlayer->CurrentVehicle->Gravity > -21.f && myPlayer->CurrentVehicle->Gravity < 21.f)
			myPlayer->CurrentVehicle->Gravity = fGravity;
	}

	static void RefreshData()
	{
		try
		{
			if (!Game::Initialized || !GUIElements::Initialized) return;

			CPed* MyPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());
			if (Mem::IsValid(MyPlayer) && MyPlayer->Health >= 100 && LocalPlayer::IsFullySpawned())
			{
				Game::Ped MyLocalPed = Game::GetPlayerPed(Game::GetPlayerID());

				//ASMLocalPlayer = (QWORD)((QWORD*)Game::GetPlayerByIndex(Game::GetPlayerID())); //EDIT THIS IF U HAVE A FUNCTION HOOK LIBRARY

				if (MyLocalPed)
				{
					/*if (Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), FALSE))
					{
						ToggleFallFromVehicle(MyLocalPed);
					}*/

					if (CTick - LTick >= 5000)
					{
						auto SetEntityProofsFunc = [](Game::Entity _Entity)
						{
							Game::SetEntityProof(_Entity, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode, Features::IsFullGodMode);
						};

						if (Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), FALSE))
						{
							SetEntityProofsFunc(Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), FALSE));
							SetEntityProofsFunc(MyLocalPed);
						}
						else SetEntityProofsFunc(MyLocalPed);

						ToogleSwimSprintVel();

						LTick = CTick;
					}
					if (Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), FALSE))
					{
						SetActualVehicleGravity(MyPlayer, Features::fVehGravity);
						SetVehicleDeformation(Features::fDeformation);
					}
				}

				if (Mem::IsValid(MyPlayer->WeaponManager))
				{
					if (Mem::IsValid(MyPlayer->WeaponManager->ActiveWeapon))
					{
						if (Mem::IsValid(MyPlayer->WeaponManager->ActiveWeapon->WeaponType))
						{
							if (MyPlayer->WeaponManager->ActiveWeapon->iAmmoType == 2 || MyPlayer->WeaponManager->ActiveWeapon->iAmmoType == 3)
							{
								auto SetWeaponData = [](char* _WeaponName, int Data)
								{
									if (Data == 0 || Data == -1) ((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fReloadTimeMultiplier = WeaponData[_WeaponName].fReloadMultiplier;
									if (Data == 1 || Data == -1) ((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fRecoilMultiplier = WeaponData[_WeaponName].fRecoil;
									if (Data == 2 || Data == -1) ((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fSpread = WeaponData[_WeaponName].fSpread;
									if (Data == 3 || Data == -1) ((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fPenetration = WeaponData[_WeaponName].fPenetration;
									if (Data == 4 || Data == -1)
									{
										((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fForceHitPed = WeaponData[_WeaponName].fImpulsePed;
										((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fForceHitVehicle = WeaponData[_WeaponName].fImpulseVeh;
										((CWeaponInfo*)WeaponData[_WeaponName].qwWepPTR)->fForceHitFlyingHeli = WeaponData[_WeaponName].fImpulseHeli;
									}

								};

								char* WeaponName = MyPlayer->WeaponManager->ActiveWeapon->WeaponType->Name;
								if (WeaponData[WeaponName].qwWepPTR)
								{
									if (Features::SuperReload)
										MyPlayer->WeaponManager->ActiveWeapon->fReloadTimeMultiplier = 750.f;
									else SetWeaponData(WeaponName, 0);

									if (Features::NoRecoil)
										MyPlayer->WeaponManager->ActiveWeapon->fRecoilMultiplier = 0.f;
									else SetWeaponData(WeaponName, 1);

									if (Features::NoSpread)
										MyPlayer->WeaponManager->ActiveWeapon->fSpread = 0.f;
									else SetWeaponData(WeaponName, 2);

									if (Features::UltraPenetration)
										MyPlayer->WeaponManager->ActiveWeapon->fPenetration = 9999.f;
									else SetWeaponData(WeaponName, 3);

									if (Features::SuperImpulse)
									{
										MyPlayer->WeaponManager->ActiveWeapon->fForceHitPed = 999999.f;
										MyPlayer->WeaponManager->ActiveWeapon->fForceHitVehicle = 999999.f;
										MyPlayer->WeaponManager->ActiveWeapon->fForceHitFlyingHeli = 999999.f;
									}
									else SetWeaponData(WeaponName, 4);

									MyPlayer->WeaponManager->ActiveWeapon->fCameraFov = Features::fAimingFOV;
								}
								else
								{
									WeaponData[WeaponName].qwWepPTR = (QWORD)MyPlayer->WeaponManager->ActiveWeapon;
									WeaponData[WeaponName].Name = WeaponName;
									WeaponData[WeaponName].fReloadMultiplier = MyPlayer->WeaponManager->ActiveWeapon->fReloadTimeMultiplier;
									WeaponData[WeaponName].fRecoil = MyPlayer->WeaponManager->ActiveWeapon->fRecoilMultiplier;
									WeaponData[WeaponName].fSpread = MyPlayer->WeaponManager->ActiveWeapon->fSpread;
									WeaponData[WeaponName].fPenetration = MyPlayer->WeaponManager->ActiveWeapon->fPenetration;
									WeaponData[WeaponName].fImpulsePed = MyPlayer->WeaponManager->ActiveWeapon->fForceHitPed;
									WeaponData[WeaponName].fImpulseVeh = MyPlayer->WeaponManager->ActiveWeapon->fForceHitVehicle;
									WeaponData[WeaponName].fImpulseHeli = MyPlayer->WeaponManager->ActiveWeapon->fForceHitFlyingHeli;
								}

								for (std::map<std::string, CWeaponData>::iterator it = WeaponData.begin(); it != WeaponData.end(); ++it)
								{
									if (it->second.qwWepPTR != (QWORD)MyPlayer->WeaponManager->ActiveWeapon)
										SetWeaponData((char*)it->second.Name.c_str(), -1);
								}
							}
						}
					}
				}

				//SetRPMultiplier(Features::fRPMultiplier);
				//SetSurvivalCashMultiplier(Features::fSurvivalCash);

				if (Mem::IsValid(MyPlayer->PlayerInfo))
				{
					MyPlayer->PlayerInfo->fDamageMultiplier = Features::fDamageMod;
					MyPlayer->PlayerInfo->fMeleeDamageMod = Features::fMeleeDamage;

					if (Features::SuperJump)			MyPlayer->PlayerInfo->FrameFlags = (1 << 14);
					else if (Features::ExplosiveMelee)  MyPlayer->PlayerInfo->FrameFlags = (1 << 13);
					else if (Features::FireAmmo)		MyPlayer->PlayerInfo->FrameFlags = (1 << 12);
					else if (Features::ExplosiveAmmo)   MyPlayer->PlayerInfo->FrameFlags = (1 << 11);

					if (Features::NeverWanted && MyPlayer->PlayerInfo->wantedLevelData.WantedLevel > 0 && MyPlayer->PlayerInfo->wantedLevelData.WantedLevel <= 5)
						MyPlayer->PlayerInfo->wantedLevelData.WantedLevel = 0;
					else if (Features::AlwaysWanted && MyPlayer->PlayerInfo->wantedLevelData.WantedLevel < 5)
						MyPlayer->PlayerInfo->wantedLevelData.WantedLevel = 5;
				}

				CTick = GetTickCount();
			}
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}


};


#endif