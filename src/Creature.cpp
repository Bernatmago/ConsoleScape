#include "../include/Creature.h"


Creature::Creature(string name, string description, CreatureType creatureType, Room* location, Direction position): Entity(name, description, EntityType::CREATURE) {
	this->creatureType = creatureType;
	this->location = location;
	this->position = position;
}

Room* Creature::GetLocation() const {
	return location;
}

CreatureType Creature::GetCreatureType() const{
	return creatureType;
}