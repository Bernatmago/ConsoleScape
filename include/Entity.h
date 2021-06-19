#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

enum class EntityType
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
	Entity(string name, string description, EntityType type);
	virtual ~Entity();
	string GetName() const;
	EntityType GetType() const;

	Entity* GetParent() const;
	void SetParent(Entity* parent);

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	list<Entity*> GetContained(const string& name, const EntityType type) const;

	virtual void PrintDescription();
	virtual void ShowEntities(EntityType type);

protected:
	string name;
	string description;
	EntityType type;
	// Entity that contains it (if any)
	Entity* parent;
	// Entities contained inside that entity (Items on Room, Items on player, etc..)
	list<Entity*> contains;
};

