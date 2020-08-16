#include "stdafx.h"
#include "skins.h"
#include "weapons.h"
#include "Global.h"
#include "menu_functions.h"

const std::vector<std::string> MENU_WEAPON_CATEGORIES{ "Melee", "Handguns", "Submachine Guns", "Assault Rifles", "Shotguns", "Sniper Rifles", "Heavy Weapons", "Thrown Weapons", "MK2 Weapons" };

const std::vector<std::string> CAPTIONS_MELEE{ "Knife", "Nightstick", "Hammer", "Baseball Bat", "Golf Club", "Crowbar", "Bottle", "Antique Dagger", "Hatchet", "Knuckle Duster" };
const std::vector<std::string> VALUES_MELEE{ "WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR", "WEAPON_BOTTLE", "WEAPON_DAGGER", "WEAPON_HATCHET", "WEAPON_KNUCKLE" }; //10
const std::vector<std::string> CAPTIONS_HANDGUN{ "Pistol", "Combat Pistol", "AP Pistol", "Pistol .50", "SNS Pistol", "Heavy Pistol", "Vintage Pistol", "Stun Gun", "Flare Gun", "Marksman Pistol" };
const std::vector<std::string> VALUES_HANDGUN{ "WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_SNSPISTOL", "WEAPON_HEAVYPISTOL", "WEAPON_VINTAGEPISTOL", "WEAPON_STUNGUN", "WEAPON_FLAREGUN", "WEAPON_MARKSMANPISTOL" }; //10
const std::vector<std::string> CAPTIONS_SUBMACHINE{ "Micro SMG", "SMG", "Assault SMG", "MG", "Combat MG", "Gusenberg Sweeper", "Combat PDW" };
const std::vector<std::string> VALUES_SUBMACHINE{ "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_GUSENBERG", "WEAPON_COMBATPDW" }; //6
const std::vector<std::string> CAPTIONS_ASSAULT{ "Assault Rifle", "Carbine Rifle", "Advanced Rifle", "Special Carbine", "Bullpup Rifle" };
const std::vector<std::string> VALUES_ASSAULT{ "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_SPECIALCARBINE", "WEAPON_BULLPUPRIFLE" }; //5
const std::vector<std::string> CAPTIONS_SHOTGUN{ "Pump Shotgun", "Sawed-Off Shotgun", "Bullpup Shotgun", "Assault Shotgun", "Musket", "Heavy Shotgun" };
const std::vector<std::string> VALUES_SHOTGUN{ "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_MUSKET", "WEAPON_HEAVYSHOTGUN" }; //6
const std::vector<std::string> CAPTIONS_SNIPER{ "Sniper Rifle", "Heavy Sniper", "Marksman Rifle" };
const std::vector<std::string> VALUES_SNIPER{ "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_MARKSMANRIFLE" }; //3
const std::vector<std::string> CAPTIONS_HEAVY{ "Grenade Launcher", "RPG", "Minigun", "Fireworks Launcher", "Railgun", "Homing Launcher" };
const std::vector<std::string> VALUES_HEAVY{ "WEAPON_GRENADELAUNCHER", "WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_FIREWORK", "WEAPON_RAILGUN", "WEAPON_HOMINGLAUNCHER" }; //6
const std::vector<std::string> CAPTIONS_THROWN{ "Grenade", "Sticky Bomb", "Proximity Mine", "Teargas", "Molotov", "Fire Extinguisher", "Jerry Can", "Snowball", "Flare" };
const std::vector<std::string> VALUES_THROWN{ "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_PROXMINE", "WEAPON_SMOKEGRENADE", "WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN", "WEAPON_SNOWBALL", "WEAPON_FLARE" }; //9

const std::vector<std::string> CAPTIONS_MK2{ "Pistol Mk II", "SMG Mk II", "Assault Rifle Mk II", "Carbine Rifle Mk II", "Combat MG Mk II", "Heavy Sniper Mk II" };
const std::vector<std::string> VALUES_MK2{ "WEAPON_PISTOL_MK2", "WEAPON_SMG_MK2", "WEAPON_ASSAULTRIFLE_MK2", "WEAPON_CARBINERIFLE_MK2", "WEAPON_COMBATMG_MK2", "WEAPON_HEAVYSNIPER_MK2" }; //9


const std::vector<std::string> CAPTIONS_ATTACH_MK2_PISTOL = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Hollowpoint Clip","FMJ Clip","Rail","Flashlight","Suppressor","Compensator","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_PISTOL = { "COMPONENT_PISTOL_MK2_CLIP_01","COMPONENT_PISTOL_MK2_CLIP_02","COMPONENT_PISTOL_MK2_CLIP_TRACER","COMPONENT_PISTOL_MK2_CLIP_INCENDIARY","COMPONENT_PISTOL_MK2_CLIP_HOLLOWPOINT","COMPONENT_PISTOL_MK2_CLIP_FMJ","COMPONENT_AT_PI_RAIL","COMPONENT_AT_PI_FLSH_02","COMPONENT_AT_PI_SUPP_02","COMPONENT_AT_PI_COMP","COMPONENT_PISTOL_MK2_CAMO","COMPONENT_PISTOL_MK2_CAMO_02","COMPONENT_PISTOL_MK2_CAMO_03","COMPONENT_PISTOL_MK2_CAMO_04","COMPONENT_PISTOL_MK2_CAMO_05","COMPONENT_PISTOL_MK2_CAMO_06","COMPONENT_PISTOL_MK2_CAMO_07","COMPONENT_PISTOL_MK2_CAMO_08","COMPONENT_PISTOL_MK2_CAMO_09","COMPONENT_PISTOL_MK2_CAMO_10","COMPONENT_PISTOL_MK2_CAMO_IND_01" };

const std::vector<std::string> CAPTIONS_ATTACH_MK2_SMG = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Hollowpoint Clip","FMJ Clip","Flashlight","Red Dot","Mini Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_SMG = { "COMPONENT_SMG_MK2_CLIP_01","COMPONENT_SMG_MK2_CLIP_02","COMPONENT_SMG_MK2_CLIP_TRACER","COMPONENT_SMG_MK2_CLIP_INCENDIARY","COMPONENT_SMG_MK2_CLIP_HOLLOWPOINT","COMPONENT_SMG_MK2_CLIP_FMJ","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS_SMG","COMPONENT_AT_SCOPE_MACRO_02_SMG_MK2","COMPONENT_AT_SCOPE_SMALL_SMG_MK2","COMPONENT_AT_PI_SUPP","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_SB_BARREL_01","COMPONENT_AT_SB_BARREL_02","COMPONENT_SMG_MK2_CAMO","COMPONENT_SMG_MK2_CAMO_02","COMPONENT_SMG_MK2_CAMO_03","COMPONENT_SMG_MK2_CAMO_04","COMPONENT_SMG_MK2_CAMO_05","COMPONENT_SMG_MK2_CAMO_06","COMPONENT_SMG_MK2_CAMO_07","COMPONENT_SMG_MK2_CAMO_08","COMPONENT_SMG_MK2_CAMO_09","COMPONENT_SMG_MK2_CAMO_10","COMPONENT_SMG_MK2_CAMO_IND_01" };

