#pragma once
#include "entity.h"

class Item :
	public Entity
{
public:
	Item(string name, string description) : Entity(name, description, EntityType::ITEM){}
};

