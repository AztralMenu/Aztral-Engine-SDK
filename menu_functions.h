
#pragma once

#include "stdafx.h"

#include <string>
#include <sstream> 

#include <ctime>
#include <vector>
#include <algorithm>

#pragma once
#pragma warning(disable : 4244 4305 4267) // double <-> float conversions <-> size_t conversions


extern void(*periodic_feature_call)(void);

static const char* LOCAL_TEXTURE_DICT = "LOCALTEXTURES";

template<class T>
class MenuItem
{
public:

	virtual ~MenuItem() {}

	std::string caption;
	T value;
	int currentMenuIndex = 0;
	bool isLeaf = true;
	void(*onConfirmFunction)(const MenuItem<T> choice) = NULL;


	/**
	Handle the on-item confirmation press.
	Returns whether the confirmation has been absorbed; if not, it will be
	passed up to the parent menu.
	*/
	virtual inline bool onConfirm()
	{
		//set_status_text("Parent confirm");
		if (onConfirmFunction != NULL)
		{
			onConfirmFunction(*this);
		}
		return false;
	};

	virtual bool isAbsorbingLeftAndRightEvents() { return false; };

	virtual void handleLeftPress() {}

	virtual void handleRightPress() {}

protected:

};

template<class T>
class ToggleMenuItem : public MenuItem < T >
{
public:

	virtual ~ToggleMenuItem() {}

	bool *toggleValue = NULL;
	bool *toggleValueUpdated = NULL;

	virtual bool get_toggle_value()
	{
		return *toggleValue;
	}

	virtual bool onConfirm();
};

template<class T>
class FunctionDrivenToggleMenuItem : public ToggleMenuItem < T >
{
public:

	virtual ~FunctionDrivenToggleMenuItem() {}

	bool(*getter_call)(std::vector<T> extras);
	void(*setter_call)(bool, std::vector<T> extras);

	std::vector<T> extra_arguments;

	virtual bool get_toggle_value()
	{
		return getter_call(extra_arguments);
	}

	virtual inline bool onConfirm()
	{
		setter_call(!getter_call(extra_arguments), extra_arguments);
		return true;
	}
};

/*lass WantedSymbolItem : public MenuItem <int>
{
public:

	virtual ~WantedSymbolItem() {}

	int get_wanted_value();

	virtual bool onConfirm() { return true; };

	virtual bool isAbsorbingLeftAndRightEvents() { return true; };

	virtual void handleLeftPress();

	virtual void handleRightPress();
};*/

class SelectFromListMenuItem : public MenuItem <int>
{
public:

	inline SelectFromListMenuItem(std::vector<std::string> captions, void(*onValueChangeCallback)(int, SelectFromListMenuItem*))
	{
		this->itemCaptions = captions;
		this->onValueChangeCallback = onValueChangeCallback;
	}

	virtual ~SelectFromListMenuItem() {}

	virtual bool onConfirm();

	virtual bool isAbsorbingLeftAndRightEvents();

	virtual void handleLeftPress();

	virtual void handleRightPress();

	virtual std::string getCurrentCaption();

	std::vector<std::string> itemCaptions;

	void(*onValueChangeCallback)(int index, SelectFromListMenuItem* source);

	bool wrap = true;

	bool locked = false;

	std::vector<int> extras;
};

template<class T>
class CashItem : public MenuItem <T>
{
	virtual ~CashItem() {}

	int cash = 10000;
	int increment = 10000;
	int min = 10000;
	int max = 10000000;

	virtual bool onConfirm();
	virtual bool isAbsorbingLeftAndRightEvents() { return true; };
	virtual void handleLeftPress();
	virtual void handleRightPress();

public:
	int GetCash() { return cash; }
};

enum MenuItemType { STANDARD, TOGGLE, CASH, WANTED };

struct StandardOrToggleMenuDef {
	std::string text;
	bool *pState;
	bool *pUpdated;
	bool isLeaf;
	MenuItemType itemType;
};

struct StringStandardOrToggleMenuDef {
	std::string text;
	std::string value;
	bool *pState;
	bool *pUpdated;
};

class MenuItemImage
{
public:
	inline bool is_local()
	{
		return strcmp(dict, LOCAL_TEXTURE_DICT) == 0;
	};

