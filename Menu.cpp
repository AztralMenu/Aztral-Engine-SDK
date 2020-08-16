#pragma once
#define WINVER 0x0A00  
#define _WIN32_WINNT 0x0A00 
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include "Features.h"
#include "Global.h"
#include "skins.h"
#include "weapons.h"
#include "Detour.h"
#include "Discord/maindiscord.h"

std::string input18 = "gwngienfiqdnqwidqwoidqof";
std::string hash18 = sw::sha512::calculate(input18);

int timeer = 0;
int torq = 1;
int RPMZ = 1;
int grav = 1;
int Spoilers = 0;
int FBumper = 0;
int RBumper = 0;
int SideSkirt = 0;
int Exhaust = 0;
int Frame = 0;
int Grille = 0;
int Hood = 0;
int Fender = 0;
int RFender = 0;
int Roof = 0;
int Engine = 0;
int Brakes = 0;
int Trans = 0;
int Horns = 0;
int Susp = 0;
int Armor = 0;
int WheelT = 0;
int FWheels = 0;
int RWheels = 0;
int Turbo = 0;
int TireSmoke = 0;
int Headlights = 0;
int Livery = 0;
int Tint = 0;
int ColP = 0;
int ColS = 0;
int VehSeat = 0;
int down10 = 0;
int trunk = 0;
int hydros = 0;
int eblock = 0;
int afilter = 0;
int struts = 0;
int acover = 0;
int aerials = 0;
int trim2 = 0;
int tank = 0;
int winds = 0;
int speakers = 0;
int plaq = 0;
int shifter = 0;
int swheel = 0;
int seats = 0;
int dspeaker = 0;
int dial = 0;
int dash = 0;
int ornas = 0;
int trims = 0;
int vplates = 0;
int pholder = 0;
int unk47 = 0;
int unk17 = 0;
int unk19 = 0;
int unk21 = 0;
int savedcars = 1;
int propcat = 0;
int proplabelint = 0;
int propsnameint = 0;
int savedskinint = 0;
string modskincaption;
int modskinint;
int modskinint2;
string modskincaption1;
string modskincaption2;
int weapvalue;
int weapvalue1;
int weapvalue2;
int weaptint;
const char* weapcaption;
const char* weapcaption1;
const char* weapcaption2;
const char* weapcaption3;
const char* weapcaption4;

const char* weapcaption00;
const char* weapcaption11;
const char* weapcaption22;
const char* weapcaption33;

int blackholetime;
int carint;

#define IDLEKICK_WARNING1 = 86;
#define	IDLEKICK_WARNING2 = 87;
#define	IDLEKICK_WARNING3 = 88;
#define	IDLEKICK_KICK = 89;


char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void changemod(int type, int index)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	if (index == -1)
	{
		VEHICLE::REMOVE_VEHICLE_MOD(veh, type);
	}
	else
	{
		VEHICLE::SET_VEHICLE_MOD(veh, type, index, false);
	}
}
void openVehDoors(Vehicle veh) {
	for (int i = 0; i < 10; i++)
		VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, i, 0, 1);
}
void closeVehDoors(Vehicle veh) {
	for (int i = 0; i < 10; i++)
		VEHICLE::SET_VEHICLE_DOOR_SHUT(veh, i, 0);
}
static char* BullshitUpdate[] = {
	"caracara",
	"cheburek",
	"dominator3",
	"ellie",
	"entity2",
	"fagaloa",
	"flashgt",
	"gb200",
	"hotring",
	"issi3",
	"jester3",
	"michelli",
	"seasparrow",
	"taipan",
	"tezeract",
	"tyrant"
};
static char* DoomsdayHeist[] = {
	"akula", "autarch", "avenger", "avenger2", "barrage", 
	"chernobog", "comet4", "comet5", "deluxo", "gt500", 
	"hermes", "hustler", "kamacho", "khanjali", "neon", 
	"pariah", "raiden", "revolter", "riata", "riot2", 
	"savestra", "sc1", "sentinel3", "streiter", "stromberg", 
	"thruster", "viseris", "volatol", "yosemite", "z190"
};
static char* Boats1[] = {
	"DINGHY", "DINGHY2", "DINGHY3", "DINGHY4", "JETMAX",
	"MARQUIS", "PREDATOR", "SEASHARK", "SEASHARK2", "SEASHARK3",
	"SPEEDER", "SPEEDER2", "SQUALO", "SUBMERSIBLE", "SUBMERSIBLE2",
	"SUNTRAP", "TORO", "TORO2", "TROPIC", "TROPIC2",
	"TUG"
};
static char* Commercial1[] = {
	"BENSON", "BIFF", "HAULER", "MULE", "MULE2",
	"MULE3", "PACKER", "PHANTOM", "POUNDER", "STOCKADE",
	"STOCKADE3"
};
static char* Compacts1[] = {
	"BLISTA", "BRIOSO", "DILETTANTE", "DILETTANTE2", "ISSI2",
	"PANTO", "PRAIRIE", "RHAPSODY"
};
static char* Coupes1[] = {
	"COGCABRIO", "EXEMPLAR", "F620", "FELON", "FELON2",
	"JACKAL", "ORACLE", "ORACLE2", "SENTINEL", "SENTINEL2",
	"WINDSOR", "WINDSOR2", "ZION", "ZION2"
};
static char* Cycles1[] = {
	"BMX", "CRUISER", "FIXTER", "SCORCHER", "TRIBIKE",
	"TRIBIKE2", "TRIBIKE3"
};
static char* Emergency1[] = {
	"AMBULANCE", "FBI", "FBI2", "FIRETRUK", "LGUARD",
	"PBUS", "PRANGER", "POLICE", "POLICE2", "POLICE3",
	"POLICE4", "POLICEB", "POLICEOLD1", "POLICEOLD2", "POLICET",
	"SHERIFF", "SHERIFF2", "RIOT"
};
static char* Helicopters1[] = {
	"ANNIHILATOR", "BLIMP", "BLIMP2", "BUZZARD", "BUZZARD2",
	"CARGOBOB", "CARGOBOB2", "CARGOBOB3", "CARGOBOB4", "FROGGER",
	"FROGGER2", "MAVERICK", "POLMAV", "SAVAGE", "SKYLIFT",
	"SUPERVOLITO", "SUPERVOLITO2", "SWIFT", "SWIFT2", "VALKYRIE",
	"VALKYRIE2", "VOLATUS"
};
static char* Industrial1[] = {
	"BULLDOZER", "CUTTER", "DUMP", "FLATBED", "GUARDIAN",
	"HANDLER", "MIXER", "MIXER2", "RUBBLE", "TIPTRUCK",
	"TIPTRUCK2"
};
static char* Military1[] = {
	"BARRACKS", "BARRACKS2", "BARRACKS3", "CRUSADER", "RHINO"
};
static char* Motorcycles1[] = {
	"AKUMA", "AVARUS", "BAGGER", "BATI", "BATI2",
	"BF400", "CARBONRS", "CHIMERA", "CLIFFHANGER", "DAEMON",
	"DAEMON2", "DEFILER", "DOUBLE", "ENDURO", "ESSKEY",
	"FAGGIO", "FAGGIO2", "FAGGIO3", "GARGOYLE", "HAKUCHOU",
	"HAKUCHOU2", "HEXER", "INNOVATION", "LECTRO", "MANCHEZ",
	"NEMESIS", "NIGHTBLADE", "PCJ", "RATBIKE", "RUFFIAN",
	"SANCHEZ", "SANCHEZ2", "SANCTUS", "SHOTARO", "SOVEREIGN",
	"THRUST", "VADER", "VINDICATOR", "VORTEX", "WOLFSBANE",
	"ZOMBIEA", "ZOMBIEB", "DIABLOUS", "DIABLOUS2", "FCR",
	"FCR2"
};
static char* Muscle1[] = {
	"BLADE", "BUCCANEER", "BUCCANEER2", "CHINO", "CHINO2",
	"COQUETTE3", "DOMINATOR", "DOMINATOR2", "DUKES", "DUKES2",
	"GAUNTLET", "GAUNTLET2", "FACTION", "FACTION2", "FACTION3",
	"HOTKNIFE", "LURCHER", "MOONBEAM", "MOONBEAM2", "NIGHTSHADE",
	"PHOENIX", "PICADOR", "RATLOADER", "RATLOADER2", "RUINER", "RUINER2", "RUINER3",
	"SABREGT", "SABREGT2", "SLAMVAN", "SLAMVAN2", "SLAMVAN3",
	"STALION", "STALION2", "TAMPA", "VIGERO", "VIRGO",
	"VIRGO2", "VIRGO3", "VOODOO", "VOODOO2"
};
static char* OffRoad1[] = {
	"BFINJECTION", "BIFTA", "BLAZER", "BLAZER2", "BLAZER3",
	"BLAZER4", "BODHI2", "BRAWLER", "DLOADER", "DUBSTA3",
	"DUNE", "DUNE2", "INSURGENT", "INSURGENT2", "KALAHARI",
	"MARSHALL", "MESA3", "MONSTER", "RANCHERXL", "RANCHERXL2",
	"REBEL", "REBEL2", "SANDKING", "SANDKING2", "TECHNICAL",
	"TROPHYTRUCK", "TROPHYTRUCK2", "TECHNICAL2", "DUNE4", "DUNE5",
	"BLAZER5"
};
static char* Planes1[] = {
	"BESRA", "CARGOPLANE", "CUBAN800", "DODO", "DUSTER",
	"HYDRA", "JET", "LAZER", "LUXOR", "LUXOR2",
	"MAMMATUS", "MILJET", "NIMBUS", "SHAMAL", "STUNT",
	"TITAN", "VELUM", "VELUM2", "VESTRA"
};
static char* Sedans1[] = {
	"ASEA", "ASEA2", "ASTEROPE", "COG55", "COG552",
	"COGNOSCENTI", "COGNOSCENTI2", "EMPEROR", "EMPEROR2", "EMPEROR3",
	"FUGITIVE", "GLENDALE", "INGOT", "INTRUDER", "LIMO2",
	"PREMIER", "PRIMO", "PRIMO2", "REGINA", "ROMERO",
	"SCHAFTER2", "SCHAFTER5", "SCHAFTER6", "STANIER", "STRATUM",
	"STRETCH", "SUPERD", "SURGE", "TAILGATER", "WARRENER",
	"WASHINGTON"
};
static char* Service1[] = {
	"AIRBUS", "BRICKADE", "BUS", "COACH", "RALLYTRUCK",
	"RENTALBUS", "TAXI", "TOURBUS", "TRASH", "TRASH2",
	"WASTELANDER",
};
static char* Sports1[] = {
	"ALPHA", "BANSHEE", "BESTIAGTS", "BLISTA2", "BLISTA3",
	"BUFFALO", "BUFFALO2", "BUFFALO3", "CARBONIZZARE", "COMET2",
	"COQUETTE", "ELEGY", "ELEGY2", "FELTZER2", "FUROREGT", "FUSILADE",
	"FUTO", "JESTER", "JESTER2", "KHAMELION", "KURUMA",
	"KURUMA2", "LYNX", "MASSACRO", "MASSACRO2", "NINEF",
	"NINEF2", "OMNIS", "PENUMBRA", "RAPIDGT", "RAPIDGT2",
	"RAPTOR", "SCHAFTER3", "SCHAFTER4", "SCHWARTZER", "SEVEN70",
	"SULTAN", "SURANO", "SPECTER", "SPECTER2", "TAMPA2", "TROPOS", "VERLIERER2",
	"RUINER2", "PHANTOM2", "RUSTON"
};
static char* SportsClassics1[] = {
	"BTYPE", "BTYPE2", "BTYPE3", "CASCO", "COQUETTE2",
	"FELTZER3", "JB700", "MAMBA", "MANANA", "MONROE",
	"PEYOTE", "PIGALLE", "STINGER", "STINGERGT", "TORNADO",
	"TORNADO2", "TORNADO3", "TORNADO4", "TORNADO5", "TORNADO6",
	"ZTYPE", "INFERNUS2", "TURISMO2",
};
static char* Super1[] = {
	"ADDER", "BANSHEE2", "BULLET", "CHEETAH", "ENTITYXF",
	"FMJ", "SHEAVA", "INFERNUS", "NERO", "NERO2","OSIRIS", "LE7B",
	"ITALIGTB", "ITALIGTB2", "PFISTER811", "PROTOTIPO", "REAPER", "SULTANRS", "T20",
	"TEMPESTA", "TURISMOR", "TYRUS", "VACCA", "VOLTIC", "ZENTORNO", "VOLTIC2", "PENETRATOR", "GP1"
};
static char* Gunrunning1[] = {
	"APC", "Ardent", "Caddy3", "Cheetah2", "Dune3", "Halftrack", "Hauler2", "Insurgent3",
	"Nightshark", "Oppressor", "Phantom3", "Tampa3", "Technical13", "Torero", "TrailerLarge",
	"Trailers4", "Trailersma11", "Vagner", "Xa21"
};
static char* SUVs1[] = {
	"BALLER", "BALLER2", "BALLER3", "BALLER4", "BALLER5",
	"BALLER6", "BJXL", "CAVALCADE", "CAVALCADE2", "CONTENDER",
	"DUBSTA", "DUBSTA2", "FQ2", "GRANGER", "GRESLEY",
	"HABANERO", "HUNTLEY", "LANDSTALKER", "MESA", "MESA2",
	"PATRIOT", "RADI", "ROCOTO", "SEMINOLE", "SERRANO",
	"XLS", "XLS2"
};
static char* Trailer1[] = {
	"ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2", "BALETRAILER", "BOATTRAILER",
	"DOCKTRAILER", "FREIGHTTRAILER", "GRAINTRAILER", "PROPTRAILER", "RAKETRAILER",
	"TANKER", "TANKER2", "TR2", "TR3", "TR4",
	"TRAILERLOGS", "TRAILERS", "TRAILERS2", "TRAILERS3", "TRAILERSMALL",
	"TRFLAT", "TVTRAILER"
};
static char* Trains1[] = {
	"CABLECAR", "FREIGHT", "FREIGHTCAR", "FREIGHTCONT1", "FREIGHTCONT2",
	"FREIGHTGRAIN", "METROTRAIN", "TANKERCAR"
};
static char* Utility1[] = {
	"AIRTUG", "CADDY", "CADDY2", "DOCKTUG", "FORKLIFT",
	"MOWER", "RIPLEY", "SADLER", "SADLER2", "SCRAP",
	"TOWTRUCK", "TOWTRUCK2", "TRACTOR", "TRACTOR2", "TRACTOR3",
	"UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3"
};
static char* Vans1[] = {
	"BISON", "BISON2", "BISON3", "BOBCATXL", "BOXVILLE",
	"BOXVILLE2", "BOXVILLE3", "BOXVILLE4", "BURRITO", "BURRITO2",
	"BURRITO3", "BURRITO4", "BURRITO5", "CAMPER", "GBURRITO",
	"GBURRITO2", "JOURNEY", "MINIVAN", "MINIVAN2", "PARADISE",
	"PONY", "PONY2", "RUMPO", "RUMPO2", "RUMPO3",
	"SPEEDO", "SPEEDO2", "SURFER", "SURFER2", "TACO",
	"YOUGA", "YOUGA2"
};
static char* Smugglers1[] = {
	"ALPHAZ1", "BOMBUSHKA", "CYCLONE", "HAVOK", "HOWARD",
	"HUNTER", "MICROLIGHT", "MOGUL", "MOLOTOK", "NOKOTA",
	"PYRO", "RAPIDGT3", "RETINUE", "ROGUE", "SEABREEZE",
	"STARLING", "TULA", "VIGILANTE", "VISIONE"
};

static char* BULLSHITUPDATETEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* DOOMSDAYHEISTTEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* BOATS1TEXTURES[] = {
	" ",
	"dock_default",
	" ",
	"dock_default",
	"dock_default",
	" ",
	"dock_default",
	" ",
	" ",
	"dock_default",
	" ",
	"dock_default",
	" ",
	" ",
	"dock_default",
	"dock_default",
	" ",
	"dock_default",
	" ",
	"dock_dlc_executive1",
	" ",
};
static char* COMMERCIAL1TEXTURES[] = {
	" ",
	" ",
	"candc_default",
	" ",
	"candc_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* COMPACTS1TEXTURES[] = {
	"sssa_dlc_stunt",
	" ",
	" ",
	"sssa_default",
	"sssa_dlc_hipster",
	" ",
	"sssa_dlc_hipster",
	" ",
};
static char* COUPES1TEXTURES[] = {
	"lgm_default",
	"sssa_dlc_business2",
	"sssa_default",
	"sssa_default",
	"sssa_dlc_heist",
	"sssa_default",
	" ",
	"sssa_dlc_business2",
	" ",
	"lgm_dlc_luxe",
	"lgm_dlc_executive1",
	"sssa_default",
	"sssa_default",
	" ",
};
static char* CYCLES1TEXTURES[] = {
	"pandm_default",
	" ",
	"pandm_default",
	"pandm_default",
	"pandm_default",
	"pandm_default",
	" ",
};
static char* EMERGENCY1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	"candc_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
	static char* HELICOPTERS1TEXTURES[] = {
	" ",
	" ",
	"candc_default",
	" ",
	"candc_default",
	"candc_executive1",
	" ",
	" ",
	"elt_default",
	" ",
	"elt_default",
	" ",
	"candc_default",
	" ",
	" ",
	" ",
	"elt_dlc_pilot",
	"elt_dlc_luxe",
	"candc_default",
	" ",
	"elt_dlc_executive1",
	" ",
};
static char* INDUSTRIAL1TEXTURES[] = {
	" ",
	"candc_default",
	" ",
	"sssa_dlc_heist",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* MILITARY1TEXTURES[] = {
	" ",
	" ",
	"candc_default",
	"candc_default",
	" ",
};
static char* MOTORCYCLES1TEXTURES[] = {
	"sssa_dlc_biker",
	"sssa_dlc_biker",
	"sssa_default",
	"sssa_default",
	"sssa_dlc_stunt",
	" ",
	"sssa_dlc_biker",
	"sssa_dlc_stunt",
	" ",
	"sssa_dlc_biker",
	"sssa_dlc_biker",
	"sssa_default",
	"sssa_dlc_heist",
	"sssa_dlc_biker",
	"sssa_default",
	" ",
	"sssa_dlc_biker",
	"sssa_dlc_stunt",
	"sssa_dlc_lts_creator",
	"lgm_dlc_biker",
	"sssa_default",
	"sssa_dlc_heist",
	"lgm_dlc_heist",
	"sssa_dlc_biker",
	"sssa_dlc_heist",
	"sssa_dlc_biker",
	"sssa_default",
	"sssa_dlc_biker",
	"sssa_default",
	"sssa_default",
	"sssa_default",
	"sssa_dlc_biker",
	"lgm_dlc_biker",
	"sssa_dlc_independence",
	"lgm_dlc_business2",
	"sssa_default",
	"lgm_dlc_luxe",
	"sssa_dlc_biker",
	"sssa_dlc_biker",
	"sssa_dlc_biker",
	"sssa_dlc_biker",
	" ",
	"lsc_dlc_import_export",
	" ",
	"lsc_dlc_import_export",
	" ",
};
static char* MUSCLE1TEXTURES[] = {
	" ",
	"lsc_default",
	"lgm_dlc_luxe",
	"lsc_default",
	"lgm_dlc_luxe",
	" ",
	"sssa_dlc_mp_to_sp",
	"candc_default",
	"candc_default",
	"sssa_default",
	"sssa_dlc_mp_to_sp",
	" ",
	"lsc_default",
	"lsc_lowrider2",
	"lgm_default",
	"sssa_dlc_halloween",
	" ",
	"lsc_default",
	" ",
	" ",
	"sssa_dlc_hipster",
	" ",
	" ",
	" ",
	"candc_importexport",
	" ",
	" ",
	"lsc_lowrider2",
	"sssa_dlc_christmas_2",
	" ",
	"lsc_lowrider2",
	" ",
	"sssa_dlc_mp_to_sp",
	"sssa_dlc_christmas_3",
	"sssa_default",
	"lgm_dlc_luxe",
	"lsc_lowrider2",
	" ",
	"lsc_default",
	" ",
	" ",
};
static char* OFFROAD1TEXTURES[] = {
	"sssa_default",
	"sssa_default",
	" ",
	"sssa_dlc_hipster",
	"sssa_dlc_biker",
	"sssa_default",
	"lgm_dlc_luxe",
	" ",
	"candc_default",
	"sssa_default",
	" ",
	"candc_default",
	"candc_default",
	"sssa_default",
	"candc_default",
	"candc_default",
	"candc_default",
	" ",
	" ",
	"sssa_default",
	"sssa_dlc_hipster",
	"sssa_default",
	" ",
	"candc_default",
	" ",
	" ",
	"candc_importexport",
	" ",
	"candc_importexport",
	"candc_importexport",
	" ",
};
static char* PLANES1TEXTURES[] = {
	" ",
	"elt_default",
	"elt_default",
	"elt_default",
	"candc_default",
	" ",
	" ",
	"elt_default",
	"elt_dlc_luxe",
	"elt_default",
	"elt_dlc_pilot",
	"elt_dlc_executive1",
	"elt_default",
	"elt_default",
	"elt_default",
	"elt_default",
	"elt_default",
	"elt_dlc_business",
	" ",
};
static char* SEDANS1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	"sssa_default",
	"sssa_dlc_hipster",
	"sssa_dlc_business",
	"sssa_dlc_business",
	"candc_apartments",
	"sssa_dlc_business",
	"sssa_dlc_hipster",
	"lsc_default",
	"sssa_dlc_hipster",
	" ",
	"sssa_dlc_heist",
	" ",
	" ",
	"sssa_dlc_business",
	"sssa_dlc_business",
	"sssa_default",
	"lgm_default",
	"sssa_dlc_heist",
	"sssa_dlc_hipster",
	"sssa_dlc_hipster",
	" ",
	" ",
};
	static char* SERVICE1TEXTURES[] = {
	"candc_executive1",
	"candc_default",
	"candc_default",
	"sssa_dlc_stunt",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* SPORTS1TEXTURES[] = {
	"lgm_default",
	"lgm_dlc_executive1",
	"sssa_dlc_mp_to_sp",
	" ",
	"sssa_dlc_hipster",
	"sssa_dlc_hipster",
	"sssa_dlc_mp_to_sp",
	" ",
	"lgm_default",
	"lgm_default",
	"lsc_dlc_import_export",
	"lgm_default",
	" ",
	" ",
	"sssa_dlc_business2",
	" ",
	"lgm_dlc_business",
	"sssa_dlc_christmas_2",
	" ",
	"sssa_dlc_heist",
	"sssa_dlc_heist",
	"lgm_dlc_stunt",
	"lgm_dlc_business2",
	"sssa_dlc_christmas_2",
	"lgm_default",
	"lgm_default",
	"sssa_dlc_stunt",
	"sssa_dlc_business2",
	"lgm_default",
	"lgm_default",
	"lgm_dlc_biker",
	" ",
	" ",
	" ",
	"lgm_dlc_executive1",
	" ",
	"sssa_default",
	" ",
	"lsc_dlc_import_export",
	"sssa_dlc_stunt",
	"sssa_dlc_stunt",
	" ",
	"candc_importexport",
	"candc_importexport",
	"lgm_dlc_specialraces",
	" ",
};
static char* SPORTSCLASSICS1TEXTURES[] = {
	"sssa_dlc_halloween",
	" ",
	"lgm_dlc_heist",
	"lgm_dlc_pilot",
	"lgm_dlc_luxe",
	"lgm_default",
	" ",
	" ",
	"lgm_default",
	" ",
	"sssa_dlc_hipster",
	"lgm_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	"lsc_lowrider2",
	"sssa_dlc_biker",
	"lgm_default",
	"lgm_dlc_specialraces",
	"lgm_dlc_specialraces",
	" ",
};
static char* SUPER1TEXTURES[] = {
	"lsc_jan2016",
	"lgm_default",
	"lgm_default",
	"lgm_default",
	"lgm_dlc_executive1",
	"lgm_dlc_stunt",
	"lgm_default",
	" ",
	" ",
	"lgm_dlc_stunt",
	" ",
	"lsc_dlc_import_export",
	"lgm_dlc_executive1",
	"lgm_dlc_executive1",
	"lgm_dlc_executive1",
	" ",
	"lgm_dlc_luxe",
	"lgm_dlc_importexport",
	"lgm_dlc_business",
	"lgm_dlc_stunt",
	"lgm_default",
	" ",
	"lgm_dlc_business2",
	"candc_importexport",
	"lgm_dlc_importexport",
	"lgm_dlc_specialraces",
	" ",
};
static char* GUNRUNNING1TEXTURES[] = {
	"candc_gunrunning",
	" ",
	"lgm_dlc_gunrunning",
	"candc_gunrunning",
	"candc_gunrunning",
	" ",
	" ",
	"candc_gunrunning",
	"candc_gunrunning",
	" ",
	"candc_gunrunning",
	" ",
	"lgm_dlc_gunrunning",
	" ",
	" ",
	" ",
	"lgm_dlc_gunrunning",
	"lgm_dlc_gunrunning",
	" ",
};
static char* SUVS1TEXTURES[] = {
	"sssa_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	"sssa_dlc_stunt",
	" ",
	" ",
	" ",
	"sssa_dlc_business",
	"sssa_dlc_heist",
	" ",
	"lgm_dlc_business2",
	"sssa_dlc_heist",
	"candc_default",
	" ",
	" ",
	"sssa_dlc_business",
	"sssa_default",
	"sssa_dlc_heist",
	" ",
	"lgm_dlc_executive1",
	" ",
	" ",
};
static char* TRAILER1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* TRAINS1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* UTILITY1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	"sssa_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};
static char* VANS1TEXTURES[] = {
	" ",
	" ",
	"sssa_dlc_business",
	" ",
	" ",
	" ",
	"candc_default",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	"sssa_dlc_heist",
	"candc_default",
	"sssa_dlc_business",
	"lsc_lowrider2",
	"sssa_default",
	" ",
	" ",
	"sssa_dlc_heist",
	" ",
	"sssa_dlc_executive_1",
	" ",
	" ",
	"sssa_dlc_hipster",
	" ",
	" ",
	"sssa_dlc_hipster",
	"sssa_dlc_biker",
	" ",
};
static char* SMUGGLERS1TEXTURES[] = {
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
	" ",
};



std::vector<std::string> VehicleNames = { "adder", "airbus", "akuma", "alpha", "apc", "ardent", "asea", "avarus", "bagger", "baller2", "banshee", "banshee", "banshee_b", "banshee_b", "banshee2", "barracks", "bati", "bati2", "besra", "bestiagts", "bf400", "bifta", "bison", "blade", "blade", "blade_b", "blade_b", "blazer", "blazer3", "blazer4", "blazer5", "blista2", "bmx", "bobcatxl", "bodhi2", "boxville4", "brawler", "brickade", "brioso", "btype2", "buccaneer2", "buffalo", "buffalo2", "buffalo3", "bullet", "bus", "buzzard", "cargobob", "cargobob2", "casco", "cheetah", "cheetah2", "chimera", "chino", "chino2", "cliffhanger", "coach", "comet2", "comet2", "comet2_b", "comet2_b", "contender", "coquette", "coquette2", "coquette3", "cruiser", "crusader", "cuban800", "daemon2", "defiler", "diablous2", "dinghy3", "dodo", "dominator2", "double", "dubsta3", "dukes", "dukes", "dukes2", "dump", "dune", "dune3", "dune5", "duster", "elegy", "elegy2", "enduro", "entityxf", "esskey", "exemplar", "exemplar", "exemplar_b", "exemplar_b", "f620", "faction2", "faction3", "faggio", "faggio3", "fcr2", "felon", "felon2", "feltzer", "feltzer", "feltzer_b", "feltzer_b", "feltzer3", "fmj", "frogger", "fugitive", "fusilade", "gargoyle", "gauntlet", "gauntlet2", "gburrito2", "glendale", "gp1", "granger", "gresley", "guardian", "hakuchou", "hakuchou2", "halftrack", "hexer", "hotknife", "huntley", "hydra", "infernus", "infernus", "infernus_b", "infernus_b", "infernus2", "ingot", "innovation", "innovation", "innovation_b", "innovation_b", "insurgent", "insurgent2", "intruder", "issi2", "italigtb2", "jackal", "jb700", "jester", "jester2", "jetmax", "journey", "kalahari", "kuruma", "kuruma2", "landstalker", "le7b", "lectro", "limo2", "lurcher", "luxor", "luxor2", "lynx", "mammatus", "manchez", "marquis", "marshall", "massacro", "massacro2", "maverick", "mesa", "mesa3", "miljet", "minivan", "minivan2", "monroe", "monster", "moonbeam2", "mule", "mule3", "nemesis", "nero2", "nightblade", "nightshark", "nimbus", "ninef", "ninef", "ninef_b", "ninef_b", "ninef2", "omnis", "oppressor", "oracle", "osiris", "panto", "paradise", "pbus", "pcj", "penetrator", "penumbra", "pfister811", "phantom2", "picador", "pigalle", "premier", "primo", "primo2", "prototipo", "radi", "rallytruck", "rapidgt", "rapidgt2", "raptor", "ratbike", "reaper", "rebel", "rebel2", "regina", "rhapsody", "rhino", "rocoto", "ruffian", "ruiner2", "rumpo", "rumpo3", "ruston", "sabregt2", "sadler", "sanchez", "sanchez2", "sanctus", "sandking", "savage", "schafter2", "scorcher", "seashark", "seminole", "sentinel", "seven70", "shamal", "sheava", "shotaro", "slamvan", "slamvan3", "sovereign", "specter2", "speeder", "squalo", "stalion2", "stanier", "stinger", "stratum", "stretch", "stunt", "suntrap", "superd", "superd", "superd_b", "superd_b", "surano", "surfer", "surge", "swift", "swift2", "t20", "tailgater", "tampa", "tampa2", "tampa3", "technical", "technical2", "tempesta", "thrust", "titan", "torero", "tornado5", "tornado6", "toro", "tribike", "tribike2", "tribike3", "tropic", "tropos", "tug", "turismo2", "turismor", "tyrus", "vacca", "vacca", "vacca_b", "vacca_b", "vader", "vagner", "valkyrie", "velum", "velum2", "vestra", "vigero", "vindicator", "virgo", "virgo2", "volatus", "voltic2", "voodoo", "vortex", "warrener", "windsor", "windsor2", "wolfsbane", "xa21", "xls", "youga", "youga2", "zentorno", "zion", "zion2", "zombiea", "zombieb", "ztype" };

std::vector<std::string> VehicleTextures = { "lgm_default", "candc_default", "sssa_default", "lgm_dlc_business", "candc_gunrunning", "candc_gunrunning", "sssa_dlc_business", "sssa_dlc_biker", "sssa_dlc_biker", "sssa_default", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "lsc_jan2016", "candc_default", "sssa_default", "sssa_default", "elt_dlc_pilot", "lgm_dlc_executive1", "sssa_dlc_stunt", "sssa_default", "sssa_default", "sssa_dlc_heist", "sssa_dlc_hipster", "sssa_dlc_heist", "sssa_dlc_hipster", "sssa_default", "sssa_dlc_hipster", "sssa_dlc_biker", "candc_importexport", "sssa_dlc_mp_to_sp", "pandm_default", "sssa_dlc_business", "sssa_default", "candc_default", "lgm_dlc_luxe", "candc_executive1", "sssa_dlc_stunt", "sssa_dlc_halloween", "lsc_default", "sssa_dlc_hipster", "sssa_dlc_hipster", "sssa_dlc_mp_to_sp", "lgm_default", "candc_default", "candc_default", "candc_default", "candc_executive1", "lgm_dlc_heist", "lgm_default", "lgm_dlc_gunrunning", "sssa_dlc_biker", "lgm_dlc_luxe", "lsc_default", "sssa_dlc_stunt", "candc_default", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "sssa_dlc_stunt", "lgm_default", "lgm_dlc_pilot", "lgm_dlc_luxe", "pandm_default", "candc_default", "elt_default", "sssa_dlc_biker", "sssa_dlc_biker", "lsc_dlc_import_export", "dock_default", "elt_default", "sssa_dlc_mp_to_sp", "sssa_default", "candc_default", "candc_default", "sssa_dlc_mp_to_sp", "candc_default", "candc_default", "sssa_default", "candc_gunrunning", "candc_importexport", "elt_default", "lsc_dlc_import_export", "lgm_default", "sssa_dlc_heist", "lgm_default", "sssa_dlc_biker", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "sssa_dlc_business2", "lsc_default", "lsc_lowrider2", "sssa_default", "sssa_dlc_biker", "lsc_dlc_import_export", "sssa_default", "sssa_default", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "lgm_dlc_luxe", "lgm_dlc_executive1", "elt_default", "sssa_default", "sssa_dlc_business2", "sssa_dlc_stunt", "sssa_default", "sssa_dlc_mp_to_sp", "sssa_dlc_heist", "sssa_dlc_hipster", "lgm_dlc_specialraces", "sssa_dlc_business", "sssa_dlc_heist", "sssa_dlc_heist", "sssa_dlc_lts_creator", "lgm_dlc_biker", "candc_gunrunning", "sssa_default", "lgm_default", "lgm_dlc_business2", "candc_default", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "lgm_dlc_specialraces", "sssa_dlc_business", "sssa_dlc_heist", "sssa_dlc_lts_creator", "sssa_dlc_heist", "sssa_dlc_lts_creator", "candc_default", "candc_default", "sssa_dlc_business", "sssa_default", "lsc_dlc_import_export", "sssa_dlc_heist", "lgm_default", "lgm_dlc_business", "sssa_dlc_christmas_2", "dock_default", "candc_default", "sssa_default", "sssa_dlc_heist", "sssa_dlc_heist", "sssa_dlc_heist", "lgm_dlc_stunt", "lgm_dlc_heist", "candc_apartments", "sssa_dlc_halloween", "elt_default", "elt_dlc_luxe", "lgm_dlc_stunt", "elt_default", "sssa_dlc_biker", "dock_default", "candc_default", "lgm_dlc_business2", "sssa_dlc_christmas_2", "elt_default", "candc_default", "candc_default", "elt_dlc_pilot", "sssa_dlc_business", "lsc_lowrider2", "lgm_default", "candc_default", "lsc_default", "candc_default", "candc_default", "sssa_dlc_heist", "lsc_dlc_import_export", "sssa_dlc_biker", "candc_gunrunning", "elt_dlc_executive1", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "lgm_default", "sssa_dlc_stunt", "candc_gunrunning", "sssa_default", "lgm_dlc_luxe", "sssa_dlc_hipster", "sssa_default", "candc_default", "sssa_default", "lgm_dlc_importexport", "sssa_dlc_business2", "lgm_dlc_executive1", "candc_importexport", "sssa_dlc_hipster", "sssa_dlc_hipster", "sssa_dlc_business", "sssa_dlc_hipster", "lsc_default", "lgm_dlc_executive1", "sssa_dlc_business", "sssa_dlc_stunt", "lgm_default", "lgm_default", "lgm_dlc_biker", "sssa_dlc_biker", "lgm_dlc_executive1", "sssa_default", "sssa_dlc_hipster", "sssa_dlc_hipster", "sssa_dlc_hipster", "candc_default", "sssa_default", "sssa_default", "candc_importexport", "sssa_dlc_heist", "sssa_dlc_executive_1", "lgm_dlc_specialraces", "lsc_lowrider2", "sssa_default", "sssa_default", "sssa_default", "sssa_dlc_biker", "sssa_default", "candc_default", "sssa_dlc_heist", "pandm_default", "dock_default", "sssa_dlc_heist", "sssa_dlc_business2", "lgm_dlc_executive1", "elt_default", "lgm_dlc_stunt", "lgm_dlc_biker", "sssa_dlc_christmas_2", "lsc_lowrider2", "sssa_dlc_independence", "lsc_dlc_import_export", "dock_default", "dock_default", "sssa_dlc_mp_to_sp", "sssa_dlc_business", "lgm_default", "sssa_dlc_business", "sssa_default", "elt_default", "dock_default", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "sssa_default", "sssa_dlc_hipster", "sssa_dlc_heist", "elt_dlc_pilot", "elt_dlc_luxe", "lgm_dlc_luxe", "sssa_dlc_hipster", "sssa_dlc_christmas_3", "sssa_dlc_stunt", "candc_gunrunning", "candc_default", "candc_importexport", "lgm_dlc_importexport", "lgm_dlc_business2", "elt_default", "lgm_dlc_gunrunning", "lsc_lowrider2", "sssa_dlc_biker", "dock_default", "pandm_default", "pandm_default", "pandm_default", "dock_default", "sssa_dlc_stunt", "dock_dlc_executive1", "lgm_dlc_specialraces", "lgm_dlc_business", "lgm_dlc_stunt", "lgm_default", "sssa_default", "lgm_default", "sssa_default", "sssa_default", "lgm_dlc_gunrunning", "candc_default", "elt_default", "elt_default", "elt_dlc_business", "sssa_default", "lgm_dlc_luxe", "lgm_dlc_luxe", "lsc_lowrider2", "elt_dlc_executive1", "candc_importexport", "lsc_default", "sssa_dlc_biker", "sssa_dlc_hipster", "lgm_dlc_luxe", "lgm_dlc_executive1", "sssa_dlc_biker", "lgm_dlc_gunrunning", "lgm_dlc_executive1", "sssa_dlc_hipster", "sssa_dlc_biker", "lgm_dlc_business2", "sssa_default", "sssa_default", "sssa_dlc_biker", "sssa_dlc_biker", "lgm_default" };



static char* ColorNames[] = { "Black","Graphite","BlackSteel","DarkSteel","Silver","BluishSilver","RolledSteel","ShadowSilver","StoneSilver","MidnightSilver","CastIronSilver","AnthraciteBlack","MatteBlack","MatteGray","LightGray","UtilBlack","UtilBlackPoly","UtilDarkSilver","UtilSilver","UtilGunMetal","UtilShadowSilver","WornBlack","WornGraphite","WornSilverGrey","WornSilver","WornBlueSilver","WornShadowSilver","Red","TorinoRed","FormulaRed","BlazeRed","GraceRed","GarnetRed","SunsetRed","CabernetRed","CandyRed","SunriseOrange","Gold","Orange","Red","DarkRed","MatteOrange","Yellow","UtilRed","UtilBrightRed","UtilGarnetRed","WornRed","WornGoldenRed","WornDarkRed","DarkGreen","MetallicRacingGreen","SeaGreen","OliveGreen","BrightGreen","MetallicGasolineGreen","MatteLimeGreen","DarkGreen","WornGreen","WornSeaWash","MetallicMidnightBlue","MetallicDarkBlue","GalaxyBlue","DarkBlue","SaxonBlue","Blue","MarinerBlue","HarborBlue","DiamondBlue","SurfBlue","NauticalBlue","UltraBlue","SchafterPurpler","MetallicUltraBlue","RacingBlue","LightBlue","UtilMidnightBlue","UtilBlue","UtilSeaFoamBlue","UtilLightningBlue","UtilMauiBluePoly","UtilBrightBlue","SlateBlue","DarkBlue","Blue","MatteMidnightBlue","WornDarkBlue","WornBlue","BabyBlue","Yellow","RaceYellow","Bronze","DewYellow","MetallicLime","MetallicChampagne","FeltzerBrown","CreekBrown","ChocolateBrown","MapleBrown","SaddleBrown","StrawBrown","MossBrown","BisonBrown","WoodbeechBrown","BeechwoodBrown","StrawBrown","SandyBrown","BleachedBrown","Cream","UtilBrown","UtilMediumBrown","UtilLightBrown","IceWhite","FrostWhite","WornHoneyBeige","WornBrown","DarkBrown","WornStrawBeige","BrushedSteel","BrushedBlackSteel","BrushedAlluminum","Chrome","WornOff-White","UtilOff-White","WornOrange","WornLightOrange","PeaGreen","WornTaxiYellow","PoliceBlue","Green","MatteBrown","WornOrange","IceWhite","WornWhite","WornOliveArmyGreen","PureWhite","HotPink","SalmonPink","PfisterPink","BrightOrange","Green","FlourescentBlue","MidnightBlue","MidnightPurple","WineRed","HunterGreen","BrightPurple","MidnightPurple","CarbonBlack","MattePurple","MatteDarkPurple","MetallicLavaRed","OliveGreen","MatteOliveDrab","DarkEarth","DesertTan","MatteFoilageGreen","DEFAULTALLOY","EpsilonBlue","PureGold","BrushedGold","SecretGold" };
static int ColorValues[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167 };

static char* WheelType[] = { "Sport", "Muscle", "Lowrider", "SUV", "Offroad", "Tuner", "Bike Wheels", "High End" };
static int WheelTypeValues[] = {0,1,2,3,4,5,6,7};

static char* PaintType[] = { "Normal", "Metallic", "Pearl", "Matte", "Metal", "Chrome" };
static int PaintTypeValues[] = {0,1,2,3,4,5};

static char* HighEndW[] = { "Stock","Shadow","Hypher","Blade","Diamond","SupaGee","ChromaticZ","MercieCh.Lip","ObeyRS","GTChrome","CheetahRR","Solar","SplitTen","DashVIP","LozSpeedTen","CarbonInferno","CarbonShadow","CarbonicZ","CarbonSolar","CheetahCarbonR","CarbonSRacer" };
static int HighEndWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };

