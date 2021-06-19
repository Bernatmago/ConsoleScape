#pragma once
#include "GameCommons.h"
#include "World.h"
#include "Entity.h"
#include "Room.h"

using namespace std;

class Creature :
	public Entity
{
public:
	Creature(string name, string description, CreatureType creatureType, Room* location);

	Room* GetLocation() const;
	CreatureType GetCreatureType() const;

protected:
	CreatureType creatureType;
	Room* location;
};

