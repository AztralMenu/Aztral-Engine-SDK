#include <string>
#include <vector>

#include "stdafx.h"

#pragma once

struct PropInfo
{
	char* model;
	std::string label;
	std::string category;
};

class SpawnedPropInstance
{
public:
	Object instance;
	std::string title;
	int counter;
	bool isInvincible;
	bool isImmovable;
	bool hasGravity;
};

/*bool onconfirm_prop_selection();

void process_props_menu();

void add_props_feature_enablements(std::vector<FeatureEnabledLocalDefinition>* results);

void add_props_generic_settings(std::vector<StringPairSettingDBRow>* results);

void handle_generic_settings_props(std::vector<StringPairSettingDBRow>* settings);

void cleanup_props();

void reset_prop_globals();

int find_highest_instance_num_of_prop(Hash model);

bool prop_spawned_instances_menu();

bool onconfirm_prop_instance_menu();

bool prop_spawned_single_instance_menu(int index);

bool prop_instance_menu_interrupt();

SpawnedPropInstance* get_prop_at_index(int i);*/