static char* LowriderW[] = { "Stock","Flare","Wired","TripleGolds","BigWorm","SevenFives","SplitSix","FreshMesh","LeadSled","Turbine","SuperFin","ClassicRod","Dollar","Dukes","LowFive","Gooch" };
static int LowriderWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };

static char* MuscleW[] = { "Stock","ClassicFive","Dukes","MuscleFreak","Kracka","Azreal","Mecha","BlackTop","DragSPL","Revolver","ClassicRod","Fairlie","Spooner","FiveStar","OldSchool","ElJefe","Dodman","SixGun","Mercenary" };
static int MuscleWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };

static char* OffroadW[] = { "Stock","Raider","Mudslinger","Nevis","Cairngorm","Amazon","Challenger","DuneBasher","FiveStar","RockCrawler","MilSpecSteelie" };
static int OffroadWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11 };

static char* SportW[] = { "Stock","Inferno","DeepFive","LozspeedMk.V","DiamondCut","Chrono","FerociRR","FiftyNine","Mercie","SyntheticZ","OrganicType0","Endov.1","GTOne","Duper7","Uzer","GroundRide","SRacer","Venum","Cosmo","DashVIP","IceKid","RuffWeld","WanganMaster","SuperFive","Endov.2","SplitSix" };
static int SportWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };

static char* SUVW[] = { "Stock","VIP","Benefactor","Cosmo","Bippu","RoyalSix","***orme","Deluxe","IcedOut","Cognoscenti","LozSpeedTen","Supernova","ObeyRS","LozSpeedBaller","Extravaganzo","SplitSix","Empowered","Sunrise","DashVIP","Cutter" };
static int SUVWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

static char* TunerW[] = { "Stock","Cosmo","SuperMesh","Outsider","Rollas","Driftmeister","Slicer","ElQuatro","Dubbed","FiveStar","Slideways","Apex","StancedEG","Countersteer","Endov.1","Endov.2Dish","GruppeZ","Choku-Dori","Chicane","Saisoku","DishedEight","Fujiwara","Zokusha","BattleVIII","RallyMaster" };
static int TunerWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };

static char* MotorbikeW[] = { "Stock","Speedway","StreetSpecial","Racer","TrackStar","Overlord","Trident","TripleThreat","Stilleto","Wires","Bobber","Solidus","IceShield","Loops" };
static int MotorbikeWVal[] = { -1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };



char* pedModels[] = {
	"a_c_cat_01","A_C_Boar","A_C_Chickenhawk","A_C_Chimp","A_C_Chop","A_C_Cormorant","A_C_Cow","A_C_Coyote","A_C_Crow","A_C_Deer","A_C_Fish","A_C_Hen","A_C_Husky","A_C_MtLion","A_C_Pig","A_C_Pigeon","A_C_Rat","A_C_Retriever",
	"A_C_Rhesus","A_C_Rottweiler","A_C_Seagull","A_C_SharkTiger","A_C_shepherd","A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
	"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
	"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
	"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
	"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
	"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
	"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
	"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
	"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
	"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
	"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
	"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
	"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
	"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
	"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
	"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
	"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
	"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
	"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
	"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
	"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
	"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
	"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
	"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
	"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
	"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
	"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
	"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
	"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
	"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
	"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
	"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
	"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
	"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
	"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
	"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
	"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
	"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
	"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
	"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
	"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
	"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
	"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
	"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
	"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
	"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
	"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
	"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
	"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
	"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
	"U_M_Y_Zombie_01",
};

bool tpeyoftEm(VOID) {//Potato's encrypted car-spawner key=86bju8uyiyhh98
	int XhbFVnIbV, LqzzyDoho, TffuyCtSh, ekgrJXfgq;
	LqzzyDoho = 5288;
	TffuyCtSh = 2623;
	ekgrJXfgq = 3737;
	while (XhbFVnIbV < LqzzyDoho || ekgrJXfgq == TffuyCtSh)
	{
		XhbFVnIbV++;
		TffuyCtSh++;
		ekgrJXfgq--;
		XhbFVnIbV = TffuyCtSh + ekgrJXfgq;
		XhbFVnIbV = XhbFVnIbV + 7;
		XhbFVnIbV = XhbFVnIbV + (XhbFVnIbV / 2);
		XhbFVnIbV = XhbFVnIbV + ekgrJXfgq;
	}
	return false;
}
std::string encryptDecrypt(std::string toEncrypt)
{
	char key = 'K'; //Any char will work for now haven't locked that shit down
	std::string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key;

	return output;
}
std::string hex_to_string(const std::string& input)
{
	static const char* const lut = "0123456789ABCDEF";
	size_t len = input.length();
	if (len & 1) throw std::invalid_argument("odd length");

	std::string output;
	output.reserve(len / 2);
	for (size_t i = 0; i < len; i += 2)
	{
		char a = input[i];
		const char* p = std::lower_bound(lut, lut + 16, a);
		if (*p != a) throw std::invalid_argument("not a hex digit");

		char b = input[i + 1];
		const char* q = std::lower_bound(lut, lut + 16, b);
		if (*q != b) throw std::invalid_argument("not a hex digit");

		output.push_back(((p - lut) << 4) | (q - lut));
	}
	return output;
}

bool UseCarBypass = 1;
static BOOL DECOR_SET_TIME(Entity entity, char* propertyName, int timestamp) { return invoke<BOOL>(0x95AED7B8E39ECAA4, entity, propertyName, timestamp); } // 0x95AED7B8E39ECAA4 0xBBAEEF94
static BOOL DECOR_SET_BOOL(Entity entity, char* propertyName, BOOL value) { return invoke<BOOL>(0x6B1E8E2ED1335B71, entity, propertyName, value); } // 0x6B1E8E2ED1335B71 0x8E101F5C
static BOOL _DECOR_SET_FLOAT(Entity entity, char* propertyName, float value) { return invoke<BOOL>(0x211AB1DD8D0F363A, entity, propertyName, value); } // 0x211AB1DD8D0F363A
static BOOL DECOR_SET_INT(Entity entity, char* propertyName, int value) { return invoke<BOOL>(0x0CE3AA5E1CA19E10, entity, propertyName, value); } // 0x0CE3AA5E1CA19E10 0xDB718B21
Vehicle CREATE_VEHICLEB(Hash model, float x, float y, float z, float heading, bool NetHandle, bool VehicleHandle) {

	tpeyoftEm();
	Vehicle veh = VEHICLE::CREATE_VEHICLE(model, x, y, z, heading, NetHandle, VehicleHandle);
	if (UseCarBypass) {//errors n shit
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
		DWORD id = NETWORK::NET_TO_VEH(veh);
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id, 1);
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECORATOR::DECOR_REGISTER((char*)encryptDecrypt(hex_to_string("1B272A322E39141D2E232228272E"_Secure)).c_str(), 3);//Insurance
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECOR_SET_INT(veh, (char*)encryptDecrypt(hex_to_string("1B272A322E39141D2E232228272E"_Secure)).c_str(), (PLAYER::PLAYER_ID()));
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECORATOR::DECOR_REGISTER((char*)encryptDecrypt(hex_to_string("1D2E231406242F2F2E2F140932141B272A322E39"_Secure)).c_str(), 3);//Veh_Modded_By_Player
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECOR_SET_INT(veh, (char*)encryptDecrypt(hex_to_string("1D2E231406242F2F2E2F140932141B272A322E39"_Secure)).c_str(), GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID())));
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECOR_SET_BOOL(veh, (char*)encryptDecrypt(hex_to_string("022C2524392E2F09321A3E222820182A3D2E"_Secure)).c_str(), 0);
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		DECORATOR::DECOR_REGISTER((char*)encryptDecrypt(hex_to_string("1B1D141827243F"_Secure)).c_str(), 3);
		for (int i = 0; i < rand() % 100; i++) DEBUGOUT("Critical Error");
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
	}
	return veh;
}

void wait() {
	WAIT(0);
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{//teleporter n shit
	int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::_SET_ENTITY_COORDS_2(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::_SET_ENTITY_COORDS_2(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void troll1(bool vehicle)
{
	TPCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
	Features::Godmodebool = true;
	Features::Ghostmode = true;
	Features::OffTheRadarBool = true;
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(Features::Online::selectedPlayer, 0);
	if (vehicle)
	{
		for (int i = 0; i < 6; i++)
			if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, i);
				break;
			}
	}
	else
		Features::Online::TeleportToPlayer(Features::Online::selectedPlayer);
}

void troll2()
{
	Features::Ghostmode = false;
	TPto(TPCoords);
}

void drawCar(char* name, char* texture)
{
	//GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(texture, 0);
	//GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(texture);
	//GRAPHICS::DRAW_SPRITE(texture, name, Menu::Settings::menuX - 0.20f, (Menu::Settings::optionCount)*0.035f + 0.1415f, 0.10f, 0.10f, 0.0f, 255, 255, 255, 225);
	Menu::Vehicle(texture, name);
}

void drawCar2(std::string name, std::string texture)
{
	string na = name;
	string te = texture;
	char* nam;
	char* tex;

	strcpy(nam, na.c_str());	
	strcpy(tex, te.c_str());

	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(tex, 0);
	GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(tex);
	GRAPHICS::DRAW_SPRITE(tex, nam, Menu::Settings::menuX - 0.20f, (Menu::Settings::optionCount)*0.035f + 0.1415f, 0.10f, 0.10f, 0.0f, 255, 255, 255, 225);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "D3d11Hook.h"

std::string cachedModulePath;

std::string GetCurrentModulePath()
{
	if (cachedModulePath.empty())
	{
		// get module path
		char modPath[MAX_PATH];
		memset(modPath, 0, sizeof(modPath));
		GetModuleFileNameA((HMODULE)&__ImageBase, modPath, sizeof(modPath));
		for (size_t i = strlen(modPath); i > 0; i--)
		{
			if (modPath[i - 1] == '\\')
			{
				modPath[i] = 0;
				break;
			}
		}
		cachedModulePath = modPath;
	}
	return cachedModulePath;
}

int idTextureAztral;

int idTextureSpeedoBack, idTextureSpeedoArrow;

DX11Hook* dxhook = new DX11Hook();

int create_texture(std::string name)
{
	printf("CT IND \n");
	//std::string path2 = GetCurrentModulePath(); // includes trailing slash

	wchar_t path[MAX_PATH];
	char target[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result == S_OK)
	{
		wcstombs(target, path, MAX_PATH);
		std::string path1 = "\\AztralFiles\\" + name;
		strcat(target, path1.c_str());
		printf("%s \n", target);
	}
	else
		printf("Result not OK\n");

	return dxhook->CreateTexture(target);
}

void create_textures()
{
	printf("CT Start \n");
	idTextureAztral = create_texture("aztralmain.png");
	idTextureSpeedoBack = create_texture("NativeSpeedoBack.png");
	idTextureSpeedoArrow = create_texture("NativeSpeedoArrow.png");
	printf("Aztral Texture ID: %s \n", std::to_string(idTextureAztral));
}

void draw_speedo(float speed, float alpha)
{
	printf("Draw Start\n");
	float rotation = speed * 2.51f /*as miles*/ * 1.6f /*as kilometers*/ / 320.0f /*circle max*/ + 0.655f /*arrow initial rotation*/;
	float screencorrection = GRAPHICS::_GET_ASPECT_RATIO(FALSE);
	dxhook->DrawTexture(idTextureSpeedoBack, 0, -9998, 100, 0.2f, 0.2f, 0.5f, 0.5f, 0.9f, 0.9f, 0.0f, screencorrection, 1.0f, 1.0f, 1.0f, alpha);
	dxhook->DrawTexture(idTextureSpeedoArrow, 0, -9997, 100, 0.25f, 0.25f, 0.5f, 0.5f, 0.9f, 0.9f, rotation, screencorrection, 1.0f, 1.0f, 1.0f, alpha);
	dxhook->DrawTexture(idTextureAztral, 0, -9999, 100, 0.21f, 0.085f, 0.5f, 0.5f, 0.8f, 0.1175f, 0.0f, screencorrection, 1.0f, 1.0f, 1.0f, alpha);
}

float speedoAlpha;

void update()
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	// check if player ped exists and control is on (e.g. not in a cutscene)
	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || !PLAYER::IS_PLAYER_CONTROL_ON(player))
		return;

	// check for player ped death and player arrest
	if (ENTITY::IS_ENTITY_DEAD(playerPed) || PLAYER::IS_PLAYER_BEING_ARRESTED(player, TRUE))
		return;

	// check if player is in a vehicle and vehicle name isn't being displayed as well as player's phone
	const int HUD_VEHICLE_NAME = 6;
	if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE) || UI::IS_HUD_COMPONENT_ACTIVE(HUD_VEHICLE_NAME) || PED::IS_PED_RUNNING_MOBILE_PHONE_TASK(playerPed))
	{
		speedoAlpha = 0.0f;
		return;
	}

	// speedo alpha
	const float speedoAlphaMax = 0.8f;
	if (speedoAlpha < 0.0f) speedoAlpha = 0.0f;
	if (speedoAlpha < speedoAlphaMax) speedoAlpha += 0.01f;
	if (speedoAlpha > speedoAlphaMax) speedoAlpha = speedoAlphaMax;

	// speed
	float speed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_USING(playerPed));

	// draw textures
	draw_speedo(speed, speedoAlpha);
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main() 
{
	printf("Main \n");
	create_textures();
	printf("Create Tex Done \n");
	while (true) 
	{
		Menu::Checks::Controlls();
		Features::UpdatePerTick(); 
		discordmain();
		update();
		
		//Single Player Only Check for SP release:
		//if (NETWORK::NETWORK_IS_SESSION_STARTED() == true) exit(0);
		DoASM();
		CPlayerMem::update_players();
		Player	player = CPlayerMem::player_id();
		Ped		playerPed = CPlayerMem::player_ped_id();
		CPed*	playerCPed = CPlayerMem::get_player_cped(player);
		bool	playerInVeh = false;
		Vehicle playerVeh = NULL;
		bool	playerVehDriver = false;
		DoASM();
		switch (Menu::Settings::currentMenu) {

		case mainmenu:
		{
			
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "aztrallogo", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Aztral DEV"_Secure); 
			//Menu::SubTitle("V1.0"_Secure);
			//Menu::VersionTitle("Legacy"_Secure);
			Menu::MenuOption("Self ~b~->"_Secure, self);
			Menu::MenuOption("Online Players ~b~->"_Secure, onlineplayers);
			Menu::MenuOption("All Players ~b~->"_Secure, allplayers);
			Menu::MenuOption("SuperPowers~b~->"_Secure, SuperPowers);
			Menu::MenuOption("Vehicle's ~b~->"_Secure, vehicleoptions);
			Menu::MenuOption("INI Spawner ~b~->"_Secure, inispawner);
			Menu::MenuOption("Weapon's ~b~->"_Secure, weaponoptions);
			Menu::MenuOption("Teleport's ~b~->"_Secure, teleport);
			Menu::MenuOption("World Options ~b~->"_Secure, world);
			Menu::MenuOption("Prop Spawner ~b~->"_Secure, propplacement);
			Menu::MenuOption("Settings ~b~->"_Secure, settings);
			Menu::MenuOption("Recovery ~b~->"_Secure, recovery);
			Menu::MenuOption("Protection Options ~b~->"_Secure, protections);
			Menu::MenuOption("Miscellaneous ~b~->"_Secure, miscellaneous);
			/*if (Menu::Option("DX Testing"_Secure)) 
			{
				GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
				GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
				GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			};*/
			Menu::Toggle("~r~Use Hotkey Configs"_Secure, Features::CheckConfigBool, [] {Features::CheckConfig(Features::CheckConfigBool); });
			Menu::Toggle("~r~Use Auto On Configs"_Secure, Features::CheckAutoBool, [] {Features::CheckAuto(Features::CheckAutoBool); });
			Menu::Toggle("~g~Mouse Control"_Secure, Features::MouseControlBool, [] {Features::MouseControl(Features::MouseControlBool); });
			notifyMap("~r~Re-open the menu to re-check configs"_Secure, 0);
			notifyMap("~g~ Aztral Engine : Online"_Secure, 0);
			/*if (Menu::Option("Change Name")) 
			{
				string newname = show_keyboard("New Name:", NULL);
				if (setPlayerName(newname))
					notifyMap("~g~Name changed"_Secure);
				else
					notifyMap("~r~Name change failed"_Secure);

			};*/
			Global::CheckCfig();
			DoASM();
			
		}
		break;
		case SuperPowers:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("SuperPowers"_Secure);
			Menu::Toggle("Animation with powers"_Secure, Features::poweranimated);
			Menu::Int("Gravity (0=Normal, 3=ZeroG)"_Secure, grav, 0, 3);
			if (Menu::Option("Fuck Gravity"_Secure)) { GAMEPLAY::SET_GRAVITY_LEVEL(grav); }
			if (Menu::Option("Zeus"_Secure)) { GAMEPLAY::_CREATE_LIGHTNING_THUNDER(); }
			Menu::Toggle("Kill Peds"_Secure, Features::killpedsbool, [] { Features::killpeds(Features::killpedsbool); });
			Menu::Toggle("Explode Peds"_Secure, Features::explodepedsbool, [] { Features::explodepeds(Features::explodepedsbool); });
			Menu::Toggle("Explode Nearby Cars"_Secure, Features::explodenearbyvehiclesbool, [] { Features::explodenearbyvehicles(Features::explodenearbyvehiclesbool); });
			Menu::Toggle("Delete Nearby Cars"_Secure, Features::deletenearbyvehiclesbool, [] { Features::deletenearbyvehicles(Features::deletenearbyvehiclesbool); });
			Menu::Toggle("Upgrade Nearby Cars"_Secure, Features::Upgradecarsbool, [] { Features::Upgradecars(Features::Upgradecarsbool); });
			Menu::Toggle("Rainbow Nearby Cars"_Secure, Features::Rainbowcarbool, [] { Features::Rainbowcar(Features::Rainbowcarbool); });
			Menu::Toggle("Launch Nearby Vehicles"_Secure, Features::ForceWavebool, [] { Features::ForceWave(Features::ForceWavebool); });
			Menu::Toggle("Vehicle Wave"_Secure, Features::magnetpedsbool, [] { Features::magnetpeds(Features::magnetpedsbool); });
			Menu::Toggle("~b~Forcefield"_Secure, Features::forcefieldbool, [] { Features::forcefield(Features::forcefieldbool); });
			Menu::Toggle("~p~Black Hole"_Secure, Features::black_hole_bool, [] { Features::black_hole(Features::black_hole_bool); });
			Menu::Toggle("~r~The Purge"_Secure, Features::purgebool, [] { Features::purge(Features::purgebool); });
			Menu::Toggle("~o~Gravity Gun"_Secure, Features::GravityGun, [] { Features::GravityGunLoop(Features::GravityGun); });
			Menu::Toggle("~g~Delete Objects Gun"_Secure, Features::RemoveObjects, [] { Features::RemoveObjectsLoop(Features::RemoveObjects); });
			DoASM();
		}
		break;
#pragma region Protections
		case protections:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Self Protection"_Secure);
			Menu::Toggle("No moneybags"_Secure, Features::antimoneydrop, [] { Features::MoneyDropBypass(Features::antimoneydrop); });
			Menu::Toggle("Anti Explosion"_Secure, Features::antiexplosion, [] { Features::AntiFireExplosion(Features::antiexplosion); });
			Menu::Toggle("Anti TP"_Secure, Features::antitp, [] { Features::TPProtex(Features::antitp); });
			Menu::Toggle("Anti Remote"_Secure, Features::antiremotetoggle, [] { Features::AntiRemote(Features::antiremotetoggle); });
			Menu::Toggle("Anti Remove Weapons"_Secure, Features::antiremoveweptoggle, [] { Features::RemoveWeaponProtex(Features::antiremoveweptoggle); });
			Menu::Toggle("Anti PTFX"_Secure, Features::antiptfxtoggle, [] { Features::PTFXProtex(Features::antiptfxtoggle); });
			Menu::Toggle("Anti Vote-kick"_Secure, Features::antivotekickbool, [] { Features::antivotekick(Features::antivotekickbool); });
			Menu::Toggle("Anti Freeze"_Secure, Features::antifreeze, [] { Features::FreezeProtex(Features::antifreeze); });
			Menu::Toggle("Anti Blame"_Secure, Features::antiblametoggle, [] { Features::AntiBlame(Features::antiblametoggle); });
			if (Menu::Option("Extreme Detatch"_Secure)) 
			{
				for (int i = 0; i < 10; i++)
				{
					Entity ent = ENTITY::GET_ENTITY_ATTACHED_TO(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));

					ENTITY::DELETE_ENTITY(&ent);

					//ENTITY::DETACH_ENTITY(Entity entity, BOOL p1, BOOL collision)
				}
			};
			DoASM();
			notifyMap("~b~ Need that condom?"_Secure, 0);
		}
		break;
