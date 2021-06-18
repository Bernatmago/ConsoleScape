#pragma once
#include "entity.h"

class Item :
	public Entity
{
public:
	// TODO: Manage item types
	Item(string name, string description) : Entity(name, description, EntityType::ITEM){}
};

