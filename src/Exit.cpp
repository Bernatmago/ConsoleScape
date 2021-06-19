#include "../include/Exit.h"


Exit::Exit(string name, Direction direction, Room* location, Room* destination, bool locked=false) : Entity(name, ExitDescription(destination), EntityType::EXIT) {
	this->direction = direction;
	this->location = location;
	this->destination = destination;
	this->locked = locked;
}

Direction Exit::GetDirection() const { return direction; }
Room* Exit::GetLocation() const { return location; }
Room* Exit::GetDestination() const { return destination; }
bool& Exit::Locked() { return locked; }

string Exit::ExitDescription(Room* destination) {
	return "Changes working directory to " + destination->GetName();
}