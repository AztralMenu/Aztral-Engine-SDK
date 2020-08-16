#include "stdafx.h"
#include "IDX11.h"

float DX11Renderer::ScreenX = 0, DX11Renderer::ScreenY = 0;
float DX11Renderer::ScreenSX = 0, DX11Renderer::ScreenSY = 0;

SimpleMath::Vector2 GUI2::LastMousePosition = SimpleMath::Vector2(0, 0);
SimpleMath::Vector2 GUI2::MousePosition = SimpleMath::Vector2(0, 0);

typedef HRESULT(__stdcall* D3D11PresentHook) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
D3D11PresentHook DX11HookPresent = NULL;
PLH::Detour* PresentHook;

#include "stdafx.h"

GID TWindows = 0;
GID TCheckboxes = 0;
GID TTabs = 0;
GID TProgressBars = 0;
GID TLabels = 0;
GID TDropMenus = 0;
GID TButtons = 0;

SimpleMath::Vector2 CGUI::CursorPos = SimpleMath::Vector2();
INT CGUI::LastClick = 0;
INT CGUI::LastTick = 0;
INT CGUI::CurrentTick = 60000;

BOOLEAN GUIElements::Initialized = FALSE;


void GUIElements::InitGUIElements()
{
	//YAML LOADING GUI STUFF
	Color MainWndColor;
	/*if (MyYAML::Initialized)
	{
	MainWndColor = Color(MyYAML::GetValueFromNode<int>("Menu_Color", "Red"), MyYAML::GetValueFromNode<int>("Menu_Color", "Green"), MyYAML::GetValueFromNode<int>("Menu_Color", "Blue"), MyYAML::GetValueFromNode<int>("Menu_Color", "Alpha"));

	//MAIN WINDOW
	GID MainWindow = GUIElements::GUICreateWindow(new CWindow(Rect(200, 200, 485, 375), "UnKnoWnCheaTs GTA V Ultimatum - By Tonyx97", Vector2(380, 300), 2, MainWndColor, Color(255, 255, 255, 255), 0, -1, "")); //STORES TAB SIZE

	//TABS
	GID MainTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "Main", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 0));
	GID WeaponsTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "Weapons", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 1));
	GID TeleportTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "Teleport", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 2));
	GID ESPTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "ESP", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 3));
	GID CustomizationTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "Customization", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 4));
	//GID SettingsTab = GUIElements::GUICreateTab(new CTab(Rect(10, 10, 0, 30), "Settings", Color(0, 0, 0, 180), Color(255, 255, 255, 255), Color(255, 255, 255, 255), MainWindow, "window", 5));

	//DEFAULT TABS FOR CUSTOMIZATION
	CDropMenuElements* VirtualKeys = new CDropMenuElements("VKeys");
	VirtualKeys->InsertItem("F1", VK_F1);
	VirtualKeys->InsertItem("F2", VK_F2);
	VirtualKeys->InsertItem("F3", VK_F3);
	VirtualKeys->InsertItem("F4", VK_F4);
	VirtualKeys->InsertItem("F5", VK_F5);
	VirtualKeys->InsertItem("F6", VK_F6);
	VirtualKeys->InsertItem("F7", VK_F7);
	VirtualKeys->InsertItem("F8", VK_F8);
	VirtualKeys->InsertItem("F9", VK_F9);
	VirtualKeys->InsertItem("F10", VK_F10);
	VirtualKeys->InsertItem("F11", VK_F11);
	VirtualKeys->InsertItem("F12", VK_F12);
	VirtualKeys->InsertItem("NUMPAD 0", VK_NUMPAD0);
	VirtualKeys->InsertItem("NUMPAD 1", VK_NUMPAD1);
	VirtualKeys->InsertItem("NUMPAD 2", VK_NUMPAD2);
	VirtualKeys->InsertItem("NUMPAD 3", VK_NUMPAD3);
	VirtualKeys->InsertItem("NUMPAD 4", VK_NUMPAD4);
	VirtualKeys->InsertItem("NUMPAD 5", VK_NUMPAD5);
	VirtualKeys->InsertItem("NUMPAD 6", VK_NUMPAD6);
	VirtualKeys->InsertItem("NUMPAD 7", VK_NUMPAD7);
	VirtualKeys->InsertItem("NUMPAD 8", VK_NUMPAD8);
	VirtualKeys->InsertItem("NUMPAD 9", VK_NUMPAD9);
	VirtualKeys->InsertItem("0", 0x30);
	VirtualKeys->InsertItem("1", 0x31);
	VirtualKeys->InsertItem("2", 0x32);
	VirtualKeys->InsertItem("3", 0x33);
	VirtualKeys->InsertItem("4", 0x34);
	VirtualKeys->InsertItem("5", 0x35);
	VirtualKeys->InsertItem("6", 0x36);
	VirtualKeys->InsertItem("7", 0x37);
	VirtualKeys->InsertItem("8", 0x38);
	VirtualKeys->InsertItem("9", 0x39);
	VirtualKeys->InsertItem("A", 0x41);
	VirtualKeys->InsertItem("B", 0x42);
	VirtualKeys->InsertItem("C", 0x43);
	VirtualKeys->InsertItem("D", 0x44);
	VirtualKeys->InsertItem("E", 0x45);
	VirtualKeys->InsertItem("F", 0x46);
	VirtualKeys->InsertItem("G", 0x47);
	VirtualKeys->InsertItem("H", 0x48);
	VirtualKeys->InsertItem("I", 0x49);
	VirtualKeys->InsertItem("J", 0x4A);
	VirtualKeys->InsertItem("K", 0x4B);
	VirtualKeys->InsertItem("J", 0x4C);
	VirtualKeys->InsertItem("M", 0x4D);
	VirtualKeys->InsertItem("N", 0x4E);
	VirtualKeys->InsertItem("O", 0x4F);
	VirtualKeys->InsertItem("P", 0x50);
	VirtualKeys->InsertItem("Q", 0x51);
	VirtualKeys->InsertItem("R", 0x52);
	VirtualKeys->InsertItem("S", 0x53);
	VirtualKeys->InsertItem("T", 0x54);
	VirtualKeys->InsertItem("U", 0x55);
	VirtualKeys->InsertItem("V", 0x56);
	VirtualKeys->InsertItem("W", 0x57);
	VirtualKeys->InsertItem("X", 0x58);
	VirtualKeys->InsertItem("Y", 0x59);
	VirtualKeys->InsertItem("Z", 0x5A);
	VirtualKeys->InsertItem("Multiply", VK_MULTIPLY);
	VirtualKeys->InsertItem("Divide", VK_DIVIDE);
	VirtualKeys->InsertItem("Add", VK_ADD);
	VirtualKeys->InsertItem("Substract", VK_SUBTRACT);
	VirtualKeys->InsertItem("Separator", VK_SEPARATOR);
	VirtualKeys->InsertItem("Decimal", VK_DECIMAL);

	GID ImpulseKey_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(10, 40, 0, 0), "virtualkeys", "Impulse Key", VirtualKeys, Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), CustomizationTab, "tab", "Impulse Key"));
	GID InstantStopKey_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(140, 40, 0, 0), "virtualkeys", "Instant Stop Key", VirtualKeys->GetCopy(), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), CustomizationTab, "tab", "Instant Stop Key"));
	GID OpenMenuKey_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(300, 40, 0, 0), "virtualkeys", "Menu Key", VirtualKeys->GetCopy(), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), CustomizationTab, "tab", "Menu Key"));
	GID KillAllPeds_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(180, 195, 0, 0), "virtualkeys", "Kill Peds Key", VirtualKeys->GetCopy(), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), CustomizationTab, "tab", "Kill All Peds"));

	GID MenuRed_PB = GUIElements::GUICreateProgressBar(new CProgressBar("menured", Rect(10, 180, 150, 5), "Menu Red: %i", (int)MainWndColor.R(), Color(0, 255, 0, 255), Color(100, 100, 100, 175), CustomizationTab, "tab"));
	GID MenuGreen_PB = GUIElements::GUICreateProgressBar(new CProgressBar("menugreen", Rect(10, 210, 150, 5), "Menu Green: %i", (int)MainWndColor.G(), Color(0, 255, 0, 255), Color(100, 100, 100, 175), CustomizationTab, "tab"));
	GID MenuBlue_PB = GUIElements::GUICreateProgressBar(new CProgressBar("menublue", Rect(10, 240, 150, 5), "Menu Blue: %i", (int)MainWndColor.B(), Color(0, 255, 0, 255), Color(100, 100, 100, 175), CustomizationTab, "tab"));
	GID MenuAlpha_PB = GUIElements::GUICreateProgressBar(new CProgressBar("menualpha", Rect(10, 270, 150, 5), "Menu Alpha: %i", (int)MainWndColor.A(), Color(0, 255, 0, 255), Color(100, 100, 100, 175), CustomizationTab, "tab"));

	GUIDropMenus[ImpulseKey_DM]->SetMainItem(MyYAML::GetValueFromNode<std::string>("Customizables", "Vehicle_Impulse_Key").c_str());
	GUIDropMenus[InstantStopKey_DM]->SetMainItem(MyYAML::GetValueFromNode<std::string>("Customizables", "Vehicle_Instant_Stop_Key").c_str());
	GUIDropMenus[OpenMenuKey_DM]->SetMainItem(MyYAML::GetValueFromNode<std::string>("Customizables", "Menu_Key").c_str());
	GUIDropMenus[KillAllPeds_DM]->SetMainItem(MyYAML::GetValueFromNode<std::string>("Customizables", "Kill_All_Peds_Key").c_str());

	//MAIN TAB
	GID FullGodMode_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 10, 0, 0), "Full God Mode", "full_godmode", Features::IsFullGodMode = MyYAML::GetValueFromNode<bool>("Main", "Full_God_Mode"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID GodMode_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 30, 0, 0), "Broken lol", "asm_godmode", Features::IsGodMode, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	//GID FallFromVehicle_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 50, 0, 0), "Developing...", "fallfromvehicle", Features::FallFromVehicle, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID InvisiblePlayer_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 70, 0, 0), "Invisible Player", "invisibleplayer", Features::InvisiblePlayer, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID InvisibleVehicle_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 90, 0, 0), "Invisible Vehicle", "invisiblevehicle", Features::InvisibleVehicle, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID FastSwimSprint_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 110, 0, 0), "Fast Swim & Sprint", "fastswimetc", Features::FastSwimSprint = MyYAML::GetValueFromNode<bool>("Main", "Fast_Movement"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID NeverWanted_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 130, 0, 0), "Never Wanted", "neverwanted", Features::NeverWanted, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID AlwaysWanted_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 150, 0, 0), "Always Wanted", "alwayswanted", Features::AlwaysWanted, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID SuperJump_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 170, 0, 0), "Super Jump", "superjump", Features::SuperJump, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID ExplosiveMelee_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 190, 0, 0), "Explosive Melee", "explosivemelee", Features::ExplosiveMelee, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID FireAmmo_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 210, 0, 0), "Fire Ammo", "fireammo", Features::FireAmmo, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));
	GID ExplosiveAmmo_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 230, 0, 0), "Explosive Ammo", "explosiveammo", Features::ExplosiveAmmo, Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), MainTab, "tab"));

	//GID RPMultiplier_PB = GUIElements::GUICreateProgressBar(new CProgressBar("rpmultiplier", Rect(10, 260, 200, 5), "RP Multiplier: %.2f", 1.f, Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID DamageMod_PB = GUIElements::GUICreateProgressBar(new CProgressBar("damagemod", Rect(10, 290, 200, 5), "Damage Mod: %.2f", Features::fDamageMod = MyYAML::GetValueFromNode<float>("Main", "Damage_Mod"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID VehImpulse_PB = GUIElements::GUICreateProgressBar(new CProgressBar("vehimpulse", Rect(225, 50, 175, 5), "Vehicle Impulse: %.2f", Features::fVehImpulse = MyYAML::GetValueFromNode<float>("Main", "Vehicle_Impulse"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID MeleeDamage_PB = GUIElements::GUICreateProgressBar(new CProgressBar("meleedamage", Rect(225, 80, 175, 5), "Melee Damage: %.2f", Features::fMeleeDamage = MyYAML::GetValueFromNode<float>("Main", "Melee_Damage"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID VehicleGravity_PB = GUIElements::GUICreateProgressBar(new CProgressBar("vehiclegravity", Rect(225, 110, 175, 5), "Vehicle Gravity: %.1f", Features::fVehGravity = MyYAML::GetValueFromNode<float>("Main", "Vehicle_Gravity"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID PedAmount_PB = GUIElements::GUICreateProgressBar(new CProgressBar("pedamount", Rect(225, 140, 175, 5), "Ped Amount: %.2f", MyYAML::GetValueFromNode<float>("Main", "Ped_Amount"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID VehicleAmount_PB = GUIElements::GUICreateProgressBar(new CProgressBar("vehicleamount", Rect(225, 170, 175, 5), "Vehicle Amount: %.2f", MyYAML::GetValueFromNode<float>("Main", "Vehicle_Amount"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	GID VehicleDeformation_PB = GUIElements::GUICreateProgressBar(new CProgressBar("vehdeformation", Rect(225, 200, 175, 5), "Vehicle Deformation: %.1f", Features::fDeformation, Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));
	//GID SurvivalCashModifier_PB = GUIElements::GUICreateProgressBar(new CProgressBar("survivalcash", Rect(225, 230, 175, 5), "Coming soon %.1f", 1.f, Color(0, 255, 0, 255), Color(100, 100, 100, 175), MainTab, "tab"));

	GID GiveHealth_BTN = GUIElements::GUICreateButton(new CButton("givehparmor", Rect(250, 40, 125, 25), "Fill HP & Armor", Color(255, 255, 255, 255), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 255, 0, 175), -1, MainTab, "tab"));

	//WEAPONS TAB
	GID NoReload_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 10, 0, 0), "Fast Reload", "fastreload", Features::SuperReload = MyYAML::GetValueFromNode<bool>("Weapons", "Fast_Reload"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), WeaponsTab, "tab"));
	GID SuperImpulse_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 30, 0, 0), "Super Impulse", "superimpulse", Features::SuperImpulse = MyYAML::GetValueFromNode<bool>("Weapons", "Super_Impulse"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), WeaponsTab, "tab"));
	GID UltraPenetration_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 50, 0, 0), "Ultra Penetration", "ultrapenetration", Features::UltraPenetration = MyYAML::GetValueFromNode<bool>("Weapons", "Ultra_Penetration"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), WeaponsTab, "tab"));
	GID InstantKill_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 70, 0, 0), "No Spread", "nospread", Features::NoSpread = MyYAML::GetValueFromNode<bool>("Weapons", "No_Spread"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), WeaponsTab, "tab"));
	GID NoRecoil_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 90, 0, 0), "No Recoil", "norecoil", Features::NoRecoil = MyYAML::GetValueFromNode<bool>("Weapons", "No_Recoil"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), WeaponsTab, "tab"));

	GID AimingFOV_PB = GUIElements::GUICreateProgressBar(new CProgressBar("aimingfov", Rect(175, 20, 175, 5), "Aiming FOV: %.0f", Features::fAimingFOV = MyYAML::GetValueFromNode<float>("Weapons", "Aiming_FOV"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), WeaponsTab, "tab"));

	CDropMenuElements* WeaponsAvailable = new CDropMenuElements("WeaponList");
	WeaponsAvailable->InsertItem("Baseball Bat", WEAPON_BAT);
	WeaponsAvailable->InsertItem("Little Knife", WEAPON_KNIFE);
	WeaponsAvailable->InsertItem("Nightstick", WEAPON_NIGHTSTICK);
	WeaponsAvailable->InsertItem("Crowbar", WEAPON_CROWBAR);
	WeaponsAvailable->InsertItem("Golf Stick", WEAPON_GOLFCLUB);
	WeaponsAvailable->InsertItem("Bottle", WEAPON_BOTTLE);
	WeaponsAvailable->InsertItem("Dagger", WEAPON_DAGGER);
	WeaponsAvailable->InsertItem("Hatchet", WEAPON_HATCHET);
	WeaponsAvailable->InsertItem("Knuckledusters", WEAPON_KNUCKLE);
	WeaponsAvailable->InsertItem("Machete", WEAPON_MACHETE);
	WeaponsAvailable->InsertItem("Hammer", WEAPON_HAMMER);
	WeaponsAvailable->InsertItem("Flashlight", WEAPON_FLASHLIGHT);
	WeaponsAvailable->InsertItem("Switchblade", WEAPON_SWITCHBLADE);
	WeaponsAvailable->InsertItem("Pistol", WEAPON_PISTOL);
	WeaponsAvailable->InsertItem("Combat Pistol", WEAPON_COMBATPISTOL);
	WeaponsAvailable->InsertItem("AP Pistol", WEAPON_APPISTOL);
	WeaponsAvailable->InsertItem("Tazer", WEAPON_STUNGUN);
	WeaponsAvailable->InsertItem("Deagle", WEAPON_PISTOL50);
	WeaponsAvailable->InsertItem("SNS Pistol", WEAPON_SNSPISTOL);
	WeaponsAvailable->InsertItem("Heavy Pistol", WEAPON_HEAVYPISTOL);
	WeaponsAvailable->InsertItem("Vintage Pistol", WEAPON_VINTAGEPISTOL);
	WeaponsAvailable->InsertItem("Flare Gun", WEAPON_FLAREGUN);
	WeaponsAvailable->InsertItem("Marksman Pistol", WEAPON_MARKSMANPISTOL);
	WeaponsAvailable->InsertItem("Revolver", WEAPON_REVOLVER);
	WeaponsAvailable->InsertItem("Micro SMG", WEAPON_MICROSMG);
	WeaponsAvailable->InsertItem("SMG", WEAPON_SMG);
	WeaponsAvailable->InsertItem("Assault SMG", WEAPON_ASSAULTSMG);
	WeaponsAvailable->InsertItem("PDW", WEAPON_COMBATPDW);
	WeaponsAvailable->InsertItem("TEC-9", WEAPON_TEC9);
	WeaponsAvailable->InsertItem("Pump Shotgun", WEAPON_PUMPSHOTGUN);
	WeaponsAvailable->InsertItem("Sawed-Off", WEAPON_SAWNOFFSHOTGUN);
	WeaponsAvailable->InsertItem("Assault Shotgun", WEAPON_ASSAULTSHOTGUN);
	WeaponsAvailable->InsertItem("Bullpup Shotgun", WEAPON_BULLPUPSHOTGUN);
	WeaponsAvailable->InsertItem("Musket", WEAPON_MUSKET);
	WeaponsAvailable->InsertItem("Heavy Shotgun", WEAPON_HEAVYSHOTGUN);
	WeaponsAvailable->InsertItem("Double Barreled", WEAPON_DOUBLEBARRELED);
	WeaponsAvailable->InsertItem("Assault Rifle", WEAPON_ASSAULTRIFLE);
	WeaponsAvailable->InsertItem("Carbine Rifle", WEAPON_CARBINERIFLE);
	WeaponsAvailable->InsertItem("Advanced Rifle", WEAPON_ADVANCEDRIFLE);
	WeaponsAvailable->InsertItem("Special Carbine", WEAPON_SPECIALCARBINE);
	WeaponsAvailable->InsertItem("Bullpup Rifle", WEAPON_BULLPUPRIFLE);
	WeaponsAvailable->InsertItem("Compact Rifle", WEAPON_COMPACTRIFLE);
	WeaponsAvailable->InsertItem("Shrewsbury MG", WEAPON_MG);
	WeaponsAvailable->InsertItem("Combat MG", WEAPON_COMBATMG);
	WeaponsAvailable->InsertItem("Gusenberg", WEAPON_GUSENBERG);
	WeaponsAvailable->InsertItem("Sniper Rifle", WEAPON_SNIPERRIFLE);
	WeaponsAvailable->InsertItem("Heavy Sniper", WEAPON_HEAVYSNIPER);
	WeaponsAvailable->InsertItem("Marksman Rifle", WEAPON_MARKSMANRIFLE);
	WeaponsAvailable->InsertItem("RPG", WEAPON_RPG);
	WeaponsAvailable->InsertItem("Grenade Launcher", WEAPON_GRENADELAUNCHER);
	WeaponsAvailable->InsertItem("Minigun", WEAPON_MINIGUN);
	WeaponsAvailable->InsertItem("Firework Launcher", WEAPON_FIREWORK);
	WeaponsAvailable->InsertItem("Railgun", WEAPON_RAILGUN);
	WeaponsAvailable->InsertItem("Heat RPG", WEAPON_HOMINGLAUNCHER);
	WeaponsAvailable->InsertItem("Grenade", WEAPON_GRENADE);
	WeaponsAvailable->InsertItem("Tear Gas", WEAPON_SMOKEGRENADE);
	WeaponsAvailable->InsertItem("Molotov", WEAPON_MOLOTOV);
	WeaponsAvailable->InsertItem("Sticky Bomb", WEAPON_STICKYBOMB);
	WeaponsAvailable->InsertItem("Mine", WEAPON_PROXMINE);
	WeaponsAvailable->InsertItem("Snowballs", WEAPON_SNOWBALL);
	WeaponsAvailable->InsertItem("Petrol Can", WEAPON_PETROLCAN);
	WeaponsAvailable->InsertItem("Dog Ball", WEAPON_BALL);
	WeaponsAvailable->InsertItem("Fire Extinguisher", WEAPON_FIREEXTINGUISHER);
	WeaponsAvailable->InsertItem("Parachute", WEAPON_PARACHUTE);
	WeaponsAvailable->InsertItem("Briefcase", WEAPON_BRIEFCASE);
	WeaponsAvailable->InsertItem("Garbage Bag", WEAPON_GARBAGEBAG);
	WeaponsAvailable->InsertItem("Handcuffs", WEAPON_HANDCUFFS);

	GID GiveWeapon_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(10, 160, 40, 0), "weaponsdm", "Weapons", WeaponsAvailable, Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), WeaponsTab, "tab", "All Weapons"));

	CDropMenuElements* PlayersOnline = new CDropMenuElements("Players Online");
	PlayersOnline->InsertItem("Me");

	GID Players_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(155, 160, 40, 0), "playersweaponsdm", "Players Online", PlayersOnline, Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), WeaponsTab, "tab", "Players List"));

	GID GiveWeapon_BTN = GUIElements::GUICreateButton(new CButton("GiveWeaponBTN", Rect(345, 160, 50, 30), "Give", Color(255, 255, 255, 255), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 255, 0, 175), GiveWeapon_DM, WeaponsTab, "tab"));
	GID GiveAllWeapon_BTN = GUIElements::GUICreateButton(new CButton("GiveAllWeaponBTN", Rect(340, 200, 60, 30), "Give All", Color(255, 255, 255, 255), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 255, 0, 175), -1, WeaponsTab, "tab"));

	//TELEPORT TAB
	CDropMenuElements* TeleportBookMark = new CDropMenuElements("Teleports Places");
	TeleportBookMark->InsertItem("Michael's Home");
	TeleportBookMark->InsertItem("Trevor's Home");
	TeleportBookMark->InsertItem("Franklin's Home");
	TeleportBookMark->InsertItem("Airport");
	TeleportBookMark->InsertItem("FIB Building");
	TeleportBookMark->InsertItem("IAA Office");
	TeleportBookMark->InsertItem("Mount Chiliad");
	TeleportBookMark->InsertItem("Bank Tower");

	for (GID i = 0; i < MyYAML::GetNodeSize("Teleport_Bookmark"); i++)
	{
	std::string TeleportIndexName = "Teleport_" + std::to_string(i + 1);

	std::string TeleportName = MyYAML::GetValueFromArrayNode<std::string>("Teleport_Bookmark", TeleportIndexName, 3);

	Vector3 TeleportPosition = Vector3(MyYAML::GetValueFromArrayNode<float>("Teleport_Bookmark", TeleportIndexName, 0),
	MyYAML::GetValueFromArrayNode<float>("Teleport_Bookmark", TeleportIndexName, 1),
	MyYAML::GetValueFromArrayNode<float>("Teleport_Bookmark", TeleportIndexName, 2));

	TeleportBookMark->InsertItem(TeleportName, TeleportPosition, TRUE);
	}

	GID TeleportBookmark_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(10, 40, 0, 0), "teleportdm", "Teleport Bookmark", TeleportBookMark, Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), TeleportTab, "tab", "Default Locations"));
	GID PlayersTeleportList_DM = GUIElements::GUICreateDropMenu(new CDropMenu(Rect(195, 40, 0, 0), "tptoplaya", "Teleport To Player", PlayersOnline, Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 100, 255, 150), TeleportTab, "tab", "Players List"));

	GID ButtonTeleportToPlayer_BTN = GUIElements::GUICreateButton(new CButton("TPPlayerButton", Rect(380, 40, 50, 30), "GO!", Color(255, 255, 255, 255), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 255, 0, 175), PlayersTeleportList_DM, TeleportTab, "tab"));
	GID Waypoint_BTN = GUIElements::GUICreateButton(new CButton("waypointtp", Rect(10, 200, 75, 30), "Waypoint", Color(255, 255, 255, 255), Color(255, 255, 255, 255), Color(0, 0, 0, 0), Color(0, 255, 0, 175), -1, TeleportTab, "tab"));

	//ESP TAB
	GID Enable_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 10, 0, 0), "Enable", "enableesp", Features::ESP = MyYAML::GetValueFromNode<bool>("ESP", "Enable"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), ESPTab, "tab"));
	GID Boxes3D_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 30, 0, 0), "3D Boxes", "3dboxes", Features::Boxes3D = MyYAML::GetValueFromNode<bool>("ESP", "Boxes3D"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), ESPTab, "tab"));
	GID ShowPeds_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 50, 0, 0), "Show Peds", "showpeds", Features::ShowPeds = MyYAML::GetValueFromNode<bool>("ESP", "Show_Peds"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), ESPTab, "tab"));
	GID ShowPlayers_CB = GUIElements::GUICreateCheckBox(new CCheckBox(Rect(10, 70, 0, 0), "Show Players", "showplayers", Features::ShowPlayers = MyYAML::GetValueFromNode<bool>("ESP", "Show_Players"), Color(255, 255, 255, 255), Color(255, 0, 0, 255), Color(0, 0, 0, 0), ESPTab, "tab"));

	GID ESPDistance_PB = GUIElements::GUICreateProgressBar(new CProgressBar("espdistance", Rect(150, 20, 175, 5), "ESP Max Distance: %.0f", Features::fESPMaxDistance = MyYAML::GetValueFromNode<float>("ESP", "ESP_Max_Distance"), Color(0, 255, 0, 255), Color(100, 100, 100, 175), ESPTab, "tab"));

	Initialized = TRUE;
	}*/
}

