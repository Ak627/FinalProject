#include<iostream>
#include<Windows.h>
#include<ctime>
#include<string>
using namespace std;

//function declarations
void Bosses();
void Monsters();
void Shop();
void battle(int BossHealth, char Btype);
void NPC(int ctype);
//variable declarations
int health = 100;
int coins = 10;
int turns = 0;
//inventory set up
string Inventory[10] = { "wool shirt","wool pants","animal skin shoes"};
//main game loop 
int main() {
	srand(time(NULL));
	//starting point and local variables
	int room = 1;
	int num;
	string input;
	system("title The Lost Adventurer");
	cout << "You wake up and find yourself in a mysterious forest. Can you figure out the way out? Will you find the treasure that is rumoured to be in this forest? Good luck adventurer have fun." << endl;
	cout << "You see an opening through the trees." << endl;
	cout << "(To quit at any point in the game enter q)\n";
	do {//game loop start
		num = rand() % 4 + 1;//random number generator
		cout << "Inventory: ";
		for (int i = 0; i < 10; i++)//for loop that prints out inventory slots
			cout << Inventory[i] << " | ";
		cout << endl;
		cout << "Health: " << health << endl;//health counter
		cout << "Coin Count: " << coins << endl;//coin counter
		cout << "Turns taken: " << turns << endl;//turns counter
		cout << "You have " << 50 - turns << " turns left." << endl;//subtracts from turn variable
		turns++;
		switch (room) {
		case 1:
			system("COLOR 2F");//changes color of gamescreen and text
			cout << "You enter the opening between the trees you see. You can head North." << endl;
			cin >> input;
			if (input == "North")//if choices that indicate choice from user input
				room = 2;
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);//adds a text box on the screen that indicates you quit from the game
				return 0;//stops the code from running
			}
			else
				cout << "trees block the path this way" << endl;
			break;
		case 2:
			system("COLOR 2F");
			cout << "You head North and find yourself near a pond." << endl;
			cout << "There is a path to the West as well as a hike to the East." << endl;
			if (Inventory[3] != "sharpenedstick") {//checks inventory slots to see if you have a certain item and prints out a statement if item is not present
				cout << "There is a sharpened stick you find on the floor, you have a feeling it might be useful. You pick it up." << endl;
				Inventory[3] = "sharpenedstick";//adds this item to your inventory slot
			}
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
			if (input == "Stay") {
				if (Inventory[5].compare("small coin") != 0) {//if you don't have this item you die or lose game
					system("COLOR 48");
					MessageBox(nullptr, TEXT("YOU DIED."), TEXT("The creatures were hungry and didn't want their meal leaving."), MB_OK);
					return 0;
				}
				else
					room = 22;//if you have this item you will be taken to another room
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
			cout << "You enter the cave it is very cold with little to no visibility.\n";
			cout << "There are three different visbile paths North, South, and West. You can also exit outside of the cave going East.\n";
			cout << "Which way shall you go?\n";
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
			system("COLOR 1E");
			cout << "The villagers find your kindness very honorable\n";
			cout << "They guide you to a path to what they call Mystical Treasure. But they warn yuou of creatures you may possibly encounter.\n";
			cout << "As you go down their path you see a beautiful flower plains with the sun accenting it with an elegant golden glow to the South.\n";
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
			cout << "You walk into a flower plain, there are many beautiful and vibrant flowers.\n";
			cout << "Each different shades of golden yellow, hot pink, beautiful lavender, and even ocean blue flowers.\n";
			NPC(num);//NPC call with the random number generator as the argument to randomly call a different NPC
			cout << "To the East there is more fields of these vibrant flowers with some faint objects in the distance.\n";
			cin >> input;
			if (input == "East")
				room = 10;
			else if (input == "North")
				cout << "You stop as you go back through the villagers path, you can't go back now after what they did for you.\n";
			else if (input == "q") {
				MessageBox(nullptr, TEXT("YOU QUIT."), TEXT("Thanks for playing."), MB_OK);
				return 0;
			}
			else
				cout << "You just stand there.\n";
			break;
		case 10:
			system("COLOR 2D");
			cout << "You walk further into the flower plains with many more beautiful and vibrant flowers." << endl;
			NPC(num);
			cout << "You see a path South, West, and further East.\n";
			cin >> input;
			if (input == "South") {
				if (Inventory[3].compare("sword") != 0) {
					cout << "You think about entering this area but you feel a presence you have never felt before." << endl;
					cout << "You feel it should be better to grab a weapon, like a sword, to continue your quest." << endl;
				}
				else
					room = 23;
			}
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
			cout << "You move past the fountain into the thick forest ahead, there is a small open path South and the fountain back West.\n";
			if (Inventory[6] != "magickey") {
				cout << "You see a Magical looking Key on the floor, you decide it might be a good idea to pick it up." << endl << endl;
				Inventory[6] = "magickey";
			}
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
			system("COLOR 2F");
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
			if (input == "Y")//type in a certain letter, phrase, or number to enter the shop function
				Shop();//shop function call based on user input
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
			Monsters();//monster function called when you enter certain rooms
			cout << "You go to another path in the cave, there is an opening outside to the West and a path back North.\n";
			cout << "A strange purple light seeps through from the West.\n";
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
			cout << "You head down another cold path, it's almost like you are in a maze, there is an path North, East, and West." << endl;
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
			cout << "You head down another path in the cave, there is an path North, and East." << endl;
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
			cout << "You head towards a darker path of the cave, There are open paths South and West." << endl;
			cin >> input;
			if (input == "South")
				room = 7;
			else if (input == "West")
				room = 18;
			else
				cout << "It's cold and dark. Nothing happens." << endl;
			break;
		case 18:
			system("COLOR 0F");
			Monsters();
			cout << "You head down another eerie path in the cave, there are different paths South, East, and West." << endl;
			cin >> input;
			if (input == "West")
				room = 19;
			else if (input == "South")
				room = 15;
			else if (input == "East")
				room = 17;
			else
				cout << "It's cold and dark, nothing happens." << endl;
			break;
		case 19:
			system("COLOR 0F");
			Monsters();
			cout << "You head to a corner of the cave, there are paths South and East." << endl;
			if (Inventory[5] != "small coin") {
				cout << "You pick up a small coin you found on the ground." << endl;
				Inventory[5] = "small coin";
			}
			cin >> input;
			if (input == "South")
				room = 16;
			else if (input == "East")
				room = 18;
			else
				cout << "It's cold and dark, nothing happens.\n";
			break;
		case 20:
			cout << "You have went South, there are many many trees blocking paths around you." << endl;
			NPC(num);
			cout << "The only paths you see are East and North." << endl;
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
			cout << "You see the source of the bright purple light coming from a strange doorway. Would you like to enter? Y/N" << endl;
			cin >> input;
			if (input == "Y") {
				if (Inventory[6].compare("magickey") != 0) {
					cout << "The portal won't let you through, it looks like you need a key to get it started." << endl;
					cout << "You see there is a small key like hole on the portal." << endl;
					room = 14;
				}
				else {
					int portal = rand() % 24 + 1;
					room = portal;
					cout << "The portal teleports you to a random location." << endl;
				}
			}
			else if (input == "N")
				room = 14;
			else
				cout << "You stand there mesmerized by the portal." << endl;
			break;
		case 22:
			system("COLOR 0E");
			cout << "These creatures loved the coin you had an lead you to their secret treasure, a room filled with gold, they tell you that you can take whatever you want." << endl;
			coins += 150;//adds more values to your money variable
			cout << "You can Stay longer if you would like or you could Leave with the creatures." << endl;
			cin >> input;
			if (input == "Stay") {
				cout << "You stay a little longer but the creatures decide it's time for you to go." << endl;
				room = 5;
			}
			else if (input == "Leave") {
				cout << "When you're done in the room the creatures lead you over to the village so you can complete your journey." << endl;
				room = 5;
			}
			break;
		case 23:
			system("COLOR 4E");
			cout << "You find yourself in a large space, there is a big red ring with a glowing gold treasure chest in the middle." << endl;
			cout << "This is finally it! The rumoured treasure of these forests!" << endl;
			cout << "But wait its too easy, you hear a noise and feel a rumble beneath your feet..." << endl << endl;
			Bosses();//calls the function for bosses
			room = 24;
			break;
		case 24:
			system("COLOR 70");
			cout << "     ____________" << endl;//ASCII art for the treasure chest you win at the end of the game
			cout <<"    / \\____;; ___\\" << endl;
			cout << "   | /         /" << endl;
			cout << "   `. ())oo() ." << endl;
			cout << "   |\\(%()*^^()^\\" << endl;
			cout << "   | |-% ------ |" << endl;
			cout << "   \\ | %))      |" << endl;
			cout << "    \\| % ______ |" << endl;
			cout << "The Lost Treasure of Ascana" << endl;
			MessageBox(nullptr, TEXT("YOU WON!"), TEXT("You defeated the boss and took it's treasure! Well Done!"), MB_OK);//a text box that's printed out to the screen to tell the user they won the game
			return 0;//stops code running
		}
	} while (input != "q" && turns < 50 && health > 0);//ends game loop based on user input and/or variable numbers
	if (turns == 50) {//if statments that print out a losing condition based on how you lose(running out of turns, losing all health)
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
//function definitions
void Monsters() {
	int num = rand() % 100 + 1;//random number generator to generate random monsters
	int healthsub = rand() % 20 +1;//random number generator to generate random damage
	if (num <= 40) {//if statements that will generate a monster bsaed on the number that is randomly generated
		cout << "A frail skeleton appears and smacks you!" << endl;
		health -= 10;//subtracts 10 health points from health variable
		cout << "You get hit for 10 hp." << endl << endl;
	}
	else if (num <= 75) {
		cout << "a zombie appears and bites you at an attempt to eat your brains!" << endl;
		health -= healthsub;//subtracts health based on the random number generated
		cout << "You get hit for " << healthsub << " hp." << endl << endl;
	}
	else if (num <= 90) {
		cout << "A group of goblins raid you and steal all your coins!" << endl;
		coins -= coins;
		cout << "You have 0 coins now." << endl << endl;
	}
	else if (num <= 95) {
		cout << "A group of cave fairies give you some coins and heal you by 50 hp." << endl;
		coins += 25;//adds 25 coins to the coin count
		health += 50;//adds 50 health points to health
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
		cin >> input;//input that takes in input to buy items form shop
		if (input == "p"  && coins >=20) {//checks to see if user has a sufficient amount of money to buy this item
			Inventory[4] = "potion";//if money is sufficient the user will get an item in their inventory array
			cout << "You got a potion" << endl;
			coins -= 20;//subtracts 20 coins from coin count
		}
		else if (input == "p" && coins < 20) {//if money is insufficient user will be told they cannot buy this item and will need to get more coins
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "s" && coins >= 25) {
			Inventory[3] = "sword";
			cout << "You got a sword." << endl;
			coins -= 25;
		}
		else if (input == "s" && coins < 25) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hc" && coins >= 30) {
			Inventory[0] = "heavy chestplate";
			cout << "You got a heavy chestplate." << endl;
			coins -= 30;
			health += 15;
		}
		else if (input == "hc" && coins < 30) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hl" && coins >= 25) {
			Inventory[1] = "heavy leggings";
			cout << "You got heavy leggings." << endl;
			coins -= 25;
			health += 10;
		}
		else if (input == "hl" && coins < 25) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "hb" && coins >= 20) {
			Inventory[2] = "heavy boots";
			cout << "You got heavy boots." << endl;
			coins -= 20;
			health += 5;
		}
		else if (input == "hb" && coins < 20) {
			cout << "I'm sorry my friend you don't have enough money." << endl;
		}
		else if (input == "q")
			cout << "Goodbye my friend, hope to see you again soon!" << endl;
	} while (input != "q");
}

