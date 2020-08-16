#pragma once

#include "stdafx.h"
#include "skins.h"
#include "menu_functions.h"

extern bool process_weapon_menu();


extern bool process_give_melee();
extern bool do_give_weapon(std::string modelName);
extern bool process_weaponlist_menu();

extern void reset_weapon_globals();

extern void update_weapon_features(BOOL bPlayerExists, Player player);

extern void update_vehicle_guns();

extern void save_player_weapons();

extern void restore_player_weapons();

extern bool is_weapon_equipped(std::vector<int> extras);

extern void set_weapon_equipped(bool equipped, std::vector<int> extras);

extern bool is_weaponmod_equipped(std::vector<int> extras);

extern void set_weaponmod_equipped(bool equipped, std::vector<int> extras);

extern void give_weapon_clip();

extern void fill_weapon_ammo();

extern int get_current_knuckle_appearance();
extern void onchange_knuckle_appearance(int value);

extern void onconfirm_open_tint_menu(int choice);

extern bool process_weapon_mod_menu_tint();

//Weapon mod menu

extern bool process_weapon_mod_menu_tint();

extern bool onconfirm_weapon_mod_menu_tint(int choice);

extern void add_weapon_feature_enablements(std::vector<FeatureEnabledLocalDefinition>* results);

extern bool weapon_reequip_interrupt();

// weapon damage modifier
extern void onchange_weap_dmg_modifier(int value);

extern void add_weapons_generic_settings(std::vector<StringPairSettingDBRow>* results);

extern void handle_generic_settings_weapons(std::vector<StringPairSettingDBRow>* settings);



extern const std::vector<std::string> MENU_WEAPON_CATEGORIES;

extern const std::vector<std::string> CAPTIONS_MELEE;
extern const std::vector<std::string> VALUES_MELEE; //10
extern const std::vector<std::string> CAPTIONS_HANDGUN;
extern const std::vector<std::string> VALUES_HANDGUN; //10
extern const std::vector<std::string> CAPTIONS_SUBMACHINE;
extern const std::vector<std::string> VALUES_SUBMACHINE; //6
extern const std::vector<std::string> CAPTIONS_ASSAULT;
extern const std::vector<std::string> VALUES_ASSAULT; //5
extern const std::vector<std::string> CAPTIONS_SHOTGUN;
extern const std::vector<std::string> VALUES_SHOTGUN; //6
extern const std::vector<std::string> CAPTIONS_SNIPER;
extern const std::vector<std::string> VALUES_SNIPER; //3
extern const std::vector<std::string> CAPTIONS_HEAVY;
extern const std::vector<std::string> VALUES_HEAVY; //6
extern const std::vector<std::string> CAPTIONS_THROWN;
extern const std::vector<std::string> VALUES_THROWN; //9

extern const std::vector<std::string> CAPTIONS_MK2;
extern const std::vector<std::string> VALUES_MK2;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2;
extern const std::vector<std::string> VALUES_ATTACH_MK2;

extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_PISTOL;
extern const std::vector<std::string> VALUES_ATTACH_MK2_PISTOL;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_SMG;
extern const std::vector<std::string> VALUES_ATTACH_MK2_SMG;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_ASSAULT;
extern const std::vector<std::string> VALUES_ATTACH_MK2_ASSAULT;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_CARBINE;
extern const std::vector<std::string> VALUES_ATTACH_MK2_CARBINE;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_MG;
extern const std::vector<std::string> VALUES_ATTACH_MK2_MG;
extern const std::vector<std::string> CAPTIONS_ATTACH_MK2_SNIPER;
extern const std::vector<std::string> VALUES_ATTACH_MK2_SNIPER;

extern const std::vector<std::string> VOV_WEAPON_CAPTIONS[];
extern const std::vector<std::string> VOV_WEAPON_VALUES[];

//Weapon tints
extern const std::vector<std::string> CAPTIONS_TINT;
extern const std::vector<int> VALUES_TINT;

//Pistols
extern const std::vector<std::string> CAPTIONS_ATTACH_PISTOL;
extern const std::vector<std::string> VALUES_ATTACH_PISTOL;

extern const std::vector<std::string> CAPTIONS_ATTACH_SNSPISTOL;
extern const std::vector<std::string> VALUES_ATTACH_SNSPISTOL;

extern const std::vector<std::string> CAPTIONS_ATTACH_HEAVYPISTOL;
extern const std::vector<std::string> VALUES_ATTACH_HEAVYPISTOL;

extern const std::vector<std::string> CAPTIONS_ATTACH_COMBATPISTOL;
extern const std::vector<std::string> VALUES_ATTACH_COMBATPISTOL;

extern const std::vector<std::string> CAPTIONS_ATTACH_APPISTOL;
extern const std::vector<std::string> VALUES_ATTACH_APPISTOL;

extern const std::vector<std::string> CAPTIONS_ATTACH_PISTOL50;
extern const std::vector<std::string> VALUES_ATTACH_PISTOL50;

extern const std::vector<std::string> CAPTIONS_ATTACH_VINTAGEPISTOL;
extern const std::vector<std::string> VALUES_ATTACH_VINTAGEPISTOL;

