/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 *
 * Press Dpad down to open/close the garage when your near one.
 *
 * Needs the fixed natives.h found here https://bitbucket.org/ThreeSocks/gtaiv-example-mods/ repo before the SET_GARAGE_LEAVE_CAMERA_ALONE native will work correctly.
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#define BUTTON_DPAD_DOWN  0x9

int activateGarage = 0;

void DoActivators(void)
{

	// These are all the garages that can be opened using OPEN_GARAGE.
	if (activateGarage > 0)
	{
		char *GenGarage;

		if (activateGarage == 1)
		{
			GenGarage = "QW2MG1";
		}
		else if (activateGarage == 2)
		{
			GenGarage = "BxGRG1";
		}
		else if (activateGarage == 3)
		{
			GenGarage = "bs3MG";
		}
		else if (activateGarage == 4)
		{
			GenGarage = "PaulMH3";
		}
		activateGarage = 0;
		SET_GARAGE_LEAVE_CAMERA_ALONE(GenGarage, 1);
		if (IS_GARAGE_CLOSED(GenGarage))
		{
			OPEN_GARAGE(GenGarage);
		}
		else
		{
			CLOSE_GARAGE(GenGarage);
		}
	}

}

void DoLoop(void)
{

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
		// Faustin's Garage - used in "Crime and Punishment"
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 917.17250000, 570.09330000, 23.27200000, 11.50000000, 12.50000000, 10.00000000, 0))
		{
			activateGarage = 1;
		}

		// Stevie's Garage - Bohan
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 722.57110000, 1383.07900000, 13.30010000, 11.50000000, 12.50000000, 15.00000000, 0))
		{
			activateGarage = 2;
		}

		// Vlad's Garage - used in "Clean Getaway"
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 965.15340000, -324.35270000, 19.23930000, 11.50000000, 12.50000000, 3.00000000, 0))
		{
			activateGarage = 3;
		}
		
		// Packie's Garage - used in "Harboring a Grudge"
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -513.50000000, 332.00000000, 7.00000000, 35.00000000, 35.00000000, 10.00000000, 0))
		{
			activateGarage = 4;
		}
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