/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "Functions.c"

float game_cam_x, game_cam_y, game_cam_z, pos_x = 0.0500, width = 0.3000, height = 0.3000;
uint r = 255, g = 255, b = 255, a = 110;
Camera game_cam;

void DoLoop(void)
{
	GET_GAME_CAM(&game_cam);
	if (IS_CAM_ACTIVE(game_cam))
	{
		GET_CAM_POS(game_cam, &game_cam_x, &game_cam_y, &game_cam_z);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.1000, game_cam_x);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.1300, game_cam_y);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.1600, game_cam_z);
	}
}

void main(void)
{
	while(true)
	{
		WAIT(0);
		DoLoop();
	}
}