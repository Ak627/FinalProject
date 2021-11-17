#include<iostream>
#include<Windows.h>
#include<ctime>
#include<string>
using namespace std;

void Bosses();
void Monsters();
void Shop();
void battle(int BossHealth, char Btype);

int health = 100;
int coins = 10;
int turns = 0;
string Inventory[10] = { "wool shirt","wool pants","animal skin shoes"};

int main() {
	srand(time(NULL));
	int room = 1;
	string input;
	system("title The Lost Adventurer");
	cout << "You wake up and find yourself in a mysterious forest. Can you figure out the way out? Will you find the treasure that is rumoured to be in this forest? Good luck adventurer have fun." << endl;
	cout << "You see an opening through the trees." << endl;
	cout << "(To quit at any point in the game enter q)\n";
	do {
		cout << "Inventory: ";
		for (int i = 0; i < 10; i++)
			cout << Inventory[i] << " | ";
		cout << endl;
		cout << "Health: " << health << endl;
		cout << "Coin Count: " << coins << endl;
		cout << "Turns taken: " << turns << endl;
		cout << "You have " << 50 - turns << " turns left." << endl;
		turns++;
		switch (room) {
		case 1:
			system("COLOR 2F");
			cout << "You enter the opening between the trees you see. You can head North." << endl;
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
			system("COLOR 2F");
			cout << "You head North and find yourself near a pond." << endl;
			cout << "There is a sharpened stick you find on the floor, you have a feeling it might be useful. You pick it up." << endl;
			Inventory[3] = "sharpenedstick";
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
			system("COLOR 2F");
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
			if (Inventory[5] != "small coin") {
				cout << "You pick up a small coin you found on the ground." << endl;
				Inventory[5] = "small coin";
			}
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
			else if (input == "North")
				room = 4;
			else
				cout << "You stand there awkwardly with the villagers" << endl;
			break;
		case 6:
			system("COLOR 2E");
			cout << "You walk towards the small light." << endl;
			cout << "The light is a very lovely looking fountain filled with mystical creatures." << endl;
			cout << "The creatures seem very interested in you, would you like to Stay or keep heading East?" << endl;
			cin >> input;
			if (input.compare("Stay")) {
				if (Inventory[5].compare("small coin") != 0) {
					system("COLOR 48");
					MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The creatures were hungry."), MB_OK);
					return 0;
				}
				else
					room = 23;
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
				cout << "Please make a decision." << endl;
			break;
		case 7:
			system("COLOR 0F");
			cout << "You enter the cave it is dark and cold.\n";
			cout << "There are three different paths North, South, and West.\n";
			cout << "Which way shall you go?\n";
			if(Inventory)
			cin >> input;
			if (input == "North")
				room = 17;
			else if (input == "South")
				room = 14;
			else if (input == "West")
				room = 15;
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
			if (input == "South")
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
			system("COLOR 2F");
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
			system("COLOR 1F");
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
			Monsters();
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
			system("COLOR 0F");
			Monsters();
			cout << "You head West, there is an path North, East, and West." << endl;
			cin >> input;
			if (input == "West")
				room = 16;
			else if (input == "North")
				room = 18;
			else if (input == "East")
				room = 7;
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
		case 16:
			system("COLOR 0F");
			Monsters();
			cout << "You head West, there is an path North, and East." << endl;
			cin >> input;
			if (input == "North")
				room = 19;
			else if (input == "East")
				room = 15;
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
			
		case 17:
			system("COLOR 0F");
			Monsters();
			cout << "You head North, There is a path South and West." << endl;
			cin >> input;
			if (input == "South")
				room = 7;
			else if (input == "West")
				room = 22;
			else
				cout << "It's cold and darl. Nothing happens." << endl;
			break;
		case 18:
			system("COLOR 0F");
			Monsters();
			cout << "You head down another path in the cave, there is an path South, East, and West." << endl;
			cin >> input;
			if (input == "West")
				room = 19;
			else if (input == "South")
				room = 15;
			else if (input == "East")
				room = 17;
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
		case 19:
			system("COLOR 0F");
			Monsters();
			cout << "You head to a corner of the cave, there are paths South and East." << endl;
			cin >> input;
			if (input == "South")
				room = 16;
			else if (input == "East")
				room = 18;
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
		case 20:
			cout << "You have went South, there are so many trees around you only see paths to the East and the North." << endl;
			cin >> input;
			if (input == "East") {
				system("COLOR 48");
				MessageBox(nullptr, TEXT("YOU DIED."), TEXT("You ran through the trees too fast and didn't realize the big crater in the ground."), MB_OK);
				return 0;
			}
			else if (input == "North")
				room = 11;
			else
				cout << "You stand there confused." << endl;
			break;
		case 21:
			cout << "You go towards the light, you are on top of the cave." << endl;
			cout << "You see the source of the light coming from a strange doorway. Would you like to enter? Y/N" << endl;
			cin >> input;
			if (input == "Y") {
				int portal = rand() % 24 + 1;
				room = portal;
				cout << "The portal teleports you to a random location." << endl;
			}
			else if (input == "N")
				room = 14;
			else
				cout << "You stand there mesmerized by the portal." << endl;
			break;
		case 22:
			break;
		case 23:
			system("COLOR 0E");
			cout << "These creatures loved the coin you had an lead you to their secret treasure, a room filled with gold, they tell you that you can take whatever you want." << endl;
			coins += 150;
			cout << "After they lead you over to the village so you can complete your journey." << endl;
			room = 5;
			break;
		case 24:
			system("COLOR 4E");
			cout << "You find yourself in a large space, there is a big red ring with a treasure chest in the middle." << endl;
			cout << "This is it! The rumoured treasure of these forrests!" << endl;
			cout << "But wait its too easy, you hear a noise..." << endl;
			Bosses();
			break;
		}
	} while (input != "q" && turns < 50 && health > 0);
	if (turns == 50) {
		system("COLOR 48");
		MessageBox(nullptr, TEXT("YOU DIED."), TEXT("You starved to death in the harsh wilderness."), MB_OK);
		return 0;
	}
	else if (health == 0) {
		system("COLOR 48");
		MessageBox(nullptr, TEXT("YOU DIED."), TEXT("You were killed!"), MB_OK);
		return 0;
	}
}
void Monsters() {
	int num = rand() % 100 + 1;
	int healthsub = rand() % 20 +1;
	if (num <= 40) {
		cout << "A frail skeleton appears and smacks you!" << endl;
		health -= 10;
		cout << "You get hit for 10 hp." << endl << endl;
	}
	else if (num <= 75) {
		cout << "a zombie appears and bites you at an attempt to eat your brains!" << endl;
		health -= healthsub;
		cout << "You get hit for " << healthsub << " hp." << endl << endl;
	}
	else if (num <= 90) {
		cout << "A group of goblins raid you and steal all your coins!" << endl;
		coins -= coins;
		cout << "You have 0 coins now." << endl << endl;
	}
	else if (num <= 95) {
		cout << "A group of cave fairies give you some coins and heal you by 50 hp." << endl;
		coins += 25;
		health += 50;
		cout << "They wish you good luck on your adventure." << endl << endl;
	}
	else
		cout << "Nothing happens, it's quiet..." << endl << endl;
}
void Shop() {
	cout << "Hello my friend! Welcome to my shop!" << endl;
	string input;
	do {
		cout << "Coins: " << coins << endl;
		cout << "Enter 'p' for a potion for 20 coins, 's' for a sword for 25 coins, 'hc' for heavy chestplate for 30 coins, 'hl' for heavy leggings for 25 coins, 'hb' for heavy boots for 20 coins. To exit the shop press 'q'." << endl;
		cin >> input;
		if (input == "p"  && coins >=20) {
			Inventory[4] = "potion";
			cout << "You got a potion" << endl;
		}
		else if (input == "p" && coins < 20) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "s" && coins >= 25) {
			Inventory[5] = "sword";
			cout << "You got a sword." << endl;
		}
		else if (input == "s" && coins < 25) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hc" && coins >= 30) {
			Inventory[0] = "heavy chestplate";
			cout << "You got a heavy chestplate." << endl;
		}
		else if (input == "hc" && coins < 30) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hl" && coins >= 25) {
			Inventory[1] = "heavy leggings";
			cout << "You got heavy leggings." << endl;
		}
		else if (input == "hl" && coins < 25) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hb" && coins >= 20) {
			Inventory[2] = "heavy boots";
			cout << "You got heavy boots." << endl;
		}
		else if (input == "hb" && coins < 20) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "q")
			cout << "Goodbye my friend, hope to see you again soon!" << endl;
	} while (input != "q");
}

