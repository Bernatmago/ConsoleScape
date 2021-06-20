#include "../include/World.h"

World::World(string playerName)
{	
	this->gameOver = false;

	// Room definitions
	//Starting room
	Room* desktop = new Room("/home/" + playerName + "/desktop", CommonDescription("desktop", "your applications"));
	entities.push_back(desktop);
	//Second Room
	Room* user = new Room("/home/" + playerName, CommonDescription("user", "your files"));
	entities.push_back(user);
	// Sub-rooms
	Room* pictures = new Room("/home/" + playerName + "/pictures", CommonDescription("user", "safe for work pictures"));
	entities.push_back(pictures);
	Room* music = new Room("/home/" + playerName + "/music", CommonDescription("user", "some sick beats"));
	entities.push_back(desktop);
	// Third Room
	Room* home = new Room("/home", CommonDescription("home", "other users data"));
	entities.push_back(home);
	// Fourth Room
	Room* root = new Room("?", CommonDescription("?", "powerful commands"));
	entities.push_back(root);

	// Room connections (unlocked by default)
	Exit* exitDU = new Exit(playerName, Direction::NORTH, desktop, user);
	desktop->AddEntity(exitDU);
	Exit* exitUD = new Exit("desktop", Direction::SOUTH, user, desktop);
	user->AddEntity(exitUD);

	Exit* exitUP = new Exit("pictures", Direction::WEST, user, pictures);
	user->AddEntity(exitUP);
	Exit* exitPU = new Exit(playerName, Direction::EAST, pictures, user);
	pictures->AddEntity(exitPU);

	Exit* exitUM = new Exit("music", Direction::EAST, user, music);
	user->AddEntity(exitUM);
	Exit* exitMU = new Exit(playerName, Direction::WEST, music, user);
	music->AddEntity(exitMU);

	Exit* exitUH = new Exit("home", Direction::NORTH, user, home);
	user->AddEntity(exitUH);
	Exit* exitHU = new Exit(playerName, Direction::SOUTH, home, user);
	home->AddEntity(exitHU);

	Exit* exitHR = new Exit("root", Direction::NORTH, home, root);
	home->AddEntity(exitHR);
	Exit* exitRH = new Exit("home", Direction::SOUTH, root, home);
	root->AddEntity(exitRH);

	// Escape exit
	Exit* end = new Exit("Strange mirror", Direction::WEST, root, nullptr, true);
	root->AddEntity(end);

	// Npc definitions
	Npc* cortana = new Npc("Cortana", "Your personal assistant", desktop, "How may i help you, " + playerName + "?");
	desktop->AddEntity(cortana);
	Npc* zork = new Npc("Zork", "A well known text based game", desktop, "I am your father, literally!");
	desktop->AddEntity(zork);
	Npc* unfinishedProject = new Npc("Unfinished project", "It has some python 2.7 code", user, "I have merge conflicts, please fix them...");
	user->AddEntity(unfinishedProject);
	Npc* os = new Npc("OS", "The one who rules this game", root, "You are trapped in this machine forever! (Unless you have an exploit)");
	root->AddEntity(root);

	// Item definitions
	Item* cd = new Item("cd", "allows you to change directories"); // Allows to move when used
	Item* passwordFile = new Item("password.txt", "Super secret password: 1234"); // Gives the password required to enter home
	Item* sudo = new Item("sudo", "grants admin permissions"); // Unlocks door to root
	Item* forkBomb = new Item("forkbomb", ":(){ :|:& };:"); // Wins the game when used and location is root
	Item* animePicture = new Item("anime picture", "picture of your faviourite anime character"); // Useless
	Item* mixtape = new Item("mixtape", "your newest mixtape, its fire (available on soundcloud)"); // Useless

	// Locate Items
	// Desktop
	desktop->AddEntity(cd);
	// User	
	user->AddEntity(sudo);
	// Pictures
	pictures->AddEntity(animePicture);
	pictures->AddEntity(forkBomb);
	// Music
	music->AddEntity(mixtape);
	music->AddEntity(passwordFile);
	// Home (No items)
	// Root (No items)

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
	string actionTarget = "";
	if (tokens.size() > 1)
		actionTarget = tokens.at(1);

	if (baseAction == ACTION_HELP)
		ShowActions();
	else if (baseAction == ACTION_GO)
		player->Go(actionTarget);
	else if (baseAction == ACTION_GRAB)
		player->Grab(actionTarget);
	else if (baseAction == ACTION_DROP)
		player->Drop(actionTarget);
	else if (baseAction == ACTION_TALK)
		player->Talk(actionTarget);
	else if (baseAction == ACTION_INSPECT)
		if (actionTarget != "")
			player->Inspect(actionTarget);
		else
			player->DescribeCurrentRoom();
	else if (baseAction == ACTION_ITEMS)
		player->ShowItems();
	else if (baseAction == ACTION_USE)
			player->UseItem(actionTarget);
	else if (baseAction == ACTION_BREATHE)
		player->Breathe();
	else if (baseAction == ACTION_EXIST)
		player->Go(actionTarget);
	else if (baseAction == ACTION_SURRENDER) {
		gameOver = true;
		cout << "You have forfeited, better luck next time <3" << endl;
	}		
	else
		cout << "Could not parse action, try again" << endl;
}

string World::CommonDescription(string dirName, string extraDescription) {
	return "This is the " + dirName + " directory, here you can find " + extraDescription + ".";
}

void World::ShowActions() {
	cout << "Commands:" << endl;
	// Gameplay Actions
	cout << "- " << ACTION_GO << ":" << endl;
	cout << "- " << ACTION_GRAB << ":" << endl;
	cout << "- " << ACTION_DROP << ":" << endl;
	cout << "- " << ACTION_TALK << ":" << endl;
	cout << "- " << ACTION_INSPECT << ":" << endl;
	cout << "- " << ACTION_ITEMS << ":" << endl;
	
	// Item actions
	cout << "- " << ACTION_USE<< " <item>:" << endl;


	// Game Control Actions
	cout << "- " << ACTION_SURRENDER << ":" << endl;
}
