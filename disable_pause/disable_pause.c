#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

bool disable_pause, disable_hud, freeze_game;

void doInput(void)
{
	if ((IS_BUTTON_PRESSED(0, 6) && IS_BUTTON_JUST_PRESSED(0, 11)) || (IS_GAME_KEYBOARD_KEY_PRESSED(18) && IS_GAME_KEYBOARD_KEY_JUST_PRESSED(205)))
	{
		if (disable_pause)
		{
			disable_pause = false;
			DISABLE_PAUSE_MENU(false);
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Pause Enabled", 1500, true);
		}
		else
		{
			disable_pause = true;
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Pause Disabled", 1500, true);
		}
	}

	if ((IS_BUTTON_PRESSED(0, 6) && IS_BUTTON_JUST_PRESSED(0, 10)) || (IS_GAME_KEYBOARD_KEY_PRESSED(18) && IS_GAME_KEYBOARD_KEY_JUST_PRESSED(203)))
	{
		if (disable_hud)
		{
			disable_hud = false;
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Hud Enabled", 1500, true);
		}
		else
		{
			disable_hud = true;
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Hud Disabled", 1500, true);
		}
	}
	
	if ((IS_BUTTON_PRESSED(0, 6) && IS_BUTTON_JUST_PRESSED(0, 16)) || (IS_GAME_KEYBOARD_KEY_PRESSED(18) && IS_GAME_KEYBOARD_KEY_JUST_PRESSED(25)))
	{
		if (freeze_game)
		{
			freeze_game = false;
			UNPAUSE_GAME();
		}
		else
			freeze_game = true;
	}
}

void doAction(void)
{
	if (disable_pause)
	{
		if (IS_PAUSE_MENU_ACTIVE())
			DEACTIVATE_FRONTEND();

		DISABLE_PAUSE_MENU(true);
	}

	if (disable_hud)
	{
		HIDE_HELP_TEXT_THIS_FRAME();
		HIDE_HUD_AND_RADAR_THIS_FRAME();
	}

	if (freeze_game)
		PAUSE_GAME();
}

void main(void)
{
	while(true)
	{
		WAIT(0);
		doInput();
		doAction();
	}
}