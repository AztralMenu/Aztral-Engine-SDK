#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include "Features.h"
#include "Global.h"

//#define PROP_MONEY_BAG_01 0x113FD533
//#define PROP_MONEY_BAG_02 -1666779307
//#define PICKUP_MONEY_CASE -1666779307

#define PROP_MONEY_BAG_01 0x113FD533
#define PROP_MONEY_BAG_02 -1666779307
#define PICKUP_MONEY_CASE 0x1E9A99F8
int grip = 1;
int down = 0;
Vehicle lastspawnedcar;

std::string input19 = "skgnwoighwofhwidqdlkfwnofo";
std::string hash19 = sw::sha512::calculate(input19);

const DWORD object_prop_money_hash[] =
{
	0x6b795ebc, 0x40f52369, 0x4b3d240f, 0xa9bd0d16, 0xe3ba450,	//"prop_alien_egg_01", "p_v_43_safe_s", "prop_wheelchair_01", "prop_coke_block_01", "prop_xmas_tree_int",
	0x5571173d, 0x6ad326c2, 0x456aa864, 0x58d3b4ea, 0xd541462d,	//"prop_beer_neon_01", "prop_space_rifle", "prop_dj_deck_01", "prop_micro_01", "p_ld_soc_ball_01", 
	0x532b1dd1, 0x7ffbc1e2, 0x5869a8f8, 0xe6cb661e, 0x927a5723,	//"prop_rub_trolley01a", "prop_dummy_01", "prop_large_gold", "prop_cs_dildo_01", "prop_fan_01",
	0x34d5d3fd, 0x2ae13dfa, 0x29cb0f3c, 0x922c2a43, 0xfa686c0e,	//"prop_golf_bag_01", "prop_armchair_01", "prop_armour_pickup", "prop_big_shit_01", "prop_bin_04a", 
	0x1f550c17, 0x5b5c4263, 0x39885bb5, 0x16a39a90, 0x1b6ed610,	//"prop_chair_01a", "prop_chip_fryer", "prop_chickencoop_a", "prop_dog_cage_01", "prop_coffin_02", 
	0x82bac591, 0x28cdf74c										//"prop_coffin_02b", "prop_cs_dumpster_01a"
};

void Features::UpdatePerTick() 
{

	
	MouseControlBool ? MouseControl(true) : NULL;

	if (rapidfirer)
	{
		rapidmaker();
	}
	if (superpunchbool)
	{
		superpunch();
	}

	CarWeaponLoopBool ? CarWeaponLoop(true) : NULL;

	expammo ? explosive_ammo(true) : NULL;

	cargodmodebool ? VehicleGodmode(true) : NULL;

	//cashdropbool ? cashdrop(true) : NULL;

	//bigcashdropbool ? bigcashdrop(true) : NULL;

	storycashdropbool ? storycashdrop(true) : NULL;

	storymodebool ? storymode(true) : NULL;

	//Pickupdropbool ? Pickupdrop(true) : NULL;

	neverwanted ? NeverGetWanted(true) : NULL;

	dowbool ? DriveOnWater(true) : NULL;

	fcbool ? FlyingCarLoop(true) : NULL;

	MoneyGunBool ? Moneygun(true) : NULL;

	BagGunBool ? Baggun(true) : NULL;

	Alieneggsbool ? Alieneggs(true) : NULL;

	goldgunbool ? goldgun(true) : NULL;

	Arcadegunbool ? Arcadegun(true) : NULL;

	Planeweaponbool ? Planeweapon(true) : NULL;

	Pedweaponbool ? Pedweapon(true) : NULL;

	fastrunbool ? fastrun(true) : NULL;

	RPLoop ? rpLoop(true) : NULL;
	
	boostbool ? carboost(true) : NULL;

	superboostbool ? supercarboost(true) : NULL;

	fuckhornlolbool ? fuckhornlol(true) : NULL;

	slomobool ? slomonig(true) : NULL;
	
	rbgun ? RBGuner(true) : NULL;
	
	stealthbool ? stealth(true) : NULL;

	stealth15bool ? Stealth15(true) : NULL; 

	stealth1bool ? stealth1(true) : NULL;

	stealth2bool ? stealth2(true) : NULL;

	stealth3bool ? stealth3(true) : NULL;

	lowerveh100bool ? lowerveh100(true) : NULL;

	lowerveh50bool ? lowerveh50(true) : NULL;

	Ghostmode ? ghostmode(true) : NULL;

	mobileRadio ? mobilevoid(true) : NULL;

	blockcallsbool ? blockcalls(true) : NULL;

	Superjump ? superjump(true) : NULL;

	rainbowmenu ? Rainbowmenu(true) : NULL;
	

	infammo ? noreloadv(true) : NULL;

	antimoneydrop ? MoneyDropBypass(true) : NULL; 

	antivotekickbool ? antivotekick(true) : NULL;

	nofallbool ? nofall(true) : NULL;

	antitp ? TPProtex(true) : NULL;

	OffTheRadarBool ? OffTheRadar(true) : NULL;

	antiremoveweptoggle ? RemoveWeaponProtex(true) : NULL;

	antiptfxtoggle ? PTFXProtex(true) : NULL;

	antifreeze ? FreezeProtex(true) : NULL;

	antiexplosion ? AntiFireExplosion(true) : NULL;

	antiblametoggle ? AntiBlame(true) : NULL;

	antiremotetoggle ? AntiRemote(true) : NULL;

	Nothrowshit ? NoRagdoll(true) : NULL;

	rlbool ? HasPaintLoop(true) : NULL;

	Superman ? superman(true) : NULL;

	Godmodebool ? Godmode(true) : NULL;

	SemiGodModebool ? SemiGodMode(true) : NULL;

	fatbitchesbool ? fatbitches(true) : NULL;

	angrypedsbool ? angrypeds(true) : NULL;

	magnetpedsbool ? magnetpeds(true) : NULL;

	magnetpedsbool1 ? magnetpeds1(true) : NULL;

	purgebool ? purge(true) : NULL;

	NoClipping ? NoClipme(true) : NULL;

	killpedsbool ? killpeds(true) : NULL;

	explodepedsbool ? explodepeds(true) : NULL;

	deletenearbyvehiclesbool ? deletenearbyvehicles(true) : NULL;

	explodenearbyvehiclesbool ? explodenearbyvehicles(true) : NULL;

	Upgradecarsbool ? Upgradecars(true) : NULL;

	Rainbowcarbool ? Rainbowcar(true) : NULL;
	
	ForceWavebool ? ForceWave(true) : NULL;

	//SelfDriveBool ? SelfDrive(true) : NULL;

	showcoordsbool ? showcoords(true) : NULL;

	torquebool ? torque(grip) : NULL;
	
	//maxspeedbool ? maxspeed(true) : NULL;
	
	downforcebool ? downforce(down) : NULL;

	showspeedbool ? showspeed(true) : NULL;
	
	showspeed1bool ? showspeed1(true) : NULL;

	enginealwaysonbool ? enginealwayson(true) : NULL;

	earrapebool ? earrape(true) : NULL;

	CheckConfigBool ? CheckConfig(true) : NULL;

	GravityGun ? GravityGunLoop(true) : NULL;
	
	RemoveObjects ? RemoveObjectsLoop(true) : NULL;

	CustomLightsbool ? CustomLights(true) : NULL;

	FireWheelsBool ? FireWheels(true) : NULL;

	black_hole_bool ? black_hole(true) : NULL;

	forcefieldbool ? forcefield(true) : NULL;

	attachobjectsCrashbool ? attachobjectsCrash(true) : NULL;

	if (PTFXBool) PTFXCALL();

	if (PTFXOBool) PTFXCALLO();



	for (int ix = 0; ix < 33; ix++)
	{
		if (freezed[ix])
		{
			Freezer(ix);
		}

		if (cashdrop2bool[ix])
		{
			cashdrop2(ix);
		}
		if (twofitybool[ix])
		{
			twofity(ix);
		}
		if (twofitybool1[ix])
		{
			twofity1(ix);
		}
		if (Features::ceomoneybool[32])
		{
			Features::ceomoney(ix);
		}
		/*if (cashdropbool[ix])
		{
			cashdrop(ix);
		}*/
		if (fakebagsbool[ix])
		{
			fakebags(ix);
		}
		if (cashdrop3bool)
		{
			cashdrop2(ix);
		}
		if (playerfireloop[ix])
		{
			FireLoop(ix);
		}
		if (playerwaterloop[ix])
		{
			WaterLoop(ix);
		}
		if (fuckedhandling[ix])
		{
			fuckhandling(ix);
		}
		if (esper)
		{
			esp(ix);
		}
		if (spectate[ix])
		{
			specter(ix);
		}
	}

	}



int Features::TimePD;
int Features::TimePD1;
int Features::TimePD2;
int Features::TimePD3;
int Features::TimePD4;
int Features::TimePD5;
int Features::TimePD6;
int Features::TimePD7;
int Features::TimePD8;
int Features::TimePD9;
int Features::delay = 1000;

bool Features::MouseControlBool = false;
void Features::MouseControl(bool toggle)
{
	if (toggle)
	{
		UI::_SHOW_CURSOR_THIS_FRAME();
		std::string cursorpos = "X:" + std::to_string(CONTROLS::GET_CONTROL_VALUE(0, ControlCursorX)) + "\nY:" + std::to_string(CONTROLS::GET_CONTROL_VALUE(0, ControlCursorY));
		//notifyBottom(cursorpos);
		Menu::getCursorMenu();
		CONTROLS::DISABLE_CONTROL_ACTION(INPUTGROUP_LOOK, ControlLookLeftRight, true);
		CONTROLS::DISABLE_CONTROL_ACTION(INPUTGROUP_LOOK, ControlLookUpDown, true);
	}
	else
	{
		CONTROLS::ENABLE_CONTROL_ACTION(INPUTGROUP_LOOK, ControlLookLeftRight, true);
		CONTROLS::ENABLE_CONTROL_ACTION(INPUTGROUP_LOOK, ControlLookUpDown, true);
	}
}



//Teleports
void Features::TPtoWaypoint()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		notifyMap("No Waypoint Set!", 0);
		return;
	}
	// get entity to teleport
	Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}
	// load needed map region and check height levels for ground existence
	bool groundFound = false;
	static float groundCheckHeight[] =
	{ 100.0, 150.0, 50.0, 0.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	// if ground not found then set Z in air and give player a parachute
	if (!groundFound)
	{
		coords.z = 1000.0;
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0xFBAB5776, 1, 0);
	}
	//do it
	teleport_to_coords(e, coords);
}
void Features::TPtoObjective()
{
	Vector3 coords;
	Entity e;
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	else
		e = playerPed;

	bool blipFound = false;

	if (ENTITY::IS_ENTITY_A_VEHICLE(e)) RequestControlOfEnt(e);
	for (int i = 0; i <= 1000; i++)
	{
		Blip_t* blip = Hooking::GetBlipList()->m_Blips[i];
		if (blip)
		{
			if ((blip->dwColor == ColorYellowMission && blip->iIcon == SpriteStandard) || (blip->dwColor == ColorYellow && blip->iIcon == SpriteStandard) ||
				(blip->dwColor == ColorWhite && blip->iIcon == SpriteRaceFinish) || (blip->dwColor == ColorGreen && blip->iIcon == SpriteStandard) || (blip->iIcon == SpriteCrateDrop)) {
				coords = blip->coords;
				blipFound = true;
				break; //During a race there's sometimes 2 yellow markers. We want the first one.
			}	
		}
	}

	blipFound ? teleport_to_coords(e, coords) : notifyMap("Objective not found!", 0);
}
//Online Player Options
bool Features::cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}

void Features::teleportallcoordsns(Vector3 target)
{
	//finish me
}
bool Features::givespawnmaxed = false;
void Features::spawn_vehicle_on_player(char* toSpawn) {

	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (Hooking::is_model_valid(model))
	{
		Hooking::request_model(model);
		while (!Hooking::has_model_loaded(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		//ENTITY::_SET_ENTITY_SOMETHING(veh, true);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Aztral");
		if (Features::givespawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
		}
	}
}
Vehicle Features::ramplayer(DWORD toSpawn)
{
	float offset;
	Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0.0, -10.0, 0.0);
	Hash model = toSpawn;
	if (Hooking::is_model_valid(model))
	{
		Vector3 dim1, dim2;
		GAMEPLAY::GET_MODEL_DIMENSIONS(model, &dim1, &dim2);

		offset = dim2.y * 1.6;

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
		float rot = (ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0)).z;

		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), pCoords.z, rot, 1, 1);
		NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		//ENTITY::_SET_ENTITY_SOMETHING(veh, true);
		return veh;
	}
}
void Features::spawn_vehicle2(char* toSpawn) {
	float forward = 5.f;
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float playerHeading = ENTITY::GET_ENTITY_HEADING(playerPed);

	float xVect = forward * sin(degToRad(playerHeading)) * -1.0f;
	float yVect = forward * cos(degToRad(playerHeading));

	DWORD model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (Hooking::is_model_in_cdimage(model) && Hooking::is_model_a_vehicle(model)) {
		Hooking::request_model(model);
		while (!Hooking::has_model_loaded(model)) WAIT(0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, playerPos.x, playerPos.y, playerPos.z, playerHeading, TRUE, TRUE);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return;
		PED::SET_PED_INTO_VEHICLE(playerPed, model, -1);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
/*bool Features::PTLoopedO[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::PTLopperO(Player target)
{

	if ((timeGetTime() - Features::TimePD6) > 500) // Time between drops
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET(call1o);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2o);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(nameo, PTLoopPed, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		Features::TimePD6 = timeGetTime();

	}
}*/
void Features::trapcage(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}
bool Features::esper = false;
void Features::esp(Player target)
{
	if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 0, 255, 239, 255);

		GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 255, 239, 255);

		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 0, 255, 239, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 0, 255, 239, 255);

		Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 0, 255, 239, 255);
	}
}

bool Features::spectate[32] = { false };
void Features::specter(Player target)
{
	if (Features::spectate[target] == true) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(Features::spectate[target], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
	}
	else if (Features::spectate[target] == false) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	}
}
bool Features::playerfireloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::FireLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 12, 5, true, 0, 0);
}
bool Features::dowbool = false;
void Features::DriveOnWater(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WATER::_SET_CURRENT_INTENSITY(height);
	if (WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			RequestControlOfEnt(container);
			ENTITY::_SET_ENTITY_COORDS_2(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
			if (pos.z < containerCoords.z) {
				if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
					ENTITY::_SET_ENTITY_COORDS_2(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else {
					RequestControlOfEnt(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
					ENTITY::_SET_ENTITY_COORDS_2(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else {
			Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
			Hooking::request_model(model);
			while (!Hooking::has_model_loaded(model)) WAIT(0);
			container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEnt(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::_SET_ENTITY_COORDS_2(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_CURRENT_INTENSITY();
		}
	}
}
bool Features::fcbool = false;
void Features::FlyingCarLoop(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0))
	{
		int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);

		if (IsKeyPressed(VK_LSHIFT) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRt) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Up
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, false, true);
		}

		if (IsKeyPressed(VK_LCONTROL) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLt) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Down
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, false, true);
		}

		if (IsKeyPressed(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRup) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Forward
		{
			//float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 5, 0, 0, 0, 0, 1, false, true, true, false, true);
		}

		if (IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRdown) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Backward
		{
			//float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, -5, 0, 0, 0, 0, 1, false, true, true, false, true);
		}

		if ((IsKeyPressed(VK_KEY_A)) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid)) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRleft) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Left
		{
			//Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			//Rot.z = Rot.z + 1.0;
			//ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, -5, 0, 0, 0, 0, 0, 1, false, true, true, false, true);
		}

		if ((IsKeyPressed(VK_KEY_D)) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid)) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRright) && Menu::Settings::controllerinput && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Right
		{
			//Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			//Rot.z = Rot.z - 1.0;
			//ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
			ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 5, 0, 0, 0, 0, 0, 1, false, true, true, false, true);
		}
	}
}
bool Features::playerwaterloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::WaterLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 13, 5, true, 0, 0);
}
bool Features::fuckedhandling[32] = { false };
void Features::fuckhandling(Player player)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	RequestControlOfEnt(veh);
	VEHICLE::SET_VEHICLE_STEER_BIAS(veh, Features::fuckedhandling[player] ? 1.0f : 0.0f);
}

bool Features::earrapebool = false;
void Features::earrape(bool toggle)
{
	Ped playerPedID = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPedID, 0);
	for (int i = 0; i <= 32; i++)
	{
		if (i != PLAYER::PLAYER_ID() && i != 32)
		{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		if (!ENTITY::DOES_ENTITY_EXIST(Handle)) continue;
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z + 15, 29, 999999.5f, false, true, 1.0f);
		}
	}
}




//Vehicle Options
bool Features::boostbool = false;
void Features::carboost(bool toggle) {
	if (IsKeyPressed(VK_KEY_E) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLs) && Menu::Settings::controllerinput)
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			//ENTITY::APPLY_FORCE_TO_ENTITY(Veh, 1, 0, 1, 0, 0, 0, 0, 1, true, true, true, false, true);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 45.f);
		}
	}
}

bool Features::superboostbool = false;
void Features::supercarboost(bool toggle) {
	if (IsKeyPressed(VK_KEY_E) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLs) && Menu::Settings::controllerinput)
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			//ENTITY::APPLY_FORCE_TO_ENTITY(Veh, 1, 0, 5, 0, 0, 0, 0, 1, true, true, true, false, true);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 72.f);
		}
	}
}
bool Features::SelfDriveBool = false;
void Features::SelfDrive(bool toggle)
{
	if (SelfDriveBool)
	{
		Vector3 coords = get_blip_marker();

		if (coords.x == 0 && coords.y == 0)
		{
			notifyMap("No Waypoint Set!", 0);
			return;
		}
		
		Entity playerped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle playerveh = PED::GET_VEHICLE_PED_IS_USING(playerped);

		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(playerped, playerveh, coords.x, coords.y, coords.z, 30.f, 1074529084, 10.f);
		PED::SET_DRIVER_ABILITY(playerped, 100.f);
	}
	else
	{
		Entity playerped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		AI::CLEAR_PED_TASKS_IMMEDIATELY(playerped);
		int vehID = PED::GET_VEHICLE_PED_IS_IN(playerped, 1);
		PED::SET_PED_INTO_VEHICLE(playerped, vehID, -1);
	}
}

void Features::delpeds()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) != peds[OffsetID])
		{
			PED::DELETE_PED(&peds[OffsetID]);
		}
	}
}

bool Features::ChauffeurBool = false;
void Features::Chauffeur(bool toggle)
{
	if (ChauffeurBool)
	{
		Vector3 coords = get_blip_marker();

		if (coords.x == 0 && coords.y == 0)
		{
			notifyMap("No Waypoint Set!", 0);
			return;
		}


		Entity playerped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle playerveh = PED::GET_VEHICLE_PED_IS_USING(playerped);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerped, 1);
		Hash pedm = GAMEPLAY::GET_HASH_KEY("S_M_M_HighSec_02");
		int vehID = PED::GET_VEHICLE_PED_IS_IN(playerped, 1);

		Hooking::request_model(pedm);

		while (!Hooking::has_model_loaded(pedm))
				WAIT(0);

		int my_group = PLAYER::GET_PLAYER_GROUP(playerped);
		Ped clone = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
		PED::SET_PED_AS_GROUP_LEADER(playerped, my_group);
		PED::SET_PED_AS_GROUP_MEMBER(clone, my_group);
		PED::SET_PED_NEVER_LEAVES_GROUP(clone, my_group);
		PED::SET_GROUP_FORMATION(my_group, 3);
		PED::SET_PED_MAX_HEALTH(clone, 5000);

		PED::SET_PED_INTO_VEHICLE(playerped, vehID, 0);
		PED::SET_PED_INTO_VEHICLE(clone, vehID, -1);

		WAIT(0);

		AI::TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(clone, playerveh, coords.x, coords.y, coords.z, 30.f, 1074529084, 10.f);
		PED::SET_DRIVER_ABILITY(clone, 100.f);
		
		
	}
	else
	{
		Entity playerped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped *peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(playerped, peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) != peds[OffsetID])
			{
				PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false);
			}
		}
		int vehID = PED::GET_VEHICLE_PED_IS_IN(playerped, 0);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(playerped);
		PED::SET_PED_INTO_VEHICLE(playerped, vehID, -1);
	}
}


bool Features::FireWheelsBool = false;
void Features::FireWheels(bool toggle)
{
	Vehicle playerveh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Ped player = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	int boneindex1 = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerveh, "hub_lr");
	int boneindex2 = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerveh, "hub_rr");
	int boneindexhead = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(player, "BONETAG_HEAD");

	
	if (FireWheelsBool == true)
	{
		Features::Godmodebool = true;
		Features::cargodmodebool = true;
		if (VEHICLE::GET_VEHICLE_CLASS(playerveh) != 8)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("core"))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2("ent_amb_beach_campfire", playerveh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex1, 1.0, false, false, false);
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2("ent_amb_beach_campfire", playerveh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex2, 1.0, false, false, false);
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_amb_beach_campfire", player, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindexhead, 1.0, false, false, false);
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
			}
			else
			{
				WAIT(0);
			}
		}
		else
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("core"))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2("ent_amb_beach_campfire", playerveh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex1, 1.0, false, false, false);
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
				GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_amb_beach_campfire", player, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindexhead, 1.0, false, false, false);
			}
			else
			{
				WAIT(0);
			}
		}
	}
	else
	{
		GRAPHICS::REMOVE_PARTICLE_FX_FROM_ENTITY(playerveh);
		GRAPHICS::REMOVE_PARTICLE_FX_FROM_ENTITY(player);
	}
}

bool Features::torquebool = true;
void Features::torque(int torque1)
{
	grip = torque1;
	if (torquebool)
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, grip);
	}
}

bool Features::maxspeedbool = false;
void Features::maxspeed(bool toggle)
{

	if (maxspeedbool)
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		ENTITY::SET_ENTITY_MAX_SPEED(veh, 10000.f);
	}
}

bool Features::downforcebool = true;
void Features::downforce(int down11)
{
	down = down11/100;
	down = 0 - down;
	if (downforcebool)
	{
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, down, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(veh, "wheel_lf"), true, true, true, false, true);
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, down, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(veh, "wheel_rf"), true, true, true, false, true);
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, down, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(veh, "wheel_lr"), true, true, true, false, true);
			ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, down, 0, 0, 0, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(veh, "wheel_rr"), true, true, true, false, true);
		}
	}
}

void Features::doAnimation(char* anim, char* animid) {
	int pPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
	}
}


char* Features::call1s = NULL;
char* Features::call2s = NULL;
char* Features::names = NULL;

char* Features::call1o = NULL;
char* Features::call2o = NULL;
char* Features::nameo = NULL;
Player Features::target = NULL;


bool Features::PTFXBool = false;
void Features::PTFXCALL() 
{
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0))
	{
		Ped playerped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		int boneindex = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerped, "BONETAG_PELVIS");
		if (PTFXBool == false)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
		}
		else
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
			else
			{
				WAIT(0);
			}
		}
	}
	else
	{
		Vehicle playerped = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		int boneindex = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerped, "bumper_r");
		if (PTFXBool == false)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
		}
		else
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
			else
			{
				WAIT(0);
			}
		}
	}
}
bool Features::PTFXOBool = false;
void Features::PTFXCALLO() 
{
	Ped user = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::target);
	if (!PED::IS_PED_IN_ANY_VEHICLE(user, 0))
	{
		Ped playerped = user;
		int boneindex = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerped, "BONETAG_PELVIS");
		if (PTFXBool == false)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1o);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1o))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2o);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::nameo, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
		}
		else
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1o);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1o))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2o);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::nameo, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
			else
			{
				WAIT(0);
			}
		}
	}
	else
	{
		Vehicle playerped = PED::GET_VEHICLE_PED_IS_USING(user);
		int boneindex = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(playerped, "bumper_r");
		if (PTFXBool == false)
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
		}
		else
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET(Features::call1s);
			if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(Features::call1s))
			{
				GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(Features::call2s);
				GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE_2(Features::names, playerped, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, boneindex, 1.0, false, false, false);
			}
			else
			{
				WAIT(0);
			}
		}
	}
}
bool Features::fuckhornlolbool = false;
void Features::fuckhornlol(bool toggle) {
	if (IsKeyPressed(VK_KEY_E) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLs) && Menu::Settings::controllerinput)
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			//ENTITY::APPLY_FORCE_TO_ENTITY(Veh, 1, 0, 30, 0, 0, 0, 0, 1, true, true, true, false, true);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 112.f);
		}
	}
}
bool Features::lowerveh100bool = false;
void Features::lowerveh100(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -0.8, 0, 0, 0, true, true, true, true, false, true);
	}
}

bool Features::cargodmodebool = false;
void Features::cargodmode(bool toggle)
{
	bool incar = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);

	if (incar)
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, incar);
		ENTITY::SET_ENTITY_PROOFS(vehicle, incar, incar, incar, incar, incar, incar, incar, incar);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, incar);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, incar);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !incar);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !incar);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !incar);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !incar);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !incar);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !incar);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !incar);
	}
	else
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, incar);
		ENTITY::SET_ENTITY_PROOFS(vehicle, incar, incar, incar, incar, incar, incar, incar, incar);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, incar);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, incar);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !incar);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !incar);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !incar);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !incar);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !incar);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !incar);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
	}
}

bool Features::lowerveh50bool = false;
void Features::lowerveh50(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -0.4, 0, 0, 0, true, true, true, true, false, true);
	}
}

bool Features::enginealwaysonbool = false;
void Features::enginealwayson(bool toggle)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
	VEHICLE::SET_VEHICLE_ENGINE_ON(veh, Features::enginealwaysonbool, Features::enginealwaysonbool, Features::enginealwaysonbool);
	VEHICLE::SET_VEHICLE_LIGHTS(veh, 0);
	//VEHICLE::_SET_VEHICLE_LIGHTS_MODE(veh, 2);
}

void Features::flipup()
{
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false));
}
void Features::maxvehicle()
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
	}
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Aztral");
}






bool Features::rlbool = false;
void Features::HasPaintLoop(bool toggle)
{
	if ((timeGetTime() - Features::TimePD5) > 100) // Time between drops
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0));
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		Features::TimePD5 = timeGetTime();
	}
}

bool Features::bulletprooftiresbool = false;
void Features::bulletprooftires()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !bulletprooftiresbool);
	}
}

bool Features::spawnincar = true;
bool Features::spawnmaxed = true;
void Features::spawn_vehicle(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (Hooking::is_model_valid(model))
	{
		Hooking::request_model(model);
		while (!Hooking::has_model_loaded(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		lastspawnedcar = veh;
		NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		//ENTITY::_SET_ENTITY_SOMETHING(veh, true);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Aztral");


		if (Features::spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, -1);
		}
		if (Features::spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
			}
		}
		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
/*bool Features::gunrunningbypassbool = false;
void Features::gunrunningbypass(bool toggle)
{
//removed for now :)
}*/

void Features::dirtycar()
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 12);
	}

}








//Recovery Options
void Features::deposit(long amount)
{
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("mpply_last_mp_char"), &iVar0, -1);
	UNK3::_NETWORK_TRANSFER_WALLET_TO_BANK(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}

void Features::withdraw(long amount)
{
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("mpply_last_mp_char"), &iVar0, -1);
	UNK3::_NETWORK_TRANSFER_BANK_TO_WALLET(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}
bool Features::Banked = false;

bool Features::ceomoneybool[32] = { false };
void Features::ceomoney(Player player)
{
	trigger_script_event(SCRIPTEVENT_SECURO_PAYMENT_SILENT, player, 50000);
}


bool Features::stealthbool = false;
void Features::stealth(bool toggle)
{
	if ((timeGetTime() - Features::TimePD4) > Features::delay && Features::riskymodebool == true)
	{
		int money = INT_MAX;
		int transactionID = money;
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, -1586170317, 1445302971, 14999999, 4))
			UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
	}
}


bool Features::riskymodebool = true;
void Features::riskymode(bool toggle)
{
	WAIT(0);
}

bool Features::stealth15bool = false;
void Features::Stealth15(bool toggle)
{
	if ((timeGetTime() - Features::TimePD4) > Features::delay && Features::riskymodebool == true)
	{
		int money = INT_MAX;
		int transactionID = money;
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, 312105838, 1445302971, 9999999, 4))
			UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
		//(&transactionID, 1474183246, remove ? -1359375127 : -1586170317, remove ? 537254313 : 1445302971, amount, 4)
	}
}


//Sell? -1172900789 Doesnt work

bool Features::stealth1bool = false;
void Features::stealth1(bool toggle)
{
	if ((timeGetTime() - Features::TimePD4) > Features::delay && Features::riskymodebool == true)
	{
		int money = INT_MAX;
		int transactionID = money;
		int cash = 1000000;
		int transactionCode = 1287308202;
			if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, transactionCode, 1445302971, cash, 4))
			{
				UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
			}
	}
}

//Bounty works
bool Features::stealth2bool = false;
void Features::stealth2(bool toggle)
{
	if ((timeGetTime() - Features::TimePD4) > Features::delay && Features::riskymodebool == true)
	{
		int money = INT_MAX;
		int transactionID = money;
		int transactionCode = -990286235;
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, transactionCode, 1445302971, 10000, 4))
			UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
	}
}


int transIDs[] = { 2209654107, -1645229221, -585718395, -1359375127, 454359403, -982394051, 1643659499, -2072289654, 650665123, 1654961868, -876847842, 68030260, -2122299283, 366672791, 283351220, 291576838, 1182673174, -516219046, 1036455748, 277665518, 2043854386, 1839532116, 1022400740, 1940862352, -1389227906, 711665950, 1704445500, 1515774909, 1173654533, -899802304, -663944335, 1208553146, -613221010, -671062876, -407201236, -754024203, -1885444887, 1931729587, 1064954035, -180141073, 2131324797, 1612072658, -517447402, 1948102096, 1108628223, -1834046564, -1239008812, -222363842, -1276678868, -31156877, 1718438689, -1027218631, -1398318418, 1652884147, -57868256, -1216489292, -46622315, -352356931, -990286235, 563463121, 1734805203, 941287179, -1186079845, -1985150258, -1127021384, -109201286, 312105838, 1982688246, -661030418, 1301046174 };
int transIDiterator = 0;

//Testing 
bool Features::stealth3bool = false;
void Features::stealth3(bool toggle)
{
	if ((timeGetTime() - Features::TimePD4) > Features::delay)
	{
		
		//-999939337
	
		int money = INT_MAX;
		int transactionID = money;
		int balancestart = NETWORKCASH::NETWORK_GET_VC_BALANCE();

		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&transactionID, 1474183246, transIDs[transIDiterator], 1445302971, 100000, 4))
		{
			UNK3::_NETWORK_SHOP_CHECKOUT_START(transactionID);
		}

		{
			string idlog = std::to_string(transIDs[transIDiterator]) + " : " + std::to_string(NETWORKCASH::NETWORK_GET_VC_BALANCE() - balancestart);
			Write2File("DEBUG.txt", idlog.c_str());
		}

		notifyBottom(std::to_string(transIDiterator));

		if (transIDiterator == 70)
			transIDiterator = 0;
		else
			transIDiterator++;
	}
}


void Features::MoneyEdit(int towallet, int tobank)
{ 
	int iVar2 = INT_MAX; 
	if (globalHandle(2599118).As<int>() == -1) 
	{ 
		globalHandle(2599118) = NETWORKCASH::NETWORK_GET_VC_BANK_BALANCE(); 
	} 
	if (globalHandle(2599119).As<int>() == -1) 
	{ 
		globalHandle(2599119) = NETWORKCASH::NETWORK_GET_VC_WALLET_BALANCE(-1); 
	} 
	towallet = 0; 
	tobank = 0; 
	if (globalHandle(2599118).Get<int>() > 0) 
	{ 
		if (globalHandle(2599118).Get<int>() >= &iVar2) 
		{ 
			tobank = iVar2; 
		} 
		else 
		{ 
			tobank = iVar2 - (iVar2 - globalHandle(2599118).As<int>()); 
		} 
		iVar2 -= tobank; 
	} 
	if (iVar2 > 0) 
	{ 
		if (globalHandle(2599119).Get<int>() > 0) 
		{ 
			if (globalHandle(2599119).Get<int>() >= &iVar2) 
			{
				towallet = iVar2; 
			} 
			else 
			{ 
				towallet = iVar2 - (iVar2 - globalHandle(2599119).As<int>());
			} 
			iVar2 -= towallet; 
		} 
	} 
	invoke<Void>(536737010038877744, towallet, tobank); 
	globalHandle(2599118) = towallet; 
	globalHandle(2599119) = tobank; 
}




bool Features::fakebagsbool[32] = { false };
void Features::fakebags(Player target)
{


	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

	int amount = -2500;

	if ((timeGetTime() - Features::TimePD5) > 200) // Time between drops
	{
		Hooking::request_model(PROP_MONEY_BAG_02);
		if (!Hooking::has_model_loaded(PROP_MONEY_BAG_02)) {
			WAIT(0);
		}
		else {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pos.x, pos.y, pos.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pos.x, pos.y, pos.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);

			Features::TimePD5 = timeGetTime();

		}
	}
}
bool Features::Banked2 = false;

bool Features::twofitybool[32] = { false };
void Features::twofity(Player target)
{


	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

	int amount = 2000;

	if ((timeGetTime() - Features::TimePD4) > 200) // Time between drops
	{
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
		OBJECT::_PED_DEATH_DROP(pos.x, pos.y, pos.z + 0.5f, amount, 1, PICKUP_MONEY_CASE);

		Features::TimePD4 = timeGetTime();
	}
}

int Pa = 0;
int Pb = 1;
int Pc = 2;
int Pd = 3;
int Pe = 4;
int Pf = 5;
int Pg = 6;
int Ph = 7;
int Pi = 8;
int Pj = 9;
int Pk = 10;
int Pl = 11;
int Pm = 12;
int Pn = 13;
int Po = 14;
int Pp = 15;
int Pq = 16;
int Pr = 17;
int Ps = 18;
int Pt = 19;
int Pu = 20;
int Pv = 21;
int Pw = 22;
int Px = 23;
int Py = 24;
int Pz = 25;
int Paa = 26;
int Pbb = 27;
int Pcc = 28;
int Pdd = 29;
int Pee = 30;
int Pff = 31;

