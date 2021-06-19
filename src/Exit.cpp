#include "../include/Exit.h"


Exit::Exit(string name, Direction direction, Room* location, Room* destination, bool locked=false) : Entity(name, ExitDescription(destination), EntityType::EXIT) {
	this->direction = direction;
	this->location = location;
	this->destination = destination;
	this->locked = locked;
}

Direction& Exit::GetDirection() const {}
Room* Exit::GetLocation() const {}
Room* Exit::GetDestination() const {}
bool& Exit::Locked() {}

string Exit::ExitDescription(Room* destination) {
	return "Changes directory to " + destination->GetName();
}