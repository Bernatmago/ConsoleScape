#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>


#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Player.h"
#include "Npc.h"

// Gameplay Actions
#define ACTION_GO "go"
#define ACTION_GRAB "grab"
#define ACTION_DROP "drop"
#define ACTION_TALK "talk"
#define ACTION_INSPECT "inspect"
#define ACTION_ITEMS "items"

// Item actions
#define ACTION_USE "use" 
#define ACTION_ITEM_TARGET "on"

// Gimmicks
#define ACTION_BREATHE "breathe"
#define ACTION_EXIST "exist"

// Game Control Actions
#define ACTION_SURRENDER "surrender"

enum Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};


class World
{
public:
	World(string playerName);
	// TODO: implement destructor
	~World();

	void GetActionString(string input);
	bool GameOver() const;

private:
	bool gameOver;
	Player* player;
	vector<Entity*> entities;

	vector<string> ParseActionString(string actionString);
	void ProcessAction(const vector<string>& tokens);
	string CommonDescription(string dirName, string extraDescription);

	
};

