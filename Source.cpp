#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<random>
#include<ctime>
#include<Windows.h>

using namespace std;

/*
I need:
10 rooms: check								:)	
A way to win and lose: not yet				:(
Vividly written description: Yes so far		:)...
Strings for input: Yes						:)
Inventory of at least 5 items: yes			:)
Inventory in a string array: Yes			:)
Two non trivial functions: 0 so far			:(
Comments: Not nearly enough					:(
sounds and colors: not yet					:(
ASCII art: Oh god, no.						:(
A well draw paper map: Well drawn? well...	:(...
Back story: Not yet							:(
2-3 Concept art: Not yet					:(
good white space: Yes						:)
*/

bool inventoryDisplay[10] = { 0,0,0,0,0,0,0,0,0,0 };
string inventory[10];
/*Things to go in the inventory: 
1. Money(random amount?)
2. Lighter
3. Wood(useless)
4. A toy(useless)
5. Kitchen knife(probably kill monster)
6. Pocket knife(be lucky to kill the monster)
7. Spear(almost definitely kill the monster)
8. Flashlight(better for stairs/second floor)
9. Batteries
10.Makeshift chest armor(increase likelyhood of a w)*/
enum INVENTORY {MONEY, LIGHTER, WOOD, TOY, KITCHEN, POCKET, SPEAR, FLASHLIGHT, BATTERIES, CHESTPLATE};
int health = 100;

void thingsInAllRooms(string input);
bool bossFight(string input);
int betterRand();
void topBar();

