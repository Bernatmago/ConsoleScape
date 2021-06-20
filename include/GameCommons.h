#pragma once

// Gameplay Actions
#define ACTION_HELP "help"
#define ACTION_GO "go"
#define ACTION_GRAB "grab"
#define ACTION_DROP "drop"
#define ACTION_TALK "talk"
#define ACTION_INSPECT "inspect"
#define ACTION_ITEMS "items"
#define ACTION_UNLOCK "unlock"

// Item actions
#define ACTION_USE "use"

// Gimmicks (Not shown on help)
#define ACTION_BREATHE "breathe"
#define ACTION_EXIST "exist"

// Game Control Actions
#define ACTION_SURRENDER "surrender"

// Directions
#define DIR_NORTH "north"
#define DIR_EAST "east"
#define DIR_SOUTH "south"
#define DIR_WEST "west"

enum class Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

