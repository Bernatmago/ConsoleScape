#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

#include "GameCommons.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Npc.h"

using namespace std;

class World
{
public:
	World(string playerName);
	// TODO: implement destructor
	//~World();

	void GetActionString(string input);
	bool GameOver() const;

private:
	bool gameOver;
	Player* player;
	vector<Entity*> entities;

	vector<string> ParseActionString(string actionString);
	void ProcessAction(const vector<string>& tokens);
	string CommonDescription(string dirName, string extraDescription);
	void ShowActions();	
};

