#include "stdafx.h"
#include "Detour.h"
#include "Features.h"

void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_FONT(4); //ill make it customizable later
	UI::SET_TEXT_SCALE(size.w, size.h);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	Hooking::begin_text_cmd_display_text("STRING");
	Hooking::add_text_comp_substr_playername((char*)text);
	Hooking::end_text_cmd_display_text(position.x, position.y); //Drawtext is older but it should still work
	DoASM();
}
void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	DoASM();
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		DoASM();
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
	DoASM();
	//GRAPHICS::DRAW_RECT(position.x, position.y, 0.3f, 0.085f, rgba.r, rgba.g, rgba.b, rgba.a);
}


float Menu::Settings::menuX = 0.8f;
bool Menu::Settings::selectPressed = false;
bool Menu::Settings::leftPressed = false;
bool Menu::Settings::rightPressed = false;
bool Menu::Settings::mousecontrol = false;
bool firstopen = true;
int Menu::Settings::maxVisOptions = 20;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;
SubMenus Menu::Settings::currentMenu = NOMENU;
int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];
SubMenus Menu::Settings::menusArray[1000];
RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
RGBA Menu::Settings::checkBox{ 255, 255, 255, 255 };//
RGBAF Menu::Settings::titleText{ 255, 255, 255, 255, 7 };//
RGBA Menu::Settings::titleRect{ 255, 255, 255, 15 };//
RGBAF Menu::Settings::optionText{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::breakText{ 255, 255, 255, 255, 1 };
RGBAF Menu::Settings::arrow{ 255, 255, 255, 255, 3 };                          // Mod Menu Colors 
RGBA Menu::Settings::optionRect{ 0, 0, 0, 110 };
RGBA Menu::Settings::scroller{ 255, 255, 255, 255 };//
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 2 };
RGBA Menu::Settings::line{ 255, 255, 255, 255 };
RGBA Menu::Settings::primary{ 255, 0, 0 };
RGBA Menu::Settings::secondary{ 0, 255, 0 };

POINT point;

int MouseWheelHandler()
{
	if (CONTROLS::GET_CONTROL_NORMAL(0, ControlCursorScrollUp) > 0)
	{
		return 1;
	}
	else if (CONTROLS::GET_CONTROL_NORMAL(0, ControlCursorScrollDown) > 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	DoASM();
	/*
	ControlCursorAccept = 237,
	ControlCursorCancel = 238,
	ControlCursorX = 239,
	ControlCursorY = 240,
	ControlCursorScrollUp = 241,
	ControlCursorScrollDown = 242,
	CONTROLS::GET_CONTROL_VALUE(0, ControlCursorX)
	CONTROLS::GET_CONTROL_VALUE(0, ControlCursorY)
	*/
}

int Menu::getCursorMenu()
{
	int X = CONTROLS::GET_CONTROL_VALUE(0, ControlCursorX);
	int Y = CONTROLS::GET_CONTROL_VALUE(0, ControlCursorY);
	DoASM();
	if (X <= 242 && X >= 215)
	{
		if (Y <= 151 && Y >= 147)
			Menu::Settings::currentOption = 1;
		if (Y <= 156 && Y > 151)
			Menu::Settings::currentOption = 2;
		if (Y <= 160 && Y > 156)
			Menu::Settings::currentOption = 3;
		if (Y <= 165 && Y > 160)
			Menu::Settings::currentOption = 4;
		if (Y <= 169 && Y > 165)
			Menu::Settings::currentOption = 5;
		if (Y <= 174 && Y > 169)
			Menu::Settings::currentOption = 6;
		if (Y <= 178 && Y > 174)
			Menu::Settings::currentOption = 7;
		if (Y <= 183 && Y > 178)
			Menu::Settings::currentOption = 8;
		if (Y <= 187 && Y > 183)
			Menu::Settings::currentOption = 9;
		if (Y <= 191 && Y > 187)
			Menu::Settings::currentOption = 10;
		if (Y <= 196 && Y > 191)
			Menu::Settings::currentOption = 11;
		if (Y <= 200 && Y > 196)
			Menu::Settings::currentOption = 12;
		if (Y <= 205 && Y > 200)
			Menu::Settings::currentOption = 13;
		if (Y <= 209 && Y > 205)
			Menu::Settings::currentOption = 14;
		if (Y <= 214 && Y > 209)
			Menu::Settings::currentOption = 15;
		if (Y <= 218 && Y > 214)
			Menu::Settings::currentOption = 16;
		if (Y <= 222 && Y > 218)
			Menu::Settings::currentOption = 17;
		if (Y <= 227 && Y > 222)
			Menu::Settings::currentOption = 18;
		if (Y <= 231 && Y > 227)
			Menu::Settings::currentOption = 19;
		if (Y <= 236 && Y > 231)
			Menu::Settings::currentOption = 20;
	}
	return Menu::Settings::currentOption;

}

void Menu::Title(const char * title)
{
	Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.095f }, { 0.85f, 0.85f }, true);
	Drawing::Rect(Settings::titleRect, { Settings::menuX, 0.1175f }, { 0.21f, 0.085f });
	// Disable Controls
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
	DoASM();
}

