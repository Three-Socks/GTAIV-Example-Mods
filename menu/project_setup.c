/**
 * This file is from Three-Socks trainer Project https://bitbucket.org/ThreeSocks/gtaiv-trainer
 *
 */

void project_setup(void)
{
	// Start y positioning.
	menu_start_y = 0.0890;
	// Spacing between each item.
	menu_spacing = 0.0400;
	// Max number of items before scrolling.
	menu_max = 14;
	// When to start scrolling.
	menu_start_scrolling = 7;

	startup_script = "sample_menu";

	inMenu = true;
}

void project_error(uint error_id)
{
	if (menu_item[item_selected].action)
		actionError = true;

	menu_clean();

	// Invalid Menu.
	menu_header = sample_menu_error;

	if (error_id == SAMPLE_ERROR_ID_INVALID)
		menu_addItem(sample_menu_error_invalid);

	menu_addItem(sample_menu_error_goback);
	inError = true;
}