bool Features::twofitybool1[32] = { false };
void Features::twofity1(Player target)
{
	if ((timeGetTime() - Features::TimePD4) > 200) // Time between drops
	{
		Ped iPedPa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pa);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPa)) 
		{
			Vector3 posPa = ENTITY::GET_ENTITY_COORDS(iPedPa, FALSE);
			OBJECT::_PED_DEATH_DROP(posPa.x, posPa.y, posPa.z + 0.5f, 2000);
		}
		Ped iPedPb = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pb);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPb)) 
		{
			Vector3 posPb = ENTITY::GET_ENTITY_COORDS(iPedPb, FALSE);
			OBJECT::_PED_DEATH_DROP(posPb.x, posPb.y, posPb.z + 0.5f, 2000);
		}
		Ped iPedPc = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pc);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPc)) 
		{
			Vector3 posPc = ENTITY::GET_ENTITY_COORDS(iPedPc, FALSE);
			OBJECT::_PED_DEATH_DROP(posPc.x, posPc.y, posPc.z + 0.5f, 2000);
		}
		Ped iPedPd = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pd);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPd)) 
		{
			Vector3 posPd = ENTITY::GET_ENTITY_COORDS(iPedPd, FALSE);
			OBJECT::_PED_DEATH_DROP(posPd.x, posPd.y, posPd.z + 0.5f, 2000);
		}
		Ped iPedPe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pe);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPe)) 
		{
			Vector3 posPe = ENTITY::GET_ENTITY_COORDS(iPedPe, FALSE);
			OBJECT::_PED_DEATH_DROP(posPe.x, posPe.y, posPe.z + 0.5f, 2000);
		}
		Ped iPedPf = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pf);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPf)) 
		{
			Vector3 posPf = ENTITY::GET_ENTITY_COORDS(iPedPf, FALSE);
			OBJECT::_PED_DEATH_DROP(posPf.x, posPf.y, posPf.z + 0.5f, 2000);
		}
		Ped iPedPg = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pg);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPg)) 
		{
			Vector3 posPg = ENTITY::GET_ENTITY_COORDS(iPedPg, FALSE);
			OBJECT::_PED_DEATH_DROP(posPg.x, posPg.y, posPg.z + 0.5f, 2000);
		}
		Ped iPedPh = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Ph);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPh)) 
		{
			Vector3 posPh = ENTITY::GET_ENTITY_COORDS(iPedPh, FALSE);
			OBJECT::_PED_DEATH_DROP(posPh.x, posPh.y, posPh.z + 0.5f, 2000);
		}
		Ped iPedPi = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pi);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPi)) 
		{
			Vector3 posPi = ENTITY::GET_ENTITY_COORDS(iPedPi, FALSE);
			OBJECT::_PED_DEATH_DROP(posPi.x, posPi.y, posPi.z + 0.5f, 2000);
		}
		Ped iPedPj = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pj);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPj)) 
		{
			Vector3 posPj = ENTITY::GET_ENTITY_COORDS(iPedPj, FALSE);
			OBJECT::_PED_DEATH_DROP(posPj.x, posPj.y, posPj.z + 0.5f, 2000);
		}
		Ped iPedPk = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pk);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPk)) 
		{
			Vector3 posPk = ENTITY::GET_ENTITY_COORDS(iPedPk, FALSE);
			OBJECT::_PED_DEATH_DROP(posPk.x, posPk.y, posPk.z + 0.5f, 2000);
		}
		Ped iPedPl = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pl);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPl)) 
		{
			Vector3 posPl = ENTITY::GET_ENTITY_COORDS(iPedPl, FALSE);
			OBJECT::_PED_DEATH_DROP(posPl.x, posPl.y, posPl.z + 0.5f, 2000);
		}
		Ped iPedPm = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pm);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPm)) 
		{
			Vector3 posPm = ENTITY::GET_ENTITY_COORDS(iPedPm, FALSE);
			OBJECT::_PED_DEATH_DROP(posPm.x, posPm.y, posPm.z + 0.5f, 2000);
		}
		Ped iPedPn = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pn);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPn)) 
		{
			Vector3 posPn = ENTITY::GET_ENTITY_COORDS(iPedPn, FALSE);
			OBJECT::_PED_DEATH_DROP(posPn.x, posPn.y, posPn.z + 0.5f, 2000);
		}
		Ped iPedPo = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Po);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPo)) 
		{
			Vector3 posPo = ENTITY::GET_ENTITY_COORDS(iPedPo, FALSE);
			OBJECT::_PED_DEATH_DROP(posPo.x, posPo.y, posPo.z + 0.5f, 2000);
		}
		Ped iPedPp = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pp);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPp)) 
		{
			Vector3 posPp = ENTITY::GET_ENTITY_COORDS(iPedPp, FALSE);
			OBJECT::_PED_DEATH_DROP(posPp.x, posPp.y, posPp.z + 0.5f, 2000);
		}
		Ped iPedPq = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pq);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPq)) 
		{
			Vector3 posPq = ENTITY::GET_ENTITY_COORDS(iPedPq, FALSE);
			OBJECT::_PED_DEATH_DROP(posPq.x, posPq.y, posPq.z + 0.5f, 2000);
		}
		Ped iPedPr = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pr);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPr)) 
		{
			Vector3 posPr = ENTITY::GET_ENTITY_COORDS(iPedPr, FALSE);
			OBJECT::_PED_DEATH_DROP(posPr.x, posPr.y, posPr.z + 0.5f, 2000);
		}
		Ped iPedPs = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Ps);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPs)) 
		{
			Vector3 posPs = ENTITY::GET_ENTITY_COORDS(iPedPs, FALSE);
			OBJECT::_PED_DEATH_DROP(posPs.x, posPs.y, posPs.z + 0.5f, 2000);
		}
		Ped iPedPt = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pt);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPt)) 
		{
			Vector3 posPt = ENTITY::GET_ENTITY_COORDS(iPedPt, FALSE);
			OBJECT::_PED_DEATH_DROP(posPt.x, posPt.y, posPt.z + 0.5f, 2000);
		}
		Ped iPedPu = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pu);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPu)) 
		{
			Vector3 posPu = ENTITY::GET_ENTITY_COORDS(iPedPu, FALSE);
			OBJECT::_PED_DEATH_DROP(posPu.x, posPu.y, posPu.z + 0.5f, 2000);
		}
		Ped iPedPv = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pv);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPv)) 
		{
			Vector3 posPv = ENTITY::GET_ENTITY_COORDS(iPedPv, FALSE);
			OBJECT::_PED_DEATH_DROP(posPv.x, posPv.y, posPv.z + 0.5f, 2000);
		}
		Ped iPedPw = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pw);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPw)) 
		{
			Vector3 posPw = ENTITY::GET_ENTITY_COORDS(iPedPw, FALSE);
			OBJECT::_PED_DEATH_DROP(posPw.x, posPw.y, posPw.z + 0.5f, 2000);
		}
		Ped iPedPx = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Px);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPx)) 
		{
			Vector3 posPx = ENTITY::GET_ENTITY_COORDS(iPedPx, FALSE);
			OBJECT::_PED_DEATH_DROP(posPx.x, posPx.y, posPx.z + 0.5f, 2000);
		}
		Ped iPedPy = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Py);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPy)) 
		{
			Vector3 posPy = ENTITY::GET_ENTITY_COORDS(iPedPy, FALSE);
			OBJECT::_PED_DEATH_DROP(posPy.x, posPy.y, posPy.z + 0.5f, 2000);
		}
		Ped iPedPz = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pz);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPz)) 
		{
			Vector3 posPz = ENTITY::GET_ENTITY_COORDS(iPedPz, FALSE);
			OBJECT::_PED_DEATH_DROP(posPz.x, posPz.y, posPz.z + 0.5f, 2000);
		}
		Ped iPedPaa = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Paa);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPaa)) 
		{
			Vector3 posPaa = ENTITY::GET_ENTITY_COORDS(iPedPaa, FALSE);
			OBJECT::_PED_DEATH_DROP(posPaa.x, posPaa.y, posPaa.z + 0.5f, 2000);
		}
		Ped iPedPbb = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pbb);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPbb)) 
		{
			Vector3 posPbb = ENTITY::GET_ENTITY_COORDS(iPedPbb, FALSE);
			OBJECT::_PED_DEATH_DROP(posPbb.x, posPbb.y, posPbb.z + 0.5f, 2000);
		}
		Ped iPedPcc = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pcc);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPcc)) 
		{
			Vector3 posPcc = ENTITY::GET_ENTITY_COORDS(iPedPcc, FALSE);
			OBJECT::_PED_DEATH_DROP(posPcc.x, posPcc.y, posPcc.z + 0.5f, 2000);
		}
		Ped iPedPdd = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pdd);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPdd)) 
		{
			Vector3 posPdd = ENTITY::GET_ENTITY_COORDS(iPedPdd, FALSE);
			OBJECT::_PED_DEATH_DROP(posPdd.x, posPdd.y, posPdd.z + 0.5f, 2000);
		}
		Ped iPedPee = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pee);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPee)) 
		{
			Vector3 posPee = ENTITY::GET_ENTITY_COORDS(iPedPee, FALSE);
			OBJECT::_PED_DEATH_DROP(posPee.x, posPee.y, posPee.z + 0.5f, 2000);
		}
		Ped iPedPff = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Pff);

		if (ENTITY::DOES_ENTITY_EXIST(iPedPff)) 
		{
			Vector3 posPff = ENTITY::GET_ENTITY_COORDS(iPedPff, FALSE);
			OBJECT::_PED_DEATH_DROP(posPff.x, posPff.y, posPff.z + 0.5f, 2000);
		}
		Features::TimePD4 = timeGetTime();
	}
}

bool Features::cashdrop2bool[32] = { false };
bool Features::cashdrop3bool = false;
void Features::cashdrop2(Player target)
{


	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

	int amount = 10000;

	/*for (int i = 0; i < ARRAYSIZE(object_prop_money_hash); i++)
	{*/

		if ((timeGetTime() - Features::TimePD4) > 200) // Time between drops
		{
			Hooking::request_model(PROP_MONEY_BAG_02);
			if (!Hooking::has_model_loaded(PROP_MONEY_BAG_02)) 
			{
				WAIT(0);
			}
			else 
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::CREATE_AMBIENT_PICKUP(0xFE18F3AF, pos.x, pos.y, pos.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, 0, 0);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
				NETWORKCASH::NETWORK_SPENT_HOLDUPS(amount, 0, 0);
				Features::TimePD4 = timeGetTime();

			}
		}
	//}
}

bool Features::storymodebool = false;
void Features::storymode(bool toggle)
{
	if (storymodebool == true)
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false), true, false);
		if (NETWORK::NETWORK_IS_SESSION_STARTED() == true) exit(0);
	}
}
bool Features::storycashdropbool = false;
void Features::storycashdrop(bool toggle)
{


	Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	int amount = 100000000;

	if ((timeGetTime() - Features::TimePD4) > 200 && storymodebool == true) // Time between drops
	{
		Hooking::request_model(PROP_MONEY_BAG_02);
		if (!Hooking::has_model_loaded(PROP_MONEY_BAG_02)) {
			WAIT(0);
		}
		else {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, pos.x, pos.y, pos.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);

			Features::TimePD4 = timeGetTime();

		}
	}
}

bool Features::slomobool = false;
void Features::slomonig(bool toggle)
{
	if (slomobool)
	{
		GAMEPLAY::SET_TIME_SCALE(0.2);
	}
	else
	{
		GAMEPLAY::SET_TIME_SCALE(1.0);
	}
}

void Features::SetRank(int rpvalue)
{
	if (rpvalue < 1 || rpvalue > 8000)
	{
		rpvalue = 8000;
	}
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Features::Levels[rpvalue], 0);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), Features::Levels[rpvalue], 0);

}

