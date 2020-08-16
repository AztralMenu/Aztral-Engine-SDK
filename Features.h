#pragma once

namespace Features {

	void UpdatePerTick();

	void RequestControlOfid(Entity netid);

	void clearanim();

	extern bool MouseControlBool;
	void MouseControl(bool toggle);
	
	void spawn_vehicle2(char* toSpawn);

	void spawn_vehicle_on_player(char* toSpawn);
	Vehicle ramplayer(DWORD toSpawn);

	void OrbitalCannon();

	extern bool blockcallsbool;
	void blockcalls(bool toggle);

	extern bool explodenearbyvehiclesbool;
	void explodenearbyvehicles(bool toggle);
	
	extern int delay;

	extern bool spectate[32];
	void specter(Player target);

	extern int Levels[8000];

	void deposit(long amount);
	void withdraw(long amount);

	void trapcage(Ped ped);
	
	extern bool superboostbool;
	void supercarboost(bool toggle);

	extern bool fuckhornlolbool;
	void fuckhornlol(bool toggle);


	extern bool boostbool;
	void carboost(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);


	extern bool fcbool;
	void FlyingCarLoop(bool toggle);

	//extern bool PotatosMassacurebool;
	void PotatosMassacure();

	extern bool fatbitchesbool;
	void fatbitches(bool toggle);
	void fatbitches2();
	void fatbitches3();

	extern bool angrypedsbool;
	void angrypeds(bool toggle);

	extern bool magnetpedsbool;
	void magnetpeds(bool toggle);	
	
	extern bool magnetpedsbool1;
	void magnetpeds1(bool toggle);

	extern bool purgebool;
	void purge(bool toggle);

	extern bool SelfDriveBool;
	void SelfDrive(bool toggle);

	//extern bool gunrunningbypassbool;
	//void gunrunningbypass(bool toggle);


	extern int amount2;
	extern int amount3;
	extern bool poweranimated;
	extern bool spawnincar;
	extern bool spawnmaxed;
	extern bool givespawnmaxed;
	extern bool Banked;

	void torque(int torque1);
	extern bool torquebool;
	
	void maxspeed(bool toggle);
	extern bool maxspeedbool;

	extern bool earrapebool;
	void earrape(bool toggle);

	void spawn_vehicle(char* toSpawn);

	void dirtycar();

	void TPtoWaypoint();

	void TPtoObjective();

	void doAnimation(char* anim, char* animid);

	extern bool PTFXBool;
	void PTFXCALL();

	extern char* call1s;
	extern char* call2s;
	extern char* names;

	extern bool PTFXOBool;
	void PTFXCALLO();

	extern char* call1o;
	extern char* call2o;
	extern char* nameo;
	extern Player target;
	
	extern bool esper;
	void esp(Player target);
	
	extern bool stealthbool;
	void stealth(bool toggle);

	extern bool stealth1bool;
	void stealth1(bool toggle);
	
	extern bool stealth2bool;
	void stealth2(bool toggle);

	void MoneyEdit(int towallet, int tobank);

	extern bool stealth3bool;
	void stealth3(bool toggle);

	extern bool stealth15bool;
	void Stealth15(bool toggle);

	//extern bool penisbool;
	//void penis(bool toggle);
	
	extern bool Banked2;

	void SetRank(int rpvalue);

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool fuckedhandling[32];
	void fuckhandling(Player player);

	extern bool cargodmodebool;
	void cargodmode(bool toggle);

	extern bool nofallbool;
	void nofall(bool toggle);

	extern bool lowerveh100bool;
	void lowerveh100(bool toggle);
	
	extern bool Godmodebool;
	void Godmode(bool toggle);

	extern bool SemiGodModebool;
	void SemiGodMode(bool toggle);

	extern bool lowerveh50bool;
	void lowerveh50(bool toggle);

