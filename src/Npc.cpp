#include "../include/Npc.h"

Npc::Npc(string name, string description, Room* location, string response): Creature(name, description, CreatureType::NPC, location) {
	this->response = response;
	this->position = position;
}