const std::vector<std::string> CAPTIONS_ATTACH_MK2_ASSAULT = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Flashlight","Red Dot","Small Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_ASSAULT = { "COMPONENT_ASSAULTRIFLE_MK2_CLIP_01","COMPONENT_ASSAULTRIFLE_MK2_CLIP_02","COMPONENT_ASSAULTRIFLE_MK2_CLIP_TRACER","COMPONENT_ASSAULTRIFLE_MK2_CLIP_INCENDIARY","COMPONENT_ASSAULTRIFLE_MK2_CLIP_ARMORPIERCING","COMPONENT_ASSAULTRIFLE_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_MACRO_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_AR_SUPP_02","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_AR_BARREL_01","COMPONENT_AT_AR_BARREL_02","COMPONENT_ASSAULTRIFLE_MK2_CAMO","COMPONENT_ASSAULTRIFLE_MK2_CAMO_02","COMPONENT_ASSAULTRIFLE_MK2_CAMO_03","COMPONENT_ASSAULTRIFLE_MK2_CAMO_04","COMPONENT_ASSAULTRIFLE_MK2_CAMO_05","COMPONENT_ASSAULTRIFLE_MK2_CAMO_06","COMPONENT_ASSAULTRIFLE_MK2_CAMO_07","COMPONENT_ASSAULTRIFLE_MK2_CAMO_08","COMPONENT_ASSAULTRIFLE_MK2_CAMO_09","COMPONENT_ASSAULTRIFLE_MK2_CAMO_10","COMPONENT_ASSAULTRIFLE_MK2_CAMO_IND_01" };

const std::vector<std::string> CAPTIONS_ATTACH_MK2_CARBINE = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Flashlight","Red Dot","Small Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_CARBINE = { "COMPONENT_CARBINERIFLE_MK2_CLIP_01","COMPONENT_CARBINERIFLE_MK2_CLIP_02","COMPONENT_CARBINERIFLE_MK2_CLIP_TRACER","COMPONENT_CARBINERIFLE_MK2_CLIP_INCENDIARY","COMPONENT_CARBINERIFLE_MK2_CLIP_ARMORPIERCING","COMPONENT_CARBINERIFLE_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_MACRO_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_AR_SUPP","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_CR_BARREL_01","COMPONENT_AT_CR_BARREL_02","COMPONENT_CARBINERIFLE_MK2_CAMO","COMPONENT_CARBINERIFLE_MK2_CAMO_02","COMPONENT_CARBINERIFLE_MK2_CAMO_03","COMPONENT_CARBINERIFLE_MK2_CAMO_04","COMPONENT_CARBINERIFLE_MK2_CAMO_05","COMPONENT_CARBINERIFLE_MK2_CAMO_06","COMPONENT_CARBINERIFLE_MK2_CAMO_07","COMPONENT_CARBINERIFLE_MK2_CAMO_08","COMPONENT_CARBINERIFLE_MK2_CAMO_09","COMPONENT_CARBINERIFLE_MK2_CAMO_10","COMPONENT_CARBINERIFLE_MK2_CAMO_IND_01" };

const std::vector<std::string> CAPTIONS_ATTACH_MK2_MG = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Red Dot","Small Scope","Scope","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_MG = { "COMPONENT_COMBATMG_MK2_CLIP_01","COMPONENT_COMBATMG_MK2_CLIP_02","COMPONENT_COMBATMG_MK2_CLIP_TRACER","COMPONENT_COMBATMG_MK2_CLIP_INCENDIARY","COMPONENT_COMBATMG_MK2_CLIP_ARMORPIERCING","COMPONENT_COMBATMG_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_SMALL_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_MG_BARREL_01","COMPONENT_AT_MG_BARREL_02","COMPONENT_COMBATMG_MK2_CAMO","COMPONENT_COMBATMG_MK2_CAMO_02","COMPONENT_COMBATMG_MK2_CAMO_03","COMPONENT_COMBATMG_MK2_CAMO_04","COMPONENT_COMBATMG_MK2_CAMO_05","COMPONENT_COMBATMG_MK2_CAMO_06","COMPONENT_COMBATMG_MK2_CAMO_07","COMPONENT_COMBATMG_MK2_CAMO_08","COMPONENT_COMBATMG_MK2_CAMO_09","COMPONENT_COMBATMG_MK2_CAMO_10","COMPONENT_COMBATMG_MK2_CAMO_IND_01" };

