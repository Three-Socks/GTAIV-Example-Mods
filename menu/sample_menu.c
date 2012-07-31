/**
 * This file is from Three-Socks Trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

//#define PC
#define MAX_MENU_ITEMS 52
#define MAX_MENU_LEVLS 5

// Menu
#include "menu/menu.h"

// Trainer
#include "sample_menu_lang.h"
#include "sample_menu_locals.h"

#include "project_setup.c"

// Project
#include "project_set.c"
#include "project_action.c"

// Menu
#include "menu/menu_core.c"

void main(void)
{
	menu_core_init();

	while(true)
	{
		WAIT(0);

		// Core menu function (Catch button press. Set menu).
		menu_core();

		// Draw background/header/text.
		drawCurvedWindow();

		drawFrontend();
	
		drawHeader();
		menu_draw();

		if (menu_len > menu_consts_max && item_highlighted > menu_start_scrolling)
			DRAW_SPRITE(arrow_txd, 0.1900, 0.1260, 0.0160, 0.0160, 0, 255, 255, 255, 255);

		if (menu_len > menu_consts_max)
			DRAW_SPRITE(arrow_txd, 0.1900, 0.6890, 0.0160, 0.0160, 180.0000, 255, 255, 255, 255);
	}
}