int main() {
	srand(time(NULL));
	int burnTime;
	bool burning = 0;
	int floor = 1;
	int room = 1;
	bool amIStillHere[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	bool haveIBeenHere[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	string input;
	cout << "						THE TOWNHOUSE\n\n";
	cout << "        `'::.\n";
	cout << "    _________H ,%%&%,\n";
	cout << "   /\\     _   \\%&&%%&%\n";
	cout << "  /  \\___/^\\___\\%&%%&&\n";
	cout << "  |  | []   [] |%\\Y&%'\n";
	cout << "  |  |   .-.   | ||\n";
	cout << "~~@._|@@_|||_@@|~||~~~~~~~~~~~~~\n";
	cout << "     `\"\"\") )\"\"\"`\n";
	system("PAUSE>nul");
	system("cls");
	while (input != "q" && health > 0) {
		//PlaySoundA((LPCSTR)"boom.WAV", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySoundA((LPCSTR)"Waterphone.WAV", NULL, SND_FILENAME | SND_ASYNC);
		topBar();
		if (floor == 1) { //main floor
			switch (room) {
			default:
				cout << "I seem to have messed up, you're not in a room.\n";
			case 1:
				if (amIStillHere[0] == 0) {
					cout << "You've arrived, before you sits a dilapidated town house.\n";
					system("timeout /t 3 >nul");
					cout << "A deep sense of dread fills you, and you feel as though you should not be here.\n";
					system("timeout /t 3 >nul");
					cout << "Before you is the front door, you contemplate entering, or running.\n";
					amIStillHere[0] = 1;
				}
				else {
					cout << "You've arrived, before you sits a dilapidated town house.\n";
					cout << "A deep sense of dread fills you, and you feel as though you should not be here.\n";
					cout << "Before you is the front door, you contemplate entering, or running.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("door") == 0 || input.compare("enter door") == 0 || input.compare("front door") == 0 || input.compare("enter front door") == 0 || input.compare("d") == 0 || input.compare("enter") == 0) {
					room = 2;
					haveIBeenHere[0] = 1;
				}
				else if (input.compare("run") == 0 || input.compare("run away") == 0 || input.compare("away") == 0 || input.compare("r") == 0) {
					input = "q";
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 2:
				if (haveIBeenHere[1] == 0) {
					if (amIStillHere[1] == 0) {
						cout << "You enter the house, and a cold wave washes over you.\n";
						system("timeout /t 3 >nul");
						cout << "The door slams behind you; you jump.\n";
						system("timeout /t 3 >nul");
						cout << "You're standing in the foyer, every visible inch is dirty.\n";
						system("timeout /t 3 >nul");
						cout << "Next to you, hanging on the wall, is a coat that looks like it hasn't been touched in 10 years.\n";
						system("timeout /t 3 >nul");
						cout << "In front of you is a staircase leading upstairs that seems to extend into an impossibly infinite darkness.\n";
						system("timeout /t 3 >nul");
						cout << "To your right is a hallway, filthy, and dimly lit.\n";
						amIStillHere[1] = 1;
					}
					else {
						cout << "You enter the house, and a cold wave washes over you.\n";
						cout << "The door slams behind you; you jump.\n";
						cout << "You're standing in the foyer, every visible inch is dirty.\n";
						cout << "Next to you, hanging on the wall, is a coat that looks like it hasn't been touched in 10 years.\n";
						cout << "In front of you is a staircase leading upstairs that seems to extend into an impossibly infinite darkness.\n";
						cout << "To your right is a hallway, filthy, and dimly lit.\n";
					}
				}
				else {
					cout << "You're back in the foyer on the first floor.\n";
					cout << "Next to you, hanging on the wall, is a coat that looks like it hasn't been touched in 10 years.\n";
					cout << "In front of you is a staircase leading upstairs that seems to extend into an impossibly infinite darkness.\n";
					cout << "To your right is a hallway, filthy, and dimly lit.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("stairs") == 0 || input.compare("go up the stairs") == 0 || input.compare("staircase") == 0 || input.compare("walk up the stairs") == 0 || input.compare("s") == 0 || input.compare("take the stairs") == 0) {
					if (inventory[0] == "Burning Money" || (inventory[FLASHLIGHT] == "Flashlight" && inventory[BATTERIES] == "Batteries"))
						room = 9;
					else {
						system("cls");
						topBar();
						cout << "You begin the ascent up the endless stairs.\n";
						system("timeout /t 3 >nul");
						cout << "The darkness begins to envelope you, and an uncontrollable fear tightens around you.\n";
						system("timeout /t 3 >nul");
						cout << "The fear peaks, and you instinctively dash back down the stairs.\n";
						system("timeout /t 3 >nul");
						cout << "Perhaps if it wasn't so dark...\n";
						system("PAUSE>nul");
					}
				}
				else if (input.compare("hallway") == 0 || input.compare("hall") == 0 || input.compare("enter the hall") == 0 || input.compare("h") == 0) {
					room = 3;
					haveIBeenHere[1] = 1;
				}
				else if (input.compare("check coat") == 0 || input.compare("examine coat") == 0 || input.compare("coat") == 0 || input.compare("c") == 0 || input.compare("inspect coat") == 0) {
					system("cls");
					topBar();
					if (inventoryDisplay[MONEY] == 0) {
						int random = betterRand();
						cout << "You examine the coat, searching it's pockets. In one, you find";
						//bill type
						if (random > 95) {
							cout << " two 100 dollar bills.\n";
							burnTime = 2;
						}
						else if (random > 85) {
							cout << " four 50 dollar bills.\n";
							burnTime = 4;
						}
						else if (random > 70) {
							cout << " ten 10 dollar bills.\n";
							burnTime = 10;
						}
						else if (random > 40) {
							cout << " thirty 10 dollar bills.\n";
							burnTime = 30;
						}
						else if (random > 0) {
							cout << " sixty 1 dollar bills.\n";
							burnTime = 60;
						}
						inventory[MONEY] = "Money";
						inventoryDisplay[MONEY] = 1;
					}
					else {
						cout << "You've already examined this coat, you had found";
						if (burnTime == 2) {
							cout << " two 100 dollar bills.\n";
						}
						else if (burnTime == 4) {
							cout << " four 50 dollar bills.\n";
						}
						else if (burnTime == 10) {
							cout << " ten 10 dollar bills.\n";
						}
						else if (burnTime == 30) {
							cout << " thirty 10 dollar bills.\n";
						}
						else if (burnTime == 60) {
							cout << " sixty 1 dollar bills.\n";
						}
					}
					system("PAUSE>nul");
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 3:
				if (amIStillHere[2] == 0) {
					cout << "You walk into the hallway. Around a left bend,\n";
					system("timeout /t 3 >nul");
					cout << "you see before you what could only be a living room,\n";
					system("timeout /t 3 >nul");
					cout << "though a sad one at that, and quite dark.\n";
					amIStillHere[2] = 1;
				}
				else {
					cout << "You walk into the hallway. Around a left bend,\n";
					cout << "you see before you what could only be a living room,\n";
					cout << "though a sad one at that, and quite dark.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("living room") == 0 || input.compare("livingroom") == 0 || input.compare("forward") == 0 || input.compare("walk forward") == 0 || input.compare("l") == 0 || input.compare("go forward") == 0) {
					room = 4;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("foyer") == 0 || input.compare("b") == 0) {
					room = 2;
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 4:
				if (amIStillHere[3] == 0) {
					cout << "You're in the first half of the living room. It's dark,\n";
					system("timeout /t 3 >nul");
					cout << "and all you can see is a tv with it's face smashed in,\n";
					system("timeout /t 3 >nul");
					cout << "and a disheveled couch that fades into the darkness.\n";
					system("timeout /t 3 >nul");
					cout << "The hallway back towards the entrance is behind you,\n";
					system("timeout /t 3 >nul");
					cout << "with the rest of the living room lurking in the darkness before you.\n";
					amIStillHere[3] = 1;
				}
				else {
					cout << "You're in the first half of the living room. It's dark,\n";
					cout << "and all you can see is a tv with it's face smashed in,\n";
					cout << "and a disheveled couch that fades into the darkness.\n";
					cout << "The hallway back towards the entrance is behind you,\n";
					cout << "with the rest of the living room lurking in the darkness before you.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("living room") == 0 || input.compare("livingroom") == 0 || input.compare("forward") == 0 || input.compare("walk forward") == 0 || input.compare("l") == 0 || input.compare("go forward") == 0 || input.compare("f") == 0) {
					room = 5;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("hallway") == 0 || input.compare("b") == 0 || input.compare("h") == 0 || input.compare("hall") == 0) {
					room = 3;
				}
				else if (input.compare("check tv") == 0 || input.compare("examine tv") == 0 || input.compare("tv") == 0 || input.compare("t") == 0 || input.compare("inspect tv") == 0) {
					system("cls");
					topBar();
					if (inventoryDisplay[FLASHLIGHT] == 0) {
						cout << "You walk over to the the shattered tv, which is sitting on a tv stand a remote next to it.\n";
						system("timeout /t 3 >nul");
						cout << "You peer around it, and decide to reach into the broken screen.\n";
						system("timeout /t 3 >nul");
						cout << "You feel a solid metal object. A flashlight! It doesn't have any batteries.\n";
						inventory[FLASHLIGHT] = "Flashlight";
						inventoryDisplay[FLASHLIGHT] = 1;
					}
					else {
						cout << "You already looked in the tv, you had found a flashlight without batteries.\n";
					}
					system("PAUSE>nul");
				}
				else if (input.compare("check remote") == 0 || input.compare("examine remote") == 0 || input.compare("remote") == 0 || input.compare("r") == 0 || input.compare("inspect remote") == 0) {
					system("cls");
					topBar();
					if (inventoryDisplay[BATTERIES] == 0) {
						cout << "You pick up the remote next to the broken tv. It has weight to it.\n";
						system("timeout /t 3 >nul");
						cout << "You take off the back. Batteries. You test them in the flashlight.\n";
						system("timeout /t 3 >nul");
						cout << "Success! Your flashlight works, though for how long you don't know.\n";
						inventory[BATTERIES] = "BATTERIES";
						inventoryDisplay[BATTERIES] = 1;
					}
					else {
						cout << "You already looked in the remote, you had found a batteries for your flashlight.\n";
					}
					system("PAUSE>nul");
				}
				else if (input.compare("check couch") == 0 || input.compare("examine couch") == 0 || input.compare("couch") == 0 || input.compare("c") == 0 || input.compare("inspect couch") == 0) {
					system("cls");
					topBar();
					cout << "You couldn't find anthing in the couch. With how torn it is,\n";
					system("timeout /t 1 >nul");
					cout << "perhaps it was searched already. Not by anything human though.\n";
					system("PAUSE>nul");
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 5:
				if (haveIBeenHere[4] == 0) {
					if (amIStillHere[4] == 0) {
						cout << "You walk into the other portion of the living room.\n";
						system("timeout /t 3 >nul");
						cout << "Out of the darkness, an armchair appears in the far right corner of the room.\n";
						system("timeout /t 3 >nul");
						cout << "It looks relatively untouched in comparison to the couch.\n";
						system("timeout /t 3 >nul");
						cout << "To your left is another hallway, somehow looking less inviting than the last one.\n";
						system("timeout /t 3 >nul");
						cout << "In front of you is an archway leading into a large looking dining room.\n";
						amIStillHere[4] = 1;
					}
					else {
						cout << "You walk into the other portion of the living room.\n";
						cout << "Out of the darkness, an armchair appears in the far right corner of the room.\n";
						cout << "It looks relatively untouched in comparison to the couch.\n";
						cout << "To your left is another hallway, somehow looking less inviting than the last one.\n";
						cout << "In front of you is an archway leading into a large looking dining room.\n";

					}
				}
				else {
					if (amIStillHere[4] == 0) {
						cout << "You walk into the second half of the living room.\n";
						system("timeout /t 3 >nul");
						cout << "An armchair is in the far right corner of the room.\n";
						system("timeout /t 3 >nul");
						cout << "It looks relatively untouched in comparison to the couch.\n";
						system("timeout /t 3 >nul");
						cout << "To your left is another hallway, and in front of you\n";
						system("timeout /t 3 >nul");
						cout << "is an archway leading into the dining room and kitchen.\n";
						amIStillHere[4] = 1;
					}
					else {
						cout << "You walk into the second half of the living room.\n";
						cout << "An armchair is in the far right corner of the room.\n";
						cout << "It looks relatively untouched in comparison to the couch.\n";
						cout << "To your left is another hallway, and in front of you\n";
						cout << "is an archway leading into the dining room and kitchen.\n";
					}
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("dining room") == 0 || input.compare("diningroom") == 0 || input.compare("forward") == 0 || input.compare("walk forward") == 0 || input.compare("d") == 0 || input.compare("go forward") == 0) {
					room = 6;
					haveIBeenHere[4] = 1;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("living room") == 0 || input.compare("b") == 0) {
					room = 4;
				}
				else if (input.compare("check armchair") == 0 || input.compare("examine armchair") == 0 || input.compare("armchair") == 0 || input.compare("c") == 0 || input.compare("inspect armchair") == 0 || input.compare("chair") == 0) {
					system("cls");
					topBar();
					if (inventoryDisplay[LIGHTER] == 0) {
						cout << "You walk over to the armchair, which is a dark red.\n";
						system("timeout /t 3 >nul");
						cout << "You check it carefully, looking under it,\n";
						system("timeout /t 3 >nul");
						cout << "and under the cusions. Under the cusions you find some lose change,\n";
						system("timeout /t 3 >nul");
						cout << "and a lighter with so little fluid in it, you'll only get seconds of flame.\n";
						inventory[LIGHTER] = "Lighter";
						inventoryDisplay[LIGHTER] = 1;
					}
					else {
						cout << "You already checked out the chair, you had found a lighter with almost no fluid.\n";
					}
					system("PAUSE>nul");
				}
				else if (input.compare("hallway") == 0 || input.compare("hall") == 0 || input.compare("enter the hall") == 0 || input.compare("h") == 0) {
					room = 8;
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 6:
				if (haveIBeenHere[5] == 0) {
					if (amIStillHere[5] == 0) {
						cout << "You walk into the large looking dining room.\n";
						system("timeout /t 3 >nul");
						cout << "As you pass through the arch, you see that the dining room\n";
						system("timeout /t 3 >nul");
						cout << "is in fact not that large, but is instead adjacent to the kitchen,\n";
						system("timeout /t 3 >nul");
						cout << "seperated by a peninsula, and an island.\n";
						system("timeout /t 3 >nul");
						cout << "In the center of the dining room, is a table that's been cracked in half,\n";
						system("timeout /t 3 >nul");
						cout << "and in the right corner, is a keyboard with all it's keys missing.\n";
						amIStillHere[5] = 1;
					}
					else {
						cout << "You walk into the large looking dining room.\n";
						cout << "As you pass through the arch, you see that the dining room\n";
						cout << "is in fact not that large, but is instead adjacent to the kitchen,\n";
						cout << "seperated by a peninsula, and an island.\n";
						cout << "In the center of the dining room, is a table that's been cracked in half,\n";
						cout << "and in the right corner, is a keyboard with all it's keys missing.\n";

					}
				}
				else {
					cout << "You walk back into the dining room.\n";
					cout << "Adjacent to you is the kitchen,\n";
					cout << "seperated from the dining room by a peninsula, and an island.\n";
					cout << "In the center of the dining room, is a table that's been cracked in half,\n";
					cout << "and in the right corner, is a keyboard with all it's keys missing.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("dining room") == 0 || input.compare("diningroom") == 0 || input.compare("forward") == 0 || input.compare("walk forward") == 0 || input.compare("d") == 0 || input.compare("go forward") == 0) {
					room = 6;
					haveIBeenHere[4] = 1;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("living room") == 0 || input.compare("b") == 0) {
					room = 4;
				}
				else if (input.compare("check table") == 0 || input.compare("examine table") == 0 || input.compare("table") == 0 || input.compare("t") == 0 || input.compare("inspect table") == 0 || input.compare("dining table") == 0) {
					system("cls");
					topBar();
					cout << "You attempt to check out the table.\n";
					PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
					system("timeout /t 1 >nul");
					cout << "Ouch! You got a splinter! Maybe don't do that again.\n";
					health -= 1;
					system("PAUSE>nul");
				}
				else if (input.compare("hallway") == 0 || input.compare("hall") == 0 || input.compare("enter the hall") == 0 || input.compare("h") == 0) {
					room = 8;
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 7:

				break;
			case 8:

				break;
			case 9:
				floor = 2;
				break;
			case 10:

				break;
			case 11:

				break;
			}
		}
		else if (floor == 2) { //second story
			switch (room) {
			default:
				cout << "I seem to have messed up, you're not in a room.\n";
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			case 10:

				break;
			}
		}
		else {
			switch (room) { //basement
			default:
				cout << "I seem to have messed up, you're not in a room.\n";
			case 1:

				break;
			case 2:

				break;
			case 3:

			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			case 10:

				break;
				break;
			}
		}
	}
}

void thingsInAllRooms(string input) {
	if (input.compare("inventory") == 0) {
		system("cls");
		topBar();
		cout << "Your inventory contains:\n";
		for (int i = 0; i < 10; i++) {
			if (inventoryDisplay[i] == 1) {
				system("timeout /t 1 >nul");
				cout << inventory[i] << endl;
			}
		}
		cout << endl;
		system("PAUSE>nul");
	}
	else if (input.compare("help") == 0) {
		system("cls");
		topBar();
		cout << "Available commands: Help, Inventory \n";
		system("PAUSE>nul");
	}
	else if ((input.compare("light money") == 0 || input.compare("use lighter on money") == 0 || input.compare("ignite money") == 0 || input.compare("burn money") == 0 || input.compare("use lighter") == 0) && inventory[LIGHTER] == "Lighter" && inventory[MONEY] == "Money") {
		system("cls");
		topBar();
		inventory[MONEY] = "Burning Money";
		system("PAUSE>nul");
	}
	else if (input.compare("win") == 0) {
		system("cls");
		topBar();
		cout << "YOU WIN!!\n";
		system("timeout /t 2 >nul");
		cout << "Just kidding. You wish though!\n";
		health -= 20;
		PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
		system("timeout /t 2 >nul");
	}
	else if (input != "") {
		cout << "\nUnfortunately, that isn't an option.\n";
		system("PAUSE>nul");
	}
}

bool bossFight(string input) {
	int random = betterRand();
	if (inventory[POCKET] == "Pocket Knife") {
		if (random <= 10) {

		}
		else {

		}
	}
	else if (inventory[KITCHEN] == "Kitchen Knife") {
		if (random <= 50) {

		}
		else {

		}
	}
	return 0;
}

int betterRand() {
	return (rand() % 100 + 1);
}

void topBar() {
	cout << "Press 'q' to quit.											  Health: ";
	if (health > 80)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	else if (health > 20)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	else if (health > 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout <<  health << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}