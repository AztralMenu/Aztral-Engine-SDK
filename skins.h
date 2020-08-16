#pragma once
#include "stdafx.h"
#include "weapons.h"

#include <string>

/***
* METHODS
*/

extern bool applyChosenSkin();

extern bool applyChosenSkin(std::string skinName);

extern void applyChosenModelAsSkin();

extern Ped spawnChosenModelAsBodyguard();

extern void reset_skin_globals();

extern int skinDetailMenuIndex;

extern int skinDetailMenuValue;

extern int skinPropsCategoryValue;

extern int skinPropsDrawablePosition[10];

//Save related stuff

extern bool skin_save_menu_interrupt();

extern bool skin_save_slot_menu_interrupt();

extern bool spawn_saved_skin(int slot, std::string caption);

extern bool spawn_saved_skin_bodyguard(int slot, std::string caption);

extern void save_current_skin(int slot);

extern bool onconfirm_savedskin_menu(int choice, std::string caption);

extern int lastKnownSavedSkinCount;

extern bool onconfirm_savedskin_slot_menu(int choice);

extern bool onconfirm_skinchanger_choices_players(std::string choice, int choiceint);

extern bool onconfirm_skinchanger_choices_animals(std::string choice, int choiceint);

extern bool onconfirm_skinchanger_choices_misc(std::string choice, int choiceint);

extern std::string getSkinDetailAttribDescription(int i);

extern std::string getPropDetailAttribDescription(int i);

extern const std::vector<std::string> SKINS_PLAYER_CAPTIONS;
extern const std::vector<std::string> SKINS_PLAYER_VALUES;

extern const std::vector<std::string> SKINS_ANIMAL_CAPTIONS;
extern const std::vector<std::string> SKINS_ANIMAL_VALUES;

extern const std::vector<std::string> SKINS_GENERAL_CAPTIONS;
extern const std::vector<std::string> SKINS_GENERAL_VALUES;

extern const std::vector<std::string> SKINS_TEST_VALUES;