const std::vector<std::string> CAPTIONS_ATTACH_MK2_SNIPER = { "Normal Clip","Extended Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Explosive Clip","Large Scope","Max Scope","Nightvision Scope","Thermal Scope","Suppressor","Muzzle8","Muzzle9","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
const std::vector<std::string> VALUES_ATTACH_MK2_SNIPER = { "COMPONENT_HEAVYSNIPER_MK2_CLIP_01","COMPONENT_HEAVYSNIPER_MK2_CLIP_02","COMPONENT_HEAVYSNIPER_MK2_CLIP_INCENDIARY","COMPONENT_HEAVYSNIPER_MK2_CLIP_ARMORPIERCING","COMPONENT_HEAVYSNIPER_MK2_CLIP_FMJ","COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIVE","COMPONENT_AT_SCOPE_LARGE_MK2","COMPONENT_AT_SCOPE_MAX","COMPONENT_AT_SCOPE_NV","COMPONENT_AT_SCOPE_THERMAL","COMPONENT_AT_SR_SUPP_03","COMPONENT_AT_MUZZLE_08","COMPONENT_AT_MUZZLE_09","COMPONENT_AT_SR_BARREL_01","COMPONENT_AT_SR_BARREL_02","COMPONENT_HEAVYSNIPER_MK2_CAMO","COMPONENT_HEAVYSNIPER_MK2_CAMO_02","COMPONENT_HEAVYSNIPER_MK2_CAMO_03","COMPONENT_HEAVYSNIPER_MK2_CAMO_04","COMPONENT_HEAVYSNIPER_MK2_CAMO_05","COMPONENT_HEAVYSNIPER_MK2_CAMO_06","COMPONENT_HEAVYSNIPER_MK2_CAMO_07","COMPONENT_HEAVYSNIPER_MK2_CAMO_08","COMPONENT_HEAVYSNIPER_MK2_CAMO_09","COMPONENT_HEAVYSNIPER_MK2_CAMO_10","COMPONENT_HEAVYSNIPER_MK2_CAMO_IND_01" };






const std::vector<std::string> VOV_WEAPON_CAPTIONS[] = { CAPTIONS_MELEE, CAPTIONS_HANDGUN, CAPTIONS_SUBMACHINE, CAPTIONS_ASSAULT, CAPTIONS_SHOTGUN, CAPTIONS_SNIPER, CAPTIONS_HEAVY, CAPTIONS_THROWN, CAPTIONS_MK2 };
const std::vector<std::string> VOV_WEAPON_VALUES[] = { VALUES_MELEE, VALUES_HANDGUN, VALUES_SUBMACHINE, VALUES_ASSAULT, VALUES_SHOTGUN, VALUES_SNIPER, VALUES_HEAVY, VALUES_THROWN, VALUES_MK2 };

//Weapon tints
const std::vector<std::string> CAPTIONS_TINT{ "Normal", "Green", "Gold", "Pink", "Army", "LSPD", "Orange", "Platinum" };
const std::vector<int> VALUES_TINT{ 0, 1, 2, 3, 4, 5, 6, 7 };

//Pistols
const std::vector<std::string> CAPTIONS_ATTACH_PISTOL{ "Extended Magazine", "Suppressor", "Flashlight", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_PISTOL{ "COMPONENT_PISTOL_CLIP_02", "COMPONENT_AT_PI_SUPP_02", "COMPONENT_AT_PI_FLSH", "COMPONENT_PISTOL_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_SNSPISTOL{ "Extended Magazine" };
const std::vector<std::string> VALUES_ATTACH_SNSPISTOL{ "COMPONENT_SNSPISTOL_CLIP_02" };

const std::vector<std::string> CAPTIONS_ATTACH_HEAVYPISTOL{ "Extended Magazine", "Suppressor", "Flashlight", "Etched Wood Grip Finish" };
const std::vector<std::string> VALUES_ATTACH_HEAVYPISTOL{ "COMPONENT_HEAVYPISTOL_CLIP_02", "COMPONENT_AT_PI_SUPP", "COMPONENT_AT_PI_FLSH", "COMPONENT_HEAVYPISTOL_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_COMBATPISTOL{ "Extended Magazine", "Suppressor", "Flashlight" };
const std::vector<std::string> VALUES_ATTACH_COMBATPISTOL{ "COMPONENT_COMBATPISTOL_CLIP_02", "COMPONENT_AT_PI_SUPP", "COMPONENT_AT_PI_FLSH" };

const std::vector<std::string> CAPTIONS_ATTACH_APPISTOL{ "Extended Magazine", "Suppressor", "Flashlight", "Gilded Gun Metal Finish" };
const std::vector<std::string> VALUES_ATTACH_APPISTOL{ "COMPONENT_APPISTOL_CLIP_02", "COMPONENT_AT_PI_SUPP", "COMPONENT_AT_PI_FLSH", "COMPONENT_APPISTOL_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_PISTOL50{ "Extended Magazine", "Suppressor", "Flashlight", "Platinum Pearl Deluxe Finish" };
const std::vector<std::string> VALUES_ATTACH_PISTOL50{ "COMPONENT_PISTOL50_CLIP_02", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_PI_FLSH", "COMPONENT_PISTOL50_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_VINTAGEPISTOL{ "Extended Magazine", "Suppressor" };
const std::vector<std::string> VALUES_ATTACH_VINTAGEPISTOL{ "COMPONENT_VINTAGEPISTOL_CLIP_02", "COMPONENT_AT_PI_SUPP" };

//SMGs
const std::vector<std::string> CAPTIONS_ATTACH_MICROSMG{ "Extended Magazine", "Scope", "Suppressor", "Flashlight", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_MICROSMG{ "COMPONENT_MICROSMG_CLIP_02", "COMPONENT_AT_SCOPE_MACRO", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_PI_FLSH", "COMPONENT_MICROSMG_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_SMG{ "Extended Magazine", "Scope", "Suppressor", "Flashlight", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_SMG{ "COMPONENT_SMG_CLIP_02", "COMPONENT_AT_SCOPE_MACRO_02", "COMPONENT_AT_PI_SUPP", "COMPONENT_AT_AR_FLSH", "COMPONENT_SMG_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTSMG{ "Extended Magazine", "Scope", "Suppressor", "Flashlight" };
const std::vector<std::string> VALUES_ATTACH_ASSAULTSMG{ "COMPONENT_ASSAULTSMG_CLIP_02", "COMPONENT_AT_SCOPE_MACRO", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_AR_FLSH" };

//Rifles
const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTRIFLE{ "Extended Magazine", "Scope", "Suppressor", "Grip", "Flashlight", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_ASSAULTRIFLE{ "COMPONENT_ASSAULTRIFLE_CLIP_02", "COMPONENT_AT_SCOPE_MACRO", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_AR_AFGRIP", "COMPONENT_AT_AR_FLSH", "COMPONENT_ASSAULTRIFLE_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_CARBINERIFLE{ "Extended Magazine", "Scope", "Suppressor", "Grip", "Flashlight", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_CARBINERIFLE{ "COMPONENT_CARBINERIFLE_CLIP_02", "COMPONENT_AT_SCOPE_MEDIUM", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_AFGRIP", "COMPONENT_AT_AR_FLSH", "COMPONENT_CARBINERIFLE_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_ADVANCEDRIFLE{ "Extended Magazine", "Scope", "Suppressor", "Flashlight", "Gilded Gun Metal Finish" };
const std::vector<std::string> VALUES_ATTACH_ADVANCEDRIFLE{ "COMPONENT_ADVANCEDRIFLE_CLIP_02", "COMPONENT_AT_SCOPE_SMALL", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_FLSH", "COMPONENT_ADVANCEDRIFLE_VARMOD_LUXE" };

//Machine Guns
const std::vector<std::string> CAPTIONS_ATTACH_MG{ "Extended Magazine", "Scope" };
const std::vector<std::string> VALUES_ATTACH_MG{ "COMPONENT_MG_CLIP_02", "COMPONENT_AT_SCOPE_SMALL_02" };

const std::vector<std::string> CAPTIONS_ATTACH_COMBATMG{ "Extended Magazine", "Scope", "Grip" };
const std::vector<std::string> VALUES_ATTACH_COMBATMG{ "COMPONENT_COMBATMG_CLIP_02", "COMPONENT_AT_SCOPE_MEDIUM", "COMPONENT_AT_AR_AFGRIP" };

//Shotguns

const std::vector<std::string> CAPTIONS_ATTACH_SAWNOFF{ "Gilded Gun Metal Finish" };
const std::vector<std::string> VALUES_ATTACH_SAWNOFF{ "COMPONENT_SAWNOFFSHOTGUN_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_PUMPSHOTGUN{ "Suppressor", "Flashlight" };
const std::vector<std::string> VALUES_ATTACH_PUMPSHOTGUN{ "COMPONENT_AT_SR_SUPP", "COMPONENT_AT_AR_FLSH" };

const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTSHOTGUN{ "Extended Magazine", "Suppressor", "Grip" };
const std::vector<std::string> VALUES_ATTACH_ASSAULTSHOTGUN{ "COMPONENT_ASSAULTSHOTGUN_CLIP_02", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_AFGRIP" };

const std::vector<std::string> CAPTIONS_ATTACH_BULLPUPSHOTGUN{ "Flashlight", "Suppressor", "Grip" };
const std::vector<std::string> VALUES_ATTACH_BULLPUPSHOTGUN{ "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_AR_AFGRIP" };

//Sniper Rifles
const std::vector<std::string> CAPTIONS_ATTACH_SNIPERRIFLE{ "Advanced Scope", "Suppressor", "Etched Wood Grip Finish" };
const std::vector<std::string> VALUES_ATTACH_SNIPERRIFLE{ "COMPONENT_AT_SCOPE_MAX", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_SNIPERRIFLE_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_HEAVYSNIPER{ "Normal Scope" };
const std::vector<std::string> VALUES_ATTACH_HEAVYSNIPER{ "COMPONENT_AT_SCOPE_LARGE" };

//Heavy Weapons
const std::vector<std::string> CAPTIONS_ATTACH_GRENADELAUNCHER{ "Scope", "Flashlight", "Grip" };
const std::vector<std::string> VALUES_ATTACH_GRENADELAUNCHER{ "COMPONENT_AT_SCOPE_SMALL", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_AR_AFGRIP" };

//DLC Weapons
const std::vector<std::string> CAPTIONS_ATTACH_BULLPUPRIFLE{ "Extended Magazine", "Flashlight", "Scope", "Suppressor", "Grip" };
const std::vector<std::string> VALUES_ATTACH_BULLPUPRIFLE{ "COMPONENT_BULLPUPRIFLE_CLIP_02", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_SCOPE_SMALL", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_AFGRIP" };

const std::vector<std::string> CAPTIONS_ATTACH_GUSENBERG{ "Extended Magazine" };
const std::vector<std::string> VALUES_ATTACH_GUSENBERG{ "COMPONENT_GUSENBERG_CLIP_02" };

const std::vector<std::string> CAPTIONS_ATTACH_HEAVYSHOTGUN{ "Extended Magazine", "Flashlight", "Suppressor", "Grip" };
const std::vector<std::string> VALUES_ATTACH_HEAVYSHOTGUN{ "COMPONENT_HEAVYSHOTGUN_CLIP_02", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_AR_AFGRIP" };

const std::vector<std::string> CAPTIONS_ATTACH_MARKSMANRIFLE{ "Extended Magazine", "Flashlight", "Suppressor", "Grip", "Yusuf Amir Luxury Finish" };
const std::vector<std::string> VALUES_ATTACH_MARKSMANRIFLE{ "COMPONENT_MARKSMANRIFLE_CLIP_02", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_AR_SUPP", "COMPONENT_AT_AR_AFGRIP", "COMPONENT_MARKSMANRIFLE_VARMOD_LUXE" };

const std::vector<std::string> CAPTIONS_ATTACH_SPECIALCARBINE{ "Extended Magazine", "Flashlight", "Scope", "Suppressor", "Grip" };
const std::vector<std::string> VALUES_ATTACH_SPECIALCARBINE{ "COMPONENT_SPECIALCARBINE_CLIP_02", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_SCOPE_MEDIUM", "COMPONENT_AT_AR_SUPP_02", "COMPONENT_AT_AR_AFGRIP" };

const std::vector<std::string> CAPTIONS_ATTACH_COMBATPDW{ "Extended Magazine", "Flashlight", "Scope", "Grip" };
const std::vector<std::string> VALUES_ATTACH_COMBATPDW{ "COMPONENT_COMBATPDW_CLIP_02", "COMPONENT_AT_AR_FLSH", "COMPONENT_AT_SCOPE_SMALL", "COMPONENT_AT_AR_AFGRIP" };

const std::vector<std::string> CAPTIONS_ATTACH_KNUCKLES{ "Default", "Pimp", "Ballas", "Dollars", "Diamond", "Hate", "Love", "Player", "King", "Vagos" };
const std::vector<std::string> VALUES_ATTACH_KNUCKLES{ "COMPONENT_KNUCKLE_VARMOD_BASE", "COMPONENT_KNUCKLE_VARMOD_PIMP", "COMPONENT_KNUCKLE_VARMOD_BALLAS", "COMPONENT_KNUCKLE_VARMOD_DOLLAR", "COMPONENT_KNUCKLE_VARMOD_DIAMOND", "COMPONENT_KNUCKLE_VARMOD_HATE", "COMPONENT_KNUCKLE_VARMOD_LOVE", "COMPONENT_KNUCKLE_VARMOD_PLAYER", "COMPONENT_KNUCKLE_VARMOD_KING", "COMPONENT_KNUCKLE_VARMOD_VAGOS" };

//Tintable weapons list
const std::vector<std::string> WEAPONTYPES_TINT{ "WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_SNSPISTOL", "WEAPON_HEAVYPISTOL", "WEAPON_VINTAGEPISTOL", "WEAPON_STUNGUN", "WEAPON_FLAREGUN", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_GUSENBERG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_SPECIALCARBINE", "WEAPON_BULLPUPRIFLE", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_MUSKET", "WEAPON_HEAVYSHOTGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_MARKSMANRIFLE", "WEAPON_GRENADELAUNCHER", "WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_FIREWORK", "WEAPON_RAILGUN", "WEAPON_HOMINGLAUNCHER", "WEAPON_COMBATPDW", "WEAPON_MARKSMANPISTOL", "WEAPON_PISTOL_MK2", "WEAPON_SMG_MK2", "WEAPON_ASSAULTRIFLE_MK2", "WEAPON_CARBINERIFLE_MK2", "WEAPON_COMBATMG_MK2", "WEAPON_HEAVYSNIPER_MK2" };

//Moddable weapons list
const std::vector<std::string> WEAPONTYPES_MOD{ "WEAPON_PISTOL", "WEAPON_HEAVYPISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG", "WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG", "WEAPON_COMBATMG", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_PUMPSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_BULLPUPRIFLE", "WEAPON_GUSENBERG", "WEAPON_HEAVYSHOTGUN", "WEAPON_MARKSMANRIFLE", "WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_VINTAGEPISTOL", "WEAPON_COMBATPDW", "WEAPON_PISTOL_MK2", "WEAPON_SMG_MK2", "WEAPON_ASSAULTRIFLE_MK2", "WEAPON_CARBINERIFLE_MK2", "WEAPON_COMBATMG_MK2", "WEAPON_HEAVYSNIPER_MK2" };

const std::vector<std::string> VOV_WEAPONMOD_CAPTIONS[] = { CAPTIONS_ATTACH_PISTOL, CAPTIONS_ATTACH_HEAVYPISTOL, CAPTIONS_ATTACH_COMBATPISTOL, CAPTIONS_ATTACH_APPISTOL, CAPTIONS_ATTACH_PISTOL50, CAPTIONS_ATTACH_MICROSMG, CAPTIONS_ATTACH_SMG, CAPTIONS_ATTACH_ASSAULTSMG, CAPTIONS_ATTACH_ASSAULTRIFLE, CAPTIONS_ATTACH_CARBINERIFLE, CAPTIONS_ATTACH_ADVANCEDRIFLE, CAPTIONS_ATTACH_MG, CAPTIONS_ATTACH_COMBATMG, CAPTIONS_ATTACH_SAWNOFF, CAPTIONS_ATTACH_PUMPSHOTGUN, CAPTIONS_ATTACH_ASSAULTSHOTGUN, CAPTIONS_ATTACH_BULLPUPSHOTGUN, CAPTIONS_ATTACH_SNIPERRIFLE, CAPTIONS_ATTACH_HEAVYSNIPER, CAPTIONS_ATTACH_GRENADELAUNCHER, CAPTIONS_ATTACH_BULLPUPRIFLE, CAPTIONS_ATTACH_GUSENBERG, CAPTIONS_ATTACH_HEAVYSHOTGUN, CAPTIONS_ATTACH_MARKSMANRIFLE, CAPTIONS_ATTACH_SNSPISTOL, CAPTIONS_ATTACH_SPECIALCARBINE, CAPTIONS_ATTACH_VINTAGEPISTOL, CAPTIONS_ATTACH_COMBATPDW, CAPTIONS_ATTACH_MK2_PISTOL, CAPTIONS_ATTACH_MK2_SMG, CAPTIONS_ATTACH_MK2_ASSAULT, CAPTIONS_ATTACH_MK2_CARBINE, CAPTIONS_ATTACH_MK2_MG, CAPTIONS_ATTACH_MK2_SNIPER };
const std::vector<std::string> VOV_WEAPONMOD_VALUES[] = { VALUES_ATTACH_PISTOL, VALUES_ATTACH_HEAVYPISTOL, VALUES_ATTACH_COMBATPISTOL, VALUES_ATTACH_APPISTOL, VALUES_ATTACH_PISTOL50, VALUES_ATTACH_MICROSMG, VALUES_ATTACH_SMG, VALUES_ATTACH_ASSAULTSMG, VALUES_ATTACH_ASSAULTRIFLE, VALUES_ATTACH_CARBINERIFLE, VALUES_ATTACH_ADVANCEDRIFLE, VALUES_ATTACH_MG, VALUES_ATTACH_COMBATMG, VALUES_ATTACH_SAWNOFF, VALUES_ATTACH_PUMPSHOTGUN, VALUES_ATTACH_ASSAULTSHOTGUN, VALUES_ATTACH_BULLPUPSHOTGUN, VALUES_ATTACH_SNIPERRIFLE, VALUES_ATTACH_HEAVYSNIPER, VALUES_ATTACH_GRENADELAUNCHER, VALUES_ATTACH_BULLPUPRIFLE, VALUES_ATTACH_GUSENBERG, VALUES_ATTACH_HEAVYSHOTGUN, VALUES_ATTACH_MARKSMANRIFLE, VALUES_ATTACH_SNSPISTOL, VALUES_ATTACH_SPECIALCARBINE, VALUES_ATTACH_VINTAGEPISTOL, VALUES_ATTACH_COMBATPDW, VALUES_ATTACH_MK2_PISTOL, VALUES_ATTACH_MK2_SMG, VALUES_ATTACH_MK2_ASSAULT, VALUES_ATTACH_MK2_CARBINE, VALUES_ATTACH_MK2_MG, VALUES_ATTACH_MK2_SNIPER };

//Weapon damage modifier list
const std::vector<std::string> WEAP_DMG_CAPTIONS{ "1.0x", "1.5x", "2.0x", "5.0x", "10.0x", "50.0x", "100.0x", "1000.0x" };
const std::vector<float> WEAP_DMG_FLOAT{ 1.0, 1.5, 2.0, 5.0, 10.0, 50.0, 100.0, 1000.0 };

const int PARACHUTE_ID = 0xFBAB5776;

const int TOTAL_WEAPONS_COUNT = 54;
const int TOTAL_WEAPONS_SLOTS = 57;
const int MAX_MOD_SLOTS = 15;

int activeLineIndexWeapon = 0;
int lastSelectedWeaponCategory = 0;
int lastSelectedWeapon = 0;

int weapDmgModIndex = 0;

bool featureWeaponInfiniteAmmo = false;
bool featureWeaponInfiniteParachutes = false;
bool featureWeaponNoReload = false;
bool featureWeaponFireAmmo = false;
bool featureWeaponExplosiveAmmo = false;
bool featureWeaponExplosiveMelee = false;
bool featureWeaponVehRockets = false;

DWORD featureWeaponVehShootLastTime = 0;

int saved_weapon_model[TOTAL_WEAPONS_SLOTS];
int saved_ammo[TOTAL_WEAPONS_SLOTS];
int saved_clip_ammo[TOTAL_WEAPONS_SLOTS];
int saved_weapon_tints[TOTAL_WEAPONS_SLOTS];
bool saved_weapon_mods[TOTAL_WEAPONS_SLOTS][MAX_MOD_SLOTS];
bool saved_parachute = false;
int saved_armour = 0;

bool redrawWeaponMenuAfterEquipChange = false;

void onchange_knuckle_appearance(int value)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int weapHash = GAMEPLAY::GET_HASH_KEY("WEAPON_KNUCKLE");

	int i = 0;

	Hash hashToApply = 0;
	for each (std::string componentName in VALUES_ATTACH_KNUCKLES)
	{
		DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

		WEAPON::REMOVE_WEAPON_COMPONENT_FROM_PED(playerPed, weapHash, componentHash);

		if (i == value)
		{
			hashToApply = componentHash;
		}

		i++;
	}

	if (hashToApply != 0)
	{
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(playerPed, weapHash, hashToApply);
	}
}

int get_current_knuckle_appearance()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int weapHash = GAMEPLAY::GET_HASH_KEY("WEAPON_KNUCKLE");

	int i = 0;
	for each (std::string componentName in VALUES_ATTACH_KNUCKLES)
	{
		if (i == 0)
		{
			continue;
		}

		DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

		if (WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(playerPed, weapHash, componentHash))
		{
			return i;
		}

		i++;
	}

	return 0;
}

bool process_individual_weapon_menu(int weaponIndex)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	int originalWeapon = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);

	lastSelectedWeapon = weaponIndex;

	std::string caption = VOV_WEAPON_CAPTIONS[lastSelectedWeaponCategory].at(weaponIndex);
	if (caption.compare("Pistol .50") == 0)
	{
		caption = "Pistol"; //menu title can't handle symbols
	}

	std::string value = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(weaponIndex);
	std::vector<MenuItem<int>*> menuItems;

	std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(weaponIndex);
	char *weaponChar = (char*)weaponValue.c_str();
	int thisWeaponHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
	bool isEquipped = (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY(weaponChar), 0) ? true : false);

	WEAPON::SET_CURRENT_PED_WEAPON(playerPed, thisWeaponHash, true);

	FunctionDrivenToggleMenuItem<int> *equipItem = new FunctionDrivenToggleMenuItem<int>();
	std::stringstream ss;
	ss << "Equip " << caption << "?";
	equipItem->caption = ss.str();
	equipItem->value = 1;
	equipItem->getter_call = is_weapon_equipped;
	equipItem->setter_call = set_weapon_equipped;
	equipItem->extra_arguments.push_back(lastSelectedWeaponCategory);
	equipItem->extra_arguments.push_back(weaponIndex);
	menuItems.push_back(equipItem);

	if (isEquipped)
	{

		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
		char *weaponChar = (char*)weaponValue.c_str();
		int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
		int maxClipAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weapHash, false);

		/*if (maxClipAmmo > 0)
		{
			MenuItem<int> *giveClipItem = new MenuItem<int>();
			giveClipItem->caption = "Give Clip";
			giveClipItem->value = 2;
			giveClipItem->isLeaf = true;
			giveClipItem->onConfirmFunction = give_weapon_clip;
			menuItems.push_back(giveClipItem);

			MenuItem<int> *fillAmmoItem = new MenuItem<int>();
			fillAmmoItem->caption = "Fill Ammo";
			fillAmmoItem->value = 3;
			fillAmmoItem->isLeaf = true;
			fillAmmoItem->onConfirmFunction = fill_weapon_ammo;
			menuItems.push_back(fillAmmoItem);
		}*/

		int moddableIndex = -1;
		for (int i = 0; i < WEAPONTYPES_MOD.size(); i++)
		{
			if (weaponValue.compare(WEAPONTYPES_MOD.at(i)) == 0)
			{
				moddableIndex = i;
				break;
			}
		}

		if (moddableIndex != -1)
		{
			std::vector<std::string> modCaptions = VOV_WEAPONMOD_CAPTIONS[moddableIndex];
			for (int i = 0; i < modCaptions.size(); i++)
			{
				FunctionDrivenToggleMenuItem<int> *item = new FunctionDrivenToggleMenuItem<int>();
				item->caption = modCaptions.at(i);
				item->getter_call = is_weaponmod_equipped;
				item->setter_call = set_weaponmod_equipped;
				item->extra_arguments.push_back(lastSelectedWeaponCategory);
				item->extra_arguments.push_back(weaponIndex);
				item->extra_arguments.push_back(moddableIndex);
				item->extra_arguments.push_back(i);
				menuItems.push_back(item);
			}
		}

		/*if (strcmp(weaponChar, "WEAPON_KNUCKLE") == 0)
		{
			SelectFromListMenuItem *listItem = new SelectFromListMenuItem(CAPTIONS_ATTACH_KNUCKLES, onchange_knuckle_appearance);
			listItem->wrap = false;
			listItem->caption = "Skin Choice";
			listItem->value = get_current_knuckle_appearance();
			menuItems.push_back(listItem);
		}

		int tintableIndex = -1;
		for (int i = 0; i < WEAPONTYPES_TINT.size(); i++)
		{
			if (weaponValue.compare(WEAPONTYPES_TINT.at(i)) == 0)
			{
				tintableIndex = i;
				break;
			}
		}

		if (tintableIndex != -1)
		{
			MenuItem<int> *tintItem = new MenuItem<int>();
			tintItem->caption = "Weapon Tints";
			tintItem->value = 4;
			tintItem->isLeaf = false;
			tintItem->onConfirmFunction = onconfirm_open_tint_menu;
			menuItems.push_back(tintItem);
		}*/
	}

	draw_generic_menu<int>(menuItems, 0, caption, NULL, NULL, NULL, weapon_reequip_interrupt);

	int unarmed = GAMEPLAY::GET_HASH_KEY("WEAPON_UNARMED");
	if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, originalWeapon, 0))
	{
		if (originalWeapon != unarmed)
		{
			WEAPON::SET_CURRENT_PED_WEAPON(playerPed, originalWeapon, true);
		}
	}
	else
	{
		WEAPON::SET_CURRENT_PED_WEAPON(playerPed, unarmed, true);
	}

	return false;
}

bool weapon_reequip_interrupt()
{
	return redrawWeaponMenuAfterEquipChange;
}

bool onconfirm_weapon_in_category(MenuItem<int> choice)
{
	do
	{
		redrawWeaponMenuAfterEquipChange = false;
		process_individual_weapon_menu(choice.value);
	} while (redrawWeaponMenuAfterEquipChange);

	return false;
}

bool process_weapons_in_category_menu(int category)
{
	lastSelectedWeaponCategory = category;
	std::vector<MenuItem<int>*> menuItems;

	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int weaponSelectionIndex = 0;
	int current = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);

	for (int i = 0; i < VOV_WEAPON_CAPTIONS[category].size(); i++)
	{
		MenuItem<int> *item = new MenuItem<int>();
		item->caption = VOV_WEAPON_CAPTIONS[category].at(i);

		const char* value = VOV_WEAPON_VALUES[category].at(i).c_str();
		if (weaponSelectionIndex == 0 && GAMEPLAY::GET_HASH_KEY((char*)value) == current)
		{
			weaponSelectionIndex = i;
		}

		item->value = i;
		item->isLeaf = false;
		menuItems.push_back(item);
	}

	return draw_generic_menu<int>(menuItems, &weaponSelectionIndex, MENU_WEAPON_CATEGORIES[category], onconfirm_weapon_in_category, NULL, NULL);
}

bool onconfirm_weaponlist_menu(MenuItem<int> choice)
{
	process_weapons_in_category_menu(choice.value);
	return false;
}

bool process_weaponlist_menu()
{
	std::vector<MenuItem<int>*> menuItems;

	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int weaponSelectionIndex = 0;
	int current = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);

	for (int i = 0; i < MENU_WEAPON_CATEGORIES.size(); i++)
	{
		MenuItem<int> *item = new MenuItem<int>();
		item->caption = MENU_WEAPON_CATEGORIES[i];
		item->value = i;
		item->isLeaf = false;
		menuItems.push_back(item);

		if (weaponSelectionIndex == 0)
		{
			for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
			{
				const char* value = VOV_WEAPON_VALUES[i].at(j).c_str();
				if (GAMEPLAY::GET_HASH_KEY((char*)value) == current)
				{
					weaponSelectionIndex = i;
					break;
				}
			}
		}
	}

	return draw_generic_menu<int>(menuItems, &weaponSelectionIndex, "Weapon Categories", onconfirm_weaponlist_menu, NULL, NULL);
}

bool do_give_weapon(std::string modelName)
{
	// common variables
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	if (bPlayerExists) { WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, GAMEPLAY::GET_HASH_KEY((char *)modelName.c_str()), 1000, 0); return true; }
	else { return false; }
}

bool onconfirm_weapon_menu(MenuItem<int> choice)
{
	// common variables
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	switch (activeLineIndexWeapon)
	{
	case 0:
		for (int i = 0; i < sizeof(VOV_WEAPON_VALUES) / sizeof(VOV_WEAPON_VALUES[0]); i++)
		{
			for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
			{
				char *weaponName = (char*)VOV_WEAPON_VALUES[i].at(j).c_str();
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, GAMEPLAY::GET_HASH_KEY(weaponName), 1000, 0);
			}
		}

		//parachute
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), PARACHUTE_ID, 1, 0);

		set_status_text("All weapons added");
		break;
		// switchable features
	case 1:
		process_weaponlist_menu();
		break;
	default:
		break;
	}
	return false;
}

bool process_weapon_menu()
{
	int i = 0;

	std::string caption = "Weapon Options";
	std::vector<MenuItem<int>*> menuItems;

	MenuItem<int> *item = new MenuItem<int>();
	item->caption = "Give All Weapons";
	item->value = i++;
	item->isLeaf = true;
	menuItems.push_back(item);

	item = new MenuItem<int>();
	item->caption = "Individual Weapons";
	item->value = i++;
	item->isLeaf = false;
	menuItems.push_back(item);

	/*SelectFromListMenuItem *listItem = new SelectFromListMenuItem(WEAP_DMG_CAPTIONS, onchange_weap_dmg_modifier);
	listItem->wrap = false;
	listItem->caption = "Weapon Damage Modifier";
	listItem->value = weapDmgModIndex;
	menuItems.push_back(listItem);*/

	ToggleMenuItem<int>* toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Infinite Ammo";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponInfiniteAmmo;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Infinite Parachutes";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponInfiniteParachutes;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "No Reload";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponNoReload;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Fire Ammo";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponFireAmmo;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Explosive Ammo";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponExplosiveAmmo;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Explosive Melee";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponExplosiveMelee;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);

	toggleItem = new ToggleMenuItem<int>();
	toggleItem->caption = "Vehicle Rockets";
	toggleItem->value = i++;
	toggleItem->toggleValue = &featureWeaponVehRockets;
	toggleItem->toggleValueUpdated = NULL;
	menuItems.push_back(toggleItem);
	/*
	StandardOrToggleMenuDef lines[lineCount] = {
	{ "Give All Weapons", NULL, NULL, true },
	{ "Individual Weapons", NULL, NULL, false },
	{ "Infinite Ammo", &featureWeaponInfiniteAmmo, NULL },
	{ "Infinite Parachutes", &featureWeaponInfiniteParachutes, NULL },
	{ "No Reload", &featureWeaponNoReload, NULL },
	{ "Fire Ammo", &featureWeaponFireAmmo, NULL },
	{ "Explosive Ammo", &featureWeaponExplosiveAmmo, NULL },
	{ "Explosive Melee", &featureWeaponExplosiveMelee, NULL },
	{ "Vehicle Rockets", &featureWeaponVehRockets, NULL }
	};
	*/
	return draw_generic_menu<int>(menuItems, &activeLineIndexWeapon, caption, onconfirm_weapon_menu, NULL, NULL);
}

void reset_weapon_globals()
{
	activeLineIndexWeapon = 0;

	weapDmgModIndex = 0;

	featureWeaponInfiniteAmmo =
		featureWeaponInfiniteParachutes =
		featureWeaponNoReload =
		featureWeaponFireAmmo =
		featureWeaponExplosiveAmmo =
		featureWeaponExplosiveMelee =
		featureWeaponVehRockets = false;
}

void update_weapon_features(BOOL bPlayerExists, Player player)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	// weapon damage modifier
	if (bPlayerExists) {
		// Don't need to set this per-frame if it's at the default
		PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(player, WEAP_DMG_FLOAT[weapDmgModIndex]);
		PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(player, WEAP_DMG_FLOAT[weapDmgModIndex]);
		PLAYER::SET_PLAYER_VEHICLE_DAMAGE_MODIFIER(player, WEAP_DMG_FLOAT[weapDmgModIndex]);
	}

	// weapon
	if (featureWeaponFireAmmo)
	{
		if (bPlayerExists)
		{
			GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(player);
		}
	}
	if (featureWeaponExplosiveAmmo)
	{
		if (bPlayerExists)
		{
			GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(player);
		}
	}
	if (featureWeaponExplosiveMelee)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(player);
	}

	// infinite ammo
	if (bPlayerExists && featureWeaponInfiniteAmmo)
	{
		for (int i = 0; i < sizeof(VOV_WEAPON_VALUES) / sizeof(VOV_WEAPON_VALUES[0]); i++)
		{
			for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
			{
				char *weaponName = (char*)VOV_WEAPON_VALUES[i].at(j).c_str();
				Hash weapon = GAMEPLAY::GET_HASH_KEY(weaponName);

				if (WEAPON::IS_WEAPON_VALID(weapon) && WEAPON::HAS_PED_GOT_WEAPON(playerPed, weapon, 0))
				{
					int ammo;

					if (WEAPON::GET_MAX_AMMO(playerPed, weapon, &ammo))
					{
						WEAPON::SET_PED_AMMO(playerPed, weapon, ammo);
					}
				}
			}
		}
	}

	// infinite parachutes
	if (bPlayerExists && featureWeaponInfiniteParachutes)
	{
		int pState = PED::GET_PED_PARACHUTE_STATE(playerPed);
		//unarmed or falling - don't try and give p/chute to player already using one, crashes game
		if (pState == -1 || pState == 3)
		{
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, 0xFBAB5776, 1, 0);
		}
	}

	// weapon no reload
	if (bPlayerExists && featureWeaponNoReload)
	{
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(playerPed, cur, &maxAmmo))
				{
					WEAPON::SET_PED_AMMO(playerPed, cur, maxAmmo);

					maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, cur, 1);
					if (maxAmmo > 0)
						WEAPON::SET_AMMO_IN_CLIP(playerPed, cur, maxAmmo);
				}
			}
		}
	}
}

void update_vehicle_guns()
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !featureWeaponVehRockets) return;

	bool bSelect = KeyDown(VK_ADD) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRb);

	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
			{
				WAIT(0);
			}
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);

		featureWeaponVehShootLastTime = GetTickCount();
	}
}

