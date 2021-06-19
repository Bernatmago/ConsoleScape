#pragma once
#include <string>
#include <list>
#include "World.h"

using namespace std;

enum EntityType
{
	//ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE	
};

class Entity
{
public:	
	virtual ~Entity();
	string GetName() const;
	EntityType GetType() const;

	Entity* GetParent() const;
	void SetParent(Entity* parent);

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);

	virtual void PrintDescription();
	virtual void ShowEntities(EntityType type);

	Entity* GetContained(const string& name, const EntityType type) const;

protected:
	Entity(string name, string description, EntityType type);
	string name;
	string description;
	EntityType type;
	// Entity that contains it (if any)
	Entity* parent;
	// Entities contained inside that entity (Items on Room, Items on player, etc..)
	list<Entity*> contains;
};

