#include "../include/Entity.h"


Entity::Entity(string name, string description, EntityType type)
{
	this->name = name;
	this->description = description;
	this->type = type;
	this->parent = nullptr;
}

Entity::~Entity()
{
}
		