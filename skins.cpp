#include "stdafx.h"
#include "skins.h"
#include "weapons.h"
#include "Features.h"


#pragma warning(disable : 4192)


//std::string chosenSkinName = "";

DWORD mModelHash;

bool DEBUG_MODE_SKINS = false;



int skinMainMenuPosition = 0;

int skinPropsMenuPosition = 0;

int skinDetailMenuIndex = 0;
int skinDetailMenuValue = 0;
int skinPropsCategoryValue = 0;

int activeSavedSkinIndex = -1;
std::string activeSavedSkinSlotName;
int lastKnownSavedSkinCount = 0;
bool skinSaveMenuInterrupt = false;
bool skinSaveSlotMenuInterrupt = false;
bool requireRefreshOfSkinSaveSlots = false;
bool requireRefreshOfSkinSlotMenu = false;
int skinPropsDrawablePosition[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

const std::vector<std::string> SKINS_PLAYER_CAPTIONS{ "Michael", "Franklin", "Trevor", "MP Female", "MP Male" };
const std::vector<std::string> SKINS_PLAYER_VALUES{ "player_zero", "player_one", "player_two", "mp_f_freemode_01", "mp_m_freemode_01" };

const std::vector<std::string> SKINS_ANIMAL_CAPTIONS{ "Boar", "Cat", "Chimp", "Chop", "Cormorant", "Cow", "Coyote", "Crow", "Deer", "Dolphin", "Fish", "German Shepherd", "Grey Whale", "Hammerhead Shark", "Hawk", "Hen", "Humpback", "Husky", "Killer Whale", "Mountain Lion", "Pig", "Pigeon", "Poodle", "Pug", "Rabbit", "Rat", "Retriever", "Rhesus", "Rottweiler", "Seagull", "Stingray", "Tiger Shark", "Westy" };
const std::vector<std::string> SKINS_ANIMAL_VALUES{ "a_c_boar", "a_c_cat_01", "a_c_chimp", "a_c_chop", "a_c_cormorant", "a_c_cow", "a_c_coyote", "a_c_crow", "a_c_deer", "a_c_dolphin", "a_c_fish", "a_c_shepherd", "a_c_whalegrey", "a_c_sharkhammer", "a_c_chickenhawk", "a_c_hen", "a_c_humpback", "a_c_husky", "a_c_killerwhale", "a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_poodle", "a_c_pug", "a_c_rabbit_01", "a_c_rat", "a_c_retriever", "a_c_rhesus", "a_c_rottweiler", "a_c_seagull", "a_c_stingray", "a_c_sharktiger", "a_c_westy" };

const std::vector<std::string> SKINS_GENERAL_CAPTIONS{ "Abigail Mathers (CS)", "Abigail Mathers (IG)", "Abner", "African American Male", "Agent (CS)", "Agent (IG)", "Agent 14 (CS)", "Agent 14 (IG)", "Air Hostess", "Air Worker Male", "Al Di Napoli Male", "Alien", "Altruist Cult Mid-Age Male", "Altruist Cult Old Male", "Altruist Cult Old Male 2", "Altruist Cult Young Male", "Altruist Cult Young Male 2", "Amanda De Santa (CS)", "Amanda De Santa (IG)", "Ammu-Nation City Clerk", "Ammu-Nation Rural Clerk", "Andreas Sanchez (CS)", "Andreas Sanchez (IG)", "Anita Mendoza", "Anton Beaudelaire", "Anton Beaudelaire", "Armenian Boss", "Armenian Goon", "Armenian Goon 2", "Armenian Lieutenant", "Armoured Van Security", "Armoured Van Security", "Armoured Van Security 2", "Army Mechanic", "Ashley Butler (CS)", "Ashley Butler (IG)", "Autopsy Tech", "Autoshop Worker", "Autoshop Worker 2", "Azteca", "Baby D", "Ballas East Male", "Ballas Female", "Ballas OG", "Ballas OG (IG)", "Ballas Original Male (IG)", "Ballas South Male", "Bank Manager (CS)", "Bank Manager (IG)", "Bank Manager Male", "Barber Female", "Barman", "Barry (CS)", "Barry (IG)", "Bartender", "Bartender (Rural)", "Baywatch Female", "Baywatch Male", "Beach Female", "Beach Male", "Beach Male 2", "Beach Muscle Male", "Beach Muscle Male 2", "Beach Old Male", "Beach Tramp Female", "Beach Tramp Male", "Beach Young Female", "Beach Young Male", "Beach Young Male 2", "Beach Young Male 3", "Best Man (IG)", "Beverly Felton (CS)", "Beverly Felton (IG)", "Beverly Hills Female", "Beverly Hills Female 2", "Beverly Hills Male", "Beverly Hills Male 2", "Beverly Hills Young Female", "Beverly Hills Young Female 2", "Beverly Hills Young Female 3", "Beverly Hills Young Female 4", "Beverly Hills Young Male", "Beverly Hills Young Male 2", "Bigfoot (CS)", "Bigfoot (IG)", "Bike Hire Guy", "Biker Chic Female", "Black Ops Soldier", "Black Ops Soldier 2", "Black Ops Soldier 3", "Black Street Male", "Black Street Male 2", "Bodybuilder Female", "Bouncer", "Brad (CS)", "Brad (IG)", "Brad's Cadaver (CS)", "Breakdancer Male", "Bride", "Bride (IG)", "Burger Drug Worker", "Burger Drug Worker", "Busboy", "Business Casual", "Business Female 2", "Business Male", "Business Young Female", "Business Young Female 2", "Business Young Female 3", "Business Young Female 4", "Business Young Male", "Business Young Male 2", "Business Young Male 3", "Busker", "Car 3 Guy 1", "Car 3 Guy 1 (IG)", "Car 3 Guy 2", "Car 3 Guy 2 (IG)", "Car Buyer (CS)", "Casey (CS)", "Casey (IG)", "Chef", "Chef", "Chef (CS)", "Chef (IG)", "Chef (IG)", "Chemical Plant Security", "Chemical Plant Worker", "Chinese Boss", "Chinese Goon", "Chinese Goon", "Chinese Goon 2", "Chinese Goon Older", "Chip", "Claude Speed", "Clay Jackson (The Pain Giver) (IG)", "Clay Simons (The Lost) (CS)", "Clay Simons (The Lost) (IG)", "Cletus", "Cletus (IG)", "Clown", "Construction Worker", "Construction Worker 2", "Cop", "Cop Female", "Cop Male", "Corpse Female", "Corpse Young Female", "Corpse Young Female 2", "Crew Member", "Cris Formage (CS)", "Cris Formage (IG)", "Customer", "Cyclist Male", "Cyclist Male", "Dale (CS)", "Dale (IG)", "Dave Norton (CS)", "Dave Norton (IG)", "Dead Hooker", "Dealer", "Debra (CS)", "Denise (CS)", "Denise (IG)", "Denise's Friend", "Devin (CS)", "Devin (IG)", "Devin's Security", "Dima Popov (CS)", "Dima Popov (IG)", "DOA Man", "Dock Worker", "Dock Worker", "Doctor", "Dom Beasley (CS)", "Dom Beasley (IG)", "Doorman", "Downhill Cyclist", "Downtown Female", "Downtown Male", "Dr. Friedlander (CS)", "Dr. Friedlander (IG)", "Dressy Female", "DW Airport Worker", "DW Airport Worker 2", "East SA Female", "East SA Female 2", "East SA Male", "East SA Male 2", "East SA Young Female", "East SA Young Female 2", "East SA Young Female 3", "East SA Young Male", "East SA Young Male 2", "Ed Toh", "Epsilon Female", "Epsilon Male", "Epsilon Male 2", "Epsilon Tom (CS)", "Epsilon Tom (IG)", "Ex-Army Male", "Ex-Mil Bum", "Fabien (CS)", "Fabien (IG)", "Factory Worker Female", "Factory Worker Male", "Families CA Male", "Families DD Male", "Families DNF Male", "Families Female", "Families FOR Male", "Families Gang Member?", "Families Gang Member? (IG)", "Farmer", "Fat Black Female", "Fat Cult Female", "Fat Latino Male", "Fat White Female", "Female Agent", "Ferdinand Kerimov (Mr. K) (CS)", "Ferdinand Kerimov (Mr. K) (IG)", "FIB Architect", "FIB Mugger", "FIB Office Worker", "FIB Office Worker 2", "FIB Security", "FIB Security", "FIB Suit (CS)", "FIB Suit (IG)", "Financial Guru", "Fireman Male", "Fitness Female", "Fitness Female 2", "Floyd Hebert (CS)", "Floyd Hebert (IG)", "FOS Rep?", "Free Mode Female", "Free Mode Male", "Gaffer", "Garbage Worker", "Gardener", "Gay Male", "Gay Male 2", "General Fat Male", "General Fat Male 2", "General Hot Young Female", "General Street Old Female", "General Street Old Male", "General Street Young Male", "General Street Young Male 2", "Gerald", "GLENSTANK? Male", "Golfer Male", "Golfer Young Female", "Golfer Young Male", "Griff", "Grip", "Groom", "Groom (IG)", "Grove Street Dealer", "Guadalope (CS)", "Guido", "Gun Vendor", "GURK? (CS)", "Hairdresser Male", "Hao", "Hao (IG)", "Hasidic Jew Male", "Hasidic Jew Young Male", "Hick", "Hick (IG)", "High Security", "High Security 2", "Highway Cop", "Hiker Female", "Hiker Male", "Hillbilly Male", "Hillbilly Male 2", "Hippie Female", "Hippie Male", "Hippie Male", "Hipster", "Hipster (IG)", "Hipster Female", "Hipster Female 2", "Hipster Female 3", "Hipster Female 4", "Hipster Male", "Hipster Male 2", "Hipster Male 3", "Hooker", "Hooker 2", "Hooker 3", "Hospital Scrubs Female", "Hot Posh Female", "Hugh Welsh", "Hunter (CS)", "Hunter (IG)", "IAA Security", "Impotent Rage", "Imran Shinowa", "Indian Male", "Indian Old Female", "Indian Young Female", "Indian Young Male", "Jane", "Janet (CS)", "Janet (IG)", "Janitor", "Janitor", "Jay Norris (IG)", "Jesco White (Tapdancing Hillbilly)", "Jesus", "Jetskier", "Jewel Heist Driver", "Jewel Heist Gunman", "Jewel Heist Hacker", "Jewel Thief", "Jeweller Assistant", "Jeweller Assistant (CS)", "Jeweller Assistant (IG)", "Jeweller Security", "Jimmy Boston (CS)", "Jimmy Boston (IG)", "Jimmy De Santa (CS)", "Jimmy De Santa (IG)", "Jogger Female", "Jogger Male", "Jogger Male 2", "John Marston", "Johnny Klebitz (CS)", "Johnny Klebitz (IG)", "Josef (CS)", "Josef (IG)", "Josh (CS)", "Josh (IG)", "Juggalo Female", "Juggalo Male", "Justin", "Karen Daniels (CS)", "Karen Daniels (IG)", "Kerry McIntosh (IG)", "Kifflom Guy", "Korean Boss", "Korean Female", "Korean Female 2", "Korean Lieutenant", "Korean Male", "Korean Old Female", "Korean Old Male", "Korean Young Male", "Korean Young Male", "Korean Young Male 2", "Korean Young Male 2", "Lamar Davis (CS)", "Lamar Davis (IG)", "Latino Handyman Male", "Latino Street Male 2", "Latino Street Young Male", "Latino Young Male", "Lazlow (CS)", "Lazlow (IG)", "Lester Crest (CS)", "Lester Crest (IG)", "Life Invader (CS)", "Life Invader (IG)", "Life Invader 2 (IG)", "Life Invader Male", "Line Cook", "Love Fist Willy", "LS Metro Worker Male", "Magenta (CS)", "Magenta (IG)", "Maid", "Malibu Male", "Mani", "Manuel (CS)", "Manuel (IG)", "Mariachi", "Marine", "Marine", "Marine 2", "Marine Young", "Marine Young 2", "Marine Young 3", "Mark Fostenburg", "Marnie Allen (CS)", "Marnie Allen (IG)", "Martin Madrazo (CS)", "Mary-Ann Quinn (CS)", "Mary-Ann Quinn (IG)", "Maude", "Maude (IG)", "Maxim Rashkovsky (CS)", "Maxim Rashkovsky (IG)", "Mechanic", "Mechanic 2", "Merryweather Merc", "Meth Addict", "Mexican", "Mexican (IG)", "Mexican Boss", "Mexican Boss 2", "Mexican Gang Member", "Mexican Goon", "Mexican Goon 2", "Mexican Goon 3", "Mexican Labourer", "Mexican Rural", "Mexican Thug", "Michelle (CS)", "Michelle (IG)", "Migrant Female", "Migrant Male", "Milton McIlroy (CS)", "Milton McIlroy (IG)", "Mime Artist", "Minuteman Joe (CS)", "Minuteman Joe (IG)", "Miranda", "Mistress", "Misty", "Molly (CS)", "Molly (IG)", "Money Man (CS)", "Money Man (IG)", "Motocross Biker", "Motocross Biker 2", "Movie Astronaut", "Movie Director", "Movie Premiere Female", "Movie Premiere Female (CS)", "Movie Premiere Male", "Movie Premiere Male (CS)", "Movie Star Female", "Mrs. Phillips (CS)", "Mrs. Phillips (IG)", "Mrs. Thornhill (CS)", "Mrs. Thornhill (IG)", "Natalia (CS)", "Natalia (IG)", "Nervous Ron (CS)", "Nervous Ron (IG)", "Nigel (CS)", "Nigel (IG)", "Niko Bellic", "OG Boss", "Old Man 1 (CS)", "Old Man 1 (IG)", "Old Man 2 (CS)", "Old Man 2 (IG)", "Omega (CS)", "Omega (IG)", "O'Neil Brothers (IG)", "Ortega", "Ortega (IG)", "Oscar", "Paige Harris (CS)", "Paige Harris (IG)", "Paparazzi Male", "Paparazzi Young Male", "Paramedic", "Party Target", "Partygoer", "Patricia (CS)", "Patricia (IG)", "Pest Control", "Peter Dreyfuss (CS)", "Peter Dreyfuss (IG)", "Pilot", "Pilot", "Pilot 2", "Pogo the Monkey", "Polynesian", "Polynesian Goon", "Polynesian Goon 2", "Polynesian Young", "Poppy Mitchell", "Porn Dude", "Postal Worker Male", "Postal Worker Male 2", "Priest (CS)", "Priest (IG)", "Princess", "Prison Guard", "Prisoner", "Prisoner", "Prisoner (Muscular)", "Prologue Driver", "Prologue Driver", "Prologue Host Female", "Prologue Host Male", "Prologue Host Old Female", "Prologue Mourner Female", "Prologue Mourner Male", "Prologue Security", "Prologue Security", "Prologue Security 2 (CS)", "Prologue Security 2 (IG)", "PROS?", "Ranger Female", "Ranger Male", "Reporter", "Republican Space Ranger", "Rival Paparazzo", "Road Cyclist", "Robber", "Rocco Pelosi", "Rocco Pelosi (IG)", "Rural Meth Addict Female", "Rural Meth Addict Male", "Russian Drunk (CS)", "Russian Drunk (IG)", "Sales Assistant (High-End)", "Sales Assistant (Low-End)", "Sales Assistant (Mask Stall)", "Sales Assistant (Mid-Price)", "Salton Female", "Salton Male", "Salton Male 2", "Salton Male 3", "Salton Male 4", "Salton Old Female", "Salton Old Male", "Salton Young Male", "Salvadoran Boss", "Salvadoran Goon", "Salvadoran Goon 2", "Salvadoran Goon 3", "Scientist", "Screenwriter", "Screenwriter (IG)", "Security Guard", "Sheriff Female", "Sheriff Male", "Shopkeeper", "Simeon Yetarian (CS)", "Simeon Yetarian (IG)", "Skater Female", "Skater Male", "Skater Young Male", "Skater Young Male 2", "Skid Row Female", "Skid Row Male", "Snow Cop Male", "Solomon Richards (CS)", "Solomon Richards (IG)", "South Central Female", "South Central Female 2", "South Central Latino Male", "South Central Male", "South Central Male 2", "South Central Male 3", "South Central Male 4", "South Central MC Female", "South Central Old Female", "South Central Old Female 2", "South Central Old Male", "South Central Old Male 2", "South Central Old Male 3", "South Central Young Female", "South Central Young Female 2", "South Central Young Female 3", "South Central Young Male", "South Central Young Male 2", "South Central Young Male 3", "South Central Young Male 4", "Sports Biker", "Spy Actor", "Spy Actress", "Stag Party Groom", "Steve Haines (CS)", "Steve Haines (IG)", "Street Performer", "Street Preacher", "Street Punk", "Street Punk 2", "Street Vendor", "Street Vendor Young", "Stretch (CS)", "Stretch (IG)", "Stripper", "Stripper", "Stripper 2", "Stripper 2", "Stripper Lite", "Stripper Lite", "Sunbather Male", "Surfer", "SWAT", "Sweatshop Worker", "Sweatshop Worker Young", "Talina (IG)", "Tanisha (CS)", "Tanisha (IG)", "Tao Cheng (CS)", "Tao Cheng (IG)", "Tao's Translator (CS)", "Tao's Translator (IG)", "Tattoo Artist", "Tennis Coach (CS)", "Tennis Coach (IG)", "Tennis Player Female", "Tennis Player Male", "Terry (CS)", "Terry (IG)", "The Lost MC Female", "The Lost MC Male", "The Lost MC Male 2", "The Lost MC Male 3", "Tom (CS)", "Tonya", "Tonya (IG)", "Topless", "Tourist Female", "Tourist Male", "Tourist Young Female", "Tourist Young Female 2", "Tracey De Santa (CS)", "Tracey De Santa (IG)", "Traffic Warden", "Traffic Warden (IG)", "Tramp Female", "Tramp Male", "Tramp Old Male", "Tramp Old Male", "Transport Worker Male", "Transvestite Male", "Transvestite Male 2", "Trucker Male", "Tyler Dixon (IG)", "Undercover Cop", "United Paper Man (CS)", "United Paper Man (IG)", "UPS Driver", "UPS Driver 2", "US Coastguard", "Vagos Female", "Valet", "Vespucci Beach Male", "Vespucci Beach Male 2", "Vinewood Douche", "Vinewood Female", "Vinewood Female 2", "Vinewood Female 3", "Vinewood Female 4", "Vinewood Male", "Vinewood Male 2", "Vinewood Male 3", "Vinewood Male 4", "Wade (CS)", "Wade (IG)", "Waiter", "Wei Cheng (CS)", "Wei Cheng (IG)", "White Street Male", "White Street Male 2", "Window Cleaner", "Yoga Female", "Yoga Male", "Zimbor (CS)", "Zimbor (IG)", "Zombie" };
const std::vector<std::string> SKINS_GENERAL_VALUES{ "csb_abigail", "ig_abigail", "u_m_y_abner", "a_m_m_afriamer_01", "csb_agent", "ig_agent", "csb_mp_agent14", "ig_mp_agent14", "s_f_y_airhostess_01", "s_m_y_airworker", "u_m_m_aldinapoli", "s_m_m_movalien_01", "a_m_m_acult_01", "a_m_o_acult_01", "a_m_o_acult_02", "a_m_y_acult_01", "a_m_y_acult_02", "cs_amandatownley", "ig_amandatownley", "s_m_y_ammucity_01", "s_m_m_ammucountry", "cs_andreas", "ig_andreas", "csb_anita", "csb_anton", "u_m_y_antonb", "g_m_m_armboss_01", "g_m_m_armgoon_01", "g_m_y_armgoon_02", "g_m_m_armlieut_01", "mp_s_m_armoured_01", "s_m_m_armoured_01", "s_m_m_armoured_02", "s_m_y_armymech_01", "cs_ashley", "ig_ashley", "s_m_y_autopsy_01", "s_m_m_autoshop_01", "s_m_m_autoshop_02", "g_m_y_azteca_01", "u_m_y_babyd", "g_m_y_ballaeast_01", "g_f_y_ballas_01", "csb_ballasog", "ig_ballasog", "g_m_y_ballaorig_01", "g_m_y_ballasout_01", "cs_bankman", "ig_bankman", "u_m_m_bankman", "s_f_m_fembarber", "s_m_y_barman_01", "cs_barry", "ig_barry", "s_f_y_bartender_01", "s_m_m_cntrybar_01", "s_f_y_baywatch_01", "s_m_y_baywatch_01", "a_f_m_beach_01", "a_m_m_beach_01", "a_m_m_beach_02", "a_m_y_musclbeac_01", "a_m_y_musclbeac_02", "a_m_o_beach_01", "a_f_m_trampbeac_01", "a_m_m_trampbeac_01", "a_f_y_beach_01", "a_m_y_beach_01", "a_m_y_beach_02", "a_m_y_beach_03", "ig_bestmen", "cs_beverly", "ig_beverly", "a_f_m_bevhills_01", "a_f_m_bevhills_02", "a_m_m_bevhills_01", "a_m_m_bevhills_02", "a_f_y_bevhills_01", "a_f_y_bevhills_02", "a_f_y_bevhills_03", "a_f_y_bevhills_04", "a_m_y_bevhills_01", "a_m_y_bevhills_02", "cs_orleans", "ig_orleans", "u_m_m_bikehire_01", "u_f_y_bikerchic", "s_m_y_blackops_01", "s_m_y_blackops_02", "s_m_y_blackops_03", "a_m_y_stbla_01", "a_m_y_stbla_02", "a_f_m_bodybuild_01", "s_m_m_bouncer_01", "cs_brad", "ig_brad", "cs_bradcadaver", "a_m_y_breakdance_01", "csb_bride", "ig_bride", "csb_burgerdrug", "u_m_y_burgerdrug_01", "s_m_y_busboy_01", "a_m_y_busicas_01", "a_f_m_business_02", "a_m_m_business_01", "a_f_y_business_01", "a_f_y_business_02", "a_f_y_business_03", "a_f_y_business_04", "a_m_y_business_01", "a_m_y_business_02", "a_m_y_business_03", "s_m_o_busker_01", "csb_car3guy1", "ig_car3guy1", "csb_car3guy2", "ig_car3guy2", "cs_carbuyer", "cs_casey", "ig_casey", "s_m_y_chef_01", "csb_chef", "csb_chef2", "ig_chef", "ig_chef2", "s_m_m_chemsec_01", "g_m_m_chemwork_01", "g_m_m_chiboss_01", "g_m_m_chigoon_01", "csb_chin_goon", "g_m_m_chigoon_02", "g_m_m_chicold_01", "u_m_y_chip", "mp_m_claude_01", "ig_claypain", "cs_clay", "ig_clay", "csb_cletus", "ig_cletus", "s_m_y_clown_01", "s_m_y_construct_01", "s_m_y_construct_02", "csb_cop", "s_f_y_cop_01", "s_m_y_cop_01", "u_f_m_corpse_01", "u_f_y_corpse_01", "u_f_y_corpse_02", "s_m_m_ccrew_01", "cs_chrisformage", "ig_chrisformage", "csb_customer", "a_m_y_cyclist_01", "u_m_y_cyclist_01", "cs_dale", "ig_dale", "cs_davenorton", "ig_davenorton", "mp_f_deadhooker", "s_m_y_dealer_01", "cs_debra", "cs_denise", "ig_denise", "csb_denise_friend", "cs_devin", "ig_devin", "s_m_y_devinsec_01", "csb_popov", "ig_popov", "u_m_m_doa_01", "s_m_m_dockwork_01", "s_m_y_dockwork_01", "s_m_m_doctor_01", "cs_dom", "ig_dom", "s_m_y_doorman_01", "a_m_y_dhill_01", "a_f_m_downtown_01", "a_m_y_downtown_01", "cs_drfriedlander", "ig_drfriedlander", "a_f_y_scdressy_01", "s_m_y_dwservice_01", "s_m_y_dwservice_02", "a_f_m_eastsa_01", "a_f_m_eastsa_02", "a_m_m_eastsa_01", "a_m_m_eastsa_02", "a_f_y_eastsa_01", "a_f_y_eastsa_02", "a_f_y_eastsa_03", "a_m_y_eastsa_01", "a_m_y_eastsa_02", "u_m_m_edtoh", "a_f_y_epsilon_01", "a_m_y_epsilon_01", "a_m_y_epsilon_02", "cs_tomepsilon", "ig_tomepsilon", "mp_m_exarmy_01", "u_m_y_militarybum", "cs_fabien", "ig_fabien", "s_f_y_factory_01", "s_m_y_factory_01", "g_m_y_famca_01", "mp_m_famdd_01", "g_m_y_famdnf_01", "g_f_y_families_01", "g_m_y_famfor_01", "csb_ramp_gang", "ig_ramp_gang", "a_m_m_farmer_01", "a_f_m_fatbla_01", "a_f_m_fatcult_01", "a_m_m_fatlatin_01", "a_f_m_fatwhite_01", "a_f_y_femaleagent", "cs_mrk", "ig_mrk", "u_m_m_fibarchitect", "u_m_y_fibmugger_01", "s_m_m_fiboffice_01", "s_m_m_fiboffice_02", "mp_m_fibsec_01", "s_m_m_fibsec_01", "cs_fbisuit_01", "ig_fbisuit_01", "u_m_o_finguru_01", "s_m_y_fireman_01", "a_f_y_fitness_01", "a_f_y_fitness_02", "cs_floyd", "ig_floyd", "csb_fos_rep", "mp_f_freemode_01", "mp_m_freemode_01", "s_m_m_gaffer_01", "s_m_y_garbage", "s_m_m_gardener_01", "a_m_y_gay_01", "a_m_y_gay_02", "a_m_m_genfat_01", "a_m_m_genfat_02", "a_f_y_genhot_01", "a_f_o_genstreet_01", "a_m_o_genstreet_01", "a_m_y_genstreet_01", "a_m_y_genstreet_02", "csb_g", "u_m_m_glenstank_01", "a_m_m_golfer_01", "a_f_y_golfer_01", "a_m_y_golfer_01", "u_m_m_griff_01", "s_m_y_grip_01", "csb_groom", "ig_groom", "csb_grove_str_dlr", "cs_guadalope", "u_m_y_guido_01", "u_m_y_gunvend_01", "cs_gurk", "s_m_m_hairdress_01", "csb_hao", "ig_hao", "a_m_m_hasjew_01", "a_m_y_hasjew_01", "csb_ramp_hic", "ig_ramp_hic", "s_m_m_highsec_01", "s_m_m_highsec_02", "s_m_y_hwaycop_01", "a_f_y_hiker_01", "a_m_y_hiker_01", "a_m_m_hillbilly_01", "a_m_m_hillbilly_02", "a_f_y_hippie_01", "u_m_y_hippie_01", "a_m_y_hippy_01", "csb_ramp_hipster", "ig_ramp_hipster", "a_f_y_hipster_01", "a_f_y_hipster_02", "a_f_y_hipster_03", "a_f_y_hipster_04", "a_m_y_hipster_01", "a_m_y_hipster_02", "a_m_y_hipster_03", "s_f_y_hooker_01", "s_f_y_hooker_02", "s_f_y_hooker_03", "s_f_y_scrubs_01", "u_f_y_hotposh_01", "csb_hugh", "cs_hunter", "ig_hunter", "s_m_m_ciasec_01", "u_m_y_imporage", "csb_imran", "a_m_m_indian_01", "a_f_o_indian_01", "a_f_y_indian_01", "a_m_y_indian_01", "u_f_y_comjane", "cs_janet", "ig_janet", "csb_janitor", "s_m_m_janitor", "ig_jay_norris", "u_m_o_taphillbilly", "u_m_m_jesus_01", "a_m_y_jetski_01", "hc_driver", "hc_gunman", "hc_hacker", "u_m_m_jewelthief", "u_f_y_jewelass_01", "cs_jewelass", "ig_jewelass", "u_m_m_jewelsec_01", "cs_jimmyboston", "ig_jimmyboston", "cs_jimmydisanto", "ig_jimmydisanto", "a_f_y_runner_01", "a_m_y_runner_01", "a_m_y_runner_02", "mp_m_marston_01", "cs_johnnyklebitz", "ig_johnnyklebitz", "cs_josef", "ig_josef", "cs_josh", "ig_josh", "a_f_y_juggalo_01", "a_m_y_juggalo_01", "u_m_y_justin", "cs_karen_daniels", "ig_karen_daniels", "ig_kerrymcintosh", "u_m_y_baygor", "g_m_m_korboss_01", "a_f_m_ktown_01", "a_f_m_ktown_02", "g_m_y_korlieut_01", "a_m_m_ktown_01", "a_f_o_ktown_01", "a_m_o_ktown_01", "g_m_y_korean_01", "a_m_y_ktown_01", "g_m_y_korean_02", "a_m_y_ktown_02", "cs_lamardavis", "ig_lamardavis", "s_m_m_lathandy_01", "a_m_m_stlat_02", "a_m_y_stlat_01", "a_m_y_latino_01", "cs_lazlow", "ig_lazlow", "cs_lestercrest", "ig_lestercrest", "cs_lifeinvad_01", "ig_lifeinvad_01", "ig_lifeinvad_02", "s_m_m_lifeinvad_01", "s_m_m_linecook", "u_m_m_willyfist", "s_m_m_lsmetro_01", "cs_magenta", "ig_magenta", "s_f_m_maid_01", "a_m_m_malibu_01", "u_m_y_mani", "cs_manuel", "ig_manuel", "s_m_m_mariachi_01", "csb_ramp_marine", "s_m_m_marine_01", "s_m_m_marine_02", "s_m_y_marine_01", "s_m_y_marine_02", "s_m_y_marine_03", "u_m_m_markfost", "cs_marnie", "ig_marnie", "cs_martinmadrazo", "cs_maryann", "ig_maryann", "csb_maude", "ig_maude", "csb_rashcosvki", "ig_rashcosvki", "s_m_y_xmech_01", "s_m_y_xmech_02", "csb_mweather", "a_m_y_methhead_01", "csb_ramp_mex", "ig_ramp_mex", "g_m_m_mexboss_01", "g_m_m_mexboss_02", "g_m_y_mexgang_01", "g_m_y_mexgoon_01", "g_m_y_mexgoon_02", "g_m_y_mexgoon_03", "a_m_m_mexlabor_01", "a_m_m_mexcntry_01", "a_m_y_mexthug_01", "cs_michelle", "ig_michelle", "s_f_y_migrant_01", "s_m_m_migrant_01", "cs_milton", "ig_milton", "s_m_y_mime", "cs_joeminuteman", "ig_joeminuteman", "u_f_m_miranda", "u_f_y_mistress", "mp_f_misty_01", "cs_molly", "ig_molly", "csb_money", "ig_money", "a_m_y_motox_01", "a_m_y_motox_02", "s_m_m_movspace_01", "u_m_m_filmdirector", "s_f_y_movprem_01", "cs_movpremf_01", "s_m_m_movprem_01", "cs_movpremmale", "u_f_o_moviestar", "cs_mrsphillips", "ig_mrsphillips", "cs_mrs_thornhill", "ig_mrs_thornhill", "cs_natalia", "ig_natalia", "cs_nervousron", "ig_nervousron", "cs_nigel", "ig_nigel", "mp_m_niko_01", "a_m_m_og_boss_01", "cs_old_man1a", "ig_old_man1a", "cs_old_man2", "ig_old_man2", "cs_omega", "ig_omega", "ig_oneil", "csb_ortega", "ig_ortega", "csb_oscar", "csb_paige", "ig_paige", "a_m_m_paparazzi_01", "u_m_y_paparazzi", "s_m_m_paramedic_01", "u_m_m_partytarget", "u_m_y_party_01", "cs_patricia", "ig_patricia", "s_m_y_pestcont_01", "cs_dreyfuss", "ig_dreyfuss", "s_m_m_pilot_01", "s_m_y_pilot_01", "s_m_m_pilot_02", "u_m_y_pogo_01", "a_m_m_polynesian_01", "g_m_y_pologoon_01", "g_m_y_pologoon_02", "a_m_y_polynesian_01", "u_f_y_poppymich", "csb_porndudes", "s_m_m_postal_01", "s_m_m_postal_02", "cs_priest", "ig_priest", "u_f_y_princess", "s_m_m_prisguard_01", "s_m_y_prisoner_01", "u_m_y_prisoner_01", "s_m_y_prismuscl_01", "u_m_y_proldriver_01", "csb_prologuedriver", "a_f_m_prolhost_01", "a_m_m_prolhost_01", "u_f_o_prolhost_01", "u_f_m_promourn_01", "u_m_m_promourn_01", "csb_prolsec", "u_m_m_prolsec_01", "cs_prolsec_02", "ig_prolsec_02", "mp_g_m_pros_01", "s_f_y_ranger_01", "s_m_y_ranger_01", "csb_reporter", "u_m_y_rsranger_01", "u_m_m_rivalpap", "a_m_y_roadcyc_01", "s_m_y_robber_01", "csb_roccopelosi", "ig_roccopelosi", "a_f_y_rurmeth_01", "a_m_m_rurmeth_01", "cs_russiandrunk", "ig_russiandrunk", "s_f_m_shop_high", "s_f_y_shop_low", "s_m_y_shop_mask", "s_f_y_shop_mid", "a_f_m_salton_01", "a_m_m_salton_01", "a_m_m_salton_02", "a_m_m_salton_03", "a_m_m_salton_04", "a_f_o_salton_01", "a_m_o_salton_01", "a_m_y_salton_01", "g_m_y_salvaboss_01", "g_m_y_salvagoon_01", "g_m_y_salvagoon_02", "g_m_y_salvagoon_03", "s_m_m_scientist_01", "csb_screen_writer", "ig_screen_writer", "s_m_m_security_01", "s_f_y_sheriff_01", "s_m_y_sheriff_01", "mp_m_shopkeep_01", "cs_siemonyetarian", "ig_siemonyetarian", "a_f_y_skater_01", "a_m_m_skater_01", "a_m_y_skater_01", "a_m_y_skater_02", "a_f_m_skidrow_01", "a_m_m_skidrow_01", "s_m_m_snowcop_01", "cs_solomon", "ig_solomon", "a_f_m_soucent_01", "a_f_m_soucent_02", "a_m_m_socenlat_01", "a_m_m_soucent_01", "a_m_m_soucent_02", "a_m_m_soucent_03", "a_m_m_soucent_04", "a_f_m_soucentmc_01", "a_f_o_soucent_01", "a_f_o_soucent_02", "a_m_o_soucent_01", "a_m_o_soucent_02", "a_m_o_soucent_03", "a_f_y_soucent_01", "a_f_y_soucent_02", "a_f_y_soucent_03", "a_m_y_soucent_01", "a_m_y_soucent_02", "a_m_y_soucent_03", "a_m_y_soucent_04", "u_m_y_sbike", "u_m_m_spyactor", "u_f_y_spyactress", "u_m_y_staggrm_01", "cs_stevehains", "ig_stevehains", "s_m_m_strperf_01", "s_m_m_strpreach_01", "g_m_y_strpunk_01", "g_m_y_strpunk_02", "s_m_m_strvend_01", "s_m_y_strvend_01", "cs_stretch", "ig_stretch", "csb_stripper_01", "s_f_y_stripper_01", "csb_stripper_02", "s_f_y_stripper_02", "s_f_y_stripperlite", "mp_f_stripperlite", "a_m_y_sunbathe_01", "a_m_y_surfer_01", "s_m_y_swat_01", "s_f_m_sweatshop_01", "s_f_y_sweatshop_01", "ig_talina", "cs_tanisha", "ig_tanisha", "cs_taocheng", "ig_taocheng", "cs_taostranslator", "ig_taostranslator", "u_m_y_tattoo_01", "cs_tenniscoach", "ig_tenniscoach", "a_f_y_tennis_01", "a_m_m_tennis_01", "cs_terry", "ig_terry", "g_f_y_lost_01", "g_m_y_lost_01", "g_m_y_lost_02", "g_m_y_lost_03", "cs_tom", "csb_tonya", "ig_tonya", "a_f_y_topless_01", "a_f_m_tourist_01", "a_m_m_tourist_01", "a_f_y_tourist_01", "a_f_y_tourist_02", "cs_tracydisanto", "ig_tracydisanto", "csb_trafficwarden", "ig_trafficwarden", "a_f_m_tramp_01", "a_m_m_tramp_01", "u_m_o_tramp_01", "a_m_o_tramp_01", "s_m_m_gentransport", "a_m_m_tranvest_01", "a_m_m_tranvest_02", "s_m_m_trucker_01", "ig_tylerdix", "csb_undercover", "cs_paper", "ig_paper", "s_m_m_ups_01", "s_m_m_ups_02", "s_m_y_uscg_01", "g_f_y_vagos_01", "s_m_y_valet_01", "a_m_y_beachvesp_01", "a_m_y_beachvesp_02", "a_m_y_vindouche_01", "a_f_y_vinewood_01", "a_f_y_vinewood_02", "a_f_y_vinewood_03", "a_f_y_vinewood_04", "a_m_y_vinewood_01", "a_m_y_vinewood_02", "a_m_y_vinewood_03", "a_m_y_vinewood_04", "cs_wade", "ig_wade", "s_m_y_waiter_01", "cs_chengsr", "ig_chengsr", "a_m_y_stwhi_01", "a_m_y_stwhi_02", "s_m_y_winclean_01", "a_f_y_yoga_01", "a_m_y_yoga_01", "cs_zimbor", "ig_zimbor", "u_m_y_zombie_01" };

const std::vector<std::string> SKINS_TEST_VALUES{ "a_f_y_femaleagent", "csb_agent", "csb_chef2", "csb_money", "csb_paige", "csb_popov", "csb_rashcosvki", "csb_undercover", "ig_chef2", "ig_money", "ig_paige", "ig_popov", "ig_rashcosvki", "s_m_m_ccrew_01", "s_m_m_fibsec_01", "s_m_y_blackops_03", "u_m_m_doa_01", "u_m_m_edtoh", "cs_karen_daniels", "csb_mp_agent14", "ig_agent", "ig_karen_daniels", "ig_mp_agent14" };


void reset_skin_globals()
{
	//chosenSkinName = "";
}

int activeLineIndexModel = 0;

bool onconfirm_model_actions_menu(int choice)
{

	switch (choice)
	{
	case 0:
		applyChosenModelAsSkin();
		break;
	case 1:
		spawnChosenModelAsBodyguard();
		break;

	default:
		break;
	}
	return false;
}

bool applyChosenSkin(std::string skinName)
{
	mModelHash = GAMEPLAY::GET_HASH_KEY((char *)skinName.c_str());
	return applyChosenSkin();
}

bool applyChosenSkin()
{
	int i = 0;
	onconfirm_model_actions_menu(i);

	/*i++;
	if (Menu::Option("Spawn Model As Bodyguard"_Secure)) { onconfirm_model_actions_menu(i); };
	*/
	return true;
}

void applyChosenModelAsSkin()
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(mModelHash) && STREAMING::IS_MODEL_VALID(mModelHash))
	{
		STREAMING::REQUEST_MODEL(mModelHash);
		while (!STREAMING::HAS_MODEL_LOADED(mModelHash))
		{
			WAIT(0);
		}
		//STREAMING::LOAD_ALL_OBJECTS_NOW();

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0))
		{
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		}

		save_player_weapons();

		PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), mModelHash);
		//PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), FALSE);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		WAIT(0);

		if (veh != NULL)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, -1);
		}

		restore_player_weapons();

		//reset the skin detail choice
		skinDetailMenuIndex = 0;
		skinDetailMenuValue = 0;

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(mModelHash);

		//chosenSkinName = skinName;

	}

	return;
}

