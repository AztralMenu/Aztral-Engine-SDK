#include "stdafx.h"
std::set<Ped> lastSeenPeds;


//============
// STATS
//============

void SET_STAT_i(char *stat, int value, bool save) {
	if (UI::_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY(stat), value, save);
	else {
		char sbuf[50];
		int stat_r;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
		snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY(sbuf), value, save);
	}
}

void SET_STAT_b(char *stat, int value, bool save) {
	if (UI::_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY(stat), value, save);
	else {
		char sbuf[50];
		int stat_r;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
		snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
		STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY(sbuf), value, save);
	}
}

void SET_STAT_f(char *stat, float value, bool save) {
	if (UI::_GET_TEXT_SUBSTRING(stat, 0, 5) == "MPPLY")
		STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY(stat), value, save);
	else {
		char sbuf[50];
		int stat_r;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &stat_r, 1);
		snprintf(sbuf, sizeof(sbuf), "MP%i_%s", stat_r, stat);
		STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY(sbuf), value, save);
	}
}

//=================
// PED FUNCTIONS
//=================

Ped ClonePed(Ped ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && !ENTITY::IS_ENTITY_DEAD(ped))
		return PED::CLONE_PED(ped, ENTITY::GET_ENTITY_HEADING(ped), 1, 1);

	return 0;
}

Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle)
{
	Ped NewPed;
	int PedHash = $(PedName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(PedHash))
	{
		if (STREAMING::IS_MODEL_VALID(PedHash))
		{
			STREAMING::REQUEST_MODEL(PedHash);
			while (!STREAMING::HAS_MODEL_LOADED(PedHash)) WAIT(0);

			NewPed = PED::CREATE_PED(ped_type, PedHash, SpawnCoordinates.x, SpawnCoordinates.y, SpawnCoordinates.z, 0, network_handle, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedHash);
			return NewPed;
		}
	}

	return -1;
}





//Animations
void LoadAnim(char * dict)
{
	int tick = 0;
	STREAMING::REQUEST_ANIM_DICT(dict);
	while (tick < 100 && !STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		tick++;
		WAIT(0);
	}
}

void playAnimation(Ped ped, bool loop, char * dict, char * anim)
{
	LoadAnim(dict);
	int a = -1;
	int b = 1;

	if (!loop)
	{
		a = 1;
		b = 0;
	}

	AI::TASK_PLAY_ANIM(ped, dict, anim, 10000.0f, -1.5f, a, b, 0.445f, false, false, false);
}

//Skins
bool applyChosenSkin123(DWORD model)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
			WAIT(0);

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0))
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));

		PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), model);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		WAIT(0);

		if (veh != NULL)
			PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, -1);

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return true;
	}

	return false;
}

bool applyChosenSkin123(std::string skinName)
{
	DWORD model = $((char *)skinName.c_str());
	return applyChosenSkin123(model);
}
//GOD MODE
/*void GodMode(bool toggle)
{
	static int armour_player = 0;
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (armour_player == 0)
		armour_player = PED::GET_PED_ARMOUR(playerPed);

	if (Features::Godmodebool == true)
	{
		PLAYER::SET_PLAYER_INVINCIBLE(player, true);
		ENTITY::SET_ENTITY_PROOFS(playerPed, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE);
		PED::SET_PED_CAN_RAGDOLL(playerPed, FALSE);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, FALSE);
		PED::ADD_ARMOUR_TO_PED(playerPed, PLAYER::GET_PLAYER_MAX_ARMOUR(player) - PED::GET_PED_ARMOUR(playerPed));
	}
	else
	{
		PLAYER::SET_PLAYER_INVINCIBLE(player, false);
		ENTITY::SET_ENTITY_PROOFS(playerPed, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
		PED::SET_PED_CAN_RAGDOLL(playerPed, TRUE);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, TRUE);
		if (armour_player != 0)
		{
			PED::SET_PED_ARMOUR(playerPed, armour_player);
			armour_player = 0;
		}
	}
}*/
//CONTROL
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED()) 
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
		RequestControlOfEnt(e);

	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
}
//NEARBY PEDS
std::set<Ped> getNearbyPeds()
{
	return lastSeenPeds;
}

