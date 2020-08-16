#include "stdafx.h"


BOOLEAN Game::ThreadState[2] = { TRUE };
BOOLEAN Game::Initialized = FALSE;

Game::WorldToScreen_t Game::World2Screen = NULL;
Game::GetPlayerByIndex_t Game::GetPlayerByIndex = NULL;
Game::SetVehicleForwardSpeed_t Game::SetVehicleForwardSpeed = NULL;
Game::GetPlayerPed_t Game::GetPlayerPed = NULL;
Game::GetVehiclePedIsIn_t Game::GetVehiclePedIsIn = NULL;
Game::GetPlayerID_t Game::GetPlayerID = NULL;
Game::SetEntityInvincible_t Game::SetEntityInvincible = NULL;
Game::SetPedAmmo_t Game::SetPedAmmo = NULL;
Game::GetPedMaxAmmo_t Game::GetPedMaxAmmo = NULL;
Game::HasPedGotWeapon_t Game::HasPedGotWeapon = NULL;
Game::GiveWeaponToPed_t Game::GiveWeaponToPed = NULL;
Game::SetEntityProof_t Game::SetEntityProof = NULL;
Game::SetEntityVelocity_t Game::SetEntityVelocity = NULL;
Game::SetEntityVisible_t Game::SetEntityVisible = NULL;
Game::SetPedCanRagdoll_t Game::SetPedCanRagdoll = NULL;
Game::SetPedCanRagdollOnCollision_t Game::SetPedCanRagdollOnCollision = NULL;
Game::SetPedCanBeKnockedOffVehicle_t Game::SetPedCanBeKnockedOffVehicle = NULL;
Game::SetPedConfigFlag_t Game::SetPedConfigFlag = NULL;
Game::DisableAllControls_t Game::DisableAllControls = NULL;

float Features::fDamageMod = 0.72f;
float Features::fVehImpulse = -100.f;
float Features::fMeleeDamage = 1.f;
float Features::fVehGravity = 9.8f;
float Features::fAimingFOV = 40.f;
float Features::fESPMaxDistance = 1000.f;
float Features::fDeformation = 0.8f;
float Features::fRPMultiplier = 1.f;
float Features::fSurvivalCash = 1.f;

BOOLEAN Features::IsGodMode = FALSE;
BOOLEAN Features::IsFullGodMode = FALSE;
BOOLEAN Features::MenuOpened = FALSE;
BOOLEAN Features::FallFromVehicle = TRUE;
BOOLEAN Features::InvisiblePlayer = FALSE;
BOOLEAN Features::InvisibleVehicle = FALSE;
BOOLEAN Features::FastSwimSprint = FALSE;
BOOLEAN Features::AlwaysWanted = FALSE;
BOOLEAN Features::NeverWanted = FALSE;
BOOLEAN Features::SuperJump = FALSE;
BOOLEAN Features::ExplosiveMelee = FALSE;
BOOLEAN Features::FireAmmo = FALSE;
BOOLEAN Features::ExplosiveAmmo = FALSE;
BOOLEAN Features::SuperImpulse = FALSE;
BOOLEAN Features::UltraPenetration = FALSE;
BOOLEAN Features::NoSpread = FALSE;
BOOLEAN Features::SuperReload = FALSE;
BOOLEAN Features::NoRecoil = FALSE;

BOOLEAN Features::ESP = FALSE;
BOOLEAN Features::Boxes3D = FALSE;
BOOLEAN Features::ShowPeds = FALSE;
BOOLEAN Features::ShowPlayers = FALSE;

INT LocalPlayer::LTick = 0;
INT LocalPlayer::CTick = 5000;
BOOLEAN LocalPlayer::IsDead = FALSE;


std::map<std::string, LocalPlayer::CWeaponData> LocalPlayer::WeaponData;

QWORD ASMLocalPlayer = NULL;
QWORD RA_Damage = NULL;
//HookFunction ASMGodMode; //EDIT THIS IF U HAVE A FUNCTION HOOK LIBRARY


void MainThread()
{
	BOOLEAN console = FALSE;
	if (console)
	{
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	}

	while (true)
	{
		IHooks::HooksInput();

		LocalPlayer::RefreshData();

		//CLOSING
		if (!Game::ThreadState[0])
		{
			if (console) ShowWindow(GetConsoleWindow(), SW_HIDE);
			Game::ThreadState[1] = FALSE;
			ExitThread(1);
			break;
		}

		/*if (MyYAML::Initialized && GUIElements::Initialized)
		{
			if (MyYAML::CSaveTick - MyYAML::LSaveTick > 15000)
			{
				MyYAML::SaveData();
				MyYAML::LSaveTick = MyYAML::CSaveTick;
			}
			MyYAML::CSaveTick = GetTickCount();
		}*/

		
		Sleep(1);
	}
}