	extern bool fastrunbool;
	void fastrun(bool toggle);
	extern bool fastswimbool;
	void fastswim(bool toggle);

	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);
	void maxvehicle();
	void flipup();

	extern bool rlbool;
	void HasPaintLoop(bool toggle);

	extern bool bulletprooftiresbool;
	void bulletprooftires();

	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	extern int TimePD9;

	extern bool RPLoop;
	void rpLoop(bool toggle);
	extern int RPLoopDelay;

	extern bool deletenearbyvehiclesbool;
	void deletenearbyvehicles(bool toggle);

	extern bool forcefieldbool;
	void forcefield(bool toggle);

	extern bool Upgradecarsbool;
	void Upgradecars(bool toggle);

	extern bool Rainbowcarbool;
	void Rainbowcar(bool toggle);

	extern bool killpedsbool;
	void killpeds(bool toggle);

	extern bool ForceWavebool;
	void ForceWave(bool toggle);

	extern bool superpunchbool;
	void superpunch();

	extern bool explodepedsbool;
	void explodepeds(bool toggle);

	extern bool riskymodebool;
	void riskymode(bool toggle);

	extern bool storymodebool;
	void storymode(bool toggle);

	void teleportallcoordsns(Vector3 target);

	bool cstrcmp(const char* s1, const char* s2);

	void Smallstuff(bool toggle);
	extern bool Gettiny;


	void superman(bool toggle);
	//void OSKR(bool toggle);

	extern bool osk;
	extern bool Superman;

	extern bool infammo;
	void noreloadv(bool toggle);

	void Freezer(Player target);
	extern bool freezed[35];

	extern bool fireammo;
	extern bool expammo;
	extern bool rbgun;

	extern bool rapidfirer;
	void rapidmaker();

	extern bool Forcefield;
	
	void Fireammos(bool toggle);
	void Expammos(bool toggle);
	void RBGuner(bool toggle);

	extern bool NoClipping;
	void NoClipme(bool toggle);

	extern bool Nothrowshit;
	void NoRagdoll(bool toggle);

	extern int Wantedshit;
	void ChangeWanted(int level);
	int GetWanted(Player player);

	extern int attachobj[100];
	extern int attachobj1[100];
	extern int nuattach;
	extern int nuattach1;
	void attachobjects2(char* object);

	extern bool attachobjectsCrashbool;
	void attachobjectsCrash(bool toggle);
	void DeleteEntity(int Handle);

	//extern bool cashdropbool;
	//void cashdrop(Player targer);
	extern bool cashdropbool[32];

	//extern bool bigcashdropbool;
	//void bigcashdrop(bool toggle);

	//extern bool Pickupdropbool;
	//void Pickupdrop(bool toggle);

	extern bool storycashdropbool;
	void storycashdrop(bool toggle);

	extern bool twofitybool[32];
	void twofity(Player targer);

	extern bool twofitybool1[32];
	void twofity1(Player target);


	extern bool fakebagsbool[32];
	void fakebags(Player targer);

	extern bool cashdrop2bool[32];
	extern bool cashdrop3bool;

	void cashdrop2(Player target);

	extern bool neverwanted;
	void NeverGetWanted(bool toggle);

	extern bool slomobool;
	void slomonig(bool toggle);

	extern bool OffTheRadarBool;
	void OffTheRadar(bool toggle);

	extern bool MoneyGunBool;
	void Moneygun(bool toggle);

	extern bool Alieneggsbool;
	void Alieneggs(bool toggle);

	extern bool BagGunBool; 
	void Baggun(bool toggle);

	extern bool goldgunbool;
	void goldgun(bool toggle);

	extern bool Arcadegunbool;
	void Arcadegun(bool toggle); //note: remove these broken features dumbass

	extern bool Planeweaponbool;
	void Planeweapon(bool toggle);

	extern bool Pedweaponbool;
	void Pedweapon(bool toggle);

	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);
		//void Teleportall(Player player);
	}

	extern bool Disablephonebool;
	void Disablephone(bool toggle);

	extern bool Ghostmode;
	void ghostmode(bool toggle);

	extern bool mobileRadio;
	void mobilevoid(bool toggle);

	extern bool Superjump;
	void superjump(bool toggle);
	
	//extern bool StealthLooptoggle2;
	//void StealthLoop2(bool toggle);
	
	extern bool rainbowmenu;
	void Rainbowmenu(bool toggle);

	extern bool antiremoveweptoggle;
	void RemoveWeaponProtex(bool toggle);

	extern bool antiptfxtoggle;
	void PTFXProtex(bool toggle);

	extern bool antifreeze;
	void FreezeProtex(bool toggle);

	extern bool antiexplosion;
	void AntiFireExplosion(bool toggle);

	extern bool antiblametoggle;
	void AntiBlame(bool toggle);

	extern bool antiremotetoggle;
	void AntiRemote(bool toggle);

	extern bool antimoneydrop;
	void MoneyDropBypass(bool toggle);

	extern bool antivotekickbool;
	void antivotekick(bool toggle);

	extern bool antitp;
	void TPProtex(bool toggle);
		
	extern bool PTLoopedO[35];
	void PTLopperO(Player target);

	extern bool showcoordsbool;
	void showcoords(bool toggle);
	void savecoords();

	extern bool showspeedbool;
	void showspeed(bool toggle);
	
	extern bool showspeed1bool;
	void showspeed1(bool toggle);

	extern bool downforcebool;
	void downforce(int down);

	void WriteToFile(std::string filename, std::string content);

	extern bool CheckConfigBool;
	void CheckConfig(bool toggle);

	extern bool CheckAutoBool;
	void CheckAuto(bool toggle);

	extern bool ChauffeurBool;
	void Chauffeur(bool toggle);
	void delpeds();

	extern bool RemoveObjects;
	void RemoveObjectsLoop(bool toggle);
	extern bool GravityGun;
	void GravityGunLoop(bool toggle);
	Vector3 GetCoordsInfrontOfCam(float distance);
	extern bool gravgun;


	void save_current_vehicle(int slot);
	bool spawn_saved_car(int slot);
	void rename_saved_car(int slot);
	void delete_saved_car(int slot);
	void overwrite_saved_car(int slot);
	Vehicle do_spawn_vehicle(DWORD model, std::string modelTitle, bool cleanup);
	Vehicle do_spawn_vehicle(DWORD model);
	ENTDatabase* get_database();

	extern bool PropSpawn(int choice);
	void do_spawn_prop(PropInfo prop, bool silent);
	void do_spawn_model(Hash propHash, char* model, std::string title, bool silent);
	bool get_ground_height_at_position(Vector3 coords, float* result);
	void manage_prop_set();

	extern bool propCreationIsInvincible;
	extern bool propCreationIsOnFire;
	extern bool propCreationIsImmovable;
	extern bool propCreationHasGravity;
	extern int propCreationAlphaIndex;
	extern const std::vector<std::string> ALPHA_LABELS;
	extern const int ALPHA_VALUES[];
	void deleteprops();

	void deleteprop1(int propindex);
	void explodeprop1(int propindex);
	void moveprop1(int propindex);
	void invincprop1(int propindex, bool toggle);
	void immoveprop1(int propindex, bool toggle);
	void fireprop1(int propindex, bool toggle);
	void gravityprop1(int propindex, bool toggle);
	void attachprop1(int propindex);
	extern bool invincprop1bool;
	extern bool immoveprop1bool;
	extern bool fireprop1bool;
	extern bool gravityprop1bool;
	SpawnedPropInstance* get_prop_at_index(int i);

	extern std::vector<SpawnedPropInstance*> propsWeCreated;
	int find_highest_instance_num_of_prop(Hash model);

	extern bool CustomLightsbool;
	void CustomLights(bool toggle);
	void customcopcar();
	void inispawner(const char* fileName);
	
	extern bool FireWheelsBool;
	void FireWheels(bool toggle);

	void BypassOnlineVehicle(Vehicle vehicle);
	void jetcar();

	extern bool black_hole_bool;
	void black_hole(bool toggle);

	extern bool ceomoneybool[32];
	void ceomoney(Player player);

	void explosive_ammo(bool toggle);

	extern bool CarWeaponLoopBool;
	void CarWeaponLoop(bool toggle);
}