void save_player_weapons()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	int index = 0;
	for (int i = 0; i < sizeof(VOV_WEAPON_VALUES) / sizeof(VOV_WEAPON_VALUES[0]); i++)
	{
		for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
		{
			std::string weaponNameStr = VOV_WEAPON_VALUES[i].at(j);
			char *weaponName = (char*)weaponNameStr.c_str();
			if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY(weaponName), 0))
			{
				Weapon w = GAMEPLAY::GET_HASH_KEY(weaponName);
				saved_weapon_model[index] = w;
				saved_ammo[index] = WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, w);
				WEAPON::GET_AMMO_IN_CLIP(playerPed, w, &saved_clip_ammo[index]);

				for (int k = 0; k < WEAPONTYPES_TINT.size(); k++)
				{
					if (weaponNameStr.compare(WEAPONTYPES_TINT.at(k)) == 0)
					{
						saved_weapon_tints[index] = WEAPON::GET_PED_WEAPON_TINT_INDEX(playerPed, w);
						break;
					}
				}

				for (int k = 0; k < WEAPONTYPES_MOD.size(); k++)
				{
					if (weaponNameStr.compare(WEAPONTYPES_MOD.at(k)) == 0)
					{
						for (int m = 0; m < VOV_WEAPONMOD_VALUES[k].size(); m++)
						{
							std::string componentName = VOV_WEAPONMOD_VALUES[k].at(m);
							DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

							bool modEquipped = WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(playerPed, w, componentHash) ? true : false;
							saved_weapon_mods[index][m] = modEquipped;
						}
						break;
					}
				}
			}

			index++;
		}
	}

	saved_parachute = (WEAPON::HAS_PED_GOT_WEAPON(playerPed, PARACHUTE_ID, 0)) ? true : false;
	saved_armour = PED::GET_PED_ARMOUR(playerPed);
}