Ped spawnChosenModelAsBodyguard()
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(mModelHash) && STREAMING::IS_MODEL_VALID(mModelHash))
	{
		STREAMING::REQUEST_MODEL(mModelHash);
		while (!STREAMING::HAS_MODEL_LOADED(mModelHash))
		{
			
			WAIT(0);
		}

		int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		Vector3 spawn_coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 2.0, 2.0, 0.0);
		Ped ped = PED::CREATE_PED(25, mModelHash, spawn_coords.x, spawn_coords.y, spawn_coords.z, 0, false, false);

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 0))
		{
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
		}

		PED::SET_PED_AS_GROUP_LEADER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), my_group);
		PED::SET_PED_AS_GROUP_MEMBER(ped, my_group);
		PED::SET_PED_NEVER_LEAVES_GROUP(ped, my_group);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
		PED::SET_PED_COMBAT_ABILITY(ped, 100);
		//weapons
		static Hash weaponList[] = { WEAPON_ADVANCEDRIFLE, WEAPON_APPISTOL, WEAPON_ASSAULTRIFLE, WEAPON_ASSAULTSHOTGUN, WEAPON_ASSAULTSMG, WEAPON_BALL, WEAPON_BAT, WEAPON_BOTTLE, WEAPON_BULLPUPSHOTGUN, WEAPON_CARBINERIFLE, WEAPON_COMBATMG, WEAPON_COMBATPDW, WEAPON_COMBATPISTOL, WEAPON_CROWBAR, WEAPON_DAGGER, WEAPON_FIREEXTINGUISHER, WEAPON_FIREWORK, WEAPON_FLAREGUN, WEAPON_GOLFCLUB, WEAPON_GRENADE, WEAPON_GRENADELAUNCHER, WEAPON_GUSENBERG, WEAPON_HAMMER, WEAPON_HEAVYPISTOL, WEAPON_HEAVYSHOTGUN, WEAPON_HEAVYSNIPER, WEAPON_HOMINGLAUNCHER, WEAPON_KNIFE, WEAPON_KNUCKLE, WEAPON_MARKSMANPISTOL, WEAPON_MARKSMANRIFLE, WEAPON_MG, WEAPON_MICROSMG, WEAPON_MOLOTOV, WEAPON_MUSKET, WEAPON_NIGHTSTICK, WEAPON_PETROLCAN, WEAPON_PISTOL, WEAPON_PISTOL50, WEAPON_PROXMINE, WEAPON_PUMPSHOTGUN, WEAPON_RPG, WEAPON_SAWNOFFSHOTGUN, WEAPON_SMG, WEAPON_SMOKEGRENADE, WEAPON_SNIPERRIFLE, WEAPON_SNOWBALL, WEAPON_SNSPISTOL, WEAPON_SPECIALCARBINE, WEAPON_STICKYBOMB, WEAPON_STUNGUN, WEAPON_VINTAGEPISTOL, WEAPON_MINIGUN };
		for each (Hash weapon in weaponList)
		{
			int maxAmmo;
			if (WEAPON::HAS_PED_GOT_WEAPON(ped, weapon, FALSE) == FALSE)
			{
				WEAPON::GIVE_WEAPON_TO_PED(ped, weapon, (WEAPON::GET_MAX_AMMO(ped, weapon, &maxAmmo) == TRUE) ? maxAmmo : 9999, FALSE, TRUE);
				WEAPON::SET_PED_WEAPON_TINT_INDEX(ped, weapon, ((weapon == WEAPON_MINIGUN) || (weapon == WEAPON_SPECIALCARBINE)) ? WEAPONTINT_PLATINUM : WEAPONTINT_LSPD);
			}
			if (WEAPON::GET_WEAPONTYPE_GROUP(weapon) == WEAPON_TYPE_GROUP_THROWABLE)
			{
				WEAPON::REMOVE_WEAPON_FROM_PED(ped, weapon);
				WEAPON::GIVE_WEAPON_TO_PED(ped, weapon, (WEAPON::GET_MAX_AMMO(ped, weapon, &maxAmmo) == TRUE) ? maxAmmo : 9999, FALSE, TRUE);
			}
		}

		PED::SET_PED_CAN_SWITCH_WEAPON(ped, true);
		/*  -- Note : Group Formations
		0 : Nothing
		1 : Circle Around Leader
		2 : Alternative Circle Around Leader
		3 : Line, with Leader at center. --  */
		int val = 1;
		PED::SET_GROUP_FORMATION(my_group, val);

		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(ped);
		WAIT(0);

		if (veh != NULL)
		{
			for (int i = 1; i <= 8; i++)
			{
				if (!VEHICLE::IS_VEHICLE_SEAT_FREE(veh, i)) continue;
				AI::TASK_WARP_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), veh, i); break;
				PED::SET_PED_INTO_VEHICLE(ped, veh, i);
			}
		}

		//reset the skin detail choice
		skinDetailMenuIndex = 0;
		skinDetailMenuValue = 0;

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(mModelHash);

		//chosenSkinName = skinName;
		return ped;
	}
}

