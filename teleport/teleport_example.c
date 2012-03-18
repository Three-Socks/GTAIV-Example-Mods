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

void main(void)
{

	while (IS_SCREEN_FADING())
	{
		WAIT(0);
	}
	DO_SCREEN_FADE_OUT(500);
	while (IS_SCREEN_FADING())
	{
		WAIT(0);
	}

	float x = 862.05460000, y = -120.81720000, z = 4.95870000;
	SET_PLAYER_CONTROL(GetPlayerIndex(), false);
	
	LOAD_SCENE(x, y, z);
	WAIT(500);

	SET_PLAYER_CONTROL(GetPlayerIndex(), true);
	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), x, y, z);
	
	while (IS_SCREEN_FADING())
	{
		WAIT(0);
	}
	DO_SCREEN_FADE_IN(500);
	while (IS_SCREEN_FADING())
	{
		WAIT(0);
	}
	TERMINATE_THIS_SCRIPT();
}