void restore_player_weapons()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int index = 0;
	for (int i = 0; i < sizeof(VOV_WEAPON_VALUES) / sizeof(VOV_WEAPON_VALUES[0]); i++)
	{
		for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
		{
			char *weaponName = (char*)VOV_WEAPON_VALUES[i].at(j).c_str();
			Weapon w = GAMEPLAY::GET_HASH_KEY(weaponName);
			WEAPON::GIVE_WEAPON_TO_PED(playerPed, saved_weapon_model[index], 1000, 0, 0);
			WEAPON::SET_PED_AMMO(playerPed, saved_weapon_model[i], saved_ammo[index]);
			WEAPON::SET_AMMO_IN_CLIP(playerPed, saved_weapon_model[i], saved_clip_ammo[index]);

			for (int k = 0; k < WEAPONTYPES_TINT.size(); k++)
			{
				if (VOV_WEAPON_VALUES[i].at(j).compare(WEAPONTYPES_TINT.at(k)) == 0)
				{
					WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, w, saved_weapon_tints[index]);
					break;
				}
			}

			for (int k = 0; k < WEAPONTYPES_MOD.size(); k++)
			{
				if (VOV_WEAPON_VALUES[i].at(j).compare(WEAPONTYPES_MOD.at(k)) == 0)
				{
					for (int m = 0; m < VOV_WEAPONMOD_VALUES[k].size(); m++)
					{
						std::string componentName = VOV_WEAPONMOD_VALUES[k].at(m);
						DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

						if (saved_weapon_mods[index][m])
						{
							WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(playerPed, w, componentHash);
						}
						else
						{
							WEAPON::REMOVE_WEAPON_COMPONENT_FROM_PED(playerPed, w, componentHash);
						}
					}
					break;
				}
			}

			index++;
		}
	}

	if (saved_parachute)
	{
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, PARACHUTE_ID, 1, 0);
	}

	PED::SET_PED_ARMOUR(playerPed, saved_armour);
}

