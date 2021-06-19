#include <iostream>
#include <string>
#include "include/World.h"

int main()
{
	string input;

    std::cout << "Booting up system!" << endl;
	std::cout << "Username:" << endl;
	getline(cin, input);

	World world(input);

	while (!world.GameOver()) {

		getline(cin, input);

		world.GetActionString(input);
		
	}
}