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
#define ACTION_TALK "talk"
#define ACTION_INSPECT "inspect"
#define ACTION_ITEMS "items"

// Item actions
#define ACTION_USE "use" 
#define ACTION_TARGET "on"

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