GID GUIElements::GUICreateWindow(CWindow* data)
{
	GUIWindows[TWindows] = data;
	TWindows++;
	return TWindows - 1;
}

GID GUIElements::GUICreateCheckBox(CCheckBox* data)
{
	GUICheckBoxes[TCheckboxes] = data;
	TCheckboxes++;
	return TCheckboxes - 1;
}

GID GUIElements::GUICreateTab(CTab* data)
{
	std::wstring text = DX11->ConvertToWStr(data->text);
	XMVECTOR size = DX11->DX11Purista->MeasureString(text.c_str());
	data->SizeX = (XMVectorGetX(size) / 2) + 10;

	GUITabs[TTabs] = data;

	if (data->parent != -1)
	{
		if (data->parentType == "window")
		{
			GUIWindows[data->parent]->Tabs[data->windowTabID] = TTabs;
		}
	}
	TTabs++;
	return TTabs - 1;
}

GID GUIElements::GUICreateProgressBar(CProgressBar* data)
{
	XMVECTOR size = DX11->DX11Purista->MeasureString(DX11->ConvertToWStr(data->p_text).c_str());
	data->TextSize = (XMVectorGetX(size) / 2) + 10;

	GUIProgressBars[TProgressBars] = data;
	TProgressBars++;
	return TProgressBars - 1;
}

GID GUIElements::GUICreateLabel(CLabel* data)
{
	GUILabels[TLabels] = data;
	TLabels++;
	return TLabels - 1;
}

GID GUIElements::GUICreateDropMenu(CDropMenu* data)
{
	XMVECTOR size = DX11->DX11Purista->MeasureString(DX11->ConvertToWStr(data->text).c_str());
	data->TextSize = (XMVectorGetX(size) / 2) + 10;
	data->TextSizeY = (XMVectorGetY(size) / 2) + 10;

	GUIDropMenus[TDropMenus] = data;

	TDropMenus++;
	return TDropMenus - 1;
}

GID GUIElements::GUICreateButton(CButton* data)
{
	GUIButtons[TButtons] = data;
	TButtons++;
	return TButtons - 1;
}

std::string CGUI::StrVars(const char* _text, ...)
{
	std::string NewTextCall;
	char TempBuff[512] = { '\0' };
	va_list VAL;
	va_start(VAL, _text);
	vsprintf_s(TempBuff, _text, VAL);
	va_end(VAL);

	NewTextCall = TempBuff;

	return NewTextCall;
}

