#pragma once
#include "stdafx.h"
#include <Tlhelp32.h>


//============
// STATS
//============

void SET_STAT_i(char *stat, int value, bool save);

void SET_STAT_b(char *stat, int value, bool save);

void SET_STAT_f(char *stat, float value, bool save);



//=================
// PED FUNCTIONS
//=================

Ped ClonePed(Ped ped);
Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);

//Animations
void LoadAnim(char * dict);
void playAnimation(Ped ped, bool loop, char * dict, char * anim);

//SKINS
bool applyChosenSkin123(std::string skinName);

//GOD MODE
void GodMode(bool toggle);

//CONTROL
void RequestControlOfEnt(Entity entity);

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z);

//CALM PEDS
void set_all_nearby_peds_to_calm();

//NEARBY PEDS
std::set<Ped> getNearbyPeds();
void update_nearby_peds(Ped playerPed, int count);

//VEHICLE
bool get_vehicle_keyboard_result(uint* outModel);

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str);

//Converts Radians to Degrees
float degToRad(float degs);

//quick function to get-coords-of-entity:
Vector3 coordsOf(Entity entity);

//quick function to get distance between 2 points:
float distanceBetween(Vector3 A, Vector3 B);

//quick "get random int in range 0-x" function:
int rndInt(int start, int end);

//TELEPORTATION
Vector3 get_blip_marker();
void teleport_to_coords(Entity e, Vector3 coords);

//KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text);

//VECTOR/FLOAT
Vector3 rot_to_direction(Vector3*rot);
Vector3 add(Vector3*vectorA, Vector3*vectorB);
Vector3 sub(Vector3 vectorA, Vector3 vectorB);
Vector3 multiply(Vector3*vector, float x);
float get_distance(Vector3*pointA, Vector3*pointB);
float get_vector_length(Vector3*vector);

//NOTIFICATION
void notifyBottom(char * fmt, ...);
void notifyBottom(std::string str);
void notifyMap(const char * fmt, ...); 
void notifyMap(char * fmt, ...);
void update_status_text();

//UTILITY
static CReplayInterface* m_replayIntf;
Vector3 get_coords_infront_player(float dist);
bool spawn_object(Hash model, Object* objOut);
void update_nearby_ped(bool alive = true, queue_int* out = &CHack::m_nearbyPed);
void update_nearby_vehicle(bool driveable = true, queue_int* out = &CHack::m_nearbyVehicle);
float get_dist_bet(Vector3 vec1, Vector3 vec2);
void trigger_script_event(eScriptEvent id, Player player, uint64_t arg2 = 0, uint64_t arg3 = 0);

void func_12(int uParam0 = 0, int iParam1 = 0);

uintptr_t get_address_of_item_in_pool(MemoryPool* pool, int handle);

template <typename rT>
rT*	handle_to_ptr(int handle)
{
	uintptr_t ptr = get_address_of_item_in_pool(*Hooking::m_entityPool, handle);
	return *reinterpret_cast<rT**>(ptr + 8);
}

void teleport_player_on_foot(Ped ped, float X, float Y, float Z);
void attach_entities(Entity e, Entity t, int bone, Vector3 pos, Vector3 rot, Hash object = 0xe6cb661e);

void Write2File(std::string filename, std::string content);

struct CPlayer
{
	bool		m_active;
	int			m_pedId,
				m_teamId;
	CPed*		m_pCPed;
};

class CPlayerMem
{
public:
	static void		update_players();

	static Player	player_id();
	static Ped		player_ped_id();
	static Ped		get_player_ped(Player player);
	static int		get_player_team(Player player);
	static CPed*	get_player_cped(Player player);
	static bool		is_player_in_any_vehicle(Player player);
	static Vector3		get_player_coords(Player player);
	static float	get_player_health(Player player);
	static float	get_player_max_health(Player player);
	static float	get_player_armour(Player player);
	static bool		is_player_god(Player player);
	static int		get_player_from_ped(Ped ped);
private:
	CPlayerMem() {};
	~CPlayerMem() {};

	static bool		is_player_valid(Player player);

	static int				m_localPlayerId;
	static CPlayer			m_player[0x20];		//player buffer
};

bool setPlayerName(std::string& name);

int GetPlayerNetworkHandle(Player player);