std::string getSkinDetailAttribDescription(int i)
{
	switch (i)
	{
	case 0:
		return "Head/Face";
	case 1:
		return "Beard/Mask";
	case 2:
		return "Hair/Hat";
	case 3:
		return "Top";
	case 4:
		return "Legs";
	case 5:
		return "Accessory/Gloves";
	case 6:
		return "Accessory/Shoes";
	case 7:
	case 8:
	case 9:
		return "Accessory";
	case 10:
		return "Badges";
	case 11:
		return "Shirt/Jacket";
	default:
		return std::to_string(i);
	}
}

std::string getPropDetailAttribDescription(int i)
{
	switch (i)
	{
	case 0:
		return "Hats/Masks/Helmets";
	case 1:
		return "Glasses";
	case 2:
		return "Earrings";
	case 3:
		return "??? 3";
	case 4:
		return "??? 4";
	case 5:
		return "??? 5";
	case 6:
		return "??? 6";
	case 7:
		return "??? 7";
	case 8:
		return "??? 8";
	case 9:
		return "??? 9";
	case 10:
		return "??? 10";
	case 11:
		return "??? 11";
	default:
		return std::to_string(i);
	}
}

int lastTriedComponentIndex = 0;
int lastTriedPalette = 0;


/*
* ===============
* SKIN PLAYER CHOICES
* =================
*/

