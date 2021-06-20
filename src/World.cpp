#include "../include/World.h"

World::World(string playerName)
{	
	this->gameOver = false;

	// Room definitions
	//Starting room
	Room* desktop = new Room("root/home/" + playerName + "/desktop", CommonDescription("desktop", "Your applications"));
	entities.push_back(desktop);
	//Second Room
	Room* user = new Room("root/home/" + playerName, CommonDescription("user", "Your files"));
	entities.push_back(user);
	// Sub-rooms
	Room* pictures = new Room("root/home/" + playerName + "/pictures", CommonDescription("user", "Safe for work pictures"));
	entities.push_back(pictures);
	Room* music = new Room("root/home/" + playerName + "/music", CommonDescription("user", "Some sick beats"));
	entities.push_back(desktop);
	// Third Room
	Room* home = new Room("root/home", CommonDescription("home", "Other users data"));
	entities.push_back(home);
	// Fourth Room
	Room* root = new Room("root", CommonDescription("root", "Powerful commands"));
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

	Exit* exitUH = new Exit("home", Direction::NORTH, user, home, true);
	user->AddEntity(exitUH);
	Exit* exitHU = new Exit(playerName, Direction::SOUTH, home, user);
	home->AddEntity(exitHU);

	Exit* exitHR = new Exit("root", Direction::NORTH, home, root, true);
	home->AddEntity(exitHR);
	Exit* exitRH = new Exit("login", Direction::SOUTH, root, home);
	root->AddEntity(exitRH);

	// Cannot be unlockd, just for the inspect
	Exit* outsideWorld = new Exit("?¿?¿ The real world ?¿?¿", Direction::EAST, root, nullptr, true);
	root->AddEntity(outsideWorld);

	// Npc definitions
	Npc* cortana = new Npc("Cortana", "Your personal assistant", desktop, "How may i help you, " + playerName + "?");
	desktop->AddEntity(cortana);
	Npc* zork = new Npc("Zork", "A well known text based game", desktop, "I am your father, literally!");
	desktop->AddEntity(zork);
	Npc* unfinishedProject = new Npc("Project", "It has some python 2.7 code", user, "I have merge conflicts, please fix them...");
	user->AddEntity(unfinishedProject);
	Npc* guestUser = new Npc("guest", "Elon", root, "I contain all of Elon's plans, so unlucky that my data is encrypted.");
	home->AddEntity(guestUser);
	Npc* os = new Npc("OS", "The one who rules this game", root, "You are trapped in this machine forever! (Unless you have an exploit)");
	root->AddEntity(os);

	// Item definitions
	Item* cd = new Item("cd", "allows you to change directories"); // Allows to move when used
	Item* passwordFile = new Item("password.txt", "Super secret password: 1234"); // Gives the password required to enter home
	Item* sudo = new Item("sudo", "grants admin permissions"); // Unlocks door to root
	Item* forkBomb = new Item("forkbomb", ":(){ :|:& };:"); // Wins the game when used and location is root
	Item* animePicture = new Item("picture", "picture of your faviourite anime character"); // Useless
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
	if (tokens.size() > 0) {
		string baseAction = tokens.front();
		string actionTarget = "";
		if (tokens.size() > 1)
			actionTarget = tokens.at(1);

		if (baseAction == ACTION_HELP)
			ShowActions();
		else if (baseAction == ACTION_GO)
			player->Go(actionTarget);
		else if (baseAction == ACTION_UNLOCK)
			player->Unlock(actionTarget);
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
}

void World::ProcessWinCondition() {
	if (player->GetLocation() == nullptr)
		gameOver = true;
}

string World::CommonDescription(string dirName, string extraDescription) {
	return "This is the " + dirName + " directory, here you can find " + extraDescription + ".";
}

void World::ShowActions() {
	cout << "Commands:" << endl;
	// Gameplay Actions
	cout << "- " << ACTION_GO << " <direction>" << endl;
	cout << "- " << ACTION_GRAB << " <item>" << endl;
	cout << "- " << ACTION_DROP << " <item>" << endl;
	cout << "- " << ACTION_TALK << " <npc>" << endl;
	cout << "- " << ACTION_INSPECT << " <target> (no target means inspect room)" << endl;
	cout << "- " << ACTION_ITEMS << endl;
	cout << "- " << ACTION_UNLOCK << " <direction>" << endl;

	
	// Item actions
	cout << "- " << ACTION_USE<< " <item>" << endl;


	// Game Control Actions
	cout << "- " << ACTION_SURRENDER << endl;
}