bool is_weapon_equipped(std::vector<int> extras)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[extras.at(0)].at(extras.at(1));
	char *weaponChar = (char*)weaponValue.c_str();
	return (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY(weaponChar), 0) ? true : false);
}

void set_weapon_equipped(bool equipped, std::vector<int> extras)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[extras.at(0)].at(extras.at(1));
	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
	if (equipped)
	{
		WEAPON::GIVE_WEAPON_TO_PED(playerPed, weapHash, 1000, 0, 0);

		//fill the clip and one spare
		int maxClipAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weapHash, false);
		WEAPON::SET_PED_AMMO(playerPed, weapHash, maxClipAmmo);
		WEAPON::SET_AMMO_IN_CLIP(playerPed, weapHash, maxClipAmmo);
	}
	else
	{
		WEAPON::REMOVE_WEAPON_FROM_PED(playerPed, GAMEPLAY::GET_HASH_KEY(weaponChar));
	}

	redrawWeaponMenuAfterEquipChange = true;
}

bool is_weaponmod_equipped(std::vector<int> extras)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[extras.at(0)].at(extras.at(1));

	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);

	std::string componentName = VOV_WEAPONMOD_VALUES[extras.at(2)].at(extras.at(3));
	DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

	return WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(playerPed, weapHash, componentHash) ? true : false;
}