bool onconfirm_skinchanger_choices_players(std::string choice, int choiceint)
{
	applyChosenSkin(choice);
	return false;
}

bool onconfirm_skinchanger_choices_animals(std::string choice, int choiceint)
{
	applyChosenSkin(choice);
	return false;
}

bool onconfirm_skinchanger_choices_misc(std::string choice, int choiceint)
{
	applyChosenSkin(choice);
	return false;
}

bool onconfirm_skinchanger_choices_test(std::string choice, int choiceint)
{
	applyChosenSkin(choice);
	return false;
}

bool process_skinchanger_choices_test()
{
	for (int i = 0; i < SKINS_TEST_VALUES.size(); i++)
	{
		string caption1 = SKINS_TEST_VALUES[i];
		const char* itemoption = caption1.c_str();
		string value1 = SKINS_TEST_VALUES[i];
		if (Menu::Option(itemoption)) { onconfirm_skinchanger_choices_test(value1, i); };
	}

	return true;
}

bool skin_save_menu_interrupt()
{
	if (skinSaveMenuInterrupt)
	{
		skinSaveMenuInterrupt = false;
		return true;
	}
	return false;
}

bool skin_save_slot_menu_interrupt()
{
	if (skinSaveSlotMenuInterrupt)
	{
		skinSaveSlotMenuInterrupt = false;
		return true;
	}
	return false;
}

