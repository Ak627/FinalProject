#include<iostream>
#include<Windows.h>
int main() {
	int room = 1;
	char input;
	system("title The Lost Traveler");
	std::cout << "You wake up and find yourself in a mysterious forest. Can you figure out the exit? Good luck adventurer have fun." << std::endl;
	std::cout << "You see an opening through the trees." << std::endl;
	do {
		switch (room) {
		case 1:
			system("COLOR 2B");
			std::cout << "You enter the opening you see. You can head North." << std::endl;
			std::cin >> input;
			if (input == 'N')
				room = 2;
			else
				std::cout << "trees block the path this way" << std::endl;
			break;
		case 2:
			system("COLOR 2B");
			std::cout << "You head North and find yourself near a pond." << std::endl;
			std::cout << "There is a path to the West as well as a hike to the East." << std::endl;
			std::cin >> input;
			if (input == 'W')
				room = 3;
			else if (input == 'E')
				room = 4;
			else if (input == 'S')
				room = 1;
			else
				std::cout << "trees block the path this way" << std::endl;
			break;
		case 3:
			system("COLOR 2B");
			std::cout << "You go down the path to the West." << std::endl;
			std::cout << "There is a large cave in Front of you." << std::endl;
			std::cout << "Would you like to enter? Y/N" << std::endl;
			std::cin >> input;
			if (input == 'Y')
				room = 7;
			else if (input == 'N')
				room = 2;
			else
				std::cout << "You stand there aimlessly. You must make a decision" << std::endl;
			break;
		case 4:
			system("COLOR 0B");
			std::cout << "You head East and hike up a small mountain that goes above the tree tops." << std::endl;
			std::cout << "While standing on the mountain you see village further South as well as a light more to the East." << std::endl;
			std::cin >> input;
			if (input == 'S')
				room = 5;
			else if (input == 'E')
				room = 6;
			else if (input == 'W')
				room = 2;
			else
				std::cout << "You stand there wihout any thoughts, please choose a path." << std::endl;
			break;
		case 5:
			system("COLOR 1E");
			std::cout << "You head for the village." << std::endl;
			std::cout << "Upon arrvial you meet the settlers." << std::endl;
			std::cout << "They offer you shelter and food. Do you accept? Y/N" << std::endl;
			std::cin >> input;
			if (input == 'Y')
				room = 8;
			else if (input == 'N') {
				MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The settlers found you very rude."), MB_OK);
				return 0;
			}
			else
				std::cout << "You stand there awkwardly with the settlers" << std::endl;
			break;
		case 6:
			system("COLOR 2E");
			std::cout << "You walk towards the small light." << std::endl;
			std::cout << "The light is a very lovely looking fountain filled with mystical creatures." << std::endl;
			std::cout << "The creatures seem very interested in you, would you like to Stay or keep heading East?" << std::endl;
			std::cin >> input;
			if (input == 'S') {
				MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The creatures were hungry."), MB_OK);
				return 0;
			}
			else if (input == 'E')
				room = 11;
			else if (input == 'W')
				room = 4;
			else
				std::cout << "Please make a decision." << std::endl;
			break;
		case 7:
			system("COLOR 0F");
			std::cout << "You enter the cave it is dark and cold.\n";
			std::cout << "There are three different paths North, South, and West.\n";
			std::cout << "Which way shall you go?\n";
			std::cin >> input;
			if (input == 'N')
				room = 17;
			else if (input == 'S')
				room = 14;
			else if (input == 'W')
				room = 16;
			else if (input == 'E')
				room = 3;
			else
				std::cout << "You stand in the dark and cold. Please choose a path.\n";
			break;
		case 8:
			std::cout << "The settler find your kindness very respectable\n";
			std::cout << "They guide you to a path to what they call 'Mystical Treasure'.\n";
			std::cout << "As you go down their path you see a flower plains to the South\n";
		}
	} while (input != 'q');
}
