#include "../include/Creature.h"


Creature::Creature(string name, string description, CreatureType creatureType, Room* location) :Entity(name, description, EntityType::CREATURE) {
	this->creatureType = creatureType;
}

Room* Creature::GetLocation() const {
	return location;
}

CreatureType Creature::GetCreatureType() const{
	return creatureType;
}