#pragma once
#include "GameCommons.h"
#include "Creature.h"

using namespace std;

class Npc :
	public Creature
{
public:
	Npc(string name, string description, Room* location, string response);

	void PrintResponse();

private:
	string response;
};

