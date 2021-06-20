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
	Exit* exitDU = new Exit("cd ./" + playerName, Direction::NORTH, desktop, user);
	desktop->AddEntity(exitDU);
	Exit* exitUD = new Exit("cd ./desktop", Direction::SOUTH, user, desktop);
	user->AddEntity(exitUD);

	Exit* exitUP = new Exit("cd ./pictures", Direction::WEST, user, pictures);
	user->AddEntity(exitUP);
	Exit* exitPU = new Exit("cd ./" + playerName, Direction::EAST, pictures, user);
	pictures->AddEntity(exitPU);

	Exit* exitUM = new Exit("cd ./music", Direction::EAST, user, music);
	user->AddEntity(exitUM);
	Exit* exitMU = new Exit("cd ./" + playerName, Direction::WEST, music, user);
	music->AddEntity(exitMU);

	Exit* exitUH = new Exit("cd ./home", Direction::NORTH, user, home);
	user->AddEntity(exitUH);
	Exit* exitHU = new Exit("cd ./" + playerName, Direction::SOUTH, home, user);
	home->AddEntity(exitHU);

	Exit* exitHR = new Exit("cd ./root", Direction::NORTH, home, root);
	home->AddEntity(exitHR);
	Exit* exitRH = new Exit("cd ./" + playerName, Direction::SOUTH, root, home);
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
	Npc* os = new Npc("OS", "The one who rules this game", home, "You shall not pass! (Unless you have the one command to rule them all)");
	root->AddEntity(os);

	// Item definitions
	Item* cd = new Item("cd command", "allows you to change directories"); // Allows to move when used
	Item* passwordFile = new Item("password.txt", "Super secret password: 1234"); // Gives the password required to enter home
	Item* sudo = new Item("sudo command", "grants admin permissions"); // Allows to access root
	Item* forkBomb = new Item(":(){ :|:& };:", "bash fork bomb"); // Wins the game on root
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
		player->Inspect(actionTarget);
	else if (baseAction == ACTION_ITEMS)
		player->ShowItems();
	else if (baseAction == ACTION_USE) {
		if (tokens.size() > 3 && tokens.at(2) == ACTION_ITEM_TARGET)
			// Use item on target
			player->UseItem(actionTarget, tokens.at(3));
		else
			// Use item no target
			player->UseItem(actionTarget);
	}
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
	cout << "- " << ACTION_USE << " <item> " ACTION_ITEM_TARGET " <target>:" << endl;


// Game Control Actions
#define ACTION_SURRENDER 
}
