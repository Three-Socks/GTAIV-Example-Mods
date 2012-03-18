/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 *
 * Button combo's:
 *
 *  While holding Dpad left tap X - God Mode Enable/Disable
 *  While holding Dpad right tap X - Clear wanted
 *  While holding R3 tap X - Play as brucie. Press again for random clothes.
 *  While holding X left tap L3 - Fix vehicle.
 * 
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#define BUTTON_SELECT  0xD
#define BUTTON_START  0xC
#define BUTTON_S  0xE
#define BUTTON_T  0xF
#define BUTTON_X  0x10
#define BUTTON_O  0x11
#define BUTTON_DPAD_UP  0x8
#define BUTTON_DPAD_DOWN  0x9
#define BUTTON_DPAD_LEFT  0xA
#define BUTTON_DPAD_RIGHT  0xB
#define BUTTON_L2  0x5
#define BUTTON_R2  0x7
#define BUTTON_L1  0x4
#define BUTTON_R1  0x6
#define BUTTON_STICK_LEFT  0x12
#define BUTTON_STICK_RIGHT  0x13

int activateGodMode = false;
int activateClearWanted = false;
int activateClothes = false;
int activateFixCar = false;

bool isGodModeactivated = false;
bool isBrucieactivated = false;

void DoActivators(void)
{

	if (activateGodMode)
	{
		activateGodMode = false;
		if (isGodModeactivated)
		{
			SET_PLAYER_INVINCIBLE(GetPlayerIndex(), false);
			SET_PLAYER_NEVER_GETS_TIRED(GetPlayerIndex(), false);
			SET_PLAYER_FAST_RELOAD(GetPlayerIndex(), false);
			ENABLE_MAX_AMMO_CAP(true);
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "God Mode Disabled", 1000, 1);

			isGodModeactivated = false;
		}
		else
		{
			SET_PLAYER_INVINCIBLE(GetPlayerIndex(), true);
			SET_PLAYER_NEVER_GETS_TIRED(GetPlayerIndex(), true);
			SET_PLAYER_FAST_RELOAD(GetPlayerIndex(), true);
			ENABLE_MAX_AMMO_CAP(false);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BASEBALLBAT);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_RLAUNCHER);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_PISTOL);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_SHOTGUN);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_MP5);
			UpdateWeaponOfPed(GetPlayerPed(), WEAPON_AK47);
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "God Mode Enabled", 1000, 1);

			isGodModeactivated = true;
		}
	}

	if (activateClearWanted)
	{
		activateClearWanted = false;
		CLEAR_WANTED_LEVEL(GetPlayerIndex());
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Cleared Wanted", 1000, 1);
	}

	if (activateClothes)
	{
		activateClothes = false;
		if (isBrucieactivated)
		{		
			SET_CHAR_RANDOM_COMPONENT_VARIATION(GetPlayerPed());
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Clothes Changed", 1000, 1);
		}
		else
		{
			REQUEST_MODEL(MODEL_IG_BRUCIE);
			while (!HAS_MODEL_LOADED(MODEL_IG_BRUCIE)) WAIT(0);
			CHANGE_PLAYER_MODEL(GetPlayerIndex(), MODEL_IG_BRUCIE);
			MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_IG_BRUCIE);
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 0, 0, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 1, 1, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 2, 0, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 5, 0, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 4, 0, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 3, 0, 0 );
			SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 7, 0, 0 );
			
			SET_LOCAL_PLAYER_VOICE("BRUCIE");
			SET_LOCAL_PLAYER_PAIN_VOICE("BRUCIE");
			FORCE_FULL_VOICE(GetPlayerPed());
			PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Playing as brucie", 1500, 1);
			
			isBrucieactivated = true;
		}
	}

	if (activateFixCar)
	{
		activateFixCar = false;
		Vehicle fix_vehicle;
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &fix_vehicle);
		FIX_CAR(fix_vehicle);
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Vehicle Fixed", 1000, 1);
	}

}

void DoLoop(void)
{

	if (IS_BUTTON_PRESSED(0, BUTTON_DPAD_LEFT) && IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
	{
		activateGodMode = true;
	}

	if (IS_BUTTON_PRESSED(0, BUTTON_DPAD_RIGHT) && IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
	{
		activateClearWanted = true;
	}

	if (IS_CHAR_ON_FOOT(GetPlayerPed()) && IS_BUTTON_PRESSED(0, BUTTON_STICK_RIGHT) && IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
	{
		activateClothes = true;
	}

	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()) && IS_BUTTON_PRESSED(0, BUTTON_X) && IS_BUTTON_JUST_PRESSED(0, BUTTON_STICK_LEFT))
	{
		activateFixCar = true;
	}

}

void main(void)
{
	while(true)
	{
		WAIT(0);
		DoLoop();
		DoActivators();
	}
}