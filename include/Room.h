#pragma once
#include "Entity.h"

using namespace std;

class Room :
	public Entity
{
public:
	Room(string name, string description) : Entity(name, description, EntityType::ROOM) {}
};

