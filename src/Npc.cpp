#include "../include/Npc.h"

Npc::Npc(string name, string description, Room* location, Direction position, string response): Creature(name, description, CreatureType::NPC, location, Direction:: position) {
	this->response = response;

}