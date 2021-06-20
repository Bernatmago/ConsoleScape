#include "../include/Entity.h"


Entity::Entity(string name, string description, EntityType type)
{
	this->name = name;
	this->description = description;
	this->type = type;
	this->parent = nullptr;
}

Entity::~Entity()
{
	for (Entity* e : contains)
		delete e;
	contains.clear();
}


string Entity::GetName() const { return name; }

EntityType Entity::GetType() const { return type; }

Entity* Entity::GetParent() const { return parent; }

void Entity::SetParent(Entity* parent) { this->parent = parent; }

void Entity::AddEntity(Entity* entity) { contains.push_back(entity); }

void Entity::RemoveEntity(Entity* entity) { contains.remove(entity); }

list<Entity*> Entity::GetContained() const { return contains; }

void Entity::PrintDescription() { cout << description << endl; }

void Entity::ShowEntities(EntityType type) {
	for (Entity* e : contains) {
		if (type == e->GetType()) {
				cout << "- " << e->GetName() << endl;
		}
	}
}

