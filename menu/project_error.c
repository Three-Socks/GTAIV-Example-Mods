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