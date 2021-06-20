#pragma once
#include <string>
#include "GameCommons.h"
#include "Creature.h"
#include "Exit.h"
#include "Item.h"

using namespace std;

class Player :
	public Creature
{
public:
	Player(string name, string description, Room* location);

	void ShowItems();
	void DescribeCurrentRoom();

	
	void Go(const string& directionString);
	void Grab(const string& itemName);
	void Drop(const string& itemName);
	void Talk(const string& entityName);
	void Inspect(const string& entityName);
	void UseItem(const string& itemName);
	void UseItem(const string& itemName, const string& targetEntityName);

	bool CanMove() const;
	bool IsAdmin() const;

	// Gimmicks (No real use)
	void Breathe();
	void Exist();

protected:
	bool canMove;
	bool isAdmin;
	void MakeAdmin();
	void MakeMoveable();
	Direction* ParseDirection(const string& directionString);
	template <class T>
	list<T*> GetEntityTypeFromTarget(const Entity* target, const EntityType type) const;
	template <class T>
	T* GetEntityFromTarget(const string& name, const Entity* target, const EntityType type) const;
	Exit* GetExitFromDirection(const Direction* direction) const;
	
};
