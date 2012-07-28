#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>
	
Vehicle v_modding;
bool neonToggle;

// Toggle Front & Back neons.
bool neonToggleFB = true;
// Colour RGB.
uint neonColour_r = 71;
uint neonColour_g = 120;
uint neonColour_b = 60;
uint neonColour_n = 60;
// Neon Front Y offset.
float neonFYoff = 1.3;
// Neon Back Y offset.
float neonBYoff = -1.3;
// Neon Middle Y offset.
float neonMYoff = 0.0;
// Neon Height offset.
float neonHeight = 0.0;
// Neon Front & Back range.
float neonFBrange = 2.7;
// Neon Front & Back intensity.
float neonFBIntensity = 85;
// Neon Middle range.
float neonMRange = 2.5;
// Neon Middle intensity.
float neonMIntensity = 85;

void doNeon(void)
{
	if (neonToggle)
	{
		if (DOES_VEHICLE_EXIST(v_modding) && IS_VEH_DRIVEABLE(v_modding))
		{
			float v_attach_x, v_attach_y, v_attach_z, v_attach_h;
			GET_CAR_HEADING(v_modding, &v_attach_h);
			GET_CAR_COORDINATES(v_modding, &v_attach_x, &v_attach_y, &v_attach_z);

			float v_moff_x, v_moff_y, v_moff_z;
			GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(v_modding, -20.0, neonMYoff, neonHeight, &v_moff_x, &v_moff_y, &v_moff_z);

			float mdist;
			GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x + -20.0, v_attach_y + neonMYoff, v_attach_x, v_attach_y, &mdist);
			float mx = COS(v_attach_h) * mdist + v_moff_x;
			float my = SIN(v_attach_h) * mdist + v_moff_y;

			DRAW_LIGHT_WITH_RANGE(mx, my, v_attach_z + neonHeight, neonColour_r, neonColour_g, neonColour_b, neonMRange, neonMIntensity);

			if (neonToggleFB)
			{
				float v_foff_x, v_foff_y, v_foff_z;
				GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(v_modding, -20.0, neonFYoff, neonHeight, &v_foff_x, &v_foff_y, &v_foff_z);
				float v_boff_x, v_boff_y, v_boff_z;
				GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(v_modding, -20.0, neonBYoff, neonHeight, &v_boff_x, &v_boff_y, &v_boff_z);
				float fdist;
				GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x + -20.0, v_attach_y + neonFYoff, v_attach_x, v_attach_y, &fdist);
				float bdist;
				GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x - -20.0, v_attach_y - neonBYoff, v_attach_x, v_attach_y, &bdist);
				float fx = COS(v_attach_h) * fdist + v_foff_x;
				float fy = SIN(v_attach_h) * fdist + v_foff_y;
				float bx = COS(v_attach_h) * bdist + v_boff_x;
				float by = SIN(v_attach_h) * bdist + v_boff_y;
				DRAW_LIGHT_WITH_RANGE(fx, fy, v_attach_z + neonHeight, neonColour_r, neonColour_g, neonColour_b, neonFBrange, neonFBIntensity);
				DRAW_LIGHT_WITH_RANGE(bx, by, v_attach_z + neonHeight, neonColour_r, neonColour_g, neonColour_b, neonFBrange, neonFBIntensity);
			}
		}
		else
		{
			neonToggle = 0;
			MARK_CAR_AS_NO_LONGER_NEEDED(&v_modding);
		}
	}
}
	
void main(void)
{
	if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
	{
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_modding);
		neonToggle = true;
	}

	while(true)
	{
		WAIT(0);
		doNeon();
	}
}