	char* dict;
	char* name;
	int localID;
};

template<class T>
class MenuParameters
{
public:
	inline MenuParameters(std::vector<MenuItem<T>*> items, std::string headerText)
	{
		this->items = items;
		this->headerText = headerText;
	}

	std::vector<MenuItem<T>*> items;
	std::string headerText;
	int *menuSelectionPtr = 0;
	bool(*onConfirmation)(MenuItem<T> value) = NULL;
	void(*onHighlight)(MenuItem<T> value) = NULL;
	void(*onExit)(bool returnValue) = NULL;
	bool(*interruptCheck)(void) = NULL;
	MenuItemImage*(*lineImageProvider)(MenuItem<T> value) = NULL;

	int get_menu_selection_index()
	{
		return *menuSelectionPtr;
	}

	void set_menu_selection_index(int index)
	{
		*menuSelectionPtr = index;
	}

	bool has_menu_selection_ptr()
	{
		return menuSelectionPtr != 0;
	}
};

static const float TEXT_HEIGHT_NORMAL = 17.0f;

static const float TEXT_HEIGHT_TITLE = 24.0f;

static const float TEXT_HEIGHT_NONLEAF = 24.0f;

static const float TEXT_HEIGHT_WSTARS = 24.0f;

/**Set the method that is used to periodically update the entire UI and apply repeat settings. The script core does this once.*/
void set_periodic_feature_call(void method(void));

/**Make the periodic feature call. For example it updates the status text etc. - look at existing menus to see where this is done.*/
void make_periodic_feature_call();

void set_menu_showing(bool showing);

bool is_menu_showing();

/**Draw a solid rectangle.
* I think parameters are:
* - A_0: X
* - A_1: Y
* - A_2: W
* - A_3: H
* - A_4 - 7: R,G,B,A
* but you'll have to look at uses to be sure, and to understand scaling.
*/
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7);

void draw_ingame_sprite(MenuItemImage *image, float x, float y, int w, int h);

inline void draw_menu_header_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool rescaleText = true, int curPage = 1, int pageCount = 1)
{
	/*
	std::replace(caption.begin(), caption.end(), '-', ' ');
	std::replace(caption.begin(), caption.end(), '_', ' ');
	caption.erase(remove_if(caption.begin(), caption.end(), [](char c)
	{
	return !isalnum(c) && c != ' ';
	}), caption.end());
	*/

	// default values
	int text_col[4] = { 255, 255, 255, 255.0f },
		rect_col[4] = { 0, 0, 0, 200.0f };

	float text_scale = rescaleText ? 0.60 : 0.35;

	int font = 2;
	bool outline = false;
	bool dropShadow = false;

	int screen_w, screen_h;
	GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;

	float textHeightScaled = TEXT_HEIGHT_TITLE / (float)screen_h;

	// this is how it's done in original scripts

	// text upper part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);

	if (outline)
	{
		UI::SET_TEXT_OUTLINE();
	}

	if (dropShadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}

	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());

	float textY = lineTopScaled + (0.5f * (lineHeightScaled - textHeightScaled));
	float leftMarginScaled = textLeftScaled - lineLeftScaled;

	UI::END_TEXT_COMMAND_DISPLAY_TEXT(textLeftScaled, textY);

	// rect
	draw_rect(lineLeftScaled, lineTopScaled,
		lineWidthScaled, lineHeightScaled,
		rect_col[0], rect_col[1], rect_col[2], rect_col[3]);

	// draw page count in different colour
	if (pageCount > 1)
	{
		std::ostringstream ss;
		ss << " ~HUD_COLOUR_MENU_YELLOW~" << curPage << "~HUD_COLOUR_GREYLIGHT~ of ~HUD_COLOUR_MENU_YELLOW~" << pageCount;

		text_col[0] = 255;
		text_col[1] = 180;
		text_col[2] = 0;

		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, text_scale);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);

		if (outline)
		{
			UI::SET_TEXT_OUTLINE();
		}

		if (dropShadow)
		{
			UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}


		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::SET_TEXT_WRAP(0.0f, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_PRINT("STRING");

		auto ssStr = ss.str();
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char *)ssStr.c_str());
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);
	}
}