void CGUI::SaveInClipBoard(const std::string &s)
{
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg)
	{
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

CCheckBox* CGUI::GetCheckboxFromName(const char* _Name)
{
	for (GID i = 0; i < TCheckboxes; i++)
	{
		if (GUICheckBoxes[i]->Name == _Name) return GUICheckBoxes[i];
	}
	return nullptr;
}

CDropMenu* CGUI::GetDropMenuFromName(const char* _Name)
{
	for (GID i = 0; i < TDropMenus; i++)
	{
		if (GUIDropMenus[i]->Name == _Name) return GUIDropMenus[i];
	}
	return nullptr;
}

/*CProgressBar* CGUI::GetProgressBarFromName(const char* _Name)
{
for (GID i = 0; i < TProgressBars; i++)
{
if (GUIProgressBars[i]->Name == _Name) return GUIProgressBars[i];
}
return nullptr;
}*/


//GUI FUNCTIONALITY
//GUI FUNCTIONALITY
float co = 0.03f;

void CGUI::RefreshCursor()
{
	POINT Pos;
	GetCursorPos(&Pos);
	CursorPos = SimpleMath::Vector2(Pos.x - DX11->ScreenX, Pos.y - DX11->ScreenY);

	if (GetAsyncKeyState(VK_F6))
	{
		co += 0.0001f;
	}
	if (GetAsyncKeyState(VK_F5))
	{
		co -= 0.0001f;
	}

	//CUSTOM REFRESH CODE
	//CUSTOM REFRESH CODE
	if (CurrentTick - LastTick > 60000) //player weapon list refreshed each 60 seconds
	{
		CDropMenu* PlayerListForWeapons = GetDropMenuFromName("Players Online");
		CDropMenu* PlayerListForTP = GetDropMenuFromName("Teleport To Player");
		PlayerListForWeapons->DeleteAllItems();
		PlayerListForTP->DeleteAllItems();

		for (GID i = 0; i < 0x1E; i++)
		{
			CPed* Player = (CPed*)Game::GetPlayerByIndex(i);
			if (Mem::IsValid(Player))
			{
				if (Player->Health >= 50)
				{
					if (Mem::IsValid(Player->PlayerInfo))
						PlayerListForWeapons->ItemsInside->InsertItem(Player->PlayerInfo->PlayerName);
				}
			}
		}
		for (GID i = 0; i < 0x1E; i++)
		{
			CPed* Player = (CPed*)Game::GetPlayerByIndex(i);
			if (Mem::IsValid(Player))
			{
				if (Player->Health >= 50)
				{
					if (Mem::IsValid(Player->PlayerInfo))
						PlayerListForTP->ItemsInside->InsertItem(Player->PlayerInfo->PlayerName);
				}
			}
		}

		LastTick = GetTickCount();
	}

	//CUSTOM REFRESH CODE
	//CUSTOM REFRESH CODE

	if (!GetAsyncKeyState(VK_LBUTTON) && MouseLeftPressed) MouseLeftPressed = false;

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		//PROGRESS BAR FUNCTION

		for (GID _pb = 0; _pb < TProgressBars; _pb++)
		{
			CProgressBar* bar = GUIProgressBars[_pb];
			Rect r = bar->EventRect;
			Rect r2 = bar->rect;
			float Limit = bar->LimitLeft;
			if (IsCursorHover(Rect(Limit - 10, r.y - 15, r2.sx + 20, r2.sy + 35), bar->Active))
			{
				bar->Progress = CursorPos.x - 2.5f;
				if (bar->Progress < Limit) bar->Progress = Limit;
				if (bar->Progress > Limit + r2.sx - 5) bar->Progress = Limit + r2.sx - 5;

				OnProgressBarMove(_pb);

				GUI.ElementSelected = 1;
				break;
			}
		}

		if (GUI.ElementSelected == -1)  //AVOID MOVING WINDOWS WHEN CLICKING BUTTONS ETC
		{
			//WINDOWS MOVING FUNCTIONS
			for (GID _wi = 0; _wi < TWindows; _wi++)
			{
				if (IsCursorHover(GUIWindows[_wi]->rect, true))
				{
					if (!MouseLeftPressed)
					{
						MouseLeftPressed = true;
						LatestCursorPos = CursorPos - SimpleMath::Vector2(GUIWindows[_wi]->rect.x, GUIWindows[_wi]->rect.y);
					}
					GUIWindows[_wi]->rect.x = CursorPos.x - LatestCursorPos.x;
					GUIWindows[_wi]->rect.y = CursorPos.y - LatestCursorPos.y;
					break;
				}
			}
		}
	}
	else
	{
		//CURSORHOVER CHECKS COLOR ETC
		for (GID _dd = 0; _dd < TDropMenus; _dd++)
		{
			CDropMenu* DM = GUIDropMenus[_dd];

			if (IsCursorHover(DM->EventRect, DM->IsActive)) DM->BoxColor = DM->HighlightColor;
			else DM->BoxColor = DM->DefaultBoxColor;

			if (DM->IsOpened)
			{
				for (GID i = DM->RollPage; i < DM->RollPage + 4; i++)
				{
					if (i < DM->ItemsInside->Items)
					{
						GID ItemID = (i + 1) - DM->RollPage;
						Rect ItemPos = DM->EventRect + Rect(0, ItemID * DM->EventRect.sy, 0, 0);
						if (IsCursorHover(ItemPos, DM->IsActive))
						{
							DM->ItemSelected = CDropMenu::ItemInfo(DM->ItemsInside->text[i], i - DM->RollPage);
							break;
						}
						else
						{
							if (DM->ItemSelected.ID != -1) DM->ItemSelected = CDropMenu::ItemInfo("", -1);
						}
					}
				}
			}
		}

		for (GID _ta = 0; _ta < TTabs; _ta++)
		{
			CTab* Tab = GUITabs[_ta];

			if (IsCursorHover(Tab->EventRect, true)) Tab->BoxColor = Color(0, 255, 255, 170);
			else Tab->BoxColor = Tab->DefaultBoxColor;
		}

		for (GID _btn = 0; _btn < TButtons; _btn++)
		{
			CButton* Button = GUIButtons[_btn];

			if (IsCursorHover(Button->EventRect, Button->IsActive)) Button->BoxColor = Button->HighlightColor;
			else
			{
				Button->BoxColor = Button->DefaultBoxColor;

				if (Button->IsClicked)  //if cursor is out but the button is up then this will help to reset it
				{
					Button->rect.x -= 2.f;
					Button->rect.y -= 2.f;
					Button->rect.sx += 4.f;
					Button->rect.sy += 4.f;

					GUI.ElementSelected = -1;

					Button->IsClicked = FALSE;
				}
			}
		}
	}
	CurrentTick = GetTickCount();
}

bool CGUI::IsCursorHover(Rect rect, bool IsElementActive)
{
	if (CursorPos.x >= rect.x && CursorPos.x <= rect.x + rect.sx &&
		CursorPos.y >= rect.y && CursorPos.y <= rect.y + rect.sy && IsElementActive)
	{
		return true;
	}
	return false;
}

void CGUI::OnLeftMouseButtonDown()
{
	if (!Features::MenuOpened) return;

	GUI.ElementSelected = -1;

	if (OnClick()) GUI.ElementSelected = 1;

	BOOLEAN EfficientCheck = FALSE;

	for (GID i = 0; i < TButtons; i++)
	{
		CButton* Button = GUIButtons[i];

		if (IsCursorHover(Button->EventRect, Button->IsActive))
		{
			ButtonEvents(Button);
			EfficientCheck = TRUE;

			break;
		}
	}
	if (!EfficientCheck)
	{
		for (GID i = 0; i < TDropMenus; i++) //drop down items selection
		{
			CDropMenu* DM = GUIDropMenus[i];
			if (IsCursorHover(DM->EventRect, DM->IsActive))
			{
				if (DM->IsOpened) DM->IsClosing = true;
				else DM->IsOpening = true;

				EfficientCheck = TRUE;

				break;
			}
			if (DM->IsOpened && !EfficientCheck)
			{
				for (GID i = DM->RollPage; i < DM->RollPage + 4; i++)
				{
					if (i < DM->ItemsInside->Items)
					{
						Rect ItemPos = DM->EventRect + Rect(0, ((i + 1) - DM->RollPage) * DM->EventRect.sy, 0, 0);
						if (IsCursorHover(ItemPos, DM->IsActive))
						{
							OnDropMenuItemClick(DM, i);
							EfficientCheck = TRUE;
							DM->IsClosing = true;

							break;
						}
					}
				}
			}
		}
		for (GID i = 0; i < TCheckboxes; i++)
		{
			CCheckBox* Checkbox = GUICheckBoxes[i];
			if (IsCursorHover(Checkbox->EventRect, Checkbox->IsActive))
			{
				CheckboxEvents(Checkbox);
				EfficientCheck = TRUE;

				break;
			}
		}
	}
	if (EfficientCheck) GUI.ElementSelected = 1;
}

void CGUI::OnLeftMouseButtonUp()
{
	if (!Features::MenuOpened) return;

	if (GUI.ElementSelected >= 0)
	{
		for (GID i = 0; i < TButtons; i++)
		{
			CButton* Button = GUIButtons[i];

			if (IsCursorHover(Rect(Button->EventRect.x, Button->EventRect.y, Button->EventRect.sx, Button->EventRect.sy), Button->IsActive))
			{
				Button->rect.x -= 2.f;
				Button->rect.y -= 2.f;
				Button->rect.sx += 4.f;
				Button->rect.sy += 4.f;

				Button->IsClicked = FALSE;
			}
		}
		GUI.ElementSelected = -1;
	}
}

void CGUI::OnProgressBarMove(GID ProgressBar)
{
	if (!Features::MenuOpened) return;

	CProgressBar* bar = GUIProgressBars[ProgressBar];
	if (bar->Name == "rpmultiplier")
	{
		float Value = 1.f + ((bar->Progress - bar->LimitLeft) * 0.005115f);
		if (Value >= 1.f && Value <= 2.f)
		{
			Features::fRPMultiplier = Value;
			bar->p_text = GUI.StrVars("RP Multiplier: %.2f", Value);
		}
	}
	else if (bar->Name == "damagemod")
	{
		float Value = 0.72f + ((bar->Progress - bar->LimitLeft) * 0.047583f);
		Features::fDamageMod = Value;
		bar->p_text = GUI.StrVars("Damage Mod: %.2f", Features::fDamageMod);
	}
	else if (bar->Name == "vehimpulse")
	{
		float Value = -100.f + ((bar->Progress - bar->LimitLeft) * 1.176498f);
		Features::fVehImpulse = Value;
		bar->p_text = GUI.StrVars("Vehicle Impulse: %.2f", Features::fVehImpulse);
	}
	else if (bar->Name == "meleedamage")
	{
		float Value = 1.f + ((bar->Progress - bar->LimitLeft) * 5.876474);
		Features::fMeleeDamage = Value;
		bar->p_text = GUI.StrVars("Melee Damage: %.2f", Features::fMeleeDamage);
	}
	else if (bar->Name == "menured") //MENU COLORS
	{
		int Value = (bar->Progress - bar->LimitLeft) * 1.761026f;
		GUIWindows[0]->color.R(Value);
		bar->p_text = GUI.StrVars("Menu Red: %i", Value);
	}
	else if (bar->Name == "menugreen") //MENU COLORS
	{
		int Value = (bar->Progress - bar->LimitLeft) * 1.761026f;
		GUIWindows[0]->color.G(Value);
		bar->p_text = GUI.StrVars("Menu Green: %i", Value);
	}
	else if (bar->Name == "menublue") //MENU COLORS
	{
		int Value = (bar->Progress - bar->LimitLeft) * 1.761026f;
		GUIWindows[0]->color.B(Value);
		bar->p_text = GUI.StrVars("Menu Blue: %i", Value);
	}
	else if (bar->Name == "menualpha") //MENU COLORS
	{
		int Value = (bar->Progress - bar->LimitLeft) * 1.761026f;
		GUIWindows[0]->color.A(Value);
		bar->p_text = GUI.StrVars("Menu Alpha: %i", Value);
	}
	else if (bar->Name == "vehiclegravity")
	{
		float Value = -20.f + (bar->Progress - bar->LimitLeft) * 0.235403f;
		Features::fVehGravity = Value;
		bar->p_text = GUI.StrVars("Vehicle Gravity: %.1f", Value);
	}
	else if (bar->Name == "aimingfov")
	{
		float Value = 10.f + (bar->Progress - bar->LimitLeft) * 0.235903f;
		Features::fAimingFOV = Value;
		bar->p_text = GUI.StrVars("Aiming FOV: %.0f", Value);
	}
	else if (bar->Name == "pedamount")
	{
		float Value = (bar->Progress - bar->LimitLeft) * 0.00589f;
		LocalPlayer::SetPedAmount(Value);
		bar->p_text = GUI.StrVars("Ped Amount: %.2f", Value);
	}
	else if (bar->Name == "vehicleamount")
	{
		float Value = (bar->Progress - bar->LimitLeft) * 0.00589f;
		LocalPlayer::SetVehicleAmount(Value);
		bar->p_text = GUI.StrVars("Vehicle Amount: %.2f", Value);
	}
	else if (bar->Name == "espdistance")
	{
		float Value = (bar->Progress - bar->LimitLeft) * 11.765175f;
		Features::fESPMaxDistance = Value;
		bar->p_text = GUI.StrVars("ESP Max Distance: %.0f", Value);
	}
	else if (bar->Name == "vehdeformation")
	{
		float Value = (bar->Progress - bar->LimitLeft) * 0.589301f;
		Features::fDeformation = Value;
		bar->p_text = GUI.StrVars("Vehicle Deformation: %.1f", Value);
	}
	else if (bar->Name == "survivalcash")
	{
		float Value = 1.f + (bar->Progress - bar->LimitLeft) * 0.0235f;
		if (Value >= 1.f && Value <= 5.5f)
		{
			//Features::fSurvivalCash = Value;
			bar->p_text = GUI.StrVars("Coming Soon", Value);
		}
	}

}

