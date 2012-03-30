/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 * Picks up a vehicle while in the skylift.
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#define BUTTON_STICK_LEFT 0x12

Vehicle v_attach;
bool pickedup = false;

void LocateVehicle(float warp_x, float warp_y, float warp_z)
{
	v_attach = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 15.00000000, 0, 70);
	if (!DOES_VEHICLE_EXIST(v_attach))
	{
		v_attach = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 15.00000000, 0, 69);
	}
	if (!DOES_VEHICLE_EXIST(v_attach))
	{
		v_attach = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 15.00000000, 0, 71);
	}
}

void pickupVehicle(void)
{
	float locate_x, locate_y, locate_z;
	GET_CHAR_COORDINATES(GetPlayerPed(), &locate_x, &locate_y, &locate_z);
	LocateVehicle(locate_x, locate_y, locate_z);
	if (DOES_VEHICLE_EXIST(v_attach))
	{
		Vehicle veh_skylift;
		float skylift_heading, v_attach_x, v_attach_y, v_attach_z, v_attach_height;
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &veh_skylift);

		FREEZE_CAR_POSITION(v_attach, true);

		GET_CAR_HEADING(veh_skylift, &skylift_heading);
		GET_CAR_COORDINATES(v_attach, &v_attach_x, &v_attach_y, &v_attach_z);

		SET_CAR_HEADING(v_attach, skylift_heading);

		v_attach_height = GET_HEIGHT_OF_VEHICLE(v_attach, v_attach_x, v_attach_y, v_attach_z, false, true);

		float offset_y = -2.80000000, offset_z = 0.65;
		
		if (IS_BIG_VEHICLE(v_attach))
		{
			offset_y = -3.50000000, offset_z = 0.90;
		}
		ATTACH_CAR_TO_CAR(v_attach, veh_skylift, 0, 0.00000000, -2.80000000, v_attach_height - 0.63, 0.00000000, 0.00000000, 0.00000000);

		pickedup = true;
	}
}

void main(void)
{

	while (true)
	{
		WAIT(0);
		if (IS_PLAYER_PLAYING(GetPlayerIndex()) && IS_CHAR_IN_MODEL(GetPlayerPed(), MODEL_SKYLIFT) && IS_BUTTON_JUST_PRESSED(0, BUTTON_STICK_LEFT))
		{
			if (pickedup)
			{
				pickedup = false;
				if (DOES_VEHICLE_EXIST(v_attach))
				{
					FREEZE_CAR_POSITION(v_attach, false);
					DETACH_CAR(v_attach);
				}
			}
			else
			{
				pickupVehicle();
			}
		}
	}
}