template<typename T>
void draw_menu_item_line(MenuItem<T> *item, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool rescaleText)
{
	// default values
	int text_col[4] = { 255, 255, 255, 255.0f },
		rect_col[4] = { 255, 255, 255, 80.f };
	float text_scale = 0.35;
	int font = 0;
	bool outline = false;
	bool dropShadow = false;

	// correcting values for active line
	if (active)
	{
		text_col[0] = 0;
		text_col[1] = 0;
		text_col[2] = 0;

		rect_col[0] = 255;
		rect_col[1] = 180;
		rect_col[2] = 0;
		rect_col[3] = 200.0f;

		//outline = true;

		if (rescaleText) text_scale = 0.40;
	}
	else
	{
		outline = true;
	}

	int screen_w, screen_h;
	GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

	textLeft += lineLeft;

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;
	float leftMarginScaled = textLeftScaled - lineLeftScaled;

	float textHeightScaled = TEXT_HEIGHT_NORMAL / (float)screen_h;
	float rightMarginScaled = 30.0f / (float)screen_w;

	// this is how it's done in original scripts

	// text upper part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);

	if (outline)
	{
		UI::SET_TEXT_OUTLINE();
	}

	if (dropShadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}

	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)item->caption.c_str());

	float textY = lineTopScaled + (0.5f * (lineHeightScaled - textHeightScaled));

	UI::END_TEXT_COMMAND_DISPLAY_TEXT(textLeftScaled, textY);

	// rect
	draw_rect(lineLeftScaled, lineTopScaled,
		lineWidthScaled, lineHeightScaled,
		rect_col[0], rect_col[1], rect_col[2], rect_col[3]);

	if (ToggleMenuItem<T>* toggleItem = dynamic_cast<ToggleMenuItem<T>*>(item))
	{
		//set_status_text("Found toggle");
		if (toggleItem->get_toggle_value())
		{
			text_col[0] = 182;
			text_col[1] = 255;
			text_col[2] = 0;
		}
		else
		{
			text_col[0] = 255;
			text_col[1] = 60;
			text_col[2] = 60;
		}

		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, text_scale);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_CENTRE(0);

		UI::SET_TEXT_OUTLINE();

		if (dropShadow)
		{
			UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}

		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::SET_TEXT_CENTRE(1);
		UI::SET_TEXT_WRAP(0, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(toggleItem->get_toggle_value() ? "ON" : "OFF");
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(lineLeftScaled + lineWidthScaled - rightMarginScaled, textY);
	}
	else if (CashItem<T>* cashItem = dynamic_cast<CashItem<T>*>(item))
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, text_scale);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);

		UI::SET_TEXT_OUTLINE();

		if (dropShadow)
		{
			UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}

		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::SET_TEXT_WRAP(0.0f, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");

		std::string commaCash = std::to_string(cashItem->GetCash());
		int insertPosition = commaCash.length() - 3;
		while (insertPosition > 0)
		{
			commaCash.insert(insertPosition, ",");
			insertPosition -= 3;
		}

		std::stringstream ss;
		ss << "<C>~HUD_COLOUR_GREYLIGHT~&lt;&lt; ~HUD_COLOUR_PURE_WHITE~" << std::string("$") << commaCash << " ~HUD_COLOUR_GREYLIGHT~&gt;&gt;</C>";
		auto ssStr = ss.str();
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char *)ssStr.c_str());
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);
	}
	else if (SelectFromListMenuItem* selectFromListItem = dynamic_cast<SelectFromListMenuItem*>(item))
	{
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, text_scale);
		UI::SET_TEXT_COLOUR(205, 205, 205, 255);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);

		UI::SET_TEXT_OUTLINE();

		if (dropShadow)
		{
			UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}

		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
		UI::SET_TEXT_WRAP(0, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");

		std::string caption = selectFromListItem->getCurrentCaption();

		std::stringstream ss;

		if ((selectFromListItem->wrap || selectFromListItem->value > 0) && selectFromListItem->locked)
		{
			ss << "&lt;&lt; ";
		}
		else
		{
			ss << "";
		}

		if (selectFromListItem->locked)
			ss << "~HUD_COLOUR_PURE_WHITE~" << caption;
		else
			ss << "~HUD_COLOUR_GREYLIGHT~" << caption;

		if ((selectFromListItem->wrap || selectFromListItem->value < selectFromListItem->itemCaptions.size() - 1) && selectFromListItem->locked)
		{
			ss << " ~HUD_COLOUR_GREYLIGHT~&gt;&gt;";
		}
		else
		{
			ss << "";
		}
		auto ssStr = ss.str();

		//write_text_to_log_file(ssStr);

		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char *)ssStr.c_str());
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);

		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255);

		textY = lineTopScaled + (0.5f * (lineHeightScaled - (TEXT_HEIGHT_NONLEAF / (float)screen_h)));

		/*
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, 0.4f);
		UI::SET_TEXT_CENTRE(0);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(0);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("<<");

		UI::END_TEXT_COMMAND_DISPLAY_TEXT(lineLeftScaled + lineWidthScaled + 0.01f, textY);

		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, 0.4f);
		UI::SET_TEXT_CENTRE(0);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);
		UI::SET_TEXT_WRAP(0.0f, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("");
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);
		*/
	}
	/*else if (WantedSymbolItem* wantedItem = dynamic_cast<WantedSymbolItem*>(item))
	{
		rightMarginScaled = 10.0f / (float)screen_w;
		float starTextScale = 0.6f;

		text_col[0] = 255;
		text_col[1] = 255;
		text_col[2] = 255;

		UI::SET_TEXT_FONT(7);
		UI::SET_TEXT_SCALE(0.0, starTextScale);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);

		UI::SET_TEXT_OUTLINE();

		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);

		float starWidth = 19.5f / (float)screen_w;
		textY = lineTopScaled + (0.5f * (lineHeightScaled - (TEXT_HEIGHT_WSTARS / (float)screen_h)));

		std::ostringstream wantedStars;
		int wantedLevel = wantedItem->get_wanted_value();
		int i = 0;
		for (; i < wantedLevel; i++)
		{
			wantedStars << "*";
		}

		UI::SET_TEXT_WRAP(0, lineLeftScaled + lineWidthScaled - rightMarginScaled - (starWidth*(5 - i)));
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");

		auto wantedStarsStr = wantedStars.str();
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char *)wantedStarsStr.c_str());
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);

		text_col[0] = 100;
		text_col[1] = 100;
		text_col[2] = 100;

		UI::SET_TEXT_FONT(7);
		UI::SET_TEXT_SCALE(0.0, starTextScale);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);

		UI::SET_TEXT_OUTLINE();

		UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);

		std::ostringstream unwantedStars;
		for (; i < 5; i++)
		{
			unwantedStars << "*";
		}

		UI::SET_TEXT_WRAP(0, lineLeftScaled + lineWidthScaled - rightMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");

		auto unwantedStarsStr = unwantedStars.str();
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char *)unwantedStarsStr.c_str());

		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);
	}*/
	else if (!item->isLeaf)
	{
		text_col[0] = 200;
		text_col[1] = 200;
		text_col[2] = 200;

		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(0.0, 0.4f);
		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_CENTRE(0);

		/*
		UI::SET_TEXT_OUTLINE();

		if (dropShadow)
		{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
		}
		*/

		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255);

		UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
		UI::SET_TEXT_RIGHT_JUSTIFY(1);
		UI::SET_TEXT_WRAP(0.0f, lineLeftScaled + lineWidthScaled - leftMarginScaled);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(">>");
		float textY = lineTopScaled + (0.5f * (lineHeightScaled - (TEXT_HEIGHT_NONLEAF / (float)screen_h)));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0, textY);
	}
}


