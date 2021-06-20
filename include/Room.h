#pragma once
#include "Entity.h"

using namespace std;

class Room :
	public Entity
{
public:
	Room(string name, string description);
	void Describe();
};

