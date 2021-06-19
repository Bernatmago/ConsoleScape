#pragma once
#include "Entity.h"

using namespace std;

class Item :
	public Entity
{
public:
	Item(string name, string description) : Entity(name, description, EntityType::ITEM){}
};