bool onconfirm_savedskin_menu(int choice, std::string caption)
{
	if (choice == -1)
	{
		save_current_skin(-1);
		requireRefreshOfSkinSaveSlots = true;
		skinSaveMenuInterrupt = true;
		return false;
	}

	activeSavedSkinIndex = choice;
	activeSavedSkinSlotName = caption;
	return true;
}

bool onconfirm_savedskin_slot_menu(int choice)
{
	switch (choice)
	{
	case 1: //spawn
		spawn_saved_skin(activeSavedSkinIndex, activeSavedSkinSlotName);
		break;
	case 2: //overwrite
	{
		save_current_skin(activeSavedSkinIndex);
		requireRefreshOfSkinSaveSlots = true;
		requireRefreshOfSkinSlotMenu = true;
		skinSaveSlotMenuInterrupt = true;
		skinSaveMenuInterrupt = true;
	}
	break;
	case 3: //rename
	{
		std::string result = show_keyboard(NULL, (char*)activeSavedSkinSlotName.c_str());
		if (!result.empty())
		{
			ENTDatabase* database = Features::get_database();
			database->rename_saved_skin(result, activeSavedSkinIndex);
			activeSavedSkinSlotName = result;
		}
		requireRefreshOfSkinSaveSlots = true;
		requireRefreshOfSkinSlotMenu = true;
		skinSaveSlotMenuInterrupt = true;
		skinSaveMenuInterrupt = true;
	}
	break;
	case 4: //delete
	{
		ENTDatabase* database = Features::get_database();
		database->delete_saved_skin(activeSavedSkinIndex);
		requireRefreshOfSkinSlotMenu = false;
		requireRefreshOfSkinSaveSlots = true;
		skinSaveSlotMenuInterrupt = true;
		skinSaveMenuInterrupt = true;
	}
	break;
	case 5: //bodyguard
	{
		spawn_saved_skin_bodyguard(activeSavedSkinIndex, activeSavedSkinSlotName);
	}
	break;
	}
	return false;
}



