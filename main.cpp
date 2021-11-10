#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;

void Monsters();
void Shop();
int health = 100;
int coins = 0;
string Inventory[10] = { "wool shirt","wool pants","animal skin shoes","sharpened stick" };

int main() {
	int room = 1;
	string input;
	system("title The Lost Adventurer");
	cout << "You wake up and find yourself in a mysterious forest. Can you figure out the way out? Will you find the treasure that is rumoured to be in this forest? Good luck adventurer have fun." <<  endl;
	cout << "You see an opening through the trees." <<  endl;
	cout << "(To quit at any point in the game enter q)\n";
	do {
		cout << "Inventory: ";
		for (int i = 0; i < 10; i++)
			cout << Inventory[i] << " | ";
		cout << endl;
		cout << "Health: " << health << endl;
		cout << "Coin Count: " << coins << endl;
		switch (room) {
		case 1:
			system("COLOR 2B");
			cout << "You enter the opening you see. You can head North." <<  endl;
			cin >> input;
			if (input == "North")
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				 cout << "trees block the path this way" << endl;
			break;
		case 2:
			system("COLOR 2B");
			cout << "You head North and find yourself near a pond." << endl;
			cout << "There is a path to the West as well as a hike to the East." << endl;
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
				cout << "trees block the path this way" << endl;
			break;
		case 3:
			system("COLOR 2B");
			cout << "You go down the path to the West." << endl;
			cout << "There is a large cave in Front of you." << endl;
			cout << "Would you like to enter? Y/N" << endl;
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
				cout << "You stand there aimlessly. You must make a decision" << endl;
			break;
		case 4:
			system("COLOR 0B");
			cout << "You head East and hike up a small mountain that goes above the tree tops." << endl;
			cout << "While standing on the mountain you see village further South as well as a light more to the East." << endl;
			cin >> input;
			if (input == "South")
				room = 5;
			else if (input == "East")
				room = 6;
			else if (input == "West")
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there wihout any thoughts, please choose a path." << endl;
			break;
		case 5:
			system("COLOR 1E");
			cout << "You head for the village." << endl;
			cout << "Upon arrvial you meet the villagers." << endl;
			cout << "They offer you shelter and food. Do you accept? Y/N" << endl;
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
				cout << "You stand there awkwardly with the villagers" <<  endl;
			break;
		case 6:
			system("COLOR 2E");
			cout << "You walk towards the small light." <<  endl;
			cout << "The light is a very lovely looking fountain filled with mystical creatures." <<  endl;
			cout << "The creatures seem very interested in you, would you like to Stay or keep heading East?" <<  endl;
			cin >> input;
			if (input == "Stay") {
					system("COLOR 48");
					MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The creatures were hungry."), MB_OK);
					return 0;
			}
			else if (input == "East")
				room = 11;
			else if (input == "West")
				room = 4;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Please make a decision." <<  endl;
			break;
		case 7:
			system("COLOR 0F");
			cout << "You enter the cave it is dark and cold.\n";
			cout << "There are three different paths North, South, and West.\n";
			cout << "Which way shall you go?\n";
			cin >> input;
			if (input == "North")
				room = 17;
			else if (input == "South")
				room = 14;
			else if (input == "West")
				room = 16;
			else if (input == "East")
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
			if (input == "South")
				room = 9;
			else if (input == "North")
				cout << "The villagers don't want you to return they wish for you to keep going on your adventure.\n";
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You stand there aimlessly.\n";
			break;
		case 9:
			system("COLOR 2D");
			cout << "You walk into a flower plain, there are many beautiful flowers.\n";
			cout << "To the East there is more fields of flowers with some objects in the distance.\n";
			cin >> input;
			if (input == "East")
				room = 10;
			else if (input == "North")
				cout << "You stop as you go back through the villagers paht, you can't go back now after what they did for you.\n";
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You just stand there.\n";
			break;
		case 10:
			system("COLOR 2D");
			cout << "You walk further into the flower plains and see a path South,West, and more East.\n";
			cin >> input;
			if (input == "South ")
				room = 24;
			else if (input == "East")
				room = 12;
			else if (input == "West")
				room = 9;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Nothing happens.\n";
			break;
		case 11:
			system("COLOR 2C");
			cout << "You move past the fountain, there is a path South and West.\n";
			cin >> input;
			if (input == "South")
				room = 20;
			else if (input == "West")
				room = 6;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Nothing happens.\n";
			break;
		case 12:
			system("COLOR 2B");
			cout << "You walk up to a docks, there is a bridge that goes further East, and a path back West.\n";
			cin >> input;
			if (input == "East")
				room = 13;
			else if (input == "West")
				room = 10;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Nothing happens\n";
			break;
		case 13:
			system("COLOR 18");
			cout << "You walk across the docks and find yourself at a small shop.\n";
			cout << "Would you like to enter Y/N?\n";
			cin >> input;
			if (input == "Y")
				Shop();
			else if (input == "N")
				room = 12;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "Nothing happens.\n";
			break;
		case 14:
			system("COLOR 0F");
			cout << "You go South, there is an opening to the West and a path back North.\n";
			cout << "A strange light seeps through from the West.\n";
			cin >> input;
			if (input == "West")
				room = 21;
			else if (input == "North")
				room = 7;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		}
	} while (input != "q");
}
void Monsters() {
	int num = rand() % 100 + 1;
	if (num <= 20)
		cout << "A skeleton appears!" << endl << endl;
	else if (num <= 50)
		cout << "a zombie appears!" << endl << endl;
	else if (num <= 90)
		cout << "A group of goblins raid you!" << endl << endl;
	else
		cout << "Nothing happens, it's quiet..." << endl << endl;
}
void Shop() {

	string input;
	do {
		cout << "Hello! Welcome to my shop!" << endl;
		cout << "Press 'p' for a potion, 's' for a sword, and 'm' for magic wand. To exit the shop press 'q'." << endl;
		cin >> input;
		if (input == "p") {
			Inventory[4] = "potion";
			cout << "You got a potion" << endl;
		}
		else if (input == "s") {
			Inventory[5] = "sword";
			cout << "You got a sword." << endl;
		}
		else if (input == "m") {
			Inventory[6] = "magic wand";
			cout << "You got a magic wand." << endl;
		}
		else if (input == "q")
			cout << "Goodbye hope to see you again soon!" << endl;
	} while (input != "q");
}
