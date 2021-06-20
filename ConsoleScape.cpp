#include <iostream>
#include <string>
#include "include/World.h"

using namespace std;

int main()
{
	string input;

    cout << "Booting up system!" << endl;
	cout << "Username: ";

	getline(cin, input);
	World world(input);

	cout << "Welcome " << input << ", you can start writting commands (" << ACTION_HELP " to see commands)" << endl;	

	while (!world.GameOver()) {
		getline(cin, input);
		world.GetActionString(input);
		world.ProcessWinCondition();
	}

	cout << "Press ENTER to close the game" << endl;
	cin.get();
}