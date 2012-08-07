#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

//#define PC
#define MAX_MENU_ITEMS 52
#define MAX_MENU_LEVLS 5
#define STYLE 1

// Menu
#include "menu/menu.h"

// Trainer
#include "sample_menu_lang.h"
#include "sample_menu_locals.h"

#include "project_error.c"

// Project
#include "project_set.c"
#include "project_action.c"

// Menu
#include "menu/menu_core.c"

void main(void)
{
	startup_script = "sample_startup";
	inMenu = true;

	menu_core_startup();
	draw_startup();

	while(true)
	{
		WAIT(0);

		// Core menu function (Catch button press. Set menu).
		menu_core();

		// Draw background/header/text.
		drawWindow();

		drawFrontend();
	
		drawHeader();
		menu_draw();
	}
}