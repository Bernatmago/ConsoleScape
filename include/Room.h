#pragma once
#include "Entity.h"


class Room :
	public Entity
{
public:
	Room(string name, string description) : Entity(name, description, EntityType::ROOM) {}
};