void CGUI::OnDropMenuItemClick(CDropMenu* DropMenu, GID index)
{
	if (!Features::MenuOpened) return;

	DropMenu->MainItem = DropMenu->ItemSelected;
	DropMenu->MainItem.ID = index;
	DropMenu->MainItem.bUsingStrText = DropMenu->ItemsInside->UsingStrText[index];
	if (DropMenu->MainItem.bUsingStrText)
		DropMenu->MainItem.Name = DropMenu->ItemsInside->strText[index].c_str();


	if (DropMenu->Name == "Teleport Bookmark")
	{
		if (DropMenu->MainItem.Name == "Michael's Home")
			LocalPlayer::Teleport(SimpleMath::Vector3(-812.084656, 179.722183, 72.15923));
		else if (DropMenu->MainItem.Name == "Trevor's Home")
			LocalPlayer::Teleport(SimpleMath::Vector3(1981.892822, 3816.623779, 32.30817));
		else if (DropMenu->MainItem.Name == "Franklin's Home")
			LocalPlayer::Teleport(SimpleMath::Vector3(6.047129, 533.308960, 175.34393));
		else if (DropMenu->MainItem.Name == "Airport")
			LocalPlayer::Teleport(SimpleMath::Vector3(-1148.327271, -2883.376709, 13.94442));
		else if (DropMenu->MainItem.Name == "FIB Building")
			LocalPlayer::Teleport(SimpleMath::Vector3(135.947464, -749.110535, 258.15167));
		else if (DropMenu->MainItem.Name == "IAA Office")
			LocalPlayer::Teleport(SimpleMath::Vector3(113.713234, -619.143066, 206.04679));
		else if (DropMenu->MainItem.Name == "Mount Chiliad")
			LocalPlayer::Teleport(SimpleMath::Vector3(446.700073, 5572.014160, 781.18939));
		else if (DropMenu->MainItem.Name == "Bank Tower")
			LocalPlayer::Teleport(SimpleMath::Vector3(-75.030563, -819.588928, 326.17517));
		else
		{
			if (DropMenu->ItemsInside->VarType == "Vector3") //CUSTOM TELEPORTS
				LocalPlayer::Teleport(DropMenu->GetItemDataFromName<SimpleMath::Vector3>(DropMenu->MainItem.Name));
		}
	}
}

void CGUI::OnWheelMove(short Dir)
{
	if (!Features::MenuOpened) return;

	for (GID i = 0; i < TDropMenus; i++)
	{
		CDropMenu* DM = GUIDropMenus[i];

		if (DM->IsOpened && IsCursorHover(Rect(DM->EventRect.x, DM->EventRect.y, DM->EventRect.sx, DM->EventRect.sy + (DM->ItemsInside->Items * DM->TextSizeY)), DM->IsActive))
		{
			if (DM->RollPage > 0 && Dir == 0) DM->RollPage--;
			else if (DM->RollPage + 4 < DM->ItemsInside->Items && Dir == -1) DM->RollPage++;
		}
	}
}

void CGUI::ButtonEvents(CButton* btn)
{
	btn->rect.x += 2.f;
	btn->rect.y += 2.f;
	btn->rect.sx -= 4.f;
	btn->rect.sy -= 4.f;	//THIS SHOULD BE CHANGED WITH FASTER OPERATIONS AND FIX RECT STRUCT

	if (btn->LinkedDropMenu == -1) //NORMAL BUTTONS
	{
		if (btn->Name == "givehparmor")
		{
			LocalPlayer::GiveHealthArmor();
		}
		else if (btn->Name == "GiveAllWeaponBTN")
		{
			const char* szPlayerName = GetDropMenuFromName("Players Online")->ItemSelected.Name;
			if (szPlayerName != "Players Online")
			{
				Game::Ped Player = LocalPlayer::GetPlayerPedFromName(szPlayerName);
				if (Player) Game::GiveWeaponsToPlayer(Player);
				else		GUIDropMenus[btn->LinkedDropMenu]->MainItem = CDropMenu::ItemInfo("Players Online", -1);
			}
		}
		else if (btn->Name == "waypointtp")
		{
			if (Game::GetWaypointPosition().Length() > 211)
				LocalPlayer::Teleport(Game::GetWaypointPosition());
		}
	}
	else	//buttons with dropdownmenu linked
	{
		CDropMenu* ButtonDropMenu = GUIDropMenus[btn->LinkedDropMenu];
		if (btn->Name == "TPPlayerButton")
		{
			const char* szPlayerName = GetDropMenuFromName("Teleport To Player")->MainItem.Name;
			if (szPlayerName != "Teleport To Player")
			{
				CPed* Player = LocalPlayer::GetPlayerPTRFromName(szPlayerName);
				if (Mem::IsValid(Player)) LocalPlayer::Teleport(Player->VisualPosition + SimpleMath::Vector3(1, 1, 0));
				else					  ButtonDropMenu->MainItem = CDropMenu::ItemInfo("Teleport To Player", -1);
			}
		}
		else if (btn->Name == "GiveWeaponBTN")
		{
			Game::Hash Weapon;

			if (ButtonDropMenu->IsUsingDataAndRead(Weapon))
			{
				const char* szPlayerName = GetDropMenuFromName("Players Online")->MainItem.Name;
				if (szPlayerName != "Players Online")
				{
					Game::Ped Player = LocalPlayer::GetPlayerPedFromName(szPlayerName);
					if (Player) Game::GiveWeaponsToPlayer(Player, Weapon);
					else		ButtonDropMenu->MainItem = CDropMenu::ItemInfo("Players Online", -1);
				}
			}
		}
	}

	btn->IsClicked = TRUE;
	GUI.ElementSelected = 1;
}

void CGUI::CheckboxEvents(CCheckBox* checkbox)
{
	if (checkbox->Name == "full_godmode")
	{
		checkbox->ToggleWithValue(Features::IsFullGodMode);
		GetCheckboxFromName("asm_godmode")->DisableWithValue(Features::IsGodMode);
	}
	else if (checkbox->Name == "asm_godmode")
	{
		//checkbox->ToggleWithValue(Features::IsGodMode);
		//GetCheckboxFromName("full_godmode")->DisableWithValue(Features::IsFullGodMode);
		//LocalPlayer::ToggleASMGodMode(); //EDIT THIS IF U HAVE A FUNCTION HOOK LIBRARY
	}
	else if (checkbox->Name == "fallfromvehicle")
	{
		checkbox->ToggleWithValue(Features::FallFromVehicle);
	}
	else if (checkbox->Name == "invisibleplayer")
	{
		checkbox->ToggleWithValue(Features::InvisiblePlayer);
		//Game::SetEntityVisible(Game::GetPlayerPed(Game::GetPlayerID()), !Features::InvisiblePlayer, TRUE);
	}
	else if (checkbox->Name == "invisiblevehicle")
	{
		checkbox->ToggleWithValue(Features::InvisibleVehicle);
		Game::SetEntityVisible(Game::GetVehiclePedIsIn(Game::GetPlayerPed(Game::GetPlayerID()), TRUE), !Features::InvisibleVehicle, TRUE);
	}
	else if (checkbox->Name == "fastswimetc")
	{
		checkbox->ToggleWithValue(Features::FastSwimSprint);
		LocalPlayer::ToogleSwimSprintVel();
	}
	else if (checkbox->Name == "neverwanted")
	{
		checkbox->ToggleWithValue(Features::NeverWanted);
		GetCheckboxFromName("alwayswanted")->DisableWithValue(Features::AlwaysWanted);
	}
	else if (checkbox->Name == "alwayswanted")
	{
		checkbox->ToggleWithValue(Features::AlwaysWanted);
		GetCheckboxFromName("neverwanted")->DisableWithValue(Features::NeverWanted);
	}
	else if (checkbox->Name == "superjump")
	{
		checkbox->ToggleWithValue(Features::SuperJump);
		GetCheckboxFromName("explosivemelee")->DisableWithValue(Features::ExplosiveMelee);
		GetCheckboxFromName("fireammo")->DisableWithValue(Features::FireAmmo);
		GetCheckboxFromName("explosiveammo")->DisableWithValue(Features::ExplosiveAmmo);
	}
	else if (checkbox->Name == "explosivemelee")
	{
		checkbox->ToggleWithValue(Features::ExplosiveMelee);
		GetCheckboxFromName("superjump")->DisableWithValue(Features::SuperJump);
		GetCheckboxFromName("fireammo")->DisableWithValue(Features::FireAmmo);
		GetCheckboxFromName("explosiveammo")->DisableWithValue(Features::ExplosiveAmmo);
	}
	else if (checkbox->Name == "fireammo")
	{
		checkbox->ToggleWithValue(Features::FireAmmo);
		GetCheckboxFromName("superjump")->DisableWithValue(Features::SuperJump);
		GetCheckboxFromName("explosivemelee")->DisableWithValue(Features::ExplosiveMelee);
		GetCheckboxFromName("explosiveammo")->DisableWithValue(Features::ExplosiveAmmo);
	}
	else if (checkbox->Name == "explosiveammo")
	{
		checkbox->ToggleWithValue(Features::ExplosiveAmmo);
		GetCheckboxFromName("superjump")->DisableWithValue(Features::SuperJump);
		GetCheckboxFromName("explosivemelee")->DisableWithValue(Features::ExplosiveMelee);
		GetCheckboxFromName("fireammo")->DisableWithValue(Features::FireAmmo);
	}
	else if (checkbox->Name == "fastreload")
	{
		checkbox->ToggleWithValue(Features::SuperReload);
	}
	else if (checkbox->Name == "superimpulse")
	{
		checkbox->ToggleWithValue(Features::SuperImpulse);
	}
	else if (checkbox->Name == "ultrapenetration")
	{
		checkbox->ToggleWithValue(Features::UltraPenetration);
	}
	else if (checkbox->Name == "norecoil")
	{
		checkbox->ToggleWithValue(Features::NoRecoil);
	}
	else if (checkbox->Name == "nospread")
	{
		checkbox->ToggleWithValue(Features::NoSpread);
	}
	else if (checkbox->Name == "enableesp")
	{
		checkbox->ToggleWithValue(Features::ESP);
	}
	else if (checkbox->Name == "3dboxes")
	{
		checkbox->ToggleWithValue(Features::Boxes3D);
	}
	else if (checkbox->Name == "showpeds")
	{
		checkbox->ToggleWithValue(Features::ShowPeds);
	}
	else if (checkbox->Name == "showplayers")
	{
		checkbox->ToggleWithValue(Features::ShowPlayers);
	}


	GUI.ElementSelected = 1;
}

bool CGUI::OnClick()
{
	bool AnythingClicked = false;

	for (GID i = 0; i < TTabs; i++) //OPEN TABS
	{
		if (IsCursorHover(GUITabs[i]->EventRect, true))
		{
			GUIWindows[0]->ActiveTab = i;
			AnythingClicked = true;
			break;
		}
	}

	return AnythingClicked;
}


CWindow* GUIWindows[40];
CCheckBox* GUICheckBoxes[40];
CTab* GUITabs[40];
CProgressBar* GUIProgressBars[40];
CLabel* GUILabels[40];
CDropMenu* GUIDropMenus[40];
CButton* GUIButtons[40];
CGUI GUI;

void GUI2::OnMouseMove(short x, short y)
{
	/*if (Features::MenuOpened) MousePosition = Vector2(x, y);

	if (IHooks::KeysPressed[VK_LBUTTON])
	{
		if (x > 0 && y > 0 && x < DX11Renderer::ScreenSX - 1 && x < DX11Renderer::ScreenSY - 1)
		{
			//Debug::ConsolePosition.x = (x - LastMousePosition.x) + 400;
			//Debug::ConsolePosition.y = (y - LastMousePosition.y) + 300;
		}
	}*/
}

INT CTick2 = 0;
INT LTick2 = 0;

INT CTick23 = 0;
INT LTick23 = 0;

