#include "../include/Exit.h"


Exit::Exit(string name, string description, Direction direction, Room* location, Room* destination, bool locked=false) : Entity(name, description, EntityType::EXIT) {
	this->direction = direction;
	this->location = location;
	this->destination = destination;
	this->locked = locked;
}

Direction& Exit::GetDirection() const {}
Room* Exit::GetLocation() const {}
Room* Exit::GetDestination() const {}
bool& Exit::Locked() {}