#pragma once
#include "Entity.h"


class Exit:
	public Entity
{
public:
	Exit(string name, Direction direction, Room* location, Room* destination, bool locked=false);

	Direction& GetDirection() const;
	Room* GetLocation() const;
	Room* GetDestination() const;

	bool& Locked();

private:
	Direction direction;
	Room* location;
	Room* destination;
	bool locked;

	string ExitDescription(Room* destination);
};