bool spawn_saved_skin(int slot, std::string caption)
{
	ENTDatabase* database = Features::get_database();

	std::vector<SavedSkinDBRow*> savedSkins = database->get_saved_skins(slot);

	SavedSkinDBRow* savedSkin = savedSkins.at(0);
	database->populate_saved_skin(savedSkin);

	mModelHash = savedSkin->model;

	applyChosenSkin();

	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	for each (SavedSkinComponentDBRow *comp in savedSkin->components)
	{
		PED::SET_PED_COMPONENT_VARIATION( ped, comp->slotID, comp->drawable, comp->texture, 0);
	}

	PED::CLEAR_ALL_PED_PROPS(ped);
	for each (SavedSkinBlend *prop in savedSkin->blends)
	{
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY(prop->stat), prop->value, 1);
		STATS::STAT_SET_FLOAT(GAMEPLAY::GET_HASH_KEY(prop->stat), prop->value, 1);
	}

	for each (SavedSkinPropDBRow *prop in savedSkin->props)
	{
		PED::SET_PED_PROP_INDEX(ped, prop->propID, prop->drawable, prop->texture, 0);
	}

	for (std::vector<SavedSkinDBRow*>::iterator it = savedSkins.begin(); it != savedSkins.end(); ++it)
	{
		delete (*it);
	}
	savedSkins.clear();

	return false;
}