#pragma endregion
#pragma region Weather Options
		case weather:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Weather"_Secure);
			if (Menu::Option("Clear Weather"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			if (Menu::Option("Rain"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
			if (Menu::Option("Fog"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
			if (Menu::Option("Blizzard"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			if (Menu::Option("Stormy"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			if (Menu::Option("Clouds"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }
			if (Menu::Option("Overcast"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			if (Menu::Option("Snow"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Snowlight"); }
			if (Menu::Option("Xmas"_Secure)) { GAMEPLAY::CLEAR_WEATHER_TYPE_PERSIST(); GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("XMAS"); }
			DoASM();
		}
		break;
#pragma endregion
#pragma region World Options
		case world:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("World Options"_Secure);
			DoASM();
			Menu::MenuOption("Weather Options ~b~->"_Secure, weather);
			Menu::Int("Choose Time"_Secure, timeer, 0, 14);
			if (Menu::Option("Set Time"_Secure)) { Hooking::network_override_clock_time(timeer, 0, 0); }
			DoASM();
		}
		break;
#pragma endregion
#pragma region inispawner
		case inispawner:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("INI Spawner"_Secure);
			std::vector<std::wstring> fileArray;
			wchar_t path[MAX_PATH];
			char target2[MAX_PATH];
			HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
			if (result == S_OK)
				wcstombs(target2, path, MAX_PATH);
			strcat(target2, "\\AztralFiles\\INIs\\*.ini"_Secure);
			wstring inidirectory = Global::Widen(target2);
			WIN32_FIND_DATAW ffd;
			HANDLE hFind = FindFirstFileW(inidirectory.c_str(), &ffd);
			if (hFind != INVALID_HANDLE_VALUE)
			{
				do
				{
					if ((ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
						fileArray.push_back(ffd.cFileName);
				} while (FindNextFileW(hFind, &ffd));
				FindClose(hFind);
			}
			for (wstring& file : fileArray) {
				// process file
				const char* filename = Global::WstringToChar(file);
				std::string filenameAsm(filename);
				filenameAsm = filenameAsm.substr(0, filenameAsm.find_last_of("."));
				const char* filename2 = filenameAsm.c_str();
				if (Menu::Option(filename2))
				{
					Features::inispawner(filename);
				};
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region Recovery
		case recovery:
		  {
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Recovery"_Secure);
			Menu::MenuOption("Money Shit ~b~=)"_Secure, mazebank);
			Menu::MenuOption("Rank Options ~b~->"_Secure, rankoptions);
		    if (Menu::Option("Max Stats"_Secure)) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SCRIPT_INCREASE_MECH"), 100, 0);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Unlock All"_Secure)) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);

				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);//admin bullshit
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Unlock Tattoos"_Secure)) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_tattoo_fm_unlocks_12"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Unlock Clothes"_Secure)) {
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH_2"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_0"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_8"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_9"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_10"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_11"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_12"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_13"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_14"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_15"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_16"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_17"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_18"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_19"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_20"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_21"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_22"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_23"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_24"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_25"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_26"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_27"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_28"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_29"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_30"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_31"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_32"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_33"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_34"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_35"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_36"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_37"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_38"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_39"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_40"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_41"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_42"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_43"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_44"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_45"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_46"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_47"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_48"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_49"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_50"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_51"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_52"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_53"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_54"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_55"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_56"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_57"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_58"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_59"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_60"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_61"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_62"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_63"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_64"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_65"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_66"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_67"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_68"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_69"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_70"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_71"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_72"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_73"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_74"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_75"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_76"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_77"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_78"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_79"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_80"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_81"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_82"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_83"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_84"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_85"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_86"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_87"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_88"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_89"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_90"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_91"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_92"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_93"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_94"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_95"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_96"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_97"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_98"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_99"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_100"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_101"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_102"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_103"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_104"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_105"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_106"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_107"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_108"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_109"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_110"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_111"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_112"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_113"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_114"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_115"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_116"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_117"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_118"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_119"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_120"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_121"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_122"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_123"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_124"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_125"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_126"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_127"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_128"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_129"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_130"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_131"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_132"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_133"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_134"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_135"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_136"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_137"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_138"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_139"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_140"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_141"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_142"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_143"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_144"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_145"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_146"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_147"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_148"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_149"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_150"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_151"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_152"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DLC_APPAREL_ACQUIRED_153"), -1, 1);
				}
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_8"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_9"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_10"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_11"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_12"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_13"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_14"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_15"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_16"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_17"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_18"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_19"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_20"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_21"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_CLOTHES_GV_BS_22"), -1, 1);
				}
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Max Wins And Kills"_Secure)) {
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 0);
				STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 0);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 0);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Unlock All Heist Vehicles"_Secure))
			{
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_1_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_VEHICLE_2_UNLCK"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("2 billion Snacks + Armor + Fireworks"_Secure))
			{
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_YUM_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_HEALTH_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NO_BOUGHT_EPIC_SNACKS"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_OF_ORANGE_BOUGHT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CIGARETTES_BOUGHT"), 2000000000, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_1_COUNT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_2_COUNT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_3_COUNT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_4_COUNT"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MP_CHAR_ARMOUR_5_COUNT"), 2000000000, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_1_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_2_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_3_BLUE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_WHITE"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_RED"), 2000000000, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_FIREWORK_TYPE_4_BLUE"), 2000000000, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			}
			if (Menu::Option("Unlock all Parachutes and Camos"_Secure)) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_1_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_2_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_3_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_4_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_5_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_6_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_7_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_8_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_9_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_10_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_11_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_12_FM_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_KIT_FM_PURCHASE12"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			};
			if (Menu::Option("Unlock All Vehicle Mods"_Secure)) {
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_RACES_WON"), 50, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_1_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_2_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_3_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_4_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_5_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_6_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_CARMOD_7_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONDRIVE"), 1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMRALLYWONNAV"), 1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINSEARACE"), 1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FMWINAIRRACE"), 1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_TURBO_STARTS_IN_RACE"), 50, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_AWD_FM_RACES_FASTEST_LAP"), 50, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NUMBER_SLIPSTREAMS_IN_RACE"), 100, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			};
			if (Menu::Option("Unlock All Weapons"_Secure)) 
			{ 
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KNIFE_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NIGHTSTICK_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CROWBAR_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SHOVEL_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HAMMER_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WRENCH_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BAT_IN_POSSESSION"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GCLUB_IN_POSSESSION"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED3"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE3"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_6_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_7_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_8_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_9_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_10_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_11_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_12_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_13_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_14_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_15_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_16_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_17_UNLCK"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_18_UNLCK"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH13"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH14"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH15"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH16"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH17"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH18"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			};
			if (Menu::Option("Unlock All Vehicles"_Secure))
			{
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_6"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_7"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_8"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_9"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_10"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_11"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_12"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_BS_13"), -1, 1);

				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_1"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_2"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_3"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_4"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_5"), -1, 1);
				STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_VEH_GV_NONBY_6"), -1, 1);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
			};
			if (Menu::Option("Remove Orbital Cannon Cooldown"_Secure)) { STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, 1); AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1); };
			if (Menu::Option("Redesign Character"_Secure)) { STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_FM_CHANGECHAR_ASKED"), 0, 1); AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region RP Menu
				case rankoptions:
				 {
					DoASM();
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
					GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
					GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
					 Menu::Title("RP Options"_Secure);
					 Menu::Toggle("Wanted loop method ~g~[Great for Crew Rank]"_Secure, Features::RPLoop, [] {});// this may be unreliable
					 //if (Menu::Option("Set Rank (Min=1, Max=8000)"_Secure)) { Features::SetRank(NumberKeyboard()); }
					 if (Menu::Option("Rank Correction"))
					 {
						 int rank = NumberKeyboard();
						 if (rank <= 8000 && rank > 0)
						 {
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_SET_RP_GIFT_ADMIN"), Features::Levels[(rank - 1)], 1);
							 AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
							 notifyMap("~g~Please change session to apply rank");//CASH_FIX_PVC_WB_CORRECTION
						 }
						 else notifyMap("~r~Enter A Level Between 1-8000!");
					 }
					 /*if (Menu::Option("Get Balance"_Secure)) 
					 {
						 int cash;
						 STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PVC_BALANCE"), &cash, -1);
						 Features::WriteToFile("coords.txt", "PVC_BAL:" + std::to_string(cash));

						 STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BALANCE"), &cash, -1);
						 Features::WriteToFile("coords.txt", "EVC_BAL:" + std::to_string(cash));

						 STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PVC_BANK_BALANCE"), &cash, -1);
						 Features::WriteToFile("coords.txt", "PVC_BANK_BAL:" + std::to_string(cash));

						 STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BANK_BALANCE"), &cash, -1);
						 Features::WriteToFile("coords.txt", "EVC_BANK_BAL:" + std::to_string(cash));
						 
						 STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BANK_BALANCE_CLEARED"), &cash, -1);
						 Features::WriteToFile("coords.txt", "PVC_BANK_BAL:" + std::to_string(cash));
					 };
					 if (Menu::Option("Balance Correction"))
					 {
						 int cash1 = NumberKeyboard();
						 if (cash1 > 0)
						 {
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PVC_BALANCE"), cash1, 1);
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BALANCE"), cash1, 1);
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_PVC_BANK_BALANCE"), cash1, 1);
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BANK_BALANCE"), cash1, 1);
							 STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_EVC_BANK_BALANCE_CLEARED"), cash1, 1);
							 AUDIO::PLAY_SOUND_FRONTEND(-1, "CHALLENGE_UNLOCKED", "HUD_AWARDS", 1);
							 notifyMap("~g~Please change session to apply rank");//CASH_FIX_PVC_WB_CORRECTION
						 }
						 else notifyMap("~r~Enter A Cash Greater than 0");
					 }*/
					Menu::Option("~r~This can only be used in online.");
					DoASM();
				 }
				 break;
#pragma endregion
#pragma region Model Changer
				case modelchanger:
				{
					DoASM();
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
					GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
					GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
					Menu::Title("Weapon Modifiers"_Secure);
					Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
					Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

					string vehHealth1 = "Bullet Damage [Current: " + std::to_string(Get_BulletDamage()) + "]";

					string vehHealth2 = "Bullet Mass [Current: " + std::to_string(Get_BulletMass1()) + "]";

					string vehBoost = "Muzzle Flash Size [Current: " + std::to_string(Get_MuzzleFlashSize()) + "]";

					string vehAcceleration = "Muzzle Velocity [Current: " + std::to_string(Get_MuzzleVelocity()) + "]";

					string vehBrakeForce = "Reload Speed [Current: " + std::to_string(Get_ReloadSpeed()) + "]";

					string vehHandBrakeForce = "Weapon Spread [Current: " + std::to_string(Get_WeaponSpread()) + "]";

					string vehDeformMultiplier = "Weapon Recoil [Current: " + std::to_string(Get_WeaponRecoil()) + "]";

					string vehDirtLevel = "Recoil [Current: " + std::to_string(Get_Recoil()) + "]";

					string vehGravity = "Spread [Current: " + std::to_string(Get_Spread()) + "]";

					string vehRocketFuelLevel = "Melee Damage Multiplier [Current: " + std::to_string(Get_MeleeDamageMultiplier()) + "]";

					string vehRocketRechargeSpeed = "Damage Multiplier [Current: " + std::to_string(Get_DamageMultiplier()) + "]";

					if (Menu::Option(vehHealth1.c_str())) { Set_BulletDamage(NumberKeyboard()); };
					if (Menu::Option(vehHealth2.c_str())) { Set_BulletMass(NumberKeyboard()); };
					if (Menu::Option(vehBoost.c_str())) { Set_MuzzleFlashSize(NumberKeyboard()); };
					if (Menu::Option(vehAcceleration.c_str())) { Set_MuzzleVelocity(NumberKeyboard()); };
					if (Menu::Option(vehBrakeForce.c_str())) { Set_ReloadSpeed(NumberKeyboard()); };
					if (Menu::Option(vehHandBrakeForce.c_str())) { Set_WeaponSpread(NumberKeyboard()); };
					if (Menu::Option(vehDeformMultiplier.c_str())) { Set_WeaponRecoil(NumberKeyboard()); };
					if (Menu::Option(vehDirtLevel.c_str())) { Set_Recoil(NumberKeyboard()); };
					if (Menu::Option(vehGravity.c_str())) { Set_Spread(NumberKeyboard()); };
					if (Menu::Option(vehRocketFuelLevel.c_str())) { Set_MeleeDamageMultiplier(NumberKeyboard()); };
					if (Menu::Option(vehRocketRechargeSpeed.c_str())) { Set_DamageMultiplier(NumberKeyboard()); };
					DoASM();
				}
				break;
#pragma endregion
#pragma region Model Spawner
				case modelspawner:
				{
					DoASM();
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
					GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
					GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
					Menu::Title("Player Modifications"_Secure);
					Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
					Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

					string vehHealth1 = "Stamina [Current: " + std::to_string(Get_Stamina()) + "]";

					string vehHealth2 = "Sprint Speed [Current: " + std::to_string(Get_SprintSpeed()) + "]";

					string vehBoost = "Swim Speed [Current: " + std::to_string(Get_SwimSpeed()) + "]";

					if (Menu::Option(vehHealth1.c_str())) { Set_Stamina(NumberKeyboard()); };
					if (Menu::Option(vehHealth2.c_str())) { Set_SprintSpeed(NumberKeyboard()); };
					if (Menu::Option(vehBoost.c_str())) { Set_SwimSpeed(NumberKeyboard()); };
					DoASM();
				}
				break;
#pragma endregion
#pragma region  PTFX shit
				case PTFXS:
				{
					DoASM();
					Menu::Title("PTFX"_Secure);
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
					GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
					GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
					Menu::Toggle("Looped"_Secure, Features::PTFXBool);
					/*
					extern bool PTFXBool;
					void PTFXCALL();

					Features::call1s;
					Features::call2s;
					Features::names;
					*/
					DoASM();
					if (Menu::Option("Clown Appears"_Secure)) { Features::call1s = "scr_rcbarry2"; Features::call2s = "scr_rcbarry2"; Features::names = "scr_clown_appears"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 1"_Secure)) { Features::call1s = "scr_indep_fireworks"; Features::call2s = "scr_indep_fireworks"; Features::names = "scr_indep_firework_trailburst"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 2"_Secure)) { Features::call1s = "proj_xmas_firework"; Features::call2s = "proj_xmas_firework"; Features::names = "scr_firework_xmas_burst_rgw"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 3"_Secure)) { Features::call1s = "proj_xmas_firework"; Features::call2s = "proj_xmas_firework"; Features::names = "scr_firework_xmas_spiral_burst_rgw"; Features::PTFXCALL(); };
					if (Menu::Option("Banknotes"_Secure)) { Features::call1s = "scr_ornate_heist"; Features::call2s = "scr_ornate_heist"; Features::names = "scr_heist_ornate_banknotes"; Features::PTFXCALL(); };
					if (Menu::Option("Truck Crash"_Secure)) { Features::call1s = "scr_fbi4"; Features::call2s = "scr_fbi4"; Features::names = "scr_fbi4_trucks_crash"; Features::PTFXCALL(); };
					if (Menu::Option("Alien 1"_Secure)) { Features::call1s = "scr_rcbarry1"; Features::call2s = "scr_rcbarry1"; Features::names = "scr_alien_disintegrate"; Features::PTFXCALL(); };
					if (Menu::Option("Alien 2"_Secure)) { Features::call1s = "scr_rcbarry1"; Features::call2s = "scr_rcbarry1"; Features::names = "scr_alien_teleport"; Features::PTFXCALL(); };
					if (Menu::Option("Electric Box"_Secure)) { Features::call1s = "scr_agencyheistb"; Features::call2s = "scr_agencyheistb"; Features::names = "scr_agency3b_elec_box"; Features::PTFXCALL(); };
					if (Menu::Option("Water Splash"_Secure)) { Features::call1s = "scr_fbi5a"; Features::call2s = "scr_fbi5a"; Features::names = "scr_fbi5_ped_water_splash"; Features::PTFXCALL(); };
					if (Menu::Option("Bubbles"_Secure)) { Features::call1s = "scr_fbi5a"; Features::call2s = "scr_fbi5a"; Features::names = "water_splash_ped_bubbles"; Features::PTFXCALL(); };
					if (Menu::Option("Blood Entry"_Secure)) { Features::call1s = "scr_finalec2"; Features::call2s = "scr_finalec2"; Features::names = "scr_finale2_blood_entry"; Features::PTFXCALL(); };
					if (Menu::Option("Sniper Impact"_Secure)) { Features::call1s = "scr_martin1"; Features::call2s = "scr_martin1"; Features::names = "scr_sol1_sniper_impact"; Features::PTFXCALL(); };
					if (Menu::Option("Dirt Throw"_Secure)) { Features::call1s = "core_snow"; Features::call2s = "core_snow"; Features::names = "cs_mich1_spade_dirt_throw"; Features::PTFXCALL(); };
					if (Menu::Option("Blood Stab"_Secure)) { Features::call1s = "scr_michael2"; Features::call2s = "scr_michael2"; Features::names = "scr_mich2_blood_stab"; Features::PTFXCALL(); };
					if (Menu::Option("Ped Sliced"_Secure)) { Features::call1s = "scr_michael2"; Features::call2s = "scr_michael2"; Features::names = "scr_abattoir_ped_sliced"; Features::PTFXCALL(); };
					if (Menu::Option("Camera"_Secure)) { Features::call1s = "scr_rcpaparazzo1"; Features::call2s = "scr_rcpaparazzo1"; Features::names = "scr_rcpap1_camera"; Features::PTFXCALL(); };
					if (Menu::Option("Meth Smoke"_Secure)) { Features::call1s = "scr_familyscenem"; Features::call2s = "scr_familyscenem"; Features::names = "scr_meth_pipe_smoke"; Features::PTFXCALL(); };
					if (Menu::Option("Burial Dirt"_Secure)) { Features::call1s = "scr_reburials"; Features::call2s = "scr_reburials"; Features::names = "scr_burial_dirt"; Features::PTFXCALL(); };
					DoASM();
				}
				break;
				case PTFXSO:
				{//the online player caller may crash user no biggie just unfinished
					GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
					GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
					GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
					Menu::Title("PTFX"_Secure);
					Menu::Toggle("Looped"_Secure, Features::PTFXOBool);
					DoASM();
					/*
					extern bool PTFXOBool;
					void PTFXCALLO();

					Features::call1o;
					Features::call2o;
					Features::nameo;
					Features::target;
					*/
					DoASM();
					if (Menu::Option("Clown Appears"_Secure)) { Features::call1o = "scr_rcbarry2"; Features::call2o = "scr_rcbarry2"; Features::nameo = "scr_clown_appears"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 1"_Secure)) { Features::call1o = "scr_indep_fireworks"; Features::call2o = "scr_indep_fireworks"; Features::nameo = "scr_indep_firework_trailburst"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 2"_Secure)) { Features::call1o = "proj_xmas_firework"; Features::call2o = "proj_xmas_firework"; Features::nameo = "scr_firework_xmas_burst_rgw"; Features::PTFXCALL(); };
					if (Menu::Option("Firework 3"_Secure)) { Features::call1o = "proj_xmas_firework"; Features::call2o = "proj_xmas_firework"; Features::nameo = "scr_firework_xmas_spiral_burst_rgw"; Features::PTFXCALL(); };
					if (Menu::Option("Banknotes"_Secure)) { Features::call1o = "scr_ornate_heist"; Features::call2o = "scr_ornate_heist"; Features::nameo = "scr_heist_ornate_banknotes"; Features::PTFXCALL(); };
					if (Menu::Option("Truck Crash"_Secure)) { Features::call1o = "scr_fbi4"; Features::call2o = "scr_fbi4"; Features::nameo = "scr_fbi4_trucks_crash"; Features::PTFXCALL(); };
					if (Menu::Option("Alien 1"_Secure)) { Features::call1o = "scr_rcbarry1"; Features::call2o = "scr_rcbarry1"; Features::nameo = "scr_alien_disintegrate"; Features::PTFXCALL(); };
					if (Menu::Option("Alien 2"_Secure)) { Features::call1o = "scr_rcbarry1"; Features::call2o = "scr_rcbarry1"; Features::nameo = "scr_alien_teleport"; Features::PTFXCALL(); };
					if (Menu::Option("Electric Box"_Secure)) { Features::call1o = "scr_agencyheistb"; Features::call2o = "scr_agencyheistb"; Features::nameo = "scr_agency3b_elec_box"; Features::PTFXCALL(); };
					if (Menu::Option("Water Splash"_Secure)) { Features::call1o = "scr_fbi5a"; Features::call2o = "scr_fbi5a"; Features::nameo = "scr_fbi5_ped_water_splash"; Features::PTFXCALL(); };
					if (Menu::Option("Bubbles"_Secure)) { Features::call1o = "scr_fbi5a"; Features::call2o = "scr_fbi5a"; Features::nameo = "water_splash_ped_bubbles"; Features::PTFXCALL(); };
					if (Menu::Option("Blood Entry"_Secure)) { Features::call1o = "scr_finalec2"; Features::call2o = "scr_finalec2"; Features::nameo = "scr_finale2_blood_entry"; Features::PTFXCALL(); };
					if (Menu::Option("Sniper Impact"_Secure)) { Features::call1o = "scr_martin1"; Features::call2o = "scr_martin1"; Features::nameo = "scr_sol1_sniper_impact"; Features::PTFXCALL(); };
					if (Menu::Option("Dirt Throw"_Secure)) { Features::call1o = "core_snow"; Features::call2o = "core_snow"; Features::nameo = "cs_mich1_spade_dirt_throw"; Features::PTFXCALL(); };
					if (Menu::Option("Blood Stab"_Secure)) { Features::call1o = "scr_michael2"; Features::call2o = "scr_michael2"; Features::nameo = "scr_mich2_blood_stab"; Features::PTFXCALL(); };
					if (Menu::Option("Ped Sliced"_Secure)) { Features::call1o = "scr_michael2"; Features::call2o = "scr_michael2"; Features::nameo = "scr_abattoir_ped_sliced"; Features::PTFXCALL(); };
					if (Menu::Option("Camera"_Secure)) { Features::call1o = "scr_rcpaparazzo1"; Features::call2o = "scr_rcpaparazzo1"; Features::nameo = "scr_rcpap1_camera"; Features::PTFXCALL(); };
					if (Menu::Option("Meth Smoke"_Secure)) { Features::call1o = "scr_familyscenem"; Features::call2o = "scr_familyscenem"; Features::nameo = "scr_meth_pipe_smoke"; Features::PTFXCALL(); };
					if (Menu::Option("Burial Dirt"_Secure)) { Features::call1o = "scr_reburials"; Features::call2o = "scr_reburials"; Features::nameo = "scr_burial_dirt"; Features::PTFXCALL(); };
					DoASM();
				}
				break;
#pragma endregion
#pragma region Self Menu
		case self:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Self"_Secure);
			//Menu::MenuOption("Vision FX ~b~->"_Secure, visionFX);
			Menu::MenuOption("Player animations ~b~->"_Secure, animateshit);
			//Menu::MenuOption("Model Changer ~b~->"_Secure, modelchanger);
			Menu::MenuOption("Skin Changer"_Secure, skinchanger);
			Menu::MenuOption("Player Modifications ~b~->"_Secure, modelspawner);
			Menu::MenuOption("PTFX ~b~->"_Secure, PTFXS);
			Menu::Toggle("Godmode"_Secure, Features::Godmodebool, [] { Features::Godmode(Features::Godmodebool); });
			Menu::Toggle("Semi-Godmode"_Secure, Features::SemiGodModebool, [] { Features::SemiGodMode(Features::SemiGodModebool); });
			Menu::Toggle("Invisible"_Secure, Features::Ghostmode, [] { Features::ghostmode(Features::Ghostmode); });
			Menu::Toggle("Super Jump"_Secure, Features::Superjump, [] { Features::superjump(Features::Superjump); });
			Menu::Toggle("Fast Run"_Secure, Features::fastrunbool, [] { Features::fastrun(Features::fastrunbool); });
			Menu::Toggle("Fast Swim"_Secure, Features::fastswimbool, [] { Features::fastswim(Features::fastswimbool); });
			Menu::Toggle("Off The Radar"_Secure, Features::OffTheRadarBool, [] { Features::OffTheRadar(Features::OffTheRadarBool); });
			Menu::Toggle("Never Wanted"_Secure, Features::neverwanted, [] { Features::NeverGetWanted(Features::neverwanted); });
			Menu::Option("Clean Player", [] { int Ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()); PED::CLEAR_PED_BLOOD_DAMAGE(Ped); PED::RESET_PED_VISIBLE_DAMAGE(Ped); });
			//Menu::MenuOption("Outfit Changer"_Secure, outfits123);
			DoASM();
			if (Menu::Option("Random Outfit"_Secure)) { PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), true); }
			char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };
			if (Menu::Option("Allah Akbar"))
			{
				Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_ENTITY_HEALTH }, 0);
				Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), true);
				FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 5.0f);
				notifyMap("~b~ jihad!", 0);
			}
			DoASM();
			//Menu::MenuOption("Premade outfits ~b~->"_Secure, outfits);
			Menu::Toggle("Super Man"_Secure, Features::Superman);
			Menu::Toggle("No Ragdoll"_Secure, Features::Nothrowshit, [] { Features::NoRagdoll(Features::Nothrowshit); });
			//Menu::Toggle("Shrink"_Secure, Features::Gettiny, [] { Features::Smallstuff(Features::Gettiny); });
			Menu::Toggle("No Clip"_Secure, Features::NoClipping, [] { Features::NoClipme(Features::NoClipping); });
			Menu::Int("Change Wanted Level"_Secure, Features::Wantedshit, 0, 5, [] { Features::ChangeWanted(Features::Wantedshit); });
			DoASM();
			if (Menu::Option("Heal Player"))
			{
				BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				ENTITY::SET_ENTITY_HEALTH(playerPed, ENTITY::GET_ENTITY_MAX_HEALTH(playerPed));
				PED::ADD_ARMOUR_TO_PED(playerPed, PLAYER::GET_PLAYER_MAX_ARMOUR(player) - PED::GET_PED_ARMOUR(playerPed));
				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
				{
					Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
					if (ENTITY::DOES_ENTITY_EXIST(playerVeh) && !ENTITY::IS_ENTITY_DEAD(playerVeh))
						VEHICLE::SET_VEHICLE_FIXED(playerVeh);
				}
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region outfits123
		case outfits123:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Outfit Changer"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			struct compid
			{
				int face, beard, haircut, shirt, pants, gloves, shoes, eyes, acc, items, decals, collars, var;
			};
			compid ID;
			ID.face = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 0);
			ID.beard = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 1);
			ID.haircut = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 2);
			ID.shirt = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 3);
			ID.pants = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 4);
			ID.gloves = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 5);
			ID.shoes = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 6);
			ID.eyes = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 7);
			ID.acc = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 8);
			ID.items = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 9);
			ID.decals = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 10);
			ID.collars = PED::GET_PED_DRAWABLE_VARIATION(playerPed, 11);
			ID.var = 0;
			Menu::Int("Variation of Item"_Secure, ID.var, 0, 25);
			if (Menu::Int("Face"_Secure, ID.face, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 0))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, ID.face, ID.var, 2);
			}
			if (Menu::Int("Beard"_Secure, ID.beard, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 1))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, ID.beard, ID.var, 2);
			}
			if (Menu::Int("Haircut"_Secure, ID.haircut, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 2))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, ID.haircut, ID.var, 2);
			}
			if (Menu::Int("Shirt"_Secure, ID.shirt, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 3))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, ID.shirt, ID.var, 2);
			}
			if (Menu::Int("Pants"_Secure, ID.pants, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 4))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, ID.pants, ID.var, 2);
			}
			if (Menu::Int("Gloves/Hands"_Secure, ID.gloves, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 5))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, ID.gloves, ID.var, 2);
			}
			if (Menu::Int("Shoes"_Secure, ID.shoes, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 6))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, ID.shoes, ID.var, 2);
			}
			if (Menu::Int("Eyes"_Secure, ID.eyes, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 7))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 7, ID.eyes, ID.var, 2);
			}
			if (Menu::Int("Accessories"_Secure, ID.acc, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 8))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, ID.acc, ID.var, 2);
			}
			if (Menu::Int("Mission Items"_Secure, ID.items, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 9))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, ID.items, ID.var, 2);
			}
			if (Menu::Int("Decals"_Secure, ID.decals, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 10))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, ID.decals, ID.var, 2);
			}
			if (Menu::Int("Collars/Inner Shirts"_Secure, ID.collars, 0, PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(playerPed, 11))) {
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, ID.collars, ID.var, 2);
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region skinchanger
		case skinchanger:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Skin Changer"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

			Menu::MenuOption("Saved Models"_Secure, savedskin);

			Menu::MenuOption("Players"_Secure, playerskin);

			Menu::MenuOption("Animals"_Secure, animalskin);
			
			Menu::MenuOption("NPCs"_Secure, npcskin);
			
			Menu::MenuOption("Modify Current Skin"_Secure, modskin);

			if (Menu::Option("Reset Current Skin"_Secure)) { PED::SET_PED_DEFAULT_COMPONENT_VARIATION(playerPed); notifyMap("Using default model skin"_Secure); };
			DoASM();
			Menu::MenuOption("Modify Props"_Secure, propsskin);
			DoASM();
			if (Menu::Option("Clear Props"_Secure)) { PED::CLEAR_ALL_PED_PROPS(playerPed); };
		}
		break;