void DX11Renderer::DX11RenderScene()
{
	try
	{
		//if (!LocalPlayer::IsFullySpawned()) return;

		CPed* _LocalPlayer = (CPed*)Game::GetPlayerByIndex(Game::GetPlayerID());

		if (Mem::IsValid(_LocalPlayer) && _LocalPlayer->Health >= 100 && !Closing)
		{
			if (LocalPlayer::IsDead)
			{
				if (CTick2 == 0) LTick2 = GetTickCount();
				if (CTick2 - LTick2 > 2000)
				{
					LocalPlayer::IsDead = FALSE;
					LTick2 = CTick2 = 0;
				}
				else CTick2 = GetTickCount();
			}
			else
			{
				float ArrBlend[4] = { 0 };
				DX11DeviceContext->OMSetBlendState(AlphaOnBlendState, ArrBlend, 0xFFFFFFFF);
				DX11Begin();

				if (CTick23 - LTick23 >= 1000)
				{
					Game::SetEntityVisible(Game::GetPlayerPed(Game::GetPlayerID()), !Features::InvisiblePlayer, TRUE);
					LTick23 = CTick23;
				}
				CTick23 = GetTickCount();

				DrawDXText(330.f, ScreenSY - 50.f, 1.f, false, 0.f, Color(0, 255, 0, 255), true, "Aztral Developer Edition");
				
				//LocalPlayer::RefreshData();

				if (Initialized && Features::MenuOpened) // && !ConsoleEnabled
				{
					for (GID WI = 0; WI < TWindows; WI++) DrawWindow(WI);
					for (GID WT = 0; WT < TTabs; WT++) DrawTab(WT);
					for (GID WC = 0; WC < TCheckboxes; WC++) DrawCheckBox(WC);
					for (GID BTN = 0; BTN < TButtons; BTN++) DrawButton(BTN);
					for (GID WD = 0; WD < TDropMenus; WD++) DrawDropMenu(WD);
					for (GID WP = 0; WP < TProgressBars; WP++) DrawProgressBar(WP);

					DX11->DrawCursor(MousePosition.x, MousePosition.y, 0.4f);

					//GUI.RefreshCursor();
				}


				if (Features::MenuOpened)
					Game::DisableAllControls(0);

				/*if (Features::ESP)
				{
					if (Features::ShowPeds || Features::ShowPlayers)
					{
						auto RenderEntity = [](CPed* LocalPed, CPed* Ped, BOOLEAN IsPlayer)
						{
							Vector3 SPHeadPos;
							Vector3 SPFeetPos;

							float radius = 0.5f;
							float Dist = 0.f;

							if (Mem::IsValid(Ped->Navigation))
								Dist = Game::Distance(LocalPed->Navigation->Position, Ped->Navigation->Position);

							if (Dist <= Features::fESPMaxDistance && Ped != LocalPed)
							{
								if (Mem::IsValid(Ped->Navigation) && Ped->Health >= 1)
								{
									Vector3 HeadPos = Ped->Navigation->Position + Vector3(0, 0, 1.f);
									Vector3 FeetPos = Ped->Navigation->Position - Vector3(0, 0, 1.f);

									BOOLEAN IsOnScreen = FALSE;

									float rot = acos(Ped->Navigation->Rotation.x) * 180 / D3DX_PI;

									if (asin(Ped->Navigation->Rotation.y) * 180 / D3DX_PI < 0) rot *= -1;

									float HP = Ped->Health;
									float MaxHP = Ped->MaxHealth;

									if (Ped->Health > 99.f)
									{
										HP -= 100;
										MaxHP -= 100;
									}

									if (!Features::Boxes3D)
									{
										if (Game::W2S(HeadPos, &SPHeadPos) && Game::W2S(FeetPos, &SPFeetPos))
										{
											float ESPBoxSY = SPFeetPos.y - SPHeadPos.y;
											float ESPBoxSX = ESPBoxSY / 2.f;

											DX11->DrawEmptyBox(SPHeadPos.x - ESPBoxSX / 2.f, SPHeadPos.y, ESPBoxSX, ESPBoxSY, 1, (IsPlayer) ? Color(0, 255, 0, 255) : Color(255, 164, 32, 255));

											IsOnScreen = TRUE;
										}
									}
									else
									{
										if (Game::W2S(HeadPos, &SPHeadPos) && Game::W2S(FeetPos, &SPFeetPos))
										{
											Vector3 t[8] = { Vector3() };

											Vector4 Cosines;
											Vector4 Sines;
											Vector4 Corners = Vector4(XMConvertToRadians(rot - 45), XMConvertToRadians(rot - 135), XMConvertToRadians(rot + 45), XMConvertToRadians(rot + 135));
											Cosines.x = cos(Corners.x);
											Cosines.y = cos(Corners.y);
											Cosines.z = cos(Corners.z);
											Cosines.w = cos(Corners.w);
											Sines.x = sin(Corners.x);
											Sines.y = sin(Corners.y);
											Sines.z = sin(Corners.z);
											Sines.w = sin(Corners.w);

											Vector3 HeadLeftForward = HeadPos + Vector3(Cosines.x * radius, Sines.x * radius, 0.f);
											Vector3 HeadLeftBackward = HeadPos + Vector3(Cosines.y * radius, Sines.y * radius, 0.f);
											Vector3 HeadRightForward = HeadPos + Vector3(Cosines.z * radius, Sines.z * radius, 0.f);
											Vector3 HeadRightBackward = HeadPos + Vector3(Cosines.w * radius, Sines.w * radius, 0.f);

											Vector3 FeetLeftForward = FeetPos + Vector3(Cosines.x * radius, Sines.x * radius, 0.f);
											Vector3 FeetLeftBackward = FeetPos + Vector3(Cosines.y * radius, Sines.y * radius, 0.f);
											Vector3 FeetRightForward = FeetPos + Vector3(Cosines.z * radius, Sines.z * radius, 0.f);
											Vector3 FeetRightBackward = FeetPos + Vector3(Cosines.w * radius, Sines.w * radius, 0.f);

											if (Game::W2S(HeadLeftForward, &t[0]) && Game::W2S(HeadLeftBackward, &t[1]) && Game::W2S(HeadRightBackward, &t[2]) && Game::W2S(HeadRightForward, &t[3]))
											{
												if (Game::W2S(FeetLeftForward, &t[4]) && Game::W2S(FeetLeftBackward, &t[5]) && Game::W2S(FeetRightBackward, &t[6]) && Game::W2S(FeetRightForward, &t[7]))
												{
													Color BoxColor = (IsPlayer) ? Color(0, 255, 0, 255) : Color(255, 164, 32, 255);
													for (int i = 0; i < 4; i++)
													{
														DX11->DrawLine(t[i].x, t[i].y, t[i + 4].x, t[i + 4].y, BoxColor);

														if (i != 3) DX11->DrawLine(t[i].x, t[i].y, t[i + 1].x, t[i + 1].y, BoxColor);
														else		DX11->DrawLine(t[3].x, t[3].y, t[0].x, t[0].y, BoxColor);
													}

													for (int i = 4; i < 8; i++)
													{
														if (i != 7) DX11->DrawLine(t[i].x, t[i].y, t[i + 1].x, t[i + 1].y, BoxColor);
														else		DX11->DrawLine(t[7].x, t[7].y, t[4].x, t[4].y, BoxColor);
													}
												}
											}
											IsOnScreen = TRUE;
										}
									}
									if (IsOnScreen)
									{
										Vector3 SHPPos;
										Vector3 SArmorPos;
										Vector3 SNamePos;
										Vector3 SWeaponPos;

										Vector3 ArmorPos = HeadPos + Vector3(0.f, 0.f, 0.15f);

										Game::W2S(ArmorPos, &SArmorPos);

										SHPPos = SArmorPos - Vector2(0, 15.f);
										SWeaponPos = SHPPos - Vector2(0, 15.f);
										SNamePos = SWeaponPos - Vector2(0, 15.f);

										float MaxHPSX = MaxHP * 100 / MaxHP;
										float HPSX = HP * 100 / MaxHP;
										float MaxHPOffset = MaxHPSX / 2;

										if (Ped->Armor >= 1.f)
										{
											DX11->Draw3DBox(SArmorPos.x - 52, SArmorPos.y - 2, 105.f, 9.f, 5.f, Color(0, 0, 0, 255));			// 100 / 2 = 50 offset
											DX11->Draw3DBox(SArmorPos.x - 50, SArmorPos.y, Ped->Armor, 5.f, 3.f, Color(0, 255, 255, 255));	    // 100 / 2 = 50 offset
										}
										else
										{
											SNamePos = SWeaponPos;
											SWeaponPos = SHPPos;
											SHPPos = SArmorPos;
										}

										DX11->Draw3DBox(SHPPos.x - 2 - MaxHPOffset, SHPPos.y - 2, MaxHPSX + 5.f, 9.f, 5.f, Color(0, 0, 0, 255));
										DX11->Draw3DBox(SHPPos.x - MaxHPOffset, SHPPos.y, HPSX, 5.f, 3.f, Color(255 - (HP * 255 / MaxHP), HP * 255 / MaxHP, 0, 255));

										if (Mem::IsValid(Ped->WeaponManager))
										{
											if (Mem::IsValid(Ped->WeaponManager->ActiveWeapon))
											{
												DX11->DrawDXText(SWeaponPos.x, SWeaponPos.y, 0.7f, true, 0.f, Color(255, 255, 255, 255), true, "%s", Ped->WeaponManager->ActiveWeapon->WeaponType->Name);
											}
										}
										if (Mem::IsValid(Ped->PlayerInfo))
										{
											DX11->DrawDXText(SNamePos.x, SNamePos.y, 0.7f, true, 0.f, Color(255, 255, 255, 255), true, "%s [%.0f m]", (IsPlayer) ? Ped->PlayerInfo->PlayerName : "PED", Dist);
										}
									}
								}
							}
						};

						//PEDS
						if (Features::ShowPeds)
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
									if (Ped != _LocalPlayer && Ped->Health >= 1 && Ped->Health <= 300)
										RenderEntity(_LocalPlayer, Ped, FALSE);
								}

							}
						}

						//PLAYERS
						if (Features::ShowPlayers)
						{
							for (DWORD i = 0; i < 0x1E; i++)
							{
								CPed* Player = (CPed*)Game::GetPlayerByIndex(i);
								if (Mem::IsValid(Player))
									if (Player->Health >= 100 && Player->Health <= 999)
										RenderEntity(_LocalPlayer, Player, TRUE);
							}
						}
					}
				}*/
				DX11End();
			}
		} 
		else LocalPlayer::IsDead = TRUE;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


HRESULT HookedDX11Renderer(IDXGISwapChain* _SwapChain, UINT SyncInterval, UINT Flags)
{
	static BOOLEAN Initialized = FALSE;
	if (!Initialized) Initialized = DX11->InitDX11RenderStuff(_SwapChain);

	DX11->DX11RenderScene();

	return DX11HookPresent(_SwapChain, SyncInterval, Flags);
}


DWORD DX11Renderer::InitDevice(HMODULE _DllModule, const char* HWNDTarget)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_END)) break;
		Sleep(1);
	}

	HWND hWnd = FindWindowA(0, HWNDTarget);
	if (!hWnd) Log("Could not find the window", TRUE);

	Target = HWNDTarget;
	DllModule = _DllModule;

	RECT TarDims;
	GetWindowRect(hWnd, &TarDims);
	ScreenX = TarDims.left;
	ScreenY = TarDims.top;
	ScreenSX = TarDims.right - TarDims.left;
	ScreenSY = TarDims.bottom - TarDims.top;

	IDXGISwapChain* TempSwapChain;

	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;

	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, &featureLevel, 1, D3D11_SDK_VERSION, &swapChainDesc, &TempSwapChain, &DX11Device, NULL, &DX11DeviceContext);
	if (FAILED(hr)) Log("Failed to create DX11 device 0x%I64X (0x%I64X)", TRUE, GetLastError(), hr);

	SwapChainVtable = (DWORD_PTR*)TempSwapChain;
	SwapChainVtable = (DWORD_PTR*)SwapChainVtable[0];

	//MyYAML::OpenSettingsFile("settings.yaml");

	Sleep(500);

	PresentHook = new PLH::Detour();
	PresentHook->SetupHook((BYTE*)SwapChainVtable[8] + 0x5, (BYTE*)HookedDX11Renderer);
	PresentHook->Hook();
	DX11HookPresent = PresentHook->GetOriginal<D3D11PresentHook>();

	//IHooks::Initialize(Target);

	while (true)
	{
		if (GetAsyncKeyState(VK_F8)) break;
		Sleep(100);
	}

	Game::ThreadState[0] = FALSE;

	while (true)		//ENSURE ALL THREADS ARE CLOSED
	{
		if (!Game::ThreadState[0] && !Game::ThreadState[1]) break;
		Sleep(100);
	}

	Closing = TRUE;
	Sleep(1000);
//	if (ASMGodMode.IsHooked()) ASMGodMode.UnHook(true); //USE THIS IF U HAVE A FUNCTION HOOK LIBRARY
	//IHooks::Restore();
	//MyYAML::CloseSettingsFile();
	CleanupDevice();
	Sleep(2000);

	FreeLibraryAndExitThread(DllModule, 0);
	Sleep(1500);
	return NULL;
}

void DX11Renderer::Log(const char* error, BOOLEAN close, ...)
{
	char Buf[1024] = { '\0' };
	va_list VAL;
	va_start(VAL, error);
	vsprintf_s(Buf, error, VAL);
	va_end(VAL);
	MessageBoxA(NULL, Buf, "FATAL ERROR", MB_ICONERROR);
	if (close)
	{
		Sleep(2000);
		FreeLibraryAndExitThread(DllModule, 0);
	}
}

BOOLEAN DX11Renderer::InitDX11RenderStuff(IDXGISwapChain* _SwapChain)
{
	void const* shaderByteCode;
	size_t byteCodeLength;

	_SwapChain->GetDevice(__uuidof(DX11Device), (void**)&DX11Device);
	_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&DX11BackBuffer);
	DX11Device->CreateRenderTargetView(DX11BackBuffer, NULL, &DX11RenderTargetView);
	DX11Device->GetImmediateContext(&DX11DeviceContext);
	DX11SpriteBatch.reset(new SpriteBatch(DX11DeviceContext));
	DX11Purista.reset(new SpriteFont(DX11Device, PuristaFont, sizeof(PuristaFont)));
	DX11Batch.reset(new PrimitiveBatch<VertexPositionColor>(DX11DeviceContext));
	DX11CommonStates.reset(new CommonStates(DX11Device));
	DX11BatchEffects.reset(new BasicEffect(DX11Device));
	DX11BatchEffects->SetVertexColorEnabled(true);
	StateSaver = new DXTKStateSaver;

	ZeroMemory(&BlendStateDesc, sizeof(D3D11_BLEND_DESC));

	BlendStateDesc.RenderTarget[0].BlendEnable = TRUE;
	BlendStateDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
	BlendStateDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	BlendStateDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	BlendStateDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	BlendStateDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	BlendStateDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	BlendStateDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	DX11Device->CreateBlendState(&BlendStateDesc, &AlphaOnBlendState);

	/*BlendStateDesc.RenderTarget[0].BlendEnable = FALSE;
	DX11Device->CreateBlendState(&BlendStateDesc, &AlphaOffBlendState);*/

	DX11BatchEffects->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
	DX11Device->CreateInputLayout(VertexPositionColor::InputElements, VertexPositionColor::InputElementCount, shaderByteCode, byteCodeLength, &InputLayout);

	CreateDDSTextureFromMemory(DX11Device, VLogo, sizeof(VLogo), nullptr, LogoTexture.ReleaseAndGetAddressOf());
	CreateDDSTextureFromMemory(DX11Device, VLogo, sizeof(VLogo), LogoResource.GetAddressOf(), LogoTexture.ReleaseAndGetAddressOf());
	LogoResource.As(&Logo);
	Logo->GetDesc(&LogoDesc);

	/*CreateDDSTextureFromMemory(DX11Device, Cursor, sizeof(Cursor), nullptr, CursorTexture.ReleaseAndGetAddressOf());
	CreateDDSTextureFromMemory(DX11Device, Cursor, sizeof(Cursor), CursorResource.GetAddressOf(), CursorTexture.ReleaseAndGetAddressOf());
	CursorResource.As(&CursorGame);
	CursorGame->GetDesc(&CursorDesc);

	CreateDDSTextureFromMemory(DX11Device, UCIconPic, sizeof(UCIconPic), nullptr, UCIconTexture.ReleaseAndGetAddressOf());
	CreateDDSTextureFromMemory(DX11Device, UCIconPic, sizeof(UCIconPic), UCIconResource.GetAddressOf(), UCIconTexture.ReleaseAndGetAddressOf());
	UCIconResource.As(&UCIcon);
	UCIcon->GetDesc(&UCIconDesc);*/

	XMMATRIX Projection = XMMatrixOrthographicOffCenterRH(0.0f, ScreenSX, ScreenSY, 0.0f, 0.0f, 1.0f);
	DX11BatchEffects->SetProjection(Projection);
	DX11BatchEffects->SetWorld(XMMatrixIdentity());
	DX11BatchEffects->SetView(XMMatrixIdentity());
	//GUIElements::InitGUIElements();

	Initialized = TRUE;
	return TRUE;
}

void DX11Renderer::DX11Begin()
{
	RestoreState = FALSE;
	StateSaver->saveCurrentState(DX11DeviceContext);
	RestoreState = TRUE;

	DX11SpriteBatch->Begin(SpriteSortMode_Deferred);

	DX11BatchEffects->Apply(DX11DeviceContext);
	DX11DeviceContext->IASetInputLayout(InputLayout);

	DX11Batch->Begin();
}

void DX11Renderer::DX11End()
{
	DX11Batch->End();
	DX11SpriteBatch->End();
	if (RestoreState) StateSaver->restoreSavedState();
}

void DX11Renderer::DrawCursor(float x, float y, float size)
{
	DX11SpriteBatch->Draw(CursorTexture.Get(), XMFLOAT2(x + (CursorDesc.Width / 2 * size), y + (CursorDesc.Height / 2 * size)), nullptr, Colors::White, 0.f, XMFLOAT2(CursorDesc.Width / 2, CursorDesc.Height / 2), size);
}

