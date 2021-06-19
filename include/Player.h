#pragma once
#include "World.h"
#include "Creature.h"


class Player :
	public Creature
{
public:
	Player(string name, string description, Room* location) : Creature(name, description, CreatureType::PLAYER, location) {}

	void ShowItems();
	void DescribeCurrentRoom();

	
	void Go(const string& roomName);
	void Grab(const string& itemName);
	void Drop(const string& itemName);
	void Talk(const string& entityName);
	void Inspect(const string& entityName);
	void UseItem(const string& itemName, const string& targetEntityName);

protected:
	template <class EntitySubclass>
	EntitySubclass* GetEntityFromTarget(const string& name, const Entity* target, const EntityType type) const;
	Exit* GetExitFromDirection(const Direction& dir) const;
};