int Features::Levels[8000] = { 0, 800, 2100, 3800, 6100, 9500, 12500, 16000, 19800, 24000, 28500, 33400, 38700, 44200, 50200, 56400, 63000, 69900, 77100, 84700, 92500, 100700, 109200, 118000, 127100, 136500, 146200,
156200, 166500, 177100, 188000, 199200, 210700, 222400, 234500, 246800, 259400, 272300, 285500, 299000, 312700, 326800, 341000, 355600, 370500, 385600, 401000, 416600, 432600, 448800, 465200, 482000, 499000,
516300, 533800, 551600, 569600, 588000, 606500, 625400, 644500, 663800, 683400, 703300, 723400, 743800, 764500, 785400, 806500, 827900, 849600, 871500, 893600, 916000, 938700, 961600, 984700, 1008100, 1031800,
1055700, 1079800, 1104200, 1128800, 1153700, 1178800, 1204200, 1229800, 1255600, 1281700, 1308100, 1334600, 1361400, 1388500, 1415800, 1443300, 1471100, 1499100, 1527300, 1555800, 1584350, 1612950, 1641600,
1670300, 1699050, 1727850, 1756700, 1785600, 1814550, 1843550, 1872600, 1901700, 1930850, 1960050, 1989300, 2018600, 2047950, 2077350, 2106800, 2136300, 2165850, 2195450, 2225100, 2254800, 2284550, 2314350,
2344200, 2374100, 2404050, 2434050, 2464100, 2494200, 2524350, 2554550, 2584800, 2615100, 2645450, 2675850, 2706300, 2736800, 2767350, 2797950, 2828600, 2859300, 2890050, 2920850, 2951700, 2982600, 3013550,
3044550, 3075600, 3106700, 3137850, 3169050, 3200300, 3231600, 3262950, 3294350, 3325800, 3357300, 3388850, 3420450, 3452100, 3483800, 3515550, 3547350, 3579200, 3611100, 3643050, 3675050, 3707100, 3739200,
3771350, 3803550, 3835800, 3868100, 3900450, 3932850, 3965300, 3997800, 4030350, 4062950, 4095600, 4128300, 4161050, 4193850, 4226700, 4259600, 4292550, 4325550, 4358600, 4391700, 4424850, 4458050, 4491300,
4524600, 4557950, 4591350, 4624800, 4658300, 4691850, 4725450, 4759100, 4792800, 4826550, 4860350, 4894200, 4928100, 4962050, 4996050, 5030100, 5064200, 5098350, 5132550, 5166800, 5201100, 5235450, 5269850,
5304300, 5338800, 5373350, 5407950, 5442600, 5477300, 5512050, 5546850, 5581700, 5616600, 5651550, 5686550, 5721600, 5756700, 5791850, 5827050, 5862300, 5897600, 5932950, 5968350, 6003800, 6039300, 6074850,
6110450, 6146100, 6181800, 6217550, 6253350, 6289200, 6325100, 6361050, 6397050, 6433100, 6469200, 6505350, 6541550, 6577800, 6614100, 6650450, 6686850, 6723300, 6759800, 6796350, 6832950, 6869600, 6906300,
6943050, 6979850, 7016700, 7053600, 7090550, 7127550, 7164600, 7201700, 7238850, 7276050, 7313300, 7350600, 7387950, 7425350, 7462800, 7500300, 7537850, 7575450, 7613100, 7650800, 7688550, 7726350, 7764200,
7802100, 7840050, 7878050, 7916100, 7954200, 7992350, 8030550, 8068800, 8107100, 8145450, 8183850, 8222300, 8260800, 8299350, 8337950, 8376600, 8415300, 8454050, 8492850, 8531700, 8570600, 8609550, 8648550,
8687600, 8726700, 8765850, 8805050, 8844300, 8883600, 8922950, 8962350, 9001800, 9041300, 9080850, 9120450, 9160100, 9199800, 9239550, 9279350, 9319200, 9359100, 9399050, 9439050, 9479100, 9519200, 9559350,
9599550, 9639800, 9680100, 9720450, 9760850, 9801300, 9841800, 9882350, 9922950, 9963600, 10004300, 10045050, 10085850, 10126700, 10167600, 10208550, 10249550, 10290600, 10331700, 10372850, 10414050, 10455300,
10496600, 10537950, 10579350, 10620800, 10662300, 10703850, 10745450, 10787100, 10828800, 10870550, 10912350, 10954200, 10996100, 11038050, 11080050, 11122100, 11164200, 11206350, 11248550, 11290800, 11333100,
11375450, 11417850, 11460300, 11502800, 11545350, 11587950, 11630600, 11673300, 11716050, 11758850, 11801700, 11844600, 11887550, 11930550, 11973600, 12016700, 12059850, 12103050, 12146300, 12189600, 12232950,
12276350, 12319800, 12363300, 12406850, 12450450, 12494100, 12537800, 12581550, 12625350, 12669200, 12713100, 12757050, 12801050, 12845100, 12889200, 12933350, 12977550, 13021800, 13066100, 13110450, 13154850,
13199300, 13243800, 13288350, 13332950, 13377600, 13422300, 13467050, 13511850, 13556700, 13601600, 13646550, 13691550, 13736600, 13781700, 13826850, 13872050, 13917300, 13962600, 14007950, 14053350, 14098800,
14144300, 14189850, 14235450, 14281100, 14326800, 14372550, 14418350, 14464200, 14510100, 14556050, 14602050, 14648100, 14694200, 14740350, 14786550, 14832800, 14879100, 14925450, 14971850, 15018300, 15064800,
15111350, 15157950, 15204600, 15251300, 15298050, 15344850, 15391700, 15438600, 15485550, 15532550, 15579600, 15626700, 15673850, 15721050, 15768300, 15815600, 15862950, 15910350, 15957800, 16005300, 16052850,
16100450, 16148100, 16195800, 16243550, 16291350, 16339200, 16387100, 16435050, 16483050, 16531100, 16579200, 16627350, 16675550, 16723800, 16772100, 16820450, 16868850, 16917300, 16965800, 17014350, 17062950,
17111600, 17160300, 17209050, 17257850, 17306700, 17355600, 17404550, 17453550, 17502600, 17551700, 17600850, 17650050, 17699300, 17748600, 17797950, 17847350, 17896800, 17946300, 17995850, 18045450, 18095100,
18144800, 18194550, 18244350, 18294200, 18344100, 18394050, 18444050, 18494100, 18544200, 18594350, 18644550, 18694800, 18745100, 18795450, 18845850, 18896300, 18946800, 18997350, 19047950, 19098600, 19149300,
19200050, 19250850, 19301700, 19352600, 19403550, 19454550, 19505600, 19556700, 19607850, 19659050, 19710300, 19761600, 19812950, 19864350, 19915800, 19967300, 20018850, 20070450, 20122100, 20173800, 20225550,
20277350, 20329200, 20381100, 20433050, 20485050, 20537100, 20589200, 20641350, 20693550, 20745800, 20798100, 20850450, 20902850, 20955300, 21007800, 21060350, 21112950, 21165600, 21218300, 21271050, 21323850,
21376700, 21429600, 21482550, 21535550, 21588600, 21641700, 21694850, 21748050, 21801300, 21854600, 21907950, 21961350, 22014800, 22068300, 22121850, 22175450, 22229100, 22282800, 22336550, 22390350, 22444200,
22498100, 22552050, 22606050, 22660100, 22714200, 22768350, 22822550, 22876800, 22931100, 22985450, 23039850, 23094300, 23148800, 23203350, 23257950, 23312600, 23367300, 23422050, 23476850, 23531700, 23586600,
23641550, 23696550, 23751600, 23806700, 23861850, 23917050, 23972300, 24027600, 24082950, 24138350, 24193800, 24249300, 24304850, 24360450, 24416100, 24471800, 24527550, 24583350, 24639200, 24695100, 24751050,
24807050, 24863100, 24919200, 24975350, 25031550, 25087800, 25144100, 25200450, 25256850, 25313300, 25369800, 25426350, 25482950, 25539600, 25596300, 25653050, 25709850, 25766700, 25823600, 25880550, 25937550,
25994600, 26051700, 26108850, 26166050, 26223300, 26280600, 26337950, 26395350, 26452800, 26510300, 26567850, 26625450, 26683100, 26740800, 26798550, 26856350, 26914200, 26972100, 27030050, 27088050, 27146100,
27204200, 27262350, 27320550, 27378800, 27437100, 27495450, 27553850, 27612300, 27670800, 27729350, 27787950, 27846600, 27905300, 27964050, 28022850, 28081700, 28140600, 28199550, 28258550, 28317600, 28376700,
28435850, 28495050, 28554300, 28613600, 28672950, 28732350, 28791800, 28851300, 28910850, 28970450, 29030100, 29089800, 29149550, 29209350, 29269200, 29329100, 29389050, 29449050, 29509100, 29569200, 29629350,
29689550, 29749800, 29810100, 29870450, 29930850, 29991300, 30051800, 30112350, 30172950, 30233600, 30294300, 30355050, 30415850, 30476700, 30537600, 30598550, 30659550, 30720600, 30781700, 30842850, 30904050,
30965300, 31026600, 31087950, 31149350, 31210800, 31272300, 31333850, 31395450, 31457100, 31518800, 31580550, 31642350, 31704200, 31766100, 31828050, 31890050, 31952100, 32014200, 32076350, 32138550, 32200800,
32263100, 32325450, 32387850, 32450300, 32512800, 32575350, 32637950, 32700600, 32763300, 32826050, 32888850, 32951700, 33014600, 33077550, 33140550, 33203600, 33266700, 33329850, 33393050, 33456300, 33519600,
33582950, 33646350, 33709800, 33773300, 33836850, 33900450, 33964100, 34027800, 34091550, 34155350, 34219200, 34283100, 34347050, 34411050, 34475100, 34539200, 34603350, 34667550, 34731800, 34796100, 34860450,
34924850, 34989300, 35053800, 35118350, 35182950, 35247600, 35312300, 35377050, 35441850, 35506700, 35571600, 35636550, 35701550, 35766600, 35831700, 35896850, 35962050, 36027300, 36092600, 36157950, 36223350,
36288800, 36354300, 36419850, 36485450, 36551100, 36616800, 36682550, 36748350, 36814200, 36880100, 36946050, 37012050, 37078100, 37144200, 37210350, 37276550, 37342800, 37409100, 37475450, 37541850, 37608300,
37674800, 37741350, 37807950, 37874600, 37941300, 38008050, 38074850, 38141700, 38208600, 38275550, 38342550, 38409600, 38476700, 38543850, 38611050, 38678300, 38745600, 38812950, 38880350, 38947800, 39015300,
39082850, 39150450, 39218100, 39285800, 39353550, 39421350, 39489200, 39557100, 39625050, 39693050, 39761100, 39829200, 39897350, 39965550, 40033800, 40102100, 40170450, 40238850, 40307300, 40375800, 40444350,
40512950, 40581600, 40650300, 40719050, 40787850, 40856700, 40925600, 40994550, 41063550, 41132600, 41201700, 41270850, 41340050, 41409300, 41478600, 41547950, 41617350, 41686800, 41756300, 41825850, 41895450,
41965100, 42034800, 42104550, 42174350, 42244200, 42314100, 42384050, 42454050, 42524100, 42594200, 42664350, 42734550, 42804800, 42875100, 42945450, 43015850, 43086300, 43156800, 43227350, 43297950, 43368600,
43439300, 43510050, 43580850, 43651700, 43722600, 43793550, 43864550, 43935600, 44006700, 44077850, 44149050, 44220300, 44291600, 44362950, 44434350, 44505800, 44577300, 44648850, 44720450, 44792100, 44863800,
44935550, 45007350, 45079200, 45151100, 45223050, 45295050, 45367100, 45439200, 45511350, 45583550, 45655800, 45728100, 45800450, 45872850, 45945300, 46017800, 46090350, 46162950, 46235600, 46308300, 46381050,
46453850, 46526700, 46599600, 46672550, 46745550, 46818600, 46891700, 46964850, 47038050, 47111300, 47184600, 47257950, 47331350, 47404800, 47478300, 47551850, 47625450, 47699100, 47772800, 47846550, 47920350,
47994200, 48068100, 48142050, 48216050, 48290100, 48364200, 48438350, 48512550, 48586800, 48661100, 48735450, 48809850, 48884300, 48958800, 49033350, 49107950, 49182600, 49257300, 49332050, 49406850, 49481700,
49556600, 49631550, 49706550, 49781600, 49856700, 49931850, 50007050, 50082300, 50157600, 50232950, 50308350, 50383800, 50459300, 50534850, 50610450, 50686100, 50761800, 50837550, 50913350, 50989200, 51065100,
51141050, 51217050, 51293100, 51369200, 51445350, 51521550, 51597800, 51674100, 51750450, 51826850, 51903300, 51979800, 52056350, 52132950, 52209600, 52286300, 52363050, 52439850, 52516700, 52593600, 52670550,
52747550, 52824600, 52901700, 52978850, 53056050, 53133300, 53210600, 53287950, 53365350, 53442800, 53520300, 53597850, 53675450, 53753100, 53830800, 53908550, 53986350, 54064200, 54142100, 54220050, 54298050,
54376100, 54454200, 54532350, 54610550, 54688800, 54767100, 54845450, 54923850, 55002300, 55080800, 55159350, 55237950, 55316600, 55395300, 55474050, 55552850, 55631700, 55710600, 55789550, 55868550, 55947600,
56026700, 56105850, 56185050, 56264300, 56343600, 56422950, 56502350, 56581800, 56661300, 56740850, 56820450, 56900100, 56979800, 57059550, 57139350, 57219200, 57299100, 57379050, 57459050, 57539100, 57619200,
57699350, 57779550, 57859800, 57940100, 58020450, 58100850, 58181300, 58261800, 58342350, 58422950, 58503600, 58584300, 58665050, 58745850, 58826700, 58907600, 58988550, 59069550, 59150600, 59231700, 59312850,
59394050, 59475300, 59556600, 59637950, 59719350, 59800800, 59882300, 59963850, 60045450, 60127100, 60208800, 60290550, 60372350, 60454200, 60536100, 60618050, 60700050, 60782100, 60864200, 60946350, 61028550,
61110800, 61193100, 61275450, 61357850, 61440300, 61522800, 61605350, 61687950, 61770600, 61853300, 61936050, 62018850, 62101700, 62184600, 62267550, 62350550, 62433600, 62516700, 62599850, 62683050, 62766300,
62849600, 62932950, 63016350, 63099800, 63183300, 63266850, 63350450, 63434100, 63517800, 63601550, 63685350, 63769200, 63853100, 63937050, 64021050, 64105100, 64189200, 64273350, 64357550, 64441800, 64526100,
64610450, 64694850, 64779300, 64863800, 64948350, 65032950, 65117600, 65202300, 65287050, 65371850, 65456700, 65541600, 65626550, 65711550, 65796600, 65881700, 65966850, 66052050, 66137300, 66222600, 66307950,
66393350, 66478800, 66564300, 66649850, 66735450, 66821100, 66906800, 66992550, 67078350, 67164200, 67250100, 67336050, 67422050, 67508100, 67594200, 67680350, 67766550, 67852800, 67939100, 68025450, 68111850,
68198300, 68284800, 68371350, 68457950, 68544600, 68631300, 68718050, 68804850, 68891700, 68978600, 69065550, 69152550, 69239600, 69326700, 69413850, 69501050, 69588300, 69675600, 69762950, 69850350, 69937800,
70025300, 70112850, 70200450, 70288100, 70375800, 70463550, 70551350, 70639200, 70727100, 70815050, 70903050, 70991100, 71079200, 71167350, 71255550, 71343800, 71432100, 71520450, 71608850, 71697300, 71785800,
71874350, 71962950, 72051600, 72140300, 72229050, 72317850, 72406700, 72495600, 72584550, 72673550, 72762600, 72851700, 72940850, 73030050, 73119300, 73208600, 73297950, 73387350, 73476800, 73566300, 73655850,
73745450, 73835100, 73924800, 74014550, 74104350, 74194200, 74284100, 74374050, 74464050, 74554100, 74644200, 74734350, 74824550, 74914800, 75005100, 75095450, 75185850, 75276300, 75366800, 75457350, 75547950,
75638600, 75729300, 75820050, 75910850, 76001700, 76092600, 76183550, 76274550, 76365600, 76456700, 76547850, 76639050, 76730300, 76821600, 76912950, 77004350, 77095800, 77187300, 77278850, 77370450, 77462100,
77553800, 77645550, 77737350, 77829200, 77921100, 78013050, 78105050, 78197100, 78289200, 78381350, 78473550, 78565800, 78658100, 78750450, 78842850, 78935300, 79027800, 79120350, 79212950, 79305600, 79398300,
79491050, 79583850, 79676700, 79769600, 79862550, 79955550, 80048600, 80141700, 80234850, 80328050, 80421300, 80514600, 80607950, 80701350, 80794800, 80888300, 80981850, 81075450, 81169100, 81262800, 81356550,
81450350, 81544200, 81638100, 81732050, 81826050, 81920100, 82014200, 82108350, 82202550, 82296800, 82391100, 82485450, 82579850, 82674300, 82768800, 82863350, 82957950, 83052600, 83147300, 83242050, 83336850,
83431700, 83526600, 83621550, 83716550, 83811600, 83906700, 84001850, 84097050, 84192300, 84287600, 84382950, 84478350, 84573800, 84669300, 84764850, 84860450, 84956100, 85051800, 85147550, 85243350, 85339200,
85435100, 85531050, 85627050, 85723100, 85819200, 85915350, 86011550, 86107800, 86204100, 86300450, 86396850, 86493300, 86589800, 86686350, 86782950, 86879600, 86976300, 87073050, 87169850, 87266700, 87363600,
87460550, 87557550, 87654600, 87751700, 87848850, 87946050, 88043300, 88140600, 88237950, 88335350, 88432800, 88530300, 88627850, 88725450, 88823100, 88920800, 89018550, 89116350, 89214200, 89312100, 89410050,
89508050, 89606100, 89704200, 89802350, 89900550, 89998800, 90097100, 90195450, 90293850, 90392300, 90490800, 90589350, 90687950, 90786600, 90885300, 90984050, 91082850, 91181700, 91280600, 91379550, 91478550,
91577600, 91676700, 91775850, 91875050, 91974300, 92073600, 92172950, 92272350, 92371800, 92471300, 92570850, 92670450, 92770100, 92869800, 92969550, 93069350, 93169200, 93269100, 93369050, 93469050, 93569100,
93669200, 93769350, 93869550, 93969800, 94070100, 94170450, 94270850, 94371300, 94471800, 94572350, 94672950, 94773600, 94874300, 94975050, 95075850, 95176700, 95277600, 95378550, 95479550, 95580600, 95681700,
95782850, 95884050, 95985300, 96086600, 96187950, 96289350, 96390800, 96492300, 96593850, 96695450, 96797100, 96898800, 97000550, 97102350, 97204200, 97306100, 97408050, 97510050, 97612100, 97714200, 97816350,
97918550, 98020800, 98123100, 98225450, 98327850, 98430300, 98532800, 98635350, 98737950, 98840600, 98943300, 99046050, 99148850, 99251700, 99354600, 99457550, 99560550, 99663600, 99766700, 99869850, 99973050,
100076300, 100179600, 100282950, 100386350, 100489800, 100593300, 100696850, 100800450, 100904100, 101007800, 101111550, 101215350, 101319200, 101423100, 101527050, 101631050, 101735100, 101839200, 101943350,
102047550, 102151800, 102256100, 102360450, 102464850, 102569300, 102673800, 102778350, 102882950, 102987600, 103092300, 103197050, 103301850, 103406700, 103511600, 103616550, 103721550, 103826600, 103931700,
104036850, 104142050, 104247300, 104352600, 104457950, 104563350, 104668800, 104774300, 104879850, 104985450, 105091100, 105196800, 105302550, 105408350, 105514200, 105620100, 105726050, 105832050, 105938100,
106044200, 106150350, 106256550, 106362800, 106469100, 106575450, 106681850, 106788300, 106894800, 107001350, 107107950, 107214600, 107321300, 107428050, 107534850, 107641700, 107748600, 107855550, 107962550,
108069600, 108176700, 108283850, 108391050, 108498300, 108605600, 108712950, 108820350, 108927800, 109035300, 109142850, 109250450, 109358100, 109465800, 109573550, 109681350, 109789200, 109897100, 110005050,
110113050, 110221100, 110329200, 110437350, 110545550, 110653800, 110762100, 110870450, 110978850, 111087300, 111195800, 111304350, 111412950, 111521600, 111630300, 111739050, 111847850, 111956700, 112065600,
112174550, 112283550, 112392600, 112501700, 112610850, 112720050, 112829300, 112938600, 113047950, 113157350, 113266800, 113376300, 113485850, 113595450, 113705100, 113814800, 113924550, 114034350, 114144200,
114254100, 114364050, 114474050, 114584100, 114694200, 114804350, 114914550, 115024800, 115135100, 115245450, 115355850, 115466300, 115576800, 115687350, 115797950, 115908600, 116019300, 116130050, 116240850,
116351700, 116462600, 116573550, 116684550, 116795600, 116906700, 117017850, 117129050, 117240300, 117351600, 117462950, 117574350, 117685800, 117797300, 117908850, 118020450, 118132100, 118243800, 118355550,
118467350, 118579200, 118691100, 118803050, 118915050, 119027100, 119139200, 119251350, 119363550, 119475800, 119588100, 119700450, 119812850, 119925300, 120037800, 120150350, 120262950, 120375600, 120488300,
120601050, 120713850, 120826700, 120939600, 121052550, 121165550, 121278600, 121391700, 121504850, 121618050, 121731300, 121844600, 121957950, 122071350, 122184800, 122298300, 122411850, 122525450, 122639100,
122752800, 122866550, 122980350, 123094200, 123208100, 123322050, 123436050, 123550100, 123664200, 123778350, 123892550, 124006800, 124121100, 124235450, 124349850, 124464300, 124578800, 124693350, 124807950,
124922600, 125037300, 125152050, 125266850, 125381700, 125496600, 125611550, 125726550, 125841600, 125956700, 126071850, 126187050, 126302300, 126417600, 126532950, 126648350, 126763800, 126879300, 126994850,
127110450, 127226100, 127341800, 127457550, 127573350, 127689200, 127805100, 127921050, 128037050, 128153100, 128269200, 128385350, 128501550, 128617800, 128734100, 128850450, 128966850, 129083300, 129199800,
129316350, 129432950, 129549600, 129666300, 129783050, 129899850, 130016700, 130133600, 130250550, 130367550, 130484600, 130601700, 130718850, 130836050, 130953300, 131070600, 131187950, 131305350, 131422800,
131540300, 131657850, 131775450, 131893100, 132010800, 132128550, 132246350, 132364200, 132482100, 132600050, 132718050, 132836100, 132954200, 133072350, 133190550, 133308800, 133427100, 133545450, 133663850,
133782300, 133900800, 134019350, 134137950, 134256600, 134375300, 134494050, 134612850, 134731700, 134850600, 134969550, 135088550, 135207600, 135326700, 135445850, 135565050, 135684300, 135803600, 135922950,
136042350, 136161800, 136281300, 136400850, 136520450, 136640100, 136759800, 136879550, 136999350, 137119200, 137239100, 137359050, 137479050, 137599100, 137719200, 137839350, 137959550, 138079800, 138200100,
138320450, 138440850, 138561300, 138681800, 138802350, 138922950, 139043600, 139164300, 139285050, 139405850, 139526700, 139647600, 139768550, 139889550, 140010600, 140131700, 140252850, 140374050, 140495300,
140616600, 140737950, 140859350, 140980800, 141102300, 141223850, 141345450, 141467100, 141588800, 141710550, 141832350, 141954200, 142076100, 142198050, 142320050, 142442100, 142564200, 142686350, 142808550,
142930800, 143053100, 143175450, 143297850, 143420300, 143542800, 143665350, 143787950, 143910600, 144033300, 144156050, 144278850, 144401700, 144524600, 144647550, 144770550, 144893600, 145016700, 145139850,
145263050, 145386300, 145509600, 145632950, 145756350, 145879800, 146003300, 146126850, 146250450, 146374100, 146497800, 146621550, 146745350, 146869200, 146993100, 147117050, 147241050, 147365100, 147489200,
147613350, 147737550, 147861800, 147986100, 148110450, 148234850, 148359300, 148483800, 148608350, 148732950, 148857600, 148982300, 149107050, 149231850, 149356700, 149481600, 149606550, 149731550, 149856600,
149981700, 150106850, 150232050, 150357300, 150482600, 150607950, 150733350, 150858800, 150984300, 151109850, 151235450, 151361100, 151486800, 151612550, 151738350, 151864200, 151990100, 152116050, 152242050,
152368100, 152494200, 152620350, 152746550, 152872800, 152999100, 153125450, 153251850, 153378300, 153504800, 153631350, 153757950, 153884600, 154011300, 154138050, 154264850, 154391700, 154518600, 154645550,
154772550, 154899600, 155026700, 155153850, 155281050, 155408300, 155535600, 155662950, 155790350, 155917800, 156045300, 156172850, 156300450, 156428100, 156555800, 156683550, 156811350, 156939200, 157067100,
157195050, 157323050, 157451100, 157579200, 157707350, 157835550, 157963800, 158092100, 158220450, 158348850, 158477300, 158605800, 158734350, 158862950, 158991600, 159120300, 159249050, 159377850, 159506700,
159635600, 159764550, 159893550, 160022600, 160151700, 160280850, 160410050, 160539300, 160668600, 160797950, 160927350, 161056800, 161186300, 161315850, 161445450, 161575100, 161704800, 161834550, 161964350,
162094200, 162224100, 162354050, 162484050, 162614100, 162744200, 162874350, 163004550, 163134800, 163265100, 163395450, 163525850, 163656300, 163786800, 163917350, 164047950, 164178600, 164309300, 164440050,
164570850, 164701700, 164832600, 164963550, 165094550, 165225600, 165356700, 165487850, 165619050, 165750300, 165881600, 166012950, 166144350, 166275800, 166407300, 166538850, 166670450, 166802100, 166933800,
167065550, 167197350, 167329200, 167461100, 167593050, 167725050, 167857100, 167989200, 168121350, 168253550, 168385800, 168518100, 168650450, 168782850, 168915300, 169047800, 169180350, 169312950, 169445600,
169578300, 169711050, 169843850, 169976700, 170109600, 170242550, 170375550, 170508600, 170641700, 170774850, 170908050, 171041300, 171174600, 171307950, 171441350, 171574800, 171708300, 171841850, 171975450,
172109100, 172242800, 172376550, 172510350, 172644200, 172778100, 172912050, 173046050, 173180100, 173314200, 173448350, 173582550, 173716800, 173851100, 173985450, 174119850, 174254300, 174388800, 174523350,
174657950, 174792600, 174927300, 175062050, 175196850, 175331700, 175466600, 175601550, 175736550, 175871600, 176006700, 176141850, 176277050, 176412300, 176547600, 176682950, 176818350, 176953800, 177089300,
177224850, 177360450, 177496100, 177631800, 177767550, 177903350, 178039200, 178175100, 178311050, 178447050, 178583100, 178719200, 178855350, 178991550, 179127800, 179264100, 179400450, 179536850, 179673300,
179809800, 179946350, 180082950, 180219600, 180356300, 180493050, 180629850, 180766700, 180903600, 181040550, 181177550, 181314600, 181451700, 181588850, 181726050, 181863300, 182000600, 182137950, 182275350,
182412800, 182550300, 182687850, 182825450, 182963100, 183100800, 183238550, 183376350, 183514200, 183652100, 183790050, 183928050, 184066100, 184204200, 184342350, 184480550, 184618800, 184757100, 184895450,
185033850, 185172300, 185310800, 185449350, 185587950, 185726600, 185865300, 186004050, 186142850, 186281700, 186420600, 186559550, 186698550, 186837600, 186976700, 187115850, 187255050, 187394300, 187533600,
187672950, 187812350, 187951800, 188091300, 188230850, 188370450, 188510100, 188649800, 188789550, 188929350, 189069200, 189209100, 189349050, 189489050, 189629100, 189769200, 189909350, 190049550, 190189800,
190330100, 190470450, 190610850, 190751300, 190891800, 191032350, 191172950, 191313600, 191454300, 191595050, 191735850, 191876700, 192017600, 192158550, 192299550, 192440600, 192581700, 192722850, 192864050,
193005300, 193146600, 193287950, 193429350, 193570800, 193712300, 193853850, 193995450, 194137100, 194278800, 194420550, 194562350, 194704200, 194846100, 194988050, 195130050, 195272100, 195414200, 195556350,
195698550, 195840800, 195983100, 196125450, 196267850, 196410300, 196552800, 196695350, 196837950, 196980600, 197123300, 197266050, 197408850, 197551700, 197694600, 197837550, 197980550, 198123600, 198266700,
198409850, 198553050, 198696300, 198839600, 198982950, 199126350, 199269800, 199413300, 199556850, 199700450, 199844100, 199987800, 200131550, 200275350, 200419200, 200563100, 200707050, 200851050, 200995100,
201139200, 201283350, 201427550, 201571800, 201716100, 201860450, 202004850, 202149300, 202293800, 202438350, 202582950, 202727600, 202872300, 203017050, 203161850, 203306700, 203451600, 203596550, 203741550,
203886600, 204031700, 204176850, 204322050, 204467300, 204612600, 204757950, 204903350, 205048800, 205194300, 205339850, 205485450, 205631100, 205776800, 205922550, 206068350, 206214200, 206360100, 206506050,
206652050, 206798100, 206944200, 207090350, 207236550, 207382800, 207529100, 207675450, 207821850, 207968300, 208114800, 208261350, 208407950, 208554600, 208701300, 208848050, 208994850, 209141700, 209288600,
209435550, 209582550, 209729600, 209876700, 210023850, 210171050, 210318300, 210465600, 210612950, 210760350, 210907800, 211055300, 211202850, 211350450, 211498100, 211645800, 211793550, 211941350, 212089200,
212237100, 212385050, 212533050, 212681100, 212829200, 212977350, 213125550, 213273800, 213422100, 213570450, 213718850, 213867300, 214015800, 214164350, 214312950, 214461600, 214610300, 214759050, 214907850,
215056700, 215205600, 215354550, 215503550, 215652600, 215801700, 215950850, 216100050, 216249300, 216398600, 216547950, 216697350, 216846800, 216996300, 217145850, 217295450, 217445100, 217594800, 217744550,
217894350, 218044200, 218194100, 218344050, 218494050, 218644100, 218794200, 218944350, 219094550, 219244800, 219395100, 219545450, 219695850, 219846300, 219996800, 220147350, 220297950, 220448600, 220599300,
220750050, 220900850, 221051700, 221202600, 221353550, 221504550, 221655600, 221806700, 221957850, 222109050, 222260300, 222411600, 222562950, 222714350, 222865800, 223017300, 223168850, 223320450, 223472100,
223623800, 223775550, 223927350, 224079200, 224231100, 224383050, 224535050, 224687100, 224839200, 224991350, 225143550, 225295800, 225448100, 225600450, 225752850, 225905300, 226057800, 226210350, 226362950,
226515600, 226668300, 226821050, 226973850, 227126700, 227279600, 227432550, 227585550, 227738600, 227891700, 228044850, 228198050, 228351300, 228504600, 228657950, 228811350, 228964800, 229118300, 229271850,
229425450, 229579100, 229732800, 229886550, 230040350, 230194200, 230348100, 230502050, 230656050, 230810100, 230964200, 231118350, 231272550, 231426800, 231581100, 231735450, 231889850, 232044300, 232198800,
232353350, 232507950, 232662600, 232817300, 232972050, 233126850, 233281700, 233436600, 233591550, 233746550, 233901600, 234056700, 234211850, 234367050, 234522300, 234677600, 234832950, 234988350, 235143800,
235299300, 235454850, 235610450, 235766100, 235921800, 236077550, 236233350, 236389200, 236545100, 236701050, 236857050, 237013100, 237169200, 237325350, 237481550, 237637800, 237794100, 237950450, 238106850,
238263300, 238419800, 238576350, 238732950, 238889600, 239046300, 239203050, 239359850, 239516700, 239673600, 239830550, 239987550, 240144600, 240301700, 240458850, 240616050, 240773300, 240930600, 241087950,
241245350, 241402800, 241560300, 241717850, 241875450, 242033100, 242190800, 242348550, 242506350, 242664200, 242822100, 242980050, 243138050, 243296100, 243454200, 243612350, 243770550, 243928800, 244087100,
244245450, 244403850, 244562300, 244720800, 244879350, 245037950, 245196600, 245355300, 245514050, 245672850, 245831700, 245990600, 246149550, 246308550, 246467600, 246626700, 246785850, 246945050, 247104300,
247263600, 247422950, 247582350, 247741800, 247901300, 248060850, 248220450, 248380100, 248539800, 248699550, 248859350, 249019200, 249179100, 249339050, 249499050, 249659100, 249819200, 249979350, 250139550,
250299800, 250460100, 250620450, 250780850, 250941300, 251101800, 251262350, 251422950, 251583600, 251744300, 251905050, 252065850, 252226700, 252387600, 252548550, 252709550, 252870600, 253031700, 253192850,
253354050, 253515300, 253676600, 253837950, 253999350, 254160800, 254322300, 254483850, 254645450, 254807100, 254968800, 255130550, 255292350, 255454200, 255616100, 255778050, 255940050, 256102100, 256264200,
256426350, 256588550, 256750800, 256913100, 257075450, 257237850, 257400300, 257562800, 257725350, 257887950, 258050600, 258213300, 258376050, 258538850, 258701700, 258864600, 259027550, 259190550, 259353600,
259516700, 259679850, 259843050, 260006300, 260169600, 260332950, 260496350, 260659800, 260823300, 260986850, 261150450, 261314100, 261477800, 261641550, 261805350, 261969200, 262133100, 262297050, 262461050,
262625100, 262789200, 262953350, 263117550, 263281800, 263446100, 263610450, 263774850, 263939300, 264103800, 264268350, 264432950, 264597600, 264762300, 264927050, 265091850, 265256700, 265421600, 265586550,
265751550, 265916600, 266081700, 266246850, 266412050, 266577300, 266742600, 266907950, 267073350, 267238800, 267404300, 267569850, 267735450, 267901100, 268066800, 268232550, 268398350, 268564200, 268730100,
268896050, 269062050, 269228100, 269394200, 269560350, 269726550, 269892800, 270059100, 270225450, 270391850, 270558300, 270724800, 270891350, 271057950, 271224600, 271391300, 271558050, 271724850, 271891700,
272058600, 272225550, 272392550, 272559600, 272726700, 272893850, 273061050, 273228300, 273395600, 273562950, 273730350, 273897800, 274065300, 274232850, 274400450, 274568100, 274735800, 274903550, 275071350,
275239200, 275407100, 275575050, 275743050, 275911100, 276079200, 276247350, 276415550, 276583800, 276752100, 276920450, 277088850, 277257300, 277425800, 277594350, 277762950, 277931600, 278100300, 278269050,
278437850, 278606700, 278775600, 278944550, 279113550, 279282600, 279451700, 279620850, 279790050, 279959300, 280128600, 280297950, 280467350, 280636800, 280806300, 280975850, 281145450, 281315100, 281484800,
281654550, 281824350, 281994200, 282164100, 282334050, 282504050, 282674100, 282844200, 283014350, 283184550, 283354800, 283525100, 283695450, 283865850, 284036300, 284206800, 284377350, 284547950, 284718600,
284889300, 285060050, 285230850, 285401700, 285572600, 285743550, 285914550, 286085600, 286256700, 286427850, 286599050, 286770300, 286941600, 287112950, 287284350, 287455800, 287627300, 287798850, 287970450,
288142100, 288313800, 288485550, 288657350, 288829200, 289001100, 289173050, 289345050, 289517100, 289689200, 289861350, 290033550, 290205800, 290378100, 290550450, 290722850, 290895300, 291067800, 291240350,
291412950, 291585600, 291758300, 291931050, 292103850, 292276700, 292449600, 292622550, 292795550, 292968600, 293141700, 293314850, 293488050, 293661300, 293834600, 294007950, 294181350, 294354800, 294528300,
294701850, 294875450, 295049100, 295222800, 295396550, 295570350, 295744200, 295918100, 296092050, 296266050, 296440100, 296614200, 296788350, 296962550, 297136800, 297311100, 297485450, 297659850, 297834300,
298008800, 298183350, 298357950, 298532600, 298707300, 298882050, 299056850, 299231700, 299406600, 299581550, 299756550, 299931600, 300106700, 300281850, 300457050, 300632300, 300807600, 300982950, 301158350,
301333800, 301509300, 301684850, 301860450, 302036100, 302211800, 302387550, 302563350, 302739200, 302915100, 303091050, 303267050, 303443100, 303619200, 303795350, 303971550, 304147800, 304324100, 304500450,
304676850, 304853300, 305029800, 305206350, 305382950, 305559600, 305736300, 305913050, 306089850, 306266700, 306443600, 306620550, 306797550, 306974600, 307151700, 307328850, 307506050, 307683300, 307860600,
308037950, 308215350, 308392800, 308570300, 308747850, 308925450, 309103100, 309280800, 309458550, 309636350, 309814200, 309992100, 310170050, 310348050, 310526100, 310704200, 310882350, 311060550, 311238800,
311417100, 311595450, 311773850, 311952300, 312130800, 312309350, 312487950, 312666600, 312845300, 313024050, 313202850, 313381700, 313560600, 313739550, 313918550, 314097600, 314276700, 314455850, 314635050,
314814300, 314993600, 315172950, 315352350, 315531800, 315711300, 315890850, 316070450, 316250100, 316429800, 316609550, 316789350, 316969200, 317149100, 317329050, 317509050, 317689100, 317869200, 318049350,
318229550, 318409800, 318590100, 318770450, 318950850, 319131300, 319311800, 319492350, 319672950, 319853600, 320034300, 320215050, 320395850, 320576700, 320757600, 320938550, 321119550, 321300600, 321481700,
321662850, 321844050, 322025300, 322206600, 322387950, 322569350, 322750800, 322932300, 323113850, 323295450, 323477100, 323658800, 323840550, 324022350, 324204200, 324386100, 324568050, 324750050, 324932100,
325114200, 325296350, 325478550, 325660800, 325843100, 326025450, 326207850, 326390300, 326572800, 326755350, 326937950, 327120600, 327303300, 327486050, 327668850, 327851700, 328034600, 328217550, 328400550,
328583600, 328766700, 328949850, 329133050, 329316300, 329499600, 329682950, 329866350, 330049800, 330233300, 330416850, 330600450, 330784100, 330967800, 331151550, 331335350, 331519200, 331703100, 331887050,
332071050, 332255100, 332439200, 332623350, 332807550, 332991800, 333176100, 333360450, 333544850, 333729300, 333913800, 334098350, 334282950, 334467600, 334652300, 334837050, 335021850, 335206700, 335391600,
335576550, 335761550, 335946600, 336131700, 336316850, 336502050, 336687300, 336872600, 337057950, 337243350, 337428800, 337614300, 337799850, 337985450, 338171100, 338356800, 338542550, 338728350, 338914200,
339100100, 339286050, 339472050, 339658100, 339844200, 340030350, 340216550, 340402800, 340589100, 340775450, 340961850, 341148300, 341334800, 341521350, 341707950, 341894600, 342081300, 342268050, 342454850,
342641700, 342828600, 343015550, 343202550, 343389600, 343576700, 343763850, 343951050, 344138300, 344325600, 344512950, 344700350, 344887800, 345075300, 345262850, 345450450, 345638100, 345825800, 346013550,
346201350, 346389200, 346577100, 346765050, 346953050, 347141100, 347329200, 347517350, 347705550, 347893800, 348082100, 348270450, 348458850, 348647300, 348835800, 349024350, 349212950, 349401600, 349590300,
349779050, 349967850, 350156700, 350345600, 350534550, 350723550, 350912600, 351101700, 351290850, 351480050, 351669300, 351858600, 352047950, 352237350, 352426800, 352616300, 352805850, 352995450, 353185100,
353374800, 353564550, 353754350, 353944200, 354134100, 354324050, 354514050, 354704100, 354894200, 355084350, 355274550, 355464800, 355655100, 355845450, 356035850, 356226300, 356416800, 356607350, 356797950,
356988600, 357179300, 357370050, 357560850, 357751700, 357942600, 358133550, 358324550, 358515600, 358706700, 358897850, 359089050, 359280300, 359471600, 359662950, 359854350, 360045800, 360237300, 360428850,
360620450, 360812100, 361003800, 361195550, 361387350, 361579200, 361771100, 361963050, 362155050, 362347100, 362539200, 362731350, 362923550, 363115800, 363308100, 363500450, 363692850, 363885300, 364077800,
364270350, 364462950, 364655600, 364848300, 365041050, 365233850, 365426700, 365619600, 365812550, 366005550, 366198600, 366391700, 366584850, 366778050, 366971300, 367164600, 367357950, 367551350, 367744800,
367938300, 368131850, 368325450, 368519100, 368712800, 368906550, 369100350, 369294200, 369488100, 369682050, 369876050, 370070100, 370264200, 370458350, 370652550, 370846800, 371041100, 371235450, 371429850,
371624300, 371818800, 372013350, 372207950, 372402600, 372597300, 372792050, 372986850, 373181700, 373376600, 373571550, 373766550, 373961600, 374156700, 374351850, 374547050, 374742300, 374937600, 375132950,
375328350, 375523800, 375719300, 375914850, 376110450, 376306100, 376501800, 376697550, 376893350, 377089200, 377285100, 377481050, 377677050, 377873100, 378069200, 378265350, 378461550, 378657800, 378854100,
379050450, 379246850, 379443300, 379639800, 379836350, 380032950, 380229600, 380426300, 380623050, 380819850, 381016700, 381213600, 381410550, 381607550, 381804600, 382001700, 382198850, 382396050, 382593300,
382790600, 382987950, 383185350, 383382800, 383580300, 383777850, 383975450, 384173100, 384370800, 384568550, 384766350, 384964200, 385162100, 385360050, 385558050, 385756100, 385954200, 386152350, 386350550,
386548800, 386747100, 386945450, 387143850, 387342300, 387540800, 387739350, 387937950, 388136600, 388335300, 388534050, 388732850, 388931700, 389130600, 389329550, 389528550, 389727600, 389926700, 390125850,
390325050, 390524300, 390723600, 390922950, 391122350, 391321800, 391521300, 391720850, 391920450, 392120100, 392319800, 392519550, 392719350, 392919200, 393119100, 393319050, 393519050, 393719100, 393919200,
394119350, 394319550, 394519800, 394720100, 394920450, 395120850, 395321300, 395521800, 395722350, 395922950, 396123600, 396324300, 396525050, 396725850, 396926700, 397127600, 397328550, 397529550, 397730600,
397931700, 398132850, 398334050, 398535300, 398736600, 398937950, 399139350, 399340800, 399542300, 399743850, 399945450, 400147100, 400348800, 400550550, 400752350, 400954200, 401156100, 401358050, 401560050,
401762100, 401964200, 402166350, 402368550, 402570800, 402773100, 402975450, 403177850, 403380300, 403582800, 403785350, 403987950, 404190600, 404393300, 404596050, 404798850, 405001700, 405204600, 405407550,
405610550, 405813600, 406016700, 406219850, 406423050, 406626300, 406829600, 407032950, 407236350, 407439800, 407643300, 407846850, 408050450, 408254100, 408457800, 408661550, 408865350, 409069200, 409273100,
409477050, 409681050, 409885100, 410089200, 410293350, 410497550, 410701800, 410906100, 411110450, 411314850, 411519300, 411723800, 411928350, 412132950, 412337600, 412542300, 412747050, 412951850, 413156700,
413361600, 413566550, 413771550, 413976600, 414181700, 414386850, 414592050, 414797300, 415002600, 415207950, 415413350, 415618800, 415824300, 416029850, 416235450, 416441100, 416646800, 416852550, 417058350,
417264200, 417470100, 417676050, 417882050, 418088100, 418294200, 418500350, 418706550, 418912800, 419119100, 419325450, 419531850, 419738300, 419944800, 420151350, 420357950, 420564600, 420771300, 420978050,
421184850, 421391700, 421598600, 421805550, 422012550, 422219600, 422426700, 422633850, 422841050, 423048300, 423255600, 423462950, 423670350, 423877800, 424085300, 424292850, 424500450, 424708100, 424915800,
425123550, 425331350, 425539200, 425747100, 425955050, 426163050, 426371100, 426579200, 426787350, 426995550, 427203800, 427412100, 427620450, 427828850, 428037300, 428245800, 428454350, 428662950, 428871600,
429080300, 429289050, 429497850, 429706700, 429915600, 430124550, 430333550, 430542600, 430751700, 430960850, 431170050, 431379300, 431588600, 431797950, 432007350, 432216800, 432426300, 432635850, 432845450,
433055100, 433264800, 433474550, 433684350, 433894200, 434104100, 434314050, 434524050, 434734100, 434944200, 435154350, 435364550, 435574800, 435785100, 435995450, 436205850, 436416300, 436626800, 436837350,
437047950, 437258600, 437469300, 437680050, 437890850, 438101700, 438312600, 438523550, 438734550, 438945600, 439156700, 439367850, 439579050, 439790300, 440001600, 440212950, 440424350, 440635800, 440847300,
441058850, 441270450, 441482100, 441693800, 441905550, 442117350, 442329200, 442541100, 442753050, 442965050, 443177100, 443389200, 443601350, 443813550, 444025800, 444238100, 444450450, 444662850, 444875300,
445087800, 445300350, 445512950, 445725600, 445938300, 446151050, 446363850, 446576700, 446789600, 447002550, 447215550, 447428600, 447641700, 447854850, 448068050, 448281300, 448494600, 448707950, 448921350,
449134800, 449348300, 449561850, 449775450, 449989100, 450202800, 450416550, 450630350, 450844200, 451058100, 451272050, 451486050, 451700100, 451914200, 452128350, 452342550, 452556800, 452771100, 452985450,
453199850, 453414300, 453628800, 453843350, 454057950, 454272600, 454487300, 454702050, 454916850, 455131700, 455346600, 455561550, 455776550, 455991600, 456206700, 456421850, 456637050, 456852300, 457067600,
457282950, 457498350, 457713800, 457929300, 458144850, 458360450, 458576100, 458791800, 459007550, 459223350, 459439200, 459655100, 459871050, 460087050, 460303100, 460519200, 460735350, 460951550, 461167800,
461384100, 461600450, 461816850, 462033300, 462249800, 462466350, 462682950, 462899600, 463116300, 463333050, 463549850, 463766700, 463983600, 464200550, 464417550, 464634600, 464851700, 465068850, 465286050,
465503300, 465720600, 465937950, 466155350, 466372800, 466590300, 466807850, 467025450, 467243100, 467460800, 467678550, 467896350, 468114200, 468332100, 468550050, 468768050, 468986100, 469204200, 469422350,
469640550, 469858800, 470077100, 470295450, 470513850, 470732300, 470950800, 471169350, 471387950, 471606600, 471825300, 472044050, 472262850, 472481700, 472700600, 472919550, 473138550, 473357600, 473576700,
473795850, 474015050, 474234300, 474453600, 474672950, 474892350, 475111800, 475331300, 475550850, 475770450, 475990100, 476209800, 476429550, 476649350, 476869200, 477089100, 477309050, 477529050, 477749100,
477969200, 478189350, 478409550, 478629800, 478850100, 479070450, 479290850, 479511300, 479731800, 479952350, 480172950, 480393600, 480614300, 480835050, 481055850, 481276700, 481497600, 481718550, 481939550, 
482160600, 482381700, 482602850, 482824050, 483045300, 483266600, 483487950, 483709350, 483930800, 484152300, 484373850, 484595450, 484817100, 485038800, 485260550, 485482350, 485704200, 485926100, 486148050, 
486370050, 486592100, 486814200, 487036350, 487258550, 487480800, 487703100, 487925450, 488147850, 488370300, 488592800, 488815350, 489037950, 489260600, 489483300, 489706050, 489928850, 490151700, 490374600, 
490597550, 490820550, 491043600, 491266700, 491489850, 491713050, 491936300, 492159600, 492382950, 492606350, 492829800, 493053300, 493276850, 493500450, 493724100, 493947800, 494171550, 494395350, 494619200, 
494843100, 495067050, 495291050, 495515100, 495739200, 495963350, 496187550, 496411800, 496636100, 496860450, 497084850, 497309300, 497533800, 497758350, 497982950, 498207600, 498432300, 498657050, 498881850, 
499106700, 499331600, 499556550, 499781550, 500006600, 500231700, 500456850, 500682050, 500907300, 501132600, 501357950, 501583350, 501808800, 502034300, 502259850, 502485450, 502711100, 502936800, 503162550, 
503388350, 503614200, 503840100, 504066050, 504292050, 504518100, 504744200, 504970350, 505196550, 505422800, 505649100, 505875450, 506101850, 506328300, 506554800, 506781350, 507007950, 507234600, 507461300, 
507688050, 507914850, 508141700, 508368600, 508595550, 508822550, 509049600, 509276700, 509503850, 509731050, 509958300, 510185600, 510412950, 510640350, 510867800, 511095300, 511322850, 511550450, 511778100, 
512005800, 512233550, 512461350, 512689200, 512917100, 513145050, 513373050, 513601100, 513829200, 514057350, 514285550, 514513800, 514742100, 514970450, 515198850, 515427300, 515655800, 515884350, 516112950, 
516341600, 516570300, 516799050, 517027850, 517256700, 517485600, 517714550, 517943550, 518172600, 518401700, 518630850, 518860050, 519089300, 519318600, 519547950, 519777350, 520006800, 520236300, 520465850, 
520695450, 520925100, 521154800, 521384550, 521614350, 521844200, 522074100, 522304050, 522534050, 522764100, 522994200, 523224350, 523454550, 523684800, 523915100, 524145450, 524375850, 524606300, 524836800, 
525067350, 525297950, 525528600, 525759300, 525990050, 526220850, 526451700, 526682600, 526913550, 527144550, 527375600, 527606700, 527837850, 528069050, 528300300, 528531600, 528762950, 528994350, 529225800, 
529457300, 529688850, 529920450, 530152100, 530383800, 530615550, 530847350, 531079200, 531311100, 531543050, 531775050, 532007100, 532239200, 532471350, 532703550, 532935800, 533168100, 533400450, 533632850, 
533865300, 534097800, 534330350, 534562950, 534795600, 535028300, 535261050, 535493850, 535726700, 535959600, 536192550, 536425550, 536658600, 536891700, 537124850, 537358050, 537591300, 537824600, 538057950, 
538291350, 538524800, 538758300, 538991850, 539225450, 539459100, 539692800, 539926550, 540160350, 540394200, 540628100, 540862050, 541096050, 541330100, 541564200, 541798350, 542032550, 542266800, 542501100, 
542735450, 542969850, 543204300, 543438800, 543673350, 543907950, 544142600, 544377300, 544612050, 544846850, 545081700, 545316600, 545551550, 545786550, 546021600, 546256700, 546491850, 546727050, 546962300, 
547197600, 547432950, 547668350, 547903800, 548139300, 548374850, 548610450, 548846100, 549081800, 549317550, 549553350, 549789200, 550025100, 550261050, 550497050, 550733100, 550969200, 551205350, 551441550, 
551677800, 551914100, 552150450, 552386850, 552623300, 552859800, 553096350, 553332950, 553569600, 553806300, 554043050, 554279850, 554516700, 554753600, 554990550, 555227550, 555464600, 555701700, 555938850, 
556176050, 556413300, 556650600, 556887950, 557125350, 557362800, 557600300, 557837850, 558075450, 558313100, 558550800, 558788550, 559026350, 559264200, 559502100, 559740050, 559978050, 560216100, 560454200, 
560692350, 560930550, 561168800, 561407100, 561645450, 561883850, 562122300, 562360800, 562599350, 562837950, 563076600, 563315300, 563554050, 563792850, 564031700, 564270600, 564509550, 564748550, 564987600, 
565226700, 565465850, 565705050, 565944300, 566183600, 566422950, 566662350, 566901800, 567141300, 567380850, 567620450, 567860100, 568099800, 568339550, 568579350, 568819200, 569059100, 569299050, 569539050, 
569779100, 570019200, 570259350, 570499550, 570739800, 570980100, 571220450, 571460850, 571701300, 571941800, 572182350, 572422950, 572663600, 572904300, 573145050, 573385850, 573626700, 573867600, 574108550, 
574349550, 574590600, 574831700, 575072850, 575314050, 575555300, 575796600, 576037950, 576279350, 576520800, 576762300, 577003850, 577245450, 577487100, 577728800, 577970550, 578212350, 578454200, 578696100, 
578938050, 579180050, 579422100, 579664200, 579906350, 580148550, 580390800, 580633100, 580875450, 581117850, 581360300, 581602800, 581845350, 582087950, 582330600, 582573300, 582816050, 583058850, 583301700, 
583544600, 583787550, 584030550, 584273600, 584516700, 584759850, 585003050, 585246300, 585489600, 585732950, 585976350, 586219800, 586463300, 586706850, 586950450, 587194100, 587437800, 587681550, 587925350, 
588169200, 588413100, 588657050, 588901050, 589145100, 589389200, 589633350, 589877550, 590121800, 590366100, 590610450, 590854850, 591099300, 591343800, 591588350, 591832950, 592077600, 592322300, 592567050, 
592811850, 593056700, 593301600, 593546550, 593791550, 594036600, 594281700, 594526850, 594772050, 595017300, 595262600, 595507950, 595753350, 595998800, 596244300, 596489850, 596735450, 596981100, 597226800, 
597472550, 597718350, 597964200, 598210100, 598456050, 598702050, 598948100, 599194200, 599440350, 599686550, 599932800, 600179100, 600425450, 600671850, 600918300, 601164800, 601411350, 601657950, 601904600, 
602151300, 602398050, 602644850, 602891700, 603138600, 603385550, 603632550, 603879600, 604126700, 604373850, 604621050, 604868300, 605115600, 605362950, 605610350, 605857800, 606105300, 606352850, 606600450, 
606848100, 607095800, 607343550, 607591350, 607839200, 608087100, 608335050, 608583050, 608831100, 609079200, 609327350, 609575550, 609823800, 610072100, 610320450, 610568850, 610817300, 611065800, 611314350, 611562950, 611811600, 612060300, 612309050, 612557850, 612806700, 613055600, 613304550, 613553550, 613802600, 614051700, 614300850, 614550050, 614799300, 615048600, 615297950, 615547350, 615796800, 616046300, 616295850, 616545450, 616795100, 617044800, 617294550, 617544350, 617794200, 618044100, 618294050, 618544050, 618794100, 619044200, 619294350, 619544550, 619794800, 620045100, 620295450, 620545850, 620796300, 621046800, 621297350, 621547950, 621798600, 622049300, 622300050, 622550850, 622801700, 623052600, 623303550, 623554550, 623805600, 624056700, 624307850, 624559050, 624810300, 625061600, 625312950, 625564350, 625815800, 626067300, 626318850, 626570450, 626822100, 627073800, 627325550, 627577350, 627829200, 628081100, 628333050, 628585050, 628837100, 629089200, 629341350, 629593550, 629845800, 630098100, 630350450, 630602850, 630855300, 631107800, 631360350, 631612950, 631865600, 632118300, 632371050, 632623850, 632876700, 633129600, 633382550, 633635550, 633888600, 634141700, 634394850, 634648050, 634901300, 635154600, 635407950, 635661350, 635914800, 636168300, 636421850, 636675450, 636929100, 637182800, 637436550, 637690350, 637944200, 638198100, 638452050, 638706050, 638960100, 639214200, 639468350, 639722550, 639976800, 640231100, 640485450, 640739850, 640994300, 641248800, 641503350, 641757950, 642012600, 642267300, 642522050, 642776850, 643031700, 643286600, 643541550, 643796550, 644051600, 644306700, 644561850, 644817050, 645072300, 645327600, 645582950, 645838350, 646093800, 646349300, 646604850, 646860450, 647116100, 647371800, 647627550, 647883350, 648139200, 648395100, 648651050, 648907050, 649163100, 649419200, 649675350, 649931550, 650187800, 650444100, 650700450, 650956850, 651213300, 651469800, 651726350, 651982950, 652239600, 652496300, 652753050, 653009850, 653266700, 653523600, 653780550, 654037550, 654294600, 654551700, 654808850, 655066050, 655323300, 655580600, 655837950, 656095350, 656352800, 656610300, 656867850, 657125450, 657383100, 657640800, 657898550, 658156350, 658414200, 658672100, 658930050, 659188050, 659446100, 659704200, 659962350, 660220550, 660478800, 660737100, 660995450, 661253850, 661512300, 661770800, 662029350, 662287950, 662546600, 662805300, 663064050, 663322850, 663581700, 663840600, 664099550, 664358550, 664617600, 664876700, 665135850, 665395050, 665654300, 665913600, 666172950, 666432350, 666691800, 666951300, 667210850, 667470450, 667730100, 667989800, 668249550, 668509350, 668769200, 669029100, 669289050, 669549050, 669809100, 670069200, 670329350, 670589550, 670849800, 671110100, 671370450, 671630850, 671891300, 672151800, 672412350, 672672950, 672933600, 673194300, 673455050, 673715850, 673976700, 674237600, 674498550, 674759550, 675020600, 675281700, 675542850, 675804050, 676065300, 676326600, 676587950, 676849350, 677110800, 677372300, 677633850, 677895450, 678157100, 678418800, 678680550, 678942350, 679204200, 679466100, 679728050, 679990050, 680252100, 680514200, 680776350, 681038550, 681300800, 681563100, 681825450, 682087850, 682350300, 682612800, 682875350, 683137950, 683400600, 683663300, 683926050, 684188850, 684451700, 684714600, 684977550, 685240550, 685503600, 685766700, 686029850, 686293050, 686556300, 686819600, 687082950, 687346350, 687609800, 687873300, 688136850, 688400450, 688664100, 688927800, 689191550, 689455350, 689719200, 689983100, 690247050, 690511050, 690775100, 691039200, 691303350, 691567550, 691831800, 692096100, 692360450, 692624850, 692889300, 693153800, 693418350, 693682950, 693947600, 694212300, 694477050, 694741850, 695006700, 695271600, 695536550, 695801550, 696066600, 696331700, 696596850, 696862050, 697127300, 697392600, 697657950, 697923350, 698188800, 698454300, 698719850, 698985450, 699251100, 699516800, 699782550, 700048350, 700314200, 700580100, 700846050, 701112050, 701378100, 701644200, 701910350, 702176550, 702442800, 702709100, 702975450, 703241850, 703508300, 703774800, 704041350, 704307950, 704574600, 704841300, 705108050, 705374850, 705641700, 705908600, 706175550, 706442550, 706709600, 706976700, 707243850, 707511050, 707778300, 708045600, 708312950, 708580350, 708847800, 709115300, 709382850, 709650450, 709918100, 710185800, 710453550, 710721350, 710989200, 711257100, 711525050, 711793050, 712061100, 712329200, 712597350, 712865550, 713133800, 713402100, 713670450, 713938850, 714207300, 714475800, 714744350, 715012950, 715281600, 715550300, 715819050, 716087850, 716356700, 716625600, 716894550, 717163550, 717432600, 717701700, 717970850, 718240050, 718509300, 718778600, 719047950, 719317350, 719586800, 719856300, 720125850, 720395450, 720665100, 720934800, 721204550, 721474350, 721744200, 722014100, 722284050, 722554050, 722824100, 723094200, 723364350, 723634550, 723904800, 724175100, 724445450, 724715850, 724986300, 725256800, 725527350, 725797950, 726068600, 726339300, 726610050, 726880850, 727151700, 727422600, 727693550, 727964550, 728235600, 728506700, 728777850, 729049050, 729320300, 729591600, 729862950, 730134350, 730405800, 730677300, 730948850, 731220450, 731492100, 731763800, 732035550, 732307350, 732579200, 732851100, 733123050, 733395050, 733667100, 733939200, 734211350, 734483550, 734755800, 735028100, 735300450, 735572850, 735845300, 736117800, 736390350, 736662950, 736935600, 737208300, 737481050, 737753850, 738026700, 738299600, 738572550, 738845550, 739118600, 739391700, 739664850, 739938050, 740211300, 740484600, 740757950, 741031350, 741304800, 741578300, 741851850, 742125450, 742399100, 742672800, 742946550, 743220350, 743494200, 743768100, 744042050, 744316050, 744590100, 744864200, 745138350, 745412550, 745686800, 745961100, 746235450, 746509850, 746784300, 747058800, 747333350, 747607950, 747882600, 748157300, 748432050, 748706850, 748981700, 749256600, 749531550, 749806550, 750081600, 750356700, 750631850, 750907050, 751182300, 751457600, 751732950, 752008350, 752283800, 752559300, 752834850, 753110450, 753386100, 753661800, 753937550, 754213350, 754489200, 754765100, 755041050, 755317050, 755593100, 755869200, 756145350, 756421550, 756697800, 756974100, 757250450, 757526850, 757803300, 758079800, 758356350, 758632950, 758909600, 759186300, 759463050, 759739850, 760016700, 760293600, 760570550, 760847550, 761124600, 761401700, 761678850, 761956050, 762233300, 762510600, 762787950, 763065350, 763342800, 763620300, 763897850, 764175450, 764453100, 764730800, 765008550, 765286350, 765564200, 765842100, 766120050, 766398050, 766676100, 766954200, 767232350, 767510550, 767788800, 768067100, 768345450, 768623850, 768902300, 769180800, 769459350, 769737950, 770016600, 770295300, 770574050, 770852850, 771131700, 771410600, 771689550, 771968550, 772247600, 772526700, 772805850, 773085050, 773364300, 773643600, 773922950, 774202350, 774481800, 774761300, 775040850, 775320450, 775600100, 775879800, 776159550, 776439350, 776719200, 776999100, 777279050, 777559050, 777839100, 778119200, 778399350, 778679550, 778959800, 779240100, 779520450, 779800850, 780081300, 780361800, 780642350, 780922950, 781203600, 781484300, 781765050, 782045850, 782326700, 782607600, 782888550, 783169550, 783450600, 783731700, 784012850, 784294050, 784575300, 784856600, 785137950, 785419350, 785700800, 785982300, 786263850, 786545450, 786827100, 787108800, 787390550, 787672350, 787954200, 788236100, 788518050, 788800050, 789082100, 789364200, 789646350, 789928550, 790210800, 790493100, 790775450, 791057850, 791340300, 791622800, 791905350, 792187950, 792470600, 792753300, 793036050, 793318850, 793601700, 793884600, 794167550, 794450550, 794733600, 795016700, 795299850, 795583050, 795866300, 796149600, 796432950, 796716350, 796999800, 797283300, 797566850, 797850450, 798134100, 798417800, 798701550, 798985350, 799269200, 799553100, 799837050, 800121050, 800405100, 800689200, 800973350, 801257550, 801541800, 801826100, 802110450, 802394850, 802679300, 802963800, 803248350, 803532950, 803817600, 804102300, 804387050, 804671850, 804956700, 805241600, 805526550, 805811550, 806096600, 806381700, 806666850, 806952050, 807237300, 807522600, 807807950, 808093350, 808378800, 808664300, 808949850, 809235450, 809521100, 809806800, 810092550, 810378350, 810664200, 810950100, 811236050, 811522050, 811808100, 812094200, 812380350, 812666550, 812952800, 813239100, 813525450, 813811850, 814098300, 814384800, 814671350, 814957950, 815244600, 815531300, 815818050, 816104850, 816391700, 816678600, 816965550, 817252550, 817539600, 817826700, 818113850, 818401050, 818688300, 818975600, 819262950, 819550350, 819837800, 820125300, 820412850, 820700450, 820988100, 821275800, 821563550, 821851350, 822139200, 822427100, 822715050, 823003050, 823291100, 823579200, 823867350, 824155550, 824443800, 824732100, 825020450, 825308850, 825597300, 825885800, 826174350, 826462950, 826751600, 827040300, 827329050, 827617850, 827906700, 828195600, 828484550, 828773550, 829062600, 829351700, 829640850, 829930050, 830219300, 830508600, 830797950, 831087350, 831376800, 831666300, 831955850, 832245450, 832535100, 832824800, 833114550, 833404350, 833694200, 833984100, 834274050, 834564050, 834854100, 835144200, 835434350, 835724550, 836014800, 836305100, 836595450, 836885850, 837176300, 837466800, 837757350, 838047950, 838338600, 838629300, 838920050, 839210850, 839501700, 839792600, 840083550, 840374550, 840665600, 840956700, 841247850, 841539050, 841830300, 842121600, 842412950, 842704350, 842995800, 843287300, 843578850, 843870450, 844162100, 844453800, 844745550, 845037350, 845329200, 845621100, 845913050, 846205050, 846497100, 846789200, 847081350, 847373550, 847665800, 847958100, 848250450, 848542850, 848835300, 849127800, 849420350, 849712950, 850005600, 850298300, 850591050, 850883850, 851176700, 851469600, 851762550, 852055550, 852348600, 852641700, 852934850, 853228050, 853521300, 853814600, 854107950, 854401350, 854694800, 854988300, 855281850, 855575450, 855869100, 856162800, 856456550, 856750350, 857044200, 857338100, 857632050, 857926050, 858220100, 858514200, 858808350, 859102550, 859396800, 859691100, 859985450, 860279850, 860574300, 860868800, 861163350, 861457950, 861752600, 862047300, 862342050, 862636850, 862931700, 863226600, 863521550, 863816550, 864111600, 864406700, 864701850, 864997050, 865292300, 865587600, 865882950, 866178350, 866473800, 866769300, 867064850, 867360450, 867656100, 867951800, 868247550, 868543350, 868839200, 869135100, 869431050, 869727050, 870023100, 870319200, 870615350, 870911550, 871207800, 871504100, 871800450, 872096850, 872393300, 872689800, 872986350, 873282950, 873579600, 873876300, 874173050, 874469850, 874766700, 875063600, 875360550, 875657550, 875954600, 876251700, 876548850, 876846050, 877143300, 877440600, 877737950, 878035350, 878332800, 878630300, 878927850, 879225450, 879523100, 879820800, 880118550, 880416350, 880714200, 881012100, 881310050, 881608050, 881906100, 882204200, 882502350, 882800550, 883098800, 883397100, 883695450, 883993850, 884292300, 884590800, 884889350, 885187950, 885486600, 885785300, 886084050, 886382850, 886681700, 886980600, 887279550, 887578550, 887877600, 888176700, 888475850, 888775050, 889074300, 889373600, 889672950, 889972350, 890271800, 890571300, 890870850, 891170450, 891470100, 891769800, 892069550, 892369350, 892669200, 892969100, 893269050, 893569050, 893869100, 894169200, 894469350, 894769550, 895069800, 895370100, 895670450, 895970850, 896271300, 896571800, 896872350, 897172950, 897473600, 897774300, 898075050, 898375850, 898676700, 898977600, 899278550, 899579550, 899880600, 900181700, 900482850, 900784050, 901085300, 901386600, 901687950, 901989350, 902290800, 902592300, 902893850, 903195450, 903497100, 903798800, 904100550, 904402350, 904704200, 905006100, 905308050, 905610050, 905912100, 906214200, 906516350, 906818550, 907120800, 907423100, 907725450, 908027850, 908330300, 908632800, 908935350, 909237950, 909540600, 909843300, 910146050, 910448850, 910751700, 911054600, 911357550, 911660550, 911963600, 912266700, 912569850, 912873050, 913176300, 913479600, 913782950, 914086350, 914389800, 914693300, 914996850, 915300450, 915604100, 915907800, 916211550, 916515350, 916819200, 917123100, 917427050, 917731050, 918035100, 918339200, 918643350, 918947550, 919251800, 919556100, 919860450, 920164850, 920469300, 920773800, 921078350, 921382950, 921687600, 921992300, 922297050, 922601850, 922906700, 923211600, 923516550, 923821550, 924126600, 924431700, 924736850, 925042050, 925347300, 925652600, 925957950, 926263350, 926568800, 926874300, 927179850, 927485450, 927791100, 928096800, 928402550, 928708350, 929014200, 929320100, 929626050, 929932050, 930238100, 930544200, 930850350, 931156550, 931462800, 931769100, 932075450, 932381850, 932688300, 932994800, 933301350, 933607950, 933914600, 934221300, 934528050, 934834850, 935141700, 935448600, 935755550, 936062550, 936369600, 936676700, 936983850, 937291050, 937598300, 937905600, 938212950, 938520350, 938827800, 939135300, 939442850, 939750450, 940058100, 940365800, 940673550, 940981350, 941289200, 941597100, 941905050, 942213050, 942521100, 942829200, 943137350, 943445550, 943753800, 944062100, 944370450, 944678850, 944987300, 945295800, 945604350, 945912950, 946221600, 946530300, 946839050, 947147850, 947456700, 947765600, 948074550, 948383550, 948692600, 949001700, 949310850, 949620050, 949929300, 950238600, 950547950, 950857350, 951166800, 951476300, 951785850, 952095450, 952405100, 952714800, 953024550, 953334350, 953644200, 953954100, 954264050, 954574050, 954884100, 955194200, 955504350, 955814550, 956124800, 956435100, 956745450, 957055850, 957366300, 957676800, 957987350, 958297950, 958608600, 958919300, 959230050, 959540850, 959851700, 960162600, 960473550, 960784550, 961095600, 961406700, 961717850, 962029050, 962340300, 962651600, 962962950, 963274350, 963585800, 963897300, 964208850, 964520450, 964832100, 965143800, 965455550, 965767350, 966079200, 966391100, 966703050, 967015050, 967327100, 967639200, 967951350, 968263550, 968575800, 968888100, 969200450, 969512850, 969825300, 970137800, 970450350, 970762950, 971075600, 971388300, 971701050, 972013850, 972326700, 972639600, 972952550, 973265550, 973578600, 973891700, 974204850, 974518050, 974831300, 975144600, 975457950, 975771350, 976084800, 976398300, 976711850, 977025450, 977339100, 977652800, 977966550, 978280350, 978594200, 978908100, 979222050, 979536050, 979850100, 980164200, 980478350, 980792550, 981106800, 981421100, 981735450, 982049850, 982364300, 982678800, 982993350, 983307950, 983622600, 983937300, 984252050, 984566850, 984881700, 985196600, 985511550, 985826550, 986141600, 986456700, 986771850, 987087050, 987402300, 987717600, 988032950, 988348350, 988663800, 988979300, 989294850, 989610450, 989926100, 990241800, 990557550, 990873350, 991189200, 991505100, 991821050, 992137050, 992453100, 992769200, 993085350, 993401550, 993717800, 994034100, 994350450, 994666850, 994983300, 995299800, 995616350, 995932950, 996249600, 996566300, 996883050, 997199850, 997516700, 997833600, 998150550, 998467550, 998784600, 999101700, 999418850, 999736050, 1000053300, 1000370600, 1000687950, 1001005350, 1001322800, 1001640300, 1001957850, 1002275450, 1002593100, 1002910800, 1003228550, 1003546350, 1003864200, 1004182100, 1004500050, 1004818050, 1005136100, 1005454200, 1005772350, 1006090550, 1006408800, 1006727100, 1007045450, 1007363850, 1007682300, 1008000800, 1008319350, 1008637950, 1008956600, 1009275300, 1009594050, 1009912850, 1010231700, 1010550600, 1010869550, 1011188550, 1011507600, 1011826700, 1012145850, 1012465050, 1012784300, 1013103600, 1013422950, 1013742350, 1014061800, 1014381300, 1014700850, 1015020450, 1015340100, 1015659800, 1015979550, 1016299350, 1016619200, 1016939100, 1017259050, 1017579050, 1017899100, 1018219200, 1018539350, 1018859550, 1019179800, 1019500100, 1019820450, 1020140850, 1020461300, 1020781800, 1021102350, 1021422950, 1021743600, 1022064300, 1022385050, 1022705850, 1023026700, 1023347600, 1023668550, 1023989550, 1024310600, 1024631700, 1024952850, 1025274050, 1025595300, 1025916600, 1026237950, 1026559350, 1026880800, 1027202300, 1027523850, 1027845450, 1028167100, 1028488800, 1028810550, 1029132350, 1029454200, 1029776100, 1030098050, 1030420050, 1030742100, 1031064200, 1031386350, 1031708550, 1032030800, 1032353100, 1032675450, 1032997850, 1033320300, 1033642800, 1033965350, 1034287950, 1034610600, 1034933300, 1035256050, 1035578850, 1035901700, 1036224600, 1036547550, 1036870550, 1037193600, 1037516700, 1037839850, 1038163050, 1038486300, 1038809600, 1039132950, 1039456350, 1039779800, 1040103300, 1040426850, 1040750450, 1041074100, 1041397800, 1041721550, 1042045350, 1042369200, 1042693100, 1043017050, 1043341050, 1043665100, 1043989200, 1044313350, 1044637550, 1044961800, 1045286100, 1045610450, 1045934850, 1046259300, 1046583800, 1046908350, 1047232950, 1047557600, 1047882300, 1048207050, 1048531850, 1048856700, 1049181600, 1049506550, 1049831550, 1050156600, 1050481700, 1050806850, 1051132050, 1051457300, 1051782600, 1052107950, 1052433350, 1052758800, 1053084300, 1053409850, 1053735450, 1054061100, 1054386800, 1054712550, 1055038350, 1055364200, 1055690100, 1056016050, 1056342050, 1056668100, 1056994200, 1057320350, 1057646550, 1057972800, 1058299100, 1058625450, 1058951850, 1059278300, 1059604800, 1059931350, 1060257950, 1060584600, 1060911300, 1061238050, 1061564850, 1061891700, 1062218600, 1062545550, 1062872550, 1063199600, 1063526700, 1063853850, 1064181050, 1064508300, 1064835600, 1065162950, 1065490350, 1065817800, 1066145300, 1066472850, 1066800450, 1067128100, 1067455800, 1067783550, 1068111350, 1068439200, 1068767100, 1069095050, 1069423050, 1069751100, 1070079200, 1070407350, 1070735550, 1071063800, 1071392100, 1071720450, 1072048850, 1072377300, 1072705800, 1073034350, 1073362950, 1073691600, 1074020300, 1074349050, 1074677850, 1075006700, 1075335600, 1075664550, 1075993550, 1076322600, 1076651700, 1076980850, 1077310050, 1077639300, 1077968600, 1078297950, 1078627350, 1078956800, 1079286300, 1079615850, 1079945450, 1080275100, 1080604800, 1080934550, 1081264350, 1081594200, 1081924100, 1082254050, 1082584050, 1082914100, 1083244200, 1083574350, 1083904550, 1084234800, 1084565100, 1084895450, 1085225850, 1085556300, 1085886800, 1086217350, 1086547950, 1086878600, 1087209300, 1087540050, 1087870850, 1088201700, 1088532600, 1088863550, 1089194550, 1089525600, 1089856700, 1090187850, 1090519050, 1090850300, 1091181600, 1091512950, 1091844350, 1092175800, 1092507300, 1092838850, 1093170450, 1093502100, 1093833800, 1094165550, 1094497350, 1094829200, 1095161100, 1095493050, 1095825050, 1096157100, 1096489200, 1096821350, 1097153550, 1097485800, 1097818100, 1098150450, 1098482850, 1098815300, 1099147800, 1099480350, 1099812950, 1100145600, 1100478300, 1100811050, 1101143850, 1101476700, 1101809600, 1102142550, 1102475550, 1102808600, 1103141700, 1103474850, 1103808050, 1104141300, 1104474600, 1104807950, 1105141350, 1105474800, 1105808300, 1106141850, 1106475450, 1106809100, 1107142800, 1107476550, 1107810350, 1108144200, 1108478100, 1108812050, 1109146050, 1109480100, 1109814200, 1110148350, 1110482550, 1110816800, 1111151100, 1111485450, 1111819850, 1112154300, 1112488800, 1112823350, 1113157950, 1113492600, 1113827300, 1114162050, 1114496850, 1114831700, 1115166600, 1115501550, 1115836550, 1116171600, 1116506700, 1116841850, 1117177050, 1117512300, 1117847600, 1118182950, 1118518350, 1118853800, 1119189300, 1119524850, 1119860450, 1120196100, 1120531800, 1120867550, 1121203350, 1121539200, 1121875100, 1122211050, 1122547050, 1122883100, 1123219200, 1123555350, 1123891550, 1124227800, 1124564100, 1124900450, 1125236850, 1125573300, 1125909800, 1126246350, 1126582950, 1126919600, 1127256300, 1127593050, 1127929850, 1128266700, 1128603600, 1128940550, 1129277550, 1129614600, 1129951700, 1130288850, 1130626050, 1130963300, 1131300600, 1131637950, 1131975350, 1132312800, 1132650300, 1132987850, 1133325450, 1133663100, 1134000800, 1134338550, 1134676350, 1135014200, 1135352100, 1135690050, 1136028050, 1136366100, 1136704200, 1137042350, 1137380550, 1137718800, 1138057100, 1138395450, 1138733850, 1139072300, 1139410800, 1139749350, 1140087950, 1140426600, 1140765300, 1141104050, 1141442850, 1141781700, 1142120600, 1142459550, 1142798550, 1143137600, 1143476700, 1143815850, 1144155050, 1144494300, 1144833600, 1145172950, 1145512350, 1145851800, 1146191300, 1146530850, 1146870450, 1147210100, 1147549800, 1147889550, 1148229350, 1148569200, 1148909100, 1149249050, 1149589050, 1149929100, 1150269200, 1150609350, 1150949550, 1151289800, 1151630100, 1151970450, 1152310850, 1152651300, 1152991800, 1153332350, 1153672950, 1154013600, 1154354300, 1154695050, 1155035850, 1155376700, 1155717600, 1156058550, 1156399550, 1156740600, 1157081700, 1157422850, 1157764050, 1158105300, 1158446600, 1158787950, 1159129350, 1159470800, 1159812300, 1160153850, 1160495450, 1160837100, 1161178800, 1161520550, 1161862350, 1162204200, 1162546100, 1162888050, 1163230050, 1163572100, 1163914200, 1164256350, 1164598550, 1164940800, 1165283100, 1165625450, 1165967850, 1166310300, 1166652800, 1166995350, 1167337950, 1167680600, 1168023300, 1168366050, 1168708850, 1169051700, 1169394600, 1169737550, 1170080550, 1170423600, 1170766700, 1171109850, 1171453050, 1171796300, 1172139600, 1172482950, 1172826350, 1173169800, 1173513300, 1173856850, 1174200450, 1174544100, 1174887800, 1175231550, 1175575350, 1175919200, 1176263100, 1176607050, 1176951050, 1177295100, 1177639200, 1177983350, 1178327550, 1178671800, 1179016100, 1179360450, 1179704850, 1180049300, 1180393800, 1180738350, 1181082950, 1181427600, 1181772300, 1182117050, 1182461850, 1182806700, 1183151600, 1183496550, 1183841550, 1184186600, 1184531700, 1184876850, 1185222050, 1185567300, 1185912600, 1186257950, 1186603350, 1186948800, 1187294300, 1187639850, 1187985450, 1188331100, 1188676800, 1189022550, 1189368350, 1189714200, 1190060100, 1190406050, 1190752050, 1191098100, 1191444200, 1191790350, 1192136550, 1192482800, 1192829100, 1193175450, 1193521850, 1193868300, 1194214800, 1194561350, 1194907950, 1195254600, 1195601300, 1195948050, 1196294850, 1196641700, 1196988600, 1197335550, 1197682550, 1198029600, 1198376700, 1198723850, 1199071050, 1199418300, 1199765600, 1200112950, 1200460350, 1200807800, 1201155300, 1201502850, 1201850450, 1202198100, 1202545800, 1202893550, 1203241350, 1203589200, 1203937100, 1204285050, 1204633050, 1204981100, 1205329200, 1205677350, 1206025550, 1206373800, 1206722100, 1207070450, 1207418850, 1207767300, 1208115800, 1208464350, 1208812950, 1209161600, 1209510300, 1209859050, 1210207850, 1210556700, 1210905600, 1211254550, 1211603550, 1211952600, 1212301700, 1212650850, 1213000050, 1213349300, 1213698600, 1214047950, 1214397350, 1214746800, 1215096300, 1215445850, 1215795450, 1216145100, 1216494800, 1216844550, 1217194350, 1217544200, 1217894100, 1218244050, 1218594050, 1218944100, 1219294200, 1219644350, 1219994550, 1220344800, 1220695100, 1221045450, 1221395850, 1221746300, 1222096800, 1222447350, 1222797950, 1223148600, 1223499300, 1223850050, 1224200850, 1224551700, 1224902600, 1225253550, 1225604550, 1225955600, 1226306700, 1226657850, 1227009050, 1227360300, 1227711600, 1228062950, 1228414350, 1228765800, 1229117300, 1229468850, 1229820450, 1230172100, 1230523800, 1230875550, 1231227350, 1231579200, 1231931100, 1232283050, 1232635050, 1232987100, 1233339200, 1233691350, 1234043550, 1234395800, 1234748100, 1235100450, 1235452850, 1235805300, 1236157800, 1236510350, 1236862950, 1237215600, 1237568300, 1237921050, 1238273850, 1238626700, 1238979600, 1239332550, 1239685550, 1240038600, 1240391700, 1240744850, 1241098050, 1241451300, 1241804600, 1242157950, 1242511350, 1242864800, 1243218300, 1243571850, 1243925450, 1244279100, 1244632800, 1244986550, 1245340350, 1245694200, 1246048100, 1246402050, 1246756050, 1247110100, 1247464200, 1247818350, 1248172550, 1248526800, 1248881100, 1249235450, 1249589850, 1249944300, 1250298800, 1250653350, 1251007950, 1251362600, 1251717300, 1252072050, 1252426850, 1252781700, 1253136600, 1253491550, 1253846550, 1254201600, 1254556700, 1254911850, 1255267050, 1255622300, 1255977600, 1256332950, 1256688350, 1257043800, 1257399300, 1257754850, 1258110450, 1258466100, 1258821800, 1259177550, 1259533350, 1259889200, 1260245100, 1260601050, 1260957050, 1261313100, 1261669200, 1262025350, 1262381550, 1262737800, 1263094100, 1263450450, 1263806850, 1264163300, 1264519800, 1264876350, 1265232950, 1265589600, 1265946300, 1266303050, 1266659850, 1267016700, 1267373600, 1267730550, 1268087550, 1268444600, 1268801700, 1269158850, 1269516050, 1269873300, 1270230600, 1270587950, 1270945350, 1271302800, 1271660300, 1272017850, 1272375450, 1272733100, 1273090800, 1273448550, 1273806350, 1274164200, 1274522100, 1274880050, 1275238050, 1275596100, 1275954200, 1276312350, 1276670550, 1277028800, 1277387100, 1277745450, 1278103850, 1278462300, 1278820800, 1279179350, 1279537950, 1279896600, 1280255300, 1280614050, 1280972850, 1281331700, 1281690600, 1282049550, 1282408550, 1282767600, 1283126700, 1283485850, 1283845050, 1284204300, 1284563600, 1284922950, 1285282350, 1285641800, 1286001300, 1286360850, 1286720450, 1287080100, 1287439800, 1287799550, 1288159350, 1288519200, 1288879100, 1289239050, 1289599050, 1289959100, 1290319200, 1290679350, 1291039550, 1291399800, 1291760100, 1292120450, 1292480850, 1292841300, 1293201800, 1293562350, 1293922950, 1294283600, 1294644300, 1295005050, 1295365850, 1295726700, 1296087600, 1296448550, 1296809550, 1297170600, 1297531700, 1297892850, 1298254050, 1298615300, 1298976600, 1299337950, 1299699350, 1300060800, 1300422300, 1300783850, 1301145450, 1301507100, 1301868800, 1302230550, 1302592350, 1302954200, 1303316100, 1303678050, 1304040050, 1304402100, 1304764200, 1305126350, 1305488550, 1305850800, 1306213100, 1306575450, 1306937850, 1307300300, 1307662800, 1308025350, 1308387950, 1308750600, 1309113300, 1309476050, 1309838850, 1310201700, 1310564600, 1310927550, 1311290550, 1311653600, 1312016700, 1312379850, 1312743050, 1313106300, 1313469600, 1313832950, 1314196350, 1314559800, 1314923300, 1315286850, 1315650450, 1316014100, 1316377800, 1316741550, 1317105350, 1317469200, 1317833100, 1318197050, 1318561050, 1318925100, 1319289200, 1319653350, 1320017550, 1320381800, 1320746100, 1321110450, 1321474850, 1321839300, 1322203800, 1322568350, 1322932950, 1323297600, 1323662300, 1324027050, 1324391850, 1324756700, 1325121600, 1325486550, 1325851550, 1326216600, 1326581700, 1326946850, 1327312050, 1327677300, 1328042600, 1328407950, 1328773350, 1329138800, 1329504300, 1329869850, 1330235450, 1330601100, 1330966800, 1331332550, 1331698350, 1332064200, 1332430100, 1332796050, 1333162050, 1333528100, 1333894200, 1334260350, 1334626550, 1334992800, 1335359100, 1335725450, 1336091850, 1336458300, 1336824800, 1337191350, 1337557950, 1337924600, 1338291300, 1338658050, 1339024850, 1339391700, 1339758600, 1340125550, 1340492550, 1340859600, 1341226700, 1341593850, 1341961050, 1342328300, 1342695600, 1343062950, 1343430350, 1343797800, 1344165300, 1344532850, 1344900450, 1345268100, 1345635800, 1346003550, 1346371350, 1346739200, 1347107100, 1347475050, 1347843050, 1348211100, 1348579200, 1348947350, 1349315550, 1349683800, 1350052100, 1350420450, 1350788850, 1351157300, 1351525800, 1351894350, 1352262950, 1352631600, 1353000300, 1353369050, 1353737850, 1354106700, 1354475600, 1354844550, 1355213550, 1355582600, 1355951700, 1356320850, 1356690050, 1357059300, 1357428600, 1357797950, 1358167350, 1358536800, 1358906300, 1359275850, 1359645450, 1360015100, 1360384800, 1360754550, 1361124350, 1361494200, 1361864100, 1362234050, 1362604050, 1362974100, 1363344200, 1363714350, 1364084550, 1364454800, 1364825100, 1365195450, 1365565850, 1365936300, 1366306800, 1366677350, 1367047950, 1367418600, 1367789300, 1368160050, 1368530850, 1368901700, 1369272600, 1369643550, 1370014550, 1370385600, 1370756700, 1371127850, 1371499050, 1371870300, 1372241600, 1372612950, 1372984350, 1373355800, 1373727300, 1374098850, 1374470450, 1374842100, 1375213800, 1375585550, 1375957350, 1376329200, 1376701100, 1377073050, 1377445050, 1377817100, 1378189200, 1378561350, 1378933550, 1379305800, 1379678100, 1380050450, 1380422850, 1380795300, 1381167800, 1381540350, 1381912950, 1382285600, 1382658300, 1383031050, 1383403850, 1383776700, 1384149600, 1384522550, 1384895550, 1385268600, 1385641700, 1386014850, 1386388050, 1386761300, 1387134600, 1387507950, 1387881350, 1388254800, 1388628300, 1389001850, 1389375450, 1389749100, 1390122800, 1390496550, 1390870350, 1391244200, 1391618100, 1391992050, 1392366050, 1392740100, 1393114200, 1393488350, 1393862550, 1394236800, 1394611100, 1394985450, 1395359850, 1395734300, 1396108800, 1396483350, 1396857950, 1397232600, 1397607300, 1397982050, 1398356850, 1398731700, 1399106600, 1399481550, 1399856550, 1400231600, 1400606700, 1400981850, 1401357050, 1401732300, 1402107600, 1402482950, 1402858350, 1403233800, 1403609300, 1403984850, 1404360450, 1404736100, 1405111800, 1405487550, 1405863350, 1406239200, 1406615100, 1406991050, 1407367050, 1407743100, 1408119200, 1408495350, 1408871550, 1409247800, 1409624100, 1410000450, 1410376850, 1410753300, 1411129800, 1411506350, 1411882950, 1412259600, 1412636300, 1413013050, 1413389850, 1413766700, 1414143600, 1414520550, 1414897550, 1415274600, 1415651700, 1416028850, 1416406050, 1416783300, 1417160600, 1417537950, 1417915350, 1418292800, 1418670300, 1419047850, 1419425450, 1419803100, 1420180800, 1420558550, 1420936350, 1421314200, 1421692100, 1422070050, 1422448050, 1422826100, 1423204200, 1423582350, 1423960550, 1424338800, 1424717100, 1425095450, 1425473850, 1425852300, 1426230800, 1426609350, 1426987950, 1427366600, 1427745300, 1428124050, 1428502850, 1428881700, 1429260600, 1429639550, 1430018550, 1430397600, 1430776700, 1431155850, 1431535050, 1431914300, 1432293600, 1432672950, 1433052350, 1433431800, 1433811300, 1434190850, 1434570450, 1434950100, 1435329800, 1435709550, 1436089350, 1436469200, 1436849100, 1437229050, 1437609050, 1437989100, 1438369200, 1438749350, 1439129550, 1439509800, 1439890100, 1440270450, 1440650850, 1441031300, 1441411800, 1441792350, 1442172950, 1442553600, 1442934300, 1443315050, 1443695850, 1444076700, 1444457600, 1444838550, 1445219550, 1445600600, 1445981700, 1446362850, 1446744050, 1447125300, 1447506600, 1447887950, 1448269350, 1448650800, 1449032300, 1449413850, 1449795450, 1450177100, 1450558800, 1450940550, 1451322350, 1451704200, 1452086100, 1452468050, 1452850050, 1453232100, 1453614200, 1453996350, 1454378550, 1454760800, 1455143100, 1455525450, 1455907850, 1456290300, 1456672800, 1457055350, 1457437950, 1457820600, 1458203300, 1458586050, 1458968850, 1459351700, 1459734600, 1460117550, 1460500550, 1460883600, 1461266700, 1461649850, 1462033050, 1462416300, 1462799600, 1463182950, 1463566350, 1463949800, 1464333300, 1464716850, 1465100450, 1465484100, 1465867800, 1466251550, 1466635350, 1467019200, 1467403100, 1467787050, 1468171050, 1468555100, 1468939200, 1469323350, 1469707550, 1470091800, 1470476100, 1470860450, 1471244850, 1471629300, 1472013800, 1472398350, 1472782950, 1473167600, 1473552300, 1473937050, 1474321850, 1474706700, 1475091600, 1475476550, 1475861550, 1476246600, 1476631700, 1477016850, 1477402050, 1477787300, 1478172600, 1478557950, 1478943350, 1479328800, 1479714300, 1480099850, 1480485450, 1480871100, 1481256800, 1481642550, 1482028350, 1482414200, 1482800100, 1483186050, 1483572050, 1483958100, 1484344200, 1484730350, 1485116550, 1485502800, 1485889100, 1486275450, 1486661850, 1487048300, 1487434800, 1487821350, 1488207950, 1488594600, 1488981300, 1489368050, 1489754850, 1490141700, 1490528600, 1490915550, 1491302550, 1491689600, 1492076700, 1492463850, 1492851050, 1493238300, 1493625600, 1494012950, 1494400350, 1494787800, 1495175300, 1495562850, 1495950450, 1496338100, 1496725800, 1497113550, 1497501350, 1497889200, 1498277100, 1498665050, 1499053050, 1499441100, 1499829200, 1500217350, 1500605550, 1500993800, 1501382100, 1501770450, 1502158850, 1502547300, 1502935800, 1503324350, 1503712950, 1504101600, 1504490300, 1504879050, 1505267850, 1505656700, 1506045600, 1506434550, 1506823550, 1507212600, 1507601700, 1507990850, 1508380050, 1508769300, 1509158600, 1509547950, 1509937350, 1510326800, 1510716300, 1511105850, 1511495450, 1511885100, 1512274800, 1512664550, 1513054350, 1513444200, 1513834100, 1514224050, 1514614050, 1515004100, 1515394200, 1515784350, 1516174550, 1516564800, 1516955100, 1517345450, 1517735850, 1518126300, 1518516800, 1518907350, 1519297950, 1519688600, 1520079300, 1520470050, 1520860850, 1521251700, 1521642600, 1522033550, 1522424550, 1522815600, 1523206700, 1523597850, 1523989050, 1524380300, 1524771600, 1525162950, 1525554350, 1525945800, 1526337300, 1526728850, 1527120450, 1527512100, 1527903800, 1528295550, 1528687350, 1529079200, 1529471100, 1529863050, 1530255050, 1530647100, 1531039200, 1531431350, 1531823550, 1532215800, 1532608100, 1533000450, 1533392850, 1533785300, 1534177800, 1534570350, 1534962950, 1535355600, 1535748300, 1536141050, 1536533850, 1536926700, 1537319600, 1537712550, 1538105550, 1538498600, 1538891700, 1539284850, 1539678050, 1540071300, 1540464600, 1540857950, 1541251350, 1541644800, 1542038300, 1542431850, 1542825450, 1543219100, 1543612800, 1544006550, 1544400350, 1544794200, 1545188100, 1545582050, 1545976050, 1546370100, 1546764200, 1547158350, 1547552550, 1547946800, 1548341100, 1548735450, 1549129850, 1549524300, 1549918800, 1550313350, 1550707950, 1551102600, 1551497300, 1551892050, 1552286850, 1552681700, 1553076600, 1553471550, 1553866550, 1554261600, 1554656700, 1555051850, 1555447050, 1555842300, 1556237600, 1556632950, 1557028350, 1557423800, 1557819300, 1558214850, 1558610450, 1559006100, 1559401800, 1559797550, 1560193350, 1560589200, 1560985100, 1561381050, 1561777050, 1562173100, 1562569200, 1562965350, 1563361550, 1563757800, 1564154100, 1564550450, 1564946850, 1565343300, 1565739800, 1566136350, 1566532950, 1566929600, 1567326300, 1567723050, 1568119850, 1568516700, 1568913600, 1569310550, 1569707550, 1570104600, 1570501700, 1570898850, 1571296050, 1571693300, 1572090600, 1572487950, 1572885350, 1573282800, 1573680300, 1574077850, 1574475450, 1574873100, 1575270800, 1575668550, 1576066350, 1576464200, 1576862100, 1577260050, 1577658050, 1578056100, 1578454200, 1578852350, 1579250550, 1579648800, 1580047100, 1580445450, 1580843850, 1581242300, 1581640800, 1582039350, 1582437950, 1582836600, 1583235300, 1583634050, 1584032850, 1584431700, 1584830600, 1585229550, 1585628550, 1586027600, 1586426700, 1586825850, 1587225050, 1587624300, 1588023600, 1588422950, 1588822350, 1589221800, 1589621300, 1590020850, 1590420450, 1590820100, 1591219800, 1591619550, 1592019350, 1592419200, 1592819100, 1593219050, 1593619050, 1594019100, 1594419200, 1594819350, 1595219550, 1595619800, 1596020100, 1596420450, 1596820850, 1597221300, 1597621800, 1598022350, 1598422950, 1598823600, 1599224300, 1599625050, 1600025850, 1600426700, 1600827600, 1601228550, 1601629550, 1602030600, 1602431700, 1602832850, 1603234050, 1603635300, 1604036600, 1604437950, 1604839350, 1605240800, 1605642300, 1606043850, 1606445450, 1606847100, 1607248800, 1607650550, 1608052350, 1608454200, 1608856100, 1609258050, 1609660050, 1610062100, 1610464200, 1610866350, 1611268550, 1611670800, 1612073100, 1612475450, 1612877850, 1613280300, 1613682800, 1614085350, 1614487950, 1614890600, 1615293300, 1615696050, 1616098850, 1616501700, 1616904600, 1617307550, 1617710550, 1618113600, 1618516700, 1618919850, 1619323050, 1619726300, 1620129600, 1620532950, 1620936350, 1621339800, 1621743300, 1622146850, 1622550450, 1622954100, 1623357800, 1623761550, 1624165350, 1624569200, 1624973100, 1625377050, 1625781050, 1626185100, 1626589200, 1626993350, 1627397550, 1627801800, 1628206100, 1628610450, 1629014850, 1629419300, 1629823800, 1630228350, 1630632950, 1631037600, 1631442300, 1631847050, 1632251850, 1632656700, 1633061600, 1633466550, 1633871550, 1634276600, 1634681700, 1635086850, 1635492050, 1635897300, 1636302600, 1636707950, 1637113350, 1637518800, 1637924300, 1638329850, 1638735450, 1639141100, 1639546800, 1639952550, 1640358350, 1640764200, 1641170100, 1641576050, 1641982050, 1642388100, 1642794200, 1643200350, 1643606550, 1644012800, 1644419100, 1644825450, 1645231850, 1645638300, 1646044800, 1646451350, 1646857950, 1647264600, 1647671300, 1648078050, 1648484850, 1648891700, 1649298600, 1649705550, 1650112550, 1650519600, 1650926700, 1651333850, 1651741050, 1652148300, 1652555600, 1652962950, 1653370350, 1653777800, 1654185300, 1654592850, 1655000450, 1655408100, 1655815800, 1656223550, 1656631350, 1657039200, 1657447100, 1657855050, 1658263050, 1658671100, 1659079200, 1659487350, 1659895550, 1660303800, 1660712100, 1661120450, 1661528850, 1661937300, 1662345800, 1662754350, 1663162950, 1663571600, 1663980300, 1664389050, 1664797850, 1665206700, 1665615600, 1666024550, 1666433550, 1666842600, 1667251700, 1667660850, 1668070050, 1668479300, 1668888600, 1669297950, 1669707350, 1670116800, 1670526300, 1670935850, 1671345450, 1671755100, 1672164800, 1672574550, 1672984350, 1673394200, 1673804100, 1674214050, 1674624050, 1675034100, 1675444200, 1675854350, 1676264550, 1676674800, 1677085100, 1677495450, 1677905850, 1678316300, 1678726800, 1679137350, 1679547950, 1679958600, 1680369300, 1680780050, 1681190850, 1681601700, 1682012600, 1682423550, 1682834550, 1683245600, 1683656700, 1684067850, 1684479050, 1684890300, 1685301600, 1685712950, 1686124350, 1686535800, 1686947300, 1687358850, 1687770450, 1688182100, 1688593800, 1689005550, 1689417350, 1689829200, 1690241100, 1690653050, 1691065050, 1691477100, 1691889200, 1692301350, 1692713550, 1693125800, 1693538100, 1693950450, 1694362850, 1694775300, 1695187800, 1695600350, 1696012950, 1696425600, 1696838300, 1697251050, 1697663850, 1698076700, 1698489600, 1698902550, 1699315550, 1699728600, 1700141700, 1700554850, 1700968050, 1701381300, 1701794600, 1702207950, 1702621350, 1703034800, 1703448300, 1703861850, 1704275450, 1704689100, 1705102800, 1705516550, 1705930350, 1706344200, 1706758100, 1707172050, 1707586050, 1708000100, 1708414200, 1708828350, 1709242550, 1709656800, 1710071100, 1710485450, 1710899850, 1711314300, 1711728800, 1712143350, 1712557950, 1712972600, 1713387300, 1713802050, 1714216850, 1714631700, 1715046600, 1715461550, 1715876550, 1716291600, 1716706700, 1717121850, 1717537050, 1717952300, 1718367600, 1718782950, 1719198350, 1719613800, 1720029300, 1720444850, 1720860450, 1721276100, 1721691800, 1722107550, 1722523350, 1722939200, 1723355100, 1723771050, 1724187050, 1724603100, 1725019200, 1725435350, 1725851550, 1726267800, 1726684100, 1727100450, 1727516850, 1727933300, 1728349800, 1728766350, 1729182950, 1729599600, 1730016300, 1730433050, 1730849850, 1731266700, 1731683600, 1732100550, 1732517550, 1732934600, 1733351700, 1733768850, 1734186050, 1734603300, 1735020600, 1735437950, 1735855350, 1736272800, 1736690300, 1737107850, 1737525450, 1737943100, 1738360800, 1738778550, 1739196350, 1739614200, 1740032100, 1740450050, 1740868050, 1741286100, 1741704200, 1742122350, 1742540550, 1742958800, 1743377100, 1743795450, 1744213850, 1744632300, 1745050800, 1745469350, 1745887950, 1746306600, 1746725300, 1747144050, 1747562850, 1747981700, 1748400600, 1748819550, 1749238550, 1749657600, 1750076700, 1750495850, 1750915050, 1751334300, 1751753600, 1752172950, 1752592350, 1753011800, 1753431300, 1753850850, 1754270450, 1754690100, 1755109800, 1755529550, 1755949350, 1756369200, 1756789100, 1757209050, 1757629050, 1758049100, 1758469200, 1758889350, 1759309550, 1759729800, 1760150100, 1760570450, 1760990850, 1761411300, 1761831800, 1762252350, 1762672950, 1763093600, 1763514300, 1763935050, 1764355850, 1764776700, 1765197600, 1765618550, 1766039550, 1766460600, 1766881700, 1767302850, 1767724050, 1768145300, 1768566600, 1768987950, 1769409350, 1769830800, 1770252300, 1770673850, 1771095450, 1771517100, 1771938800, 1772360550, 1772782350, 1773204200, 1773626100, 1774048050, 1774470050, 1774892100, 1775314200, 1775736350, 1776158550, 1776580800, 1777003100, 1777425450, 1777847850, 1778270300, 1778692800, 1779115350, 1779537950, 1779960600, 1780383300, 1780806050, 1781228850, 1781651700, 1782074600, 1782497550, 1782920550, 1783343600, 1783766700, 1784189850, 1784613050, 1785036300, 1785459600, 1785882950, 1786306350, 1786729800, 1787153300, 1787576850 };