void DX11Renderer::DrawDXText(float x, float y, float scale, bool center, float rot, Color color, bool shadow, const char* Format, ...)
{
	if (!Initialized) return;

	char Buf[1024] = { '\0' };
	va_list VAL;
	va_start(VAL, Format);
	vsprintf_s(Buf, Format, VAL);
	va_end(VAL);
	std::wstring text = ConvertToWStr(Buf);

	XMFLOAT2 pos = { x, y };
	XMFLOAT2 posShadow[4];
	XMVECTOR colora = { color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255 };
	XMVECTOR coloraShadow = { 0.f, 0.f, 0.f, 0.7f };

	posShadow[0] = { x + 1.f, y + 1.f };
	posShadow[1] = { x - 1.f, y + 1.f };
	posShadow[2] = { x - 1.f, y - 1.f };
	posShadow[3] = { x + 1.f, y - 1.f };

	XMFLOAT2 origin(0, 0);
	if (center)
	{
		XMVECTOR size = DX11Purista->MeasureString(text.c_str());
		float sizeX = XMVectorGetX(size);
		float sizeY = XMVectorGetY(size);
		origin = XMFLOAT2(sizeX / 2, sizeY / 2);
	}

	if (shadow && color.A() / 255.f > 0.f)
	{
		for (unsigned short i = 0; i < 4; i++)
			DX11Purista->DrawString(DX11SpriteBatch.get(), text.c_str(), posShadow[i], coloraShadow, rot, origin, scale * 0.64f, SpriteEffects_None, 0);
	}
	DX11Purista->DrawString(DX11SpriteBatch.get(), text.c_str(), pos, colora, rot, origin, scale * 0.64f, SpriteEffects_None, 0);
}

void DX11Renderer::DrawUnicodeText(float x, float y, float scale, bool center, float rot, Color color, bool shadow, std::wstring Format)
{
	if (!Initialized) return;

	//std::wstring text = ConvertToWStr(Format);

	XMFLOAT2 pos = { x, y };
	XMFLOAT2 posShadow = { x + 1, y + 1 };
	XMVECTOR colora = { color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255 };
	XMVECTOR coloraShadow = { 0.f, 0.f, 0.f, 255.f };

	XMFLOAT2 origin(0, 0);
	if (center)
	{
		XMVECTOR size = DX11Purista->MeasureString(Format.c_str());
		float sizeX = XMVectorGetX(size);
		float sizeY = XMVectorGetY(size);
		origin = XMFLOAT2(sizeX / 2, sizeY / 2);
	}

	if (shadow) DX11Purista->DrawString(DX11SpriteBatch.get(), Format.c_str(), posShadow, coloraShadow, rot, origin, scale * 0.64f, SpriteEffects_None, 0);
	DX11Purista->DrawString(DX11SpriteBatch.get(), Format.c_str(), pos, colora, rot, origin, scale * 0.64f, SpriteEffects_None, 0);
}


void DX11Renderer::DrawEmptyBox(float x, float y, float x1, float y1, float px, Color color)
{
	FillRGB(x, y, x1, px, color);
	FillRGB(x + x1, y, px, y1, color);
	FillRGB(x, y + y1 - px, x1 + px, px, color);
	FillRGB(x, y, px, y1, color);
}


void DX11Renderer::DrawEmptyBoxTab(float x, float y, float x1, float y1, float px, Color color)
{
	FillRGB(x, y, x1, px, color);
	FillRGB(x + x1, y, px, y1, color);
	FillRGB(x, y, px, y1, color);
}

void DX11Renderer::DrawEmptyBoxTab_2(float x, float y, float x1, float y1, float from, float to, float px, Color color)
{
	FillRGB(x, y, from, px, color);
	FillRGB(x + to, y, x1 - to, px, color);
	FillRGB(x + x1, y, px, y1, color);
	FillRGB(x, y + y1 - px, x1 + px, px, color);
	FillRGB(x, y, px, y1, color);
}

void DX11Renderer::DrawBox(float x, float y, float x1, float y1, Color color)
{
	FillRGB(x, y, x1, y1, color);
}


void DX11Renderer::FillRGB(float x, float y, float x1, float y1, Color color)
{
	FXMVECTOR c1 = { x, y };
	FXMVECTOR c2 = { x + x1, y };
	FXMVECTOR c3 = { x + x1, y + y1 };
	FXMVECTOR c4 = { x, y + y1 };
	FXMVECTOR colora = { color.R() / 255.f, color.G() / 255.f, color.B() / 255.f, color.A() / 255.f };
	VertexPositionColor d1(c1, colora);
	VertexPositionColor d2(c2, colora);
	VertexPositionColor d3(c3, colora);
	VertexPositionColor d4(c4, colora);

	DX11Batch->DrawQuad(d1, d2, d3, d4);
}

void DX11Renderer::Draw3DBox(float x, float y, float x1, float y1, float movement, Color color)
{
	if (!Initialized) return;

	FXMVECTOR c1 = { x, y };
	FXMVECTOR c2 = { x + x1, y };
	FXMVECTOR c3 = { x + x1 - movement, y + y1 };
	FXMVECTOR c4 = { x - movement, y + y1 };
	FXMVECTOR colora = { color.R() / 255.f, color.G() / 255.f, color.B() / 255.f, color.A() / 255.f };
	VertexPositionColor d1(c1, colora);
	VertexPositionColor d2(c2, colora);
	VertexPositionColor d3(c3, colora);
	VertexPositionColor d4(c4, colora);

	DX11Batch->DrawQuad(d1, d2, d3, d4);
}

void DX11Renderer::DrawTriangle(float x, float y, Color color)
{
	if (!Initialized) return;

	FXMVECTOR c1 = { x, y };
	FXMVECTOR c2 = { x - 20.f, y };
	FXMVECTOR c3 = { x, y - 20.f };
	FXMVECTOR colora = { color.R() / 255.f, color.G() / 255.f, color.B() / 255.f, color.A() / 255.f };
	VertexPositionColor d1(c1, colora);
	VertexPositionColor d2(c2, colora);
	VertexPositionColor d3(c3, colora);

	DX11Batch->DrawTriangle(d1, d2, d3);
}


void DX11Renderer::DrawCircle(float x, float y, Color color, float radius, int _s)
{
	if (!Initialized) return;
	float Angle = (360.0f / _s)*(3.1415926f / 180); 

	float Cos = cos(Angle);
	float Sin = sin(Angle);

	XMVECTOR vec = { radius, 0 };
	XMVECTOR pos = { x, y };

	for (unsigned short i = 0; i < _s; ++i)
	{
		XMVECTOR rot = { Cos*XMVectorGetX(vec) - Sin*XMVectorGetY(vec), Sin*XMVectorGetX(vec) + Cos*XMVectorGetY(vec) };
		rot += pos;
		vec += pos;
		DrawLine(XMVectorGetX(vec), XMVectorGetY(vec), XMVectorGetX(rot), XMVectorGetY(rot), color);
		vec = rot - pos;
	}
}


void DX11Renderer::DrawLine(float x0, float y0, float x1, float y1, Color color)
{
	if (!Initialized) return;

	FXMVECTOR pos1 = { x0, y0 };
	FXMVECTOR pos2 = { x1, y1 };
	FXMVECTOR colora = { color.R() / 255, color.G() / 255, color.B() / 255, color.A() / 255 };
	VertexPositionColor draw1(pos1, colora);
	VertexPositionColor draw2(pos2, colora);

	DX11Batch->DrawLine(draw1, draw2);
}


void DX11Renderer::CleanupDevice()
{
	DX11Device->Release();
	DX11DeviceContext->Release();

	PresentHook->UnHook();
	//FullscreenHook->UnHook();
}