void update_nearby_peds(Ped playerPed, int count)
{
	const int numElements = count;
	const int arrSize = numElements * 2 + 2;

	Ped *peds = new Ped[arrSize];
	peds[0] = numElements;
	int found = PED::GET_PED_NEARBY_PEDS(playerPed, peds, -1);

	for (int i = 0; i < found; i++)
	{
		int offsettedID = i * 2 + 2;

		if (!ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]))
			continue;

		Ped xped = peds[offsettedID];

		bool inSet = lastSeenPeds.find(xped) != lastSeenPeds.end();
		if (!inSet)
			lastSeenPeds.insert(xped);
	}

	std::set<Ped>::iterator it;
	for (it = lastSeenPeds.begin(); it != lastSeenPeds.end();)
	{
		if (!ENTITY::DOES_ENTITY_EXIST(*it))
			lastSeenPeds.erase(it++);
		else
			++it;
	}

	delete peds;
}

//CALM PEDS
void set_all_nearby_peds_to_calm()
{
	for each (Ped xped in lastSeenPeds)
	{
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(xped, true);
		PED::SET_PED_FLEE_ATTRIBUTES(xped, 0, 0);
		PED::SET_PED_COMBAT_ATTRIBUTES(xped, 17, 1);
	}
}

//Converts Radians to Degrees
float degToRad(float degs)
{
	return degs*3.141592653589793f / 180.f;
}

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str) {
	return GAMEPLAY::GET_HASH_KEY(&str[0u]);
}

// quick function to get - coords - of - entity:
Vector3 coordsOf(Entity entity) {
	return ENTITY::GET_ENTITY_COORDS(entity, 1);
}

//quick function to get distance between 2 points: eg - if (distanceBetween(coordsOf(player), targetCoords) < 50)
float distanceBetween(Vector3 A, Vector3 B) {
	return GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

//quick "get random int in range 0-x" function:
int rndInt(int start, int end) 
{
	return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(start, end);
}

//TELEPORTATION
void teleport_to_coords(Entity e, Vector3 coords)
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
	WAIT(0);
}

Vector3 get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}

	if (blipFound)
		return coords;

	return zero;
}
//In Game KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text)
{
	DWORD time = GetTickCount() + 400;
	while (GetTickCount() < time)
		WAIT(0);

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, (title_id == NULL ? "HUD_TITLE" : title_id), "", (prepopulated_text == NULL ? "" : prepopulated_text), "", "", "", 64);

	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
		WAIT(0);

	std::stringstream ss;
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())
		return std::string("");
	else
		return std::string(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}

//VEHICLE
static std::string lastvehmodel("");
bool get_vehicle_keyboard_result(uint* outModel)
{
	std::string result = show_keyboard("FMMC_KEY_TIP", &lastvehmodel[0]);
	if (!result.empty())
	{
		uint model = $(result);
		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model) || !STREAMING::IS_MODEL_A_VEHICLE(model))
		{
			lastvehmodel = "";
			notifyBottom("~HUD_COLOUR_RED~Not A Valid Model!");
			return false;
		}

		else
		{
			STREAMING::REQUEST_MODEL(model);
			DWORD now = GetTickCount();
			while (!STREAMING::HAS_MODEL_LOADED(model) && GetTickCount() < now + 5000)
				WAIT(0);

			if (!STREAMING::HAS_MODEL_LOADED(model))
			{
				lastvehmodel = "";
				std::ostringstream ss2;
				ss2 << "~HUD_COLOUR_RED~ Timed out requesting  " << result << " : 0x" << model;
				notifyBottom(ss2.str());
				return false;
			}

			lastvehmodel = result;
			*outModel = model;
			return true;
		}

	}

	return false;
}