void Bosses() {
	int num = rand() % 100 + 1;
	if (num <= 20) {
		cout << "You encounter the Large Cave Orc gaurding the treasure!" << endl;
		battle(50, 'o');
	}
	else if (num <= 60) {
		cout << "You encounter the Hydra that is the keeper of the treauser!" << endl;
		battle(65, 'h');
	}
	else {
		cout << "The Cyclops of the treasure appears before you!" << endl;
		battle(30, 'c');
	}
}

void battle(int BossHealth, char Btype) {
	int damage;
	string input;
	while (BossHealth > 0 && health > 0) {
		if (Btype == 'h')
			damage = rand() % 31 + 20;
		else if (Btype == 'o')
			damage = rand() % 21 + 20;
		else
			damage = rand() % 16 + 20;
		cout << "The monster hits you for " << damage << " damage" << endl;
		health -= damage;
		cout << "You have " << health << " health left" << endl;
		cout << "Your turn to attack, you can swipe or kick." << endl;
		cin >> input;
		if (Inventory[3] == "shapenedstick")
			damage * .1;
		else if (Inventory[3] == "sword")
			damage * 2;
		if (input == "swipe")
			damage = rand() % 7 + 10;
		else if (input == "kick")
			damage = rand() % 7 + 5;
		cout << "You hit the monster for " << damage << " damage" << endl;
		BossHealth -= damage;
		cout << "The Boss has " << BossHealth << " health." << endl;
	}
	if (BossHealth <= 0) {
		system("COLOR 7F");
		MessageBox(nullptr, TEXT("YOU WON!"), TEXT("You defeated the boss and took it's treasure! Well Done!"), MB_OK);
	}
	else if (health <= 0) {
		system("COLOR 4C");
		MessageBox(nullptr, TEXT("YOU DIED"), TEXT("The Boss wasn't planning on giving up it's treasure"), MB_OK);
	}
}