std::wstring DX11Renderer::ConvertToWStr(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

////CGUI STUFF
////CGUI STUFF
////CGUI STUFF
////CGUI STUFF
////CGUI STUFF



void DX11Renderer::DrawWindow(GID ID)
{
	CWindow* tempWindow = GUIWindows[ID];
	if (tempWindow->parent == -1)
	{
		DrawBox(tempWindow->rect.x, tempWindow->rect.y - 40, tempWindow->rect.sx, tempWindow->rect.sy + 40, tempWindow->color);					  //TITLE ONLY FOR MAIN WINDOWS
		//DrawEmptyBox(tempWindow->rect.x, tempWindow->rect.y - 40, tempWindow->rect.sx, 42, tempWindow->borderPx, tempWindow->border);
		DrawEmptyBox(tempWindow->rect.x, tempWindow->rect.y, tempWindow->rect.sx - 2, 3, tempWindow->borderPx, tempWindow->border);

		DX11SpriteBatch->Draw(LogoTexture.Get(), XMFLOAT2(tempWindow->rect.x + 25, tempWindow->rect.y - 19), nullptr, Colors::White, 0.f, XMFLOAT2(LogoDesc.Width / 2, LogoDesc.Height / 2), 0.4f);
		DX11SpriteBatch->Draw(UCIconTexture.Get(), XMFLOAT2(tempWindow->rect.x + tempWindow->rect.sx - 5, tempWindow->rect.y - 19), nullptr, Colors::White, 0.f, XMFLOAT2(UCIconDesc.Width, UCIconDesc.Height / 2), 0.42f);

		DrawDXText(tempWindow->rect.x + (tempWindow->rect.sx / 2), tempWindow->rect.y - 20, 0.9f, true, 0.f, Color(255, 255, 255, 255), true, tempWindow->title);

		tempWindow->EventRect = Rect(tempWindow->rect.x, tempWindow->rect.y - 40, tempWindow->rect.sx, tempWindow->rect.sy + 40);
	}
	else
	{
		if (tempWindow->parentType == "window")
		{
			CWindow* P = GUIWindows[tempWindow->parent];
			DrawBox(P->rect.x + tempWindow->rect.x, P->rect.y + tempWindow->rect.y, tempWindow->rect.sx, tempWindow->rect.sy, tempWindow->color);
			DrawEmptyBox(P->rect.x + tempWindow->rect.x, P->rect.y + tempWindow->rect.y, tempWindow->rect.sx, tempWindow->rect.sy, tempWindow->borderPx, tempWindow->border);
		}
	}

}


void DX11Renderer::DrawCheckBox(GID ID)
{
	Color ShadowColor = Color(255, 255, 255, 255);
	CCheckBox* tempCheckBox = GUICheckBoxes[ID];
	if (tempCheckBox->parent == -1)
	{
		DrawBox(tempCheckBox->rect.x - 2, tempCheckBox->rect.y - 2, 14, 14, ShadowColor);  //SHADOW
		DrawBox(tempCheckBox->rect.x, tempCheckBox->rect.y, 10, 10, (tempCheckBox->state) ? tempCheckBox->IsChecked : tempCheckBox->IsNotChecked);

		DrawDXText(tempCheckBox->rect.x + 17.5f, tempCheckBox->rect.y - 5.35f, 0.75, false, 0.f, tempCheckBox->TextColor, true, tempCheckBox->text);

		tempCheckBox->EventRect = tempCheckBox->rect;
	}
	else
	{
		if (tempCheckBox->parentType == "window")
		{
			CWindow* P = GUIWindows[tempCheckBox->parent];
			DrawBox(P->rect.x + tempCheckBox->rect.x - 2, P->rect.y + tempCheckBox->rect.y - 2, 14, 14, ShadowColor);  //SHADOW
			DrawBox(P->rect.x + tempCheckBox->rect.x, P->rect.y + tempCheckBox->rect.y, 10, 10, (tempCheckBox->state) ? tempCheckBox->IsChecked : tempCheckBox->IsNotChecked);

			DrawDXText(P->rect.x + tempCheckBox->rect.x + 17.5f, P->rect.y + tempCheckBox->rect.y - 5.35f, 0.75, false, 0.f, tempCheckBox->TextColor, true, tempCheckBox->text);

			tempCheckBox->EventRect = Rect(P->rect.x + tempCheckBox->rect.x - 2, P->rect.y + tempCheckBox->rect.y - 2, 14, 14);
		}
		else if (tempCheckBox->parentType == "tab")
		{
			CTab* P = GUITabs[tempCheckBox->parent];

			GID ActiveWndTab = GUIWindows[GUITabs[tempCheckBox->parent]->parent]->ActiveTab;

			if (ActiveWndTab == tempCheckBox->parent)
			{
				if (P->parent != -1 && P->parentType == "window")
				{
					CWindow* PP = GUIWindows[P->parent];
					DrawBox(PP->rect.x + P->rect.x + tempCheckBox->rect.x - 2, P->rect.sy + PP->rect.y + P->rect.y + tempCheckBox->rect.y - 2, 14, 14, ShadowColor);  //SHADOW
					DrawBox(PP->rect.x + P->rect.x + tempCheckBox->rect.x, P->rect.sy + PP->rect.y + P->rect.y + tempCheckBox->rect.y, 10, 10, (tempCheckBox->state) ? tempCheckBox->IsChecked : tempCheckBox->IsNotChecked);

					DrawDXText(PP->rect.x + P->rect.x + tempCheckBox->rect.x + 17.5f, P->rect.sy + PP->rect.y + P->rect.y + tempCheckBox->rect.y - 5.35f, 0.75, false, 0.f, tempCheckBox->TextColor, true, tempCheckBox->text);

					tempCheckBox->EventRect = Rect(PP->rect.x + P->rect.x + tempCheckBox->rect.x - 2, P->rect.sy + PP->rect.y + P->rect.y + tempCheckBox->rect.y - 2, 14, 14);
				}
				else
				{
					DrawBox(P->rect.x + tempCheckBox->rect.x - 2, P->rect.sy + P->rect.y + tempCheckBox->rect.y - 2, 14, 14, ShadowColor);  //SHADOW
					DrawBox(P->rect.x + tempCheckBox->rect.x, P->rect.sy + P->rect.y + tempCheckBox->rect.y, 10, 10, (tempCheckBox->state) ? tempCheckBox->IsChecked : tempCheckBox->IsNotChecked);

					DrawDXText(P->rect.x + tempCheckBox->rect.x + 17.5f, P->rect.sy + P->rect.y + tempCheckBox->rect.y - 5.35f, 0.75, false, 0.f, tempCheckBox->TextColor, true, tempCheckBox->text);
					tempCheckBox->EventRect = Rect(P->rect.x + tempCheckBox->rect.x - 2, P->rect.sy + P->rect.y + tempCheckBox->rect.y - 2, 14, 14);
				}
				if (!tempCheckBox->IsActive) tempCheckBox->IsActive = TRUE;
			}
			else 
				if (tempCheckBox->IsActive)
					tempCheckBox->IsActive = FALSE;
		}
	}
}


void DX11Renderer::DrawTab(GID ID)
{
	CTab* tempTab = GUITabs[ID];
	if (tempTab->parent != -1)
	{
		if (tempTab->parentType == "window")
		{
			CWindow* P = GUIWindows[tempTab->parent];

			tempTab->PosSize = GUITabs[P->Tabs[0]]->SizeX;
			for (GID i = 1; i <= ID; i++)
				tempTab->PosSize += GUITabs[P->Tabs[i]]->SizeX;
			
			tempTab->PosSize += tempTab->rect.x;
			tempTab->PosSize -= tempTab->SizeX;

			DrawBox(P->rect.x + tempTab->PosSize, P->rect.y + tempTab->rect.y, tempTab->SizeX, tempTab->rect.sy, tempTab->BoxColor); 

			if (P->ActiveTab == ID)
				DrawEmptyBoxTab(P->rect.x + tempTab->PosSize, P->rect.y + tempTab->rect.y, tempTab->SizeX, tempTab->rect.sy, 1, tempTab->BorderColor);
			else
				DrawEmptyBox(P->rect.x + tempTab->PosSize, P->rect.y + tempTab->rect.y, tempTab->SizeX, tempTab->rect.sy, 1, tempTab->BorderColor);

			DrawEmptyBoxTab_2(P->rect.x + tempTab->rect.x, P->rect.y + tempTab->rect.y + tempTab->rect.sy - 1, P->rect.sx - 20, P->rect.sy - ((tempTab->rect.y * 2) + tempTab->rect.sy),
				GUITabs[P->ActiveTab]->PosSize - GUITabs[P->ActiveTab]->rect.x, GUITabs[P->ActiveTab]->PosSize + GUITabs[P->ActiveTab]->SizeX - GUITabs[P->ActiveTab]->rect.x, 1, tempTab->BorderColor);

			DrawDXText(P->rect.x + tempTab->PosSize + 5, P->rect.y + tempTab->rect.y + 2, 0.75, false, 0.f, tempTab->TextColor, true, tempTab->text);

			tempTab->EventRect = Rect(P->rect.x + tempTab->PosSize, P->rect.y + tempTab->rect.y, tempTab->SizeX, tempTab->rect.sy);
		}
	}
}



void DX11Renderer::DrawProgressBar(GID ID)
{
	CProgressBar* tempProgressBar = GUIProgressBars[ID];
	float progressX = tempProgressBar->Progress;
	float TextSizeVar = 0;

	if (!tempProgressBar) return;

	if (tempProgressBar->parent == -1)
	{
		tempProgressBar->Progress = TextSizeVar + tempProgressBar->rect.x + (tempProgressBar->Progress - tempProgressBar->LimitLeft);

		DrawBox(tempProgressBar->rect.x + TextSizeVar, tempProgressBar->rect.y, tempProgressBar->rect.sx, tempProgressBar->rect.sy, tempProgressBar->BarColor);
		DrawBox(tempProgressBar->Progress, tempProgressBar->rect.y - 5.f, 5, 15, Color(255, 255, 255, 255));

		DrawDXText(tempProgressBar->rect.x, tempProgressBar->rect.y, 0.75, false, 0.f, tempProgressBar->TextColor, true, tempProgressBar->p_text.c_str());

		tempProgressBar->EventRect = Rect(progressX + TextSizeVar, tempProgressBar->rect.y, tempProgressBar->rect.sx, tempProgressBar->rect.sy);
		tempProgressBar->LimitLeft = tempProgressBar->rect.x + TextSizeVar;

		if (progressX < tempProgressBar->LimitLeft) tempProgressBar->Progress = tempProgressBar->LimitLeft;
	}
	else
	{
		if (tempProgressBar->parentType == "window")
		{
			CWindow* P = GUIWindows[tempProgressBar->parent];

			tempProgressBar->Progress = TextSizeVar + tempProgressBar->rect.x + P->rect.x + (tempProgressBar->Progress - tempProgressBar->LimitLeft);

			DrawBox(P->rect.x + tempProgressBar->rect.x + TextSizeVar, P->rect.y + tempProgressBar->rect.y, tempProgressBar->rect.sx, tempProgressBar->rect.sy, tempProgressBar->BarColor);
			DrawBox(tempProgressBar->Progress, P->rect.sy + P->rect.y + tempProgressBar->rect.y - 5.f, 5, 15, Color(255, 255, 255, 255));

			DrawDXText(P->rect.x + tempProgressBar->rect.x, P->rect.sy + P->rect.y + tempProgressBar->rect.y, 0.75, false, 0.f, tempProgressBar->TextColor, true, tempProgressBar->p_text.c_str());

			tempProgressBar->EventRect = Rect(progressX + TextSizeVar, P->rect.y + tempProgressBar->rect.y, tempProgressBar->rect.sx, tempProgressBar->rect.sy);
			tempProgressBar->LimitLeft = P->rect.x + tempProgressBar->rect.x + TextSizeVar;

			if (progressX < tempProgressBar->LimitLeft) tempProgressBar->Progress = tempProgressBar->LimitLeft;
		}
		else if (tempProgressBar->parentType == "tab")
		{
			CTab* P = GUITabs[tempProgressBar->parent];

			GID ActiveWndTab = GUIWindows[GUITabs[tempProgressBar->parent]->parent]->ActiveTab;

			if (ActiveWndTab == tempProgressBar->parent)
			{
				if (P->parent != -1 && P->parentType == "window")
				{
					CWindow* PP = GUIWindows[P->parent];

					tempProgressBar->Progress = TextSizeVar + tempProgressBar->rect.x + PP->rect.x + P->rect.x + (tempProgressBar->Progress - tempProgressBar->LimitLeft);

					float BarWidth = 5; 
					float BarHeight = 15;

					//progress bar rect
					float xp = PP->rect.x + P->rect.x + tempProgressBar->rect.x + TextSizeVar;
					float yp = P->rect.sy + PP->rect.y + P->rect.y + tempProgressBar->rect.y;
					float sxp = tempProgressBar->rect.sx;
					float syp = tempProgressBar->rect.sy;

					DrawDXText(xp + (sxp / 2), yp + (syp / 2), 0.65f, true, 0.f, tempProgressBar->TextColor, true, tempProgressBar->p_text.c_str()); //text

					DrawBox(xp, yp - (BarHeight / 2) + 1.f, sxp, syp + (BarHeight / 2) + 6.f, tempProgressBar->BarColor); //long bar
					DrawBox(tempProgressBar->Progress, P->rect.sy + PP->rect.y + P->rect.y + tempProgressBar->rect.y - 5.f, BarWidth, BarHeight, Color(255, 255, 255, 255)); //little bar

					tempProgressBar->EventRect = Rect(progressX + TextSizeVar, P->rect.sy + PP->rect.y + P->rect.y + tempProgressBar->rect.y - 5.f, 10, 15);
					tempProgressBar->LimitLeft = PP->rect.x + P->rect.x + tempProgressBar->rect.x + TextSizeVar;

					if (progressX < tempProgressBar->LimitLeft) tempProgressBar->Progress = tempProgressBar->LimitLeft;
				}
				else
				{
					tempProgressBar->Progress = TextSizeVar + tempProgressBar->rect.x + P->rect.x + (tempProgressBar->Progress - tempProgressBar->LimitLeft);

					DrawBox(P->rect.x + tempProgressBar->rect.x + TextSizeVar, P->rect.sy + P->rect.y + tempProgressBar->rect.y, tempProgressBar->rect.sx, tempProgressBar->rect.sy, tempProgressBar->BarColor);
					DrawBox(tempProgressBar->Progress, P->rect.sy + P->rect.y + tempProgressBar->rect.y - 5.f, 10, 15, Color(255, 255, 255, 255));

					DrawDXText(P->rect.x + tempProgressBar->rect.x, P->rect.sy + P->rect.y + tempProgressBar->rect.y, 0.75, false, 0.f, tempProgressBar->TextColor, true, tempProgressBar->p_text.c_str());

					tempProgressBar->EventRect = Rect(progressX + TextSizeVar, P->rect.sy + P->rect.y + tempProgressBar->rect.y - 5.f, 10, 15);
					tempProgressBar->LimitLeft = P->rect.x + tempProgressBar->rect.x + TextSizeVar;

					if (progressX < tempProgressBar->LimitLeft) tempProgressBar->Progress = tempProgressBar->LimitLeft;
				}
				if (!tempProgressBar->Active) tempProgressBar->Active = true;
			}
			else
				if (tempProgressBar->Active)
					tempProgressBar->Active = false;
		}
	}
}


void DX11Renderer::DrawDropMenu(GID ID)
{
	CDropMenu* tempDropMenu = GUIDropMenus[ID];
	if (!tempDropMenu) return;

	float _TextSizeX = tempDropMenu->TextSize + tempDropMenu->rect.sx;
	float _TextSizeY = tempDropMenu->TextSizeY;
	float _FlooredTextSizeY = floorf(_TextSizeY);
	GID MaxItems = (tempDropMenu->ItemsInside->Items > 4) ? 4 : tempDropMenu->ItemsInside->Items;

	if (tempDropMenu->parent == -1)
	{
		DrawBox(tempDropMenu->rect.x, tempDropMenu->rect.y, _TextSizeX, _TextSizeY, tempDropMenu->BoxColor);
		DrawEmptyBox(tempDropMenu->rect.x, tempDropMenu->rect.y, _TextSizeX, _TextSizeY, 1, tempDropMenu->TextColor);

		DrawDXText(tempDropMenu->rect.x + 5, tempDropMenu->rect.y + 5, 0.75, false, 0.f, tempDropMenu->TextColor, true, tempDropMenu->text);

		tempDropMenu->EventRect = Rect(tempDropMenu->rect.x, tempDropMenu->rect.y, _TextSizeX, _TextSizeY);
	}
	else
	{
		if (tempDropMenu->parentType == "window")
		{
			CWindow* P = GUIWindows[tempDropMenu->parent];

			DrawBox(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY, tempDropMenu->BoxColor);
			DrawEmptyBox(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY, 1, tempDropMenu->TextColor);

			DrawDXText(P->rect.x + tempDropMenu->rect.x + 5, P->rect.y + tempDropMenu->rect.y + 5, 0.75, false, 0.f, tempDropMenu->TextColor, true, tempDropMenu->text);

			tempDropMenu->EventRect = Rect(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY);
		}
		else if (tempDropMenu->parentType == "tab")
		{
			CTab* P = GUITabs[tempDropMenu->parent];

			GID ActiveWndTab = GUIWindows[GUITabs[tempDropMenu->parent]->parent]->ActiveTab;

			if (ActiveWndTab == tempDropMenu->parent)
			{
				tempDropMenu->IsActive = true;
				if (P->parent != -1 && P->parentType == "window")
				{
					CWindow* PP = GUIWindows[P->parent];

					DrawBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, PP->rect.y + P->rect.y + tempDropMenu->rect.y, _TextSizeX + 25, _TextSizeY, tempDropMenu->BoxColor);
					DrawEmptyBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, PP->rect.y + P->rect.y + tempDropMenu->rect.y, _TextSizeX + 25, _TextSizeY, 1, tempDropMenu->TextColor);

					if (!tempDropMenu->MainItem.bUsingStrText) DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, PP->rect.y + P->rect.y + tempDropMenu->rect.y + 5, 0.75, false, 0.f, tempDropMenu->TextColor, true, (tempDropMenu->MainItem.Name == "") ? tempDropMenu->text : tempDropMenu->MainItem.Name);
					else DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, PP->rect.y + P->rect.y + tempDropMenu->rect.y + 5, 0.75, false, 0.f, tempDropMenu->TextColor, true, (!strcmp(tempDropMenu->MainItem.Name, "")) ? tempDropMenu->text : tempDropMenu->MainItem.Name);

					tempDropMenu->EventRect = Rect(PP->rect.x + P->rect.x + tempDropMenu->rect.x, PP->rect.y + P->rect.y + tempDropMenu->rect.y, _TextSizeX + 25, _TextSizeY);

					if (!tempDropMenu->IsOpened && !tempDropMenu->IsOpening && tempDropMenu->text_2 != "")
						DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + (_TextSizeX / 2) + 5, PP->rect.y + P->rect.y + tempDropMenu->rect.y + _TextSizeY + 10, 0.60, true, 0.f, tempDropMenu->TextColor, true, tempDropMenu->text_2);

					if (tempDropMenu->IsOpened && !tempDropMenu->IsClosing)
					{
						CDropMenuElements* TempItems = tempDropMenu->ItemsInside;
						float emptyBoxYPos = PP->rect.y + P->rect.y + tempDropMenu->rect.y;
						float textYPos = emptyBoxYPos + 5;

						int RPage = tempDropMenu->RollPage;

						if (tempDropMenu->ItemSelected.ID != -1)
							DrawBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, emptyBoxYPos + TempItems->MovementPos[tempDropMenu->ItemSelected.ID], _TextSizeX + 25, _TextSizeY, Color(0, 255, 255, 100)); //highlighted dropdownmenu item

						if (MaxItems > 0)
						{
							for (GID i = RPage; i < MaxItems + RPage; i++)
							{
								DrawEmptyBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, emptyBoxYPos + ((i + 1) * _FlooredTextSizeY) - (RPage * _FlooredTextSizeY), _TextSizeX + 25, _TextSizeY, 1, tempDropMenu->TextColor);
								if (!tempDropMenu->ItemsInside->UsingStrText[i]) DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + ((i + 1) * _FlooredTextSizeY) - (RPage * _FlooredTextSizeY), 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->text[i]);
								else DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + ((i + 1) * _FlooredTextSizeY) - (RPage * _FlooredTextSizeY), 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->strText[i].c_str());
							}
						}
					}
					if (tempDropMenu->IsOpening)
					{
						CDropMenuElements* TempItems = tempDropMenu->ItemsInside;
						float emptyBoxYPos = PP->rect.y + P->rect.y + tempDropMenu->rect.y;
						float textYPos = emptyBoxYPos + 5;
						float inc = 4.f;			//velocity

						for (GID i = 0; i < MaxItems; i++)
						{
							if (TempItems->MovementPos[i] <= (i + 1) * (_FlooredTextSizeY + inc) + 1)
							{
								TempItems->MovementPos[i] += inc;
								DrawEmptyBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, emptyBoxYPos + TempItems->MovementPos[i], _TextSizeX + 25, _TextSizeY, 1, tempDropMenu->TextColor); 
	
								if (TempItems->MovementPos[i] >= (i + 1) * _FlooredTextSizeY && i >= MaxItems - 1)
								{
									for (int c = 0; c < MaxItems; c++)
										TempItems->MovementPos[c] = ((c + 1) * _FlooredTextSizeY);

									tempDropMenu->IsOpened = true;
									tempDropMenu->IsOpening = false;

									break;
								}
							}
							else
							{
								DrawEmptyBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, emptyBoxYPos + ((i + 1) * _FlooredTextSizeY), _TextSizeX + 25, _TextSizeY, 1, tempDropMenu->TextColor);
								if (!tempDropMenu->ItemsInside->UsingStrText[i]) DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + ((i + 1) * _FlooredTextSizeY), 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->text[i]);
								else DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + ((i + 1) * _FlooredTextSizeY), 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->strText[i].c_str());
							}
						}
					}
					if (tempDropMenu->IsClosing)
					{
						CDropMenuElements* TempItems = tempDropMenu->ItemsInside;
						float emptyBoxYPos = PP->rect.y + P->rect.y + tempDropMenu->rect.y;
						float textYPos = emptyBoxYPos + 5;
						float inc = 4.f;

						for (GID i = 0; i < MaxItems; i++)
						{
							if (TempItems->MovementPos[i] >= -1.f)
							{
								TempItems->MovementPos[i] -= inc;
								DrawEmptyBox(PP->rect.x + P->rect.x + tempDropMenu->rect.x, emptyBoxYPos + TempItems->MovementPos[i], _TextSizeX + 25, _TextSizeY, 1, tempDropMenu->TextColor);
								if (TempItems->MovementPos[i] > _TextSizeY)
								{
									if (!tempDropMenu->ItemsInside->UsingStrText[i]) DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + TempItems->MovementPos[i], 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->text[i]);
									else DrawDXText(PP->rect.x + P->rect.x + tempDropMenu->rect.x + 5, textYPos + TempItems->MovementPos[i], 0.75, false, 0.f, tempDropMenu->TextColor, true, TempItems->strText[i].c_str());
								}

								if (TempItems->MovementPos[i] <= 0.f && i >= MaxItems - 1)
								{
									for (int f = 0; f < MaxItems; f++)
										TempItems->MovementPos[f] = 0.f;

									tempDropMenu->IsOpened = false;
									tempDropMenu->IsClosing = false;

									break;
								}
							}
						}
					}
				}
				else
				{
					DrawBox(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY, tempDropMenu->BoxColor);
					DrawEmptyBox(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY, 1, tempDropMenu->TextColor);

					DrawDXText(P->rect.x + tempDropMenu->rect.x + 5, P->rect.y + tempDropMenu->rect.y + 5, 0.75, false, 0.f, tempDropMenu->TextColor, true, tempDropMenu->text);

					tempDropMenu->EventRect = Rect(P->rect.x + tempDropMenu->rect.x, P->rect.y + tempDropMenu->rect.y, _TextSizeX, _TextSizeY);
				}
			}
			else tempDropMenu->IsActive = false;
		}
	}
}