//VECTOR AND FLOAT FUNCTIONS
Vector3 rot_to_direction(Vector3*rot) {
	float radiansZ = rot->z*0.0174532924f;
	float radiansX = rot->x*0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ)))*(double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ))*(double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

Vector3 add(Vector3*vectorA, Vector3*vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 sub(Vector3 vectorA, Vector3 vectorB) {
	Vector3 result;
	result.x = vectorA.x;
	result.y = vectorA.y;
	result.z = vectorA.z;
	result.x -= vectorB.x;
	result.y -= vectorB.y;
	result.z -= vectorB.z;
	return result;
}

Vector3 multiply(Vector3*vector, float x) {
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float get_distance(Vector3*pointA, Vector3*pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba*y_ba;
	double x_2 = x_ba*x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float get_vector_length(Vector3*vector) {
	double x = (double)vector->x;
	double y = (double)vector->y;
	double z = (double)vector->z;
	return(float)sqrt(x*x + y*y + z*z);
}

//NOTIFICATIONS
/*
Colors:
~r~ = Red
~b~ = Blue
~g~ = Green
~y~ = Yellow
~p~ = Purple
~o~ = Orange
~c~ = Grey
~m~ = Dark Grey
~u~ = Black
~n~ = Skip Line
~s~ = White
~d~ = dark blue
~f~ = light blue
~l~ = black
~t~ = gray
~v~ = black

Fonts:
~italic~ = italic font
~bold~ = bold font
*/

char status_text[2048] = { 0 };
void update_status_text()
{
	if (GetTickCount() < 2500)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_SCALE(0.55f, 0.55f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_CENTRE(1);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(status_text);
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0.5, 0.5);
	}
}

void notifyBottom(char * fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::END_TEXT_COMMAND_PRINT(4000, 1);
}	void notifyBottom(std::string str) { notifyBottom(&str[0]); }

void notifyMap(const char * fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}


/*
UTILITY
*/

Vector3 get_coords_infront_player(float dist)
{
	Vector3 r = CPlayerMem::get_player_coords(CPlayerMem::player_id());
	float	heading = ENTITY::GET_ENTITY_HEADING(CPlayerMem::player_ped_id());
	r.x += dist * sin(degToRad(heading)) * -1,
		r.y += dist * cos(degToRad(heading));
	return r;
}

bool spawn_object(Hash model, Object* objOut)
{
	Vector3 pos = get_coords_infront_player(10.f);
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	if (!Hooking::is_model_in_cdimage(model))
		return true;
	Hooking::request_model(model);
	if (!Hooking::has_model_loaded(model))
		return false;
	
	Object obj = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, true, false, false);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

	if (objOut != nullptr)
		*objOut = obj;
	return true;
}

void update_nearby_ped(bool alive, queue_int* out)
{
	Ped localPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	CReplayInterface* replay = m_replayIntf;
	CPedInterface*	pedIF = replay->pCPedInterface;
	int	numPed = pedIF->iMaxPeds;
	for (int i = 0; i < numPed; ++i)
	{
		CPed* pPed = pedIF->get_ped(i);
		if (pPed == nullptr || (alive && pPed->fHealth < .001f))
			continue;
		Ped ped = Hooking::ptr_to_handle(pPed);
		if (ped == localPed)
			continue;
		out->push(ped);
	}
}

void update_nearby_vehicle(bool driveable, queue_int* out)
{
	CReplayInterface* replay = m_replayIntf;
	CVehicleInterface*	vehIF = replay->pCVehicleInterface;
	int							numVeh = vehIF->iMaxVehicles;
	for (int i = 0; i < numVeh; ++i)
	{
		CVehicle* pVeh = vehIF->get_vehicle(i);
		if (pVeh == nullptr || (driveable && pVeh->isVehicleDestroyed()))
			continue;
		Vehicle veh = Hooking::ptr_to_handle(pVeh);
		if (veh == PLAYER::GET_PLAYERS_LAST_VEHICLE())
			continue;
		out->push(veh);
	}
}

float get_dist_bet(Vector3 vec1, Vector3 vec2)
{
	float dist = GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z, TRUE);
	return dist;
}

void trigger_script_event(eScriptEvent id, Player player, uint64_t arg2, uint64_t arg3)
{
	if (!Hooking::network_is_session_started())
		return;
	constexpr BYTE	c = 4;
	int32_t			flags = (1 << player);
	uint64_t		args[c] = { id, (uint64_t)player, arg2, arg3 };
	Hooking::trigger_script_event(true, args, c, flags);
}

/*void func_12(int uParam0, int iParam1)
{
	auto ptr = reinterpret_cast<char*>(globalHandle(36886));
	strcpy_s(ptr, 16, "DRUNK");
	ptr[15] = '\0';
	Write2File("DEBUG.txt", ptr);
}*/

uintptr_t get_address_of_item_in_pool(MemoryPool* pool, int handle)
{
	if (pool == nullptr)
		return 0;

	int index = handle >> 8;
	int flag = pool->BoolAdr[index];

	if (flag & 0x80 || flag != (handle & 0xFF))
		return 0;

	return pool->ListAddr + index * pool->ItemSize;
}

void teleport_player_on_foot(Ped ped, float X, float Y, float Z)
{
	Hooking::clear_ped_tasks_immediately(ped);
	Vector3_t	remotePos = { X, Y, Z };
	Vector3_t cam = { 0 };
	int	scene = Hooking::network_create_synchronised_scene(&remotePos, &cam, 2, 0, 0, 0, 0.f, 0.f);
	Hooking::network_add_ped_to_synchronised_scene(ped, scene, "mini@strip_club@private_dance@part3", "priv_dance_p3", 8.0f, -8.0, 5, 0, 30, 0, 0);
	Hooking::network_start_synchronised_scene(scene);
}

void attach_entities(Entity e, Entity t, int bone, Vector3 pos, Vector3 rot, Hash object)//0xe6cb661e
{
	if (bone != -1 && pos.y == -.26f)
		pos.y = 0.f;
	bone == -1 ? bone = 0 : bone = PED::GET_PED_BONE_INDEX(t, bone);
	Vector3	pos2 = get_coords_infront_player(6.f);
	Vector3 empty = { 0 };
	RequestControlOfEnt(e);
	RequestControlOfEnt(t);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(e, t, 0, empty.x, empty.y, empty.z, empty.x, empty.y, empty.z, false, false, true, 2, true, false);
	ENTITY::PROCESS_ENTITY_ATTACHMENTS(t);
}

int mov;
int instructCount;

void instructionalSetup()
{
	instructCount = 0;
	mov = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(mov, 255, 255, 255, 0, 0);
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(mov, "CLEAR_ALL");
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(mov, "SET_CLEAR_SPACE");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(200);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}
void addInstructional(char *text, int button)
{
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(mov, "SET_DATA_SLOT");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(instructCount);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(button);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_HELP(text);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	instructCount++;
}
void instructionalClose()
{
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(mov, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(mov, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(0);
	GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(80);
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
}


void Write2File(std::string filename, std::string content)
{
	wchar_t path[MAX_PATH];
	char target[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result == S_OK)
	{
		std::string coords = content + "\n";
		wcstombs(target, path, MAX_PATH);
		std::string path = "\\AztralFiles\\" + filename;
		strcat(target, path.c_str());
		std::ofstream file(target, std::ios::app);
		file << coords << "\n";
	}
}


/*
//CPlayerMem private
*/
int			CPlayerMem::m_localPlayerId;
CPlayer		CPlayerMem::m_player[0x20];		//player buffer

bool CPlayerMem::is_player_valid(Player player)
{
	bool r = false;
	if (player >= 0 && player < 0x20)
		r = m_player[player].m_active;
	return r;
}

/*
//CPlayerMem public
*/
void CPlayerMem::update_players()
{
	m_localPlayerId = PLAYER::PLAYER_ID();
	for (int i = 0; i < 32; i++)
	{
		Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (ped <= 0)
		{
			m_player[i].m_active = false;
			continue;
		}
		m_player[i].m_active = true;
		m_player[i].m_pedId = ped;
		m_player[i].m_teamId = PLAYER::GET_PLAYER_TEAM(i);
		m_player[i].m_pCPed = handle_to_ptr<CPed>(ped);
	}
}

Player CPlayerMem::player_id()
{
	return m_localPlayerId;
}

Player CPlayerMem::player_ped_id()
{
	return m_player[m_localPlayerId].m_pedId;
}

Ped CPlayerMem::get_player_ped(Player player)
{
	Ped	r = 0;
	if (is_player_valid(player))
		r = m_player[player].m_pedId;
	return r;
}

int CPlayerMem::get_player_team(Player player)
{
	int	r = -1;
	if (is_player_valid(player))
		r = m_player[player].m_teamId;
	return r;
}

CPed* CPlayerMem::get_player_cped(Player player)
{
	CPed*	r = nullptr;
	if (is_player_valid(player))
		r = m_player[player].m_pCPed;
	return r;
}

bool CPlayerMem::is_player_in_any_vehicle(Player player)
{
	bool	r = false;
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr)
		r = m_player[player].m_pCPed->isInVehicle();
	return r;
}

Vector3 CPlayerMem::get_player_coords(Player player)
{
	Vector3	r = { 0, 0, 0 };
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr && m_player[player].m_pCPed->pCNavigation != nullptr)
		r = m_player[player].m_pCPed->pCNavigation->v3Pos;
	return r;
}

float CPlayerMem::get_player_health(Player player)
{
	float	r = 0.f;
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr)
		r = m_player[player].m_pCPed->fHealth;
	return r;
}