/*void Menu::Title(const char * title)
{
	Drawing::Text(title, Settings::titleText, { Settings::menuX, 0.080f }, { 0.85f, 0.85f }, true);
	Drawing::Rect(Settings::titleRect, { Settings::menuX, 0.1175f }, { 0.23f, 0.085f });
	Drawing::Spriter("CommonMenu", "interaction_bgd", Settings::menuX, 0.1175f, 0.23f, 0.085f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
}*/


void Menu::SubTitle(const char * title2)
{
	Drawing::Text(title2, RGBAF{ 100, 50, 220, 255, 6 }, { Settings::menuX - 0.005f, 0.140f }, { 0.35f, 0.35f }, true);

}


void Menu::VersionTitle(const char * title)
{
	Drawing::Text(title, RGBAF{ 220,0,0,255,7 }, { Settings::menuX, 0.110f }, { 0.65f, 0.65f }, true);
}

void Menu::info(const char * info)
{
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	DoASM();
	if (Settings::currentOption <= 20 && Settings::optionCount <= 20)
	{
		if (onThis)
		{
			Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.200f, (Settings::optionCount)*0.035f + 0.125f }, { 0.25f, 0.25f }, false);
			//Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.200f, (Settings::optionCount)*0.035f + 0.1415f }, { 0.06f, 0.025f });
		}
	}
	else
	{
		if (onThis)
		{
			Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.200f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.125f }, { 0.25f, 0.25f }, false);
			//Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.200f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.06f, 0.025f });
		}
	}
}