//superpowers
bool Features::poweranimated = false;
bool Features::killpedsbool = false;
void Features::killpeds(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) != peds[OffsetID])
		{
			PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false);
		}
	}
	if (Features::poweranimated)
	{
		char *dict = "rcmcollect_paperleadinout@";
		char *anim = "meditiate_idle";
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
	}
}

bool Features::explodepedsbool = false;
void Features::explodepeds(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) != peds[OffsetID])
		{
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], false);
			FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 60, 3000.f, true, false, 1.f);
			PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false);

		}
	}
	if (Features::poweranimated)
	{
		char *dict = "rcmcollect_paperleadinout@";
		char *anim = "meditiate_idle";
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
	}
}

bool Features::explodenearbyvehiclesbool = false;
void Features::explodenearbyvehicles(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], false);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 60, 10000.f, true, false, 0.f);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehs[OffsetID], "Aztral");
		}
		if (Features::poweranimated)
		{
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		}
	}
	delete vehs;
}
bool Features::ForceWavebool = false;
void Features::ForceWave(bool toggle)
{

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if ((veh[offsettedID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false)))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, INT_MAX, 0, 0, 0, 0, 1, true, true, true, false, true);
				if (Features::poweranimated)
				{
					char *dict = "rcmcollect_paperleadinout@";
					char *anim = "meditiate_idle";
					STREAMING::REQUEST_ANIM_DICT(dict);
					AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
				}
				}
		}
	}
}