void Bosses() {
	int num = rand() % 100 + 1;//random number like the monster generator to randomly generate a boss
	if (num <= 20) {
		cout << "You encounter the Large Cave Orc gaurding the treasure!" << endl;
		battle(75, 'o');//arguments for the battle system(health and boss type)
	}
	else if (num <= 60) {
		cout << "You encounter the Hydra that is the keeper of the treauser!" << endl;
		battle(110, 'h');
	}
	else {
		cout << "The Cyclops of the treasure appears before you!" << endl;
		battle(60, 'c');
	}
}

void battle(int BossHealth, char Btype) {
	int damage = 10;//damage variable for player
	int monsterdamage;//damage variable for boss/monster
	string input;//input for battle choice
	while (BossHealth > 0 && health > 0) {
		if (Btype == 'h')//based on monster type there will be different damages to the player
			monsterdamage = rand() % 31 + 20;//random number generator for boss damage
		else if (Btype == 'o')
			monsterdamage = rand() % 21 + 20;
		else
			monsterdamage = rand() % 16 + 20;
		cout << "The monster hits you for " << monsterdamage << " damage" << endl;
		health -= monsterdamage;//subtracts health based on monster damage generated 
		cout << "You have " << health << " health left" << endl;//tells user how much damage they got hit by
		cout << "Your turn to attack, you can swipe or kick the big creature, you can also heal with any available potion(p)." << endl;
		if (Inventory[3] == "shapenedstick")//damage multiplier based on what item the user has
			damage += 2;
		else if (Inventory[3] == "sword")
			damage * 5;
		cin >> input;
		if (input == "swipe") {//input thast damages the enemy based on what you type in
			damage += rand() % 15 + 10;//random number generator for the damage inflicted on the boss/enemy npc
			cout << "You hit the monster for " << damage << " damage" << endl;
			BossHealth -= damage;//damage that subracts from the monsters health
			cout << "The Boss has " << BossHealth << " health." << endl;
		}
		else if (input == "kick") {
			damage += rand() % 12 + 5;
			cout << "You hit the monster for " << damage << " damage" << endl;
			BossHealth -= damage;//damage that subracts from the monsters health
			cout << "The Boss has " << BossHealth << " health." << endl;
		}
		else if (input == "p")
			health += 15;
		else
			cout << "You missed your shot now you're gonna get hit." << endl;
	}
	if (health <= 0) {//ends the loop if you run out of health
		system("COLOR 4C");
		MessageBox(nullptr, TEXT("YOU DIED"), TEXT("The Boss wasn't planning on giving up it's treasure"), MB_OK);
	}
}
void NPC(int ctype) {//npc generator
	switch (ctype) {//chooses cases based on the argument called in main for the parameters
	case 1://cases like rooms for int main that print out a certain NPC
		cout << "A very small dwarf like man walks out from behind a little hiding spot to say hi, he is very polite." << endl;
		cout << "He gives you 5 coins for you to use on your adventure." << endl << endl;
		coins += 5;//Adds 5 coins to your coin count
		break;
	case 2:
		cout << "A fairy flies towards you and wants to give you some health(+10 hp)." << endl << endl;
		health += 10;//Adds 10 health points to the health
		break;
	case 3:
		cout << "A really annoying elf keeps following you around, you decide to push him away, he hits you as a result (-10 hp)." << endl << endl;
		health -= 10;//Subtracts 10 health points from health
		break;
	case 4:
		cout << endl;
		break;
	}
}