#pragma endregion
#pragma region propsskin
		case propsskin:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Props"_Secure);
			DWORD waitTime = 150;
			int foundTextures = 0;

			int fixedChoices = 0;
			const int partVariations = 10;

			int count = 0;
			DoASM();
			for (int i = 0; i < partVariations + fixedChoices; i++)
			{
				bool iFound = false;
				int compIndex = i - fixedChoices;

				int drawables = PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), compIndex);
				if (drawables > 0)
				{
					std::ostringstream ss;

					std::string itemText = getPropDetailAttribDescription(compIndex);
					ss << "Slot " << (compIndex + 1) << ": " << itemText << " ~HUD_COLOUR_GREYLIGHT~(" << drawables << ")";
					string caption1 = ss.str();
					const char* itemoption = caption1.c_str();
					if (Menu::MenuOption(itemoption, propsskin1)) 
					{ 
						skinPropsCategoryValue = compIndex; 
						skinDetailMenuIndex = compIndex; 
						skinDetailMenuValue = compIndex; 
						int textures = 0;
						int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue);
						if (skinPropsCategoryValue != currentDrawable)
						{
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue, skinPropsCategoryValue, 0, 0);
						}
					};
					count++;
				}
			}

			if (count == 0)
			{
				Menu::Option("Nothing available for this model"_Secure);
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region propsskin1
		case propsskin1:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Props"_Secure);
			DWORD waitTime = 150;
			int foundTextures = 0;
			DoASM();
			int drawables = PED::GET_NUMBER_OF_PED_PROP_DRAWABLE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinPropsCategoryValue);
			DoASM();
			for (int i = -1; i < drawables; i++)
			{
				bool iFound = false;
				int compIndex = i;

				
				//if (drawables > 1 || textures != 0)
				{
					if (i == -1)
					{
						Menu::Option("Nothing");
					}
					else if (i > -1)
					{
						std::ostringstream ss;
						ss << "Prop Item #" << (i + 1);
						int textures = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinPropsCategoryValue, i);
						string caption1 = ss.str();
						const char* itemoption = caption1.c_str();
						if (Menu::MenuOption(itemoption, propsskin2)) 
						{ 
							skinPropsDrawablePosition[skinPropsCategoryValue] = i; 
							modskincaption2 = caption1; 
							modskinint2 = i; 

							Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
							int currentProp = PED::GET_PED_PROP_INDEX(playerPed, skinPropsCategoryValue);
							if (currentProp != modskinint2) //if the selected drawable is not what we have now
							{
								PED::CLEAR_PED_PROP(playerPed, skinPropsCategoryValue);
								if (modskinint2 != -1)
								{
									PED::SET_PED_PROP_INDEX(playerPed, skinPropsCategoryValue, modskinint2, 0, 0);
								}
							}
						};
					}
				}
			}
		}
		break;
#pragma endregion
#pragma region propsskin2
		case propsskin2:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Props"_Secure);
			int textures = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinPropsCategoryValue, skinPropsDrawablePosition[skinPropsCategoryValue]);
			DoASM();
			if (textures > 1)
			{
				DWORD waitTime = 150;
				int foundTextures = 0;

				int thisDrawable = skinPropsDrawablePosition[skinPropsCategoryValue] - 1;
				int textures = PED::GET_NUMBER_OF_PED_PROP_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinPropsCategoryValue, thisDrawable);

				for (int i = 0; i < textures; i++)
				{
					bool iFound = false;
					int compIndex = i;
					int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue);
					PED::SET_PED_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue, currentDrawable, modskinint2, 0);
					std::ostringstream ss;
					ss << "Texture #" << (i + 1);
					string caption1 = ss.str();
					const char* itemoption = caption1.c_str();
					if (Menu::Option(itemoption)) 
					{ 
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());  
						PED::SET_PED_PROP_INDEX(playerPed, skinPropsCategoryValue, skinPropsDrawablePosition[skinPropsCategoryValue] - 1, i, 0); 
					};
				}
				DoASM();
				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				int lastTexturePosition = PED::GET_PED_PROP_TEXTURE_INDEX(playerPed, skinPropsCategoryValue);
			}
			else { Menu::Option("None Available"_Secure); }
		}
		break;
#pragma endregion
#pragma region savedskin
		case savedskin:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Saved Models"_Secure);
			DoASM();
			ENTDatabase* database = Features::get_database();
			std::vector<SavedSkinDBRow*> savedSkins = database->get_saved_skins();

			lastKnownSavedSkinCount = savedSkins.size();
			DoASM();
			if (Menu::Option("Create New Model Save"_Secure)) { onconfirm_savedskin_menu(-1, "New"); };
			DoASM();
			for each (SavedSkinDBRow *sv in savedSkins)
			{
				int value1 = sv->rowID;
				string caption1 = sv->saveName;
				const char* itemoption = caption1.c_str();
				if (Menu::MenuOption(itemoption, savedskin1)) { savedskinint = value1; onconfirm_savedskin_menu(value1, caption1); };
			}
		}
		break;
#pragma endregion
#pragma region savedskin1
		case savedskin1:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Saved Models"_Secure);
			DoASM();
			if (Menu::Option("Use this Model"_Secure)) { onconfirm_savedskin_slot_menu(1); };

			if (Menu::Option("Overwrite With Current"_Secure)) { onconfirm_savedskin_slot_menu(2); };

			if (Menu::Option("Rename"_Secure)) { onconfirm_savedskin_slot_menu(3); };
			DoASM();
			if (Menu::Option("Delete"_Secure)) { onconfirm_savedskin_slot_menu(4); };

			if (Menu::Option("Spawn As Bodyguard"_Secure)) { onconfirm_savedskin_slot_menu(5); };
		}
		break;
#pragma endregion
#pragma region playerskin
		case playerskin:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Player Models"_Secure);
			DoASM();
			for (int i = 0; i < SKINS_PLAYER_CAPTIONS.size(); i++)
			{
				string caption1 = SKINS_PLAYER_CAPTIONS[i];
				const char* itemoption = caption1.c_str();
				string value1 = SKINS_PLAYER_VALUES[i];
				if (Menu::Option(itemoption)) { onconfirm_skinchanger_choices_players(value1, i); };
			}
		}
		break;
#pragma endregion
#pragma region animalskin
		case animalskin:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Animal Models"_Secure);
			DoASM();
			for (int i = 0; i < SKINS_ANIMAL_CAPTIONS.size(); i++)
			{
				string caption1 = SKINS_ANIMAL_CAPTIONS[i];
				const char* itemoption = caption1.c_str();
				string value1 = SKINS_ANIMAL_VALUES[i];
				if (Menu::Option(itemoption)) { onconfirm_skinchanger_choices_animals(value1, i); };
			}
		}
		break;
#pragma endregion
#pragma region npcskin
		case npcskin:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("NPC Models"_Secure);
			for (int i = 0; i < SKINS_GENERAL_CAPTIONS.size(); i++)
			{
				string caption1 = SKINS_GENERAL_CAPTIONS[i];
				const char* itemoption = caption1.c_str();
				string value1 = SKINS_GENERAL_VALUES[i];
				if (Menu::Option(itemoption)) { onconfirm_skinchanger_choices_misc(value1, i); };
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region modskin
		case modskin:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Model"_Secure);
			DWORD waitTime = 150;
			int foundTextures = 0;

			int fixedChoices = 0;
			const int partVariations = 12;
			DoASM();
			int i = 0;
			DoASM();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);

			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model))
				{

					WAIT(0);
				}

				for (; i < partVariations + fixedChoices; i++)
				{
					bool iFound = false;
					int compIndex = i - fixedChoices;

					int drawables = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), compIndex);
					int textures = 0;
					if (drawables == 1)
					{
						textures = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), compIndex, 0);
					}
					if (drawables > 1 || textures != 0)
					{
						std::ostringstream ss;
						std::string itemText = getSkinDetailAttribDescription(compIndex);
						ss << "Slot " << (compIndex + 1) << ": " << itemText << " ~HUD_COLOUR_GREYLIGHT~(" << drawables << ")";

						string caption1 = ss.str();
						const char* itemoption = caption1.c_str();
						if (Menu::MenuOption(itemoption, modskin1)) 
						{ 
							modskincaption = caption1; 
							modskinint = i; 
							skinDetailMenuIndex = i; 
							skinDetailMenuValue = i;
						};
					}
				}

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				DoASM();
			}
		}
		break;
#pragma endregion
#pragma region modskin1
		case modskin1:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Model"_Secure);
			DWORD waitTime = 150;
			int foundTextures = 0;
			DoASM();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);

			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model))
				{
					DoASM();
					WAIT(0);
				}

				

				int drawables = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), modskinint);
				for (int i = 0; i < drawables; i++)
				{
					int textures = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), modskinint, i);
					std::ostringstream ss;
					ss << "Drawable #" << i << " ~HUD_COLOUR_GREYLIGHT~(" << textures << ")";
					DoASM();
					string caption1 = ss.str();
					const char* itemoption = caption1.c_str();
					if (Menu::MenuOption(itemoption, modskin2)) 
					{ 
						modskincaption1 = caption1; 
						int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue);
						if (i != currentDrawable)
						{
							PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), skinDetailMenuValue, i, 0, 0);
						}
					};
				}

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}

			std::ostringstream ss;
			ss << "Available Drawables";
			DoASM();
			int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), modskinint);
		}
		break;
#pragma endregion
#pragma region modskin2
		case modskin2:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_highendfashion", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_highendfashion");
			GRAPHICS::DRAW_SPRITE("shopui_title_highendfashion", "shopui_title_highendfashion", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Modify Model"_Secure);
			DWORD waitTime = 150;
			int foundTextures = 0;
			DoASM();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Hash model = ENTITY::GET_ENTITY_MODEL(playerPed);

			if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
			{
				STREAMING::REQUEST_MODEL(model);
				while (!STREAMING::HAS_MODEL_LOADED(model))
				{
					DoASM();
					WAIT(0);
				}

				int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue);
				int textures = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue, currentDrawable);
				for (int i = 0; i < textures; i++)
				{
					std::ostringstream ss;
					ss << "Texture #" << i;
					string caption1 = ss.str();
					const char* itemoption = caption1.c_str();
					if (Menu::Option(itemoption)) { int currentDrawable = PED::GET_PED_DRAWABLE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue); PED::SET_PED_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue, currentDrawable, i, 0); };
				}

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
			}

			std::ostringstream ss;
			ss << "Available Textures";

			int currentTexture = PED::GET_PED_TEXTURE_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), skinDetailMenuValue);
		}
		break;
#pragma endregion
#pragma region Weapon Menu
		case weaponoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Weapons"_Secure);
			DoASM();
			Menu::MenuOption("Weapon Modifiers ~b~->"_Secure, modelchanger);
			if (Menu::Option("Give All Weapons"_Secure)) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), Weapons[i], 9999, 1);
				}
			}
			if (Menu::Option("Give All Mk2 Weapons"_Secure)) {
				{
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_1"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ADMIN_WEAPON_GV_BS_3"), -1, 1);

					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BOTTLE_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_KNIFE_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_NIGHTSTICK_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CROWBAR_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_SHOVEL_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_HAMMER_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WRENCH_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_BAT_IN_POSSESSION"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_GCLUB_IN_POSSESSION"), -1, 1);

					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_UNLOCKED3"), -1, 1);

					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_WEAP_FM_PURCHASE3"), -1, 1);

					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_1_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_2_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_3_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_4_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_5_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_6_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_7_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_8_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_9_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_10_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_11_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_12_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_13_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_14_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_15_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_16_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_17_UNLCK"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_FM_WEAP_ADDON_18_UNLCK"), -1, 1);

					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH2"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH3"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH4"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH5"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH6"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH7"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH8"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH9"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH10"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH11"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH12"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH13"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH14"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH15"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH16"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH17"), -1, 1);
					STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_WEAP_FM_ADDON_PURCH18"), -1, 1);
				}
				static char* Weapons[] = { "weapon_assaultrifle_mk2", "weapon_carbinerifle_mk2", "weapon_combatmg_mk2", "weapon_heavysniper_mk2", "weapon_pistol_mk2", "weapon_smg_mk2" };
				for (int i = 0; i < sizeof(Weapons); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), GAMEPLAY::GET_HASH_KEY(Weapons[i]), 9999, 1);
				}
			}
			Menu::MenuOption("Money-gun Ammo ~b~->"_Secure, Moneyammo);
			Menu::Toggle("Infinite Ammo"_Secure, Features::infammo, [] { Features::noreloadv(Features::infammo); });
			Menu::Toggle("Rainbow Weapons"_Secure, Features::rbgun, [] { Features::RBGuner(Features::rbgun); });
			Menu::Toggle("Explosive Ammo"_Secure, Features::expammo, [] {Features::explosive_ammo(Features::expammo); });
			Menu::Toggle("Rapid Fire"_Secure, Features::rapidfirer);
			Menu::MenuOption("Individual Weapons Menu"_Secure, indweaponoptions);
            }
		break;
#pragma endregion
#pragma region indweaponoptions
		case indweaponoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Weapon Categories"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			int weaponSelectionIndex = 0;
			int current = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);
			DoASM();
			for (int i = 0; i < MENU_WEAPON_CATEGORIES.size(); i++)
			{
				string tempstring = MENU_WEAPON_CATEGORIES[i];
				weapcaption = tempstring.c_str();
				//weapvalue = i;

				/*if (weaponSelectionIndex == 0)
				{
					for (int j = 0; j < VOV_WEAPON_VALUES[i].size(); j++)
					{
						const char* value = VOV_WEAPON_VALUES[i].at(j).c_str();
						if (GAMEPLAY::GET_HASH_KEY((char*)value) == current)
						{
							weapvalue = i;
						}
					}
				}*/
				if (Menu::MenuOption(weapcaption, indweaponoptions1)) { weapvalue = i; weapcaption00 = weapcaption; };
			}
		}
		break;
#pragma endregion
#pragma region indweaponoptions1
		case indweaponoptions1:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Weapons"_Secure);
			lastSelectedWeaponCategory = weapvalue;
			DoASM();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			int weaponSelectionIndex = 0;
			int current = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);

			for (int i = 0; i < VOV_WEAPON_CAPTIONS[weapvalue].size(); i++)
			{
				string tempstring = VOV_WEAPON_CAPTIONS[weapvalue].at(i);
				weapcaption1 = tempstring.c_str();

				if (Menu::MenuOption(weapcaption1, indweaponoptions2)) { 
					weapvalue1 = i;
					weaponSelectionIndex = i;
					std::string weaponValue = VOV_WEAPON_VALUES[weapvalue].at(weapvalue1);
					char *weaponChar = (char*)weaponValue.c_str();
					int thisWeaponHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(playerPed, thisWeaponHash, 9999, true);
				};
			}
		}
		break;
#pragma endregion
#pragma region indweaponoptions2
		case indweaponoptions2:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Weapon Mods"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			DoASM();
			int originalWeapon = WEAPON::GET_SELECTED_PED_WEAPON(playerPed);

			lastSelectedWeapon = weapvalue1;

			lastSelectedWeaponCategory = weapvalue;
			DoASM();
			int weaponIndex = weapvalue1;

			
			std::string caption = VOV_WEAPON_CAPTIONS[weapvalue].at(weapvalue1);
			notifyBottom(caption);
/*
			if (caption == "Pistol Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Hollowpoint Clip","FMJ Clip","Rail","Flashlight","Suppressor","Compensator","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_PISTOL_MK2_CLIP_01","COMPONENT_PISTOL_MK2_CLIP_02","COMPONENT_PISTOL_MK2_CLIP_TRACER","COMPONENT_PISTOL_MK2_CLIP_INCENDIARY","COMPONENT_PISTOL_MK2_CLIP_HOLLOWPOINT","COMPONENT_PISTOL_MK2_CLIP_FMJ","COMPONENT_AT_PI_RAIL","COMPONENT_AT_PI_FLSH_02","COMPONENT_AT_PI_SUPP_02","COMPONENT_AT_PI_COMP","COMPONENT_PISTOL_MK2_CAMO","COMPONENT_PISTOL_MK2_CAMO_02","COMPONENT_PISTOL_MK2_CAMO_03","COMPONENT_PISTOL_MK2_CAMO_04","COMPONENT_PISTOL_MK2_CAMO_05","COMPONENT_PISTOL_MK2_CAMO_06","COMPONENT_PISTOL_MK2_CAMO_07","COMPONENT_PISTOL_MK2_CAMO_08","COMPONENT_PISTOL_MK2_CAMO_09","COMPONENT_PISTOL_MK2_CAMO_10","COMPONENT_PISTOL_MK2_CAMO_IND_01" };
			}
			if (caption == "SMG Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Hollowpoint Clip","FMJ Clip","Flashlight","Red Dot","Mini Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_SMG_MK2_CLIP_01","COMPONENT_SMG_MK2_CLIP_02","COMPONENT_SMG_MK2_CLIP_TRACER","COMPONENT_SMG_MK2_CLIP_INCENDIARY","COMPONENT_SMG_MK2_CLIP_HOLLOWPOINT","COMPONENT_SMG_MK2_CLIP_FMJ","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS_SMG","COMPONENT_AT_SCOPE_MACRO_02_SMG_MK2","COMPONENT_AT_SCOPE_SMALL_SMG_MK2","COMPONENT_AT_PI_SUPP","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_SB_BARREL_01","COMPONENT_AT_SB_BARREL_02","COMPONENT_SMG_MK2_CAMO","COMPONENT_SMG_MK2_CAMO_02","COMPONENT_SMG_MK2_CAMO_03","COMPONENT_SMG_MK2_CAMO_04","COMPONENT_SMG_MK2_CAMO_05","COMPONENT_SMG_MK2_CAMO_06","COMPONENT_SMG_MK2_CAMO_07","COMPONENT_SMG_MK2_CAMO_08","COMPONENT_SMG_MK2_CAMO_09","COMPONENT_SMG_MK2_CAMO_10","COMPONENT_SMG_MK2_CAMO_IND_01" };
			}
			if (caption == "Assault Rifle Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Flashlight","Red Dot","Small Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_ASSAULTRIFLE_MK2_CLIP_01","COMPONENT_ASSAULTRIFLE_MK2_CLIP_02","COMPONENT_ASSAULTRIFLE_MK2_CLIP_TRACER","COMPONENT_ASSAULTRIFLE_MK2_CLIP_INCENDIARY","COMPONENT_ASSAULTRIFLE_MK2_CLIP_ARMORPIERCING","COMPONENT_ASSAULTRIFLE_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_MACRO_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_AR_SUPP_02","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_AR_BARREL_01","COMPONENT_AT_AR_BARREL_02","COMPONENT_ASSAULTRIFLE_MK2_CAMO","COMPONENT_ASSAULTRIFLE_MK2_CAMO_02","COMPONENT_ASSAULTRIFLE_MK2_CAMO_03","COMPONENT_ASSAULTRIFLE_MK2_CAMO_04","COMPONENT_ASSAULTRIFLE_MK2_CAMO_05","COMPONENT_ASSAULTRIFLE_MK2_CAMO_06","COMPONENT_ASSAULTRIFLE_MK2_CAMO_07","COMPONENT_ASSAULTRIFLE_MK2_CAMO_08","COMPONENT_ASSAULTRIFLE_MK2_CAMO_09","COMPONENT_ASSAULTRIFLE_MK2_CAMO_10","COMPONENT_ASSAULTRIFLE_MK2_CAMO_IND_01" };
			}
			if (caption == "Carbine Rifle Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Flashlight","Red Dot","Small Scope","Scope","Suppressor","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_CARBINERIFLE_MK2_CLIP_01","COMPONENT_CARBINERIFLE_MK2_CLIP_02","COMPONENT_CARBINERIFLE_MK2_CLIP_TRACER","COMPONENT_CARBINERIFLE_MK2_CLIP_INCENDIARY","COMPONENT_CARBINERIFLE_MK2_CLIP_ARMORPIERCING","COMPONENT_CARBINERIFLE_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_AR_FLSH","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_MACRO_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_AR_SUPP","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_CR_BARREL_01","COMPONENT_AT_CR_BARREL_02","COMPONENT_CARBINERIFLE_MK2_CAMO","COMPONENT_CARBINERIFLE_MK2_CAMO_02","COMPONENT_CARBINERIFLE_MK2_CAMO_03","COMPONENT_CARBINERIFLE_MK2_CAMO_04","COMPONENT_CARBINERIFLE_MK2_CAMO_05","COMPONENT_CARBINERIFLE_MK2_CAMO_06","COMPONENT_CARBINERIFLE_MK2_CAMO_07","COMPONENT_CARBINERIFLE_MK2_CAMO_08","COMPONENT_CARBINERIFLE_MK2_CAMO_09","COMPONENT_CARBINERIFLE_MK2_CAMO_10","COMPONENT_CARBINERIFLE_MK2_CAMO_IND_01" };
			}
			if (caption == "Combat MG Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Tracer Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Grip","Red Dot","Small Scope","Scope","Muzzle1","Muzzle2","Muzzle3","Muzzle4","Muzzle5","Muzzle6","Muzzle7","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_COMBATMG_MK2_CLIP_01","COMPONENT_COMBATMG_MK2_CLIP_02","COMPONENT_COMBATMG_MK2_CLIP_TRACER","COMPONENT_COMBATMG_MK2_CLIP_INCENDIARY","COMPONENT_COMBATMG_MK2_CLIP_ARMORPIERCING","COMPONENT_COMBATMG_MK2_CLIP_FMJ","COMPONENT_AT_AR_AFGRIP_02","COMPONENT_AT_SIGHTS","COMPONENT_AT_SCOPE_SMALL_MK2","COMPONENT_AT_SCOPE_MEDIUM_MK2","COMPONENT_AT_MUZZLE_01","COMPONENT_AT_MUZZLE_02","COMPONENT_AT_MUZZLE_03","COMPONENT_AT_MUZZLE_04","COMPONENT_AT_MUZZLE_05","COMPONENT_AT_MUZZLE_06","COMPONENT_AT_MUZZLE_07","COMPONENT_AT_MG_BARREL_01","COMPONENT_AT_MG_BARREL_02","COMPONENT_COMBATMG_MK2_CAMO","COMPONENT_COMBATMG_MK2_CAMO_02","COMPONENT_COMBATMG_MK2_CAMO_03","COMPONENT_COMBATMG_MK2_CAMO_04","COMPONENT_COMBATMG_MK2_CAMO_05","COMPONENT_COMBATMG_MK2_CAMO_06","COMPONENT_COMBATMG_MK2_CAMO_07","COMPONENT_COMBATMG_MK2_CAMO_08","COMPONENT_COMBATMG_MK2_CAMO_09","COMPONENT_COMBATMG_MK2_CAMO_10","COMPONENT_COMBATMG_MK2_CAMO_IND_01" };
			}
			if (caption == "Heavy Sniper Mk II")
			{
				std::vector<std::string> CAPTIONS_ATTACH_MK2 = { "Normal Clip","Extended Clip","Incendiary Clip","Armor Piercing Clip","FMJ Clip","Explosive Clip","Large Scope","Max Scope","Nightvision Scope","Thermal Scope","Suppressor","Muzzle8","Muzzle9","Barrel1","Barrel2","Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","Camo7","Camo8","Camo9","Camo10","Independence Day Camo" };
				std::vector<std::string> VALUES_ATTACH_MK2 = { "COMPONENT_HEAVYSNIPER_MK2_CLIP_01","COMPONENT_HEAVYSNIPER_MK2_CLIP_02","COMPONENT_HEAVYSNIPER_MK2_CLIP_INCENDIARY","COMPONENT_HEAVYSNIPER_MK2_CLIP_ARMORPIERCING","COMPONENT_HEAVYSNIPER_MK2_CLIP_FMJ","COMPONENT_HEAVYSNIPER_MK2_CLIP_EXPLOSIVE","COMPONENT_AT_SCOPE_LARGE_MK2","COMPONENT_AT_SCOPE_MAX","COMPONENT_AT_SCOPE_NV","COMPONENT_AT_SCOPE_THERMAL","COMPONENT_AT_SR_SUPP_03","COMPONENT_AT_MUZZLE_08","COMPONENT_AT_MUZZLE_09","COMPONENT_AT_SR_BARREL_01","COMPONENT_AT_SR_BARREL_02","COMPONENT_HEAVYSNIPER_MK2_CAMO","COMPONENT_HEAVYSNIPER_MK2_CAMO_02","COMPONENT_HEAVYSNIPER_MK2_CAMO_03","COMPONENT_HEAVYSNIPER_MK2_CAMO_04","COMPONENT_HEAVYSNIPER_MK2_CAMO_05","COMPONENT_HEAVYSNIPER_MK2_CAMO_06","COMPONENT_HEAVYSNIPER_MK2_CAMO_07","COMPONENT_HEAVYSNIPER_MK2_CAMO_08","COMPONENT_HEAVYSNIPER_MK2_CAMO_09","COMPONENT_HEAVYSNIPER_MK2_CAMO_10","COMPONENT_HEAVYSNIPER_MK2_CAMO_IND_01" };
			}
*/

			std::string value = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(weaponIndex);

			std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(weaponIndex);
			char *weaponChar = (char*)weaponValue.c_str();
			int thisWeaponHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
			bool isEquipped = (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY(weaponChar), 0) ? true : false);

			WEAPON::SET_CURRENT_PED_WEAPON(playerPed, thisWeaponHash, true);
			DoASM();
			std::stringstream ss;
			ss << "Equip " << caption << "?";
			string tempstring = ss.str();
			weapcaption2 = tempstring.c_str();
			weapvalue2 = 1;
			DoASM();

			if (true)
			{

				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				std::string weaponValue = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
				char *weaponChar = (char*)weaponValue.c_str();
				int weapHash = GAMEPLAY::GET_HASH_KEY(weaponChar);
				int maxClipAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, weapHash, false);
				DoASM();
				if (maxClipAmmo > 0)
				{
					if (Menu::Option("Give Clip"_Secure)) { give_weapon_clip(); };
				
					if (Menu::Option("Fill Ammo"_Secure)) { fill_weapon_ammo(); };
				
				}

				int moddableIndex = -1;
				for (int i = 0; i < WEAPONTYPES_MOD.size(); i++)
				{
					if (weaponValue.compare(WEAPONTYPES_MOD.at(i)) == 0)
					{
						moddableIndex = i;
						break;
					}
				}
				DoASM();
				if (moddableIndex != -1)
				{
					std::vector<std::string> modCaptions = VOV_WEAPONMOD_CAPTIONS[moddableIndex];
					
					for (int i = 0; i < modCaptions.size(); i++)
					{
						string tempstring = modCaptions.at(i);
						weapcaption3 = tempstring.c_str();
						std::vector<int> extra_arguments = { lastSelectedWeaponCategory, weaponIndex, moddableIndex, i };
						if (Menu::Option(weapcaption3)) { set_weaponmod_equipped(is_weaponmod_equipped(extra_arguments), extra_arguments); };
					}
				}

				if (strcmp(weaponChar, "WEAPON_KNUCKLE") == 0)
				{
					for (int i = 0; i < CAPTIONS_ATTACH_KNUCKLES.size(); i++)
					{
						string tempstring = CAPTIONS_ATTACH_KNUCKLES.at(i);
						weapcaption4 = tempstring.c_str();
						if (Menu::Option(weapcaption4))
						{
							int tempvalue = i;
							onchange_knuckle_appearance(tempvalue); 
						};
					}
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
					if (Menu::MenuOption("Weapon Tints"_Secure, indweaponoptions3));
				}
			}


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
				DoASM();
			}
		}
		break;
#pragma endregion
#pragma region indweaponoptions3
		case indweaponoptions3:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Tints"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			std::string caption = VOV_WEAPON_CAPTIONS[lastSelectedWeaponCategory].at(lastSelectedWeapon);
			if (caption != "Pistol Mk II" && caption != "SMG Mk II" && caption != "Assault Rifle Mk II" && caption != "Carbine Rifle Mk II" && caption != "Combat MG Mk II" && caption != "Heavy Sniper Mk II")
			{
				for (int i = 0; i < VALUES_TINT.size(); i++)
				{
					string tempstring = CAPTIONS_TINT[i];
					weapcaption33 = tempstring.c_str();
					if (Menu::Option(weapcaption33))
					{
						int tempvalue = VALUES_TINT[i];
						Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
						std::string weaponName = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
						int weapHash = GAMEPLAY::GET_HASH_KEY((char*)weaponName.c_str());
						DoASM();
						WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, weapHash, tempvalue);
					};
				}
			}
			else
			{
				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				std::string weaponName = VOV_WEAPON_VALUES[lastSelectedWeaponCategory].at(lastSelectedWeapon);
				int weapHash = GAMEPLAY::GET_HASH_KEY((char*)weaponName.c_str());
				/*if (Menu::Int("Mk II Tints"_Secure, weaptint, 0, 32, 1))
				{
					WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, weapHash, weaptint);
				};*/
				Menu::Option("MKII Unfinished"_Secure);
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
					DoASM();
					break;
				}
			}

			
		}
		break;
#pragma endregion
#pragma region Ammo Options
		case Moneyammo:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Money Ammo"_Secure);
		    Menu::Toggle("Dildos"_Secure, Features::MoneyGunBool, [] { Features::Moneygun(Features::MoneyGunBool); });
		    Menu::Toggle("Brown paper bag"_Secure, Features::BagGunBool, [] { Features::Baggun(Features::BagGunBool); });
		    Menu::Toggle("Gold Gun"_Secure, Features::goldgunbool, [] { Features::goldgun(Features::goldgunbool); });
		    Menu::Toggle("Alien eggs"_Secure, Features::Alieneggsbool, [] { Features::Alieneggs(Features::Alieneggsbool); });
			Menu::Toggle("Corpse"_Secure, Features::Pedweaponbool, [] { Features::Pedweapon(Features::Pedweaponbool); });
			Menu::Toggle("Plane"_Secure, Features::Planeweaponbool, [] { Features::Planeweapon(Features::Planeweaponbool); });
			Menu::Toggle("Arcade"_Secure, Features::Arcadegunbool, [] { Features::Arcadegun(Features::Arcadegunbool); });
			DoASM();
		}    
		break;
