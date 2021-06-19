#include "../include/Player.h"

void Player::ShowItems() {

}
void Player::DescribeCurrentRoom() {

}


void Player::Go(const string& roomName) {

}
void Player::Grab(const string& itemName) {
}
void Player::Drop(const string& itemName) {
}
void Player::Talk(const string& entityName) {
}
void Player::Inspect(const string& entityName) {
}
void Player::UseItem(const string& itemName) {
}
void Player::UseItem(const string& itemName, const string& targetEntityName) {
}

void  Player::Breathe() { cout << "You are trying to breath, unfortunately you are just a combination of bits." << endl; }
void  Player::Exist() { cout << "You existing, good job..." << endl; }

template <class EntityType>
// Todo Implement
EntityType* Player::GetEntityFromTarget(const string& name, const Entity* target, const EntityType type) const { return nullptr; }
Exit* Player::GetExitFromDirection(const Direction& dir) const { return nullptr; }