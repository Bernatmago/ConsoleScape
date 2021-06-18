#pragma once
#include <string>
#include <list>

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
	Entity(string name, string description, EntityType type);
	virtual ~Entity();

	string GetName() const;
	string GetDescription() const;
	EntityType GetType() const;

	Entity* GetParent() const;
	void SetParent(Entity* parent);

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);

	virtual void PrintDescription();
	virtual void ShowEntities(EntityType type);


protected:
	string name;
	string description;
	EntityType type;
	Entity* parent;
	list<Entity*> contains;
};

