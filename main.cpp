#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void Monsters();

int main() {
	string Inventory[10] = { "wool shirt","wool pants","animal skin shoes","sharpened stick"};
	int room = 1;
	string input;
	system("title The Lost Adventurer");
	cout << "You wake up and find yourself in a mysterious forest. Can you figure out the way out? Will you find the treasure that is rumoured to be in this forest? Good luck adventurer have fun." << std::endl;
	cout << "You see an opening through the trees." << std::endl;
	cout << "(To quit at any point in the game enter q)\n";
	do {
		cout << "Inventory: ";
		for (int i = 0; i < 10; i++)
			cout << Inventory[i] << " , ";
		cout << endl;

		switch (room) {
		case 1:
			system("COLOR 2B");
			cout << "You enter the opening you see. You can head North." << std::endl;
			cin >> input;
			if (input == "North")
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				std::cout << "trees block the path this way" << std::endl;
			break;
		case 2:
			system("COLOR 2B");
			cout << "You head North and find yourself near a pond." << std::endl;
			cout << "There is a path to the West as well as a hike to the East." << std::endl;
			cin >> input;
			if (input == "West")
				room = 3;
			else if (input == "East")
				room = 4;
			else if (input == "South")
				room = 1;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				std::cout << "trees block the path this way" << std::endl;
			break;
		case 3:
			system("COLOR 2B");
			cout << "You go down the path to the West." << std::endl;
			cout << "There is a large cave in Front of you." << std::endl;
			cout << "Would you like to enter? Y/N" << std::endl;
			cin >> input;
			if (input == "Y")
				room = 7;
			else if (input == "N")
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there aimlessly. You must make a decision" << std::endl;
			break;
		case 4:
			system("COLOR 0B");
			cout << "You head East and hike up a small mountain that goes above the tree tops." << std::endl;
			cout << "While standing on the mountain you see village further South as well as a light more to the East." << std::endl;
			cout << "You see a small coin on the ground";
			if (input.compare("pick up") == 4)
				Inventory[4] = "small coin";
			cin >> input;
			if (input == "S")
				room = 5;
			else if (input == "E")
				room = 6;
			else if (input == "W")
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there wihout any thoughts, please choose a path." << std::endl;
			break;
		case 5:
			system("COLOR 1E");
			cout << "You head for the village." << std::endl;
			cout << "Upon arrvial you meet the villagers." << std::endl;
			cout << "They offer you shelter and food. Do you accept? Y/N" << std::endl;
			cin >> input;
			if (input == "Y")
				room = 8;
			else if (input == "N") {
				system("COLOR 48");
				MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The villagers found you very rude."), MB_OK);
				return 0;
			}
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there awkwardly with the villagers" << std::endl;
			break;
		case 6:
			system("COLOR 2E");
			cout << "You walk towards the small light." << std::endl;
			cout << "The light is a very lovely looking fountain filled with mystical creatures." << std::endl;
			cout << "The creatures seem very interested in you, would you like to Stay or keep heading East?" << std::endl;
			cin >> input;
			if (input == "S") {
				system("COLOR 48");
				MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The creatures were hungry."), MB_OK);
				return 0;
			}
			else if (input == "E")
				room = 11;
			else if (input == "W")
				room = 4;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Please make a decision." << std::endl;
			break;
		case 7:
			system("COLOR 0F");
			cout << "You enter the cave it is dark and cold.\n";
			cout << "There are three different paths North, South, and West.\n";
			cout << "Which way shall you go?\n";
			cin >> input;
			if (input == "N")
				room = 17;
			else if (input == "S")
				room = 14;
			else if (input == "W")
				room = 16;
			else if (input == "E")
				room = 3;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand in the dark and cold. Please choose a path.\n";
			break;
		case 8:
			cout << "The villagers find your kindness very respectable\n";
			cout << "They guide you to a path to what they call Mystical Treasure\n";
			cout << "As you go down their path you see a flower plains to the South.\n";
			cin >> input;
			if (input == "S")
				room = 9;
			else if (input == "N")
				cout << "The villagers don't want you to return they wish for you to keep going on your adventure.\n";
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there aimlessly.\n";
		case 9:
			system("COLOR 2D");
			cout << "You walk into a flower plain, there are many beautiful flowers.\n";
			cout << "To the East there is more fields of flowers with some objects in the distance.\n";
			cin >> input;
			if (input == "E")
				room = 10;
			else if (input == "N")
				cout << "You stop as you go back through the villagers paht, you can't go back now after what they did for you.\n";
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You just stand there.\n";
		}
	} while (input != "q");
}