void set_weaponmod_equipped(bool equipped, std::vector<int> extras)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[extras.at(0)].at(extras.at(1));
	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);

	std::string componentName = VOV_WEAPONMOD_VALUES[extras.at(2)].at(extras.at(3));
	DWORD componentHash = GAMEPLAY::GET_HASH_KEY((char *)componentName.c_str());

	if (WEAPON::HAS_PED_GOT_WEAPON_COMPONENT(playerPed, weapHash, componentHash))
	{
		WEAPON::REMOVE_WEAPON_COMPONENT_FROM_PED(playerPed, weapHash, componentHash);
	}
	else
	{
		WEAPON::GIVE_WEAPON_COMPONENT_TO_PED(playerPed, weapHash, componentHash);
	}
}

void give_weapon_clip()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);

	int curAmmo = WEAPON::GET_AMMO_IN_PED_WEAPON(playerPed, weapHash);
	int curClipAmmo = 0;
	WEAPON::GET_AMMO_IN_CLIP(playerPed, weapHash, &curClipAmmo);
	int maxClipAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weapHash, false);

	if (curClipAmmo < maxClipAmmo)
	{
		set_status_text("Clip Filled");
		WEAPON::SET_AMMO_IN_CLIP(playerPed, weapHash, maxClipAmmo);
	}
	else
	{
		set_status_text("Extra Clip Added");
		WEAPON::SET_PED_AMMO(playerPed, weapHash, curAmmo + maxClipAmmo);
	}
}