template<typename T>
bool draw_generic_menu(std::vector<MenuItem<T>*> items, int *menuSelectionPtr, std::string headerText,
	bool(*onConfirmation)(MenuItem<T> value),
	void(*onHighlight)(MenuItem<T> value),
	void(*onExit)(bool returnValue),
	bool(*interruptCheck)(void) = NULL)
{
	MenuParameters<T> params(items, headerText);
	params.menuSelectionPtr = menuSelectionPtr;
	params.interruptCheck = interruptCheck;
	params.onConfirmation = onConfirmation;
	params.onExit = onExit;
	params.onHighlight = onHighlight;

	return draw_generic_menu(params);
}

template<typename T>
bool draw_generic_menu(MenuParameters<T> params)
{
	if (params.items.size() == 0)
	{
		set_status_text("Whoops, nothing to see here");
		return false;
	}

	bool result = false;
	DWORD waitTime = 150;
	const int totalItems = (int)params.items.size();
	const int itemsPerLine = 12;
	const int lineCount = (int)(ceil((double)totalItems / (double)itemsPerLine));

	int currentSelectionIndex;
	if (params.has_menu_selection_ptr())
	{
		if (params.get_menu_selection_index() >= totalItems)
		{
			params.set_menu_selection_index(0);
		}
		else if (params.get_menu_selection_index() < 0)
		{
			params.set_menu_selection_index(0);
		}
		currentSelectionIndex = params.get_menu_selection_index();
	}
	else
	{
		currentSelectionIndex = 0;
	}

	if (params.onHighlight != NULL)
	{
		params.onHighlight(*params.items[currentSelectionIndex]);
	}

	MenuItemImage* image = NULL;
	if (params.lineImageProvider != NULL)
	{
		image = params.lineImageProvider(*params.items[currentSelectionIndex]);
	}

	//populate the menu items' indices
	for (int i = 0; i < totalItems; i++)
	{
		params.items[i]->currentMenuIndex = i;
	}

	while (true)
	{
		if (trainer_switch_pressed())
		{
			menu_beep();

			set_menu_showing(!is_menu_showing());
		}
		else if (params.interruptCheck != NULL && params.interruptCheck())
		{
			return false;
		}

		if (!is_menu_showing())
		{
			if (params.interruptCheck != NULL && params.interruptCheck())
			{
				return false;
			}

			make_periodic_feature_call();
			WAIT(0);
			continue;
		}

		const int currentLine = floor((double)currentSelectionIndex / (double)itemsPerLine);

		const int originalIndex = currentSelectionIndex;

		int positionOnThisLine = currentSelectionIndex % itemsPerLine;
		int lineStartPosition = currentSelectionIndex - positionOnThisLine;
		int itemsOnThisLine = (lineStartPosition + itemsPerLine > totalItems) ? (totalItems - lineStartPosition) : itemsPerLine;

		// timed menu draw, used for pause after active line switch
		DWORD maxTickCount = GetTickCount() + waitTime;
		do
		{
			draw_menu_header_line(params.headerText,
				350.0f,//line W
				50.0f,//line H
				15.0f,//line T
				0.0f,//line L
				15.0f,//text X offset
				false,
				true,
				(currentLine + 1),
				lineCount
			);

			float activeLineY = 0;

			for (int i = 0; i < itemsOnThisLine; i++)
			{
				float lineSpacingY = 8.0f;

				float lineWidth = 350.0f;
				float lineHeight = 35.0f;

				float lineTop = 73.0 + (i * (lineHeight + lineSpacingY));
				float lineLeft = 35.0f;
				float textOffset = 10.0f;

				draw_menu_item_line(params.items[lineStartPosition + i], lineWidth, lineHeight, lineTop, lineLeft, textOffset, i == positionOnThisLine, false);

				if (i == positionOnThisLine)
				{
					activeLineY = lineTop;
				}
			}

			if (image != NULL)
			{
				int screen_w, screen_h;
				GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

				float lineXPx = 35.0f + 350.0f + 8.0f;
				float lineXGame = lineXPx / (float)screen_w;
				float lineYGame = activeLineY / (float)screen_h;

				draw_ingame_sprite(image, lineXGame, lineYGame, 256, 128);
			}

			if (periodic_feature_call != NULL)
			{
				periodic_feature_call();
			}

			WAIT(0);
		} while (GetTickCount() < maxTickCount);
		waitTime = 0;

		bool bSelect, bBack, bUp, bDown, bLeft, bRight;
		get_button_state(&bSelect, &bBack, &bUp, &bDown, &bLeft, &bRight);

		MenuItem<T> *choice = params.items[currentSelectionIndex];

		if (bSelect)
		{
			menu_beep();

			waitTime = 200;

			bool confHandled = choice->onConfirm();

			//fire the main handler
			if (!confHandled && params.onConfirmation != NULL)
			{
				result = params.onConfirmation(*choice);
			}

			if (result)
			{
				//result = false; //to avoid cascading upwards
				break;
			}
		}
		else
		{
			if (bBack)
			{
				menu_beep();
				waitTime = 200;
				result = false;
				break;
			}
			else
			{
				if (bDown)
				{
					menu_beep();
					currentSelectionIndex++;
					if (currentSelectionIndex >= totalItems || (currentSelectionIndex >= lineStartPosition + itemsOnThisLine))
					{
						currentSelectionIndex = lineStartPosition;
					}
					waitTime = 150;
				}
				else
					if (bUp)
					{
						menu_beep();
						currentSelectionIndex--;
						if (currentSelectionIndex < 0 || (currentSelectionIndex < lineStartPosition))
						{
							currentSelectionIndex = lineStartPosition + itemsOnThisLine - 1;
						}
						waitTime = 150;
					}
					else
						if (bLeft)
						{
							menu_beep();

							if (choice->isAbsorbingLeftAndRightEvents())
							{
								choice->handleLeftPress();
							}
							else if (lineCount > 1)
							{
								int mod = currentSelectionIndex % itemsPerLine;
								currentSelectionIndex -= itemsPerLine;
								if (currentSelectionIndex < 0)
								{
									currentSelectionIndex = mod + ((lineCount - 1) * itemsPerLine);
									if (currentSelectionIndex >= totalItems)
									{
										currentSelectionIndex = totalItems - 1;
									}
								}
							}
							waitTime = 200;
						}
						else
							if (bRight)
							{
								menu_beep();

								if (choice->isAbsorbingLeftAndRightEvents())
								{
									choice->handleRightPress();
								}
								else if (lineCount > 1)
								{
									//if we're already at the end, restart
									if (currentLine == lineCount - 1)
									{
										currentSelectionIndex = currentSelectionIndex % itemsPerLine;
										if (currentSelectionIndex >= totalItems)
										{
											currentSelectionIndex = totalItems - 1;
										}
									}
									else
									{
										currentSelectionIndex += itemsPerLine;
										if (currentSelectionIndex >= totalItems)
										{
											currentSelectionIndex = totalItems - 1;
										}
									}
								}

								waitTime = 200;
							}

				if (params.onHighlight != NULL && originalIndex != currentSelectionIndex)
				{
					params.onHighlight(*params.items[currentSelectionIndex]);
				}

				if (params.lineImageProvider != NULL && originalIndex != currentSelectionIndex)
				{
					image = params.lineImageProvider(*params.items[currentSelectionIndex]);
				}

				if (params.has_menu_selection_ptr())
				{
					params.set_menu_selection_index(currentSelectionIndex);
				}
			}
		}
	}

	if (params.onExit != NULL)
	{
		params.onExit(result);
	}

	// wait before exit
	if (waitTime > 0)
	{
		DWORD maxTickCount = GetTickCount() + waitTime;
		do
		{
			make_periodic_feature_call();
			WAIT(0);
		} while (GetTickCount() < maxTickCount);
		waitTime = 0;
	}

	//clean up the items memory
	for (int i = 0; i< params.items.size(); i++)
	{
		delete (params.items[i]);
	}
	params.items.clear();

	if (image != NULL)
	{
		delete image;
	}

	return result;
}

void set_status_text(std::string str, bool isGxtEntry = false);

void set_status_text_centre_screen(std::string str, DWORD time = 2500, bool isGxtEntry = false);

void update_centre_screen_status_text();

void menu_beep();

void draw_menu_from_struct_def(StandardOrToggleMenuDef defs[], int lineCount, int* selectionRef, std::string caption, bool(*onConfirmation)(MenuItem<int> value));

void draw_menu_from_struct_def(StringStandardOrToggleMenuDef defs[], int lineCount, int* selectionRef, std::string caption, bool(*onConfirmation)(MenuItem<std::string> value));

std::string show_keyboard(char* title_id, char* prepopulated_text);
