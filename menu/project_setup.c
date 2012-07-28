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

	inMenu = true;
}

void project_startup(void)
{
	REQUEST_SCRIPT("sample_menu_globals");
	while (!HAS_SCRIPT_LOADED("sample_menu_globals"))
		WAIT(0);

	START_NEW_SCRIPT("sample_menu_globals", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("sample_menu_globals");

	SET_CINEMATIC_BUTTON_ENABLED(false);

#ifdef PC
if (!IS_FONT_LOADED(7))
	LOAD_TEXT_FONT(7);
#else
if (!IS_FONT_LOADED(6))
	LOAD_TEXT_FONT(6);
#endif

	// Mimic cell phone.
	// 0 = work, 1 = crash, 2 = work, 3 = crash 
	WAIT(500);
	CREATE_MOBILE_PHONE(2);

	DISABLE_FRONTEND_RADIO();

	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), true);

	REQUEST_STREAMED_TXD("network", 0);
	while (!HAS_STREAMED_TXD_LOADED("network"))
		WAIT(0);

	arrow_txd = GET_TEXTURE_FROM_STREAMED_TXD("network", "ICON_W_ARROW_UP");
	rightarrow_txd = GET_TEXTURE_FROM_STREAMED_TXD( "network", "ICON_W_ARROW_RIGHT" );

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_READY");
}

void project_shutdown(void)
{
	RELEASE_TEXTURE(arrow_txd);
	RELEASE_TEXTURE(rightarrow_txd);
	MARK_STREAMED_TXD_AS_NO_LONGER_NEEDED("network");

	ENABLE_FRONTEND_RADIO();

	BLOCK_PED_WEAPON_SWITCHING(GetPlayerPed(), false);

	SET_CINEMATIC_BUTTON_ENABLED(true);

	DESTROY_MOBILE_PHONE();

	TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("sample_menu_globals");

	REQUEST_SCRIPT("sample_menu_gexit");
	while (!HAS_SCRIPT_LOADED("sample_menu_gexit"))
		WAIT(0);

	START_NEW_SCRIPT("sample_menu_gexit", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("sample_menu_gexit");

	REQUEST_SCRIPT("sample_menu_startup");
	while (!HAS_SCRIPT_LOADED("sample_menu_startup"))
		WAIT(0);

	START_NEW_SCRIPT("sample_menu_startup", 128);
	MARK_SCRIPT_AS_NO_LONGER_NEEDED("sample_menu_startup");

	PLAY_AUDIO_EVENT("FRONTEND_MENU_MP_UNREADY");
	TERMINATE_THIS_SCRIPT();
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