bool Features::magnetpedsbool1 = false;
void Features::magnetpeds1(bool toggle)
{
	float offset;
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(selectedplayer, 0.0, -10.0, 0.0);

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(selectedplayer, veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if ((veh[offsettedID] != PED::GET_VEHICLE_PED_IS_IN(selectedplayer, false)) && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{

				float head = ENTITY::GET_ENTITY_HEADING(selectedplayer);

				ENTITY::SET_ENTITY_HEADING(veh[offsettedID], head);

				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh[offsettedID]);
				ENTITY::SET_ENTITY_VISIBLE(veh[offsettedID], true, 0);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 100, 0, 0, 0, 0, 1, true, true, true, false, true);
			}
		}
	}
}

bool Features::purgebool = false;
void Features::purge(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	Ped *peds1 = new Ped[ArrSize];
	peds1[0] = ElementAmount;

	Hash PEDGROUP = GAMEPLAY::GET_HASH_KEY("COUGAR");

	

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		Hash thispedgroup = PED::GET_PED_RELATIONSHIP_GROUP_HASH(peds[OffsetID]);
		if (thispedgroup != PEDGROUP)
		{
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()) != peds[OffsetID])
			{
				PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(peds[OffsetID], true);
				//PED::SET_PED_AS_COP(peds[OffsetID], true);

				//AI::TASK_COMBAT_HATED_TARGETS_AROUND_PED(peds[OffsetID], 100.f, 0);

				PED::SET_PED_RELATIONSHIP_GROUP_HASH(peds[OffsetID], PEDGROUP);
				AI::TASK_COMBAT_PED(peds[OffsetID], peds[OffsetID], 0, 16);

				ENTITY::SET_ENTITY_INVINCIBLE(peds[OffsetID], true);
				PED::SET_PED_COMBAT_MOVEMENT(peds[OffsetID], 3);
				PED::SET_PED_ARMOUR(peds[OffsetID], 100);
				PED::SET_PED_ACCURACY(peds[OffsetID], 100);
				PED::SET_PED_COMBAT_ABILITY(peds[OffsetID], 100);
				WEAPON::GIVE_WEAPON_TO_PED(peds[OffsetID], GAMEPLAY::GET_HASH_KEY("WEAPON_MINISMG"), 9999, false, true);
				PED::SET_PED_CAN_SWITCH_WEAPON(peds[OffsetID], true);
				PED::SET_PED_ALERTNESS(peds[OffsetID], 1000);
				PED::SET_PED_COMBAT_RANGE(peds[OffsetID], 1000);



			}
		}
	}
}

bool Features::deletenearbyvehiclesbool = false;
void Features::deletenearbyvehicles(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			ENTITY::_SET_ENTITY_COORDS_2(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
		}
	}
	if (Features::poweranimated)
	{
		char *dict = "rcmcollect_paperleadinout@";
		char *anim = "meditiate_idle";
		STREAMING::REQUEST_ANIM_DICT(dict);
		AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
	}
	delete vehs;
}
//bool Features::PotatosMassacurebool;
void Features::PotatosMassacure()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	float tempCoords1[3];
	DWORD tempVehicle;
	DWORD tempPed;
	int rndped[1000];
	int gcount = 1;
	int gogiberry = 1;
		//lets blow up vehicles
		Features::explodenearbyvehicles(true);
		// lets kick away the closest vehicle
		tempVehicle = VEHICLE::GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
		if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(tempVehicle, INT_MAX);
		//lets blow up the peds
		//Features::explodepeds(true);
//lets make some OP ass zombies

		if (gogiberry > 5)
		goto penis;
	else
		gogiberry++;
		Hash pedm = GAMEPLAY::GET_HASH_KEY("a_f_m_fatcult_01");
		Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
		Hash weapon = GAMEPLAY::GET_HASH_KEY("-656458692");
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Hooking::request_model(pedm);
		while (!Hooking::has_model_loaded(pedm))
			WAIT(0);
		rndped[gcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(rndped[gcount], true);
		PED::SET_PED_COMBAT_ABILITY(rndped[gcount], 100);
		WEAPON::GIVE_WEAPON_TO_PED(rndped[gcount], -656458692, -656458692, 9999, 9999);
		PED::SET_PED_CAN_SWITCH_WEAPON(rndped[gcount], true);
		AI::TASK_COMBAT_PED(rndped[gcount], playerPed, 1, 1);
		PED::SET_PED_ALERTNESS(rndped[gcount], 1000);
		PED::SET_PED_COMBAT_RANGE(rndped[gcount], 1000);
		gcount++;	
	penis:
			// Water hydrants
			FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], 13, 8.0f, 1, 0, 3.0f);

		if (Features::poweranimated)
		{
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		}
}

bool Features::fatbitchesbool;
void Features::fatbitches(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	float tempCoords1[3];
	DWORD tempVehicle;
	DWORD tempPed;
	int rndped[1000];
	int gcount = 1;
	int bitches = 1;
	tempVehicle = VEHICLE::GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
	if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) ENTITY::APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 0, INT_MAX, 0, 0, 0, 0, 1, true, true, true, false, true);
	bitches++;
	Hash pedm = GAMEPLAY::GET_HASH_KEY("a_f_m_fatcult_01");
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
	Hash weapon = GAMEPLAY::GET_HASH_KEY("WEAPON_AUTOSHOTGUN");
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
	Hooking::request_model(pedm);
	while (!Hooking::has_model_loaded(pedm))
		WAIT(0);
	rndped[gcount] = PED::CREATE_PED(29, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
	PED::SET_PED_AS_COP(rndped[gcount], true);
	PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(rndped[gcount]), PED::GET_PED_RELATIONSHIP_GROUP_HASH(playerPed));
	ENTITY::SET_ENTITY_INVINCIBLE(rndped[gcount], true);
	PED::SET_PED_COMBAT_MOVEMENT(rndped[gcount], 3);
	PED::SET_PED_ARMOUR(rndped[gcount], 100);
	PED::SET_PED_ACCURACY(rndped[gcount], 100);
	PED::SET_PED_COMBAT_ABILITY(rndped[gcount], 100);
	WEAPON::GIVE_WEAPON_TO_PED(rndped[gcount], weapon, 9999, false, true);
	PED::SET_PED_CAN_SWITCH_WEAPON(rndped[gcount], true);
	AI::TASK_COMBAT_PED(rndped[gcount], playerPed, 1, 1);
	PED::SET_PED_ALERTNESS(rndped[gcount], 1000);
	PED::SET_PED_COMBAT_RANGE(rndped[gcount], 1000);
	gcount++;
}
void Features::fatbitches2()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	float tempCoords1[3];
	DWORD tempVehicle;
	DWORD tempPed;
	int rndped[1000];
	int gcount = 1;
	int bitches = 1;
	tempVehicle = VEHICLE::GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
	if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) ENTITY::APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 0, INT_MAX, 0, 0, 0, 0, 1, true, true, true, false, true);

	while (bitches < 50)
	{
		bitches++;
		Hash pedm = GAMEPLAY::GET_HASH_KEY("a_f_m_fatcult_01");
		Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
		Hash weapon = GAMEPLAY::GET_HASH_KEY("WEAPON_AUTOSHOTGUN");
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Hooking::request_model(pedm);
		while (!Hooking::has_model_loaded(pedm))
			WAIT(0);
		rndped[gcount] = PED::CREATE_PED(29, pedm, pos.x + rand() % 5, pos.y + rand() % 5, pos.z + 5, 0, 1, 1);
		PED::SET_PED_AS_COP(rndped[gcount], true);
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(rndped[gcount]), PED::GET_PED_RELATIONSHIP_GROUP_HASH(playerPed));
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(selectedplayer), PED::GET_PED_RELATIONSHIP_GROUP_HASH(rndped[gcount]));
		ENTITY::SET_ENTITY_INVINCIBLE(rndped[gcount], true);
		PED::SET_PED_COMBAT_MOVEMENT(rndped[gcount], 3);
		PED::SET_PED_ARMOUR(rndped[gcount], 100);
		PED::SET_PED_ACCURACY(rndped[gcount], 100);
		PED::SET_PED_COMBAT_ABILITY(rndped[gcount], 100);
		WEAPON::GIVE_WEAPON_TO_PED(rndped[gcount], weapon, 9999, false, true);
		PED::SET_PED_CAN_SWITCH_WEAPON(rndped[gcount], true);
		AI::TASK_COMBAT_PED(rndped[gcount], playerPed, 1, 1);
		PED::SET_PED_ALERTNESS(rndped[gcount], 1000);
		PED::SET_PED_COMBAT_RANGE(rndped[gcount], 1000);
		gcount++;
	}
}

void Features::fatbitches3()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	float tempCoords1[3];
	DWORD tempVehicle;
	DWORD tempPed;
	int rndped[1000];
	int gcount = 1;
	int bitches = 1;
	tempVehicle = VEHICLE::GET_CLOSEST_VEHICLE(tempCoords1[0], tempCoords1[1], tempCoords1[2], 400.0f, 0, 4);
	if (ENTITY::DOES_ENTITY_EXIST(tempVehicle)) ENTITY::APPLY_FORCE_TO_ENTITY(tempVehicle, 1, 0, INT_MAX, 0, 0, 0, 0, 1, true, true, true, false, true);

	while (bitches < 50)
	{
		bitches++;
		Hash pedm = GAMEPLAY::GET_HASH_KEY("a_f_y_topless_01");
		Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
		Hash weapon = GAMEPLAY::GET_HASH_KEY("WEAPON_AUTOSHOTGUN");
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		Hooking::request_model(pedm);
		while (!Hooking::has_model_loaded(pedm))
			WAIT(0);
		rndped[gcount] = PED::CREATE_PED(29, pedm, pos.x + rand() % 5, pos.y + rand() % 5, pos.z + 5, 0, 1, 1);
		PED::SET_PED_AS_COP(rndped[gcount], true);
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(rndped[gcount]), PED::GET_PED_RELATIONSHIP_GROUP_HASH(playerPed));
		PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(selectedplayer), PED::GET_PED_RELATIONSHIP_GROUP_HASH(rndped[gcount]));
		ENTITY::SET_ENTITY_INVINCIBLE(rndped[gcount], true);
		PED::SET_PED_COMBAT_MOVEMENT(rndped[gcount], 3);
		PED::SET_PED_ARMOUR(rndped[gcount], 100);
		PED::SET_PED_ACCURACY(rndped[gcount], 100);
		PED::SET_PED_COMBAT_ABILITY(rndped[gcount], 100);
		WEAPON::GIVE_WEAPON_TO_PED(rndped[gcount], weapon, 9999, false, true);
		PED::SET_PED_CAN_SWITCH_WEAPON(rndped[gcount], true);
		AI::TASK_COMBAT_PED(rndped[gcount], playerPed, 1, 1);
		PED::SET_PED_ALERTNESS(rndped[gcount], 1000);
		PED::SET_PED_COMBAT_RANGE(rndped[gcount], 1000);
		gcount++;
	}
}

bool Features::angrypedsbool = false;
void Features::angrypeds(bool toggle)
{
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	Hash weapon = GAMEPLAY::GET_HASH_KEY("WEAPON_MINISMG");
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;

	
	if (angrypedsbool)
	{
		int PedFound = PED::GET_PED_NEARBY_PEDS(selectedplayer, peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && selectedplayer != peds[OffsetID])
			{
				AI::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(peds[OffsetID], true);
				PED::SET_PED_FLEE_ATTRIBUTES(peds[OffsetID], 0, 0);
				PED::SET_PED_COMBAT_ATTRIBUTES(peds[OffsetID], 17, 1);
				AI::TASK_VEHICLE_CHASE(peds[OffsetID], selectedplayer);
				AI::SET_DRIVE_TASK_DRIVING_STYLE(peds[OffsetID], 16777216);
				PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(peds[OffsetID]), PED::GET_PED_RELATIONSHIP_GROUP_HASH(selectedplayer));
				PED::SET_RELATIONSHIP_BETWEEN_GROUPS(5, PED::GET_PED_RELATIONSHIP_GROUP_HASH(selectedplayer), PED::GET_PED_RELATIONSHIP_GROUP_HASH(peds[OffsetID]));
				//AI::TASK_GO_TO_ENTITY(peds[OffsetID], selectedplayer, 50000, 0, 100, 1073741824, 1);
				PED::SET_PED_COMBAT_ABILITY(peds[OffsetID], 100);
				WEAPON::GIVE_WEAPON_TO_PED(peds[OffsetID], weapon, 9999, false, true);
				PED::SET_PED_CAN_SWITCH_WEAPON(peds[OffsetID], true);
				AI::TASK_COMBAT_PED(peds[OffsetID], selectedplayer, 1, 1);
				PED::SET_PED_ALERTNESS(peds[OffsetID], 1000);
				PED::SET_PED_COMBAT_RANGE(peds[OffsetID], 1000);
			}
		}
	}
}

bool Features::magnetpedsbool = false;
void Features::magnetpeds(bool toggle)
{
	float offset;
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	
	Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(selectedplayer, 0.0, -10.0, 0.0);

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(selectedplayer, veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if ((veh[offsettedID] != PED::GET_VEHICLE_PED_IS_IN(selectedplayer, false)) && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{

				float head = ENTITY::GET_ENTITY_HEADING(selectedplayer);

				ENTITY::SET_ENTITY_HEADING(veh[offsettedID], head);

				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh[offsettedID]);
				ENTITY::SET_ENTITY_VISIBLE(veh[offsettedID], true, 0);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, INT_MAX, 0, 0, 0, 0, 1, true, true, true, false, true);
			}
		}
	}
}
bool Features::forcefieldbool = false;
void Features::forcefield(bool toggle)
{
	float offset;
	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	
	Vector3 pCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(selectedplayer, 0.0, -10.0, 0.0);

	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	int count = PED::GET_PED_NEARBY_VEHICLES(selectedplayer, veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if ((veh[offsettedID] != PED::GET_VEHICLE_PED_IS_IN(selectedplayer, false)) && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{

				float head = ENTITY::GET_ENTITY_HEADING(selectedplayer);

				Vector3 pos = ENTITY::GET_ENTITY_COORDS(veh[offsettedID], 0);
				Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 0);
				Vector3 playerPos_pos = sub(pos, playerPos);
				float	x = playerPos_pos.x < 0.f ? playerPos_pos.x * -1.f : playerPos_pos.x,
						y = playerPos_pos.y < 0.f ? playerPos_pos.y * -1.f : playerPos_pos.y;
				float	ratio = 100.f / (x > y ? x : y);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, playerPos_pos.x * ratio, playerPos_pos.y * ratio, ENTITY::IS_ENTITY_A_PED(veh[offsettedID]) ? 20.f : 5.f, (float)rndInt(-5, 5), (float)rndInt(-5, 5), (float)rndInt(-5, 5), 0, false, 1, true, 0, 1);
			}
		}
	}
	Ped *peds = new Ped[arrSize];
	peds[0] = numElements;

	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		Entity ent = peds[OffsetID];
		RequestControlOfEnt(ent);
		if (ent != NULL && ENTITY::IS_AN_ENTITY(ent) && ent != selectedplayer)
		{
			float head = ENTITY::GET_ENTITY_HEADING(selectedplayer);

			Vector3 pos = ENTITY::GET_ENTITY_COORDS(ent, 0);
			Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 0);
			Vector3 playerPos_pos = sub(pos, playerPos);
			float	x = playerPos_pos.x < 0.f ? playerPos_pos.x * -1.f : playerPos_pos.x,
				y = playerPos_pos.y < 0.f ? playerPos_pos.y * -1.f : playerPos_pos.y;
			float	ratio = 100.f / (x > y ? x : y);
			ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, playerPos_pos.x * ratio, playerPos_pos.y * ratio, ENTITY::IS_ENTITY_A_PED(ent) ? 20.f : 5.f, (float)rndInt(-5, 5), (float)rndInt(-5, 5), (float)rndInt(-5, 5), 0, false, 1, true, 0, 1);
		}
	}
}

bool Features::Upgradecarsbool = false;
void Features::Upgradecars(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			VEHICLE::SET_VEHICLE_MOD_KIT(vehs[OffsetID], 0);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_MOD(vehs[OffsetID], i, VEHICLE::GET_NUM_VEHICLE_MODS(vehs[OffsetID], i) - 1, false);
			}
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehs[OffsetID], 108, 0, 0);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehs[OffsetID], 255, 255, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehs[OffsetID], "Aztral");
		}
		if (Features::poweranimated)
		{
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		}
	}
	delete vehs;
}

bool Features::Rainbowcarbool = false;
void Features::Rainbowcar(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(vehs[OffsetID], rand() % 255, rand() % 255, rand() % 255);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(vehs[OffsetID], rand() % 255, rand() % 255, rand() % 255);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehs[OffsetID], "Aztral");
		}
		if (Features::poweranimated)
		{
			char *dict = "rcmcollect_paperleadinout@";
			char *anim = "meditiate_idle";
			STREAMING::REQUEST_ANIM_DICT(dict);
			AI::TASK_PLAY_ANIM(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), dict, anim, 1, 1, -1, 16, 0, false, 0, false);
		}
	}
	delete vehs;
}

//Weapon Options

bool Features::fireammo = false;
bool Features::expammo = false;
bool Features::rbgun = false;

Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}
bool Features::superpunchbool = false;
void Features::superpunch() {
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 100000.0);
	PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PLAYER::PLAYER_ID(), 100000.0);
}
bool Features::rapidfirer = false;
void Features::rapidmaker() {
	Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1)) {
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
		Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
		Hash weaponhash;
		WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
		if ((GetKeyState(VK_LBUTTON) & 0x8000)) {
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
		}
	}
}


void Features::Fireammos(bool toggle) {
	byte flag = Memory::get_value<byte>({ OFFSET_PLAYER, 0x10B8, 0x1F9 });
	if (fireammo) flag += 0x32;
	Memory::set_value<byte>({ OFFSET_PLAYER, 0x10B8, 0x1F9 }, flag);

}

void Features::Expammos(bool toggle) {
	byte flag = Memory::get_value<byte>({ OFFSET_PLAYER, 0x10B8, 0x1F9 });
	if (expammo) flag += 0x64;
	Memory::set_value<byte>({ OFFSET_PLAYER, 0x10B8, 0x1F9 }, flag);//16
}

void Features::RBGuner(bool toggle) {
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "WEAPON_PISTOL_MK2", "WEAPON_SMG_MK2",
		"WEAPON_ASSAULTRIFLE_MK2", "WEAPON_CARBINERIFLE_MK2", "WEAPON_COMBATMG_MK2", "WEAPON_HEAVYSNIPER_MK2"
	};
	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
	{
		if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), rand() % 8);
		}
	}
}


bool Features::infammo = false;
bool Features::freezed[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Freezer(Player target) {
	Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Hooking::clear_ped_tasks_immediately(vic);
	AI::CLEAR_PED_TASKS(vic);
	AI::CLEAR_PED_SECONDARY_TASK(vic);
}

void Features::noreloadv(bool toggle) {
	Hash cur;
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), &cur, 1))
	{
		if (WEAPON::IS_WEAPON_VALID(cur))
		{
			int maxAmmo;
			if (WEAPON::GET_MAX_AMMO(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), cur, &maxAmmo))
			{
				WEAPON::SET_PED_AMMO(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), cur, maxAmmo);

				maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), cur, 1);
				if (maxAmmo > 0)
					WEAPON::SET_AMMO_IN_CLIP(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), cur, maxAmmo);
			}
		}
	}
}
//Self Options
bool Features::fastrunbool = false;
void Features::fastrun(bool toggle)
{
	if (!fastrunbool)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 2.5);
	}
}

bool Features::fastswimbool = false;
void Features::fastswim(bool toggle)
{
	if (!fastswimbool)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 2.5);
	}
}




bool Features::Godmodebool = false;
void Features::Godmode(bool toggle)
{
	if (Godmodebool)
	{
		BYTE Setter = 1;
		Memory::set_value<bool>({ 0x08, 0x189 }, Setter);
	}
	else
	{
		BYTE Setter = 0;
		Memory::set_value<bool>({ 0x08, 0x189 }, Setter);
	}
}

bool Features::SemiGodModebool = false;
void Features::SemiGodMode(bool toggle)
{
	if (SemiGodModebool == true && !PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))
	{
		PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PLAYER::PLAYER_ID(), 100.f);
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
}
bool Features::Gettiny = false;
void Features::Smallstuff(bool toggle)
{
	PED::SET_PED_CONFIG_FLAG(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 223, toggle);
}