float CPlayerMem::get_player_max_health(Player player)
{
	float	r = 0.f;
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr)
		r = m_player[player].m_pCPed->fHealthMax;
	return r;
}

float CPlayerMem::get_player_armour(Player player)
{
	float	r = 0.f;
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr)
		r = m_player[player].m_pCPed->fArmor;
	return r;
}

bool CPlayerMem::is_player_god(Player player)
{
	bool	r = false;
	if (is_player_valid(player) && m_player[player].m_pCPed != nullptr)
		r = m_player[player].m_pCPed->isGod();
	return r;
}

int CPlayerMem::get_player_from_ped(Ped ped)
{
	int	r = -1;
	for (int i = 0; i < 32; ++i)
	{
		if (!is_player_valid(i) || m_player[i].m_pedId != ped)
			continue;
		r = i;
		break;
	}
	return r;
}


bool setPlayerName(std::string& name)
{
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return false;

	char	buffer[0x20] = {};
	char*	pSearch = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()) + 0x5C;
	size_t	curLen = strlen(pSearch) + 1;

	strncpy_s(buffer, pSearch, curLen);

	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;

		if (++match < curLen)
		{
			++i;
			continue;
		}

		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;

	LABEL_RESET:
		i = match = 0;
	}	

	char* onlineName = Memory::get_value<char*>({ 0x23D1C48 , 0x7C , 0x10B8 , 0x8 });

	Write2File("DEBUG.txt", onlineName);

	stringstream ss;

	ss << name;

	char* newName;

	ss >> newName;

	Memory::set_value<char*>({ 0x23D1C48 , 0x7C , 0x10B8 , 0x8 }, newName);

	onlineName = Memory::get_value<char*>({ 0x23D1C48 , 0x7C , 0x10B8 , 0x8 });

	Write2File("DEBUG.txt", onlineName);
	
	return true;
}