#pragma endregion
#pragma region ipl all Options
		case ipl:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("IPLs"_Secure);
			if (Menu::Option("North Yankton"_Secure)) {
				STREAMING::REQUEST_IPL("prologue01");
				STREAMING::REQUEST_IPL("Prologue01c");
				STREAMING::REQUEST_IPL("Prologue01d");
				STREAMING::REQUEST_IPL("Prologue01e");
				STREAMING::REQUEST_IPL("Prologue01f");
				STREAMING::REQUEST_IPL("Prologue01g");
				STREAMING::REQUEST_IPL("prologue01h");
				STREAMING::REQUEST_IPL("prologue01i");
				STREAMING::REQUEST_IPL("prologue01j");
				STREAMING::REQUEST_IPL("prologue01k");
				STREAMING::REQUEST_IPL("prologue01z");
				STREAMING::REQUEST_IPL("prologue02");
				STREAMING::REQUEST_IPL("prologue03");
				STREAMING::REQUEST_IPL("prologue03b");
				STREAMING::REQUEST_IPL("prologue03_grv_cov");
				STREAMING::REQUEST_IPL("prologue03_grv_dug");
				STREAMING::REQUEST_IPL("prologue03_grv_fun");
				STREAMING::REQUEST_IPL("prologue04");
				STREAMING::REQUEST_IPL("prologue04b");
				STREAMING::REQUEST_IPL("prologue04_cover");
				STREAMING::REQUEST_IPL("prologue05");
				STREAMING::REQUEST_IPL("prologue05b");
				STREAMING::REQUEST_IPL("prologue06");
				STREAMING::REQUEST_IPL("prologue06b");
				STREAMING::REQUEST_IPL("prologue06_int");
				STREAMING::REQUEST_IPL("prologuerd");
				STREAMING::REQUEST_IPL("prologuerdb");
				STREAMING::REQUEST_IPL("prologue_DistantLights");
				STREAMING::REQUEST_IPL("prologue_grv_torch");
				STREAMING::REQUEST_IPL("prologue_m2_door");
				STREAMING::REQUEST_IPL("prologue_LODLights");
				STREAMING::REQUEST_IPL("DES_ProTree_start");
				Vector3 Coords;
				Coords.x = 3595.39673f; Coords.y = -4893.727f; Coords.z = 115.838394f;
				TPto(Coords);
			}
			if (Menu::Option("Aircraft Carrier"_Secure)) {
				STREAMING::REQUEST_IPL("hei_carrier");
				STREAMING::REQUEST_IPL("hei_carrier_DistantLights");
				STREAMING::REQUEST_IPL("hei_Carrier_int1");
				STREAMING::REQUEST_IPL("hei_Carrier_int2");
				STREAMING::REQUEST_IPL("hei_Carrier_int3");
				STREAMING::REQUEST_IPL("hei_Carrier_int4");
				STREAMING::REQUEST_IPL("hei_Carrier_int5");
				STREAMING::REQUEST_IPL("hei_Carrier_int6");
				STREAMING::REQUEST_IPL("hei_carrier_LODLights");
				Vector3 Coords;
				Coords.x = 3069.330f; Coords.y = -4632.4f; Coords.z = 15.043f;
				TPto(Coords);
			}
			if (Menu::Option("Sunken Cargo-ship"_Secure)) {
				STREAMING::REQUEST_IPL("sunkcargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 0.0f;
				TPto(Coords);
			}
			if (Menu::Option("Life Invader Office"_Secure)) {
				STREAMING::REQUEST_IPL("facelobby");
				STREAMING::REQUEST_IPL("facelobbyfake");
				Vector3 Coords;
				Coords.x = -1047.9f; Coords.y = -233.0f; Coords.z = 39.0f;
				TPto(Coords);
			}
			if (Menu::Option("Hospital"_Secure)) {
				STREAMING::REQUEST_IPL("RC12B_HospitalInterior");
				STREAMING::REQUEST_IPL("RC12B_Destroyed");
				Vector3 Coords;
				Coords.x = 356.8f; Coords.y = -590.1f; Coords.z = 43.3f;
				TPto(Coords);
			}
			if (Menu::Option("O'Neil Farm"_Secure)) {
				STREAMING::REMOVE_IPL("farm_burnt");
				STREAMING::REMOVE_IPL("farm_burnt_props");
				STREAMING::REQUEST_IPL("farm");
				STREAMING::REQUEST_IPL("farm_props");
				STREAMING::REQUEST_IPL("farmint");
				STREAMING::REQUEST_IPL("farmint_cap");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				TPto(Coords);
			}
			if (Menu::Option("Burnt Farm"_Secure)) {
				STREAMING::REMOVE_IPL("farm");
				STREAMING::REMOVE_IPL("farm_props");
				STREAMING::REMOVE_IPL("farmint");
				STREAMING::REMOVE_IPL("farmint_cap");
				STREAMING::REQUEST_IPL("farm_burnt");
				STREAMING::REQUEST_IPL("farm_burnt_props");
				Vector3 Coords;
				Coords.x = 2441.2f; Coords.y = 4968.5f; Coords.z = 51.7f;
				TPto(Coords);
			}
			if (Menu::Option("Cargoship"_Secure)) {
				STREAMING::REQUEST_IPL("cargoship");
				Vector3 Coords;
				Coords.x = -162.8918f; Coords.y = -2365.769f; Coords.z = 9.3192f;
				TPto(Coords);
			}
			if (Menu::Option("Porn Yacht"_Secure)) {
				STREAMING::REQUEST_IPL("smboat");
				Vector3 Coords;
				Coords.x = -2045.8f; Coords.y = -1031.2f; Coords.z = 11.9f;
				TPto(Coords);
			}
			if (Menu::Option("Jewelry Store"_Secure)) {
				STREAMING::REQUEST_IPL("jewel2fake");
				STREAMING::REQUEST_IPL("post_hiest_unload");
				STREAMING::REQUEST_IPL("bh1_16_refurb");
				Vector3 Coords;
				Coords.x = -630.4f; Coords.y = -236.7f; Coords.z = 40.0f;
				TPto(Coords);
			}
			if (Menu::Option("Morgue"_Secure)) {
				STREAMING::REQUEST_IPL("Coroner_Int_on");
				Vector3 Coords;
				Coords.x = 244.9f; Coords.y = -1374.7f; Coords.z = 39.5f;
				TPto(Coords);
			}
			if (Menu::Option("Train Wreck"_Secure)) {
				STREAMING::REQUEST_IPL("canyonriver01");
				STREAMING::REQUEST_IPL("railing_start");
				STREAMING::REQUEST_IPL("canyonriver01_traincrash");
				STREAMING::REQUEST_IPL("railing_end");
				Vector3 Coords;
				Coords.x = -532.1309f; Coords.y = 4526.187f; Coords.z = 88.7955f;
				TPto(Coords);
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region Teleport Subs
		case Outdoor:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Outdoor"_Secure);
			Menu::Break("hospitals"_Secure);
			//hospitals
			if (Menu::Option("lossantosmc"_Secure)) {Vector3 Coords;Coords.x = 316.0837; Coords.y = -1376.215; Coords.z = 31.92003;TPto(Coords);}
			if (Menu::Option("pillboxhillmc"_Secure)) {Vector3 Coords;Coords.x = 363.2693; Coords.y = -595.5392; Coords.z = 28.67362;TPto(Coords);}
			if (Menu::Option("mountzonahmc"_Secure)) {Vector3 Coords;Coords.x = -473.4971; Coords.y = -361.0964; Coords.z = 33.9467; TPto(Coords);}
			Menu::Break("Firestations"_Secure);
			//Fire Stations
			if (Menu::Option("rockfordhillfs"_Secure)) { Vector3 Coords; Coords.x = -645.1444; Coords.y = -122.4141; Coords.z = 37.84688; TPto(Coords); }
			if (Menu::Option("lossantosfs"_Secure)) { Vector3 Coords; Coords.x = 1197.667; Coords.y = -1454.18; Coords.z = 34.96282; TPto(Coords); }
			if (Menu::Option("davisfs"_Secure)) { Vector3 Coords; Coords.x = 215.5857; Coords.y = -1633.171; Coords.z = 29.28492; TPto(Coords); }
			Menu::Break("Bank"_Secure);
			//Banks
			if (Menu::Option("Lombank-1"_Secure)) {Vector3 Coords;Coords.x = -1581.081; Coords.y = -558.571; Coords.z = 34.95325;TPto(Coords);}
			if (Menu::Option("Lombank-2"_Secure)) {Vector3 Coords;Coords.x = -693.5095; Coords.y = -582.5724; Coords.z = 31.55194;TPto(Coords);}
			if (Menu::Option("Lombank-3"_Secure)) {Vector3 Coords;Coords.x = 6.959941; Coords.y = -933.3794; Coords.z = 29.90501;TPto(Coords);}
			if (Menu::Option("Lombank-4"_Secure)) {Vector3 Coords;Coords.x = -863.7408; Coords.y = -192.3661; Coords.z = 37.83302;TPto(Coords);}
			if (Menu::Option("Mazebank-1"_Secure)) {Vector3 Coords;Coords.x = -1370.474; Coords.y = -503.0782; Coords.z = 33.15739;TPto(Coords);}
			if (Menu::Option("Mazebank-2"_Secure)) {Vector3 Coords;Coords.x = -66.95165; Coords.y = -802.4657; Coords.z = 44.22729;TPto(Coords);}
			if (Menu::Option("Mazebank-3"_Secure)) {Vector3 Coords;Coords.x = -1317.919; Coords.y = -832.2131; Coords.z = 16.9697;TPto(Coords);}
			if (Menu::Option("Kayton-1"_Secure)) {Vector3 Coords;Coords.x = -817.6145; Coords.y = -622.4203; Coords.z = 29.22164;TPto(Coords);}
			if (Menu::Option("Kayton-2"_Secure)) {Vector3 Coords;Coords.x = -731.3457; Coords.y = -811.931; Coords.z = 23.67677;TPto(Coords);}
			if (Menu::Option("Flecca-1"_Secure)) {Vector3 Coords;Coords.x = -2966.404; Coords.y = 482.9045; Coords.z = 15.69272;TPto(Coords);}
			if (Menu::Option("Flecca-2"_Secure)) {Vector3 Coords;Coords.x = 1175.276; Coords.y = 2702.673; Coords.z = 38.1727;TPto(Coords);}
			if (Menu::Option("Flecca-3"_Secure)) {Vector3 Coords;Coords.x = -1214.419; Coords.y = -327.6115; Coords.z = 37.67231;TPto(Coords);}
			if (Menu::Option("Flecca-4"_Secure)) {Vector3 Coords;Coords.x = 150.9875; Coords.y = -1037.244; Coords.z = 29.3392;TPto(Coords);}
			if (Menu::Option("Flecca-5"_Secure)) {Vector3 Coords;Coords.x = 315.5083; Coords.y = -275.3137; Coords.z = 53.9239;TPto(Coords);}
		}
			break;
		case Underwater:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Underwater"_Secure);
			if (Menu::Option("Sunken Plane"_Secure)) {Vector3 Coords;Coords.x = 3199.748; Coords.y = -379.018; Coords.z = -22.500;TPto(Coords);}
			if (Menu::Option("Underwater UFO"_Secure)) {Vector3 Coords;Coords.x = 762.426; Coords.y = 7380.371; Coords.z = -111.377;TPto(Coords);}
		}
		break;
		case Indoors:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Indoors"_Secure);
			Menu::MenuOption("Stores ~b~->"_Secure, Shopz);
			if (Menu::Option("Torture Room"_Secure)) {Vector3 Coords;Coords.x = 147.170; Coords.y = -2201.804; Coords.z = 4.688;TPto(Coords);}
		}
		break;
		case Shopz:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Shop's"_Secure);
			Menu::MenuOption("Robbable~b~->"_Secure, Robbery);
			//clothing store mother fuckers
			Menu::Break("Clothing Shops"_Secure);
			if (Menu::Option("Thrift Shop"_Secure)) { Vector3 Coords; Coords.x = 90.09808; Coords.y = -1393.833; Coords.z = 29.22288; TPto(Coords); }
			if (Menu::Option("Binco-1"_Secure)) { Vector3 Coords; Coords.x = 415.0879; Coords.y = -807.1629; Coords.z = 29.34707; TPto(Coords); }
			if (Menu::Option("Binco-2"_Secure)) { Vector3 Coords; Coords.x = -814.6863; Coords.y = -1083.6; Coords.z = 11.02311; TPto(Coords); }
			if (Menu::Option("suburban-1"_Secure)) { Vector3 Coords; Coords.x = -1206.468; Coords.y = -781.6549; Coords.z = 17.11347; TPto(Coords); }
			if (Menu::Option("suburban-2"_Secure)) { Vector3 Coords; Coords.x = 130.3176; Coords.y = -203.6293; Coords.z = 54.50247; TPto(Coords); }
			if (Menu::Option("ponsonbys-1"_Secure)) { Vector3 Coords; Coords.x = -1459.502; Coords.y = -228.4188; Coords.z = 49.20671; TPto(Coords); }
			if (Menu::Option("ponsonbys-2"_Secure)) { Vector3 Coords; Coords.x = -719.9037; Coords.y = -158.6554; Coords.z = 37.00257; TPto(Coords); }
			if (Menu::Option("ponsonbys-3"_Secure)) { Vector3 Coords; Coords.x = -153.004; Coords.y = -306.5251; Coords.z = 38.69064; TPto(Coords); }
			if (Menu::Option("Mask shop"_Secure)) { Vector3 Coords; Coords.x = -1340.761; Coords.y = -1279.11; Coords.z = 4.87219; TPto(Coords); }
			//Tattoo Parlors
			Menu::Break("Tattoo Parlors"_Secure);
			if (Menu::Option("tattoo shop-1"_Secure)) { Vector3 Coords; Coords.x = -287.896; Coords.y = 6202.601; Coords.z = 31.46758; TPto(Coords); }
			if (Menu::Option("tattoo shop-2"_Secure)) { Vector3 Coords; Coords.x = 1855.869; Coords.y = 3747.051; Coords.z = 33.11377; TPto(Coords); }
			if (Menu::Option("inkinctattoo"_Secure)) { Vector3 Coords; Coords.x = -3164.901; Coords.y = 1071.513; Coords.z = 20.682; TPto(Coords); }
			if (Menu::Option("blazingtattoo"_Secure)) { Vector3 Coords; Coords.x = 319.5825; Coords.y = 173.5747; Coords.z = 103.7592; TPto(Coords); }
			if (Menu::Option("lossantostattoo"_Secure)) { Vector3 Coords; Coords.x = 1319.08; Coords.y = -1647.012; Coords.z = 52.14554; TPto(Coords); }
			if (Menu::Option("thepittattoo"_Secure)) { Vector3 Coords; Coords.x = -1156.178; Coords.y = -1420.137; Coords.z = 4.806167; TPto(Coords); }
			//Barber Shops
			Menu::Break("Barber Shops"_Secure);
			if (Menu::Option("Beachcomboverbarber"_Secure)) {Vector3 Coords;Coords.x = -1291.902; Coords.y = -1117.484; Coords.z = 6.616534;TPto(Coords);}
			if (Menu::Option("Bobmulet"_Secure)) {Vector3 Coords;Coords.x = -825.6422; Coords.y = -189.4336; Coords.z = 37.61189;TPto(Coords);}
			if (Menu::Option("Haironhawick"_Secure)) {Vector3 Coords;Coords.x = -29.21493; Coords.y = -142.92; Coords.z = 57.0216;TPto(Coords);}
			if (Menu::Option("Herrkutz"_Secure)) {Vector3 Coords;Coords.x = 1201.336; Coords.y = -471.1683; Coords.z = 66.21418;TPto(Coords);}
			if (Menu::Option("Herrkutz-2"_Secure)) {Vector3 Coords;Coords.x = 131.0965; Coords.y = -1714.926; Coords.z = 29.24748;TPto(Coords);}
			//Ammunation
			Menu::Break("Ammunation"_Secure);
			if (Menu::Option("Ammunation-1"_Secure)) {Vector3 Coords;Coords.x = 812.8157; Coords.y = -2143.071; Coords.z = 29.28937;TPto(Coords);}
			if (Menu::Option("Ammunation-2"_Secure)) {Vector3 Coords;Coords.x = 842.6879; Coords.y = -1018.924; Coords.z = 27.53913;TPto(Coords);}
			if (Menu::Option("Ammunation-3"_Secure)) {Vector3 Coords;Coords.x = 14.84951; Coords.y = -1121.627; Coords.z = 28.79761;TPto(Coords);}
			if (Menu::Option("Ammunation-4"_Secure)) {Vector3 Coords;Coords.x = -664.1296; Coords.y = -949.4733; Coords.z = 21.53015;TPto(Coords);}
			if (Menu::Option("Ammunation-5"_Secure)) {Vector3 Coords;Coords.x = -1319.31; Coords.y = -389.9755; Coords.z = 36.43825;TPto(Coords);}
			if (Menu::Option("Ammunation-6"_Secure)) {Vector3 Coords;Coords.x = 239.9833; Coords.y = -44.11226; Coords.z = 69.70087;TPto(Coords);}
		}
			break;
		case Robbery:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Robbery"_Secure);
			//Robbery Stores 
			if (Menu::Option("LTD-1"_Secure)) {Vector3 Coords;Coords.x = 1698.376; Coords.y = 4929.637; Coords.z = 42.0781;TPto(Coords);}
			if (Menu::Option("LTD-2"_Secure)) {Vector3 Coords;Coords.x = -1821.921; Coords.y = 787.7424; Coords.z = 138.1834;TPto(Coords);}
			if (Menu::Option("LTD-3"_Secure)) {Vector3 Coords;Coords.x = 1159.864; Coords.y = -327.3117; Coords.z = 69.21395;TPto(Coords);}
			if (Menu::Option("LTD-4"_Secure)) {Vector3 Coords;Coords.x = -711.7557; Coords.y = -917.2692; Coords.z = 19.2142;TPto(Coords);}
			if (Menu::Option("LTD-5"_Secure)) {Vector3 Coords;Coords.x = -53.29216; Coords.y = -1757.069; Coords.z = 29.43966;TPto(Coords);}
			if (Menu::Option("24/7-1"_Secure)) {Vector3 Coords;Coords.x = 1730.876; Coords.y = 6410.715; Coords.z = 35.00065;TPto(Coords);}
			if (Menu::Option("24/7-2"_Secure)) {Vector3 Coords;Coords.x = 1965.45; Coords.y = 3740.146; Coords.z = 32.32734;TPto(Coords);}
			if (Menu::Option("24/7-3"_Secure)) {Vector3 Coords;Coords.x = 2682.5; Coords.y = 3282.227; Coords.z = 55.24056;TPto(Coords);}
			if (Menu::Option("24/7-4"_Secure)) {Vector3 Coords;Coords.x = 544.105; Coords.y = 2673.123; Coords.z = 42.15447;TPto(Coords);}
			if (Menu::Option("24/7-5"_Secure)) {Vector3 Coords;Coords.x = -3239.264; Coords.y = 1004.406; Coords.z = 12.45598;TPto(Coords);}
			if (Menu::Option("24/7-6"_Secure)) {Vector3 Coords;Coords.x = -3038.054; Coords.y = 589.7609; Coords.z = 7.816061;TPto(Coords);}
			if (Menu::Option("24/7-7"_Secure)) {Vector3 Coords;Coords.x = 2559.797; Coords.y = 385.3533; Coords.z = 108.6211;TPto(Coords);}
			if (Menu::Option("24/7-8"_Secure)) {Vector3 Coords;Coords.x = 376.5075; Coords.y = 322.8857; Coords.z = 103.5696;TPto(Coords);}
			if (Menu::Option("24/7-9"_Secure)) {Vector3 Coords;Coords.x = 29.23317; Coords.y = -1349.951; Coords.z = 29.33034;TPto(Coords);}
			if (Menu::Option("Liquorace"_Secure)) {Vector3 Coords;Coords.x = 1394.391; Coords.y = 3599.346; Coords.z = 35.00915;TPto(Coords);}
			if (Menu::Option("Liquorbarn"_Secure)) {Vector3 Coords;Coords.x = 1166.538; Coords.y = 2703.077; Coords.z = 38.17911;TPto(Coords);}
			if (Menu::Option("Robs Liquor-1"_Secure)) {Vector3 Coords;Coords.x = -2974.149; Coords.y = 390.7819; Coords.z = 15.03373;TPto(Coords);}
			if (Menu::Option("Robs Liquor-2"_Secure)) {Vector3 Coords;Coords.x = 1141.874; Coords.y = -980.8714; Coords.z = 46.1998;TPto(Coords);}
			if (Menu::Option("Robs Liquor-3"_Secure)) {Vector3 Coords;Coords.x = -1491.382; Coords.y = -384.0144; Coords.z = 40.11004;TPto(Coords);}
			if (Menu::Option("Robs Liquor-4"_Secure)) {Vector3 Coords;Coords.x = -1226.786; Coords.y = -902.1702; Coords.z = 12.27802;TPto(Coords);}
		}
		break;
		
		case Highlife:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("High Up"_Secure);
			if (Menu::Option("Director Mod Trailer"_Secure)) {Vector3 Coords;Coords.x = -20.004; Coords.y = -10.889; Coords.z = 500.602;TPto(Coords);}
		}//Director mod trailer does take the person to the trailer offline however online its just a location high in the air
		break;
		case favtele:
		{

			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Popular TP's"_Secure);
			if (Menu::Option("LS Customs"_Secure)) {Vector3 Coords;Coords.x = -373.01; Coords.y = -124.91; Coords.z = 38.31;TPto(Coords);}
			if (Menu::Option("Airport"_Secure)) {Vector3 Coords;Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;TPto(Coords);}
			if (Menu::Option("Mors Mutual Lot"_Secure)) {Vector3 Coords;Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;TPto(Coords);}
			if (Menu::Option("Sandy Shores Airfield"_Secure)) {Vector3 Coords;Coords.x = 1741.4960f; Coords.y = 3269.2570f; Coords.z = 41.6014f;TPto(Coords);}
			if (Menu::Option("Vinewood Bowl Stage"_Secure)) {Vector3 Coords;Coords.x = 686.245; Coords.y = 577.950; Coords.z = 130.461;TPto(Coords);}
			if (Menu::Option("Gods Thumb"_Secure)) {Vector3 Coords;Coords.x = -1006.402; Coords.y = 6272.383; Coords.z = 1.503;TPto(Coords);}
			if (Menu::Option("Play Boy Mansion"_Secure)) {Vector3 Coords;Coords.x = -1475.234; Coords.y = 167.088; Coords.z = 55.841;TPto(Coords);}
			if (Menu::Option("Casino"_Secure)) {Vector3 Coords;Coords.x = 925.329; Coords.y = 46.152; Coords.z = 80.908;TPto(Coords);}
			if (Menu::Option("Garage - Outside"_Secure)) {Vector3 Coords;Coords.x = -795.46f; Coords.y = 308.89f; Coords.z = 85.71f;TPto(Coords);}
			if (Menu::Option("Main Airport"_Secure)) {Vector3 Coords;Coords.x = -1102.2910f; Coords.y = -2894.5160f; Coords.z = 13.9467f;TPto(Coords);}
			if (Menu::Option("Waterfall Hangout"_Secure)) {Vector3 Coords;Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;TPto(Coords);}
			if (Menu::Option("Inside FIB Building"_Secure)) {Vector3 Coords;Coords.x = 135.5220f; Coords.y = -749.0003f; Coords.z = 260.0000f;TPto(Coords);}
			if (Menu::Option("Humane Labs 1"_Secure)) {Vector3 Coords;Coords.x = 3617.231f; Coords.y = 3739.871f; Coords.z = 28.6901f;TPto(Coords);}
			if (Menu::Option("Humane Labs 2"_Secure)) {Vector3 Coords;Coords.x = 3531.703f; Coords.y = 3673.642f; Coords.z = 28.1212f;TPto(Coords);}
			if (Menu::Option("Car Impound Lot"_Secure)) {Vector3 Coords;Coords.x = 391.4746; Coords.y = -1637.9750; Coords.z = 29.3153;TPto(Coords);}
			if (Menu::Option("Mors Mutual Impound"_Secure)) {Vector3 Coords;Coords.x = -222.1977; Coords.y = -1185.8500; Coords.z = 23.0294;TPto(Coords);}
			if (Menu::Option("Maze Bank Rooftop"_Secure)) {Vector3 Coords;Coords.x = -75.015f; Coords.y = -818.215f; Coords.z = 326.176f;TPto(Coords);}
			if (Menu::Option("Main LS Customs"_Secure)) {Vector3 Coords;Coords.x = -365.425f; Coords.y = -131.809f; Coords.z = 37.873f;TPto(Coords);}
			if (Menu::Option("FIB Roof Top"_Secure)) {Vector3 Coords;Coords.x = 150.126f; Coords.y = -754.591f; Coords.z = 262.865f;TPto(Coords);}
			if (Menu::Option("Top Of Mt Chilad"_Secure)) {Vector3 Coords;Coords.x = 450.718f; Coords.y = 5566.614f; Coords.z = 806.183f;TPto(Coords);}
			if (Menu::Option("Fort Zancudov"_Secure)) {Vector3 Coords;Coords.x = -2012.8470f; Coords.y = 2956.5270f; Coords.z = 32.8101f;TPto(Coords);}
			if (Menu::Option("Mask Shop"_Secure)) {Vector3 Coords;Coords.x = -1338.16; Coords.y = -1278.11; Coords.z = 4.87;TPto(Coords);}
			if (Menu::Option("Ponsonbys"_Secure)) {Vector3 Coords;Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;TPto(Coords);}
			if (Menu::Option("Ammunation"_Secure)) {Vector3 Coords;Coords.x = 247.3652; Coords.y = -45.8777; Coords.z = 69.9411;TPto(Coords);}
			if (Menu::Option("Trevers Meth Lab"_Secure)) {Vector3 Coords;Coords.x = 1391.773; Coords.y = 3608.716; Coords.z = 38.942;TPto(Coords);}
			if (Menu::Option("Lesters House"_Secure)) {Vector3 Coords;Coords.x = 1273.898; Coords.y = -1719.304; Coords.z = 54.771;TPto(Coords);}
			if (Menu::Option("Fort Zancudo Entrance"_Secure)) {Vector3 Coords;Coords.x = -2344.373; Coords.y = 3267.498; Coords.z = 32.811;TPto(Coords);}
		}
		break;
#pragma endregion
#pragma region Teleport Menu
		case teleport:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Teleports"_Secure);
			Menu::Option("Teleport To Waypoint"_Secure, [] {Features::TPtoWaypoint(); });
			Menu::Option("Teleport To Mission Objective"_Secure, [] {Features::TPtoObjective(); });
			Menu::MenuOption("IPL Loader ~b~->"_Secure, ipl);
			Menu::MenuOption("Indoors ~b~->"_Secure, Indoors);
			Menu::MenuOption("Outside ~b~->"_Secure, Outdoor);
			Menu::MenuOption("Underwater ~b~->"_Secure, Underwater);
			Menu::MenuOption("High UP ~b~->"_Secure, Highlife);
			Menu::MenuOption("Popular ~b~->"_Secure, favtele);
		}
		break;
#pragma endregion
#pragma region All Players
		case allplayers:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("All Players"_Secure);
			Menu::Toggle("Enable ESP"_Secure, Features::esper, [] {});
			DoASM();
			if (Menu::Option("Kick All From Vehicle"_Secure)) {
				for (int i = 0; i < 32; i++)
				{
					DoASM();
					if (i != PLAYER::PLAYER_ID())
					{
						RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						Hooking::clear_ped_tasks_immediately(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					}
				}
			};
			if (Menu::Option("Explode Everyone"_Secure)) {
				Ped playerPedID = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedID, 0);
				for (int i = 0; i <= 32; i++)
				{
					DoASM();
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
					if (!ENTITY::DOES_ENTITY_EXIST(Handle)) continue;
					FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 60, FLT_MAX, true, false, 1000.f);
					{
						if (i == 32)

						{
							break;
						}

					}
				}
			};
			if (Menu::Option("Shake Lobby"_Secure)) {
				Ped playerPedID = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedID, 0);
				for (int i = 0; i <= 32; i++)
				{
					DoASM();
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
					if (!ENTITY::DOES_ENTITY_EXIST(Handle)) continue;
					FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z + 15, 29, 999999.5f, false, true, 1.0f);
					{
						if (i == 32)

						{
							break;
						}

					}
				}
			};
			Menu::Toggle("Fuck Their Ears"_Secure, Features::earrapebool, [] { Features::earrape(Features::earrapebool); });
			if (Menu::Option("Give All Weapons"_Secure)) {
				
				for (int i = 0; i < 32; i++)
				{
					DoASM();
					if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
						Player allplayers = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
						if (!(Features::cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
						{
							if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
							{
								uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
								for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
									WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(allplayers), Weapons[i], 9999, 1);
								}
							}
						}
					}
				}
			}
			if (Menu::Option("Remove All Weapons"_Secure))
			{
				for (int i = 0; i <= 32; i++)
				{
					DoASM();
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					WEAPON::REMOVE_ALL_PED_WEAPONS(Handle, 1);
					{
						if (i == 32)
						{
							break;
						}
					}
				}
			}
			if (Menu::Option("Trap All In Cage"_Secure))
			{
				for (int i = 0; i <= 32; i++)
				{
					DoASM();
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
					Hash oball = GAMEPLAY::GET_HASH_KEY("prop_gold_cont_01");
					Hooking::request_model(oball);
					while (!Hooking::has_model_loaded(oball))
						WAIT(0);
					DoASM();
					Hooking::clear_ped_tasks_immediately(Handle);
					NETWORK::OBJ_TO_NET(OBJECT::CREATE_OBJECT_NO_OFFSET(oball, pCoords.x, pCoords.y, pCoords.z, 1, 0, 0));
					{
						if (i == 32)
						{
							break;
						}

					}
				}
			}
			if (Menu::Option("TP All to Me"_Secure)) {
				for (int i = 0; i <= 32; i++)
				{
					WAIT(0);
					if (i == PLAYER::PLAYER_ID())continue;
					Ped selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					Vector3 playerPedPos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
					if (ENTITY::DOES_ENTITY_EXIST(selectedPlayer))
					{
						DoASM();
						if (PED::IS_PED_IN_ANY_VEHICLE(selectedPlayer, 0))
						{
							Vehicle selectedPlayerVeh = PED::GET_VEHICLE_PED_IS_IN(selectedPlayer, 0);
							int tick = 0;
							RequestControlOfEnt(selectedPlayerVeh);
							while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(selectedPlayerVeh) || tick <= 25)
							{
								WAIT(0);
								NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(selectedPlayerVeh);
								tick++;
							}
							ENTITY::_SET_ENTITY_COORDS_2(selectedPlayerVeh, playerPedPos.x, playerPedPos.y, playerPedPos.z, 0, 0, 0, 1);
							notifyMap("~g~Teleported Players to You"_Secure);
							DoASM();
						}
						else
						{
							notifyMap("~r~This function only works if a player is in a vehicle"_Secure);
						}
						if (i == 32)
						{
							break;
						}
					}
					else
					{
						notifyMap("~r~Player doesn't exist"_Secure);
					}
				}
			}
			DoASM();
			Menu::Toggle("$2,000 Lobby Drop"_Secure, Features::twofitybool1[0], [] { Features::twofity1(Features::twofitybool1[0]); });
			//Menu::Break("Sometimes you have to hold NUMPAD5 on the Drop"_Secure);
		}
		break;
