#include "../include/Player.h"

Player::Player(string name, string description, Room* location) : Creature(name, description, CreatureType::PLAYER, location) {
	canMove = false;
	isAdmin = false;
}

void Player::ShowItems() {
	cout << "Inventory:" << endl;
	this->ShowEntities(EntityType::ITEM);
}

void Player::DescribeCurrentRoom() {
	// Current Room
	cout << "Current location: " << location->GetName() << endl;
	location->PrintDescription();

	// Room contents
	cout << "Items:" << endl;
	location->ShowEntities(EntityType::ITEM);

	cout << "Npcs:" << endl;
	location->ShowEntities(EntityType::CREATURE);

	cout << "Doors: " << endl;
	// How to show elegantly direction
	list<Exit*> exits = GetEntityTypeFromTarget<Exit>((Entity*)location, EntityType::EXIT);
	for (Exit* e : exits)
		// Get direction string
		cout << e->GetName() << ": (" << DirectionString(e->GetDirection()) << ")" << endl;
	// location->ShowEntities(EntityType::EXIT);
}

void Player::Go(const string& directionString) {
	Direction* direction = ParseDirection(directionString);
	if (CanMove()) {
		Exit* exit = GetExitFromDirection(direction);
		if (exit != nullptr) {
			if (!exit->Locked()) {
				location = exit->GetDestination();
				if (location != nullptr)
					location->Describe();
			}
		}
		else
			cout << "No directory found in this direction" << endl;
	}
	else
		cout << "You dont have permission to move" << endl;
}
void Player::Grab(const string& itemName) {
	Item* item = GetEntityFromTarget<Item>(itemName, location, EntityType::ITEM);
	if (item != nullptr) {
		AddEntity(item);
		location->RemoveEntity(item);
		cout << item->GetName() << " obtained!" << endl;
	}
	else
		cout << "Item not found" << endl;
}
void Player::Drop(const string& itemName) {
	Item* item = GetEntityFromTarget<Item>(itemName, this, EntityType::ITEM);
	if (item != nullptr) {
		RemoveEntity(item);
		location->AddEntity(item);
		cout << item->GetName() << " dropped on " << location->GetName() << endl;
	}
	else
		cout << "You dont have this item" << endl;
}
void Player::Talk(const string& entityName) {
	Npc* npc = GetEntityFromTarget<Npc>(entityName, this, EntityType::CREATURE);
	if (npc != nullptr)
		npc->PrintResponse();
	else
		cout << "There is no npc with this name" << endl;
}

void Player::Inspect(const string& entityName) {
	// Current Room
	if (entityName == location->GetName())
		location->PrintDescription();
	// Room contents
	for (Entity* e : location->GetContained()) {
		if (entityName == e->GetName()) {
			e->PrintDescription();
			return;
		}
	}	
	// Inventory items
	for (Entity* e : GetContained()) {
		if (entityName == e->GetName()) {
			e->PrintDescription();
			return;
		}
	}
	cout << "Could not find anything with this name" << endl;
}

void Player::UseItem(const string& itemName) {
	Item* item = GetEntityFromTarget<Item>(itemName, this, EntityType::ITEM);
	if (item != nullptr) {
		if (itemName == "cd") {
			cout << "You have gained the ability of changing directories!" << endl;
			MakeMoveable();
		}			
		if (itemName == "sudo") {
			cout << "[WARNING] Admin permissions have been granted, proceed with caution!" << endl;
			MakeAdmin();
		}
		if (itemName == "forkbomb") {
			if (location->GetName() == "root") {
				cout << "System destruction initialized, you have won the game!" << endl;
			}
			else
				cout << "You need to be near the os for this exploit to take effect" << endl;
		}
		else
			cout << "This item has no effect maybe you can inspect it to gain useful (or not) information" << endl;
	}
	else
		cout << "You dont have this item" << endl;
}

void Player::Unlock(const string& directionString) {
	Direction* direction = ParseDirection(directionString);
	Exit* exit = GetExitFromDirection(direction);
	if (exit != nullptr) {
		// Password doors
		if (exit->GetName() == "home") {
			string password = "";
			cin >> password;
			if (password == "1234") {
				exit->Unlock();
				cout << "Correct password introduced" << endl;
			}
			else
				cout << "Wrong password, look for clues" << endl;
			return;				
		}
		Item* key = GetEntityFromTarget<Item>("sudo", this, EntityType::ITEM);
		
		if (key != nullptr) {
			if (exit->Locked()) {
				exit->Unlock();
				cout << "Access permission granted" << endl;
			}
			else
				cout << "Exit already unlocked" << endl;
		}
		else
			cout << "You dont have the admin key" << endl;		
	}
	else
		cout << "Exit not found" << endl;

}

bool Player::CanMove() const { return canMove; }

bool Player::IsAdmin() const { return isAdmin; }

void  Player::Breathe() { cout << "You are trying to breath, unfortunately you are just a combination of bits." << endl; }

void  Player::Exist() { cout << "You existing, good job..." << endl; }

void Player::MakeAdmin() { isAdmin = true; }

void Player::MakeMoveable() { canMove = true; }

Direction* Player::ParseDirection(const string& directionString) {
	if (directionString == DIR_NORTH)
		return new Direction(Direction::NORTH);
	if (directionString == DIR_EAST)
		return new Direction(Direction::EAST);
	if (directionString == DIR_SOUTH)
		return new Direction(Direction::SOUTH);
	if (directionString == DIR_WEST)
		return new Direction(Direction::WEST);
	return nullptr;
}

string Player::DirectionString(Direction direction) {
	if (direction == Direction::NORTH)
		return DIR_NORTH;
	if (direction == Direction::EAST)
		return DIR_EAST;
	if (direction == Direction::SOUTH)
		return DIR_SOUTH;
	if (direction == Direction::WEST)
		return DIR_WEST;
	else
		return "Unknown Dir";
}

template <class T>
list<T*> Player::GetEntityTypeFromTarget(const Entity* target, const EntityType type) const {
	list <T*> filteredEntities;
	for (Entity* e : target->GetContained())
		if (type == e->GetType())
			filteredEntities.push_back((T*)e);
	return filteredEntities;
}

template <class T>
T* Player::GetEntityFromTarget(const string& name, const Entity* target, const EntityType type) const {
	list<T*> filteredEntities = GetEntityTypeFromTarget<T>(target, type);
	if (filteredEntities.size() > 0)
		for (Entity* e : filteredEntities)
			if (name == e->GetName())
				return (T*)e;
	return nullptr;
}

Exit* Player::GetExitFromDirection(const Direction* direction) const {
	for (Exit* e : GetEntityTypeFromTarget<Exit>((Entity*)location, EntityType::EXIT))
		if (*direction == e->GetDirection())
			return e;
	return nullptr;

}