bool Menu::Option(const char * option)
{
	DoASM();
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 20 && Settings::optionCount <= 20)
	{
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.095f, (Settings::optionCount)*0.035f + 0.125f }, { 0.45f, 0.45f }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
	}
	else if (Settings::optionCount > (Settings::currentOption - 20) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.095f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.125f }, { 0.45f, 0.45f }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
	}
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}
bool Menu::Option(const char * option, std::function<void()> function)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Break(const char * option)
{
	DoASM();
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 20 && Settings::optionCount <= 20)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount)*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 20) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.125f }, { 0.45f, 0.45f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
	Option(option);
	DoASM();
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("", Settings::titleText, { Settings::menuX + 0.099f, Settings::optionCount * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("", Settings::titleText, { Settings::menuX + 0.099f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.35f, 0.35f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

bool Menu::MenuOption(const char * option, SubMenus newSub, std::function<void()> function)
{
	MenuOption(option, newSub);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Toggle(const char * option, bool & b00l)
{
	DoASM();
	Option(option);
	if (b00l)
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			drawSprite("commonmenu", b00l ? "shop_box_tick" : "shop_box_blank", Settings::menuX + 0.078f, (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, Menu::Settings::checkBox);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			drawSprite("commonmenu", b00l ? "shop_box_tick" : "shop_box_blank", Settings::menuX + 0.079f, (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, Menu::Settings::checkBox);
	}
	else
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			drawSprite("commonmenu", b00l ? "shop_box_tick" : "shop_box_blank", Settings::menuX + 0.078f, (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, Menu::Settings::checkBox);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			drawSprite("commonmenu", b00l ? "shop_box_tick" : "shop_box_blank", Settings::menuX + 0.078f, (Settings::optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, Menu::Settings::checkBox);
	}
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		b00l ^= 1;
		return true;
	}
	return false;
}
bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Int(const char * option, int & _int, int min, int max)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int-- : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, std::function<void()> function)
{
	Int(option, _int, min, max);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step, std::function<void()> function)
{
	Int(option, _int, min, max, step);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Float(const char * option, float & _float, int min, int max, int step)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.32f, 0.32f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.32f, 0.32f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max, std::function<void()> function)
{
	Float(option, _float, min, max);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Float(const char * option, float & _float, int min, int max, int step, std::function<void()> function)
{
	Float(option, _float, min, max, step);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
#pragma warning(disable: 4267)
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position, std::function<void()> function)
{
	IntVector(option, Vector, position);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position, std::function<void()> function)
{
	FloatVector(option, Vector, position);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, (Settings::optionCount - (Settings::currentOption - 20))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4267)
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords)
{
	Option(option);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		Entity handle;
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID())) : PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
		ENTITY::_SET_ENTITY_COORDS_2(handle, coords.x, coords.y, coords.z, false, false, false, false);
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords, std::function<void()> function)
{
	Teleport(option, coords);
	DoASM();
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

void Menu::End()
{
	DoASM();
	int opcount = Settings::optionCount;
	int currop = Settings::currentOption;
	if (opcount >= 20) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, 17 * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, 17 * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX, 17 * 0.035f + 0.1235f }, { 0.21f, 0.002f });
		Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((20 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
	}
	else if (opcount > 0) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, (Settings::optionCount + 1) * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX, (Settings::optionCount + 1) * 0.035f + 0.1235f }, { 0.21f, 0.002f });
		Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
	}
}

int IconNotification(char *text, char *text2, char *Subject)
{
	DoASM();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_GANGAPP", "CHAR_GANGAPP", false, 7, text2, Subject, 1.0, "___Menu");
	return UI::_DRAW_NOTIFICATION(1, 1);
}
void PlaySoundFrontend_default(char* sound_name)
{
	DoASM();
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	DoASM();
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}



int Menu::Settings::keyPressDelay = 200;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
int Menu::Settings::keyPressDelay2 = 100;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();
int Menu::Settings::openKey = VK_MULTIPLY;
int Menu::Settings::openKey2 = VK_F4;
int Menu::Settings::backKey = VK_NUMPAD0;
int Menu::Settings::upKey = VK_NUMPAD8;
int Menu::Settings::downKey = VK_NUMPAD2;
int Menu::Settings::leftKey = VK_NUMPAD4;
int Menu::Settings::rightKey = VK_NUMPAD6;
int Menu::Settings::selectKey = VK_NUMPAD5;
int Menu::Settings::arrowupKey = VK_UP;
int Menu::Settings::arrowdownKey = VK_DOWN;
int Menu::Settings::arrowleftKey = VK_LEFT;
int Menu::Settings::arrowrightKey = VK_RIGHT;
int Menu::Settings::enterKey = VK_RETURN;
int Menu::Settings::deleteKey = VK_BACK;

#pragma endregion

bool Menu::Settings::controllerinput = true;
void Menu::Checks::Controlls()
{
	DoASM();
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;
	if (GetTickCount() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
	if (GetTickCount() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
		if (GetTickCount() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
			if (IsKeyPressed(VK_MULTIPLY) || IsKeyPressed(VK_F4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
				Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
				Settings::keyPressPreviousTick = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput || (IsKeyPressed(VK_RBUTTON) && Features::MouseControlBool)) {
				Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("BACK");

				Settings::keyPressPreviousTick = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput || (MouseWheelHandler() == 1 && Features::MouseControlBool)) {
				Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("NAV_UP_DOWN");

				Settings::keyPressPreviousTick2 = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput || (MouseWheelHandler() == -1 && Features::MouseControlBool)) {
				Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("NAV_UP_DOWN");

				Settings::keyPressPreviousTick2 = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
				Settings::leftPressed = true;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("NAV_UP_DOWN");

				Settings::keyPressPreviousTick3 = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
				Settings::rightPressed = true;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("NAV_UP_DOWN");

				Settings::keyPressPreviousTick3 = GetTickCount();
			}
			else if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput || (IsKeyPressed(VK_LBUTTON) && Features::MouseControlBool)) {
				Settings::selectPressed = true;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("SELECT");

				Settings::keyPressPreviousTick = GetTickCount();
			}
		}
	}
  }
	Settings::optionCount = 0;
}
#pragma warning(default : 4018)
void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	DoASM();
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
}

void Menu::MenuLevelHandler::BackMenu()
{
	DoASM();
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
}

char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
	return (std::string)buf;
}

void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}

int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}

float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}

bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}

void Menu::Vehicle(std::string texture1, std::string texture2)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); }
	}
	else { if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); } }
}
void Menu::Speedometer(char* text)
{
	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
}
void Menu::fps(char* text)
{
	Drawing::Text(text, Settings::optionText, { 0.84f, 0.050f }, { 0.70f, 0.70f }, false);
}
void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}
void Menu::AddSmallInfo(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((20 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 20 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((20 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 20 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}

void Menu::AddSmallTitle3(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}