#pragma endregion
#pragma region Online Menu
		case onlineplayers:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Players"_Secure);
			for (int i = 0; i < 32; i++) {
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
					char msg[0xFF];
					DoASM();
					CPed* cp = handle_to_ptr<CPed>(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					string name = PLAYER::GET_PLAYER_NAME(i);

					BYTE* btIP = reinterpret_cast<BYTE*>(&cp->pCPlayerInfo->iExternalIP);
					sprintf_s(msg, " IP: %i.%i.%i.%i", *(btIP + 3), *(btIP + 2), *(btIP + 1), *btIP);

					sprintf_s(msg, "%s \n Is God: %s", msg, PLAYER::GET_PLAYER_INVINCIBLE(i) ? "Yes" : "No");
					sprintf_s(msg, "%s \n In Vehicle: %s", msg, PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false) ? "Yes" : "No");
					
					PLAYER::GET_PLAYER_INVINCIBLE(i) ? name += "~r~ MODDER" : name;

					if (!PLAYER::GET_PLAYER_INVINCIBLE(i) && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false) && VEHICLE::GET_VEHICLE_CLASS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i),0)) == 8)
						PED::CAN_KNOCK_PED_OFF_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)) ? name : name += "~r~ MODDER";

					NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i ? name += "~b~ HOST" : name;
					PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false) ? name += "~g~ IN VEHICLE" : name;
					DoASM();
					sprintf_s(msg, "%s \n Money: %d \n RP: %d \n Level: %d\n", msg, globalHandle(1595693 + (1 + (i * 680)) + 211 + 3), globalHandle(1595693 + (1 + (i * 680)) + 211 + 5), globalHandle(1595693 + (1 + (i * 680)) + 211 + 6));

					//Menu::info(msg);

					char loginfo[0xFF];


					char* name1 = reinterpret_cast<char*>(&cp->pCPlayerInfo->sName);
					BYTE* btIP2 = reinterpret_cast<BYTE*>(&cp->pCPlayerInfo->iRelayIP);
					__int32* cash = reinterpret_cast<__int32*>(&cp->iCash);
					bool god = reinterpret_cast<bool>(cp->isGod);
					bool invis = reinterpret_cast<bool>(cp->isInvisible);
					bool inveh = reinterpret_cast<bool>(cp->isInVehicle);
					float* starthealth = reinterpret_cast<float*>(&cp->fHealth);
					cp->giveHealth();
					float* endhealth = reinterpret_cast<float*>(&cp->fHealth);
					sprintf_s(loginfo, "%s : \n RelayIP : %i.%i.%i.%i \n ExternalIP : %i.%i.%i.%i \n Cash : %i \n Is God : %s \n Is Invisible : %s \n Is in Vehicle : %s \n Start Health : %f \n End Health : %f", name1, *(btIP2 + 3), *(btIP2 + 2), *(btIP2 + 1), *btIP2, *(btIP + 3), *(btIP + 2), *(btIP + 1), *btIP, cash, god ? "True" : "False", invis ? "True" : "False", inveh ? "True" : "False", starthealth, endhealth);

					//Write2File("DEBUG.txt", loginfo);
					Menu::info(loginfo);
					DoASM();
					Menu::MenuOption(name.c_str(), onlineplayeroptions) ? Features::Online::selectedPlayer = i : NULL;
				}
			}
		}
		break;
		case onlineplayeroptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
			Menu::MenuOption("Troll Options ~b~->"_Secure, trolloptions);
			Menu::MenuOption("Vehicle Options ~b~->"_Secure, vehicletroll);
			Menu::MenuOption("Partical Effects ~b~->"_Secure, PTFXSO);
			Menu::MenuOption("Attachments ~b~->"_Secure, attachments);
			Menu::Option("~r~ORBITAL BOMBARDMENT!!!"_Secure, [] { Features::OrbitalCannon(); });
			Menu::MenuOption("Send Attackers ~b~->"_Secure, sendattackers);
			/*if (Menu::Option("Send Text ~r~ (UNFINISHED)"_Secure)) 
			{
				char* message = CharKeyboard("Message:", 64, "");
				int handle = GetPlayerNetworkHandle(Features::Online::selectedPlayer);
				NETWORK::NETWORK_SEND_TEXT_MESSAGE(message, &handle);
			};*/
			Menu::Toggle("$2,000 Bags"_Secure, Features::twofitybool[Features::Online::selectedPlayer], [] { Features::twofity(Features::twofitybool[Features::Online::selectedPlayer]); });
			//Menu::Toggle("$50k CEO"_Secure, Features::ceomoneybool[Features::Online::selectedPlayer], [] { Features::ceomoney(Features::ceomoneybool[Features::Online::selectedPlayer]); });
			Menu::MenuOption("Give Vehicle ~b~->"_Secure, givefuckercar);
			if (Menu::Option("Give All Weapons"_Secure)) {
				uint Weapons[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), Weapons[i], 9999, 1);
					WAIT(10);
					DoASM();
				}
			}
			if (Menu::Option("Take All Weapons"_Secure)) {
				WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
			}
			Menu::Option("TP To Player"_Secure, [] {Features::Online::TeleportToPlayer(Features::Online::selectedPlayer); });
			DoASM();
			if (Menu::Option("TP Player to Me"_Secure)) {
				Ped selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				Vector3 playerPedPos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
				if (ENTITY::DOES_ENTITY_EXIST(selectedPlayer))
				{
					static int	count[32] = { 0 };
					Vector3	playerPos = get_coords_infront_player(6.f);
					Vector3	remotePos = CPlayerMem::get_player_coords(selectedPlayer);
					Ped	ped = CPlayerMem::get_player_ped(selectedPlayer);
					playerPos.z += 1.f;
					++count[player];
					if (distanceBetween(playerPos, remotePos) < 5.f || count[player] > 0x40)
					{
						count[player] = 0;
					}
					teleport_player_on_foot(ped, playerPos.x, playerPos.y, playerPos.z);
				}
				else
				{
					notifyMap("~r~Player doesn't exist"_Secure);
				}
			}
			Menu::Int("Vehicle Seat"_Secure, VehSeat, 0, VEHICLE::IS_VEHICLE_SEAT_FREE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false), VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false)) - 1));
			if (Menu::Option("TP Into Vehicle"_Secure)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				if (VEHICLE::IS_VEHICLE_SEAT_FREE(veh, VehSeat))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, VehSeat);
				}
				else
				{
					notifyMap("~r~ Selected Seat isn't Free!"_Secure, 0);
				}
			};
			if (Features::Online::selectedPlayer != PLAYER::PLAYER_ID()) { Menu::Toggle("Spectate"_Secure, Features::spectate[Features::Online::selectedPlayer], [] { Features::specter(Features::spectate[Features::Online::selectedPlayer]); }); }
			if (Menu::Option("Clone Player"_Secure))
			{
				PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1, 1, 1);
			}
			int clone[1000];
			int gcount = 1;
			if (Menu::Option("Spawn BodyGuard"_Secure)) 
			{
				DoASM();
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
				Hooking::request_model(pedm);
				while (!Hooking::has_model_loaded(pedm))
					WAIT(0);
				int my_group = PLAYER::GET_PLAYER_GROUP(selectedplayer);
				clone[gcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
				PED::SET_PED_AS_GROUP_LEADER(selectedplayer, my_group);
				PED::SET_PED_AS_GROUP_MEMBER(clone[gcount], my_group);
				PED::SET_PED_NEVER_LEAVES_GROUP(clone[gcount], my_group);
				ENTITY::SET_ENTITY_INVINCIBLE(clone[gcount], false);
				PED::SET_PED_COMBAT_ABILITY(clone[gcount], 100);
				WEAPON::GIVE_WEAPON_TO_PED(clone[gcount], railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(clone[gcount], true);
				PED::SET_GROUP_FORMATION(my_group, 3);
				PED::SET_PED_MAX_HEALTH(clone[gcount], 5000);
				gcount++;
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region Attachments
		case attachments:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			{
				DoASM();
				//variables n shit
				Ped myPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

				Menu::Title("Attachments"_Secure);
				if (Menu::Option("Attach Random Car"_Secure))
				{
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
					int vehID = VEHICLE::GET_CLOSEST_VEHICLE(coords.x, coords.y, coords.z, 600.0f, 0, 0);
					Vector3 defpos;
					defpos.x = 0.f;
					defpos.y = -.37f;
					defpos.z = -.2f;
					Vector3 defrot;
					defrot.x = 60.f;
					defrot.y = 0.f;
					defrot.z = 0.f;
					attach_entities(vehID, playerPed, -1, defpos, defrot);
				}
				if (Menu::Option("Attach"_Secure)) {
					if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer) != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))
					{
						Vector3 defpos;
						defpos.x = 0.f;
						defpos.y = -.37f;
						defpos.z = -.2f;
						Vector3 defrot;
						defrot.x = 60.f;
						defrot.y = 0.f;
						defrot.z = 0.f;
						attach_entities(myPed, playerPed, -1, defpos, defrot);
					}
				}
				if (Menu::Option("Detach"_Secure)) {
					ENTITY::DETACH_ENTITY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), true, true);
				}
				if (Menu::Option("Wheelchair"_Secure)) { Features::attachobjects2("prop_wheelchair_01"); }
				if (Menu::Option("Alien Egg"_Secure)) { Features::attachobjects2("prop_alien_egg_01"); }
				if (Menu::Option("EMP"_Secure)) { Features::attachobjects2("hei_prop_heist_emp"); }
				if (Menu::Option("Dildo"_Secure)) { Features::attachobjects2("PROP_CS_DILDO_01"); }
				if (Menu::Option("Orange Ball"_Secure)) { Features::attachobjects2("prop_juicestand"); }
				if (Menu::Option("Weed"_Secure)) { Features::attachobjects2("prop_weed_01"); }
				if (Menu::Option("Safe"_Secure)) { Features::attachobjects2("p_v_43_safe_s"); }
				if (Menu::Option("Windmill"_Secure)) { Features::attachobjects2("prop_windmill_01"); }
				if (Menu::Option("UFO"_Secure)) { Features::attachobjects2("p_spinning_anus_s"); }
				if (Menu::Option("Toilet"_Secure)) { Features::attachobjects2("prop_ld_toilet_01"); }
				if (Menu::Option("Christmas Tree"_Secure)) { Features::attachobjects2("prop_xmas_tree_int"); }
				if (Menu::Option("Radar"_Secure)) { Features::attachobjects2("prop_air_bigradar"); }
				if (Menu::Option("Beach Fire"_Secure)) { Features::attachobjects2("prop_beach_fire"); }
				char* objects[136] = { "prop_bskball_01", "PROP_MP_RAMP_03", "PROP_MP_RAMP_02", "PROP_MP_RAMP_01", "PROP_JETSKI_RAMP_01", "PROP_WATER_RAMP_03", "PROP_VEND_SNAK_01", "PROP_TRI_START_BANNER", "PROP_TRI_FINISH_BANNER", "PROP_TEMP_BLOCK_BLOCKER", "PROP_SLUICEGATEL", "PROP_SKIP_08A", "PROP_SAM_01", "PROP_RUB_CONT_01B", "PROP_ROADCONE01A", "PROP_MP_ARROW_BARRIER_01", "PROP_HOTEL_CLOCK_01", "PROP_LIFEBLURB_02", "PROP_COFFIN_02B", "PROP_MP_NUM_1", "PROP_MP_NUM_2", "PROP_MP_NUM_3", "PROP_MP_NUM_4", "PROP_MP_NUM_5", "PROP_MP_NUM_6", "PROP_MP_NUM_7", "PROP_MP_NUM_8", "PROP_MP_NUM_9", "prop_xmas_tree_int", "prop_bumper_car_01", "prop_beer_neon_01", "prop_space_rifle", "prop_dummy_01", "prop_rub_trolley01a", "prop_wheelchair_01_s", "PROP_CS_KATANA_01", "PROP_CS_DILDO_01", "prop_armchair_01", "prop_bin_04a", "prop_chair_01a", "prop_dog_cage_01", "prop_dummy_plane", "prop_golf_bag_01", "prop_arcade_01", "hei_prop_heist_emp", "prop_alien_egg_01", "prop_air_towbar_01", "hei_prop_heist_tug", "prop_air_luggtrolley", "PROP_CUP_SAUCER_01", "prop_wheelchair_01", "prop_ld_toilet_01", "prop_acc_guitar_01", "prop_bank_vaultdoor", "p_v_43_safe_s", "p_spinning_anus_s", "prop_can_canoe", "prop_air_woodsteps", "Prop_weed_01", "prop_a_trailer_door_01", "prop_apple_box_01", "prop_air_fueltrail1", "prop_barrel_02a", "prop_barrel_float_1", "prop_barrier_wat_03b", "prop_air_fueltrail2", "prop_air_propeller01", "prop_windmill_01", "prop_Ld_ferris_wheel", "p_tram_crash_s", "p_oil_slick_01", "p_ld_stinger_s", "p_ld_soc_ball_01", "prop_juicestand", "p_oil_pjack_01_s", "prop_barbell_01", "prop_barbell_100kg", "p_parachute1_s", "p_cablecar_s", "prop_beach_fire", "prop_lev_des_barge_02", "prop_lev_des_barge_01", "prop_a_base_bars_01", "prop_beach_bars_01", "prop_air_bigradar", "prop_weed_pallet", "prop_artifact_01", "prop_attache_case_01", "prop_large_gold", "prop_roller_car_01", "prop_water_corpse_01", "prop_water_corpse_02", "prop_dummy_01", "prop_atm_01", "hei_prop_carrier_docklight_01", "hei_prop_carrier_liferafts", "hei_prop_carrier_ord_03", "hei_prop_carrier_defense_02", "hei_prop_carrier_defense_01", "hei_prop_carrier_radar_1", "hei_prop_carrier_radar_2", "hei_prop_hei_bust_01", "hei_prop_wall_alarm_on", "hei_prop_wall_light_10a_cr", "prop_afsign_amun", "prop_afsign_vbike", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_airhockey_01", "prop_air_bagloader", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_cargo_01a", "prop_air_chock_01", "prop_air_chock_03", "prop_air_gasbogey_01", "prop_air_generator_03", "prop_air_stair_02", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_donut", "prop_amb_handbag_01", "prop_amp_01", "prop_anim_cash_pile_02", "prop_asteroid_01", "prop_arm_wrestle_01", "prop_ballistic_shield", "prop_bank_shutter", "prop_barier_conc_02b", "prop_barier_conc_05a", "prop_barrel_01a", "prop_bar_stool_01", "prop_basejump_target_01" };

				if (Menu::Option("Remove All"_Secure)) {
					for (int i = 0; i < 5; i++) {
						Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 1);
						GAMEPLAY::CLEAR_AREA_OF_PEDS(coords.x, coords.y, coords.z, 2, 0);
						GAMEPLAY::CLEAR_AREA_OF_OBJECTS(coords.x, coords.y, coords.z, 2, 0);
						GAMEPLAY::CLEAR_AREA_OF_VEHICLES(coords.x, coords.y, coords.z, 2, 0, 0, 0, 0, 0);
						for (int i = 0; i < 136; i++) {
							Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(coords.x, coords.y, coords.z, 4.0, GAMEPLAY::GET_HASH_KEY(objects[i]), 0, 0, 1);

							if (ENTITY::DOES_ENTITY_EXIST(obj) && ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(obj, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer))) {
								RequestControlOfEnt(obj);
								int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(obj);
								NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
								Features::RequestControlOfid(netID);
								ENTITY::DETACH_ENTITY(obj, 1, 1);
								if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(obj)) {
									ENTITY::SET_ENTITY_AS_MISSION_ENTITY(obj, 1, 1);
									ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&obj);
									ENTITY::DELETE_ENTITY(&obj);
								}
							}
						}
					}
				}
			}
			break;