//xd i used the declaration from fuctions yeet
void Features::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}
int Features::attachobj[100];
int Features::nuattach = 1;
void Features::attachobjects2(char* object)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
	hash = GAMEPLAY::GET_HASH_KEY(object);
	if (Hooking::is_model_in_cdimage(hash))
	{
		if (Hooking::is_model_valid(hash))
		{
			Hooking::request_model(hash);
			if (Hooking::has_model_loaded(hash))
			{
				Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
				{
					Vector3 defpos;
					defpos.x = 0.f;
					defpos.y = -.37f;
					defpos.z = -.2f;
					Vector3 defrot;
					defrot.x = 60.f;
					defrot.y = 0.f;
					defrot.z = 0.f;
					attach_entities(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), -1, defpos, defrot);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}
}

char* forbidden_object[] =
{
	"cj_arrow_icon","cj_arrow_icon_2","cj_cone","cj_cylinder","cj_ring_icon_2","cj_r_icon_flag","mk_arrow","mk_arrow_flat","mk_cone","mk_cylinder","mk_flag","mk_ring","cj_parachute","gb_cap_use","gb_specs_use","des_cropduster_end","des_cropduster_root001","des_cropduster_root002","des_cropduster_root003","des_cropduster_root004","des_cropduster_root005","des_cropduster_start","des_fbowl_end","des_fbowl_root","des_fbowl_start","des_door_rig_root_skel","cj_parachute","gb_cap_use","gb_specs_use","cj_proc_tin2","proc_coral_01","proc_fern_02","proc_trolley_lakebed","prop_bush_gorse_dry","prop_bush_gorse_lush","prop_sapling_01","v_corp_banktrolley","v_corp_bk_balustrade","v_corp_bk_bust","v_corp_bk_chair1","v_corp_bk_chair2","v_corp_bk_filecab","v_corp_bk_filedraw","v_corp_bk_flag","v_corp_bk_lamp1","v_corp_bk_lamp2","v_corp_bk_lflts","v_corp_bk_lfltstand","v_corp_bk_pens","v_corp_bk_rolladex","v_corp_bk_secpanel","v_corp_bombbin","v_corp_bombhum","v_corp_bombplant","v_corp_boxpapr1fd","v_corp_boxpaprfd","v_corp_cabshelves01","v_corp_cashpack","v_corp_cashtrolley","v_corp_cashtrolley_2","v_corp_cd_desklamp","v_corp_cd_heater","v_corp_cd_intercom","v_corp_cd_pen","v_corp_cd_poncho","v_corp_cd_recseat","v_corp_cd_rectable","v_corp_cd_wellies","v_corp_conftable","v_corp_conftable2","v_corp_conftable3","v_corp_conftable4","v_corp_cubiclefd","v_corp_deskdraw","v_corp_deskdrawdark01","v_corp_deskdrawfd","v_corp_deskseta","v_corp_desksetb","v_corp_divide","v_corp_facebeanbag","v_corp_facebeanbagb","v_corp_facebeanbagc","v_corp_facebeanbagd","v_corp_filecabdark01","v_corp_filecabdark02","v_corp_filecabdark03","v_corp_filecablow","v_corp_filecabtall","v_corp_filecabtall_01","v_corp_hicksdoor","v_corp_humidifier","v_corp_lazychair","v_corp_lazychairfd","v_corp_lidesk01","v_corp_lngestool","v_corp_lngestoolfd","v_corp_lowcabdark01","v_corp_maindesk","v_corp_maindeskfd","v_corp_offchairfd","v_corp_officedesk","v_corp_officedesk003","v_corp_officedesk004","v_corp_officedesk1","v_corp_officedesk2","v_corp_officedesk_5","v_corp_offshelf","v_corp_offshelfclo","v_corp_offshelfdark","v_corp_partitionfd","v_corp_plants","v_corp_postbox","v_corp_postboxa","v_corp_post_open","v_corp_potplant1","v_corp_potplant2","v_corp_servercln","v_corp_servercln2","v_corp_servers1","v_corp_servers2","v_corp_servrlowfd","v_corp_servrtwrfd","v_corp_sidechair","v_corp_sidechairfd","v_corp_sidetable","v_corp_sidetblefd","v_corp_srvrrackfd","v_corp_srvrtwrsfd","v_corp_tallcabdark01","v_corp_trolley_fd","v_ind_bin_01","v_ind_cfbin","v_ind_cfbucket","v_ind_cfcovercrate","v_ind_cfemlight","v_ind_cfknife","v_ind_cflight","v_ind_cflight02","v_ind_cfpaste","v_ind_cfscoop","v_ind_cftable","v_ind_cftray","v_ind_cftub","v_ind_cfwaste","v_ind_cf_bollard","v_ind_cf_broom","v_ind_cf_bugzap","v_ind_cf_paltruck","v_ind_cf_shelf","v_ind_cf_shelf2","v_ind_cf_wheat","v_ind_cf_wheat2","v_ind_chickensx3","v_ind_cm_aircomp","v_ind_cm_crowbar","v_ind_cm_electricbox","v_ind_cm_fan","v_ind_cm_grinder","v_ind_cm_heatlamp","v_ind_cm_hosereel","v_ind_cm_ladder","v_ind_cm_light_off","v_ind_cm_light_on","v_ind_cm_paintbckt01","v_ind_cm_paintbckt02","v_ind_cm_paintbckt03","v_ind_cm_paintbckt04","v_ind_cm_paintbckt06","v_ind_cm_panelstd","v_ind_cm_sprgun","v_ind_cm_tyre01","v_ind_cm_tyre02","v_ind_cm_tyre03","v_ind_cm_tyre04","v_ind_cm_tyre05","v_ind_cm_tyre06","v_ind_cm_tyre07","v_ind_cm_tyre08","v_ind_cs_axe","v_ind_cs_blowtorch","v_ind_cs_bucket","v_ind_cs_chemcan","v_ind_cs_drill","v_ind_cs_gascanister","v_ind_cs_hammer","v_ind_cs_hifi","v_ind_cs_hubcap","v_ind_cs_jerrycan01","v_ind_cs_mallet","v_ind_cs_oiltin","v_ind_cs_pliers","v_ind_cs_powersaw","v_ind_cs_screwdrivr1","v_ind_cs_screwdrivr2","v_ind_cs_screwdrivr3","v_ind_cs_spanner01","v_ind_cs_spanner02","v_ind_cs_spanner03","v_ind_cs_spanner04","v_ind_cs_striplight","v_ind_cs_toolbox2","v_ind_cs_toolbox3","v_ind_cs_toolbox4","v_ind_cs_tray04","v_ind_cs_wrench","v_ind_dc_desk03","v_ind_dc_filecab01","v_ind_dc_table","v_ind_fatbox","v_ind_meatbench","v_ind_meatbox","v_ind_meatboxsml","v_ind_meatboxsml_02","v_ind_meatbutton","v_ind_meatclner","v_ind_meatcoatblu","v_ind_meatcoatwhte","v_ind_meatcpboard","v_ind_meatdesk","v_ind_meatdogpack","v_ind_meatexit","v_ind_meathatblu","v_ind_meathatwht","v_ind_meatpacks","v_ind_meatpacks_03","v_ind_meattherm","v_ind_meatwash","v_ind_meatwellie","v_ind_meat_comm","v_ind_plazbags","v_ind_rc_balec1","v_ind_rc_balec2","v_ind_rc_balec3","v_ind_rc_balep1","v_ind_rc_balep2","v_ind_rc_balep3","v_ind_rc_bench","v_ind_rc_brush","v_ind_rc_cage","v_ind_rc_dustmask","v_ind_rc_fans","v_ind_rc_hanger","v_ind_rc_locker","v_ind_rc_lockeropn","v_ind_rc_lowtable","v_ind_rc_overalldrp","v_ind_rc_overallfld","v_ind_rc_plaztray","v_ind_rc_rubbish","v_ind_rc_rubbish2","v_ind_rc_rubbishppr","v_ind_rc_shovel","v_ind_rc_towel","v_ind_rc_workbag","v_ind_sinkequip","v_ind_sinkhand","v_ind_ss_chair01","v_ind_ss_chair2","v_ind_ss_chair3_cso","v_ind_ss_clothrack","v_ind_ss_deskfan","v_ind_ss_deskfan2","v_ind_tor_bulkheadlight","v_ind_tor_clockincard","v_ind_tor_smallhoist01","v_ind_v_recycle_lamp1","int_boxthing","v_10_baninbetbits","v_10_banker_tables","v_10_bankinbetweendirt","v_10_bankovers","v_10_bckbnkdirt","v_10_boozeprices","v_10_fleecalogo","v_10_fleecalogo2","v_10_gan_bank_reflect","v_10_genbankcounter","v_10_genbanklights_01","v_10_genbanktrim","v_10_genbank_bits","v_10_genbank_leaflets","v_10_genbank_rubbermat","v_10_gendepo_box01","v_10_gendepo_box01_lid","v_10_gen_bankcounter","v_10_gen_bnkvaultdetail","v_10_gen_country_bank","v_10_gen_liq_reflect","v_10_liqourceilingsigns","v_10_liquoradposts","v_10_liquorbacktrim","v_10_liquorbits1","v_10_liquorboard","v_10_liquorboxads","v_10_liquorcellarbits","v_10_liquordirt","v_10_liquorestorebits","v_10_liquorfagdisplay","v_10_liquorfloorshelves","v_10_liquornotes","v_10_liquorporn","v_10_liquorstore","v_10_liquorstorebeerstacks","v_10_liquor_backdirt","v_10_liquor_counter","v_10_liqurmat","v_10_liqyeltrim","v_10_lquorbeerstackshope","v_10_price_note","v_10_shop_bits","v_10_timsh*t","v_10_weeroombits","v_11_abalphook001","v_11_abarmsupp","v_11_abattoirshadprox","v_11_abattoirshell","v_11_abattoirsubshell","v_11_abattoirsubshell2","v_11_abattoirsubshell3","v_11_abattoirsubshell4","v_11_abattoir_reflection","v_11_abattpens","v_11_abbabits01","v_11_abbbetlights","v_11_abbbetlights_day","v_11_abbbigconv1","v_11_abbcattlehooist","v_11_abbconduit","v_11_abbcoofence","v_11_abbcorrishad","v_11_abbcorrsigns","v_11_abbdangles","v_11_abbdoorstop","v_11_abbebtsigns","v_11_abbendsigns","v_11_abbexitoverlays","v_11_abbgate","v_11_abbhosethings","v_11_abbinbeplat","v_11_abbleeddrains","v_11_abbmain1_stuts","v_11_abbmain2_dirt","v_11_abbmain2_rails","v_11_abbmain3bits","v_11_abbmain3_rails","v_11_abbmainbit1pipes","v_11_abbmeatchunks001","v_11_abbmnrmshad1","v_11_abbmnrmshad2","v_11_abbmnrmshad3","v_11_abbnardirt","v_11_abbnearenddirt","v_11_abboffovers","v_11_abbpordshadroom","v_11_abbprodbig","v_11_abbproddirt","v_11_abbprodlit","v_11_abbprodplats2","v_11_abbrack1","v_11_abbrack2","v_11_abbrack3","v_11_abbrack4","v_11_abbreargirds","v_11_abbrodovers","v_11_abbrolldorrswitch","v_11_abbrolldors","v_11_abbseams1","v_11_abbslaugbld","v_11_abbslaugdirt","v_11_abbslaughtdrains","v_11_abbslaughtshad","v_11_abbslaughtshad2","v_11_abbslausigns","v_11_abbtops1","v_11_abbtops2","v_11_abbtops3","v_11_abbwins","v_11_abb_repipes","v_11_abcattlegirds","v_11_abcattlights","v_11_abcattlightsent","v_11_abcoolershad","v_11_abinbetbeams","v_11_abmatinbet","v_11_abmeatbandsaw","v_11_aboffal","v_11_aboffplatfrm","v_11_abplastipsprod","v_11_abplatmovecop1","v_11_abplatmoveinbet","v_11_abplatstatic","v_11_abprodbeams","v_11_abseamsmain","v_11_abskinpull","v_11_abslaughmats","v_11_abslauplat","v_11_abslughtbeams","v_11_abstrthooks","v_11_ab_dirty","v_11_ab_pipes","v_11_ab_pipes001","v_11_ab_pipes002","v_11_ab_pipes003","v_11_ab_pipesfrnt","v_11_backrails","v_11_beefheaddropper","v_11_beefheaddroppermn","v_11_beefsigns","v_11_bleederstep","v_11_blufrocksign","v_11_cooheidrack","v_11_cooheidrack001","v_11_coolblood001","v_11_coolerrack001","v_11_cooler_drs","v_11_coolgirdsvest","v_11_crseloadpmp1","v_11_de-hidebeam","v_11_endoffbits","v_11_hangslughshp","v_11_headlopperplatform","v_11_jointracksect","v_11_leccybox","v_11_mainarms","v_11_mainbitrolldoor","v_11_mainbitrolldoor2","v_11_maindrainover","v_11_manrmsupps","v_11_meatinbetween","v_11_meatmain","v_11_metplate","v_11_midoffbuckets","v_11_midrackingsection","v_11_mincertrolley","v_11_prodflrmeat","v_11_producemeat","v_11_prod_wheel_hooks","v_11_rack_signs","v_11_rack_signsblu","v_11_sheephumperlight","v_11_slaughtbox","v_11_stungun","v_11_stungun001","v_11_wincharm","v_11__abbconang1","v_11__abbmetdoors","v_11__abbprodover","v_13_rec_chop_card","v_13_rec_chop_deta","v_13_rec_chop_exlamp","v_13_rec_chop_over","v_13_rec_chop_refl","v_13_rec_chop_shad","v_13_rec_cor1_deta","v_13_rec_cor1_over","v_13_rec_cor1_refl","v_13_rec_door_deta","v_13_rec_door_over","v_13_rec_door_refl","v_13_rec_exit_deta","v_13_rec_exit_over","v_13_rec_exit_refl","v_13_rec_main_card","v_13_rec_main_deta","v_13_rec_main_lamp","v_13_rec_main_over","v_13_rec_main_refl","v_13_rec_main_shre","v_13_rec_off1_det2","v_13_rec_off1_deta","v_13_rec_off1_exlamp","v_13_rec_off1_over","v_13_rec_off1_refl","v_13_rec_off1_shad","v_13_rec_rear_deta","v_13_rec_rear_over","v_13_rec_rear_refl","v_13_rec_she2_deta","v_13_rec_she2_over","v_13_rec_shei_deta","v_13_rec_shei_over","v_13_rec_shei_refl","v_13_rec_sta1_deta","v_13_rec_sta1_over","v_13_rec_sta1_refl","v_13_rec_sta2_deta","v_13_rec_sta2_over","v_13_rec_sta2_refl","v_13_rec_sta2_shad","v_13_rec_wind_card","v_13_rec_wind_deta","v_13_rec_wind_deta001","v_13_rec_wind_exlamp","v_13_rec_wind_over","v_13_rec_wind_shad","v_13_shell","v_13_windowshadows1","v_13_windowshadows2","v_13_windowshadows4","v_13_windowshadows5","v_15_cars_shell","v_15_garg_delta","v_15_garg_delta_ceiling","v_15_garg_delta_doordown","v_15_garg_delta_doorup","v_15_garg_mesh_carlift","v_15_garg_mesh_rack01","v_15_garg_mesh_rack2","v_15_garg_mesh_shelf","v_15_gar_over_decal","v_15_gar_over_normal","v_15_ofa_over_decal","v_15_ofa_over_normal","v_15_ofa_over_shadow","v_15_ofb_over_decal","v_15_ofb_over_normal","v_15_offa_delta2","v_15_offa_delta_glass","v_15_offa_props","v_15_offb_delta","v_15_offb_delta_ceiling","v_15_offb_delta_glass","v_15_offb_delta_props","v_15_offb_glass","v_15_offb_mesh_frames","v_15_shrm_cables","v_15_shrm_delta","v_15_shrm_delta_ceiling","v_15_shrm_delta_ceiling2","v_15_shrm_delta_photos","v_15_shrm_delta_props","v_15_shrm_frames","v_15_shrm_glass1","v_15_shrm_glass2","v_15_shrm_mesh_coffeetable","v_15_shrm_mesh_desk","v_15_shrm_mesh_woodboard","v_15_shrm_neonsign","v_15_shrm_neonsign_iref001","v_15_shrm_neonsign_prx","v_15_shrm_promotional","v_15_shrm_shelfprops","v_15_shrm_window_unbroken","v_15_srm_over_decal","v_15_srm_over_normal","v_15_srm_over_shadow","v_15_window_broken","v_15__exterior_building","v_15__exterior_frame","v_16_ap_hi_pants1","v_16_ap_hi_pants2","v_16_ap_hi_pants3","v_16_ap_hi_pants4","v_16_ap_hi_pants5","v_16_ap_hi_pants6","v_16_ap_mid_pants1","v_16_ap_mid_pants2","v_16_ap_mid_pants3","v_16_ap_mid_pants4","v_16_ap_mid_pants5","v_16_barglow","v_16_barglow001","v_16_barglownight","v_16_basketball","v_16_bathemon","v_16_bathmirror","v_16_bathstuff","v_16_bdrm_mesh_bath","v_16_bdrm_paintings002","v_16_bdr_mesh_bed","v_16_bedrmemon","v_16_bed_mesh_blinds","v_16_bed_mesh_delta","v_16_bed_mesh_windows","v_16_bookend","v_16_dnr_a","v_16_dnr_c","v_16_dt","v_16_fh_sidebrdlngb_rsref001","v_16_frankcable","v_16_frankcurtain1","v_16_frankstuff","v_16_frankstuff003","v_16_frankstuff004","v_16_frankstuff_noshad","v_16_goldrecords","v_16_hifi","v_16_highstudwalldirt","v_16_high_bath_delta","v_16_high_bath_mesh_mirror","v_16_high_bath_mesh_mirror001","v_16_high_bath_over_normals","v_16_high_bath_over_shadow","v_16_high_bed_mesh_lights","v_16_high_bed_mesh_unit","v_16_high_bed_over_dirt","v_16_high_bed_over_normal","v_16_high_bed_over_shadow","v_16_high_hall_mesh_delta","v_16_high_hall_over_dirt","v_16_high_hall_over_normal","v_16_high_hall_over_shadow","v_16_high_hal_mesh_plant","v_16_high_kit_mesh_unit","v_16_high_ktn_mesh_delta","v_16_high_ktn_mesh_fire","v_16_high_ktn_mesh_windows","v_16_high_ktn_over_decal","v_16_high_ktn_over_dirt","v_16_high_ktn_over_shadow","v_16_high_ktn_over_shadows","v_16_high_lng_armchairs","v_16_high_lng_details","v_16_high_lng_mesh_delta","v_16_high_lng_mesh_plant","v_16_high_lng_mesh_shelf","v_16_high_lng_mesh_tvunit","v_16_high_lng_over_dirt","v_16_high_lng_over_shadow","v_16_high_lng_over_shadow2","v_16_high_plan_mesh_delta","v_16_high_plan_over_normal","v_16_high_pln_mesh_lights","v_16_high_pln_m_map","v_16_high_pln_over_shadow","v_16_high_stp_mesh_unit","v_16_high_ward_over_decal","v_16_high_ward_over_normal","v_16_high_ward_over_shadow","v_16_hiigh_ktn_over_normal","v_16_hi_apt_planningrmstf","v_16_hi_apt_s_books","v_16_hi_studdorrtrim","v_16_knt_c","v_16_knt_f","v_16_knt_mesh_stuff","v_16_lgb_mesh_lngprop","v_16_lgb_rock001","v_16_livstuff003","v_16_livstuff00k2","v_16_lnb_mesh_coffee","v_16_lnb_mesh_tablecenter001","v_16_lngas_mesh_delta003","v_16_lng_mesh_blinds","v_16_lng_mesh_delta","v_16_lng_mesh_stairglass","v_16_lng_mesh_stairglassb","v_16_lng_mesh_windows","v_16_lng_over_normal","v_16_low_bath_mesh_window","v_16_low_bath_over_decal","v_16_low_bed_over_decal","v_16_low_bed_over_normal","v_16_low_bed_over_shadow","v_16_low_ktn_mesh_sideboard","v_16_low_ktn_mesh_units","v_16_low_ktn_over_decal","v_16_low_lng_mesh_armchair","v_16_low_lng_mesh_coffeetable","v_16_low_lng_mesh_fireplace","v_16_low_lng_mesh_plant","v_16_low_lng_mesh_rugs","v_16_low_lng_mesh_sidetable","v_16_low_lng_mesh_sofa1","v_16_low_lng_mesh_sofa2","v_16_low_lng_mesh_tv","v_16_low_lng_over_decal","v_16_low_lng_over_normal","v_16_low_lng_over_shadow","v_16_low_mesh_lng_shelf","v_16_lo_shower","v_16_mags","v_16_mesh_delta","v_16_mesh_shell","v_16_midapartdeta","v_16_midapt_cabinet","v_16_midapt_curts","v_16_midapt_deca","v_16_mid_bath_mesh_delta","v_16_mid_bath_mesh_mirror","v_16_mid_bed_bed","v_16_mid_bed_delta","v_16_mid_bed_over_decal","v_16_mid_hall_mesh_delta","v_16_mid_shell","v_16_molding01","v_16_mpmidapart00","v_16_mpmidapart01","v_16_mpmidapart018","v_16_mpmidapart03","v_16_mpmidapart07","v_16_mpmidapart09","v_16_mpmidapart13","v_16_mpmidapart17","v_16_mp_sofa","v_16_rpt_mesh_pictures","v_16_rpt_mesh_pictures003","v_16_shadowobject69","v_16_shadsy","v_16_skateboard","v_16_strsdet01","v_16_studapart00","v_16_studframe","v_16_studio_loshell","v_16_studio_pants1","v_16_studio_pants2","v_16_studio_pants3","v_16_studio_skirt","v_16_studio_slip1","v_16_studposters","v_16_studunits","v_16_study_rug","v_16_study_sofa","v_16_treeglow","v_16_treeglow001","v_16_vint1_multilow02","v_16_v_1_studapart02","v_16_v_sofa","v_16_wardrobe","v_19_bar_speccy","v_19_bubbles","v_19_changeshadsmain","v_19_corridor_bits","v_19_curts","v_19_dirtframes_ent","v_19_dtrpsbitsmore","v_19_ducts","v_19_fishy_coral","v_19_fishy_coral2","v_19_jakemenneon","v_19_jetceilights","v_19_jetchangebits","v_19_jetchangerail","v_19_jetchnceistuff","v_19_jetchngwrkcrd","v_19_jetdado","v_19_jetdncflrlights","v_19_jetstripceilpan","v_19_jetstripceilpan2","v_19_jetstrpstge","v_19_maindressingstuff","v_19_office_trim","v_19_payboothtrim","v_19_premium2","v_19_priv_bits","v_19_priv_shads","v_19_stp3fistank","v_19_stplightspriv","v_19_stpprvrmpics","v_19_stri3litstps","v_19_strip3pole","v_19_stripbootbits","v_19_stripbooths","v_19_stripchangemirror","v_19_stripduct","v_19_stripduct2","v_19_strip_off_overs","v_19_strip_stickers","v_19_strp3mirrors","v_19_strpbar","v_19_strpbarrier","v_19_strpchngover1","v_19_strpchngover2","v_19_strpdjbarr","v_19_strpdrfrm1","v_19_strpdrfrm2","v_19_strpdrfrm3","v_19_strpdrfrm4","v_19_strpdrfrm5","v_19_strpdrfrm6","v_19_strpentlites","v_19_strpfrntpl","v_19_strpmncled","v_19_strpprivlits","v_19_strprvrmgdbits","v_19_strpshell","v_19_strpshellref","v_19_strpstglt","v_19_strpstgtrm","v_19_strpstrplit","v_19_strp_offbits","v_19_strp_rig","v_19_trev_stuff","v_19_trev_stuff1","v_19_vabbarcables","v_19_vanbckofftrim","v_19_vanchngfacings","v_19_vanchngfcngfrst","v_19_vangroundover","v_19_vanillasigneon","v_19_vanillasigneon2","v_19_vanilla_sign_neon","v_19_vanlobsigns","v_19_vanmenuplain","v_19_vannuisigns","v_19_vanshadmainrm","v_19_vanstageshads","v_19_vanuniwllart","v_19_vanunofflights","v_19_weebitstuff","v_1_coils01","v_1_coils02","v_1_coils03","v_1_coils04","v_1_coils05","v_1_coils06","v_1_dec_02","v_1_door01","v_1_door02","v_1_door03","v_1_duct02","v_1_fdsm01","v_1_fd_crest","v_1_floor_spec","v_1_main_deta","v_1_mountedshelf","v_1_rails01","v_1_shell","v_1_vacuum003","v_1_vacuum004","v_1_vacuum005","v_1_vacuum006","v_1_vacuum01","v_1_vacuum02","v_20_armoury_gate","v_20_arm_dec","v_20_arm_det01","v_20_br_det","v_20_copfile01","v_20_copfile02","v_20_evidence01","v_20_frontdesk","v_20_lspd_sign","v_20_notbrd002","v_20_notbrd003","v_20_notbrd004","v_20_notbrd005","v_20_notbrd006","v_20_notbrd01","v_20_ornaeagle","v_20_phcorrdirt","v_20_phlobbylightsem","v_20_phlobdirt","v_20_phsm02","v_20_ph_arm_cab01","v_20_ph_cells_dec","v_20_ph_flag01","v_20_ph_flag02","v_20_ph_flag03","v_20_ph_in_outbrd","v_20_ph_in_outbrd002","v_20_ph_lobby_desk","v_20_ph_lobby_det01","v_20_ph_lobby_lights","v_20_ph_lobby_planter003","v_20_ph_lobby_planter01","v_20_ph_lobby_planter02","v_20_ph_lockers_det01","v_20_ph_musdesk","v_20_ph_muster_det01","v_20_ph_office_det01","v_20_ph_office_det02","v_20_ph_office_flag01","v_20_ph_signs01","v_20_ph_stairdets","v_20_ph_stairdets001","v_20_ph_stairs03","v_20_ph_stairwell_det01","v_20_ph_stairwell_det02","v_20_ph_stair_dec","v_20_ph_stair_dec001","v_20_policehubshell","v_20_rubbermat","v_20_sm01","v_20_stairwell_det01","v_20_wall_light003","v_20_wall_light004","v_20_wall_light005","v_20_wall_light006","v_20_wall_light007","v_20_wall_light008","v_20_wall_light01","v_20_wep_lo","v_21_dummybox","v_22_ao_room","v_22_bullets","v_22_cables1","v_22_cables2","v_22_g2_shell","v_22_g2_vents","v_22_glass01","v_22_glass02","v_22_glass03","v_22_glass04","v_22_glass05","v_22_glass06","v_22_glass07","v_22_glass08","v_22_glass09","v_22_glass10","v_22_glass11","v_22_glass12","v_22_gunsneon","v_22_handguns","v_22_merch01","v_22_merchglass003","v_22_merchglass004","v_22_merchglass005","v_22_merchglass009","v_22_merchglass010","v_22_merchglass011","v_22_merchglass1","v_22_merchglass2","v_22_merchglass3","v_22_merchglass4","v_22_merchglass5","v_22_merchglass6","v_22_merchglass7","v_22_merchglass8","v_22_overlays","v_22_reflectproxy","v_22_shadowmap","v_22_shelves","v_22_shopdirt","v_22_shopposters","v_22_shopshadow","v_22_shopskirt","v_22_walledges","v_22_wallguns","v_22_wallhooks","v_23_ao","v_23_ao_front","v_23_ao_office","v_23_blends","v_23_detail","v_23_doors","v_23_emissives","v_23_emissives_front","v_23_frames","v_23_front_blends","v_23_front_detail","v_23_front_reflect","v_23_j2_dc","v_23_lamps","v_23_lamps2","v_23_lamps_fr","v_23_lod","v_23_mirrorfloor","v_23_office_detail","v_23_pointsale01","v_23_reflect","v_23_reflect_ext","v_23_shell","v_24_bdrm_mesh_arta","v_24_bdrm_mesh_bath","v_24_bdrm_mesh_bathprops","v_24_bdrm_mesh_bookcase","v_24_bdrm_mesh_bookcasestuff","v_24_bdrm_mesh_boxes","v_24_bdrm_mesh_closetdoors","v_24_bdrm_mesh_dresser","v_24_bdrm_mesh_mags","v_24_bdrm_mesh_mirror","v_24_bdrm_mesh_picframes","v_24_bdrm_mesh_rugs","v_24_bdrm_mesh_wallshirts","v_24_bdr_mesh_bed","v_24_bdr_mesh_bed_stuff","v_24_bdr_mesh_delta","v_24_bdr_mesh_lamp","v_24_bdr_mesh_lstshirt","v_24_bdr_mesh_windows_closed","v_24_bdr_mesh_windows_open","v_24_bdr_over_decal","v_24_bdr_over_dirt","v_24_bdr_over_emmisve","v_24_bdr_over_normal","v_24_bdr_over_shadow","v_24_bdr_over_shadow_boxes","v_24_bdr_over_shadow_frank","v_24_bedroomshell","v_24_details1","v_24_details2","v_24_hal_mesh_delta","v_24_hal_mesh_props","v_24_hal_over_decal","v_24_hal_over_normal","v_24_hal_over_shadow","v_24_hangingclothes","v_24_hangingclothes1","v_24_knt_mesh_blinds","v_24_knt_mesh_boxes","v_24_knt_mesh_center","v_24_knt_mesh_delta","v_24_knt_mesh_flyer","v_24_knt_mesh_mags","v_24_knt_mesh_stuff","v_24_knt_mesh_units","v_24_knt_mesh_windowsa","v_24_knt_mesh_windowsb","v_24_knt_over_decal","v_24_knt_over_normal","v_24_knt_over_shadow","v_24_knt_over_shadow_boxes","v_24_knt_over_shelf","v_24_ktn_over_dirt","v_24_lga_mesh_delta","v_24_lga_over_dirt","v_24_lga_over_normal","v_24_lga_over_shadow","v_24_lgb_mesh_bottomdelta","v_24_lgb_mesh_fire","v_24_lgb_mesh_lngprop","v_24_lgb_mesh_sideboard","v_24_lgb_mesh_sideboard_em","v_24_lgb_mesh_sideprops","v_24_lgb_mesh_sofa","v_24_lgb_mesh_topdelta","v_24_lgb_over_dirt","v_24_llga_mesh_coffeetable","v_24_llga_mesh_props","v_24_lna_mesh_windows","v_24_lnb_coffeestuff","v_24_lnb_mesh_artwork","v_24_lnb_mesh_books","v_24_lnb_mesh_cddecks","v_24_lnb_mesh_coffee","v_24_lnb_mesh_djdecks","v_24_lnb_mesh_dvds","v_24_lnb_mesh_fireglass","v_24_lnb_mesh_goldrecords","v_24_lnb_mesh_lightceiling","v_24_lnb_mesh_records","v_24_lnb_mesh_sideboard","v_24_lnb_mesh_smallvase","v_24_lnb_mesh_tablecenter","v_24_lnb_mesh_windows","v_24_lnb_over_disk_shadow","v_24_lnb_over_shadow","v_24_lnb_over_shadow_boxes","v_24_lngb_mesh_boxes","v_24_lngb_mesh_chopbed","v_24_lngb_mesh_mags","v_24_lng_over_decal","v_24_lng_over_normal","v_24_postertubes","v_24_rct_lamptablestuff","v_24_rct_mesh_boxes","v_24_rct_mesh_lamptable","v_24_rct_over_decal","v_24_rec_mesh_palnt","v_24_rpt_mesh_delta","v_24_rpt_mesh_pictures","v_24_rpt_over_normal","v_24_rpt_over_shadow","v_24_rpt_over_shadow_boxes","v_24_shell","v_24_shlfstudy","v_24_shlfstudybooks","v_24_shlfstudypics","v_24_sta_mesh_delta","v_24_sta_mesh_glass","v_24_sta_mesh_plant","v_24_sta_mesh_props","v_24_sta_over_normal","v_24_sta_over_shadow","v_24_sta_painting","v_24_storageboxs","v_24_tablebooks","v_24_wdr_mesh_delta","v_24_wdr_mesh_rugs","v_24_wdr_mesh_windows","v_24_wdr_over_decal","v_24_wdr_over_dirt","v_24_wdr_over_normal","v_24_wrd_mesh_boxes","v_24_wrd_mesh_tux","v_24_wrd_mesh_wardrobe","v_25_class","v_25_classlights","v_25_controldesk","v_25_controlequip","v_25_controlsm","v_25_drframes","v_25_elevator01","v_25_elevstuff","v_25_elvsigns","v_25_hallstuff","v_25_levnumbers","v_25_lights","v_25_lowershad","v_25_obsvclutter","v_25_obsvdesks","v_25_obsvlights","v_25_obsvsm","v_25_reflect","v_25_security","v_25_servdesk","v_25_servers","v_25_servershad","v_25_servleds","v_25_servlights","v_25_stair01","v_25_stair02","v_25_stair03","v_25_stair04","v_25_stair05","v_25_stair06","v_25_stairlights","v_25_stairshd","v_25_towelod","v_25_towerdetail","v_25_towerglass","v_25_towershell","v_25_upperhallsm","v_26_bed","v_26_bedtidy","v_26_bedtrash","v_26_beerbox","v_26_beerboxtidy","v_26_cablestidy","v_26_cablesuntidy","v_26_cablesuntidy001","v_26_calcabletidy","v_26_calcableuntidy","v_26_calcableuntidy001","v_26_cophelmet1","v_26_cophelmet2","v_26_cophelmet3","v_26_couch","v_26_couchtidy","v_26_couchtrash","v_26_cupboards","v_26_cupboards001","v_26_cupboardstidy","v_26_cupboardtidy","v_26_cupboardtrash","v_26_cupbrdstrash","v_26_ducttape","v_26_ducttapetidy","v_26_ducttapetrash","v_26_glass005","v_26_glass006","v_26_glass007","v_26_glass008","v_26_glass1","v_26_glass2","v_26_glass3","v_26_glass4","v_26_glasstidy004","v_26_glasstidy1","v_26_glasstidy2","v_26_glasstidy4","v_26_halloverlay","v_26_halloverlaytidy","v_26_hallovertrash","v_26_kitchen","v_26_kitchendirt","v_26_kitchendirttrash","v_26_kitchentidy","v_26_kitchentrash","v_26_lamp002","v_26_lamp1","v_26_lamp1trash","v_26_michaelsuit1","v_26_michaelsuit2","v_26_michaelsuit3","v_26_mirror","v_26_mirror002","v_26_mirrortrash","v_26_m_blanket1","v_26_m_blanket2","v_26_m_blanket3","v_26_overlays","v_26_overlaystidy","v_26_overlaytrash","v_26_reflectdirty","v_26_reflecttidy","v_26_reflecttrashed","v_26_shadowmap","v_26_shadowtidy","v_26_shadowtrash","v_26_toilet","v_26_toiletlight","v_26_toiletlighttidy","v_26_toiletlighttrash","v_26_toilettdirt","v_26_toilettdirttrash","v_26_toilettidy","v_26_toilettrash","v_26_trailerint","v_26_trailerinttidy","v_26_trailertrashint","v_26_walllampson","v_26_walllampson001","v_26_walllamptrashon","v_26_wardrobe","v_26_wardrobetidy","v_26_wardrobetrash","v_26_windframes","v_26_windframestrash","v_26_windowday","v_26_windowday001","v_26_windowdaytrash","v_26_winframetidy","v_27_boxpile1","v_27_epsilonism_ao","v_27_epsilonism_dt","v_27_epsilonism_extras","v_27_epsilonism_ol","v_27_epsilonism_reflect","v_27_epsilonism_shell","v_27_epsilonism_stuff","v_28_alrm_case002","v_28_alrm_case003","v_28_alrm_case004","v_28_alrm_case005","v_28_alrm_case006","v_28_alrm_case007","v_28_alrm_case008","v_28_alrm_case009","v_28_alrm_case010","v_28_alrm_case011","v_28_alrm_case012","v_28_alrm_case013","v_28_alrm_case014","v_28_alrm_case015","v_28_alrm_case016","v_28_an1_deca","v_28_an1_deta","v_28_an1_dirt","v_28_an1_over","v_28_an1_refl","v_28_an1_shut","v_28_an2_deca","v_28_an2_deta","v_28_an2_dirt","v_28_an2_refl","v_28_an2_shut","v_28_backlab_deta","v_28_backlab_refl","v_28_blab_dirt","v_28_blab_over","v_28_coldr_deta","v_28_coldr_dirt","v_28_coldr_glass1","v_28_coldr_glass2","v_28_coldr_glass3","v_28_coldr_glass4","v_28_coldr_over","v_28_coldr_refl","v_28_corr_deta","v_28_corr_dirt","v_28_corr_over","v_28_corr_refl","v_28_gua2_deta","v_28_gua2_dirt","v_28_gua2_over","v_28_gua2_refl","v_28_guard1_deta","v_28_guard1_dirt","v_28_guard1_over","v_28_guard1_refl","v_28_ha1_cover","v_28_ha1_cover001","v_28_ha1_deca","v_28_ha1_deta","v_28_ha1_dirt","v_28_ha1_refl","v_28_ha1_step","v_28_ha2_deca","v_28_ha2_deta","v_28_ha2_dirt","v_28_ha2_refl","v_28_ha2_ste1","v_28_ha2_ste2","v_28_hazmat1_deta","v_28_hazmat1_dirt","v_28_hazmat1_over","v_28_hazmat1_refl","v_28_hazmat2_deta","v_28_hazmat2_dirt","v_28_hazmat2_over","v_28_hazmat2_refl","v_28_lab1_deta","v_28_lab1_dirt","v_28_lab1_glas","v_28_lab1_glass","v_28_lab1_over","v_28_lab1_refl","v_28_lab2_deta","v_28_lab2_dirt","v_28_lab2_over","v_28_lab2_refl","v_28_lab_end","v_28_lab_gar_dcl_01","v_28_lab_poen_deta","v_28_lab_poen_pipe","v_28_lab_pool","v_28_lab_poolshell","v_28_lab_pool_deta","v_28_lab_pool_ladd","v_28_lab_pool_wat1","v_28_lab_shell1","v_28_lab_shell2","v_28_lab_trellis","v_28_loa_deta","v_28_loa_deta2","v_28_loa_dirt","v_28_loa_lamp","v_28_loa_over","v_28_loa_refl","v_28_monkeyt_deta","v_28_monkeyt_dirt","v_28_monkeyt_over","v_28_monkeyt_refl","v_28_pool_deca","v_28_pool_dirt","v_28_pr1_deca","v_28_pr1_deta","v_28_pr1_dirt","v_28_pr1_refl","v_28_pr2_deca","v_28_pr2_deta","v_28_pr2_dirt","v_28_pr2_refl","v_28_pra_deca","v_28_pra_deta","v_28_pra_dirt","v_28_pra_refl","v_28_prh_deca","v_28_prh_deta","v_28_prh_dirt","v_28_prh_refl","v_28_prh_shut","v_28_prh_strs","v_28_steps_2","v_28_wascor_deta","v_28_wascor_dirt","v_28_wascor_over","v_28_wasele_deta","v_28_wasele_dirt","v_28_wasele_refl","v_28_wastecor_refl","v_28_waste_deta","v_28_waste_dirt","v_28_waste_over","v_28_waste_refl","v_29_arcfurnace","v_29_arcfurnpipes","v_29_arcfurnplat","v_29_arcfurnplat001","v_29_arc_furnace_doors","v_29_arfurnplat","v_29_bigcontainer","v_29_bigendblocks","v_29_bigwallsheet1","v_29_chalk_dcals","v_29_contmetcabs","v_29_controlbits","v_29_controom","v_29_crucibles","v_29_doors002","v_29_dustsheet02","v_29_emwindows","v_29_fllorplates","v_29_foucontopertor","v_29_founbenches","v_29_founcastplat003","v_29_founcontconsol","v_29_foundarches001","v_29_foundbackdirt","v_29_foundbucket","v_29_foundcontdirt","v_29_foundcontrolcables","v_29_foundcontrolpornetc","v_29_foundentsigns","v_29_foundentsigns2","v_29_foundentsignsmainrm","v_29_foundfurn_steps","v_29_foundlightcovers","v_29_foundlightcovers2","v_29_foundmachbits","v_29_foundmachdirt","v_29_foundmachgirds","v_29_foundmachleccy","v_29_foundmachwall","v_29_foundpipes","v_29_foundpipesupps","v_29_foundrybackent","v_29_foundryfloorbits","v_29_foundryshell","v_29_foundry_stairs","v_29_foundshieldpans","v_29_foundslag001","v_29_foundsmllrmlocks","v_29_foundtallcasts","v_29_foundtoprmgirs","v_29_foundtopstairs","v_29_found_blobs","v_29_found_contr_dr","v_29_found_dustpiles","v_29_found_glue","v_29_found_ref_prox","v_29_found_safety","v_29_founligths001","v_29_founmaingant","v_29_founmetplates","v_29_founsmllelec","v_29_founsmllrmdirt","v_29_founsmlrrmbench","v_29_fouondmachbitsmore","v_29_funrplatshads","v_29_furnaceslag","v_29_furnace_cables","v_29_gantrybarriers","v_29_gantry_crucibles","v_29_girderwear","v_29_glue_crnr_in004","v_29_highbits","v_29_hut_cover","v_29_ladder","v_29_mainsupportgiders","v_29_millrollback","v_29_millrollbody","v_29_molten_metal","v_29_morecasts","v_29_more_metalbits","v_29_nearcover","v_29_pithighbit","v_29_rails","v_29_rollergantry","v_29_sideroom","v_29_sidestairs","v_29_smallcasts","v_29_smallcastsmore001","v_29_tanksteps","v_29_underfunrcover","v_29_vfx_ripple_mesh_skin"
};

int forobj = 0;
int Features::attachobj1[100];
int Features::nuattach1 = 1;
bool Features::attachobjectsCrashbool = false;
void Features::attachobjectsCrash(bool toggle)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
	hash = GAMEPLAY::GET_HASH_KEY(forbidden_object[forobj]);
	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)))
	{
		if (Hooking::is_model_in_cdimage(hash))
		{
				Hooking::request_model(hash);
				if (Hooking::has_model_loaded(hash))
				{
					Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
					//if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
					//{
						//ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 31086, rndInt(0, 10), rndInt(0, 10), rndInt(0, 10), rndInt(0, 10), rndInt(0, 10), rndInt(0, 10), 1, 1, 1, 0, 2, 1);
						nuattach++;
						forobj++;
						if (nuattach >= 101) { nuattach = 1; }
						if (forobj >= 1439) { nuattach = 0; }
					//}
				}
		}
	}
	else
	{
		Features::attachobjectsCrashbool = false;
		forobj = 0;
	}
}

bool Features::osk = false;
bool Features::Superman = false;
/*
void Features::OSKR(bool toggle)
{
	if (!osk) {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 1.f);
	}
	else {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 10000.0f);
	}
}
*/
bool Features::NoClipping = false;
void Features::NoClipme(bool toggle) {

	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (NoClipping)
	{
		ENTITY::SET_ENTITY_COLLISION(playerPed, true, false);
		Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x -= xVec, pos.y -= yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			float xVec = fivef * sin(degToRad(heading)) * -1.0f;
			float yVec = fivef * cos(degToRad(heading));
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.x += xVec, pos.y += yVec;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
		}
		if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
			float fivef = .5f;
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
		}
		if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z -= 0.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
		if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
			float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
			ENTITY::SET_ENTITY_HEADING(playerPed, heading);

			pos.z += 0.5;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
		}
	}
	else
	{
		ENTITY::SET_ENTITY_COLLISION(playerPed, true, true);
	}
}

void Features::superman(bool toggle)
{
	if (toggle == true) {
		Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), hash, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), true);
		PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

		if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())) && !PED::IS_PED_RAGDOLL(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())))
		{
			if (GetAsyncKeyState(0x57)) // W key
			{
				ApplyForceToEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0, 6, 0);
			}
			if (GetAsyncKeyState(0x53)) // S key
			{
				ApplyForceToEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0, -6, 0);
			}
			if (GetAsyncKeyState(VK_SHIFT)) //VK_SHIFT
			{
				ApplyForceToEntity(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0, 0, 6);
			}
		}
	}
	else {
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);//isnt this broken? ehh ill look into it later
	}
}
bool Features::nofallbool = false;
void Features::nofall(bool toggle) {
	if (toggle == true) {
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
	}
	else
	{
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
	}
}

