#pragma once

void project_set(void)
{
	menu_items_set = true;

	uint mainMenu = last_selected[1];
	uint subMenu = last_selected[2]; 

	// Main
	if (menu_level == 1)
	{
		// Main
		menu_header = sample_menu_main;
		menu_addItem(sample_menu_1);
		menu_addItem(sample_menu_2);
		menu_addItem(sample_menu_exit);
		menu_addAction();
		return;
	}
	// Menu Item 1
	else if (mainMenu == 1)
	{
		if (menu_level == 2)
		{
			menu_header = sample_menu_sub;
			menu_addItem(sample_menu_sub_1);
			menu_addAction();
			menu_addItem(sample_menu_sub_2);
			menu_addAction();
			menu_addItem(sample_menu_sub_3);
			menu_addAction();

			return;	
		}
	}
	// Menu Item 2
	else if (mainMenu == 2)
	{
		if (menu_level == 2)
		{
			menu_header = sample_menu_sub;
			menu_addItem(sample_menu_sub_1);
			menu_addAction();
			menu_addItem(sample_menu_sub_2);
			menu_addAction();
			menu_addItem(sample_menu_sub_3);
			menu_addAction();

			return;
		}
	}

	project_error(SAMPLE_ERROR_ID_INVALID);
}

void project_catchFunctionButtonPress(void)
{
}