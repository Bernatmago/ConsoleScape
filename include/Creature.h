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
	Creature(string name, string description, CreatureType creatureType, Room* location):Entity(name, description, EntityType::CREATURE){
		this->creatureType = creatureType;
		this->location = location;
	}

	Room* GetLocation() const;
	CreatureType GetCreatureType() const;

protected:
	CreatureType creatureType;
	Room* location;
};