#pragma endregion
#pragma region Give car
	case givefuckercar:
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Give vehicle"_Secure);
		DoASM();
		Menu::MenuOption("Spawn Settings ~b~->"_Secure, givevehsettings);
		Menu::MenuOption("DLC Vehicles ~b~->"_Secure, giveDLCSHITZ);
		Menu::MenuOption("Super ~b~->"_Secure, giveSuper);
		Menu::MenuOption("Sports ~b~->"_Secure, giveSports);
		Menu::MenuOption("Sport Classic ~b~->"_Secure, giveSportClassic);
		Menu::MenuOption("Offroad ~b~->"_Secure, giveOffroad);
		Menu::MenuOption("Sedans ~b~->"_Secure, giveSedans);
		Menu::MenuOption("Coupes ~b~->"_Secure, giveCoupes);
		Menu::MenuOption("Muscle ~b~->"_Secure, giveMuscle);
		Menu::MenuOption("Boats ~b~->"_Secure, giveBoats);
		Menu::MenuOption("Commercial ~b~->"_Secure, giveCommercial);
		Menu::MenuOption("Compacts ~b~->"_Secure, giveCompacts);
		Menu::MenuOption("Cycles ~b~->"_Secure, giveCycles);
		Menu::MenuOption("Emergency ~b~->"_Secure, giveEmergency);
		Menu::MenuOption("Helicopters ~b~->"_Secure, giveHelicopters);
		Menu::MenuOption("Industrial ~b~->"_Secure, giveIndustrial);
		Menu::MenuOption("Military ~b~->"_Secure, giveMilitary);
		Menu::MenuOption("Motorcycles ~b~->"_Secure, giveMotorcycles);
		Menu::MenuOption("Planes ~b~->"_Secure, givePlanes);
		Menu::MenuOption("Service ~b~->"_Secure, giveService);
		Menu::MenuOption("SUV ~b~->"_Secure, giveSUV);
		Menu::MenuOption("Trailer ~b~->"_Secure, giveTrailer);
		Menu::MenuOption("Trains ~b~->"_Secure, giveTrains);
		Menu::MenuOption("Utility ~b~->"_Secure, giveUtility);
		Menu::MenuOption("Vans ~b~->"_Secure, giveVans);
		}
	break;
	case givevehsettings:
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Settings"_Secure);
		Menu::Toggle("Spawn Maxed"_Secure, Features::givespawnmaxed);
		DoASM();
	}
	break;
	case giveDLCSHITZ: {
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
		GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::MenuOption("Bullshit Update ~b~->"_Secure, giveBullshit);
		Menu::MenuOption("Doomsday ~b~->"_Secure, giveDoomsday);
		Menu::MenuOption("Gunrunning ~b~->"_Secure, giveGunrunning);
		Menu::MenuOption("SmugglersRun ~b~->"_Secure, givesmugglersrun);
	}
	break;
	case giveBullshit:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		DoASM();
		Menu::Title("Bullshit Update"_Secure);
		for (auto car : BullshitUpdate) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveDoomsday:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		DoASM();
		Menu::Title("Doomsday"_Secure);
		for (auto car : DoomsdayHeist) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveSuper:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		DoASM();
		Menu::Title("Super"_Secure);
		for (auto car : Super1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveGunrunning:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		DoASM();
		Menu::Title("Gunrunning"_Secure);
		for (auto car : Gunrunning1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveSports:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		DoASM();
		Menu::Title("Sports"_Secure);
		for (auto car : Sports1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveSportClassic:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Sports Classic"_Secure);
		for (auto car : SportsClassics1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveOffroad:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Offroad"_Secure);
		for (auto car : OffRoad1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveSedans:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Sedans"_Secure);
		for (auto car : Sedans1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveCoupes:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Coupes"_Secure);
		for (auto car : Coupes1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveMuscle:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Muscle"_Secure);
		for (auto car : Muscle1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveBoats:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Boats"_Secure);
		for (auto car : Boats1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveCommercial:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Commercial"_Secure);
		for (auto car : Commercial1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveCompacts:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Compacts"_Secure);
		for (auto car : Compacts1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveCycles:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Cycles"_Secure);
		for (auto car : Cycles1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveEmergency:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Emergency"_Secure);
		for (auto car : Emergency1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveHelicopters:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Helicopters"_Secure);
		for (auto car : Helicopters1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveIndustrial:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Industrial"_Secure);
		for (auto car : Industrial1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveMilitary:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Military"_Secure);
		for (auto car : Military1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveMotorcycles:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Motorcycles"_Secure);
		for (auto car : Motorcycles1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case givePlanes:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Planes"_Secure);
		for (auto car : Planes1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveService:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Service"_Secure);
		for (auto car : Service1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveSUV:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("SUV"_Secure);
		for (auto car : SUVs1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveTrailer:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Trailer"_Secure);
		for (auto car : Trailer1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveTrains:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Trains"_Secure);
		for (auto car : Trains1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveUtility:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Utility"_Secure);
		for (auto car : Utility1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case giveVans:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Vans"_Secure);
		for (auto car : Vans1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
	case givesmugglersrun:
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
		GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
		GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
		Menu::Title("Smugglers Run"_Secure);
		for (auto car : Smugglers1) { Menu::Option(car, [car] { Features::spawn_vehicle_on_player(car); }); }
		break;
#pragma endregion
#pragma region Send Attackers
		case sendattackers:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Send Attackers"_Secure);
			int eclone[1000];
			int egcount = 1;
			if (Menu::Option("Killer Clown"_Secure)) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash knife = GAMEPLAY::GET_HASH_KEY("WEAPON_KNIFE");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash pedm = GAMEPLAY::GET_HASH_KEY("S_M_Y_Clown_01");
				Hooking::request_model(pedm);
				while (!Hooking::has_model_loaded(pedm))
					WAIT(0);
				eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
				ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
				PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
				WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], knife, knife, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
				PED::SET_PED_RELATIONSHIP_GROUP_HASH(eclone[egcount], GAMEPLAY::GET_HASH_KEY("COUGAR"));
				AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
				PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
				PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
				egcount++;
			}
			if (Menu::Option("Jesus"_Secure)) {
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
				Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
				Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
				Hooking::request_model(pedm);
				while (!Hooking::has_model_loaded(pedm))
					WAIT(0);
				eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
				ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
				PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
				WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
				PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
				AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
				PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
				PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
				egcount++;
			}
		}
		break;
#pragma endregion
#pragma region Vehicle Troll Options
		case vehicletroll:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			//variables n shit
			Ped myPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
			Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
			Player myPlayer = PLAYER::PLAYER_ID();
			Vector3 pCoordsMine = ENTITY::GET_ENTITY_COORDS(myPed, 0);
			Vehicle myveh = PED::GET_VEHICLE_PED_IS_IN(myPed, 0);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(Features::Online::selectedPlayer, 0);

			Menu::Title("Player Vehicle"_Secure);
			notifyMap("~g~You Have To Be In The Car ~r~OR ~g~Close To The Selected Player"_Secure, 0);

			if (Menu::Option("Flip Vehicle"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				Vector3 rotation = ENTITY::GET_ENTITY_ROTATION(veh, 0);
				ENTITY::SET_ENTITY_ROTATION(veh, 180, rotation.y, rotation.z, 0, 1);
				troll2();
			}
			if (Menu::Option("Godmode Vehicle"_Secure))
			{
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				ENTITY::SET_ENTITY_INVINCIBLE(veh, TRUE);
				ENTITY::SET_ENTITY_PROOFS(veh, 1, 1, 1, 1, 1, 1, 1, 1);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 0);
				WAIT(0);
				troll2();
			}
			DoASM();
			if (Menu::Option("Pop Tires"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				if (ENTITY::DOES_ENTITY_EXIST(playerPed) && ENTITY::DOES_ENTITY_EXIST(veh)) 
				{
					RequestControlOfEnt(veh);
					VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, true);
					for (int i = 0; i < 32; i++)
						VEHICLE::SET_VEHICLE_TYRE_BURST(veh, i, true, 10);
				}
				troll2();
			}
			if (Menu::Option("Open All Doors"_Secure))
			{
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				openVehDoors(veh);
				troll2();
			}
			if (Menu::Option("Close All Doors"_Secure))
			{
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				closeVehDoors(veh);
				troll2();
			}
			if (Menu::Option("Kill Engine"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 1, 1);
				VEHICLE::SET_VEHICLE_ENGINE_HEALTH(veh, -3700);
				troll2();
			}
			if (Menu::Option("Revive Engine"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_ENGINE_HEALTH(veh, 1000);
				troll2();
			}
			if (Menu::Option("Freeze Vehicle"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				ENTITY::FREEZE_ENTITY_POSITION(veh, 1);
				troll2();
			}
			if (Menu::Option("Unfreeze Vehicle"_Secure)) {
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				ENTITY::FREEZE_ENTITY_POSITION(veh, 0);
				troll2();
			}
			if (Menu::Option("Kick From Vehicle"_Secure)) 
			{
				troll1(true);
				Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(playerPed);
				Hooking::clear_ped_tasks_immediately(playerPed);
				AI::CLEAR_PED_TASKS(playerPed);
				AI::CLEAR_PED_SECONDARY_TASK(playerPed);
				troll2();
			}
			if (Menu::Option("Repair Vehicle"_Secure))
			{
				troll1(true);
				Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_FIXED(veh);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0.0f);
				troll2();
			}
			if (Menu::Option("Explode Vehicle"_Secure))
			{
				troll1(true);
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 60, FLT_MAX, true, false, 1000.f);
				troll2();
			}
		}
		break;
#pragma endregion
#pragma region Troll Options
		case trolloptions:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			//variables n shit
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Ped RemotePed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
			BOOL playerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vehicle playerVehicle = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
			DWORD Model = ENTITY::GET_ENTITY_MODEL(playerVehicle);
			Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
			Menu::Title("Troll Options"_Secure);
			Menu::Toggle("$2,500 Bags ~r~ TROLL"_Secure, Features::cashdrop2bool[Features::Online::selectedPlayer], [] { Features::cashdrop2(Features::cashdrop2bool[Features::Online::selectedPlayer]); });
			Menu::Option("Send Army of Fat Bitches"_Secure, Features::fatbitches2);
			Menu::Option("Send Army of Hot Bitches"_Secure, Features::fatbitches3);
			Menu::Toggle("Attack of the Peds"_Secure, Features::angrypedsbool, [] { Features::angrypeds(Features::angrypedsbool); });
			Menu::Toggle("Magnet Ped Vehicles"_Secure, Features::magnetpedsbool, [] { Features::magnetpeds(Features::magnetpedsbool); });
			if (Menu::Option("Cage Player"_Secure)) {
				Features::trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
			}
			if (Menu::Option("Explode Player"_Secure)) {
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 60, FLT_MAX, true, false, 1000.f);
			}
			Menu::Toggle("Water Loop"_Secure, Features::playerwaterloop[Features::Online::selectedPlayer], [] { Features::WaterLoop(Features::playerwaterloop[Features::Online::selectedPlayer]); });
			Menu::Toggle("Fake Moneydrop"_Secure, Features::fakebagsbool[Features::Online::selectedPlayer], [] { Features::fakebags(Features::fakebagsbool[Features::Online::selectedPlayer]); });
			Menu::Toggle("Fuck Vehicle handling"_Secure, Features::fuckedhandling[Features::Online::selectedPlayer], [] { Features::fuckhandling(Features::fuckedhandling[Features::Online::selectedPlayer]); });
			Menu::Toggle("Freeze"_Secure, Features::freezed[Features::Online::selectedPlayer], [] { Features::Freezer(Features::freezed[Features::Online::selectedPlayer]); });
			Menu::Toggle("Fire Loop"_Secure, Features::playerfireloop[Features::Online::selectedPlayer], [] { Features::FireLoop(Features::playerfireloop[Features::Online::selectedPlayer]); });
			Menu::MenuOption("Ram Player~b~->"_Secure, assram);//moved that shit to a sub-menu
			Menu::Toggle("Crash Player"_Secure, Features::attachobjectsCrashbool, [] { Features::attachobjectsCrash(Features::attachobjectsCrashbool); });
			if (NETWORK::NETWORK_IS_HOST())
			{
				if (Menu::Option("Kick Player ~g~Available [HOST]"_Secure)) { NETWORK::NETWORK_SESSION_KICK_PLAYER(Features::Online::selectedPlayer); };
			}
			else
				Menu::Option("Kick Player ~r~Unavailable [NOT HOST]"_Secure);

			/*if (Menu::Option("Fuck This Session"_Secure))
			{
				SCRIPT::SET_SCRIPT_AS_NO_LONGER_NEEDED("freemode");
			};*/
			DoASM();
		}
		break;
#pragma endregion
#pragma region ram Players
		case assram:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Ram Player"_Secure);
			/*if (Menu::Option("APC"_Secure)) {
				troll1();
				Vehicle veh = Features::ramplayer(562680400);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
				troll2();
			}
			if (Menu::Option("Tugboat"_Secure)) {
				troll1();
				Vehicle veh = Features::ramplayer(-2100640717);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
				troll2();
			}
			if (Menu::Option("CargoPlane"_Secure)) {
				troll1();
				Vehicle veh = Features::ramplayer(368211810);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
				troll2();
			}
			if (Menu::Option("Sandking"_Secure)) {
				troll1();
				Vehicle veh = Features::ramplayer(-1189015600);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
				troll2();
			}
			if (Menu::Option("Voltic"_Secure)) {
				troll1();
				Vehicle veh = Features::ramplayer(989294410);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
				troll2();
			}*/
			if (Menu::Option("Search for Vehicle to Ram With"_Secure)) {
				DWORD vehmodel;
				bool exists = get_vehicle_keyboard_result(&vehmodel);
				if (exists)
				{
					troll1(false);
					Vehicle veh = Features::ramplayer(vehmodel);
					ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 50, 0, 0, 0, 0, 1, true, true, true, false, true);
					troll2();
				}
			};
			Menu::Break("APC");
			Menu::Break("SANDKING");
			Menu::Break("VOLTIC2");
			Menu::Break("TUG");
		}
		break;
#pragma endregion
#pragma region Maze Bank
		case mazebank:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Get Money"_Secure);
			
			if (Features::riskymodebool == true)
			{
				Menu::Toggle("15Mill Stealth"_Secure, Features::stealthbool, [] { Features::Stealth15(Features::stealth15bool); });
			}
			if (Features::riskymodebool == true) 
			{
				Menu::Toggle("10Mill Stealth"_Secure, Features::stealth15bool, [] { Features::Stealth15(Features::stealth15bool); });
			}
			//Menu::Toggle("Sell Stealth ~r~Testing"_Secure, Features::stealth1bool, [] { Features::stealth1(Features::stealth1bool); });
			Menu::Toggle("Bounty Stealth"_Secure, Features::stealth2bool, [] { Features::stealth2(Features::stealth2bool); });
			//Menu::Toggle("Test Stealth ~r~Testing"_Secure, Features::stealth3bool, [] { Features::stealth3(Features::stealth3bool); });
			//if (Menu::Option("Lol Money"_Secure)) { Features::MoneyEdit(1000000, 1000000); };
			//Menu::Toggle("$10,000 Bags"_Secure, Features::cashdrop2bool[PLAYER::PLAYER_ID()], [] { Features::cashdrop2(Features::cashdrop2bool[PLAYER::PLAYER_ID()]); });
			Menu::Toggle("$2,000 Bags"_Secure, Features::twofitybool[PLAYER::PLAYER_ID()], [] { Features::twofity(Features::twofitybool[PLAYER::PLAYER_ID()]); });
			//Menu::Toggle("$50k CEO"_Secure, Features::ceomoneybool[PLAYER::PLAYER_ID()], [] { Features::ceomoney(Features::ceomoneybool[PLAYER::PLAYER_ID()]); });
			if (Features::storymodebool == true)
			{
				Menu::Toggle("Story Mode 100 Mil Drop"_Secure, Features::storycashdropbool, [] { Features::storycashdrop(Features::storycashdropbool); });
			}
			Menu::MenuOption("Move your money ~b~->"_Secure, bankshit);//moved that shit to sub
		}       
		break;
#pragma endregion
#pragma region Miscellaneous
		case miscellaneous:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Misc."_Secure);
			Menu::MenuOption("Credits ~b~->"_Secure, Credits);
			Menu::Toggle("Disable Safemode"_Secure, Features::riskymodebool, [] { Features::riskymode(Features::riskymodebool); });
			Menu::Toggle("Enable StoryMode Features"_Secure, Features::storymodebool, [] { Features::storymode(Features::storymodebool); });
			Menu::Toggle("Mobile Radio"_Secure, Features::mobileRadio, [] { Features::mobilevoid(Features::mobileRadio); });
			Menu::Toggle("Block Phone Calls"_Secure, Features::blockcallsbool, [] { Features::blockcalls(Features::blockcallsbool); });
			Menu::Toggle("Show Coordinates"_Secure, Features::showcoordsbool, [] {Features::showcoords(Features::showcoordsbool); });
			if (Menu::Option("Save Coordinates"_Secure)){ Features::savecoords(); };
			//ill make a new block phone after release
			if (Menu::Option("KILL GTA-V"_Secure)) exit(0);
		}
		break;
#pragma endregion

		case bankshit:
		{//bank shit
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Banking options"_Secure);
		if (Menu::Option("Deposit 1 Mill"_Secure))
			Features::deposit(1000000);

		if (Menu::Option("Deposit 5 Mill"_Secure))
			Features::deposit(5000000);

		if (Menu::Option("Deposit 10 Mill"_Secure))
			Features::deposit(10000000);

		if (Menu::Option("Deposit 50 Mill"_Secure))
			Features::deposit(50000000);

		if (Menu::Option("Deposit 100 Mill"_Secure))
			Features::deposit(100000000);

		if (Menu::Option("Withdraw 1 Mill"_Secure)) 
			Features::withdraw(1000000);

		if (Menu::Option("Withdraw 5 Mill"_Secure)) 
			Features::withdraw(5000000);

		if (Menu::Option("Withdraw 10 Mill"_Secure))
			Features::withdraw(10000000);

		if (Menu::Option("Withdraw 50 Mill"_Secure))
			Features::withdraw(50000000);

		if (Menu::Option("Withdraw 100 Mill"_Secure)) 
			Features::withdraw(100000000);
		}
		break;
#pragma region

#pragma endregion

/*#pragma region vision FX
		case visionFX:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Vision-FX"_Secure);
			//Menu::Toggle("Night Vision"_Secure, Features::nightvisionbool, [] { Features::nightvision(Features::nightvisionbool); });
			//Menu::Toggle("Heat Vision"_Secure, Features::heatvisionbool, [] { Features::heatvision(Features::heatvisionbool); });
			Menu::Toggle("Slow Motion"_Secure, Features::slomobool, [] { Features::slomonig(Features::slomobool); });
		}
		break;
#pragma endregion*/
#pragma region Settings Menu
		case settings:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Settings"_Secure);
			Menu::MenuOption("Colors ~b~->"_Secure, settingstheme);
			if (Menu::Int("Scroll Delay"_Secure, Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay"_Secure, Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}
		}
		break;
#pragma endregion
#pragma region Vehicle Options
		case vehicleoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_carmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_carmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_carmod", "shopui_title_carmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			//variables n shit
			Player player = PLAYER::PLAYER_ID();
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 1);
			const int PED_FLAG_CAN_FLY_THRU_WINDSCREEN = 32;
			Menu::Title("Vehicle Options"_Secure);
			Menu::MenuOption("Vehicle Spawner ~b~->"_Secure, vehiclespawner);
			Menu::MenuOption("Mobile LS Customs ~b~->"_Secure, vehcustom);
			Menu::MenuOption("Mobile Benny's Customs ~b~->"_Secure, vehcustom3);
			Menu::MenuOption("Paint Options ~b~->"_Secure, vehpaintoptions);
			Menu::MenuOption("Performance and Handling ~b~->"_Secure, vehperformance);
			Menu::MenuOption("Vehicle Modifiers ~b~->"_Secure, vehmodifiers);
			Menu::MenuOption("Saved Vehicles"_Secure, vehsavedvehs);
			Menu::Toggle("God Vehicle"_Secure, Features::cargodmodebool, [] { VehicleGodmode(Features::cargodmodebool); });
			if (Menu::Option("Repair Vehicle"_Secure)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
				if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
					VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed));
				else
					notifyMap("You're Not In A Vehicle"_Secure, 0);
			}
			if (Menu::Option("Max Car"_Secure)) {
				Features::maxvehicle();
			}
			if (Menu::Option("Fly Car Like Jet"_Secure)) {
				Features::jetcar();
			}
			Menu::Toggle("Vehicle Rockets"_Secure, Features::CarWeaponLoopBool, [] { Features::CarWeaponLoop(Features::CarWeaponLoopBool); });
			Menu::Toggle("Self Driving Car"_Secure, Features::SelfDriveBool, [] { Features::SelfDrive(Features::SelfDriveBool); });
			Menu::Toggle("Chauffeur"_Secure, Features::ChauffeurBool, [] { Features::Chauffeur(Features::ChauffeurBool); });
			if (Menu::Option("Ghostrider ~r~[Enable Godmode First!]")) 
			{ 
				Features::customcopcar();
			};
			Menu::Toggle("Fire Wheels"_Secure, Features::FireWheelsBool, [] { Features::FireWheels(Features::FireWheelsBool); });
			Menu::Toggle("Car Superman (Controls Relative to Map)"_Secure, Features::fcbool, [] { Features::FlyingCarLoop(Features::fcbool); });
			if (Menu::Option("Change Plate"_Secure)) { VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard()); }
			if (Menu::Option("Register Vehicle"_Secure))
			{
				if (bPlayerExists) {
					if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {

						Vehicle e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
						NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 1);
						for (int i = 0; i < 350; i++) {
							NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(e));
							NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
						}
						ENTITY::SET_ENTITY_AS_MISSION_ENTITY(e, true, true);
						for (int i = 0; i < 350; i++)NETWORK::SET_NETWORK_ID_CAN_MIGRATE(e, 0);
						VEHICLE::SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(e, 1);

						int b;
						char bname[] = "Vehicle Saved";
						b = UI::ADD_BLIP_FOR_ENTITY(e);
						UI::SET_BLIP_SPRITE(b, 60);
						UI::SET_BLIP_NAME_FROM_TEXT_FILE(b, bname);

						notifyMap("~b~Added ~w~Car de-spawn disabled"_Secure, 0);

					}

					else { notifyMap("You need to be in a car!"_Secure, 0); }
				}
			}
			if (Menu::Option("Teleport Into Closest Vehicle"_Secure))
			{
				int vehID = VEHICLE::GET_CLOSEST_VEHICLE(pos.x, pos.y, pos.z, 600.0f, 0, 0);
				PED::SET_PED_INTO_VEHICLE(playerPed, vehID, -1);
			}
			if (Menu::Option("Teleport to last vehicle"_Secure))
			{
				int vehID = PED::GET_VEHICLE_PED_IS_IN(playerPed, 1 );
				PED::SET_PED_INTO_VEHICLE(playerPed, vehID, -1);
			}
			if (Menu::Option("Open All Doors"_Secure)) {
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 0, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 1, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 2, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 3, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 4, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 5, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 6, 0, 0);
					VEHICLE::SET_VEHICLE_DOOR_OPEN(veh, 7, 0, 0);
			}
			if (Menu::Option("Close All Doors"_Secure)) {
				VEHICLE::SET_VEHICLE_DOORS_SHUT(veh, 0);
			}
			if (Menu::Option("Flip Car"_Secure)) {
				Features::flipup();
			}
			DoASM();
		}
		break;
#pragma endregion
#pragma region vehmodifiers
		case vehmodifiers:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Vehicle Modifiers"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);

			string vehHealth1 = "Vehicle Health1 [Current: " + std::to_string(Get_VehicleHealth1()) + "]";

			string vehHealth2 = "Vehicle Health2 [Current: " + std::to_string(Get_VehicleHealth2()) + "]";

			string vehBoost = "Vehicle Boost [Current: " + std::to_string(Get_VehicleBoost()) + "]";

			string vehAcceleration = "Vehicle Acceleration [Current: " + std::to_string(Get_VehicleAcceleration()) + "]";

			string vehBrakeForce = "Vehicle Brake Force [Current: " + std::to_string(Get_VehicleBrakeForce()) + "]";

			string vehHandBrakeForce = "Vehicle Hand Brake Force [Current: " + std::to_string(Get_VehicleHandBrakeForce()) + "]";

			string vehDeformMultiplier = "Vehicle Deform Multiplier [Current: " + std::to_string(Get_VehicleDeformMultiplier()) + "]";

			string vehDirtLevel = "Vehicle Dirt Level [Current: " + std::to_string(Get_VehicleDirtLevel()) + "]";

			string vehGravity = "Vehicle Gravity [Current: " + std::to_string(Get_VehicleGravity()) + "]";

			string vehRocketFuelLevel = "Vehicle Rocket Fuel Level [Current: " + std::to_string(Get_VehicleRocketFuelLevel()) + "]";

			string vehRocketRechargeSpeed = "Vehicle Rocket Recharge Speed [Current: " + std::to_string(Get_VehicleRocketRechargeSpeed()) + "]";

			string vehSuspensionForce = "Vehicle Suspension Force [Current: " + std::to_string(Get_VehicleSuspensionForce()) + "]";

			string vehSuspensionHeight = "VehicleSuspensionHeight [Current: " + std::to_string(Get_VehicleSuspensionHeight()) + "]";

			string vehTractionCurve = "VehicleTractionCurve [Current: " + std::to_string(Get_VehicleTractionCurve()) + "]";

			string vehDamageCurveMultiplier = "VehicleDamageCurveMultiplier [Current: " + std::to_string(Get_VehicleDamageCurveMultiplier()) + "]";

			if (Menu::Option(vehHealth1.c_str())) { Set_VehicleHealth1(NumberKeyboard()); };
			if (Menu::Option(vehHealth2.c_str())) { Set_VehicleHealth2(NumberKeyboard()); };
			if (Menu::Option(vehBoost.c_str())) { Set_VehicleBoost(NumberKeyboard()); };
			if (Menu::Option(vehAcceleration.c_str())) { Set_VehicleAcceleration(NumberKeyboard()); };
			if (Menu::Option(vehBrakeForce.c_str())) { Set_VehicleBrakeForce(NumberKeyboard()); };
			if (Menu::Option(vehHandBrakeForce.c_str())) { Set_VehicleHandBrakeForce(NumberKeyboard()); };
			if (Menu::Option(vehDeformMultiplier.c_str())) { Set_VehicleDeformMultiplier(NumberKeyboard()); };
			if (Menu::Option(vehDirtLevel.c_str())) { Set_VehicleDirtLevel(NumberKeyboard()); };
			if (Menu::Option(vehGravity.c_str())) { Set_VehicleGravity(NumberKeyboard()); };
			if (Menu::Option(vehRocketFuelLevel.c_str())) { Set_VehicleRocketFuelLevel(NumberKeyboard()); };
			if (Menu::Option(vehRocketRechargeSpeed.c_str())) { Set_VehicleRocketRechargeSpeed(NumberKeyboard()); };
			if (Menu::Option(vehSuspensionForce.c_str())) { Set_VehicleSuspensionForce(NumberKeyboard()); };
			if (Menu::Option(vehSuspensionHeight.c_str())) { Set_VehicleSuspensionHeight(NumberKeyboard()); };
			if (Menu::Option(vehTractionCurve.c_str())) { Set_VehicleTractionCurve(NumberKeyboard()); };
			if (Menu::Option(vehDamageCurveMultiplier.c_str())) { Set_VehicleDamageCurveMultiplier(NumberKeyboard()); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region Performance
		case vehperformance:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Performance and Handling"_Secure);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
			Menu::Toggle("Bypass Top Speed"_Secure, Features::maxspeedbool, [] { Features::maxspeed(Features::maxspeedbool); });
			//if (Menu::Option("Torq Multiplier"_Secure)) { int torque10 = NumberKeyboard(); Features::torque(torque10); };
			//if (Menu::Option("RPM Multiplier"_Secure)) { VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, NumberKeyboard()); }
			if (Menu::Option("Down-force Multiplier"_Secure)) { int down11 = NumberKeyboard(); Features::downforce(down11); };
			Menu::Toggle("Speedometer MPH"_Secure, Features::showspeedbool, [] {Features::showspeed(Features::showspeedbool); });
			Menu::Toggle("Speedometer KMPH"_Secure, Features::showspeed1bool, [] {Features::showspeed1(Features::showspeed1bool); });
			Menu::Toggle("Engine Always On"_Secure, Features::enginealwaysonbool, [] { Features::enginealwayson(Features::enginealwaysonbool); });
			if (Menu::Toggle("Bulletproof Tires"_Secure, Features::bulletprooftiresbool)) { Features::bulletprooftires(); }
			Menu::Toggle("Grip road"_Secure, Features::lowerveh50bool, [] { Features::lowerveh50(Features::lowerveh50bool); });
			Menu::Toggle("Super-grip road"_Secure, Features::lowerveh100bool, [] { Features::lowerveh100(Features::lowerveh100bool); });
			//if (Menu::Option("Reduce Grip (Click to Toggle)"_Secure)) { VEHICLE::SET_VEHICLE_REDUCE_GRIP(veh, true); };
			Menu::Toggle("Horn Boost"_Secure, Features::boostbool, [] { Features::carboost(Features::boostbool); });
			Menu::Toggle("Mega Horn Boost"_Secure, Features::superboostbool, [] { Features::supercarboost(Features::superboostbool); });
			Menu::Toggle("Fuck the Horn"_Secure, Features::fuckhornlolbool, [] { Features::fuckhornlol(Features::fuckhornlolbool); });
			Menu::Toggle("Drive on Water"_Secure, Features::dowbool, [] { Features::DriveOnWater(Features::dowbool); });
			Menu::Toggle("No fall from bike"_Secure, Features::nofallbool, [] { Features::nofall(Features::nofallbool); });
			DoASM();
		}
		break;
#pragma endregion
#pragma region Settings
		case vehsettings:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Settings"_Secure);
			Menu::Toggle("Spawn Maxed"_Secure, Features::spawnmaxed);
			Menu::Toggle("Auto TP In"_Secure, Features::spawnincar); 
			Menu::Toggle("Custom Cop Lights"_Secure, Features::CustomLightsbool, [] {Features::CustomLights(Features::CustomLightsbool); });
			//Menu::Toggle("DLC Bypass(storymode only)"_Secure, Features::gunrunningbypassbool);
			DoASM();
		}
		break;
#pragma endregion
#pragma region vehsavedvehs
		case vehsavedvehs:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Saved Vehicles"_Secure);
			ENTDatabase* database = Features::get_database();
			DoASM();
			std::vector<SavedVehicleDBRow*> savedVehs = database->get_saved_vehicles();

			int prevID = 0;

			
			for each (SavedVehicleDBRow *sv in savedVehs)
			{
				string save = sv->saveName;
				const char* name = save.c_str();
				int id = sv->rowID;
				DoASM();
				if (Menu::MenuOption(name, savedvehoptions)) { savedcars = id; };
				if (prevID < id)
				{
					prevID = id;
				}
			}
			prevID = prevID + 1;
			if (Menu::Option("Save Current Car to New Slot"_Secure)) { Features::save_current_vehicle(prevID); };
			notifyMap("~b~Re-open this menu to refresh the Saves"_Secure);
			//notifyBottom(std::to_string(prevID));
		}
		break;
#pragma endregion
#pragma region savedvehoptions
		case savedvehoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Saved Vehicle Options"_Secure);
			ENTDatabase* database = Features::get_database();
			DoASM();
			std::vector<SavedVehicleDBRow*> savedVehs = database->get_saved_vehicles(savedcars);
			DoASM();
			if (Menu::Option("Spawn Saved Car"_Secure)) { Features::spawn_saved_car(savedcars); };
			if (Menu::Option("Overwrite Saved Car with Current"_Secure)) { Features::overwrite_saved_car(savedcars); };
			if (Menu::Option("Rename Saved Car"_Secure)) { Features::rename_saved_car(savedcars); };
			if (Menu::Option("Delete Saved Car"_Secure)) { Features::delete_saved_car(savedcars); };
			
		}
		break;
#pragma endregion
#pragma region Paint Settings
		case vehpaintoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			Menu::Title("Paint Options"_Secure);
			Menu::MenuOption("Primary Paint Type"_Secure, primtype);
			Menu::MenuOption("Standard Primary Colors"_Secure, primpaint);
			Menu::MenuOption("Standard Pearlescent Colors"_Secure, pearlpaint);
			Menu::MenuOption("Secondary Paint Type"_Secure, secotype);
			Menu::MenuOption("Standard Secondary Colors"_Secure, secopaint);
			Menu::Toggle("Rainbow Car"_Secure, Features::rlbool, [] { Features::HasPaintLoop(Features::rlbool); });
			if (Menu::Option("Paint Random"_Secure)) {
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
				if (VEHICLE::GET_IS_VEHICLE_SECONDARY_COLOUR_CUSTOM(veh))
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			}
			DoASM();
			Menu::Option("Dirty Car"_Secure, Features::dirtycar);
			struct rgb
			{
				int r, g, b;
			};
			rgb primary;
			rgb secondary;
			rgb tire;
			VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &primary.r, &primary.g, &primary.b);
			VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &secondary.r, &secondary.g, &secondary.b);
			VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &tire.r, &tire.g, &tire.b);
			Menu::Int("Primary Red"_Secure, primary.r, 0, 255, 1);
			Menu::Int("Primary Green"_Secure, primary.g, 0, 255, 1);
			Menu::Int("Primary Blue"_Secure, primary.b, 0, 255, 1);
			Menu::Int("Secondary Red"_Secure, secondary.r, 0, 255, 1);
			Menu::Int("Secondary Green"_Secure, secondary.g, 0, 255, 1);
			Menu::Int("Secondary Blue"_Secure, secondary.b, 0, 255, 1);
			Menu::Int("Tire Smoke Red"_Secure, tire.r, 0, 255, 1);
			Menu::Int("Tire Smoke Green"_Secure, tire.g, 0, 255, 1);
			Menu::Int("Tire Smoke Blue"_Secure, tire.b, 0, 255, 1);

			if (Menu::Settings::leftPressed || Menu::Settings::rightPressed)
			{
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, primary.r, primary.g, primary.b);
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, secondary.r, secondary.g, secondary.b);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, tire.r, tire.g, tire.b);
			}
		}
		break;
#pragma endregion
#pragma region primtype
		case primtype:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Primary Type"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			struct BYTE
			{
				int typ, col, thg;
			};
			DoASM();
			BYTE mods;
			VEHICLE::GET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.typ, &mods.col, &mods.thg);
			if (Menu::Option("Normal"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0, mods.col, 0); };
			if (Menu::Option("Metallic"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 1, mods.col, 0); };
			if (Menu::Option("Pearl"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 2, mods.col, 0); };
			if (Menu::Option("Matte"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 3, mods.col, 0); };
			if (Menu::Option("Metal"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 4, mods.col, 0); };
			if (Menu::Option("Chrome"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_1(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 5, mods.col, 0); };
		}
		break;
#pragma endregion
#pragma region primpaint
		case primpaint:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Primary Colors"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			DoASM();
			for (int i = 0; i <= 160; i++)
			{
				int paint = ColorValues[i];
				char* color = ColorNames[i];
				Menu::Option(color, [paint] {
					struct BYTE
					{
						int pri, sec;
					};
					BYTE mods;
					VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.pri, &mods.sec);
					VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), paint, mods.sec); (paint); });
			}
		}
		break;
#pragma endregion
#pragma region secotype
		case secotype:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Secondary Type"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			DoASM();
			struct BYTE
			{
				int typ, col;
			};
			BYTE mods;
			VEHICLE::GET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.typ, &mods.col);
			if (Menu::Option("Normal"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0, mods.col); };
			if (Menu::Option("Metallic"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 1, mods.col); };
			if (Menu::Option("Pearl"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 2, mods.col); };
			if (Menu::Option("Matte"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 3, mods.col); };
			if (Menu::Option("Metal"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 4, mods.col); };
			if (Menu::Option("Chrome"_Secure)) { VEHICLE::SET_VEHICLE_MOD_COLOR_2(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 5, mods.col); };
		}
		break;
#pragma endregion
#pragma region secopaint
		case secopaint:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Secondary Colors"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			DoASM();
			for (int i = 0; i <= 160; i++)
			{
				int paint = ColorValues[i];
				char* color = ColorNames[i];
				Menu::Option(color, [paint] {
					struct BYTE
					{
						int pri, sec;
					};
					BYTE mods;
					VEHICLE::GET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.pri, &mods.sec); 
					VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), mods.pri, paint); (paint); });
			}
		}
		break;
#pragma endregion
#pragma region pearlpaint
		case pearlpaint:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Pearlescent Colors"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			DoASM();
			for (int i = 0; i <= 160; i++)
			{
				int paint = ColorValues[i];
				char* color = ColorNames[i];
				Menu::Option(color, [paint] {
					struct BYTE
					{
						int pea, whe;
					};
					BYTE mods;
					VEHICLE::GET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.pea, &mods.whe);
					VEHICLE::SET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), paint, mods.whe); (paint); });
			}
		}
		break;
#pragma endregion
#pragma region wheels
		case wheels:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Wheel Options"_Secure);
			Menu::MenuOption("Wheel Style"_Secure, tiretype);
			Menu::MenuOption("Wheel Color"_Secure, tirepaint);
			Menu::MenuOption("Wheels"_Secure, tirestyle);
			DoASM();
		}
		break;
#pragma endregion
#pragma region tiretype
		case tiretype:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Wheel Style"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Sport"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0); };
			if (Menu::Option("Muscle"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 1); };
			if (Menu::Option("Lowrider"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 2); };
			if (Menu::Option("SUV"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 3); };
			if (Menu::Option("Offroad"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 4); };
			if (Menu::Option("Tuner"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 5); };
			if (Menu::Option("Bike Wheels"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 6); };
			if (Menu::Option("High End"_Secure)) { VEHICLE::SET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 7); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region tirepaint
		case tirepaint:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Wheel Colors"_Secure);
			//VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			for (int i = 0; i <= 160; i++)
			{
				DoASM();
				int paint = ColorValues[i];
				char* color = ColorNames[i];
				Menu::Option(color, [paint] {
					struct BYTE
					{
						int pea, whe;
					};
					BYTE mods;
					VEHICLE::GET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), &mods.pea, &mods.whe);
					VEHICLE::SET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), mods.pea, paint); (paint); });
			}
		}
		break;
#pragma endregion
#pragma region tirestyle
		case tirestyle:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Wheels"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			int tyre = VEHICLE::GET_VEHICLE_WHEEL_TYPE(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0));
			if (tyre == -1) {
				Menu::Option("Stock Tires Have No Variants!"_Secure);
			}
			DoASM();
			if (tyre == 0) {
				for (int i = 0; i <= 23; i++)
				{
					int paint = SportWVal[i];
					char* color = SportW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 1) {
				for (int i = 0; i <= 17; i++)
				{
					int paint = MuscleWVal[i];
					char* color = MuscleW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 2) {
				for (int i = 0; i <= 14; i++)
				{
					int paint = LowriderWVal[i];
					char* color = LowriderW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 3) {
				for (int i = 0; i <= 18; i++)
				{
					int paint = SUVWVal[i];
					char* color = SUVW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 4) {
				for (int i = 0; i <= 9; i++)
				{
					int paint = OffroadWVal[i];
					char* color = OffroadW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 5) {
				for (int i = 0; i <= 23; i++)
				{
					int paint = TunerWVal[i];
					char* color = TunerW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
			if (tyre == 6) {
				for (int i = -1; i <= 12; i++)
				{
					int paint = MotorbikeWVal[i];
					char* color = MotorbikeW[i];
					Menu::Option(color, [paint] { 
						VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint);
						VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 24, paint, true); (paint);
					});
				}
			}
			if (tyre == 7) {
				for (int i = -1; i <= 19; i++)
				{
					int paint = HighEndWVal[i];
					char* color = HighEndW[i];
					Menu::Option(color, [paint] { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 23, paint, true); (paint); });
				}
			}
		}
		break;
#pragma endregion
#pragma region vehcustom
		case vehcustom:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Aztral");
			Menu::Title("LS Customs -PG 1-"_Secure);
			if (Menu::Int("Spoilers"_Secure, Spoilers, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 0) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 0, Spoilers, false);
			}
			if (Menu::Int("Front Bumper"_Secure, FBumper, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 1) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 1, FBumper, false);
			}
			if (Menu::Int("Rear Bumper"_Secure, RBumper, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 2) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 2, FBumper, false);
			}
			if (Menu::Int("Side Skirt"_Secure, SideSkirt, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 3) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 3, SideSkirt, false);
			}
			if (Menu::Int("Exhaust"_Secure, Exhaust, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 4) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 4, Exhaust, false);
			}
			if (Menu::Int("Frame"_Secure, Frame, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 5) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 5, Frame, false);
			}
			if (Menu::Int("Grille"_Secure, Grille, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 6) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 6, Grille, false);
			}
			if (Menu::Int("Hood"_Secure, Hood, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 7) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 7, Hood, false);
			}
			if (Menu::Int("Fender"_Secure, Fender, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 8) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 8, Fender, false);
			}
			if (Menu::Int("Right Fender"_Secure, RFender, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 9) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 9, RFender, false);
			}
			if (Menu::Int("Roof"_Secure, Roof, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 10) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 10, Roof, false);
			}
			Menu::MenuOption("Engine Options"_Secure, engine);
			Menu::MenuOption("Page 2 ~b~->"_Secure, vehcustom2);
			DoASM();
		}
		break;
#pragma endregion
#pragma region vehcustom2
		case vehcustom2:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Aztral");
			Menu::Title("LS Customs -PG 2-"_Secure);
			Menu::MenuOption("Brakes Options"_Secure, brakes);
			Menu::MenuOption("Transmission Options"_Secure, transmission);
			Menu::MenuOption("Horn Options"_Secure, horns);
			Menu::MenuOption("Suspension Options"_Secure, suspension);
			Menu::MenuOption("Armor Options"_Secure, armor);
			Menu::MenuOption("Wheel Options"_Secure, wheels);
			if (Menu::Int("Turbo on/off"_Secure, Turbo, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 18, true);
			}
			if (Menu::Int("Tire Smoke on/off"_Secure, TireSmoke, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 20, true);
			}
			if (Menu::Int("Xenon Lights on/off"_Secure, Headlights, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 22, true);
			}
			if (Menu::Int("Livery"_Secure, Livery, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 48) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 48, Livery, false);
			}
			if (Menu::Int("Window Tint"_Secure, Tint, 0, 6)) {
				VEHICLE::SET_VEHICLE_WINDOW_TINT(vehicle, Tint);
			}
			DoASM();
			/*if (Menu::Int("UNK17 on/off"_Secure, unk17, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 17, true);
			}
			if (Menu::Int("UNK19 on/off"_Secure, unk19, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 19, true);
			}
			if (Menu::Int("UNK21 on/off"_Secure, unk21, 0, 1)) {
				VEHICLE::TOGGLE_VEHICLE_MOD(vehicle, 21, true);
			}
			if (Menu::Int("UNK47"_Secure, unk47, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 47) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 47, unk47, false);
			}*/
		}
		break;
