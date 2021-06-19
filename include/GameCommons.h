#pragma once

// Gameplay Actions
#define ACTION_HELP "help"
#define ACTION_GO "go"
#define ACTION_GRAB "grab"
#define ACTION_DROP "drop"
#define ACTION_TALK "talk"
#define ACTION_INSPECT "inspect"
#define ACTION_ITEMS "items"

// Item actions
#define ACTION_USE "use" 
#define ACTION_ITEM_TARGET "on"

// Gimmicks (Not shown on help)
#define ACTION_BREATHE "breathe"
#define ACTION_EXIST "exist"

// Game Control Actions
#define ACTION_SURRENDER "surrender"

enum class Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

enum class CreatureType
{
	NPC,
	PLAYER
};