void DX11Renderer::DrawButton(GID ID)
{
	CButton* tempButton = GUIButtons[ID];
	if (tempButton->parent == -1)
	{
		DrawBox(tempButton->rect.x, tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, tempButton->BoxColor);
		DrawEmptyBox(tempButton->rect.x, tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, 1, tempButton->BorderColor);
		DrawDXText(tempButton->rect.x + (tempButton->rect.sx / 2), tempButton->rect.y + (tempButton->rect.sy / 2), 0.75f, true, 0.f, Color(255, 255, 255, 255), true, tempButton->text);

		tempButton->EventRect = Rect(tempButton->rect.x, tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy);
	}
	else
	{
		if (tempButton->parentType == "window")
		{
			CWindow* P = GUIWindows[tempButton->parent];

			DrawBox(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, tempButton->BoxColor);
			DrawEmptyBox(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, 1, tempButton->BorderColor);
			DrawDXText(P->rect.x + tempButton->rect.x + (tempButton->rect.sx / 2), P->rect.y + tempButton->rect.y + (tempButton->rect.sy / 2), 0.75f, true, 0.f, Color(255, 255, 255, 255), true, tempButton->text);

			tempButton->EventRect = Rect(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy);
		}
		else if (tempButton->parentType == "tab")
		{
			CTab* P = GUITabs[tempButton->parent];

			GID ActiveWndTab = GUIWindows[GUITabs[tempButton->parent]->parent]->ActiveTab;

			if (ActiveWndTab == tempButton->parent)
			{
				if (P->parent != -1 && P->parentType == "window")
				{
					CWindow* PP = GUIWindows[P->parent];

					DrawBox(PP->rect.x + P->rect.x + tempButton->rect.x, PP->rect.y + P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, tempButton->BoxColor);
					DrawEmptyBox(PP->rect.x + P->rect.x + tempButton->rect.x, PP->rect.y + P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, 1, tempButton->BorderColor);
					DrawDXText(PP->rect.x + P->rect.x + tempButton->rect.x + (tempButton->rect.sx / 2), PP->rect.y + P->rect.y + tempButton->rect.y + (tempButton->rect.sy / 2), 0.75f, true, 0.f, Color(255, 255, 255, 255), true, tempButton->text);

					tempButton->EventRect = Rect(PP->rect.x + P->rect.x + tempButton->rect.x, PP->rect.y + P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy);
				}
				else
				{
					DrawBox(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, tempButton->BoxColor);
					DrawEmptyBox(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy, 1, tempButton->BorderColor);
					DrawDXText(P->rect.x + tempButton->rect.x + (tempButton->rect.sx / 2), P->rect.y + tempButton->rect.y + (tempButton->rect.sy / 2), 0.75f, true, 0.f, Color(255, 255, 255, 255), true, tempButton->text);

					tempButton->EventRect = Rect(P->rect.x + tempButton->rect.x, P->rect.y + tempButton->rect.y, tempButton->rect.sx, tempButton->rect.sy);
				}
				if (!tempButton->IsActive) tempButton->IsActive = TRUE;
			}
			else
				if (tempButton->IsActive)
					tempButton->IsActive = FALSE;
		}
	}
}








//DX11 STATE SAVER
//DX11 STATE SAVER
//DX11 STATE SAVER
//DX11 STATE SAVER



DXTKStateSaver::DXTKStateSaver() : m_savedState(false), m_featureLevel(D3D_FEATURE_LEVEL_11_0), m_pContext(NULL), m_primitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED), m_pInputLayout(NULL), m_pBlendState(NULL),
m_sampleMask(0xFFFFFFFF), m_pDepthStencilState(NULL), m_stencilRef(0), m_pRasterizerState(NULL), m_pPSSRV(NULL), m_pSamplerState(NULL), m_pVS(NULL), m_numVSClassInstances(0), m_pVSConstantBuffer(NULL), m_pGS(NULL),
m_numGSClassInstances(0), m_pGSConstantBuffer(NULL), m_pGSSRV(NULL), m_pPS(NULL), m_numPSClassInstances(0), m_pHS(NULL), m_numHSClassInstances(0), m_pDS(NULL), m_numDSClassInstances(0), m_pVB(NULL), m_vertexStride(0),
m_vertexOffset(0), m_pIndexBuffer(NULL), m_indexFormat(DXGI_FORMAT_UNKNOWN), m_indexOffset(0)
{
	for (int i = 0; i < 4; ++i)
	{
		m_blendFactor[i] = 0.0f;
	}
	for (int i = 0; i < 256; ++i)
	{
		m_pVSClassInstances[i] = NULL;
		m_pGSClassInstances[i] = NULL;
		m_pPSClassInstances[i] = NULL;
		m_pHSClassInstances[i] = NULL;
		m_pDSClassInstances[i] = NULL;
	}
}

DXTKStateSaver::~DXTKStateSaver()
{
	releaseSavedState();
}

HRESULT DXTKStateSaver::saveCurrentState(ID3D11DeviceContext* pContext)
{
	if (m_savedState) releaseSavedState();
	if (pContext == NULL) return E_INVALIDARG;

	ID3D11Device* pDevice;
	pContext->GetDevice(&pDevice);
	if (pDevice != NULL)
	{
		m_featureLevel = pDevice->GetFeatureLevel();
		pDevice->Release();
	}

	pContext->AddRef();
	m_pContext = pContext;
	m_pContext->IAGetPrimitiveTopology(&m_primitiveTopology);
	m_pContext->IAGetInputLayout(&m_pInputLayout);
	m_pContext->OMGetBlendState(&m_pBlendState, m_blendFactor, &m_sampleMask);
	m_pContext->OMGetDepthStencilState(&m_pDepthStencilState, &m_stencilRef);
	m_pContext->RSGetState(&m_pRasterizerState);
	m_numVSClassInstances = 256;
	m_pContext->VSGetShader(&m_pVS, m_pVSClassInstances, &m_numVSClassInstances);
	m_pContext->VSGetConstantBuffers(0, 1, &m_pVSConstantBuffer);
	m_numPSClassInstances = 256;
	m_pContext->PSGetShader(&m_pPS, m_pPSClassInstances, &m_numPSClassInstances);
	m_pContext->PSGetShaderResources(0, 1, &m_pPSSRV);
	pContext->PSGetSamplers(0, 1, &m_pSamplerState);

	if (m_featureLevel >= D3D_FEATURE_LEVEL_10_0)
	{
		m_numGSClassInstances = 256;
		m_pContext->GSGetShader(&m_pGS, m_pGSClassInstances, &m_numGSClassInstances);
		m_pContext->GSGetConstantBuffers(0, 1, &m_pGSConstantBuffer);

		m_pContext->GSGetShaderResources(0, 1, &m_pGSSRV);

		if (m_featureLevel >= D3D_FEATURE_LEVEL_11_0)
		{
			m_numHSClassInstances = 256;
			m_pContext->HSGetShader(&m_pHS, m_pHSClassInstances, &m_numHSClassInstances);

			m_numDSClassInstances = 256;
			m_pContext->DSGetShader(&m_pDS, m_pDSClassInstances, &m_numDSClassInstances);
		}
	}

	m_pContext->IAGetVertexBuffers(0, 1, &m_pVB, &m_vertexStride, &m_vertexOffset);
	m_pContext->IAGetIndexBuffer(&m_pIndexBuffer, &m_indexFormat, &m_indexOffset);
	m_savedState = true;

	return S_OK;
}

HRESULT DXTKStateSaver::restoreSavedState()
{
	if (!m_savedState) return E_FAIL;

	m_pContext->IASetPrimitiveTopology(m_primitiveTopology);
	m_pContext->IASetInputLayout(m_pInputLayout);

	m_pContext->OMSetBlendState(m_pBlendState, m_blendFactor, m_sampleMask);
	m_pContext->OMSetDepthStencilState(m_pDepthStencilState, m_stencilRef);

	m_pContext->RSSetState(m_pRasterizerState);

	m_pContext->VSSetShader(m_pVS, m_pVSClassInstances, m_numVSClassInstances);
	m_pContext->VSSetConstantBuffers(0, 1, &m_pVSConstantBuffer);

	m_pContext->PSSetShader(m_pPS, m_pPSClassInstances, m_numPSClassInstances);
	m_pContext->PSSetShaderResources(0, 1, &m_pPSSRV);
	m_pContext->PSSetSamplers(0, 1, &m_pSamplerState);

	if (m_featureLevel >= D3D_FEATURE_LEVEL_10_0)
	{
		m_pContext->GSSetShader(m_pGS, m_pGSClassInstances, m_numGSClassInstances);
		m_pContext->GSSetConstantBuffers(0, 1, &m_pGSConstantBuffer);

		m_pContext->GSSetShaderResources(0, 1, &m_pGSSRV);

		if (m_featureLevel >= D3D_FEATURE_LEVEL_11_0)
		{
			m_pContext->HSSetShader(m_pHS, m_pHSClassInstances, m_numHSClassInstances);

			m_pContext->DSSetShader(m_pDS, m_pDSClassInstances, m_numDSClassInstances);
		}
	}

	m_pContext->IASetVertexBuffers(0, 1, &m_pVB, &m_vertexStride, &m_vertexOffset);

	m_pContext->IASetIndexBuffer(m_pIndexBuffer, m_indexFormat, m_indexOffset);

	return S_OK;
}

void DXTKStateSaver::ZeroShaders(ID3D11DeviceContext* pContext)
{
	pContext->VSSetShader(NULL, NULL, 0);
	pContext->PSSetShader(NULL, NULL, 0);
	pContext->HSSetShader(NULL, NULL, 0);
	pContext->DSSetShader(NULL, NULL, 0);
	pContext->GSSetShader(NULL, NULL, 0);
}

void DXTKStateSaver::releaseSavedState()
{
	m_primitiveTopology = D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
	SAFE_RELEASE(m_pInputLayout);
	SAFE_RELEASE(m_pBlendState);
	for (int i = 0; i < 4; ++i)
		m_blendFactor[i] = 0.0f;
	m_sampleMask = 0xffffffff;
	SAFE_RELEASE(m_pDepthStencilState);
	m_stencilRef = 0;
	SAFE_RELEASE(m_pRasterizerState);
	SAFE_RELEASE(m_pPSSRV);
	SAFE_RELEASE(m_pSamplerState);
	SAFE_RELEASE(m_pVS);
	for (UINT i = 0; i < m_numVSClassInstances; ++i)
		SAFE_RELEASE(m_pVSClassInstances[i]);
	m_numVSClassInstances = 0;
	SAFE_RELEASE(m_pVSConstantBuffer);
	SAFE_RELEASE(m_pGS);
	for (UINT i = 0; i < m_numGSClassInstances; ++i)
		SAFE_RELEASE(m_pGSClassInstances[i]);
	m_numGSClassInstances = 0;
	SAFE_RELEASE(m_pGSConstantBuffer);
	SAFE_RELEASE(m_pGSSRV);
	SAFE_RELEASE(m_pPS);
	for (UINT i = 0; i < m_numPSClassInstances; ++i)
		SAFE_RELEASE(m_pPSClassInstances[i]);
	m_numPSClassInstances = 0;
	SAFE_RELEASE(m_pHS);
	for (UINT i = 0; i < m_numHSClassInstances; ++i)
		SAFE_RELEASE(m_pHSClassInstances[i]);
	m_numHSClassInstances = 0;
	SAFE_RELEASE(m_pDS);
	for (UINT i = 0; i < m_numDSClassInstances; ++i)
		SAFE_RELEASE(m_pDSClassInstances[i]);
	m_numDSClassInstances = 0;
	SAFE_RELEASE(m_pVB);
	m_vertexStride = 0;
	m_vertexOffset = 0;
	SAFE_RELEASE(m_pIndexBuffer);
	m_indexFormat = DXGI_FORMAT_UNKNOWN;
	m_indexOffset = 0;

	SAFE_RELEASE(m_pContext);
	m_featureLevel = D3D_FEATURE_LEVEL_11_0;

	m_savedState = false;
}

std::unique_ptr<DX11Renderer> DX11;

