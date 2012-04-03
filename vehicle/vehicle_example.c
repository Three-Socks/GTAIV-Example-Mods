/**
 * This file is from https://bitbucket.org/ThreeSocks/gtaiv-example-mods/
 *
 * By Three-Socks
 *
 * Spawns brucie's banshee and set various options on the car (most are not needed) and change its colour.
 *
 */

#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

void main(void)
{
	// This will be the vehicle that will be spawned. Check /inc/consts.h line 618 for vehicle model's.
	uint vehicle_model = MODEL_BANSHEE;
	// The coords the vehicle will spawn in.
	// For this example it will spawn it +5 y away from the current player coords.
	float spawn_x, spawn_y, spawn_z;
	GET_CHAR_COORDINATES(GetPlayerPed(), &spawn_x, &spawn_y, &spawn_z);
	spawn_y += 5;

	REQUEST_MODEL(vehicle_model);
	// Wait for the requested model to load. Otherwise it will crash if we try to use CREATE_CAR on the model.
	while (!HAS_MODEL_LOADED(vehicle_model)) WAIT(0);	

	// This makes so the car won't spawn in traffic but it may still spawn parked.
	// Ignore the above comment. This needs more testing. I'm unsure now on the full effects of this function.
	//SUPPRESS_CAR_MODEL(vehicle_model);

	// Actually create the car. Store it in v_spawn. 
	// The last parameter sets if we want to use collision detection. 
	// Use false if you want to spawn it exactly where you want it to.
	Vehicle v_spawn;
	CREATE_CAR(vehicle_model, spawn_x, spawn_y, spawn_z, &v_spawn, true);

	// Sets the vehicle heading
	// Not needed for this example as we use usng collision detection to auto place the car.
	//SET_CAR_HEADING(v_spawn, 180.0000);

	// Free up the vehicle model in memory.
	MARK_MODEL_AS_NO_LONGER_NEEDED(v_spawn);

	// This will make so the vehicle will never disappear
	// until another vehicle is set as the "mission car".
	SET_CAR_AS_MISSION_CAR(v_spawn);

	// These three natives are not needed. But are used incase
	// you want to do the opposite of what they do currently.
	SET_HAS_BEEN_OWNED_BY_PLAYER(v_spawn, true);
	SET_NEEDS_TO_BE_HOTWIRED(v_spawn, false);
	FREEZE_CAR_POSITION(v_spawn, false);

	// Set the 1st colour and the 2nd colour
	// The last two params are the colour. Look here for the colour codes: http://www.gtamodding.com/index.php?title=Carcols.dat#GTA4
	CHANGE_CAR_COLOUR(v_spawn, 0, 89);

	// Set the 1st/2nd extra car colour. Normally the specular or sometimes changes the wheel colour. 
	SET_EXTRA_CAR_COLOURS(v_spawn, 0, 0);

	// Clean the vehicle.
	SET_VEHICLE_DIRT_LEVEL(v_spawn, 0);
	WASH_VEHICLE_TEXTURES(v_spawn, 255);

	TERMINATE_THIS_SCRIPT();
}