int GetPlayerNetworkHandle(Player player) 
{
	const int size = 13;
	uint64_t *buffer = std::make_unique<uint64_t[]>(size).get();
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, reinterpret_cast<int *>(buffer), 13);
	for (int i = 0; i < size; i++) 
	{
		Log::Msg("networkhandle[%i]: %llx", i, buffer[i]);
	}
	std::vector<int> result(buffer, buffer + sizeof(buffer));
	return result.at(0);
}


void VehicleGodmode(bool toggle)
{
	if (toggle)
	{
		BYTE Setter = 1;
		Memory::set_value<bool>({ 0x08, 0xD28, 0x189 }, Setter);
	}
	else
	{
		BYTE Setter = 0;
		Memory::set_value<bool>({ 0x08, 0xD28, 0x189 }, Setter);
	}
}

void Set_VehicleHealth1(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x280 }, value);
	}
}

void Set_VehicleHealth2(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x89C }, value);
	}
}

void Set_VehicleBoost(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x320 }, value);
	}
}

void Set_VehicleAcceleration(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0x4C }, value);
	}
}

void Set_VehicleBrakeForce(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0x6C }, value);
	}
}

void Set_VehicleHandBrakeForce(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0x7C }, value);
	}
}

void Set_VehicleDeformMultiplier(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0xF8 }, value);
	}
}