bool Features::goldgunbool = false;
void Features::goldgun(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_gold_bar"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_gold_bar"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_gold_bar"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_gold_bar"));
			}
		}
	}
}
bool Features::Alieneggsbool = false;
void Features::Alieneggs(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xFE18F3AF, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			}
		}
	}
}



bool Features::BagGunBool = false;
void Features::Baggun(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_poly_bag_01"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_poly_bag_01"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_poly_bag_01"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_poly_bag_01"));
			}
		}
	}
}//0xDE78F17E
bool Features::MoneyGunBool = false;
void Features::Moneygun(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("PROP_CS_DILDO_01"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("PROP_CS_DILDO_01"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("PROP_CS_DILDO_01"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("PROP_CS_DILDO_01"));
			}
		}
	}
}

bool Features::Arcadegunbool = false;
void Features::Arcadegun(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_arcade_01"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_arcade_01"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_arcade_01"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_arcade_01"));
			}
		}
	}
}
bool Features::Planeweaponbool = false;
void Features::Planeweapon(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_dummy_plane"));
			}
		}
	}
}

bool Features::Pedweaponbool = false;
void Features::Pedweapon(bool toggle)
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
	{
		float xD[6];
		WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
		if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
		{
			Hooking::request_model(GAMEPLAY::GET_HASH_KEY("prop_dummy_01"));
			while (!Hooking::has_model_loaded(GAMEPLAY::GET_HASH_KEY("prop_dummy_01"))) WAIT(0);
			{
				OBJECT::CREATE_AMBIENT_PICKUP(0xDE78F17E, xD[0], xD[2], xD[4], true, 2000, GAMEPLAY::GET_HASH_KEY("prop_dummy_01"), TRUE, FALSE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_dummy_01"));
			}
		}
	}
}

bool Features::Nothrowshit = false;
void Features::NoRagdoll(bool toggle)
{
	Memory::set_value<DWORD>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_RAGDOLL }, toggle ? 0x20 : 0x01);
	PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), !toggle);
	PED::SET_PED_CAN_RAGDOLL(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), !toggle);
}

int Features::Online::selectedPlayer = 0;
void Features::Online::TeleportToPlayer(Player player) {

	Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())) : handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	ENTITY::_SET_ENTITY_COORDS_2(handle, coords.x, coords.y, coords.z, false, false, false, false);
}

bool Features::neverwanted = false;
void Features::NeverGetWanted(bool toggle)
{
	if (neverwanted)
	{
		Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, 0);
	}
	else
	{
		Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, false);

	}
}

int Features::Wantedshit = 0;
void Features::ChangeWanted(int level) {
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, Features::Wantedshit);
}
int Features::GetWanted(Player player) {
	return PLAYER::GET_PLAYER_WANTED_LEVEL(player);
}

bool Features::RPLoop = false;
int Features::RPLoopDelay = 5;
int Rptick2 = 0;
int Rptick = 0;
void Features::rpLoop(bool toggle) {
	if (Features::RPLoop)
	{
		Rptick++;
		if (Rptick > Features::RPLoopDelay) {
			Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, 5);
			Rptick2++;
			if (Rptick2 > Features::RPLoopDelay) {
				Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, 0);
				Rptick = 0;
				Rptick2 = 0;
			}
		}
	}
	else
	{
		Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, false);

	}
}

bool Features::Ghostmode = false;
void Features::ghostmode(bool toggle)
{
	if (toggle == true)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), true, 0);
	}
}
bool Features::mobileRadio = false;
void Features::mobilevoid(bool toggle) {
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();
	if (toggle == false)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);
		Hooking::set_mobile_radio(false);
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
		Hooking::set_mobile_radio(true);

	}
}
bool Features::blockcallsbool = false;
void Features::blockcalls(bool toggle) {
	if (toggle == true)
	{
		if (AUDIO::IS_MOBILE_PHONE_CALL_ONGOING())
		{
			AUDIO::STOP_SCRIPTED_CONVERSATION(1);
		}
	}
	else
	{
		if (!AUDIO::IS_MOBILE_PHONE_CALL_ONGOING())
		{
			AUDIO::STOP_SCRIPTED_CONVERSATION(0);
		}
	}
}
void Features::clearanim()
{
	Hooking::clear_ped_tasks_immediately(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));

}
/*
bool Features::nightvisionbool = false;
void Features::nightvision(bool toggle)
{
	if (nightvisionbool)
	{
		GRAPHICS::SET_NIGHTVISION(1);
	}
	else
	{
		GRAPHICS::SET_NIGHTVISION(0);
	}
}
*/
bool Features::Disablephonebool = false;
void Features::Disablephone(bool toggle)
{
	if (Disablephone)
	{
		MOBILE::_DISABLE_PHONE_THIS_FRAME(true);
	}
	else
	{
		MOBILE::_DISABLE_PHONE_THIS_FRAME(false);
	}
}
/*
bool Features::heatvisionbool = false;
void Features::heatvision(bool toggle)
{
	if (heatvisionbool)
	{
		GRAPHICS::SET_SEETHROUGH(1);
	}
	else
	{
		GRAPHICS::SET_SEETHROUGH(0);
	}
}
*/
bool Features::Superjump = false;
void Features::superjump(bool toggle)
{
	Player playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerPed);
}

constexpr uint32_t	GLOBALPTR_OTR_TOGGLE = 0x24F7C4;	//0x24F7C4 + (1 + (PLAYER::PLAYER_ID() * 420)) + 215 2422742
constexpr uint32_t	GLOBALPTR_OTR_TIME = 0x252C49;		//0x252C49 + 70 2436169

bool Features::OffTheRadarBool = false;
void Features::OffTheRadar(bool toggle) {
	
	if (toggle == true)
	{
		globalHandle(GLOBALPTR_OTR_TOGGLE).At(PLAYER::PLAYER_ID(), 420).At(215).As<int>() ^= 1;
		globalHandle(GLOBALPTR_OTR_TIME).At(70).As<int>() = NETWORK::GET_NETWORK_TIME() + 6000;
	}
	else 
	{
		globalHandle(GLOBALPTR_OTR_TIME).At(PLAYER::PLAYER_ID(), 420).At(215).As<int>() = 0;
	}
}
//Other Shit
void Menu::drawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA rgba)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	else GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, rgba.r, rgba.g, rgba.b, rgba.a);
};



	bool Features::antimoneydrop = true;
	void Features::MoneyDropBypass(bool toggle)
	{
		Hooking::defuseEvent(REVENT_REQUEST_PICKUP_EVENT, toggle);
	}
	bool Features::antivotekickbool = false;
	void Features::antivotekick(bool toggle)
	{
		Hooking::defuseEvent(REVENT_KICK_VOTES_EVENT, toggle);
	}
	
	bool Features::antitp = false;
	void Features::TPProtex(bool toggle)
	{
		Hooking::defuseEvent(REVENT_NETWORK_REQUEST_SYNCED_SCENE_EVENT, toggle);
		Hooking::defuseEvent(REVENT_NETWORK_START_SYNCED_SCENE_EVENT, toggle);
		Hooking::defuseEvent(REVENT_NETWORK_UPDATE_SYNCED_SCENE_EVENT, toggle);
		Hooking::defuseEvent(REVENT_NETWORK_STOP_SYNCED_SCENE_EVENT, toggle);
	}

	bool Features::antiremoveweptoggle = false;
	void Features::RemoveWeaponProtex(bool toggle)
	{
		Hooking::defuseEvent(REVENT_REMOVE_WEAPON_EVENT, toggle);
		Hooking::defuseEvent(REVENT_REMOVE_ALL_WEAPONS_EVENT, toggle);
	}

	bool Features::antiptfxtoggle = false;
	void Features::PTFXProtex(bool toggle)
	{
		Hooking::defuseEvent(REVENT_NETWORK_PTFX_EVENT, toggle);
	}

	bool Features::antifreeze = false;
	void Features::FreezeProtex(bool toggle)
	{
		Hooking::defuseEvent(REVENT_NETWORK_CLEAR_PED_TASKS_EVENT, toggle);
	}
	
	bool Features::antiexplosion = false;
	void Features::AntiFireExplosion(bool toggle)
	{
		Hooking::defuseEvent(REVENT_FIRE_EVENT, toggle);
		Hooking::defuseEvent(REVENT_EXPLOSION_EVENT, toggle);
	}

	bool Features::antiblametoggle = false;
	void Features::AntiBlame(bool toggle)
	{
		NETWORK::NETWORK_SET_FRIENDLY_FIRE_OPTION(toggle);
	}

	bool Features::antiremotetoggle = false;
	void Features::AntiRemote(bool toggle)
	{
		Hooking::defuseEvent(REVENT_REMOTE_SCRIPT_INFO_EVENT, toggle);
		Hooking::defuseEvent(REVENT_REMOTE_SCRIPT_LEAVE_EVENT, toggle);
	}


bool Features::rainbowmenu = false;
void Features::Rainbowmenu(bool toggle)
{
	if (Menu::Settings::titleRect.r > 0 && Menu::Settings::titleRect.b == 0, Menu::Settings::scroller.r > 0 && Menu::Settings::scroller.b == 0)
	{
		Menu::Settings::titleRect.r--;
		Menu::Settings::titleRect.g++;
		Menu::Settings::scroller.r--;
		Menu::Settings::scroller.g++;
	}
	if (Menu::Settings::titleRect.g > 0 && Menu::Settings::titleRect.r == 0, Menu::Settings::scroller.g > 0 && Menu::Settings::scroller.r == 0)
	{
		Menu::Settings::titleRect.g--;
		Menu::Settings::titleRect.b++;
		Menu::Settings::scroller.g--;
		Menu::Settings::scroller.b++;
	}
	if (Menu::Settings::titleRect.b > 0 && Menu::Settings::titleRect.g == 0, Menu::Settings::scroller.b > 0 && Menu::Settings::scroller.g == 0)
	{
		Menu::Settings::titleRect.r++;
		Menu::Settings::titleRect.b--;
		Menu::Settings::scroller.r++;
		Menu::Settings::scroller.b--;
	}
	(Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b);
	(Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b);
}

bool Features::showcoordsbool = false;
void Features::showcoords(bool toggle)
{
	Vector3 playerCoord = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
	std::string xMsg = " X " + std::to_string(playerCoord.x);
	std::string yMsg = " Y " + std::to_string(playerCoord.y);
	std::string zMsg = " Z " + std::to_string(playerCoord.z);
	std::string coordMessage = xMsg + yMsg + zMsg;
	char* xCoord = strcpy((char*)malloc(coordMessage.length() + 1), coordMessage.c_str());
	UI::SET_TEXT_FONT(7);
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(xCoord);
	UI::END_TEXT_COMMAND_PRINT(1, 1);

}

void Features::savecoords()
{
	Vector3 playerCoord = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
	std::string xMsg = " X " + std::to_string(playerCoord.x);
	std::string yMsg = " Y " + std::to_string(playerCoord.y);
	std::string zMsg = " Z " + std::to_string(playerCoord.z);
	std::string coordMessage = xMsg + yMsg + zMsg;
	char* xCoord = strcpy((char*)malloc(coordMessage.length() + 1), coordMessage.c_str());
	Features::WriteToFile(std::string("Coords.txt"), coordMessage);

}

void Features::WriteToFile(std::string filename, std::string content)
{
	wchar_t path[MAX_PATH];
	char target[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result == S_OK)
	{
		string coords = content + "\n";
		wcstombs(target, path, MAX_PATH);
		string path = "\\AztralFiles\\" + filename;
		strcat(target, path.c_str());
		std::ofstream file(target, ios::app);
		file << coords << "\n";
	}
}

bool Features::showspeedbool = false;
void Features::showspeed(bool toggle)
{
	if (showspeedbool && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1))
	{
		if (showspeed1bool)
			Features::showspeed1bool = false;
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
		float speed = ENTITY::GET_ENTITY_SPEED(veh);
		float mph = (speed * 2.236936);

		string string1 = std::to_string(mph);

		string speed1 = string1.erase(string1.find('.')) + "MPH";

		char* speed2 = strcpy((char*)malloc(speed1.length() + 1), speed1.c_str());
		

		UI::SET_TEXT_FONT(7);
		UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(speed2);
		UI::END_TEXT_COMMAND_PRINT(1, 1);
	}
}
bool Features::showspeed1bool = false;
void Features::showspeed1(bool toggle)
{
	if (showspeed1bool && PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1))
	{
		if (showspeedbool)
			Features::showspeedbool = false;
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
		float speed = ENTITY::GET_ENTITY_SPEED(veh);
		float kmh = (speed * 3.6);

		string string1 = std::to_string(kmh);

		string speed1 = string1.erase(string1.find('.')) + "KMPH";

		char* speed2 = strcpy((char*)malloc(speed1.length() + 1), speed1.c_str());

		UI::SET_TEXT_FONT(7);
		UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(speed2);
		UI::END_TEXT_COMMAND_PRINT(1, 1);
	}
}

bool Features::CheckConfigBool = true;
void Features::CheckConfig(bool toggle)
{
	if (Features::CheckConfigBool)
	{
		if (KeyJustUp(Global::cgodmode)) { if (Features::Godmodebool == true) { Features::Godmodebool = false; } else { Features::Godmodebool = true; } }
		if (KeyJustUp(Global::ctpwaypoint)) { Features::TPtoWaypoint(); }
		if (KeyJustUp(Global::ctpobj)) { Features::TPtoObjective(); }
		if (KeyJustUp(Global::cinvisible)) { if (Features::Ghostmode == true) { Features::Ghostmode = false; } else { Features::Ghostmode = true; } }
		if (KeyJustUp(Global::csuperjump)) { if (Features::Superjump == true) { Features::Superjump = false; } else { Features::Superjump = true; } }
		if (KeyJustUp(Global::cfastrun)) { if (Features::fastrunbool == true) { Features::fastrunbool = false; } else { Features::fastrunbool = true; } }
		if (KeyJustUp(Global::cfastswim)) { if (Features::fastswimbool == true) { Features::fastswimbool = false; } else { Features::fastswimbool = true; } }
		if (KeyJustUp(Global::cnoragdoll)) { if (Features::Nothrowshit == true) { Features::Nothrowshit = false; } else { Features::Nothrowshit = true; } }
		if (KeyJustUp(Global::cnoclip)) { if (Features::NoClipping == true) { Features::NoClipping = false; } else { Features::NoClipping = true; } }
		if (KeyJustUp(Global::cesp)) { if (Features::esper == true) { Features::esper = false; } else { Features::esper = true; } }
		if (KeyJustUp(Global::cshowcoords)) { if (Features::showcoordsbool == true) { Features::showcoordsbool = false; } else { Features::showcoordsbool = true; } }
		if (KeyJustUp(Global::csavecoords)) { Features::savecoords(); }
		if (KeyJustUp(Global::cgodvehicle)) { if (Features::cargodmodebool == true) { Features::cargodmodebool = false; } else { Features::cargodmodebool = true; } }
		if (KeyJustUp(Global::crepairvehicle)) { Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()); Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed); if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(playerPed)); else notifyMap("You're Not In A Vehicle"_Secure, 0); }
		if (KeyJustUp(Global::cmaxvehicle)) { Features::maxvehicle(); }
		if (KeyJustUp(Global::cselfdrive)) { if (Features::SelfDriveBool == true) { Features::SelfDriveBool = false; } else { Features::SelfDriveBool = true; } }
		if (KeyJustUp(Global::ccarsuperman)) { if (Features::fcbool == true) { Features::fcbool = false; } else { Features::fcbool = true; } }
		if (KeyJustUp(Global::ctpintolastvehicle)) { Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()); int vehID = PED::GET_VEHICLE_PED_IS_IN(playerPed, 1); PED::SET_PED_INTO_VEHICLE(playerPed, vehID, -1); }
		if (KeyJustUp(Global::ctpintoclosestvehicle)) { Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()); Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1); int vehID = VEHICLE::GET_CLOSEST_VEHICLE(pos.x, pos.y, pos.z, 600.0f, 0, 0); PED::SET_PED_INTO_VEHICLE(playerPed, vehID, -1); }
		if (KeyJustUp(Global::cflipcar)) { Features::flipup(); }
		if (KeyJustUp(Global::cspeedometerMPH)) { if (Features::showspeedbool == true) { Features::showspeedbool = false; } else { Features::showspeedbool = true; } }
		if (KeyJustUp(Global::cspeedometerKMPH)) { if (Features::showspeedbool == true) { Features::showspeedbool = false; } else { Features::showspeedbool = true; } }
		if (KeyJustUp(Global::cbulletprooftires)) { if (Features::bulletprooftiresbool == true) { Features::bulletprooftiresbool = false; } else { Features::bulletprooftiresbool = true; } }
		if (KeyJustUp(Global::chornboost)) { if (Features::boostbool == true) { Features::boostbool = false; } else { Features::boostbool = true; } }
		if (KeyJustUp(Global::cdriveonwater)) { if (Features::dowbool == true) { Features::dowbool = false; } else { Features::dowbool = true; } }
		if (KeyJustUp(Global::cenginealwayson)) { if (Features::enginealwaysonbool == true) { Features::enginealwaysonbool = false; } else { Features::enginealwaysonbool = true; } }
		if (KeyJustUp(Global::cnofallfrombike)) { if (Features::nofallbool == true) { Features::nofallbool = false; } else { Features::nofallbool = true; } }
	}
} //weapon options + add armor + inf ammo + give all weapons + spawn adder (or random car)

//chafforur w/ self driving car


bool Features::CheckAutoBool = false;
void Features::CheckAuto(bool toggle)
{
	if (Features::CheckAutoBool)
	{
		if (Global::acgodmode == 1) { Features::Godmodebool = true; }
		if (Global::acinvisible == 1) { Features::Ghostmode = true; }
		if (Global::acsuperjump == 1) { Features::Superjump = true; }
		if (Global::acfastrun == 1) { Features::fastrunbool = true; }
		if (Global::acfastswim == 1) { Features::fastswimbool = true; }
		if (Global::acnoragdoll == 1) { Features::Nothrowshit = true; }
		if (Global::acnoclip == 1) { Features::NoClipping = true; }
		if (Global::acesp == 1) { Features::esper = true; }
		if (Global::acshowcoords == 1) { Features::showcoordsbool = true; }
		if (Global::acgodvehicle == 1) { Features::cargodmodebool = true; }
		if (Global::accarsuperman == 1) { Features::fcbool = true; }
		if (Global::acspeedometerMPH == 1) { Features::showspeedbool = true; }
		if (Global::acspeedometerKMPH == 1) { Features::showspeedbool = true; }
		if (Global::acbulletprooftires == 1) { Features::bulletprooftiresbool = true; }
		if (Global::achornboost == 1) { Features::boostbool = true; }
		if (Global::acdriveonwater == 1) { Features::dowbool = true; }
		if (Global::acenginealwayson == 1) { Features::enginealwaysonbool = true; }
		if (Global::acnofallfrombike == 1) { Features::nofallbool = true; }
	}
}

void Features::inispawner(const char* fileName)
{
	float forward = 5.f;
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float playerHeading = ENTITY::GET_ENTITY_HEADING(playerPed);

	float xVect = forward * sin(degToRad(playerHeading)) * -1.0f;
	float yVect = forward * cos(degToRad(playerHeading));

	const char* file = fileName;
	Log::Msg(file);
	wchar_t path[MAX_PATH];
	char target2[MAX_PATH];
	HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, path);
	if (result == S_OK)
		wcstombs(target2, path, MAX_PATH);

	strcat(target2, "\\AztralFiles\\INIs\\"_Secure);


	char buffer[512]; // <- only storage for 512 characters.
	strncpy(buffer, target2, sizeof(buffer));
	strncat(buffer, file, sizeof(buffer));

	const char* inifile = buffer;
	
	Log::Msg(inifile);

	CIniFileA ini;

	bool loaded = ini.Load(inifile, false);
	if (loaded)
	{
		//for (SecIndex::const_iterator itr = ini.GetSections().begin(); itr != ini.GetSections().end(); ++itr)
		string sectionstring = "Vehicle";
		CIniSectionA* section = ini.GetSection(sectionstring); //returns the name of the section
															 // (*itr)->GetKeys().size() will return the number of keys associated with this section
		string sectionname = section->GetSectionName();

		Log::Msg(sectionname.c_str());

		if (strcmp(sectionname.c_str(), "Vehicle") == 0)
		{
			//Do vehicle stuff here
			string keystring = "Model";
			CIniKeyA* key = section->GetKey(keystring);
			string keyname = key->GetKeyName();// returns is the name of the key
			Vehicle veh;
			Vehicle playerveh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			
			if (strcmp(keyname.c_str(), "Model") == 0)
			{
				string model = key->GetValue();// returns is the value of the key
				int model1;
				sscanf(model.c_str(), "%d", &model1);//model1 == int of model
				Log::Msg(model.c_str());
				veh = Features::do_spawn_vehicle(model1);
				Vehicle playerveh = veh;
				
			}
			else
			{
				notifyBottom("Model Name not found or error occured"_Secure);
				return;
			}
			//Do vehicle options here
			for (KeyIndexA::const_iterator kitr = section->GetKeys().begin(); kitr != section->GetKeys().end(); kitr++)
			{
				keyname = (*kitr)->GetKeyName();
				static char* numerical[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "23", "24", "26", "25", "48", "37", "27", "28", "30", "33", "34", "35", "38", "39", "45" };
				for (int i = 0; i < 32; i++)
				{
					if (strcmp(keyname.c_str(), numerical[i]) == 0)
					{
						string name = keyname;// returns is the value of the key
						int name1;
						sscanf(name.c_str(), "%d", &name1);//name1 == int of keyname
						
						
						string value = (*kitr)->GetValue();// returns is the value of the key
						int value1;
						sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
						VEHICLE::SET_VEHICLE_MOD(veh, name1, value1, 1);
						
					}
				}
				static char* toggles[] = { "TOGGLE_17", "TOGGLE_18", "TOGGLE_19", "TOGGLE_20", "TOGGLE_21", "TOGGLE_22" };
				for (int j = 0; j < 6; j++)
				{
					if (strcmp(keyname.c_str(), toggles[j]) == 0)
					{
						string value = (*kitr)->GetValue();// returns is the value of the key
						int value1;
						sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue

						if (j == 0)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 17, value1);
						}
						if (j == 1)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, value1);
						}
						if (j == 2)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 19, value1);
						}
						if (j == 3)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, value1);
						}
						if (j == 4)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 21, value1);
						}
						if (j == 5)
						{
							VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, value1);
						}
					}
				}
				if (strcmp(keyname.c_str(), "PaintFade") == 0)
				{
					string value = (*kitr)->GetValue();// returns is the value of the key
					int value1;
					sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
					VEHICLE::SET_VEHICLE_ENVEFF_SCALE(veh, value1);
				}
				if (strcmp(keyname.c_str(), "NeonEnabled") == 0)
				{
					string value = (*kitr)->GetValue();// returns is the value of the key
					int value1;
					sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, value1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, value1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, value1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, value1);
				}
				static char* othercolors[] = { "NeonR", "NeonG", "NeonB", "SmokeR", "SmokeG", "SmokeB", "WindowTint" };
				for (int k = 0; k < 7; k++)
				{
					if (strcmp(keyname.c_str(), othercolors[k]) == 0)
					{
						string value = (*kitr)->GetValue();// returns is the value of the key
						int value1;
						sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
						int r, g, b;

						if (k == 0)
						{
							VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &r, &g, &b);
							VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, value1, g, b);
						}
						if (k == 1)
						{
							VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &r, &g, &b);
							VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, value1, b);
						}
						if (k == 2)
						{
							VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &r, &g, &b);
							VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, value1);
						}
						if (k == 3)
						{
							VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, value1, g, b);
						}
						if (k == 4)
						{
							VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, r, value1, b);
						}
						if (k == 5)
						{
							VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, r, g, value1);
						}
						if (k == 6)
						{
							VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, value1);
						}
					}
				}
				const char* paintoptions[] = { "PrimaryPaintT", "SecondaryPaintT", "PrimaryPaint", "SecondaryPaint", "Pearlescent", "PrimaryR", "PrimaryG", "PrimaryB", "SecondaryR", "SecondaryG", "SecondaryB", "WheelsColor", "WheelsType" };
				for (int l = 0; l < 13; l++)
				{
					if (strcmp(keyname.c_str(), paintoptions[l]) == 0)
					{
						string value = (*kitr)->GetValue();// returns is the value of the key
						int value1;
						sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
						int r, g, b, type, paint, pearl, wheelcolor, wheeltype;

						if (l == 0)
						{
							VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &type, &paint, &pearl);
							VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, value1, paint, 0);
						}
						if (l == 1)
						{
							VEHICLE::GET_VEHICLE_MOD_COLOR_2(veh, &type, &paint);
							VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, value1, paint);
						}
						if (l == 2)
						{
							VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &type, &paint, &pearl);
							VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, type, value1, 0);
						}
						if (l == 3)
						{
							VEHICLE::GET_VEHICLE_MOD_COLOR_2(veh, &type, &paint);
							VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, type, value1);
						}
						if (l == 4)
						{
							VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearl, &wheelcolor);
							VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, value1, wheelcolor);
						}
						if (l == 5)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, value1, g, b);
						}
						if (l == 6)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, r, value1, b);
						}
						if (l == 7)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, r, g, value1);
						}
						if (l == 8)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, value1, g, b);
						}
						if (l == 9)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, r, value1, b);
						}
						if (l == 10)
						{
							VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &r, &g, &b);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, r, g, value1);
						}
						if (l == 11)
						{
							VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearl, &wheelcolor);
							VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, pearl, value1);
						}
						if (l == 12)
						{
							VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, value1);
						}
					}
				}
			}
			//NON Vehicle Stuff Here:
			for (SecIndexA::const_iterator itr = ini.GetSections().begin(); itr != ini.GetSections().end(); ++itr)
			{
				string sectionname = (*itr)->GetSectionName(); //returns the name of the section
															   // (*itr)->GetKeys().size() will return the number of keys associated with this section
				Log::Msg(sectionname.c_str());
				if (strcmp(sectionname.c_str(), "Vehicle") != 0)
				{
					float X, Y, Z, RotX, RotY, RotZ;
					int AModel;
					for (KeyIndexA::const_iterator kitr = (*itr)->GetKeys().begin(); kitr != (*itr)->GetKeys().end(); kitr++)
					{
						keyname = (*kitr)->GetKeyName(); // (*kitr)->GetKeyName() returns is the name of the key
						
						
						const char* props[] = { "X", "Y", "Z", "RotX", "RotY", "RotZ", "Model" };
						for (int n = 0; n < 7; n++)
						{
							if (strcmp(keyname.c_str(), props[n]) == 0)
							{
								if (n == 0) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									X = value1; 
								}
								if (n == 1) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									Y = value1; 
								}
								if (n == 2) 
								{
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									Z = value1; 
								}
								if (n == 3) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									RotX = value1; 
								}
								if (n == 4) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									RotY = value1; 
								}
								if (n == 5) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									float value1;
									sscanf(value.c_str(), "%f", &value1);//value1 == int of keyvalue
									RotZ = value1; 
								}
								if (n == 6) 
								{ 
									string value = (*kitr)->GetValue();// returns is the value of the key
									int value1;
									sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
									AModel = value1; 
								}
							}
						}
					}
					//AModel == 1952396163 ? true : false;
					Vehicle playerveh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
					Entity object = OBJECT::CREATE_OBJECT(AModel, playerPos.x, playerPos.y, playerPos.z, true, false, true);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(object, playerveh, -1, X, Y, Z, RotX, RotY, RotZ, 0, 0, AModel == 1952396163 ? true : false, 0, 0, 1);
					
				}
			}
			ENTITY::PROCESS_ENTITY_ATTACHMENTS(playerveh);
		}
		else
		{
			notifyBottom("Non-Vehicle INIs not Supported YET"_Secure);
			//Non-INI Vehicle Spawning HERE
			/*for (SecIndexA::const_iterator itr = ini.GetSections().begin(); itr != ini.GetSections().end(); ++itr)
			{
				string sectionname = (*itr)->GetSectionName(); //returns the name of the section
															   // (*itr)->GetKeys().size() will return the number of keys associated with this section
				Log::Msg(sectionname.c_str());
				if (strcmp(sectionname.c_str(), "Vehicle") != 0)
				{
					int X, Y, Z, RotX, RotY, RotZ, AModel;
					for (KeyIndexA::const_iterator kitr = (*itr)->GetKeys().begin(); kitr != (*itr)->GetKeys().end(); kitr++)
					{
						string keyname = (*kitr)->GetKeyName(); // (*kitr)->GetKeyName() returns is the name of the key

						string value = (*kitr)->GetValue();// returns is the value of the key
						int value1;
						sscanf(value.c_str(), "%d", &value1);//value1 == int of keyvalue
						const char* props[] = { "X", "Y", "Z", "RotX", "RotY", "RotZ", "Model" };
						for (int n = 0; n < 7; n++)
						{
							if (strcmp(keyname.c_str(), props[n]) == 0)
							{
								if (n == 0) { X = value1; }
								if (n == 1) { Y = value1; }
								if (n == 2) { Z = value1; }
								if (n == 3) { RotX = value1; }
								if (n == 4) { RotY = value1; }
								if (n == 5) { RotZ = value1; }
								if (n == 6) { AModel = value1; }
							}
						}
					}
					OBJECT::CREATE_OBJECT(AModel, playerPos.x, playerPos.y, playerPos.z, true, false, true);
				}
			}*/
		}
	}
	else
	{
		notifyBottom("Load Failed"_Secure);
	}
}




void Features::customcopcar()
{
	float forward = 5.f;
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vector3 playerPos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float playerHeading = ENTITY::GET_ENTITY_HEADING(playerPed);

	float xVect = forward * sin(degToRad(playerHeading)) * -1.0f;
	float yVect = forward * cos(degToRad(playerHeading));

	struct VehicleOptions
	{
		int zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, twentythree, twentyfour, twentysix, twentyfive, fourtyeight, thirtyseven, twentyseven, twentyeight, thirty, thirtythree, thirtyfour, thirtyfive, thirtysix, thirtynine, fourtyfive, PaintFade, DashColor, DashLightColor, Bulletproof, CustomTyres, TOGGLE_17, TOGGLE_18, TOGGLE_19, TOGGLE_20, TOGGLE_21, TOGGLE_22, NeonEnabled, NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB, WindowTint, Model, PrimaryPaintT, SecondaryPaintT, PrimaryPaint, SecondaryPaint, Pearlescent, PrimaryR, PrimaryG, PrimaryB, SecondaryR, SecondaryG, SecondaryB, WheelsColor, WheelsType, Unknown, PlateIndex;
	};

	
	VehicleOptions Options;
	{
		Options.zero = 10;
		Options.one = -1;
		Options.two = -1;
		Options.three = -1;
		Options.four = 1;
		Options.five = -1;
		Options.six = -1;
		Options.seven = -1;
		Options.eight = -1;
		Options.nine = -1;
		Options.ten = -1;
		Options.eleven = 3;
		Options.twelve = 2;
		Options.thirteen = 2;
		Options.fourteen = 38;
		Options.fifteen = -1;
		Options.sixteen = 4;
		Options.twentythree = -1;
		Options.twentyfour = -1;
		Options.twentysix = -1;
		Options.twentyfive = -1;
		Options.fourtyeight = -1;
		Options.thirtyseven = -1;
		Options.twentyseven = -1;
		Options.twentyeight = -1;
		Options.thirty = -1;
		Options.thirtythree = -1;
		Options.thirtyfour = -1;
		Options.thirtyfive = -1;
		Options.thirtysix = -1;
		Options.thirtynine = -1;
		Options.fourtyfive = -1;
		Options.PaintFade = 0.203922;
		Options.DashColor = 105508;
		Options.DashLightColor = 105508;
		Options.Bulletproof = 1;
		Options.CustomTyres = 0;
		Options.TOGGLE_17 = 0;
		Options.TOGGLE_18 = 1;
		Options.TOGGLE_19 = 0;
		Options.TOGGLE_20 = 1;
		Options.TOGGLE_21 = 0;
		Options.TOGGLE_22 = 0;
		Options.NeonEnabled = 0;
		Options.NeonR = 255;
		Options.NeonG = 0;
		Options.NeonB = 255;
		Options.SmokeR = 255;
		Options.SmokeG = 128;
		Options.SmokeB = 0;
		Options.WindowTint = -1;
		Options.Model = GAMEPLAY::GET_HASH_KEY("sanctus");
		Options.PrimaryPaintT = 2;
		Options.SecondaryPaintT = 2;
		Options.PrimaryPaint = 12;
		Options.SecondaryPaint = 12;
		Options.Pearlescent = 0;
		Options.PrimaryR = 5;
		Options.PrimaryG = 5;
		Options.PrimaryB = 5;
		Options.SecondaryR = 5;
		Options.SecondaryG = 5;
		Options.SecondaryB = 5;
		Options.WheelsColor = 27;
		Options.WheelsType = 6;
		Options.Unknown = 0;
		Options.PlateIndex = 0;
	}

	Features::spawn_vehicle("sanctus");
	Vehicle veh = lastspawnedcar;

	{
			VEHICLE::SET_VEHICLE_MOD(veh, 0, Options.zero, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 1, Options.one, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 2, Options.two, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 3, Options.three, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 4, Options.four, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 5, Options.five, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 6, Options.six, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 7, Options.seven, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 8, Options.eight, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 9, Options.nine, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 10, Options.ten, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 11, Options.eleven, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 12, Options.twelve, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 13, Options.thirteen, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 14, Options.fourteen, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 15, Options.fifteen, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 16, Options.sixteen, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 23, Options.twentythree, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 24, Options.twentyfour, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 26, Options.twentysix, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 25, Options.twentyfive, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 48, Options.fourtyeight, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 37, Options.thirtyseven, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 27, Options.twentyseven, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 28, Options.twentyeight, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 30, Options.thirty, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 33, Options.thirtythree, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 34, Options.thirtyfour, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 35, Options.thirtyfive, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 38, Options.thirtysix, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 39, Options.thirtynine, 1);
			VEHICLE::SET_VEHICLE_MOD(veh, 45, Options.fourtyfive, 1);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(veh, Options.PaintFade);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 17, Options.TOGGLE_17);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, Options.TOGGLE_18);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 19, Options.TOGGLE_19);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, Options.TOGGLE_20);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 21, Options.TOGGLE_21);
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, Options.TOGGLE_22);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, Options.NeonEnabled);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, Options.NeonEnabled);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, Options.NeonEnabled);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, Options.NeonEnabled);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, Options.NeonR, Options.NeonG, Options.NeonB);
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, Options.SmokeR, Options.SmokeG, Options.SmokeB);
			VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, Options.WindowTint);
			VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, Options.PrimaryPaintT, Options.PrimaryPaint, 0);
			VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, Options.SecondaryPaintT, Options.SecondaryPaint);
			VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, Options.Pearlescent, Options.WheelsColor);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Options.PrimaryR, Options.PrimaryG, Options.PrimaryB);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Options.SecondaryR, Options.SecondaryG, Options.SecondaryB);
			VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, Options.WheelsType);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, Options.PlateIndex);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "RIDER");

		}

	bool incar = true;

	if (incar)
		{
			Vehicle vehicle = veh;
			ENTITY::SET_ENTITY_INVINCIBLE(vehicle, incar);
			ENTITY::SET_ENTITY_PROOFS(vehicle, incar, incar, incar, incar, incar, incar, incar, incar);
			VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
			VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, incar);
			VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, incar);
			VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !incar);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !incar);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !incar);
			VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !incar);
			VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !incar);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !incar);
			VEHICLE::SET_VEHICLE_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !incar);
		}

	{
			Entity object0 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object0, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object1 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object1, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object2 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object2, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object3 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object3, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object4 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object4, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object5 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object5, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object6 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object6, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object7 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object7, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object8 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object8, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object9 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object9, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object10 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object10, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object11 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object11, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object12 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object12, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object13 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object13, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object14 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object14, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object15 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object15, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object16 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object16, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object17 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object17, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object18 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object18, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object19 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object19, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object20 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object20, veh, -1, -0.05, 0.85, -0.2, 0, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object21 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object21, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object22 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object22, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object23 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object23, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object24 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object24, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object25 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object25, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object26 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object26, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object27 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object27, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object28 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object28, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object29 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object29, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object30 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object30, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object31 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object31, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object32 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object32, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object33 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object33, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object34 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object34, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object35 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object35, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object36 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object36, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object37 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object37, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object38 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object38, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object39 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object39, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object40 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object40, veh, -1, 0.05, 0.85, -0.2, 0, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object41 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object41, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object42 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object42, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object43 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object43, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object44 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object44, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object45 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object45, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object46 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object46, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object47 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object47, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object48 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object48, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object49 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object49, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object50 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object50, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object51 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object51, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object52 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object52, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object53 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object53, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object54 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object54, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object55 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object55, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object56 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object56, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object57 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object57, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object58 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object58, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object59 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object59, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object60 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object60, veh, -1, 0.05, -0.7, -0.25, 90, 90, 0, 0, 0, 0, 0, 0, 1);
			Entity object61 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object61, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object62 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object62, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object63 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object63, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object64 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object64, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object65 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object65, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object66 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object66, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object67 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object67, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object68 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object68, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object69 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object69, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object70 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object70, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object71 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object71, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object72 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object72, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object73 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object73, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object74 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object74, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object75 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object75, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object76 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object76, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object77 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object77, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object78 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object78, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object79 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object79, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
			Entity object80 = OBJECT::CREATE_OBJECT(3229200997, playerPos.x, playerPos.y, playerPos.z, true, false, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(object80, veh, -1, -0.05, -0.7, -0.25, 90, -90, 0, 0, 0, 0, 0, 0, 1);
		}
	
	ENTITY::PROCESS_ENTITY_ATTACHMENTS(veh);
		//ENTITY::ATTACH_ENTITY_TO_ENTITY(veh2, veh, 0, 0, 0, 0, vehx, vehy, vehz, 0, 0, 0, 0, 0, 0);
	
}

