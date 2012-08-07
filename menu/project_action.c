#pragma once

// Dummy function.
void run_my_code(void)
{
	// Your code.
}

void project_doAction(void)
{
	menu_items_set = true;

	// Helpers
	uint num_val_selected = menu_item[item_selected].num_val;
	uint mainMenu = last_selected[1];
	uint subMenu = last_selected[2]; 

	if (menu_level == 1)
	{
		if (item_selected == 3)
			// Exit
			project_shutdown();
	}
	else if (mainMenu == 1)
	{
		if (menu_level == 2)
		{
			if (subMenu == 1)
				run_my_code();
			else if (subMenu == 2)
				run_my_code();
			else if (subMenu == 3)
				run_my_code();

			return;
		}
	}
	else if (mainMenu == 2)
	{
		if (menu_level == 2)
		{
			if (subMenu == 1)
				run_my_code();
			else if (subMenu == 2)
				run_my_code();
			else if (subMenu == 3)
				run_my_code();

			return;
		}
	}

	project_error(SAMPLE_ERROR_ID_INVALID);
}