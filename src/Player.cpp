#include "../include/Player.h"

void ShowItems();
void DescribeCurrentRoom();


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

template <class EntitySubclass>
EntitySubclass* Player::GetEntityFromTarget(const string& name, const Entity* target, const EntityType type) const {}
Exit* Player::GetExitFromDirection(const Direction& dir) const {}