#pragma once
#include "Entity.h"
#include "Room.h"

enum CreatureType
{
	NPC,
	PLAYER
};

class Creature :
	public Entity
{
public:
	Creature(string name, string description, CreatureType creatureType, Room* location, Direction position);

	Room* GetLocation() const;
	CreatureType GetCreatureType() const;

protected:
	CreatureType creatureType;
	Room* location;
	Direction position;
};