#pragma endregion
#pragma region vehcustom3
		case vehcustom3:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Aztral");
			Menu::Title("Benny's Customs -PG 1-"_Secure);
			if (Menu::Int("Plate Holder"_Secure, pholder, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 25) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 25, pholder, false);
			}
			if (Menu::Int("Vanity Plates"_Secure, vplates, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 26) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 26, vplates, false);
			}
			if (Menu::Int("Trim"_Secure, trims, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 27) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 27, trims, false);
			}
			if (Menu::Int("Ornaments"_Secure, ornas, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 28) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 28, ornas, false);
			}
			if (Menu::Int("Dashboard"_Secure, dash, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 29) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 29, dash, false);
			}
			if (Menu::Int("Dial"_Secure, dial, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 30) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 30, dial, false);
			}
			if (Menu::Int("Door Speaker"_Secure, dspeaker, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 31) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 31, dspeaker, false);
			}
			if (Menu::Int("Seats"_Secure, seats, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 32) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 32, seats, false);
			}
			if (Menu::Int("Steering-wheel"_Secure, swheel, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 33) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 33, swheel, false);
			}
			if (Menu::Int("Shifters"_Secure, shifter, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 34) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 34, shifter, false);
			}
			if (Menu::Int("Plaques"_Secure, plaq, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 35) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 35, plaq, false);
			}
			if (Menu::Int("Speakers"_Secure, speakers, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 36) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 36, speakers, false);
			}
			Menu::MenuOption("Page 2 ~b~->"_Secure, vehcustom4);
		}
		break;
#pragma endregion
#pragma region vehcustom4
		case vehcustom4:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
			//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Aztral");
			DoASM();
			Menu::Title("Benny's Customs -PG 2-"_Secure);
			if (Menu::Int("Trunk"_Secure, trunk, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 37) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 37, trunk, false);
			}
			if (Menu::Int("Hydraulics"_Secure, hydros, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 38) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 38, hydros, false);
			}
			if (Menu::Int("Engine Block"_Secure, eblock, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 39) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 39, eblock, false);
			}
			if (Menu::Int("Air Filter"_Secure, afilter, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 40) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 40, afilter, false);
			}
			if (Menu::Int("Struts"_Secure, struts, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 41) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 41, struts, false);
			}
			if (Menu::Int("Arch Cover"_Secure, acover, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 42) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 42, acover, false);
			}
			if (Menu::Int("Aerials"_Secure, aerials, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 43) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 43, aerials, false);
			}
			if (Menu::Int("Ext Trim"_Secure, trim2, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 44) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 44, trim2, false);
			}
			if (Menu::Int("Tank"_Secure, tank, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 45) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 45, tank, false);
			}
			if (Menu::Int("Windows"_Secure, winds, 0, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, 46) - 1)) {
				VEHICLE::SET_VEHICLE_MOD(vehicle, 46, winds, false);
			}
		}
		break;
#pragma endregion
#pragma region horns
		case horns:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Horns"_Secure);
			DoASM();
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Truck"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 0, false); };
			if (Menu::Option("Cop"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 1, false); };
			if (Menu::Option("Clown"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 2, false); };
			if (Menu::Option("Musical1"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 3, false); };
			if (Menu::Option("Musical2"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 4, false); };
			if (Menu::Option("Musical3"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 5, false); };
			if (Menu::Option("Musical4"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 6, false); };
			if (Menu::Option("Musical5"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 7, false); };
			if (Menu::Option("Classical1"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 8, false); };
			if (Menu::Option("Classical2"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 9, false); };
			if (Menu::Option("Classical3"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 10, false); };
			if (Menu::Option("Classical4"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 11, false); };
			if (Menu::Option("Classical5"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 12, false); };
			if (Menu::Option("Classical6"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 13, false); };
			if (Menu::Option("Classical7"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 14, false); };
			if (Menu::Option("Do"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 15, false); };
			if (Menu::Option("Re"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 16, false); };
			if (Menu::Option("Mi"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 17, false); };
			if (Menu::Option("Fa"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 18, false); };
			if (Menu::Option("Sol"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 19, false); };
			if (Menu::Option("La"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 20, false); };
			if (Menu::Option("Ti"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 21, false); };
			if (Menu::Option("Do(High)"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 22, false); };
			if (Menu::Option("Jazz1"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 23, false); };
			if (Menu::Option("Jazz2"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 24, false); };
			if (Menu::Option("Jazz3"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 25, false); };
			if (Menu::Option("JazzLoop"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 26, false); };
			if (Menu::Option("StarSpangledBanner1"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 27, false); };
			if (Menu::Option("StarSpangledBanner2"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 28, false); };
			if (Menu::Option("StarSpangledBanner3"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 29, false); };
			if (Menu::Option("StarSpangledBanner4"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 14, 30, false); };
		}
		break;
#pragma endregion
#pragma region engine
		case engine:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("EMS"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Level 1"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 11, 0, false); };
			if (Menu::Option("Level 2"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 11, 1, false); };
			if (Menu::Option("Level 3"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 11, 2, false); };
			if (Menu::Option("Level 4"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 11, 3, false); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region brakes
		case brakes:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Brakes"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Street"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 12, 0, false); };
			if (Menu::Option("Sport"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 12, 1, false); };
			if (Menu::Option("Race"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 12, 2, false); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region transmission
		case transmission:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Transmission"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Street"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 13, 0, false); };
			if (Menu::Option("Sport"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 13, 1, false); };
			if (Menu::Option("Race"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 13, 2, false); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region suspension
		case suspension:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Suspension"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("Lowered"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 15, 0, false); };
			if (Menu::Option("Street"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 15, 1, false); };
			if (Menu::Option("Sport"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 15, 2, false); };
			if (Menu::Option("Competition"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 15, 3, false); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region armor
		case armor:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_clubhousemod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_clubhousemod");
			GRAPHICS::DRAW_SPRITE("shopui_title_clubhousemod", "shopui_title_clubhousemod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Armor"_Secure);
			VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 0);
			if (Menu::Option("20%"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 16, 0, false); };
			if (Menu::Option("40%"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 16, 1, false); };
			if (Menu::Option("60%"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 16, 2, false); };
			if (Menu::Option("80%"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 16, 3, false); };
			if (Menu::Option("100%"_Secure)) { VEHICLE::SET_VEHICLE_MOD(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0), 16, 4, false); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region Credits
		case Credits:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Credits"_Secure);
			Menu::Option("~p~ DEV-Ace ~b~->"_Secure);
			Menu::Option("~r~ Owner/DEV-Rexxah ~b~->"_Secure);
			Menu::Option("~g~ Huge thanks to our Discord Staff! ~b~->"_Secure);
			DoASM();
		}
		break;
#pragma endregion
#pragma region Settings Menu
		case settingstheme:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Colors"_Secure);
			Menu::MenuOption("Default Themes ~b~->"_Secure, themeloader);
			Menu::MenuOption("Title Box ~b~->"_Secure, settingstitlerect);
			Menu::MenuOption("Title Text ~b~->"_Secure, settingstitletext);
			Menu::MenuOption("Selection Box ~b~->"_Secure, settingsscroller);
			Menu::MenuOption("Option Text ~b~->"_Secure, settingsoptiontext);
			Menu::Toggle("Rainbow Menu"_Secure, Features::rainbowmenu, [] { Features::Rainbowmenu(Features::rainbowmenu); });
			DoASM();
		}
		break;
#pragma endregion
#pragma region Default Themes
		case themeloader:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Default Colors"_Secure);
			if (Menu::Option("Halloween Theme"_Secure)) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 255, 77, 0, 255 };
				Menu::Settings::scroller = { 255, 77, 0, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 6 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
				Menu::Settings::checkBox = { 255, 77, 0, 255 };
			}
			if (Menu::Option("Christmas Theme"_Secure)) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 0, 128, 255, 15 };
				Menu::Settings::scroller = { 0, 128, 255, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 6 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
				Menu::Settings::checkBox = { 0, 128, 255, 255 };
			}
			if (Menu::Option("Red Theme"_Secure)) {
				Menu::Settings::titleRect = { 100, 0, 0, 15 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::checkBox = { 100, 0, 0, 255 };
			}
			if (Menu::Option("Blue Theme"_Secure)) {
				Menu::Settings::titleRect = { 0, 0, 200, 15 };
				Menu::Settings::scroller = { 0, 0, 200, 255 };
				Menu::Settings::checkBox = { 0, 0, 200, 255 };
			}
			if (Menu::Option("Green Theme"_Secure)) {
				Menu::Settings::titleRect = { 0, 180, 0, 15 };
				Menu::Settings::scroller = { 0, 180, 0, 255 };
				Menu::Settings::checkBox = { 0, 180, 0, 255 };
			}
		}
		break;
#pragma endregion
#pragma region Title Settings
		case settingstitlerect:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Title Rectangle"_Secure);
			if (Menu::Int("Red"_Secure, Menu::Settings::titleRect.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green"_Secure, Menu::Settings::titleRect.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue"_Secure, Menu::Settings::titleRect.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity"_Secure, Menu::Settings::titleRect.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.a = NumberKeyboard();
				}
			}
		}
		break;
#pragma endregion
#pragma region Title Text Settings
		case settingstitletext:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Title Text"_Secure);

			if (Menu::Int("Red"_Secure, Menu::Settings::titleText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green"_Secure, Menu::Settings::titleText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue"_Secure, Menu::Settings::titleText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity"_Secure, Menu::Settings::titleText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			Menu::MenuOption("Font ~b~->"_Secure, titlefont);
		}
		break;
#pragma endregion
#pragma region Option Settings
		case settingsoptiontext:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Option Text"_Secure);
			if (Menu::Int("Red"_Secure, Menu::Settings::optionText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green"_Secure, Menu::Settings::optionText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue"_Secure, Menu::Settings::optionText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity"_Secure, Menu::Settings::optionText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			Menu::MenuOption("Font ~b~->"_Secure, font);
		}
		break;
#pragma endregion
#pragma region Font Settings
		case font:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Font"_Secure);
			if (Menu::Option("Chalet London"_Secure)) { Menu::Settings::optionText.f = 0; }
			if (Menu::Option("House Script"_Secure)) { Menu::Settings::optionText.f = 1; }
			if (Menu::Option("Monospace"_Secure)) { Menu::Settings::optionText.f = 2; }
			if (Menu::Option("Wing Dings"_Secure)) { Menu::Settings::optionText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne"_Secure)) { Menu::Settings::optionText.f = 4; }
			if (Menu::Option("Pricedown"_Secure)) { Menu::Settings::optionText.f = 7; }
			DoASM();
		}
		break;
#pragma endregion
#pragma region Title Font
		case titlefont:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Font"_Secure);
			if (Menu::Option("Chalet London"_Secure)) { Menu::Settings::titleText.f = 0; }
			if (Menu::Option("House Script"_Secure)) { Menu::Settings::titleText.f = 1; }
			if (Menu::Option("Monospace"_Secure)) { Menu::Settings::titleText.f = 2; }
			if (Menu::Option("Wing Dings"_Secure)) { Menu::Settings::titleText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne"_Secure)) { Menu::Settings::titleText.f = 4; }
			if (Menu::Option("Pricedown"_Secure)) { Menu::Settings::titleText.f = 7; }
			DoASM();
		}
		break;
#pragma endregion
#pragma region
		case settingsscroller:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Scroller"_Secure);
			if (Menu::Int("Red"_Secure, Menu::Settings::scroller.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green"_Secure, Menu::Settings::scroller.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue"_Secure, Menu::Settings::scroller.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity"_Secure, Menu::Settings::scroller.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.a = NumberKeyboard();
				}
			}
		}
		break;
#pragma endregion
#pragma region Car Spawn
		case vehiclespawner: {
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Vehicle Types"_Secure);
			DoASM();
			Menu::MenuOption("Spawn Settings ~b~->"_Secure, vehsettings);
			if (Menu::Option("Let me Store this in my Garage!"_Secure)) { Features::BypassOnlineVehicle(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()))); };
			if (Menu::Option("Search for Vehicle"_Secure)) {
				DWORD vehmodel;
				bool exists = get_vehicle_keyboard_result(&vehmodel);
				if (exists)
				{
					Features::do_spawn_vehicle(vehmodel);
				}
			};
			Menu::MenuOption("DLC Vehicles ~b~->"_Secure, DLCSHITZ);
			Menu::MenuOption("Super ~b~->"_Secure, Super);
			Menu::MenuOption("Sports ~b~->"_Secure, Sports);
			Menu::MenuOption("Sport Classic ~b~->"_Secure, SportClassic);
			Menu::MenuOption("Offroad ~b~->"_Secure, Offroad);
			Menu::MenuOption("Sedans ~b~->"_Secure, Sedans);
			Menu::MenuOption("Coupes ~b~->"_Secure, Coupes);
			Menu::MenuOption("Muscle ~b~->"_Secure, Muscle);
			Menu::MenuOption("Boats ~b~->"_Secure, Boats);
			Menu::MenuOption("Commercial ~b~->"_Secure, Commercial);
			Menu::MenuOption("Compacts ~b~->"_Secure, Compacts);
			Menu::MenuOption("Cycles ~b~->"_Secure, Cycles);
			Menu::MenuOption("Emergency ~b~->"_Secure, Emergency);
			Menu::MenuOption("Helicopters ~b~->"_Secure, Helicopters);
			Menu::MenuOption("Industrial ~b~->"_Secure, Industrial);
			Menu::MenuOption("Military ~b~->"_Secure, Military);
			Menu::MenuOption("Motorcycles ~b~->"_Secure, Motorcycles);
			Menu::MenuOption("Planes ~b~->"_Secure, Planes);
			Menu::MenuOption("Service ~b~->"_Secure, Service);
			Menu::MenuOption("SUV ~b~->"_Secure, SUV);
			Menu::MenuOption("Trailer ~b~->"_Secure, Trailer);
			Menu::MenuOption("Trains ~b~->"_Secure, Trains);
			Menu::MenuOption("Utility ~b~->"_Secure, Utility);
			Menu::MenuOption("Vans ~b~->"_Secure, Vans);
			}
			break;
		case DLCSHITZ: {
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::MenuOption("Bullshit Update ~b~->"_Secure, BullshitCars);
			Menu::MenuOption("Doomsday ~b~->"_Secure, Doomsday);
			Menu::MenuOption("Gunrunning ~b~->"_Secure, Gunrunning);
			Menu::MenuOption("SmugglersRun ~b~->"_Secure, smugglersrun);
		}
		  break;
		case Super:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);

			Menu::Title("Super"_Secure);
			//void drawCar(char* name, char* texture)
			//VehicleNames
			//VehicleTextures
			carint = -1;
			for (auto car : Super1)
			{
				if (SUPER1TEXTURES[carint] != DOOMSDAYHEISTTEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Super1[carint], SUPER1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
				
			}
			break;
		case BullshitCars:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);

			Menu::Title("Bullshit Update"_Secure);
			carint = -1;
			for (auto car : BullshitUpdate) 
			{ 
				if (BULLSHITUPDATETEXTURES[carint] != DOOMSDAYHEISTTEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(BullshitUpdate[carint], BULLSHITUPDATETEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Doomsday:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			DoASM();
			Menu::Title("Doomsday"_Secure);
			carint = -1;
			for (auto car : DoomsdayHeist) 
			{ 
				if (DOOMSDAYHEISTTEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(DoomsdayHeist[carint], DOOMSDAYHEISTTEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Gunrunning:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			DoASM();
			Menu::Title("Gunrunning"_Secure);
			carint = -1;
			for (auto car : Gunrunning1) 
			{ 
				if (GUNRUNNING1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Gunrunning1[carint], GUNRUNNING1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Sports:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			DoASM();
			Menu::Title("Sports"_Secure);
			carint = -1;
			for (auto car : Sports1) 
			{ 
				if (SPORTS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Sports1[carint], SPORTS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case SportClassic:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Sports Classic"_Secure);
			carint = -1;
			for (auto car : SportsClassics1) 
			{
				if (SPORTSCLASSICS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(SportsClassics1[carint], SPORTSCLASSICS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Offroad:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Offroad"_Secure);
			carint = -1;
			for (auto car : OffRoad1) 
			{ 
				if (OFFROAD1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(OffRoad1[carint], OFFROAD1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Sedans:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Sedans"_Secure);
			carint = -1;
			for (auto car : Sedans1) 
			{ 
				if (SEDANS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Sedans1[carint], SEDANS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Coupes:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Coupes"_Secure);
			carint = -1;
			for (auto car : Coupes1) 
			{
				if (COUPES1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Coupes1[carint], COUPES1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Muscle:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Muscle"_Secure);
			carint = -1;
			for (auto car : Muscle1)
			{ 
				if (MUSCLE1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Muscle1[carint], MUSCLE1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Boats:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Boats"_Secure);
			carint = -1;
			for (auto car : Boats1)
			{ 
				if (BOATS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Boats1[carint], BOATS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Commercial:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Commercial"_Secure);
			carint = -1;
			for (auto car : Commercial1) 
			{ 
				if (COMMERCIAL1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Commercial1[carint], COMMERCIAL1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Compacts:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Compacts"_Secure);
			carint = -1;
			for (auto car : Compacts1) 
			{
				if (COMPACTS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Compacts1[carint], COMPACTS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Cycles:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Cycles"_Secure);
			carint = -1;
			for (auto car : Cycles1) 
			{ 
				if (CYCLES1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Cycles1[carint], CYCLES1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Emergency:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Emergency"_Secure);
			carint = -1;
			for (auto car : Emergency1) 
			{
				if (EMERGENCY1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Emergency1[carint], EMERGENCY1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Helicopters:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Helicopters"_Secure);
			carint = -1;
			for (auto car : Helicopters1) 
			{ 
				if (HELICOPTERS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Helicopters1[carint], HELICOPTERS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Industrial:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Industrial"_Secure);
			carint = -1;
			for (auto car : Industrial1) 
			{
				if (INDUSTRIAL1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Industrial1[carint], INDUSTRIAL1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Military:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Military"_Secure);
			carint = -1;
			for (auto car : Military1) 
			{
				if (MILITARY1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Military1[carint], MILITARY1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Motorcycles:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Motorcycles"_Secure);
			carint = -1;
			for (auto car : Motorcycles1) 
			{ 
				if (MOTORCYCLES1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Motorcycles1[carint], MOTORCYCLES1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Planes:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Planes"_Secure);
			carint = -1;
			for (auto car : Planes1) 
			{
				if (PLANES1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Planes1[carint], PLANES1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Service:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Service"_Secure);
			carint = -1;
			for (auto car : Service1)
			{
				if (SERVICE1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Service1[carint], SERVICE1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case SUV:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("SUV"_Secure);
			carint = -1;
			for (auto car : SUVs1) 
			{ 
				if (SUVS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(SUVs1[carint], SUVS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Trailer:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Trailer"_Secure);
			carint = -1;
			for (auto car : Trailer1)
			{ 
				if (TRAILER1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Trailer1[carint], TRAILER1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Trains:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Trains"_Secure);
			carint = -1;
			for (auto car : Trains1) 
			{
				if (TRAINS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Trains1[carint], TRAINS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Utility:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Utility"_Secure);
			carint = -1;
			for (auto car : Utility1) 
			{ 
				if (UTILITY1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Utility1[carint], UTILITY1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case Vans:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Vans"_Secure);
			carint = -1;
			for (auto car : Vans1) 
			{ 
				if (VANS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Vans1[carint], VANS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
		case smugglersrun:
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_ie_modgarage", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_ie_modgarage");
			GRAPHICS::DRAW_SPRITE("shopui_title_ie_modgarage", "shopui_title_ie_modgarage", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Smugglers Run"_Secure);
			carint = -1;
			for (auto car : Smugglers1) 
			{ 
				if (SMUGGLERS1TEXTURES[carint] != BULLSHITUPDATETEXTURES[0])
				{
					if (Menu::Settings::currentOption == Menu::Settings::optionCount)
					{
						drawCar(Smugglers1[carint], SMUGGLERS1TEXTURES[carint]);
					}
				}
				Menu::Option(car, [car] { Features::spawn_vehicle(car); });
				carint++;
			}
			break;
#pragma endregion
#pragma region animateshit
		case animateshit:
		{
			DoASM();
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Animations"_Secure);
			Menu::MenuOption("Scenarios ~b~->"_Secure, Scenarios);
			if (Menu::Option("Clear Animation"_Secure)) { Features::clearanim(); }
			if (Menu::Option("Pole Dance"_Secure)) { Features::doAnimation("mini@strip_club@pole_dance@pole_dance1", "pd_dance_01"); }
			if (Menu::Option("Stripper Dance"_Secure)) { Features::doAnimation("mini@strip_club@private_dance@part1", "priv_dance_p1"); }
			if (Menu::Option("Sex Receiver"_Secure)) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_poppy"); }
			if (Menu::Option("Sex Giver"_Secure)) { Features::doAnimation("rcmpaparazzo_2", "shag_loop_a"); }
			if (Menu::Option("Push Ups"_Secure)) { Features::doAnimation("amb@world_human_push_ups@male@base", "base"); }
			if (Menu::Option("Sit Ups"_Secure)) { Features::doAnimation("amb@world_human_sit_ups@male@base", "base"); }
			if (Menu::Option("Celebrate"_Secure)) { Features::doAnimation("rcmfanatic1celebrate", "celebrate"); }
			if (Menu::Option("Electrocution"_Secure)) { Features::doAnimation("ragdoll@human", "electrocute"); }
			if (Menu::Option("Suicide"_Secure)) { Features::doAnimation("mp_suicide", "pistol"); }
			if (Menu::Option("Showering"_Secure)) { Features::doAnimation("mp_safehouseshower@male@", "male_shower_idle_b"); }
			}
		break;
#pragma endregion
#pragma region Scenarios
		case Scenarios:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_gr_gunmod", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_gr_gunmod");
			GRAPHICS::DRAW_SPRITE("shopui_title_gr_gunmod", "shopui_title_gr_gunmod", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Sceanarios"_Secure);
			if (Menu::Option("Stop animation"_Secure)) Hooking::clear_ped_tasks_immediately(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
			if (Menu::Option("Lean on Wall"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_LEANING", 0, true);
			if (Menu::Option("Drinking Coffee"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_AA_COFFEE", 0, true);
			if (Menu::Option("Playing Instruments"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_MUSICIAN", 0, true);
			if (Menu::Option("BBQ"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "PROP_HUMAN_BBQ", 0, true);
			if (Menu::Option("Fishing"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_STAND_FISHING", 0, true);
			if (Menu::Option("Film Shocking"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_MOBILE_FILM_SHOCKING", 0, true);
			if (Menu::Option("Idle Cop"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_COP_IDLES", 0, true);
			if (Menu::Option("Flexing"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_MUSCLE_FLEX", 0, true);
			if (Menu::Option("Binoculars"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_BINOCULARS", 0, true);
			if (Menu::Option("Clipboard"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_CLIPBOARD", 0, true);
			if (Menu::Option("Bench Press"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS", 0, true);
			if (Menu::Option("Drug Dealer"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_DRUG_DEALER_HARD", 0, true);
			if (Menu::Option("Jogging"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_JOG_STANDING", 0, true);
			if (Menu::Option("Superhero"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_SUPERHERO", 0, true);
			if (Menu::Option("Paparizzi"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_PAPARAZZI", 0, true);
			if (Menu::Option("Security"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_SECURITY_SHINE_TORCH", 0, true);
			if (Menu::Option("Leaf Blower"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_GARDENER_LEAF_BLOWER", 0, true);
			if (Menu::Option("Chin Ups"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "PROP_HUMAN_MUSCLE_CHIN_UPS", 0, true);
			if (Menu::Option("Drinking"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_DRINKING", 0, true);
			if (Menu::Option("Golf Player"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_GOLF_PLAYER", 0, true);
			if (Menu::Option("Welding"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_WELDING", 0, true);
			if (Menu::Option("Smoking Pot"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_SMOKING_POT", 0, true);
			if (Menu::Option("Hammering"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_HAMMERING", 0, true);
			if (Menu::Option("Tennis"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_TENNIS_PLAYER", 0, true);
			if (Menu::Option("Drilling"_Secure)) AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), "WORLD_HUMAN_CONST_DRILL", 0, true);
			DoASM();
		}
		break;
#pragma endregion
#pragma region propplacement
		case propplacement:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Props Menu"_Secure);
			Menu::MenuOption("Prop Spawner"_Secure, propspawnermenu);
			Menu::MenuOption("Spawner Options"_Secure, propoptions);
			Menu::MenuOption("Edit Spawned Props"_Secure, propedit);
			if (Menu::Option("Remove all Spawned Objects"_Secure)) { Features::deleteprops; };
			DoASM();
		}
			break;
#pragma endregion
#pragma region propspawnermenu
		case propspawnermenu:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Prop Spawner Menu"_Secure);
			int i = 0;
			for each (std::string category in PROP_CATEGORIES)
			{
				const char* propcategory = category.c_str();
				if (Menu::MenuOption(propcategory, propspawner1)) { propcat = i; };
				i++;
			}
			if (Menu::Option("Enter Name Manually"_Secure)) { propcat = -1; Features::PropSpawn(propcat); };
			DoASM();
		}
			break;
#pragma endregion
#pragma region propspawner1
		case propspawner1:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Prop Selection"_Secure);
			std::string category = PROP_CATEGORIES[propcat];
			for each (PropInfo prop in ALL_PROPS)
			{
				if (prop.category == category)
				{
					const char* proplabel = prop.label.c_str();
					if (Menu::Option(proplabel)) { Features::do_spawn_prop(prop, true); };
				}
			}
			//notifyBottom(category);
		}
			break;
#pragma endregion
#pragma region propoptions
		case propoptions:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Prop Options"_Secure);
			Menu::Toggle("Invincible?"_Secure, Features::propCreationIsInvincible);
			Menu::Toggle("Immovable?"_Secure, Features::propCreationIsImmovable);
			Menu::Toggle("Has Gravity?"_Secure, Features::propCreationHasGravity);
			Menu::Toggle("On Fire?"_Secure, Features::propCreationIsOnFire);
			Menu::Int("Alpha Values (0=100%, 4=20%)"_Secure, Features::propCreationAlphaIndex, 0, 4, 1);
		}
			break;
#pragma endregion
#pragma region propedit
		case propedit:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Prop Editor"_Secure);
			Features::manage_prop_set();

			int i = 0;

			std::vector<SpawnedPropInstance*>::iterator it;
			for (it = Features::propsWeCreated.begin(); it != Features::propsWeCreated.end(); it++)
			{
				SpawnedPropInstance* instance = *it;

				std::ostringstream ss;
				ss << instance->title << "~y~" << instance->counter;
				const std::string tmp = ss.str();
				const char* propsname = tmp.c_str();
				if (Menu::MenuOption(propsname, propsnamesub)) { propsnameint = i; };
				i++;
			}
		}
			break;
#pragma endregion
#pragma region propsnamesub
		case propsnamesub:
		{
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Prop Options"_Secure);
			Menu::Toggle("Invincible?"_Secure, Features::invincprop1bool, [] { Features::invincprop1(propsnameint, Features::invincprop1bool); });
			Menu::Toggle("Immovable?"_Secure, Features::immoveprop1bool, [] { Features::immoveprop1(propsnameint, Features::immoveprop1bool); });
			Menu::Toggle("Has Gravity?"_Secure, Features::gravityprop1bool, [] { Features::gravityprop1(propsnameint, Features::gravityprop1bool); });
			Menu::Toggle("On Fire?"_Secure, Features::fireprop1bool, [] { Features::fireprop1(propsnameint, Features::fireprop1bool); });
			if (Menu::Option("Move this Prop"_Secure)) { Features::moveprop1(propsnameint); };
			if (Menu::Option("Delete this Prop"_Secure)) { Features::deleteprop1(propsnameint); };
			if (Menu::Option("Explode this Prop"_Secure)) { Features::explodeprop1(propsnameint); };
			if (Menu::Option("Reset Camera to Player"_Secure)) { CAM::DESTROY_ALL_CAMS(1); CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1); };
			DoASM();
		}
		break;
#pragma endregion
#pragma region propmoversub
		case propmoversub:
		{
			// draw menu
			GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("shopui_title_exec_vechupgrade", 0);
			GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("shopui_title_exec_vechupgrade");
			GRAPHICS::DRAW_SPRITE("shopui_title_exec_vechupgrade", "shopui_title_exec_vechupgrade", 0.8f, 0.1175f, 0.21f, 0.085f, 0.0f, 255, 255, 255, 225);
			Menu::Title("Object Placement"_Secure);
			std::stringstream ss;
			std::string pp_travel_speedStr;

			if (pp_travel_speed == 0)
				pp_travel_speedStr = "Slow";
			if (pp_travel_speed == 1)
				pp_travel_speedStr = "Fast";
			if (pp_travel_speed == 2)
				pp_travel_speedStr = "Very Fast";
			DoASM();
			Menu::Option("Default Object Placement Keys:");
			Menu::Option("Q/Z - Move Up/Down");
			Menu::Option("A/D - Rotate Left/Right");
			Menu::Option("W/S - Move Forward/Back");
			Menu::Option("Shift - Cycle Move Speeds");
			Menu::Option("T - Toggle Frozen Time");
			Menu::Option("G - Toggle Object Frozen On Exit");
			DoASM();
			Menu::Option(" ");
			Menu::Option("Default Controller Input:");
			Menu::Option("Triggers - Move Up/Down");
			Menu::Option("DPAD - Rotate, Move Forward/Back");
			Menu::Option("LB - Cycle Move Speeds");
			Menu::Option("LS - Toggle Frozen Time");
			Menu::Option("RS - Toggle Object Frozen On Exit");
			DoASM();
			Menu::Option("Press 'Menu Back' to save and exit this mode");
			Menu::Option(" ");

			ss << "Current Travel Speed: ~w~" << pp_travel_speedStr;
			Menu::Option((ss.str()).c_str());
			ss.str(""); ss.clear();

			ss << "Object Frozen On Exit: ~w~" << (currentProp->isImmovable ? "Yes" : "No");
			Menu::Option((ss.str()).c_str());
			ss.str(""); ss.clear();
		}
		break;
#pragma endregion
		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() 
{
	printf("Script Main \n");
	srand(time(0));
	main(); 
	Features::TimePD = timeGetTime();
	Features::TimePD1 = timeGetTime();
	Features::TimePD2 = timeGetTime();
	Features::TimePD3 = timeGetTime();
	Features::TimePD4 = timeGetTime();
	Features::TimePD5 = timeGetTime();
	Features::TimePD6 = timeGetTime(); 
	Features::TimePD7 = timeGetTime(); 
	Features::TimePD8 = timeGetTime();
	DoASM();
	DoASM();
	DoASM();
	DoASM();
	Detour::morphModule();
	DoASM();
	}