void Set_VehicleDirtLevel(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0xF8 }, value);
	}
}

void Set_VehicleGravity(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0xBCC }, value);
	}
}

void Set_VehicleRocketFuelLevel(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x322 }, value);
	}
}

void Set_VehicleRocketRechargeSpeed(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x324 }, value);
	}
}

void Set_VehicleSuspensionForce(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0xBC }, value);
	}
}

void Set_VehicleSuspensionHeight(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0xD0 }, value);
	}
}

void Set_VehicleTractionCurve(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0xD28, 0x8C8, 0x90 }, value);
	}
}

void Set_VehicleDamageCurveMultiplier(float value)
{
	if (true)
	{
		Memory::set_value<float>({ 0x08, 0x10B8, 0xC88 }, value);
	}
}

float Get_VehicleHealth1()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x280 });
	}
}

float Get_VehicleHealth2()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x89C });
	}
}

float Get_VehicleBoost()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x320 });
	}
}

float Get_VehicleAcceleration()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0x4C });
	}
}

float Get_VehicleBrakeForce()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0x6C });
	}
}

float Get_VehicleHandBrakeForce()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0x7C });
	}
}

float Get_VehicleDeformMultiplier()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0xF8 });
	}
}

float Get_VehicleDirtLevel()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0xF8 });
	}
}

float Get_VehicleGravity()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0xBCC });
	}
}

float Get_VehicleRocketFuelLevel()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x322 });
	}
}

float Get_VehicleRocketRechargeSpeed()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x324 });
	}
}

float Get_VehicleSuspensionForce()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0xBC });
	}
}

float Get_VehicleSuspensionHeight()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0xD0 });
	}
}

float Get_VehicleTractionCurve()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0xD28, 0x8C8, 0x90 });
	}
}

float Get_VehicleDamageCurveMultiplier()
{
	if (true)
	{
		return Memory::get_value<float>({ 0x08, 0x10B8, 0xC88 });
	}
}

void Set_BulletDamage(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0xB0 }, amount);
}

void Set_BulletMass(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0xD8 }, amount);
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0xDC }, amount);
}

void Set_MuzzleFlashSize(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x1D4 }, amount);
}

void Set_MuzzleVelocity(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x114 }, amount);
}

void Set_ReloadSpeed(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x12C }, amount);
}

void Set_WeaponSpread(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x74 }, amount);
}

void Set_WeaponRecoil(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x2D8 }, amount);
}

void Set_Recoil(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x2A4 }, amount);
}

void Set_Spread(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10C8, 0x20, 0x70 }, amount);
}

void Set_MeleeDamageMultiplier(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10B8, 0xC80 }, amount);
}

void Set_DamageMultiplier(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10B8, 0xC78 }, amount);
}

float Get_BulletDamage()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0xB0 });
}

float Get_BulletMass1()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0xD8 });
}

float Get_BulletMass2()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0xDC });
}

float Get_MuzzleFlashSize()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x1D4 });
}