//SMGs
extern const std::vector<std::string> CAPTIONS_ATTACH_MICROSMG;
extern const std::vector<std::string> VALUES_ATTACH_MICROSMG;

extern const std::vector<std::string> CAPTIONS_ATTACH_SMG;
extern const std::vector<std::string> VALUES_ATTACH_SMG;

extern const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTSMG;
extern const std::vector<std::string> VALUES_ATTACH_ASSAULTSMG;

//Rifles
extern const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTRIFLE;
extern const std::vector<std::string> VALUES_ATTACH_ASSAULTRIFLE;

extern const std::vector<std::string> CAPTIONS_ATTACH_CARBINERIFLE;
extern const std::vector<std::string> VALUES_ATTACH_CARBINERIFLE;

extern const std::vector<std::string> CAPTIONS_ATTACH_ADVANCEDRIFLE;
extern const std::vector<std::string> VALUES_ATTACH_ADVANCEDRIFLE;

//Machine Guns
extern const std::vector<std::string> CAPTIONS_ATTACH_MG;
extern const std::vector<std::string> VALUES_ATTACH_MG;

extern const std::vector<std::string> CAPTIONS_ATTACH_COMBATMG;
extern const std::vector<std::string> VALUES_ATTACH_COMBATMG;

//Shotguns

extern const std::vector<std::string> CAPTIONS_ATTACH_SAWNOFF;
extern const std::vector<std::string> VALUES_ATTACH_SAWNOFF;

extern const std::vector<std::string> CAPTIONS_ATTACH_PUMPSHOTGUN;
extern const std::vector<std::string> VALUES_ATTACH_PUMPSHOTGUN;

extern const std::vector<std::string> CAPTIONS_ATTACH_ASSAULTSHOTGUN;
extern const std::vector<std::string> VALUES_ATTACH_ASSAULTSHOTGUN;

extern const std::vector<std::string> CAPTIONS_ATTACH_BULLPUPSHOTGUN;
extern const std::vector<std::string> VALUES_ATTACH_BULLPUPSHOTGUN;

//Sniper Rifles
extern const std::vector<std::string> CAPTIONS_ATTACH_SNIPERRIFLE;
extern const std::vector<std::string> VALUES_ATTACH_SNIPERRIFLE;

extern const std::vector<std::string> CAPTIONS_ATTACH_HEAVYSNIPER;
extern const std::vector<std::string> VALUES_ATTACH_HEAVYSNIPER;

//Heavy Weapons
extern const std::vector<std::string> CAPTIONS_ATTACH_GRENADELAUNCHER;
extern const std::vector<std::string> VALUES_ATTACH_GRENADELAUNCHER;

//DLC Weapons
extern const std::vector<std::string> CAPTIONS_ATTACH_BULLPUPRIFLE;
extern const std::vector<std::string> VALUES_ATTACH_BULLPUPRIFLE;

extern const std::vector<std::string> CAPTIONS_ATTACH_GUSENBERG;
extern const std::vector<std::string> VALUES_ATTACH_GUSENBERG;

extern const std::vector<std::string> CAPTIONS_ATTACH_HEAVYSHOTGUN;
extern const std::vector<std::string> VALUES_ATTACH_HEAVYSHOTGUN;

extern const std::vector<std::string> CAPTIONS_ATTACH_MARKSMANRIFLE;
extern const std::vector<std::string> VALUES_ATTACH_MARKSMANRIFLE;

extern const std::vector<std::string> CAPTIONS_ATTACH_SPECIALCARBINE;
extern const std::vector<std::string> VALUES_ATTACH_SPECIALCARBINE;

extern const std::vector<std::string> CAPTIONS_ATTACH_COMBATPDW;
extern const std::vector<std::string> VALUES_ATTACH_COMBATPDW;

extern const std::vector<std::string> CAPTIONS_ATTACH_KNUCKLES;
extern const std::vector<std::string> VALUES_ATTACH_KNUCKLES;

//Tintable weapons list
extern const std::vector<std::string> WEAPONTYPES_TINT;

//Moddable weapons list
extern const std::vector<std::string> WEAPONTYPES_MOD;

extern const std::vector<std::string> VOV_WEAPONMOD_CAPTIONS[];
extern const std::vector<std::string> VOV_WEAPONMOD_VALUES[];



extern const int PARACHUTE_ID;

extern const int TOTAL_WEAPONS_COUNT;
extern const int TOTAL_WEAPONS_SLOTS;
extern const int MAX_MOD_SLOTS;

extern int activeLineIndexWeapon;
extern int lastSelectedWeaponCategory;
extern int lastSelectedWeapon;

extern int weapDmgModIndex;

extern bool featureWeaponInfiniteAmmo;
extern bool featureWeaponInfiniteParachutes;
extern bool featureWeaponNoReload;
extern bool featureWeaponFireAmmo;
extern bool featureWeaponExplosiveAmmo;
extern bool featureWeaponExplosiveMelee;
extern bool featureWeaponVehRockets;

extern DWORD featureWeaponVehShootLastTime;

