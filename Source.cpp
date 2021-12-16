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
A way to win and lose: not yet				:)
Vividly written description: Yes so far		:)
Strings for input: Yes						:)
Inventory of at least 5 items: yes			:)
Inventory in a string array: Yes			:)
Two non trivial functions: 0 so far			:)
Comments: Not nearly enough					:(
sounds and colors: not yet					:)
ASCII art: Oh god, no.						:)
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
bool burning = 0;
bool didIWin = 0;

void thingsInAllRooms(string input);
bool bossFight();
int betterRand();
void topBar();

int main() {
	srand(time(NULL));
	int randomMoney = betterRand();
	int burnTime;
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
	while (input != "q" && health > 0 && didIWin == 0) {
		//PlaySoundA((LPCSTR)"boom.WAV", NULL, SND_FILENAME | SND_ASYNC);
		//PlaySoundA((LPCSTR)"Waterphone.WAV", NULL, SND_FILENAME | SND_ASYNC);
		topBar();
		if (burning == 1) {
			if (burnTime > 0 && floor == 2 && input != "") {
				burnTime -= 1;
				cout << "Burn time remaining: " << burnTime << endl;
			}
			else 
				floor = 1;
		}
		if (floor == 1) { //main floor
			switch (room) {
			default:
				cout << "I seem to have messed up, you're not in a room.\n";
			case 1: //start
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
			case 2: //foyer
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
						cout << "You examine the coat, searching it's pockets. In one, you find";
						//bill type
						if (randomMoney > 95) {
							cout << " two 100 dollar bills.\n";
							burnTime = 2;
						}
						else if (randomMoney > 85) {
							cout << " four 50 dollar bills.\n";
							burnTime = 4;
						}
						else if (randomMoney > 70) {
							cout << " ten 10 dollar bills.\n";
							burnTime = 10;
						}
						else if (randomMoney > 40) {
							cout << " thirty 10 dollar bills.\n";
							burnTime = 30;
						}
						else if (randomMoney > 0) {
							cout << " sixty 1 dollar bills.\n";
							burnTime = 60;
						}
						inventory[MONEY] = "Money";
						inventoryDisplay[MONEY] = 1;
					}
					else {
						cout << "You've already examined this coat, you had found";
						if (randomMoney > 95) {
							cout << " two 100 dollar bills.\n";
						}
						else if (randomMoney > 85) {
							cout << " four 50 dollar bills.\n";
						}
						else if (randomMoney > 70) {
							cout << " ten 10 dollar bills.\n";
						}
						else if (randomMoney > 40) {
							cout << " thirty 10 dollar bills.\n";
						}
						else if (randomMoney > 0) {
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
			case 3: //hallway
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
			case 4: //living room
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
						cout << "You walk over to the the shattered tv, which is sitting on a tv stand, a remote next to it.\n";
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
						inventory[BATTERIES] = "Batteries";
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
					system("timeout /t 2 >nul");
					cout << "perhaps it was searched already. Not by anything human though.\n";
					system("PAUSE>nul");
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 5: // living room 2
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
			case 6: //dining room
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
				if (input.compare("kitchen") == 0 || input.compare("front") == 0 || input.compare("forward") == 0 || input.compare("walk forward") == 0 || input.compare("k") == 0 || input.compare("go forward") == 0) {
					room = 7;
					haveIBeenHere[5] = 1;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("living room") == 0 || input.compare("b") == 0) {
					room = 5;
					haveIBeenHere[5] = 1;
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
				else if (input.compare("check keyboard") == 0 || input.compare("examine keyboard") == 0 || input.compare("keyboard") == 0 || input.compare("ke") == 0 || input.compare("inspect keyboard") == 0 || input.compare("key board") == 0) {
					system("cls");
					topBar();
					cout << "You attempt to check out the keyboard.\n";
					PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
					system("timeout /t 1 >nul");
					cout << "Ouch! The sharp plastic edges cut you! Maybe don't do that again.\n";
					health -= 1;
					system("PAUSE>nul");
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 7: //kitchen
				if (haveIBeenHere[6] == 0) {
					if (amIStillHere[6] == 0) {
						cout << "You walk past the counter into the kitchen.\n";
						system("timeout /t 3 >nul");
						cout << "On the counter is a knife holder, and \n";
						system("timeout /t 3 >nul");
						cout << "towards the back of the room is a pantry.\n";
						system("timeout /t 3 >nul");
						cout << "Pots and pans hang on the wall.\n";
						amIStillHere[6] = 1;
					}
					else {
						cout << "You walk past the counter into the kitchen.\n";
						cout << "On the counter is a knife holder, and \n";
						cout << "towards the back of the room is a pantry.\n";
						cout << "Pots and pans hang on the wall.\n";
					}
				}
				else {
					cout << "You walk back into the kitchen.\n";
					cout << "On the counter is a knife holder, and \n";
					cout << "towards the back of the room is a pantry.\n";
					cout << "Pots and pans hang on the wall.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("pantry") == 0 || input.compare("p") == 0 || input.compare("open pantry") == 0) {
					system("cls");
					topBar();
					cout << "You open the pantry.\n";
					system("timeout /t 3 >nul");
					cout << "A horrid putrid stench assaults your nostrils.\n";
					PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
					health -= 1;
					system("timeout /t 3 >nul");
					cout << "The pantry is full of rotten food, that has\n";
					system("timeout /t 3 >nul");
					cout << "mostly decomposed. You slam the door shut.\n";
					system("timeout /t 3 >nul");
					cout << "Nothing you want in there.\n";
					system("PAUSE>nul");
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("dining room") == 0 || input.compare("b") == 0) {
					room = 6;
					haveIBeenHere[6] = 1;
				}
				else if (input.compare("check knives") == 0 || input.compare("examine knives") == 0 || input.compare("knives") == 0 || input.compare("k") == 0 || input.compare("inspect knives") == 0 || input.compare("knife holder") == 0) {
					system("cls");
					topBar();
					if (inventoryDisplay[KITCHEN] == 0) {
						cout << "You walk over to the knife holder.\n";
						system("timeout /t 3 >nul");
						cout << "You find a few knives,\n";
						system("timeout /t 3 >nul");
						cout << " and decide to take the bread knife.\n";
						inventory[KITCHEN] = "Kitchen Knife";
						inventoryDisplay[KITCHEN] = 1;
					}
					else {
						cout << "You already checked out the knives, you had taken a bread knife.\n";
					}
					system("PAUSE>nul");
				}
				else if (input.compare("pots") == 0 || input.compare("pans") == 0 || input.compare("pots and pans") == 0 || input.compare("pot") == 0) {
					system("cls");
					topBar();
					cout << "You reach up to check out the pots and pans.\n";
					system("timeout /t 3 >nul");
					cout << "You notice they are completely rusted,\n";
					system("timeout /t 3 >nul");
					cout << "and as you touch one, its handle snaps off,\n";
					system("timeout /t 3 >nul");
					cout << "and hits you right on the head.\n";
					PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
					health -= 5;
					system("PAUSE>nul");
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 8: //hallway 2
				if (haveIBeenHere[7] == 0) {
					if (amIStillHere[7] == 0) {
						cout << "You walk into the hallway.\n";
						system("timeout /t 3 >nul");
						cout << "In front of you is an open door \n";
						system("timeout /t 3 >nul");
						cout << "leading to the basement,\n";
						system("timeout /t 3 >nul");
						cout << "and to your left is another open door,\n";
						system("timeout /t 3 >nul");
						cout << "leading to a filthy bathroom.\n";
						amIStillHere[7] = 1;
					}
					else {
						cout << "You walk into the hallway.\n";
						cout << "In front of you is an open door\n";
						cout << "leading to the basement,\n";
						cout << "and to your left is another open door,\n";
						cout << "leading to a filthy bathroom.\n";
					}
				}
				else {
					cout << "You walk into the hallway.\n";
					cout << "In front of you is an open door\n";
					cout << "leading to the basement,\n";
					cout << "and to your left is another open door,\n";
					cout << "leading to a filthy bathroom.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("bathroom") == 0 || input.compare("bath") == 0 || input.compare("enter the bathroom") == 0 || input.compare("b") == 0) {
				room = 11;
				haveIBeenHere[7] = 1;
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("living room") == 0 || input.compare("livingroom") == 0) {
				room = 5;
				haveIBeenHere[7] = 1;
				}
				else if (input.compare("basement") == 0 || input.compare("stairs") == 0 || input.compare("go downstairs") == 0 || input.compare("go down stairs") == 0 || input.compare("s") == 0) {
					room = 10;
					haveIBeenHere[7] = 1;
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			case 9: //stairs
				floor = 2;
				room = 1;
				break;
			case 10: //basement
				cout << "This is where you would enter the basement,\n";
				system("timeout /t 3 >nul");
				cout << "but this is early access, so, you can't.\n";
				system("timeout /t 3 >nul");
				cout << "Plans for the basement includes crafting,\n";
				system("timeout /t 3 >nul");
				cout << "however plans for this game do not include updating it.\n";
				room = 8;
				system("PAUSE");
				system("cls");
				break;
			case 11: // bathroom
				if (haveIBeenHere[10] == 0) {
					if (amIStillHere[10] == 0) {
						cout << "You walk into the bathroom.\n";
						system("timeout /t 3 >nul");
						cout << "It's disgusting. The walls are stained black,\n";
						system("timeout /t 3 >nul");
						cout << "and the toilet is cracked in half.\n";
						system("timeout /t 3 >nul");
						cout << "In the sink is something that smells terrible,\n";
						system("timeout /t 3 >nul");
						cout << "and you hope it's not something dead.\n";
						amIStillHere[10] = 1;
					}
					else {
						cout << "You walk into the bathroom.\n";
						cout << "It's disgusting. The walls are stained black,\n";
						cout << "and the toilet is cracked in half.\n";
						cout << "In the sink is something that smells terrible,\n";
						cout << "and you hope it's not something dead.\n";
					}
				}
				else {
					cout << "You walk into the bathroom.\n";
					cout << "It's disgusting. The walls are stained black,\n";
					cout << "and the toilet is cracked in half.\n";
					cout << "In the sink is something that smells terrible,\n";
					cout << "and you hope it's not something dead.\n";
				}
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("dead") == 0 || input.compare("sink") == 0 || input.compare("examine sink") == 0 || input.compare("s") == 0) {
					system("cls");
					topBar();
					cout << "You reach into the sink, holding your breath.\n";
					system("timeout /t 3 >nul");
					cout << "You touch the smelly thing, and much to your dismay,\n";
					system("timeout /t 3 >nul");
					cout << "it is in fact something dead.\n";
					system("timeout /t 3 >nul");
					cout << "You recoil, deciding you want nothing to do with it.\n";
					system("PAUSE>nul");
				}
				else if (input.compare("back") == 0 || input.compare("go back") == 0 || input.compare("walk back") == 0 || input.compare("hall") == 0 || input.compare("hallway") == 0 || input.compare("b") == 0) {
					room = 8;
					haveIBeenHere[10] = 1;
				}
				else {
					thingsInAllRooms(input);
				}
				system("cls");
				break;
			}
		}
		else if (floor == 2) { //second story
			switch (room) {
			default:
				cout << "I seem to have messed up, you're not in a room.\n";
			case 1:
				system("cls");
				topBar();
				cout << "Congratulations! You made it upstairs!\n";
				system("timeout /t 3 >nul");
				cout << "This is an area that doesn't exist yet either,\n";
				system("timeout /t 3 >nul");
				cout << "so you'll just be teleported to the boss fight.\n";
				system("timeout /t 3 >nul");
				cout << "Good Luck!\n";
				room = 8;
				system("PAUSE>nul");
				system("cls");
				break;
			case 2: // hallway

				break;
			case 3: // bedroom

				break;
			case 4: // hallway

				break;
			case 5: //bedroom

				break;
			case 6: //bathroom

				break;
			case 7: //bedroom

				break;
			case 8: //boss room
				cout << "You appear before a closet door.\n";
				system("timeout /t 3 >nul");
				cout << "You open it";
				system("timeout /t 1 >nul");
				cout << ".";
				system("timeout /t 1 >nul");
				cout << ".";
				system("timeout /t 1 >nul");
				cout << ".\n";
				system("timeout /t 3 >nul");
				cout << "Suddenly something that looks very much like you\n";
				cout << "jumps out of the shadows, slashing at your face with its fingers.\n";
				system("timeout /t 3 >nul");
				cout << "You stumble back, barely avoiding it.\n";
				system("PAUSE>nul");
				system("cls");
				didIWin = bossFight();
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
			}
		}
	}
	if (didIWin == 1) {
		system("cls");
		cout << "You Win!\nVery impressive.\n";
		system("PAUSE>nul");
	}
	else if (didIWin == 0 && input == "q") {
		system("cls");
		cout << "Game Over!\nYou quit! You'll have to start over.\n";
		system("PAUSE>nul");
	}
	else if (didIWin == 0 && health <= 0) {
		system("cls");
		cout << "Game Over!\nYou died! Will you try again?\n";
		system("PAUSE>nul");
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
	else if (input.compare("light money") == 0 || input.compare("use lighter on money") == 0 || input.compare("ignite money") == 0 || input.compare("burn money") == 0 || input.compare("use lighter") == 0) {
		if (inventory[LIGHTER] == "Lighter" && inventory[MONEY] == "Money") {
			system("cls");
			topBar();
			cout << "You set the money you found on fire.\n";
			system("timeout /t 3 >nul");
			cout << "The more paper you have, the longer the fire will last.\n";
			inventory[MONEY] = "Burning Money";
			burning = 1;
		}
		else if (inventory[MONEY] == "Burning Money") {
			system("cls");
			topBar();
			cout << "You've already lit your money on fire.\n";
		}
		else {
			cout << "Good idea, but how will you burn it?\n";
		}
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

bool bossFight() {
	bool inBattle = 0;
	int stage = 1;
	string input;
	int bossHealth = 100;
	int bossLeftA = 3;
	int bossLeftL = 3;
	int bossRightA = 3;
	int bossRightL = 3;
	int bossHead = 3;
	bool weaponOut = 0;
	int random;
	while (inBattle == 0 && health > 0 && bossHealth > 0 && bossHead > 0) {
	system("cls");
	topBar();
		switch (stage) {
			case 1:
				cout << "The fight begins.\n";
				system("timeout /t 3 >nul");
				cout << "The other you follows up his attack,\n";
				system("timeout /t 3 >nul");
				cout << "lunging for your throat.\n";
				system("timeout /t 3 >nul");
				cout << "What will you do?\n";
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("dodge") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 10) {
						cout << "You barely dodge, the creatures blackened fingers miss your neck.\n";
					}
					else {
						cout << "You aren't quite fast enough.\n";
						cout << "The creatures balckened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
					}
					stage = 2;
				}
				else if (input.compare("block") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 20) {
						cout << "You block the hit.\n";
						cout << "The creatures balckened hand strikes your arm.\n";
					}
					else {
						cout << "You aren't quite fast enough.\n";
						cout << "The creatures balckened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
					}
					stage = 2;
				}
				else if (input.compare("attack") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 50) {
						cout << "You swing at the creatures arm.\n";
						system("timeout /t 3 >nul");
						cout << "A hit! The creature takes a step back, astonsihed.\n";
						bossLeftA -= 1;
						bossHealth -= 5;
					}
					else {
						cout << "You swing at the creatures arm.\n";
						system("timeout /t 3 >nul");
						cout << "The creature alters its swing, dodging your attack.\n";
						system("timeout /t 3 >nul");
						cout << "It's blackened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
					}
					stage = 2;
				}
				if (inventory[KITCHEN] == "Kitchen Knife") {
					if (input.compare("slash") == 0 || input.compare("stab") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 90) {
							cout << "You attempt to draw your weapon and attack.\n";
							system("timeout /t 3 >nul");
							cout << "Somehow you're fast enough, cleaving into the creatures arm.\n";
							system("timeout /t 3 >nul");
							cout << "The creature recoils, stunned, as its arm leaks black blood.\n";
							bossHealth -= 10;
							bossLeftA -= 2;
						}
						else {
							cout << "You aren't quite fast enough.\n";
							system("timeout /t 3 >nul");
							cout << "You get your weapon out, but the creatures attack connects.\n";
							system("timeout /t 3 >nul");
							cout << "The creatures balckened fingers scratch your neck.\n";
							PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
							health -= 5;
						}
						stage = 2;
						weaponOut = 1;
					}
					else if (input.compare("knife") == 0 || input.compare("weapon") == 0 || input.compare("draw weapon") == 0 || input.compare("draw knife") == 0) {
						system("cls");
						topBar();
						cout << "You get your weapon out as the creature connects.\n";
						cout << "The creatures balckened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
						stage = 2;
						weaponOut = 1;
					}
					else {
						thingsInAllRooms(input);
					}
				}
				else {
					thingsInAllRooms(input);
				}
				system("PAUSE>nul");
				system("cls");
				break;
			case 2:
				cout << "How will you counter? (attack <body part>)\n";
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (weaponOut == 0) {
					if (input.compare("attack head") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 70) {
							cout << "You swing at the creatures head.\n";
							system("timeout /t 3 >nul");
							cout << "The creature tries to dodge but fails,\n";
							system("timeout /t 3 >nul");
							cout << "and your fist connects with its face.\n";
							system("timeout /t 3 >nul");
							cout << "The creature stumbles, then readies itself to attack.\n";
							bossHead -= 1;
							bossHealth -= 15;
						}
						else {
							cout << "You swing at the creatures head,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature dips, dodging your attack,\n";
							system("timeout /t 3 >nul");
							cout << "and readying its next swing.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack arm") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 10) {
							cout << "You swing at the creatures arm.\n";
							system("timeout /t 3 >nul");
							cout << "The creature moves to block,\n";
							system("timeout /t 3 >nul");
							cout << "but since you were going to hit its arm anyway,\n";
							system("timeout /t 3 >nul");
							cout << "your attack connects.\n";
							bossRightA -= 1;
							bossHealth -= 5;
						}
						else {
							cout << "You swing at the creatures arm,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack leg") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 30) {
							cout << "You kick at the creatures leg.\n";
							system("timeout /t 3 >nul");
							cout << "You connect! The creature staggers, then regains its footing.\n";
							bossLeftL -= 1;
							bossHealth -= 5;
						}
						else {
							cout << "You kick at the creatures leg,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack stomach") == 0 || input.compare("attack torso") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 60) {
							cout << "You strike at the creatures stomach.\n";
							system("timeout /t 3 >nul");
							cout << "A hit! The creature doubles over in pain.\n";
							bossHealth -= 15;
						}
						else {
							cout << "You strike at the creatures stomach,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack chest") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 60) {
							cout << "You strike at the creatures chest.\n";
							system("timeout /t 3 >nul");
							cout << "Your fist connects, knocking the breath out of the creature.\n";
							bossHealth -= 10;
						}
						else {
							cout << "You strike at the creatures chest,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, dodging your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack groin") == 0 || input.compare("attack crotch") == 0 || input.compare("attack balls") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 50) {
						cout << "You kick with all your might at the creatures balls.\n";
						system("timeout /t 3 >nul");
						cout << "A critical hit! The creature straight up dies.\n";
						system("timeout /t 3 >nul");
						cout << "Really had to do it to 'em huh?\n";
						bossHealth -= 100;
					}
					else {
						cout << "You kick with all your might at the creatures balls.\n";
						system("timeout /t 3 >nul");
						cout << "The creature blocks, and in anger,\n";
						system("timeout /t 3 >nul");
						cout << "punches your chest so hard your ribs cage in,\n";
						system("timeout /t 3 >nul");
						cout << "killing you instantly. Don't kick monsters in the balls I guess.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 100;
					}
					system("PAUSE>nul");
					system("cls");
					}
					else {
						thingsInAllRooms(input);
					}
				}
				else {
					if(input.compare("attack head") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 70) {
							cout << "You slash at the creatures head.\n";
							system("timeout /t 3 >nul");
							cout << "The creature tries to dodge but fails,\n";
							system("timeout /t 3 >nul");
							cout << "and your blade gouges with its face.\n";
							system("timeout /t 3 >nul");
							cout << "The creature stumbles, then readies itself to attack.\n";
							bossHead -= 2;
							bossHealth -= 30;
						}
						else {
							cout << "You swing at the creatures head,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature dips, dodging your attack,\n";
							system("timeout /t 3 >nul");
							cout << "and readying its next swing.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack arm") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 70) {
							cout << "You slash at the creatures arm.\n";
							system("timeout /t 3 >nul");
							cout << "The creature moves to block,\n";
							system("timeout /t 3 >nul");
							cout << "but since you were going to hit its arm anyway,\n";
							system("timeout /t 3 >nul");
							cout << "your attack connects.\n";
							bossRightA -= 2;
							bossHealth -= 15;
						}
						else {
							cout << "You slash at the creatures arm,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack leg") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 30) {
							cout << "You kick at the creatures leg.\n";
							system("timeout /t 3 >nul");
							cout << "You connect! The creature staggers, then regains its footing.\n";
							bossLeftL -= 1;
							bossHealth -= 5;
						}
						else {
							cout << "You kick at the creatures leg,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack stomach") == 0 || input.compare("attack torso") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 70) {
							cout << "You thrust at the creatures stomach.\n";
							system("timeout /t 3 >nul");
							cout << "Your blade pierces, the creature doubles over in pain.\n";	
							bossHealth -= 25;
						}
						else {
							cout << "You thrust at the creatures stomach,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, barely avoiding your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack chest") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 75) {
							cout << "You stab at the creatures chest.\n";
							system("timeout /t 3 >nul");
							cout << "Your blade connects, piercing the creatures heart,\n";
							system("timeout /t 3 >nul");
							cout << "it will die very soon.\n";
							bossHealth -= 95;
						}
						else {
							cout << "You strike at the creatures chest,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature steps back, dodging your attack.\n";
						}
						system("PAUSE>nul");
						system("cls");
					}
					else if (input.compare("attack groin") == 0 || input.compare("attack crotch") == 0 || input.compare("attack balls") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 50) {
							cout << "You kick with all your might at the creatures balls.\n";
							system("timeout /t 3 >nul");
							cout << "A critical hit! The creature straight up dies.\n";
							system("timeout /t 3 >nul");
							cout << "Really had to do it to 'em huh?\n";
							bossHealth -= 100;
						}
						else {
							cout << "You kick with all your might at the creatures balls,\n";
							system("timeout /t 3 >nul");
							cout << "but the creature blocks, and in anger,\n";
							system("timeout /t 3 >nul");
							cout << "punches your chest so hard your ribs cage in,\n";
							system("timeout /t 3 >nul");
							cout << "killing you instantly. Don't kick monsters in the balls I guess.\n";
							PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
							health -= 100;
						}
						system("PAUSE>nul");
						system("cls");
					}
					else {
						thingsInAllRooms(input);
					}
				}
				system("PAUSE>nul");
				system("cls");
				break;
			case 3:
				cout << "The creature steps forward to attack again,\n";
				system("timeout /t 3 >nul");
				cout << "and pulls its arm back for a hard punch.\n";
				system("timeout /t 3 >nul");
				cout << "It lunges.\n";
				system("timeout /t 3 >nul");
				cout << "What will you do?\n";
				getline(cin, input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				if (input.compare("dodge") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 30) {
						cout << "You barely dodge, the creatures arm extends past you.\n";
					}
					else {
						cout << "You aren't quite fast enough.\n";
						system("timeout /t 3 >nul");
						cout << "The creatures fist connects with your chest,\n";
						system("timeout /t 3 >nul");
						cout << "cracking a rib.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 15;
					}
					stage = 4;
				}
				else if (input.compare("block") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 20) {
						cout << "You block the hit.\n";
						cout << "The creatures fist strikes your arm.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
					}
					else {
						cout << "You aren't quite fast enough.\n";
						system("timeout /t 3 >nul");
						cout << "The creatures fist connects with your chest,\n";
						system("timeout /t 3 >nul");
						cout << "cracking a rib.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 15;
					}
					stage = 4;
				}
				if (weaponOut == 0) {
					if (input.compare("slash") == 0 || input.compare("stab") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 90) {
							cout << "You attempt to draw your weapon and attack.\n";
							system("timeout /t 3 >nul");
							cout << "Somehow you're fast enough, cleaving into the creatures shoulder.\n";
							system("timeout /t 3 >nul");
							cout << "The creature falls, then quickly gets back up.\n";
							bossHealth -= 15;
							bossRightA -= 2;
							system("timeout /t 3 >nul");
							if (bossRightA > 0) {
								cout << "The creatures arm seems ready to fall off.\n";
							}
							else {
								cout << "The creatures arm falls off as it stands.\n";
							}
						}
						else {
							cout << "You aren't quite fast enough.\n";
							system("timeout /t 3 >nul");
							cout << "You get your weapon out, but the creatures fist connects with your chest,\n";
							system("timeout /t 3 >nul");
							cout << "cracking a rib.\n";
							PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
							health -= 15;
						}
						stage = 4;
						weaponOut = 1;
					}
					else if (input.compare("knife") == 0 || input.compare("weapon") == 0 || input.compare("draw weapon") == 0 || input.compare("draw knife") == 0) {
						system("cls");
						topBar();
						cout << "You get your weapon out as the creature connects.\n";
						system("timeout /t 3 >nul");
						cout << "Its attack hits your chest,\n";
						system("timeout /t 3 >nul");
						cout << "cracking a rib.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 15;
						stage = 4;
						weaponOut = 1;
					}
					else {
						thingsInAllRooms(input);
					}
				}
				else {
					if (input.compare("slash") == 0 || input.compare("stab") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 60) {
							cout << "You attempt to slash at the creature.\n";
							system("timeout /t 3 >nul");
							cout << "Somehow you're fast enough, cleaving into the creatures shoulder.\n";
							system("timeout /t 3 >nul");
							cout << "The creature falls, then quickly gets back up.\n";
							bossHealth -= 15;
							bossRightA -= 2;
							system("timeout /t 3 >nul");
							if (bossRightA > 0) {
								cout << "The creatures arm seems ready to fall off.\n";
							}
							else {
								cout << "The creatures arm falls off as it stands.\n";
							}
						}
						else {
							cout << "You aren't quite fast enough.\n";
							system("timeout /t 3 >nul");
							cout << "The creatures fist connects with your chest,\n";
							system("timeout /t 3 >nul");
							cout << "cracking a rib.\n";
							PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
							health -= 15;
						}
						stage = 4;
					}
					else {
						thingsInAllRooms(input);
					}

				}
				if (input.compare("attack") == 0) {
					random = betterRand();
					system("cls");
					topBar();
					if (random > 50) {
						cout << "You swing at the creatures arm.\n";
						system("timeout /t 3 >nul");
						cout << "A hit! The creature takes a step back, astonsihed.\n";
						bossLeftA -= 1;
						bossHealth -= 5;
					}
					else {
						cout << "You swing at the creatures arm.\n";
						system("timeout /t 3 >nul");
						cout << "The creature alters its swing, dodging your attack.\n";
						system("timeout /t 3 >nul");
						cout << "It's blackened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
					}
					stage = 2;
				}
				if (inventory[KITCHEN] == "Kitchen Knife") {
					if (input.compare("slash") == 0 || input.compare("stab") == 0) {
						random = betterRand();
						system("cls");
						topBar();
						if (random > 90) {
							cout << "You attempt to draw your weapon and attack.\n";
							system("timeout /t 3 >nul");
							cout << "Somehow you're fast enough, cleaving into the creatures arm.\n";
							system("timeout /t 3 >nul");
							cout << "The creature recoils, stunned, as its arm leaks black blood.\n";
							bossHealth -= 10;
							bossLeftA -= 2;
						}
						else {
							cout << "You aren't quite fast enough.\n";
							system("timeout /t 3 >nul");
							cout << "You get your weapon out, but the creatures attack connects.\n";
							system("timeout /t 3 >nul");
							cout << "The creatures balckened fingers scratch your neck.\n";
							PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
							health -= 5;
						}
						stage = 2;
						weaponOut = 1;
					}
					else if (input.compare("knife") == 0 || input.compare("weapon") == 0 || input.compare("draw weapon") == 0 || input.compare("draw knife") == 0) {
						system("cls");
						topBar();
						cout << "You get your weapon out as the creature connects.\n";
						cout << "The creatures balckened fingers scratch your neck.\n";
						PlaySoundA((LPCSTR)"hitsound.WAV", NULL, SND_FILENAME | SND_ASYNC);
						health -= 5;
						stage = 2;
						weaponOut = 1;
					}
					else {
						thingsInAllRooms(input);
					}
				}
				else {
					thingsInAllRooms(input);
				}
				system("PAUSE>nul");
				system("cls");
				break;
		}
	}
	return 1;
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