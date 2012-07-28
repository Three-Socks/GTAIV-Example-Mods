/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "menu/menu_consts.h"

void main(void)
{
	bool load_trainer;

	while(true)
	{
		WAIT(0);

		if (load_trainer)
		{
			if (GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("sample_menu") == 0)
			{
				REQUEST_SCRIPT("sample_menu");
				while (!HAS_SCRIPT_LOADED("sample_menu"))
					WAIT(0);

				START_NEW_SCRIPT("sample_menu", 1024);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED("sample_menu");
				TERMINATE_THIS_SCRIPT();
			}
		}

		if ((IS_BUTTON_PRESSED(0, BUTTON_L1) && IS_BUTTON_PRESSED(0, BUTTON_DPAD_UP)) || (IS_GAME_KEYBOARD_KEY_PRESSED(KEY_E) && IS_GAME_KEYBOARD_KEY_PRESSED(KEY_UP_ARROW)))
			load_trainer = true;
	}
	
}