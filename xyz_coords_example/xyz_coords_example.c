#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "Functions.c"

float x, y, z, h, pos_x = 0.05000000, width = 0.30000000, height = 0.30000000;
uint r = 255, g = 255, b = 255, a = 110;

void DoStuff(void)
{
	GET_CHAR_COORDINATES(GetPlayerPed(), &x, &y, &z);
	GET_CHAR_HEADING(GetPlayerPed(), &h);

	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.10000000, x);
	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.13000000, y);
	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.16000000, z);
	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.19000000, h);
}

void main(void)
{
	while(true)
	{
		WAIT(0);
		// We only want stuff to happen while their playing.
		if (IS_PLAYER_PLAYING(GetPlayerIndex()))
		{
			DoStuff();
		}
	}
}