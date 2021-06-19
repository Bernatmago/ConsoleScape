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
	Npc* unfinishedProject = new Npc("Unfinished project", user, "Please commit some new code to my repo, it gets lonely here...");
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

string World::CommonDescription(string dirName, string extraDescription) {
	return "This is the " + dirName + " directory, here you can find " + extraDescription + ".";
}