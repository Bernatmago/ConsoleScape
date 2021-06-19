#include "../include/World.h"

World::World(string playerName)
{	
	this->gameOver = false;

	// Room definitions
	//Starting room
	Room* desktop = new Room("/home/" + playerName + "/desktop", CommonDescription("desktop", "your applications"));
	//Second Room
	Room* user = new Room("/home/" + playerName, CommonDescription("user", "your files"));
	// Sub-rooms
	Room* pictures = new Room("/home/" + playerName + "/pictures", CommonDescription("user", "safe for work pictures"));
	Room* music = new Room("/home/" + playerName + "/music", CommonDescription("user", "some sick beats"));
	// Third Room
	Room* home = new Room("/home", CommonDescription("home", "other users data"));
	// Fourth Room
	Room* root = new Room("?", CommonDescription("?", "powerful commands"));

	// Room connections (unlocked by default)
	Exit* exitDU = new Exit("cd ./" + playerName, Direction::NORTH, desktop, user);
	Exit* exitUD = new Exit("cd ./desktop", Direction::SOUTH, user, desktop);

	Exit* exitUP = new Exit("cd ./pictures", Direction::WEST, user, pictures);
	Exit* exitPU = new Exit("cd ./" + playerName, Direction::EAST, pictures, user);

	Exit* exitUM = new Exit("cd ./music", Direction::EAST, user, music);
	Exit* exitMU = new Exit("cd ./" + playerName, Direction::WEST, music, user);

	Exit* exitUH = new Exit("cd ./home", Direction::NORTH, user, home);
	Exit* exitHU = new Exit("cd ./" + playerName, Direction::SOUTH, home, user);

	Exit* exitHR = new Exit("cd ./root", Direction::NORTH, home, root);
	Exit* exitHU = new Exit("cd ./" + playerName, Direction::SOUTH, root, home);

	// Escape exit
	Exit* end = new Exit("Strange mirror", Direction::WEST, root, nullptr, true);

	// Npc definitions
	Npc* cortana = new Npc("Cortana", "Your personal assistant", desktop, "How may i help you, " + playerName + "?");
	Npc* unfinishedProject = new Npc("Unfinished project", "It has some python 2.7 code", user, "Please commit some new code to my repo, it gets lonely here...");
	Npc* os = new Npc("OS", "The one who rules this game", root, "You shall not pass! (Unless you have the one command to rule them all)");

	// Item definitions
	Item* cd = new Item("cd command", "allows you to change directories");
	Item* sudo = new Item("sudo command", "grants admin permissions");
	Item* forkBomb = new Item(":(){ :|:& };:", "bash fork bomb");
	Item* animePicture = new Item("anime picture", "picture of your faviourite anime character");
	Item* mixtape = new Item("mixtape", "your newest mixtape, its fire (available on soundcloud)");

	

	// You <3
	this->player = new Player(playerName, "This is you, the user", desktop);

	
	
}


bool World::GameOver() const { return gameOver; }

void World::GetActionString(string input) {
	vector<string> processedInput = ParseActionString(input);
	ProcessAction(processedInput);
}

vector<string> World::ParseActionString(string actionString) {

	istringstream iss(actionString);
	vector<string> tokens{ istream_iterator<string>{iss}, istream_iterator<string>{} };
	return tokens;
}

void World::ProcessAction(const vector<string>& tokens) {
	string baseAction = tokens.front();
	string actionTarget = NULL;
	if (tokens.size() > 1)
		actionTarget = tokens.at(1);

	if (baseAction == ACTION_GO)
		player->Go(actionTarget);
	else if (baseAction == ACTION_GRAB)
		player->Go(actionTarget);
	else if (baseAction == ACTION_DROP)
		player->Go(actionTarget);
	else if (baseAction == ACTION_TALK)
		player->Go(actionTarget);
	else if (baseAction == ACTION_INSPECT)
		player->Go(actionTarget);
	else if (baseAction == ACTION_ITEMS)
		player->Go(actionTarget);
	else if (baseAction == ACTION_USE) {
		if (tokens.size > 3 && tokens.at(2) == ACTION_ITEM_TARGET)
			// Use item on target
			player->Go(actionTarget);
		else
			// Use item no target
			player->Go(actionTarget);
	}
	else if (baseAction == ACTION_BREATHE)
		player->Go(actionTarget);
	else if (baseAction == ACTION_EXIST)
		player->Go(actionTarget);
	else if (baseAction == ACTION_SURRENDER)
		player->Go(actionTarget);
	else
		cout << "Could not parse action, try again" << endl;






}

string World::CommonDescription(string dirName, string extraDescription) {
	return "This is the " + dirName + " directory, here you can find " + extraDescription + ".";
}

