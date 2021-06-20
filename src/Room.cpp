#include "../include/Room.h"

Room::Room(string name, string description): Entity(name, description, EntityType::ROOM) {}

void Room :: Describe() {
	cout << "Current directory: " << GetName() << endl;
	cout << "Items:" << endl;
	cout << "Npcs:" << endl;
}