float Get_MuzzleVelocity()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x114 });
}

float Get_ReloadSpeed()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x12C });
}

float Get_WeaponSpread()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x74 });
}

float Get_WeaponRecoil()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x2D8 });
}

float Get_Recoil()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x2A4 });
}

float Get_Spread()
{
	return Memory::get_value<float>({ 0x08, 0x10C8, 0x20, 0x70 });
}

float Get_MeleeDamageMultiplier()
{
	return Memory::get_value<float>({ 0x08, 0x10B8, 0xC80 });
}

float Get_DamageMultiplier()
{
	return Memory::get_value<float>({ 0x08, 0x10B8, 0xC78 });
}

void Set_Stamina(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10B8, 0xC60 }, amount);
}

void Set_SprintSpeed(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10B8, 0x14C }, amount);
}

void Set_SwimSpeed(float amount)
{
	Memory::set_value<float>({ 0x08, 0x10B8, 0x148 }, amount);
}

float Get_Stamina()
{
	return Memory::get_value<float>({ 0x08, 0x10B8, 0xC60 });
}

float Get_SprintSpeed()
{
	return Memory::get_value<float>({ 0x08, 0x10B8, 0x14C });
}

float Get_SwimSpeed()
{
	return Memory::get_value<float>({ 0x08, 0x10B8, 0x148 });
}

static HMODULE ourModule;



std::wstring str_to_wstr(const std::string& string)
{
	std::wstring wstring;

	return MultiByteToWideChar(CP_UTF8, 0, string.data(), static_cast<int>(string.size()), &wstring[0], (int)wstring.size()) ? wstring : std::wstring();
}

std::string wstr_to_str(const std::wstring& wstring)
{
	std::string string;

	return WideCharToMultiByte(CP_UTF8, 0, wstring.data(), static_cast<int>(wstring.size()), &string[0], static_cast<int>(string.size()), nullptr, nullptr) ? string : std::string();
}

const std::string GetRunningExecutableFolder() {

	char fileName[MAX_PATH];
	GetModuleFileNameA(NULL, fileName, MAX_PATH);

	std::string currentPath = fileName;
	return currentPath.substr(0, currentPath.find_last_of("\\"));
}

const std::string GetOurModuleFolder() {

	char fileName[MAX_PATH];
	GetModuleFileNameA(ourModule, fileName, MAX_PATH);

	std::string currentPath = fileName;
	return currentPath.substr(0, currentPath.find_last_of("\\"));
}

const std::string GetModuleName(const HMODULE module) {

	char fileName[MAX_PATH];
	GetModuleFileNameA(module, fileName, MAX_PATH);

	std::string fullPath = fileName;

	size_t lastIndex = fullPath.find_last_of("\\") + 1;
	return fullPath.substr(lastIndex, fullPath.length() - lastIndex);
}

const std::string GetModuleNameWithoutExtension(const HMODULE module) {

	const std::string fileNameWithExtension = GetModuleName(module);

	size_t lastIndex = fileNameWithExtension.find_last_of(".");
	if (lastIndex == -1) {
		return fileNameWithExtension;
	}

	return fileNameWithExtension.substr(0, lastIndex);
}

void SetOurModuleHanlde(const HMODULE module) {

	ourModule = module;
}

const HMODULE GetOurModuleHandle() {

	return ourModule;
}

bool fileExists(const char* name) {

	struct stat buffer;
	return (stat(name, &buffer) == 0);
}

void create_thread(LPTHREAD_START_ROUTINE thread)
{
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, thread, 0, 0, &myThreadID);
	CloseHandle(myHandle);
}

void killProcessByName(const char *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (wcscmp(pEntry.szExeFile, str_to_wstr(filename).c_str()) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
				(DWORD)pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
}

std::uint32_t joaat(const char* string)
{
	return joaatc(string, std::strlen(string));
}

std::uint32_t joaat(const std::string& string)
{
	return joaatc(string.c_str(), string.size());
}

