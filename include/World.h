#pragma once

#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Npc.h"

// Gameplay Actions
#define ACTION_GO "go"
#define ACTION_GRAB "grab"
#define ACTION_DROP "drop"
#define ACTION_INSPECT "isnpect"
#define ACTION_ITEMS "items"
#define ACTION_USE "use" //use on other things?

// Gimmicks
#define ACTION_BREATHE "breathe"
#define ACTION_EXIST "exist"

// Game Control Actions
#define ACTION_SURRENDER "surrender"

enum Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};


class World
{
};

