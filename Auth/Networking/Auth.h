#pragma once
#include "stdafx.h"

wstring s2ws(const std::string& str);

bool is_user_authed(std::string name, std::string password);
bool is_user_authed(std::string username, std::string password, std::string version);