void fill_weapon_ammo()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);

	int maxAmmo = 0;
	WEAPON::GET_MAX_AMMO(playerPed, weapHash, &maxAmmo);
	int maxClipAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weapHash, false);

	WEAPON::SET_AMMO_IN_CLIP(playerPed, weapHash, maxClipAmmo);
	WEAPON::SET_PED_AMMO(playerPed, weapHash, maxAmmo);

	set_status_text("Ammo Filled");
}

/*void onhighlight_weapon_mod_menu_tint(MenuItem<int> choice)
{
	onconfirm_weapon_mod_menu_tint(choice);
}*/

bool onconfirm_weapon_mod_menu_tint(MenuItem<int> choice)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	std::string weaponName = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
	int weapHash = GAMEPLAY::GET_HASH_KEY((char*)weaponName.c_str());

	WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, weapHash, choice.value);

	return true;
}

void onconfirm_open_tint_menu(MenuItem<int> choice)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	std::vector<MenuItem<int>*> menuItems;
	for (int i = 0; i < VALUES_TINT.size(); i++)
	{
		MenuItem<int> *item = new MenuItem<int>();
		item->caption = CAPTIONS_TINT[i];
		item->value = VALUES_TINT[i];
		menuItems.push_back(item);
	}

	std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
	char *weaponChar = (char*)weaponValue.c_str();
	int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);

	int tintSelection = 0;
	for (int i = 0; i < WEAPONTYPES_TINT.size(); i++)
	{
		if (WEAPON::GET_PED_WEAPON_TINT_INDEX(playerPed, weapHash) == VALUES_TINT[i])
		{
			tintSelection = i;
			break;
		}
	}

	draw_generic_menu<int>(menuItems, &tintSelection, "Select Tint Color", onconfirm_weapon_mod_menu_tint, NULL, NULL);
}

void add_weapon_feature_enablements(std::vector<FeatureEnabledLocalDefinition>* results)
{
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponExplosiveAmmo", &featureWeaponExplosiveAmmo });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponExplosiveMelee", &featureWeaponExplosiveMelee });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponFireAmmo", &featureWeaponFireAmmo });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponInfiniteAmmo", &featureWeaponInfiniteAmmo });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponInfiniteParachutes", &featureWeaponInfiniteParachutes });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponNoReload", &featureWeaponNoReload });
	results->push_back(FeatureEnabledLocalDefinition{ "featureWeaponVehRockets", &featureWeaponVehRockets });
}

void onchange_weap_dmg_modifier(int value, SelectFromListMenuItem* source)
{
	weapDmgModIndex = value;
}

void add_weapons_generic_settings(std::vector<StringPairSettingDBRow>* results)
{
	results->push_back(StringPairSettingDBRow{ "weapDmgModIndex", std::to_string(weapDmgModIndex) });
}

void handle_generic_settings_weapons(std::vector<StringPairSettingDBRow>* settings)
{
	for (int i = 0; i < settings->size(); i++)
	{
		StringPairSettingDBRow setting = settings->at(i);
		if (setting.name.compare("weapDmgModIndex") == 0)
		{
			weapDmgModIndex = stoi(setting.value);
		}
	}
}
