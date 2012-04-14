/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 * Draws a coloured cylinder (chevron) that once walked into it activates some code.
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

void main(void)
{

	// The Brucie Heli pad down coords
	float teleport_helidown_x = 791.2693, teleport_helidown_y = 126.9362, teleport_helidown_z = 6.0402, teleport_helidown_h = 105.0,
	draw_helidown_x = 776.2130, draw_helidown_y = 153.2802, draw_helidown_z = 27.5750;

	// The Brucie Heli pad up coords
	float teleport_heliup_x = 778.4066, teleport_heliup_y = 152.2448, teleport_heliup_z = 27.8394, teleport_heliup_h = 268.0,
	draw_heliup_x = 794.3923, draw_heliup_y = 127.7523, draw_heliup_z = 6.0455;


	while(true)
	{
		WAIT(0);

		// Brucie Heli pad down.
		DRAW_COLOURED_CYLINDER(draw_helidown_x, draw_helidown_y, draw_helidown_z - 2, 0.80000000, 0.20000000, 0, 132, 202, 255);
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), draw_helidown_x, draw_helidown_y, draw_helidown_z, 0.80000000, 0.80000000, 2.00000000, 0 ))
		{
			if (IS_CHAR_ON_FOOT(GetPlayerPed()))
			{
				// If the player walks into the cylinder and is on foot. Activate some code. In this case it spawns to the bottom of the helipad.
				SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), teleport_helidown_x, teleport_helidown_y, teleport_helidown_z);
				SET_CHAR_HEADING(GetPlayerPed(), teleport_helidown_h);
				LOAD_SCENE(teleport_helidown_x, teleport_helidown_y, teleport_helidown_z);
				SET_CAM_BEHIND_PED(GetPlayerPed());
			}
		}

		// Brucie Heli pad up.
		DRAW_COLOURED_CYLINDER(draw_heliup_x, draw_heliup_y, draw_heliup_z - 2, 0.80000000, 0.20000000, 0, 132, 202, 255);
		if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), draw_heliup_x, draw_heliup_y, draw_heliup_z, 0.80000000, 0.80000000, 2.00000000, 0 ))
		{
			if (IS_CHAR_ON_FOOT(GetPlayerPed()))
			{
					SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), teleport_heliup_x, teleport_heliup_y, teleport_heliup_z);
					SET_CHAR_HEADING(GetPlayerPed(), teleport_heliup_h);
					LOAD_SCENE(teleport_helidown_x, teleport_helidown_y, teleport_helidown_z);
					SET_CAM_BEHIND_PED(GetPlayerPed());
			}
		}
	}

}