void VehicleGodmode(bool toggle);

void Set_VehicleHealth1(float value);

void Set_VehicleHealth2(float value);

void Set_VehicleBoost(float value);

void Set_VehicleAcceleration(float value);

void Set_VehicleBrakeForce(float value);

void Set_VehicleHandBrakeForce(float value);

void Set_VehicleDeformMultiplier(float value);

void Set_VehicleDirtLevel(float value);

void Set_VehicleGravity(float value);

void Set_VehicleRocketFuelLevel(float value);

void Set_VehicleRocketRechargeSpeed(float value);

void Set_VehicleSuspensionForce(float value);

void Set_VehicleSuspensionHeight(float value);

void Set_VehicleTractionCurve(float value);

void Set_VehicleDamageCurveMultiplier(float value);

float Get_VehicleHealth1();

float Get_VehicleHealth2();

float Get_VehicleBoost();

float Get_VehicleAcceleration();

float Get_VehicleBrakeForce();

float Get_VehicleHandBrakeForce();

float Get_VehicleDeformMultiplier();

float Get_VehicleDirtLevel();

float Get_VehicleGravity();

float Get_VehicleRocketFuelLevel();

float Get_VehicleRocketRechargeSpeed();

float Get_VehicleSuspensionForce();

float Get_VehicleSuspensionHeight();

float Get_VehicleTractionCurve();

float Get_VehicleDamageCurveMultiplier();

void Set_BulletDamage(float amount);

void Set_BulletMass(float amount);

void Set_MuzzleFlashSize(float amount);

void Set_MuzzleVelocity(float amount);

void Set_ReloadSpeed(float amount);

void Set_WeaponSpread(float amount);

void Set_WeaponRecoil(float amount);

void Set_Recoil(float amount);

void Set_Spread(float amount);

void Set_MeleeDamageMultiplier(float amount);

void Set_DamageMultiplier(float amount);

float Get_BulletDamage();

float Get_BulletMass1();

float Get_BulletMass2();

float Get_MuzzleFlashSize();

float Get_MuzzleVelocity();

float Get_ReloadSpeed();

float Get_WeaponSpread();

float Get_WeaponRecoil();

float Get_Recoil();

float Get_Spread();

float Get_MeleeDamageMultiplier();

float Get_DamageMultiplier();

void Set_Stamina(float amount);

void Set_SprintSpeed(float amount);

void Set_SwimSpeed(float amount);

float Get_Stamina();

float Get_SprintSpeed();

float Get_SwimSpeed();


std::wstring str_to_wstr(const std::string& string);
std::string wstr_to_str(const std::wstring& wstring);

const std::string	GetRunningExecutableFolder();
const std::string	GetOurModuleFolder();
const std::string	GetModuleName(const HMODULE module);
const std::string	GetModuleNameWithoutExtension(const HMODULE module);

void				SetOurModuleHanlde(const HMODULE module);
const HMODULE		GetOurModuleHandle();

bool fileExists(const char* name);

void create_thread(LPTHREAD_START_ROUTINE thread);

void killProcessByName(const char *filename);

template <typename Container, typename Element>
bool DoesVectorContain(const Container& container, const Element& element)
{
	return std::find(std::begin(container), std::end(container), element) != std::end(container);
}

constexpr unsigned char ToLowerLookupTable[256] =
{
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x2F, 0x5D, 0x5E, 0x5F,
0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
};

constexpr std::uint32_t joaatc(const char* string, std::size_t length)
{
	std::uint32_t hash = 0;

	for (std::size_t i = 0; i < length; ++i)
	{
		hash = static_cast<std::uint64_t>(hash) + ToLowerLookupTable[string[i]];
		hash = static_cast<std::uint64_t>(hash) + (hash << 10);
		hash = static_cast<std::uint64_t>(hash) ^ (hash >> 6);
	}

	hash = static_cast<std::uint64_t>(hash) + (hash << 3);
	hash = static_cast<std::uint64_t>(hash) ^ (hash >> 11);
	hash = static_cast<std::uint64_t>(hash) + (hash << 15);

	return hash;
}

std::uint32_t joaat(const char* string);
std::uint32_t joaat(const std::string& string);


constexpr std::uint32_t operator""_joaat(const char* string, std::size_t length)
{
	return joaatc(string, length);
}