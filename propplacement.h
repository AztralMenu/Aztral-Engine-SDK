#pragma once

#include "stdafx.h"


#include "props.h"

#include <string>

extern int pp_travel_speed;

extern SpawnedPropInstance* currentProp;

void begin_prop_placement(SpawnedPropInstance* prop);

void exit_prop_placer_if_showing();

void prop_placement();

void create_prop_placement_help_text();

void update_prop_placement_text();

bool is_in_prop_placement_mode();

bool is_prop_placement_frozen_time();

static const DWORD KEY_OBJECTPLACER_UP = VK_KEY_Q;
static const DWORD KEY_OBJECTPLACER_DOWN = VK_KEY_Z;
static const DWORD KEY_OBJECTPLACER_FORWARD = VK_KEY_W;
static const DWORD KEY_OBJECTPLACER_BACK = VK_KEY_S;
static const DWORD KEY_OBJECTPLACER_ROTATE_LEFT = VK_KEY_A;
static const DWORD KEY_OBJECTPLACER_ROTATE_RIGHT = VK_KEY_D;
static const DWORD KEY_OBJECTPLACER_SPEED = VK_OEM_6;
static const DWORD KEY_OBJECTPLACER_FREEZE_TIME = VK_KEY_T;
static const DWORD KEY_OBJECTPLACER_FREEZE_POSITION = VK_KEY_G;
static const DWORD KEY_OBJECTPLACER_HELP = VK_KEY_H;

static const DWORD CONTROL_OBJECTPLACER_UP = ControlFrontendLt;
static const DWORD CONTROL_OBJECTPLACER_DOWN = ControlFrontendRt;
static const DWORD CONTROL_OBJECTPLACER_FORWARD = ControlFrontendUp;
static const DWORD CONTROL_OBJECTPLACER_BACK = ControlFrontendDown;
static const DWORD CONTROL_OBJECTPLACER_ROTATE_LEFT = ControlFrontendLeft;
static const DWORD CONTROL_OBJECTPLACER_ROTATE_RIGHT = ControlFrontendRight;
static const DWORD CONTROL_OBJECTPLACER_SPEED = ControlFrontendLb;
static const DWORD CONTROL_OBJECTPLACER_FREEZE_TIME = ControlFrontendLs;
static const DWORD CONTROL_OBJECTPLACER_FREEZE_POSITION = ControlFrontendRs;
static const DWORD CONTROL_OBJECTPLACER_HELP = ControlFrontendRb;