bool spawn_saved_skin_bodyguard(int slot, std::string caption)
{
	ENTDatabase* database = Features::get_database();

	std::vector<SavedSkinDBRow*> savedSkins = database->get_saved_skins(slot);

	SavedSkinDBRow* savedSkin = savedSkins.at(0);
	database->populate_saved_skin(savedSkin);

	mModelHash = savedSkin->model;

	

	Ped ped = spawnChosenModelAsBodyguard();

	for each (SavedSkinComponentDBRow *comp in savedSkin->components)
	{
		PED::SET_PED_COMPONENT_VARIATION(ped, comp->slotID, comp->drawable, comp->texture, 0);
	}

	PED::CLEAR_ALL_PED_PROPS(ped);
	for each (SavedSkinPropDBRow *prop in savedSkin->props)
	{
		PED::SET_PED_PROP_INDEX(ped, prop->propID, prop->drawable, prop->texture, 0);
	}

	for (std::vector<SavedSkinDBRow*>::iterator it = savedSkins.begin(); it != savedSkins.end(); ++it)
	{
		delete (*it);
	}
	savedSkins.clear();

	return false;
}

void save_current_skin(int slot)
{
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()));
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());

	if (bPlayerExists)
	{
		std::ostringstream ss;
		if (slot != -1)
		{
			ss << activeSavedSkinSlotName;
		}
		else
		{
			ss << "Saved Skin " << (lastKnownSavedSkinCount + 1);
		}

		auto existingText = ss.str();
		std::string result = show_keyboard(NULL, (char*)existingText.c_str());
		if (!result.empty())
		{
			ENTDatabase* database = Features::get_database();
			
			if (database->save_skin(playerPed, result, slot))
			{
				activeSavedSkinSlotName = result;
				notifyMap("~g~Saved Skin"_Secure);
			}
			else
			{
				notifyMap("~r~Save Error"_Secure);
			}
		}
	}


}