void Features::BypassOnlineVehicle(Vehicle vehicle)
{
	Player player = PLAYER::PLAYER_ID();
	DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
	DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
	DECORATOR::DECOR_REGISTER("Not_Allow_As_Saved_Veh", 3);
	DECORATOR::DECOR_REGISTER("MPBitset", 3);
	DECORATOR::DECOR_SET_INT(vehicle, "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(player));
	DECORATOR::DECOR_SET_INT(vehicle, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(player)));
	DECORATOR::DECOR_SET_INT(vehicle, "Not_Allow_As_Saved_Veh", 0);
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
	VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, false);
}


// REQUiRMENTS


Vector3 Features::GetCoordsInfrontOfCam(float distance)
{
	Vector3 GameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 GameplayCamCoord = CAM::GET_GAMEPLAY_CAM_COORD();

	Vector3 Plane;

	float tan = (cos(GameplayCamRot.x) * distance);
	Plane.x = ((sin(GameplayCamRot.z * -1.0f) * tan) + GameplayCamCoord.x);
	Plane.y = ((cos(GameplayCamRot.z * -1.0f) * tan) + GameplayCamCoord.y);
	Plane.z = ((sin(GameplayCamRot.x) * distance) + GameplayCamCoord.z);


	return Vector3(Plane);
}



//-----------------  Remove targetted Objects  -----------------
//
// Just enable RemoveObjects Bool and shoot an object to remove it ( Client Sided )
//
//-----------------------------------------------------

bool Features::RemoveObjects = false;
void Features::RemoveObjectsLoop(bool toggle)
{
	if ((RemoveObjects == true) && (CONTROLS::IS_CONTROL_PRESSED(0, ControlFrontendLt)))
	{
		Entity EntityID;
		PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityID);
			if (ENTITY::IS_ENTITY_AN_OBJECT(EntityID) == true)
			{
				ENTITY::DELETE_ENTITY(&EntityID);
			}
	}
	if ((RemoveObjects == true) && (IsKeyPressed(0x02)))
	{
		Entity EntityID;
		PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityID);
		if (ENTITY::IS_ENTITY_AN_OBJECT(EntityID) == true)
		{
			ENTITY::DELETE_ENTITY(&EntityID);
		}
	}
}


//-----------------  Gravity gun ( Pickup and launch )  -----------------
//
// Just enable GravityGun Bool and shoot an object to pick it up shoot again to launch it
//
// When object is picked up it makes it see through and undoes this when launched ( object moves infront of you when picked up )
// ObjectHash[] can be used to display Hash of picked up object ( usefull for spawning uknown object Best display this in lower left under radar )
//
//-----------------------------------------------------


bool Features::gravgun = false;


bool Features::GravityGun = false;
void Features::GravityGunLoop(bool toggle)
{
	if (GravityGun == true)
	{
		Entity EntityID;
		//PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityID);
		if (IsKeyPressed(0x02))
		{
			PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityID);
			if (ENTITY::IS_ENTITY_A_PED(EntityID) == true)
			{
				if (PED::IS_PED_IN_ANY_VEHICLE(EntityID, 0))
				{
					EntityID = PED::GET_VEHICLE_PED_IS_IN(EntityID, 0);
				}
			}
			//Features::gravgun = true;
			//ENTITY::SET_ENTITY_ALPHA(EntityID, 200, 0);
		//}
		//else if(IsKeyPressed(0x02) && Features::gravgun == true)
		//{
			ENTITY::SET_ENTITY_DYNAMIC(EntityID, 1);
			Vector3 Rotation = ENTITY::GET_ENTITY_ROTATION(EntityID, 2);
			Vector3 GameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
			ENTITY::SET_ENTITY_ROTATION(EntityID, GameplayCamRot.x, GameplayCamRot.y, GameplayCamRot.z, 2, 1);
			ENTITY::APPLY_FORCE_TO_ENTITY(EntityID, 1, 0, 25, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			//ENTITY::SET_ENTITY_ROTATION(EntityID, Rotation.x, Rotation.y, Rotation.z, 2, 1);
			//ENTITY::SET_ENTITY_ALPHA(EntityID, 255, 0);
			//Features::gravgun = false;
		}
		/*else
		{
			if (ENTITY::DOES_ENTITY_EXIST(EntityID) == true)
			{
				Vector3 GetCoordsInfrontOfCam = Features::GetCoordsInfrontOfCam(10.f);
				ENTITY::SET_ENTITY_COORDS(EntityID, GetCoordsInfrontOfCam.x, GetCoordsInfrontOfCam.y, GetCoordsInfrontOfCam.z, 1, 0, 0, 1);
			}
		}*/
	}
}


/*
Vehicle Saver
*/

std::string activeSavedVehicleSlotName;

ENTDatabase* database = NULL;

ENTDatabase* Features::get_database()
{
	database = new ENTDatabase();
	if (!database->open())
	{
		Log::Fatal("Failed to Open Database"_Secure);
		database = NULL;
		return database;
	}
	return database;
}

void Features::save_current_vehicle(int slot)
{
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	int newslot = slot;

	if (bPlayerExists)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

			std::ostringstream ss;
			if (newslot != -1)
			{
				ss << activeSavedVehicleSlotName;
			}
			else
			{
				ss << "Saved Vehicle " << (newslot);
			}

			auto existingText = ss.str();
			std::string result = show_keyboard("Vehicle Name", (char*)existingText.c_str());
			if (!result.empty())
			{
				ENTDatabase* database = Features::get_database();
				if (database->save_vehicle(veh, result, newslot))
				{
					notifyMap("~g~Saved Vehicle");
				}
				else
				{
					notifyMap("~r~Save Error");
				}
			}
		}
		else
		{
			notifyMap("~r~Player isn't in a vehicle");
		}
	}
}



bool Features::spawn_saved_car(int slot)
{
	ENTDatabase* database = Features::get_database();

	std::vector<SavedVehicleDBRow*> savedVehs = database->get_saved_vehicles(slot);

	SavedVehicleDBRow* savedVeh = savedVehs.at(0);
	database->populate_saved_vehicle(savedVeh);

	std::string caption = savedVeh->saveName;

	Vehicle veh = do_spawn_vehicle(savedVeh->model, caption, false);
	if (veh == -1)
	{
		notifyMap("~r~Spawn failed");
	}
	else
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, (savedVeh->burstableTyres == 1) ? TRUE : FALSE);

		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, savedVeh->plateType);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, (char*)savedVeh->plateText.c_str());

		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, savedVeh->windowTint);

		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, savedVeh->wheelType);

		for each (SavedVehicleExtraDBRow *extra in savedVeh->extras)
		{
			VEHICLE::SET_VEHICLE_EXTRA(veh, extra->extraID, (extra->extraState == 1) ? 0 : -1);
		}

		for each (SavedVehicleModDBRow *mod in savedVeh->mods)
		{
			if (mod->isToggle)
			{
				VEHICLE::TOGGLE_VEHICLE_MOD(veh, mod->modID, mod->modState);
			}
			else
			{
				VEHICLE::SET_VEHICLE_MOD(veh, mod->modID, mod->modState, 0);
			}
		}

		int currmod = VEHICLE::GET_VEHICLE_MOD(veh, 23);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, currmod, savedVeh->customTyres);
		VEHICLE::SET_VEHICLE_MOD(veh, 24, currmod, savedVeh->customTyres);

		if (savedVeh->livery != -1)
		{
			VEHICLE::SET_VEHICLE_LIVERY(veh, savedVeh->livery);
		}

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, savedVeh->colourExtraPearl, savedVeh->colourExtraWheel);
		VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, savedVeh->colourMod1Type, savedVeh->colourMod1Colour, savedVeh->colourMod1P3);
		VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, savedVeh->colourMod2Type, savedVeh->colourMod2Colour);

		VEHICLE::SET_VEHICLE_COLOURS(veh, savedVeh->colourPrimary, savedVeh->colourSecondary);

		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, savedVeh->colourExtraPearl, savedVeh->colourExtraWheel);

		if (savedVeh->colourCustom1RGB[0] != -1 &&
			savedVeh->colourCustom1RGB[1] != -1 &&
			savedVeh->colourCustom1RGB[2] != -1)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, savedVeh->colourCustom1RGB[0], savedVeh->colourCustom1RGB[1], savedVeh->colourCustom1RGB[2]);
		}

		if (savedVeh->colourCustom2RGB[0] != -1 &&
			savedVeh->colourCustom2RGB[1] != -1 &&
			savedVeh->colourCustom2RGB[2] != -1)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, savedVeh->colourCustom2RGB[0], savedVeh->colourCustom2RGB[1], savedVeh->colourCustom2RGB[2]);
		}

		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(veh, savedVeh->fadeLevel);

		VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, savedVeh->dirtLevel);

		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, savedVeh->neonEnablement[0] == 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, savedVeh->neonEnablement[1] == 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, savedVeh->neonEnablement[2] == 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, savedVeh->neonEnablement[3] == 1);

		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, savedVeh->neonRGB[0], savedVeh->neonRGB[1], savedVeh->neonRGB[2]);

		if (savedVeh->tyreSmokeRGB[0] != -1 &&
			savedVeh->tyreSmokeRGB[1] != -1 &&
			savedVeh->tyreSmokeRGB[2] != -1)
		{
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, savedVeh->tyreSmokeRGB[0], savedVeh->tyreSmokeRGB[1], savedVeh->tyreSmokeRGB[2]);
		}

		if (VEHICLE::IS_VEHICLE_A_CONVERTIBLE(veh, 0))
		{
			if (savedVeh->convertibleRoofUp)
			{
				VEHICLE::SET_CONVERTIBLE_ROOF(veh, 1);
			}
			else
			{
				VEHICLE::SET_CONVERTIBLE_ROOF(veh, 0);
			}
		}



		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}

	for (std::vector<SavedVehicleDBRow*>::iterator it = savedVehs.begin(); it != savedVehs.end(); ++it)
	{
		delete (*it);
	}
	savedVehs.clear();

	return false;
}


Vehicle Features::do_spawn_vehicle(DWORD model, std::string modelTitle, bool cleanup)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			WAIT(0);
		}

		Vector3 minDimens;
		Vector3 maxDimens;
		GAMEPLAY::GET_MODEL_DIMENSIONS(model, &minDimens, &maxDimens);
		float spawnOffY = max(5.0f, 2.0f + 0.5f * (maxDimens.y - minDimens.y));

		FLOAT lookDir = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0.0, spawnOffY, 0.0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, lookDir, 1, 0);
		NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		//if we're mid-air, don't put it on the ground
		if (!ENTITY::IS_ENTITY_IN_AIR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())))
		{
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		}

		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_ENGINE, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ENGINE) - 1, 1); //Engine
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_BRAKES, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_BRAKES) - 1, 1); //Brakes
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRANSMISSION, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRANSMISSION) - 1, 1); //Transmission
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, MOD_TURBO, 1); //Turbo Tuning
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, MOD_XENONLIGHTS, 1); //Headlights

		PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, -1);
		if (VEHICLE::IS_THIS_MODEL_A_HELI(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))
		{
			VEHICLE::SET_HELI_BLADES_FULL_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())));
		}

		VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0.0f);
		//VEHICLE::_SET_VEHICLE_PAINT_FADE(veh, 0.0f);

		WAIT(0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		if (cleanup)
		{
			ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
		}

		std::ostringstream ss;
		ss << modelTitle << " spawned";
		notifyBottom(ss.str());

		return veh;
	}
	return -1;
}

Vehicle Features::do_spawn_vehicle(DWORD model)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			WAIT(0);
		}

		Vector3 minDimens;
		Vector3 maxDimens;
		GAMEPLAY::GET_MODEL_DIMENSIONS(model, &minDimens, &maxDimens);
		float spawnOffY = max(5.0f, 2.0f + 0.5f * (maxDimens.y - minDimens.y));

		FLOAT lookDir = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0.0, spawnOffY, 0.0);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(model, coords.x, coords.y, coords.z, lookDir, 1, 0);
		NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		//if we're mid-air, don't put it on the ground
		if (!ENTITY::IS_ENTITY_IN_AIR(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())))
		{
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		}

		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_ENGINE, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_ENGINE) - 1, 1); //Engine
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_BRAKES, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_BRAKES) - 1, 1); //Brakes
		VEHICLE::SET_VEHICLE_MOD(veh, MOD_TRANSMISSION, VEHICLE::GET_NUM_VEHICLE_MODS(veh, MOD_TRANSMISSION) - 1, 1); //Transmission
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, MOD_TURBO, 1); //Turbo Tuning
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, MOD_XENONLIGHTS, 1); //Headlights

		PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, -1);
		if (VEHICLE::IS_THIS_MODEL_A_HELI(ENTITY::GET_ENTITY_MODEL(veh)) || VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))
		{
			VEHICLE::SET_HELI_BLADES_FULL_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())));
		}

		VEHICLE::SET_VEHICLE_DIRT_LEVEL(veh, 0.0f);
		//VEHICLE::_SET_VEHICLE_PAINT_FADE(veh, 0.0f);

		WAIT(0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		if (true)
		{
			ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
		}

		return veh;
	}
	return -1;
}

void Features::rename_saved_car(int slot)
{
	std::string result = show_keyboard(NULL, (char*)activeSavedVehicleSlotName.c_str());
	if (!result.empty())
	{
		ENTDatabase* database = get_database();
		database->rename_saved_vehicle(result, slot);

		activeSavedVehicleSlotName = result;
	}
}

void Features::delete_saved_car(int slot)
{
	ENTDatabase* database = get_database();
	database->delete_saved_vehicle(slot);
}

void Features::overwrite_saved_car(int slot)
{
	ENTDatabase* database = get_database();
	Features::save_current_vehicle(slot);
}

/*
Prop Spawner
*/

bool Features::propCreationIsInvincible = false;
bool Features::propCreationIsOnFire = false;
bool Features::propCreationIsImmovable = false;
bool Features::propCreationHasGravity = true;
int Features::propCreationAlphaIndex = 0;

std::vector<SpawnedPropInstance*> Features::propsWeCreated;

const std::vector<std::string> Features::ALPHA_LABELS = { "100%", "80%", "60%", "40%", "20%" };
const int Features::ALPHA_VALUES[] = { 255, 204, 153, 102, 51 };
std::string lastCustomPropSpawn;

int lastSelectedCategoryIndex = 0;
int lastSelectedPropIndex = 0;

int propCategorySelection = 0;
int propSelection = 0;

bool creationParam1 = true;
bool creationParam2 = false;
bool creationParam3 = true;



bool Features::PropSpawn(int choice)
{
	if (choice == -1)
	{
		std::string result = show_keyboard(NULL, (char*)lastCustomPropSpawn.c_str());
		if (!result.empty())
		{
			lastCustomPropSpawn = result;
			Hash hash = GAMEPLAY::GET_HASH_KEY((char*)result.c_str());
			if (!STREAMING::IS_MODEL_IN_CDIMAGE(hash) || !STREAMING::IS_MODEL_VALID(hash))
			{
				std::ostringstream ss;
				ss << "Couldn't find model '" << result << "'";
				notifyBottom(ss.str());
				return false;
			}
			else
			{
				Features::do_spawn_model(GAMEPLAY::GET_HASH_KEY((char*)result.c_str()), (char*)result.c_str(), result, false);
			}
		}
		return false;
	}

	if (choice != lastSelectedCategoryIndex)
	{
		propSelection = 0;
		lastSelectedCategoryIndex = choice;
	}
	return false;

}

void Features::do_spawn_prop(PropInfo prop, bool silent) 
{
	Hash propHash = GAMEPLAY::GET_HASH_KEY((char *)prop.model);

	if (!STREAMING::IS_MODEL_IN_CDIMAGE(propHash) || !STREAMING::IS_MODEL_VALID(propHash))
	{
		if (!silent)
		{
			std::ostringstream ss;
			ss << "Model " << prop.model << " is not valid";
			notifyBottom(ss.str());
		}

		std::ostringstream ss2;
		ss2 << "INVALID-MODEL: " << prop.model;
		notifyBottom(ss2.str());
		return;
	}

	Features::do_spawn_model(propHash, prop.model, prop.label, silent);
}


void Features::do_spawn_model(Hash propHash, char* model, std::string title, bool silent)
{
	STREAMING::REQUEST_MODEL(propHash);
	DWORD now = GetTickCount();
	while (!STREAMING::HAS_MODEL_LOADED(propHash) && GetTickCount() < now + 5000)
	{
		WAIT(0);
	}

	if (!STREAMING::HAS_MODEL_LOADED(propHash))
	{
		return;
	}

	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	FLOAT look = ENTITY::GET_ENTITY_HEADING(playerPed);
	FLOAT lookAni = look + 180.00;
	FLOAT lookOff = look + 90.00;
	FLOAT vecX = 0;
	FLOAT vecY = 0;
	BOOL getPosParam1 = 1;
	BOOL getPosParam2 = 1;
	BOOL getPosParam3 = 1;

	FLOAT spawnOffX = 0.0f;
	FLOAT spawnOffY = 3.5f;
	FLOAT spawnOffZ = 0.0f;

	Vector3 minDimens;
	Vector3 maxDimens;
	GAMEPLAY::GET_MODEL_DIMENSIONS(propHash, &minDimens, &maxDimens);
	spawnOffY = max(3.5f, 1.3f * max(maxDimens.x - minDimens.x, maxDimens.y - minDimens.y));
	spawnOffZ = 0.0f;

	Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, spawnOffX, spawnOffY, spawnOffZ);

	float objZBase = 0;
	bool translatable = Features::get_ground_height_at_position(coords, &objZBase);

	Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(propHash, coords.x, coords.y, coords.z, creationParam1, creationParam2, creationParam3);
	ENTITY::SET_ENTITY_VELOCITY(obj, 0.0f, 0.0f, 0.0f);
	ENTITY::SET_ENTITY_ROTATION(obj, 0, 0, 0, 0, false);

	if (ENTITY::DOES_ENTITY_EXIST(obj))
	{
		ENTITY::SET_ENTITY_COLLISION(obj, 1, 0);

		//place on the ground doesn't work on half the items, so do it ourselves
		Vector3 curLocation = ENTITY::GET_ENTITY_COORDS(obj, 0);
		if (translatable)
		{
			if (minDimens.z < 0)
			{
				objZBase -= minDimens.z;
			}
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(obj, curLocation.x, curLocation.y, objZBase, 1, 1, 1);
		}
		else
		{
			//best effort in case of failure
			OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj);
		}

		ENTITY::SET_ENTITY_HAS_GRAVITY(obj, Features::propCreationHasGravity);

		if (Features::propCreationIsInvincible)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(obj, TRUE);
			ENTITY::SET_ENTITY_PROOFS(obj, 1, 1, 1, 1, 1, 1, 1, 1);
			ENTITY::SET_ENTITY_CAN_BE_DAMAGED(obj, FALSE);
		}
		ENTITY::FREEZE_ENTITY_POSITION(obj, Features::propCreationIsImmovable);

		if (!Features::propCreationIsImmovable)
		{
			//this unfreezes it
			ENTITY::APPLY_FORCE_TO_ENTITY(obj, 3, 0, 0, 0.1, 0, 0, 0, 0, 1, 1, 0, 0, 1);
			OBJECT::SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(obj, TRUE);
		}

		ENTITY::SET_ENTITY_LOAD_COLLISION_FLAG(obj, true);

		if (Features::propCreationIsOnFire)
		{
			FIRE::START_ENTITY_FIRE(obj);
		}

		ENTITY::SET_ENTITY_ALPHA(obj, Features::ALPHA_VALUES[Features::propCreationAlphaIndex], false);

		SpawnedPropInstance* record = new SpawnedPropInstance();
		record->instance = obj;

		record->title = title;
		record->counter = Features::find_highest_instance_num_of_prop(propHash) + 1;
		record->isInvincible = Features::propCreationIsInvincible;
		record->isImmovable = Features::propCreationIsImmovable;
		record->hasGravity = Features::propCreationHasGravity;

		Features::propsWeCreated.push_back(record);
		manage_prop_set();
	}
	else
	{
		if (!silent)
		{
			std::ostringstream ss;
			ss << "Failed to create " << title;
			notifyBottom(ss.str());
		}

		std::ostringstream ss2;
		ss2 << "INVALID-PROP: " << model;
		notifyBottom(ss2.str());
		return;
	}

	if (!silent)
	{
		std::ostringstream ss;
		ss << "Spawned " << title;
		notifyBottom(ss.str());
	}

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(propHash);
	//ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&obj);
}

bool Features::get_ground_height_at_position(Vector3 coords, float* result)
{
	Hash propHash = GAMEPLAY::GET_HASH_KEY("prop_veg_crop_03_cab");
	STREAMING::REQUEST_MODEL(propHash);
	DWORD now = GetTickCount();
	while (!STREAMING::HAS_MODEL_LOADED(propHash) && GetTickCount() < now + 5000)
	{
		WAIT(0);
	}

	if (!STREAMING::HAS_MODEL_LOADED(propHash))
	{
		return false;
	}

	Vector3 minDimens;
	Vector3 maxDimens;
	GAMEPLAY::GET_MODEL_DIMENSIONS(propHash, &minDimens, &maxDimens);

	Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(propHash, coords.x, coords.y, coords.z, creationParam1, creationParam2, creationParam3);
	ENTITY::SET_ENTITY_VISIBLE(obj, false, false);
	OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj);
	Vector3 objLocation = ENTITY::GET_ENTITY_COORDS(obj, 0);
	float objHeight = ENTITY::GET_ENTITY_HEIGHT(obj, objLocation.x, objLocation.y, objLocation.z, 1, 0);

	*result = objLocation.z - objHeight;
	if (minDimens.z < 0)
	{
		*result += minDimens.z;
	}

	OBJECT::DELETE_OBJECT(&obj);

	return true;
}

void Features::manage_prop_set()
{
	std::vector<SpawnedPropInstance*>::iterator it;
	for (it = Features::propsWeCreated.begin(); it != Features::propsWeCreated.end();)
	{
		SpawnedPropInstance* prop = *it;
		if (!ENTITY::DOES_ENTITY_EXIST(prop->instance))
		{
			it = Features::propsWeCreated.erase(it);
			delete prop;
		}
		else
		{
			++it;
		}
	}
}

void Features::deleteprops()
{
	int count = 0;
	for each (SpawnedPropInstance* prop in Features::propsWeCreated)
	{
		Object obj = prop->instance;
		if (ENTITY::DOES_ENTITY_EXIST(obj))
		{
			count++;
			OBJECT::DELETE_OBJECT(&obj);
		}
	}
	Features::manage_prop_set();
	std::ostringstream ss;
	ss << count << " object" << (count != 1 ? "s" : "") << " removed";
	notifyBottom(ss.str());
}

void Features::deleteprop1(int propindex)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);
	OBJECT::DELETE_OBJECT(&prop->instance);
	Features::propsWeCreated.erase(propsWeCreated.begin() + propindex);
	Features::manage_prop_set();
	notifyBottom("Object deleted");
}

void Features::explodeprop1(int propindex)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);
	Vector3 position = ENTITY::GET_ENTITY_COORDS(prop->instance, TRUE);
	FIRE::ADD_EXPLOSION(position.x, position.y, position.z, 60, 3.0f, true, false, 0);
}

bool Features::invincprop1bool = false;
void Features::invincprop1(int propindex, bool toggle)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);

	ENTITY::SET_ENTITY_INVINCIBLE(prop->instance, toggle);
	ENTITY::SET_ENTITY_CAN_BE_DAMAGED(prop->instance, !toggle);
	ENTITY::SET_ENTITY_PROOFS(prop->instance, toggle, toggle, toggle, toggle, toggle, toggle, toggle, toggle);
}
bool Features::immoveprop1bool = false;
void Features::immoveprop1(int propindex, bool toggle)
{
	SpawnedPropInstance* prop = get_prop_at_index(propindex);

	OBJECT::SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(prop->instance, !toggle);
	ENTITY::FREEZE_ENTITY_POSITION(prop->instance, toggle);
	if (!toggle)
	{
		//this unfreezes it
		ENTITY::APPLY_FORCE_TO_ENTITY(prop->instance, 3, 0, 0, 0.1, 0, 0, 0, 0, 1, 1, 0, 0, 1);
	}
}
bool Features::fireprop1bool = false;
void Features::fireprop1(int propindex, bool toggle)
{
	SpawnedPropInstance* prop = get_prop_at_index(propindex);
	if (toggle)
	{
		bool isInvinc = prop->isInvincible;
		ENTITY::SET_ENTITY_PROOFS(prop->instance, isInvinc, false, isInvinc, isInvinc, isInvinc, isInvinc, isInvinc, isInvinc);
		FIRE::START_ENTITY_FIRE(prop->instance);
	}
	else
	{
		FIRE::STOP_ENTITY_FIRE(prop->instance);
		Vector3 position = ENTITY::GET_ENTITY_COORDS(prop->instance, TRUE);
		FIRE::STOP_FIRE_IN_RANGE(position.x, position.y, position.z, 5.0f);
	}
}
bool Features::gravityprop1bool = false;
void Features::gravityprop1(int propindex, bool toggle)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);
	ENTITY::SET_ENTITY_HAS_GRAVITY(prop->instance, toggle);
}

void Features::moveprop1(int propindex)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);
	//MenuLevelHandler::MoveMenu(propmoversub);
	begin_prop_placement(prop);
}

void Features::attachprop1(int propindex)
{
	SpawnedPropInstance* prop = Features::get_prop_at_index(propindex);
	//ENTITY::ATTACH_ENTITY_TO_ENTITY(prop->instance, Entity entity2, int boneIndex, float xPos, float yPos, float zPos, float xRot, float yRot, float zRot, BOOL p9, BOOL useSoftPinning, false, false, int vertexIndex, BOOL fixedRot)
}

SpawnedPropInstance* Features::get_prop_at_index(int i)
{
	if (i < 0 || i > Features::propsWeCreated.size() - 1)
	{
		return NULL;
	}
	SpawnedPropInstance* prop = Features::propsWeCreated.at(i);
	return prop;
}

int Features::find_highest_instance_num_of_prop(Hash model)
{
	int highestFound = 0;
	std::vector<SpawnedPropInstance*>::iterator it;
	for (it = Features::propsWeCreated.begin(); it != Features::propsWeCreated.end(); it++)
	{
		SpawnedPropInstance* prop = *it;
		Hash entryModel = ENTITY::GET_ENTITY_MODEL(prop->instance);
		if (model == entryModel && prop->counter > highestFound)
		{
			highestFound = prop->counter;
		}
	}
	return highestFound;
}


int lightsint = 0;
double startTime = timeGetTime();
bool Features::CustomLightsbool = false;
void Features::CustomLights(bool toggle)
{
	double currentTime = timeGetTime() - startTime;

	if (currentTime <= 50) 
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(veh, 10.f);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 255, 0, 0);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);		
	}
	else
	{
		Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(playerPed, 0);
		VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(veh, 10.f);
		VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, 0, 0, 255);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
		if (currentTime >= 100)
		{
			startTime = timeGetTime();
		}
	}
}





void Features::OrbitalCannon()
{

	Vector3 vParam0 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), false);
	Vector3 vParam1 = ENTITY::GET_ENTITY_ROTATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 2);
	AUDIO::PLAY_SOUND_FRONTEND(-1, "cannon_active", "dlc_xm_orbital_cannon_sounds", 1);
	AUDIO::SET_VARIABLE_ON_SOUND(AUDIO::GET_SOUND_ID(), "Firing", 1.f);

	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
	GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x, vParam0.y, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
	FIRE::ADD_EXPLOSION(vParam0.x, vParam0.y, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
	for (int i = 1; i == 50; i++)
	{
		FIRE::ADD_EXPLOSION(vParam0.x + i, vParam0.y, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x + i, vParam0.y, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x - i, vParam0.y, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x - i, vParam0.y, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x, vParam0.y + i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x, vParam0.y + i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x, vParam0.y - i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x, vParam0.y - i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x + i, vParam0.y + i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x + i, vParam0.y + i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x - i, vParam0.y - i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x - i, vParam0.y - i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x + i, vParam0.y - i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x + i, vParam0.y - i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);
		FIRE::ADD_EXPLOSION(vParam0.x - i, vParam0.y + i, vParam0.z, 60, FLT_MAX, false, false, 1000.f);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_xm_orbital");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2("scr_xm_orbital_blast", vParam0.x - i, vParam0.y + i, vParam0.z, vParam1.x, vParam1.y, vParam1.z, 1065353216, 0, 0, 1);

	}
	AUDIO::PLAY_SOUND_FROM_COORD(-1, "DLC_XM_Explosions_Orbital_Cannon", vParam0.x, vParam0.y, vParam0.z, 0, 1, 0, 0);

	CONTROLS::SET_PAD_SHAKE(0, 500, 256);
	CAM::SHAKE_CAM(CAM::GET_RENDERING_CAM(), "GAMEPLAY_EXPLOSION_SHAKE", 1.5f);
}


void Features::jetcar()
{
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Vehicle veh1 = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);


	Features::do_spawn_vehicle(-1281684762);

	
	Vehicle veh2 = PED::GET_VEHICLE_PED_IS_USING(playerPed);

	/*if (NETWORK::NETWORK_IS_SESSION_STARTED() == true)
	{
		NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(veh2, 1);
	}*/

	ENTITY::SET_ENTITY_VISIBLE(veh2, false, 0);
	
	RequestControlOfEnt(veh1);
	RequestControlOfEnt(veh2);

	ENTITY::ATTACH_ENTITY_TO_ENTITY(veh1, veh2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	ENTITY::PROCESS_ENTITY_ATTACHMENTS(veh2);

	
}

bool Features::black_hole_bool = false;
void Features::black_hole(bool toggle)
{
	if (toggle)
	{
		Ped		playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		Entity	ent = NULL;
		static Object	bh = NULL;
		static clock_t	refreshTmr = clock();
		static clock_t	bhTmr = NULL;
		if (bh == NULL)
			if (!spawn_object(0x6b795ebc, &bh))	//"prop_alien_egg_01"
				return;
			else
			{
				bhTmr = clock();
				ENTITY::FREEZE_ENTITY_POSITION(bh, true);
			}
		else if (!ENTITY::IS_AN_ENTITY(bh))
		{
			bhTmr = 0;
			return;
		}
		const int ElementAmount = 50;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped *peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			Entity ent = peds[OffsetID];
			RequestControlOfEnt(ent);

			if (ent != NULL && ENTITY::IS_AN_ENTITY(ent))
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(ent, 0);
				Vector3 bhPos = ENTITY::GET_ENTITY_COORDS(bh, 0);

				if (get_dist_bet(bhPos, pos) < 5.f)
				{
					Vector3 tpcoords;
					tpcoords.x = -3735.f;
					tpcoords.y = -4400.f;
					tpcoords.z = 10.f;
					teleport_to_coords(ent, tpcoords);
				}
				else
				{
					Vector3 pos_bhPos = sub(bhPos, pos);
					float	x = pos_bhPos.x < 0.f ? pos_bhPos.x * -1.f : pos_bhPos.x,
						y = pos_bhPos.y < 0.f ? pos_bhPos.y * -1.f : pos_bhPos.y;
					float	ratio = 75.f / (x > y ? x : y);
					ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, pos_bhPos.x * ratio, pos_bhPos.y * ratio, ENTITY::IS_ENTITY_A_PED(ent) ? 1.f : .5f, (float)rndInt(-2, 2), (float)rndInt(-2, 2), (float)rndInt(-2, 2), -1, false, true, true, false, true);
				}
			}
		}

		Vehicle *vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false))
			{
				Entity ent = vehs[OffsetID];
				RequestControlOfEnt(ent);

				if (ent != NULL && ENTITY::IS_AN_ENTITY(ent))
				{
					Vector3 pos = ENTITY::GET_ENTITY_COORDS(ent, 0);
					Vector3 bhPos = ENTITY::GET_ENTITY_COORDS(bh, 0);

					if (get_dist_bet(bhPos, pos) < 5.f)
					{
						Vector3 tpcoords;
						tpcoords.x = -3735.f;
						tpcoords.y = -4400.f;
						tpcoords.z = 10.f;
						teleport_to_coords(ent, tpcoords);
					}
					else
					{
						Vector3 pos_bhPos = sub(bhPos, pos);
						float	x = pos_bhPos.x < 0.f ? pos_bhPos.x * -1.f : pos_bhPos.x,
							y = pos_bhPos.y < 0.f ? pos_bhPos.y * -1.f : pos_bhPos.y;
						float	ratio = 75.f / (x > y ? x : y);
						ENTITY::APPLY_FORCE_TO_ENTITY(ent, 1, pos_bhPos.x * ratio, pos_bhPos.y * ratio, ENTITY::IS_ENTITY_A_PED(ent) ? 1.f : .5f, (float)rndInt(-2, 2), (float)rndInt(-2, 2), (float)rndInt(-2, 2), -1, false, true, true, false, true);
					}
				}
			}
		}
	}
}


void Features::explosive_ammo(bool toggle)
{
	Vector3 pos = {};
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), &pos) && Features::expammo)
		FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 60, 1.f, true, false, 0.f);
}

bool Features::CarWeaponLoopBool = false;
void Features::CarWeaponLoop(bool toggle)
{
	if (toggle && IsKeyPressed(VK_SPACE))
	{
		int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0);
		int damage = 250;
		int weaponHash = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET");

		float launchSpeed = 3000.0f;

		Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, 0.6f, 0.6707f, 0.3711f);

		Vector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, -0.6f, 0.6707f, 0.3711f);

		Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, 0.6f, 5.0707f, 0.3711f);

		Vector3 getcoords4 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(VehicleHandle, -0.6f, 5.0707f, 0.3711f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, damage, 0, weaponHash, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1, 1, launchSpeed);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, damage, 0, weaponHash, PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1, 1, launchSpeed);
	}
}