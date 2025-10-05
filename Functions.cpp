#include <iostream>;
#include <fstream>;
#include <string>;
#include <stdlib.h>;
#include <windows.h>;
#include "Header.h";
using namespace std;

Inventory inventory;
Locks lock;
RoomsVisited track;

void print(string msg) {
	cout << msg << endl;
}
void printAndWait(float seconds, string msg) {
	print(msg);
	Sleep(seconds * 1000);
}

#pragma region AssessmentOneFunctions

int stringUtil::length(string msg) {
	int msgLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	return msgLength;
}
char stringUtil::charAt(string msg, int index) {
	int msgLength = 0;
	for (char i : msg) {
		msgLength++;
	}
	if (index < 0 || index > msgLength) {
		return '\0';
	}
	else {
		return msg[index - 1];
	}
}
bool stringUtil::equalTo(string msg1, string msg2) {
	if (msg1 == msg2) {
		return true;
	}
	else {
		return false;
	}
}
void stringUtil::equalTo(string msg1, string msg2, string yesmsg, string nomsg) {
	if (msg1 == msg2) {
		print(yesmsg);
	}
	else {
		print(nomsg);
	}
}
void stringUtil::append(string& msg, string append) {
	msg = msg + append;
}
void stringUtil::prepend(string& msg1, string append) {
	msg1 = append + msg1;
}
void stringUtil::toUpper(string& msg) {
	for (char &i : msg) {
		if (i >= 'a' && i <= 'z') {
			i -= 32;
		}
	}
}
void stringUtil::toLower(string& msg) {
	for (char& i : msg) {
		if (i >= 'A' && i <= 'Z') {
			i += 32;
		}
	}
}
int stringUtil::find(string msg, string findString) {
	stringUtil stringFunc;
	int msgLength = stringFunc.length(msg);
	int findLength = stringFunc.length(findString);
	if (findLength > msgLength) {
		return -1;
	}
	else {
		// Goes through every character of msg and checks with the first character of findString
		// If it finds a common character, it does repeated checks with the further characters
		// if it all connects, break the loop and return the location its found
		int location;
		for (int i = 0; i <= msgLength - findLength; i++) {
			if (msg[i] == findString[0]) {
				location = i;
				bool found = false;
				for (int a = 1; a <= findLength; a++) {
					if (a == findLength) {
						return location + 1;
					}
					if (!(msg[i + a] == findString[0 + a])) {
						break;
					}
				}
			}
		}
		return -1;
	}
}
bool stringUtil::boolFind(string msg, string findString) {
	stringUtil stringFunc;
	int msgLength = stringFunc.length(msg);
	int findLength = stringFunc.length(findString);
	if (findLength > msgLength) {
		return false;
	}
	else {
		// Goes through every character of msg and checks with the first character of findString
		// If it finds a common character, it does repeated checks with the further characters
		// if it all connects, break the loop and return the location its found
		int location;
		for (int i = 0; i <= msgLength - findLength; i++) {
			if (msg[i] == findString[0]) {
				location = i;
				bool found = false;
				for (int a = 1; a <= findLength; a++) {
					if (a == findLength) {
						return true;
					}
					if (!(msg[i + a] == findString[0 + a])) {
						break;
					}
				}
			}
		}
		return false;
	}
}
int stringUtil::find(int index, string msg, string findString) {
	stringUtil stringFunc;
	int msgLength = stringFunc.length(msg);
	int findLength = stringFunc.length(findString);
	if (findLength > msgLength) {
		return -1;
	}
	else {
		// Goes through every character of msg and checks with the first character of findString
		// If it finds a common character, it does repeated checks with the further characters
		// if it all connects, break the loop and return the location its found
		int location;
		for (int i = index; i <= msgLength - findLength; i++) {
			if (msg[i] == findString[0]) {
				location = i;
				bool found = false;
				for (int a = 1; a <= findLength; a++) {
					if (a == findLength) {
						return location + 1;
					}
					if (!(msg[i + a] == findString[0 + a])) {
						break;
					}
				}
			}
		}
		return -1;
	}
}
string stringUtil::replace(string msg, string findString, string replaceString) {
	stringUtil stringFunc;
	bool findFound = false;
	int findLocation = 0;
	int msgLength = stringFunc.length(msg);
	int findLength = stringFunc.length(findString);
	int replaceLength = stringFunc.length(replaceString);
	if (findLength > msgLength) 
	{
		return "-1";
	}
	for (int i = 0; i < msgLength - findLength; i++) 
	{
		// Compare the message to the first character of findString
		if (msg[i] == findString[0]) 
		{
			// Check for the entire findString starting at its location
			int location = stringFunc.find(i, msg, findString) - 1;
			if (location != -2) 
			{
				findFound = true;
				int og = 0;
				string newMSG = "";
				// Loop through the message until it reaches location
				// Then, it adds the replaceString message to the string
				// Goes back to writing the rest of the message afterwards
				for (int loop = 0; loop < msgLength - findLength + replaceLength; loop++) 
				{
					string originalMSG = msg;
					if (loop == location) {
						newMSG += replaceString;
						loop += replaceLength - 1;
						og += findLength;
					}
					else {
						newMSG += originalMSG[og];
						og += 1;
					}
				}
				msg = newMSG;
			}
		}
	}
	// Returns error if findString isn't found.
	if (!findFound) {
		return "-1";
	}
	else {
		return msg;
	}
}
//string stringUtil::replace(string msg, string findString, string replaceString) {
//	// You were manually counting string lengths, instead of using .length(). Should save some time.
//	int msgLength = msg.length();
//	int findLength = findString.length();
//	int replaceLength = replaceString.length();
//
//	if (findLength > msgLength) {
//		return "-1";
//	}
//	else {
//		// Goes through every character of msg and checks with the first character of findString
//		// If it finds a common character, it does repeated checks with the further characters
//		// if it all connects, start replacing strings, then goes back to checking
//		int location = 0;
//		bool found = false;
//		for (int i = 0; i <= msgLength - findLength; i++) {
//			if (msg[i] == findString[0]) {
//				for (int a = 0; a <= findLength; a++) {
//					if (a == findLength - 1)
//					{
//						// If whatever you're gonna replace it with is longer than the original
//						if (findLength < replaceLength) {
//							string tempMsg = msg;
//							string newMsg = "";
//							int e = 0;
//							for (int c = 0; c <= msgLength - findLength + replaceLength; c++) {
//
//								if (c == location) {
//									for (int f = 0; f < replaceLength; f++, c++) {
//										newMsg += replaceString[f];
//									}
//									e += findLength;
//									c -= 1;
//									// programmers will see this code and kill themselves
//								}
//								else {
//									newMsg += tempMsg[e];
//									e += 1;
//								}
//							}
//							msg = newMsg;
//						}
//						else if (findLength == replaceLength) {
//							for (int b = 0; b < findLength; b++) {
//								msg[i + b] = replaceString[b];
//							}
//							return msg;
//						}
//						else {
//
//						}
//						found = true;
//						if (!(msg[i + a] == findString[0 + a])) {
//							break;
//						}
//					}
//				}
//			}
//
//		}
//		if (!found) { return "-1"; }
//	}
//}
string stringUtil::removeSpaces(string msg) {
	for (int i = 0; i < msg.length(); i++)
	{
		if (msg[i] == ' ')
		{
			//snatched from the internet sorry :(
			msg.erase(msg.begin() + i);
			i--;
		}
	}
	return msg;
}
string stringUtil::ReadFromConsole() {
	string input = "";
	cin >> input;
	return input;
}
void stringUtil::WriteToConsole(string msg) {
	print(msg);
}
#pragma endregion

#pragma region AssessmentTwoThreeFunctions

void stringTestUtil::testLength() {
	string testMessage = "bongbong";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	int length = Test.length(testMessage);
	if (length == 8) {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Length", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Length", false);
	}
	print(" --- PRINT FUNCTION");
}
void stringTestUtil::testCharAt() {
	string testMessage = "yumyum";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	int characterAt = Test.charAt(testMessage, 4);
	if (characterAt == 'y') {
		cout << "OPERATIONAL";
		Log.appendToLogFile("CharAt", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("CharAt", false);
	}
	print(" --- CHARACTER-AT FUNCTION");
}
void stringTestUtil::testEqualTo1() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	if (!(Test.equalTo(testMessage1, testMessage2))) {
		cout << "OPERATIONAL";
		Log.appendToLogFile("String-Equalto", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("String-Equalto", false);
	}
	print(" --- STRING-EQUALTO FUNCTION");
}
//void stringTestUtil::testEqualTo2() {
//	string testMessage1 = "bongbong";
//	string testMessage2 = "yumyum";
//	stringUtil Test;
//	Test.equalTo(testMessage1, testMessage2, "Hello!", "Goodbye!");
//	print("OPERATIONAL if printed Goodbye! Else, DYSFUNCTIONAL --- VOID-EQUALTO FUNCTION");
//}
void stringTestUtil::testAppend() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	Test.append(testMessage1, testMessage2);
	if (testMessage1 == "bongbongyumyum") {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Aappend", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Append", false);
	}
	print(" --- APPEND FUNCTION");
}
void stringTestUtil::testPrepend() {
	string testMessage1 = "bongbong";
	string testMessage2 = "yumyum";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	Test.prepend(testMessage1, testMessage2);
	if (testMessage1 == "yumyumbongbong") {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Prepend", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Prepend", false);
	}
	print(" --- PREPEND FUNCTION");
}
void stringTestUtil::testtoUpper() {
	string testMessage = "BonGbONggG";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	Test.toUpper(testMessage);
	if (testMessage == "BONGBONGGG") {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Uppercase", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Uppercase", false);
	}
	print(" --- UPPERCASE FUNCTION");
}
void stringTestUtil::testtoLower() {
	string testMessage = "BonGbONggG";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	Test.toLower(testMessage);
	if (testMessage == "bongbonggg") {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Lowercase", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Lowercase", false);
	}
	print(" --- LOWERCASE FUNCTION");
}
void stringTestUtil::testFind1() {
	string testMessage = "Wingding";
	string targetMessage = "ding";
	stringUtil Test;
	fileHandle Log;
	total += 1;
	if (Test.find(testMessage, targetMessage) == 5) {
		cout << "OPERATIONAL";
		Log.appendToLogFile("First Find", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("First Find", false);
	}
	print(" --- FIND FUNCTION");
}
void stringTestUtil::testFind2() {
	string testMessage = "DookWardingDook";
	string targetMessage = "Dook";
	int index = 6;
	stringUtil Test;
	fileHandle Log;
	total += 1;
	if (Test.find(index, testMessage, targetMessage) == 12) {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Second Find", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Second Find", false);
	}
	print(" --- FIND-INDEX FUNCTION");
}
void stringTestUtil::testReplace() {
	string testMessage = "wingwongbongboom";
	string testFind = "bong";
	string testReplace = "yummer";
	fileHandle Log;
	stringUtil Test;
	total += 1;
	if (Test.replace(testMessage, testFind, testReplace) == "wingwongyummerboom") {
		cout << "OPERATIONAL";
		Log.appendToLogFile("Replace", true);
		totalSucceed += 1;
	}
	else {
		cout << "DYSFUNCTIONAL";
		Log.appendToLogFile("Replace", false);
		cout << "DYSFUNCTIONAL";
	}
	print(" --- REPLACE FUNCTION");
}
//void stringTestUtil::testReadFromConsole() {
//	string Input;
//	stringUtil Test;
//	Input = Test.ReadFromConsole();
//	print(Input);
//	print("OPERATIONAL if printed correctly! Else, DYSFUNCTIONAL --- READFROMCONSOLE FUNCTION");
//}
//void stringTestUtil::testWriteToConsole() {
//	print("TESTING OPERATION OF THE WRITETOCONSOLE FUNCTION ---");
//	string message = "If you see this message, the functiton is OPERATIONAL!";
//	stringUtil Test;
//	Test.WriteToConsole(message);
//}
void runAllTests() {
	stringTestUtil Test;
	Test.testLength();
	Test.testCharAt();
	Test.testEqualTo1();
	/*Test.testEqualTo2();*/
	Test.testAppend();
	Test.testPrepend();
	Test.testtoUpper();
	Test.testtoLower();
	Test.testFind1();
	Test.testFind2();
	Test.testReplace();
	Test.testResults();
	/*Test.testReadFromConsole();*/
	/*Test.testWriteToConsole();*/
}
#pragma endregion

#pragma region AssessmentThreeFunctions
bool fileHandle::fileExists(string filename) {
	ifstream file(filename);
	return file.is_open();
}
void fileHandle::appendToLogFile(string msg, bool result) {
	fileHandle Log;
	ofstream logFile("log_file.txt", ios::app);
	if (Log.fileExists("log_file.txt")) {
		if (result) {
			logFile << msg + " Function: Operational" << endl;
		}
		else {
			logFile << msg + " Function: Dysfunctional" << endl;
		}
		logFile.close();
	}
	else {
		print("fileHandle function error: appendtoLogFile unsuccessful");
	}
}
void stringTestUtil::testResults() {
	fileHandle Log;
	float successRate = totalSucceed / totalSucceed * 100;
	ofstream logFile("log_file.txt", ios::app);
	if (Log.fileExists("log_file.txt")) {
		logFile << "Test Success Rate: " << successRate << "%" << endl;
		logFile << "" << endl;
		logFile.close();
	}
	else {
		print("fileHandle function error: testResults unsuccessful");
	}
}
#pragma endregion

# pragma region AssessmentFourFunctions

void Rooms::inRoomLogic(string &currentRoom) {

}
void Rooms::cantGoDirection() {
	string nothing;
	print("There's nowhere to go in this direction!");
	getline(cin, nothing);
	system("cls");
}
void Rooms::useItem(string item) {
	string nothing;
	print("Hm, didn't seem to work.");
	getline(cin, nothing);
	system("cls");
}
void Rooms::searchRoom() {

}

# pragma region Entrance
void Entrance::inRoomLogic(string &currentRoom) {
	stringUtil stringFunc;
	Entrance entranceRoom;
	string input;
	while (currentRoom == "entranceRoom")
	{
		track.entranceName = "Parking Lot";
		print("You stand in the Pizzeria's parking lot.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.carTrunkName, "null", track.pizzeriaDoorsName, "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			entranceRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			entranceRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			entranceRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			entranceRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			entranceRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			entranceRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void Entrance::goNorth(string &currentRoom) {
	currentRoom = "carTrunk";
}
void Entrance::goWest(string& currentRoom) {
	cantGoDirection();
}
void Entrance::goSouth(string& currentRoom) {
	currentRoom = "pizzeriaDoors";
}
void Entrance::goEast(string& currentRoom) {
	cantGoDirection();
}
void Entrance::searchRoom() {
	system("cls");
	string nothing;
	print("The parking lot remains empty, void of cars except for yours.");
	if (inventory.checkForItem("[x] flashlight"))
	{
		print("Your flashlight doesn't emit any light; it needs some batteries.");
	}
	else if (inventory.checkForItem("flashlight") && lock.parkingLotItem)
	{
		lock.parkingLotItem = false;
		inventory.collectItem("Freddys Tophat");
		print("Your flashlight catches a glimpse of a tophat on the ground.");
		print("Maybe it belongs to someone?");
		print("[+] Freddy's Tophat");
	}
	else if (inventory.checkForItem("flashlight"))
	{
		print("You can't find anything else in this parking lot.");
	}
	else
	{
		print("In the dark of night, it's hard to find anything out here");
		string msg = (lock.parkingLotItem) ? "Maybe if you could see, you might find something out here." : "Luckily there's nothing else to find out here.";
		print(msg);
	}
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

#pragma region CarTrunk
void CarTrunk::inRoomLogic(string &currentRoom) {
	stringUtil stringFunc;
	CarTrunk carTrunkRoom;
	string input;
	while (currentRoom == "carTrunk")
	{
		track.carTrunkName = "Your Car";
		print("You return to your car's trunk.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", "null", track.entranceName, "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			carTrunkRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			carTrunkRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			carTrunkRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			carTrunkRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			carTrunkRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			carTrunkRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void CarTrunk::goNorth(string& currentRoom) {
	cantGoDirection();
}
void CarTrunk::goWest(string& currentRoom) {
	cantGoDirection();
}
void CarTrunk::goSouth(string& currentRoom) {
	currentRoom = "entranceRoom";
}
void CarTrunk::goEast(string& currentRoom) {
	cantGoDirection();
}
void CarTrunk::searchRoom() {
	string nothing;
	system("cls");
	if (!lock.carItems)
	{
		print("There's nothing else to find here");
		print("Only your lint and an old water bottle");
	}
	else
	{
		inventory.collectItem("Crowbar");
		inventory.collectItem("Pizzeria Keys");
		lock.carItems = false;
		print("It's a good thing you checked your car!");
		print("You pick up your crowbar and keys for the pizzeria");
		print("These might be useful for later.");
		print("[+] Crowbar");
		print("[+] Pizzeria Keys");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

#pragma region PizzeriaDoors
void PizzeriaDoors::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	PizzeriaDoors pizzeriaDoorsRoom;
	string input;
	while (currentRoom == "pizzeriaDoors")
	{
		track.pizzeriaDoorsName = "Pizzeria Doors";
		print("At the doors of the rundown Pizzeria building, its sign towering above.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.entranceName, "null", track.frontDeskName, "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			pizzeriaDoorsRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			pizzeriaDoorsRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			pizzeriaDoorsRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			pizzeriaDoorsRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			pizzeriaDoorsRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			pizzeriaDoorsRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void PizzeriaDoors::goNorth(string& currentRoom) {
	currentRoom = "entranceRoom";
}
void PizzeriaDoors::goWest(string& currentRoom) {
	cantGoDirection();
}
void PizzeriaDoors::goSouth(string& currentRoom) {
	string nothing;
	if (lock.frontDoorUnlocked)
	{
		currentRoom = "frontDesk";
	}
	else
	{
		system("cls");
		print("You try the doors, but it's locked.");
		track.frontDeskName = "[*] Front Desk";
		getline(cin, nothing);
	}
}
void PizzeriaDoors::goEast(string& currentRoom) {
	cantGoDirection();
}
void PizzeriaDoors::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "pizzeria keys") && !lock.frontDoorUnlocked) {
		lock.frontDoorUnlocked = true;
		inventory.useItem("pizzeria keys");
		print("You turn the keys, unlocking the doors to the pizzeria.");
		print("[-] Pizzeria Keys");
		track.frontDeskName = "Front Desk";
	}
	else if (inventory.checkForItem(item, "crowbar") && !lock.frontDoorUnlocked) {
		print("As much as you'd love to use your crowbar, you already have the keys for the place.");
	}
	else if (inventory.checkForItem(item, "crowbar"))
	{
		print("There's nothing to pry here, the doors already unlocked.");
	}
	else {
		print("Doesn't seem like you can use these here.");
	}
	getline(cin, nothing);
	system("cls");
}
void PizzeriaDoors::searchRoom() {
	system("cls");
	string nothing;
	print("The sign reads: Freddy's Fazbear Pizzeria");
	if (lock.frontDoorUnlocked)
	{
		print("The nasty door stands ajar, a horrifying aura eminating from inside the pizzeria.");
	}
	else
	{
		print("The doors stand there, rigid and closed, its glass doors dirtied and scratched.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region FrontDesk
void FrontDesk::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	FrontDesk frontDeskRoom;
	string input;
	while (currentRoom == "frontDesk")
	{
		track.frontDeskName = "Front Desk";
		print("You've entered the front desk of the pizzeria.");
		print("This is also where they would order the pizza for their parties.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.pizzeriaDoorsName, track.diningAreaName, "null", "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			frontDeskRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			frontDeskRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			frontDeskRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			frontDeskRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			frontDeskRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			frontDeskRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void FrontDesk::goNorth(string& currentRoom) {
	currentRoom = "pizzeriaDoors";
}
void FrontDesk::goWest(string& currentRoom) {
	currentRoom = "diningArea";
}
void FrontDesk::goSouth(string& currentRoom) {
	cantGoDirection();
}
void FrontDesk::goEast(string& currentRoom) {
	cantGoDirection();
}
void FrontDesk::searchRoom() {
	string nothing;
	system("cls");
	print("Rummaging through the desk, one of the papers catches your eye.");
	print("Some letters of the menu were scribbled on.");
	cout << endl;
	print("=== MENU ===");
	print("1. $4.99 - Cheese  -izza");
	print("2. $5.99 - P-pperoni  Pizza");
	print("3. $5.99 - Sau-age  Pizza");
	print("4. $8.99 - Supreme Pizz-");
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

# pragma region DiningArea
void DiningArea::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	DiningArea diningAreaRoom;
	string input;
	while (currentRoom == "diningArea")
	{
		track.diningAreaName = "Dining Area";
		print("You're at the corner of the major dining room.");
		print("You have many ways you could go from here.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.frontDeskName, track.showStageName, track.diningTablesName, track.bathroomsName);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			diningAreaRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			diningAreaRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			diningAreaRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			diningAreaRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			diningAreaRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			diningAreaRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void DiningArea::goNorth(string& currentRoom) {
	currentRoom = "frontDesk";
}
void DiningArea::goWest(string& currentRoom) {
	currentRoom = "showStage";
}
void DiningArea::goSouth(string& currentRoom) {
	currentRoom = "diningTables";
}
void DiningArea::goEast(string& currentRoom) {
	currentRoom = "bathrooms";
}
void DiningArea::searchRoom() {
	system("cls");
	string nothing;
	if (!lock.flashlightItem)
	{
		print("Besides the balloons, confetti, and party hats literring the floor,");
		print("there's nothing else here to find.");
	}
	else
	{
		print("You almost trip on something cylindrical as you search the corner.");
		if (inventory.checkForItem("Batteries"))
		{
			inventory.useItem("batteries");
			inventory.collectItem("Flashlight");
			print("Picking it up, it turns out to be a flashlight!");
			print("You insert the batteries into the empty flashlight you've found .");
			print("[x] Flashlight  ----->  Flashlight");
		}
		else
		{
			inventory.collectItem("[x] Flashlight");
			print("Picking it up, it turns out to be a flashlight! However, it's missing batteries.");
			print("[+] Flashlight - No Batteries");
		}
		lock.flashlightItem = false;
	}
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

# pragma region DiningTables
void DiningTables::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	DiningTables diningTableRoom;
	string input;
	while (currentRoom == "diningTables")
	{
		track.diningTablesName = "Dining Tables";
		print("You stand in the middle of the dining tables.");
		print("Empty pizza boxes, more confetti, party hats, and paper plates.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.diningAreaName, track.foxysCoveName, track.arcadeName, "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			diningTableRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			diningTableRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			diningTableRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			diningTableRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			diningTableRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			diningTableRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void DiningTables::goNorth(string& currentRoom) {
	currentRoom = "diningArea";
}
void DiningTables::goWest(string& currentRoom) {
	currentRoom = "foxysCove";
}
void DiningTables::goSouth(string& currentRoom) {
	currentRoom = "arcade";
}
void DiningTables::goEast(string& currentRoom) {
	cantGoDirection();
}
void DiningTables::searchRoom() {
	system("cls");
	string nothing;
	print("The pizzas too rotten, so you can't eat those, sadly.");
	print("On one of the tables, you spot a plushie of a yellow bear");
	print("Upon closer inspection, it has a \"0\" written on it's back.");
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

# pragma region ShowStage
void ShowStage::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	ShowStage showStageRoom;
	string input;
	while (currentRoom == "showStage")
	{
		track.showStageName = "Show Stage";
		print("Three huge animatronics stand on stage, inactive and lifeless; Freddy, Bonnie, and Chica.");
		if (lock.controlRoomUnlocked)
		{
			print("With the accessories returned, they once again perform on stage.");
		}
		else
		{
			print("The animatronics seems to be missing an accessory of theirs.");
		}
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.controlRoom, track.backRoom, track.foxysCoveName, track.diningAreaName);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			showStageRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			showStageRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			showStageRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			showStageRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			showStageRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			showStageRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void ShowStage::goNorth(string& currentRoom) {
	if (lock.controlRoomUnlocked)
	{
		currentRoom = "controlRoom";
	}
	else
	{
		string nothing;
		print("You try the door, but it won't open. In fact, you don't see any keyholes!");
		print("However, you did see some wires coming from the door.");
		print("They seem to be attached to the animatronics.");
		track.controlRoom = "[*] Control Room";
		getline(cin, nothing);
	}
}
void ShowStage::goWest(string& currentRoom) {
	if (lock.backRoomUnlocked)
	{
		currentRoom = "backRoom";
	}
	else
	{
		string nothing;
		print("You try the door, but it's locked.");
		track.backRoom = "[*] Backroom Area";
		getline(cin, nothing);
		system("cls");
	}
}
void ShowStage::goSouth(string& currentRoom) {
	currentRoom = "foxysCove";
}
void ShowStage::goEast(string& currentRoom) {
	currentRoom = "diningArea";
}
void ShowStage::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "freddys tophat"))
	{
		inventory.useItem("freddys tophat");
		lock.FreddyAccessory = true;
		print("You return the tophat to Freddy's head.");
		print("[-] Freddy's Tophat");
	}
	else if (inventory.checkForItem(item, "bonnies guitar"))
	{
		inventory.useItem("bonnies guitar");
		lock.BonnieAccessory = true;
		print("You return the guitar to Bonnie's hands.");
		print("[-] Bonnie's Guitar");
	}
	else if (inventory.checkForItem(item, "chicas cupcake"))
	{
		inventory.useItem("chicas cupcake");
		lock.ChicaAccessory = true;
		print("You return the cupcake to Chica's plate.");
		print("[-] Chica's Cupcake");
	}
	else if (inventory.checkForItem(item, "backroom keys") && !lock.backRoomUnlocked) {
		lock.backRoomUnlocked = true;
		inventory.useItem("backroom keys");
		print("You turn the keys, unlocking the doors to the backroom area.");
		print("[-] Backroom Keys");
		track.backRoom = "Backroom Area";
	}
	else
	{
		print("Hm, didn't seem to work.");
	}
	if (lock.FreddyAccessory && lock.BonnieAccessory && lock.ChicaAccessory && lock.FoxyAccessory && !lock.controlRoomUnlocked)
	{
		lock.controlRoomUnlocked = true;
		print("You hear a click coming from the Control Room up north.");
	}
	getline(cin, nothing);
	system("cls");
}
void ShowStage::searchRoom() {
	system("cls");
	string nothing;
	print("As you inspect closer, each animatronic seems to have a number graffitied on them.");
	print("Freddy's body has a 9 on it");
	print("Bonnie's hands has a 3 on it");
	print("Chica's head has a 1 on it");
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region BackRoom
void BackRoom::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	BackRoom backRoom;
	string input;
	while (currentRoom == "backRoom")
	{
		track.backRoom = "Backroom Area";
		print("A restricted area where animatronic parts are stored.");
		print("It's...pretty creepy in here, not gonna lie.");
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", "null", "null", track.showStageName);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			backRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			backRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			backRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			backRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			backRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			backRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void BackRoom::goNorth(string& currentRoom) {
	cantGoDirection();
}
void BackRoom::goWest(string& currentRoom) {
	cantGoDirection();
}
void BackRoom::goSouth(string& currentRoom) {
	cantGoDirection();
}
void BackRoom::goEast(string& currentRoom) {
	currentRoom = "showStage";
}
void BackRoom::searchRoom() {
	system("cls");
	string nothing;
	print("The animatronic heads seem to stare at you...ITS CREEPY!");
	print("But also, they're strangely arranged, as if it was intentional...");
	print("The heads are arranged like so:");
	print("Foxy, Freddy, Chica, Bonnie");
	print("You wonder if that means anything.");
	cout << endl;
	if (!lock.backRoomsBatteries)
	{
		print("You don't want to stay in this room any longer.");
		print("Gives you the chills.");
	}
	else
	{
		print("Lucky you! You find some batteries on one of the tables!");
		if (inventory.checkForItem("[x] flashlight"))
		{
			inventory.useItem("batteries");
			inventory.useItem("[x] flashlight");
			inventory.collectItem("Flashlight");
			print("You insert the batteries you've found into the empty flashlight.");
			print("[-] Flashlight");
			print("[x] Flashlight  ----->  Flashlight");
		}
		else
		{
			inventory.collectItem("Batteries");
			print("Now if you had something to put it in...");
			print("[+] Batteries");
		}
		lock.backRoomsBatteries = false;
	}
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

# pragma region FoxysCove
void FoxysCove::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	FoxysCove foxysCove;
	string input;
	while (currentRoom == "foxysCove")
	{
		track.foxysCoveName = "Foxy's Cove";
		if (lock.FoxyAccessory)
		{
			print("Even with the hook returned, it didn't really move. It was out of order, remember?");
		}
		else
		{
			print("The tall fox animatronic stands on its booth, his hook missing from arms.");
		}
		print("As far as you could remember, he was always out of order.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.showStageName, "null", track.leftHallway, track.diningTablesName);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			foxysCove.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			foxysCove.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			foxysCove.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			foxysCove.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			foxysCove.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			foxysCove.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void FoxysCove::goNorth(string& currentRoom) {
	currentRoom = "showStage";
}
void FoxysCove::goWest(string& currentRoom) {
	cantGoDirection();
}
void FoxysCove::goSouth(string& currentRoom) {
	currentRoom = "leftHallway";
}
void FoxysCove::goEast(string& currentRoom) {
	currentRoom = "diningTables";
}
void FoxysCove::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "foxys hook"))
	{
		inventory.useItem("foxys hook");
		lock.FoxyAccessory = true;
		print("You return the hook to Foxy's hand.");
		print("[-] Foxy's Hook");
	}
	else if (inventory.checkForItem(item, "treasure keys"))
	{
		inventory.useItem("treasure keys");
		inventory.collectItem("Admin Chip");
		lock.foxysTreasure = true;
		print("The treasure box opens, revealing a tiny micro chip.");
		print("I wonder what this is for?");
		print("[-] Treasure Keys");
		print("[+] Admin Chip");
	}
	if (lock.FreddyAccessory && lock.BonnieAccessory && lock.ChicaAccessory && lock.FoxyAccessory && !lock.controlRoomUnlocked)
	{
		lock.controlRoomUnlocked = true;
		print("You hear a click coming from the Control Room up north.");
	}
	getline(cin, nothing);
	system("cls");
}
void FoxysCove::searchRoom() {
	system("cls");
	string nothing;
	print("The number 2 was graffitied onto Foxy's back.");
	print("You can also see a locked treasure box tucked in the back of the cove.");
	print("It'll probably require a special key for me to open it.");
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region Bathrooms
void Bathrooms::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	Bathrooms bathRoom;
	string input;
	while (currentRoom == "bathrooms")
	{
		track.bathroomsName = "Bathroom Hall";
		print("The stagnant and absolutely pungant bathroom hall awaits.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", track.diningAreaName, track.womensBathroom, track.mensBathroom);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			bathRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			bathRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			bathRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			bathRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			bathRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			bathRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void Bathrooms::goNorth(string& currentRoom) {
	cantGoDirection();
}
void Bathrooms::goWest(string& currentRoom) {
	currentRoom = "diningArea";
}
void Bathrooms::goSouth(string& currentRoom) {
	string nothing;
	print("The women's restrooms were buried in rubble.");
	print("You can't find any way across the rubble from here.");
	track.womensBathroom = "[x] Women's Restrooms";
	getline(cin, nothing);
}
void Bathrooms::goEast(string& currentRoom) {
	currentRoom = "mensBathroom";
}
void Bathrooms::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "handkerchief") || inventory.checkForItem(item, "cleaning spray"))
	{
		if (inventory.checkForItem("handkerchief") && inventory.checkForItem("cleaning spray"))
		{
			inventory.useItem("handkerchief");
			inventory.useItem("cleaning spray");
			lock.bathroomClean = true;
			print("You manage to clean the sludge on the walls");
			print("It reveals a message:");
			print("I ALWAYS COME BACK");
			print("You wonder if it's for anything?");
		}
		else if (inventory.checkForItem("cleaning spray"))
		{
			print("You have the spray ready, but you don't have anything to wipe off the sludge.");
		}
		else if (inventory.checkForItem("handkerchief"))
		{
			print("You can't wipe it away with your handkerchief alone!");
		}
	}
	else if (inventory.checkForItem(item, "sledgehammer"))
	{
		print("The sledgehammer won't break these rocks.");
		print("You don't want to collapse the whole building trying either.");
		print("It'd be best to go around this one.");
	}
	else
	{
		print("Hm, didn't seem to work.");
	}
	getline(cin, nothing);
	system("cls");
}
void Bathrooms::searchRoom() {
	system("cls");
	string nothing;
	if (lock.bathroomClean)
	{
		print("Besides the rubble of the womens bathroom, the halls are pretty clean.");
		print("On the spot that you cleaned, the message says:");
		print("I ALWAYS COME BACK");
	}
	else
	{
		print("You notice a spot with unknown sludge on the walls");
		print("You suspect that it's covering something important.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region MensBathroom
void MensBathroom::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	MensBathroom mensBathroom;
	string input;
	while (currentRoom == "mensBathroom")
	{
		track.mensBathroom = "Men's Restrooms";
		print("The men's restrooms; stalls and urinals line one wall, and sinks line the other.");
		print("For a public restroom, it's cleaner than you'd think.");
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", track.bathroomsName, "null", "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			mensBathroom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			mensBathroom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			mensBathroom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			mensBathroom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			mensBathroom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			mensBathroom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void MensBathroom::goNorth(string& currentRoom) {
	cantGoDirection();
}
void MensBathroom::goWest(string& currentRoom) {
	currentRoom = "bathrooms";
}
void MensBathroom::goSouth(string& currentRoom) {
	cantGoDirection();
}
void MensBathroom::goEast(string& currentRoom) {
	cantGoDirection();
}
void MensBathroom::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "crowbar") && !lock.menStallOpen)
	{
		inventory.collectItem("Bonnies Guitar");
		lock.menStallOpen = true;
		print("You pry open one of the stall doors and find an electric guitar");
		print("Maybe this belongs to someone?");
		print("[+] Bonnie's Guitar");
	}
	else if (inventory.checkForItem(item, "crowbar"))
	{
		print("No other stall doors had anything or needed to be pried open.");
	}
	else
	{
		print("Hm, didn't seem to work.");
	}
	getline(cin, nothing);
	system("cls");
}
void MensBathroom::searchRoom() {
	system("cls");
	string nothing;
	if (lock.menStallOpen)
	{
		print("A beautiful row of stalls minus the broken door you pried open.");
		print("Otherwise, there's nothing else to see in this room.");
	}
	else
	{
		print("Going through each stall, one of them seemed to have something inside.");
		print("Unfortunately, it also happened to be the stall that's stuck.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region WomensBathroom
void WomensBathroom::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	WomensBathroom bathRoom;
	string input;
	while (currentRoom == "womensBathroom")
	{
		track.kitchenVents = "Womens Bathroom";
		print("The womens restrooms are about what you expect, stalls and whatnot.");
		print("Although, half of the restrooms are buried in rubble.");
		print("Type help to see all valid commands");
		cout << endl;
		compass("[x] Bathrooms", "null", "null", track.kitchen);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			bathRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			bathRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			bathRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			bathRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			bathRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			bathRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void WomensBathroom::goNorth(string& currentRoom) {
	string nothing;
	print("The entryway is blocked by rubble.");
	print("You can't find any way across the rubble from here.");
	print("Not like it matters, you went through a vent to get here anyways.");
	getline(cin, nothing);
}
void WomensBathroom::goWest(string& currentRoom) {
	cantGoDirection();
}
void WomensBathroom::goSouth(string& currentRoom) {
	cantGoDirection();
}
void WomensBathroom::goEast(string& currentRoom) {
	currentRoom = "kitchen";
}
void WomensBathroom::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "sledgehammer"))
	{
		print("The sledgehammer won't break these rocks.");
		print("You don't want to collapse the whole building trying either.");
		print("It'd be best to go around this one.");
	}
	else
	{
		print("Don't bother.");
	}
	getline(cin, nothing);
	system("cls");
}
void WomensBathroom::searchRoom() {
	system("cls");
	string nothing;
	if (lock.womenBathroomItem)
	{
		inventory.collectItem("Handkerchief");
		print("You notice an unstained handkerchief on the bathroom sink.");
		print("[+] Handkerchief");
	}
	else
	{
		print("Nothing else is notable in the stalls, broken or untouched.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region Arcade
void Arcade::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	Arcade arcadeRoom;
	string input;
	while (currentRoom == "arcade")
	{
		track.arcadeName = "The Arcade";
		print("Arcade machines line the walls adjacent to the security hallways.");
		print("One of the machines seem to be turned on, strangely enough.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.diningTablesName, track.leftHallway, "null", track.rightHallway);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			arcadeRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			arcadeRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			arcadeRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			arcadeRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			arcadeRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			arcadeRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			if (lock.coinInserted && lock.arcadeAdminAccess && !lock.consoleUnlocked)
			{
				string nothing;
				if (digitCheck(input) && input.length() > 4)
				{
					print("The passcode you tried typing was too long.");
				}
				else if (digitCheck(input) && input.length() < 4)
				{
					print("The passcode you tried typing was too short.");
				}
				else if (digitCheck(input) && input.length() == 4)
				{
					if (input == lock.arcadePassword)
					{
						lock.consoleUnlocked = true;
						inventory.collectItem("Foxys Hook");
						print("You hear rattling noises from the arcade machine's compartment.");
						print("You open it, revealing a pirate's hook from within.");
						print("Maybe this belonged to somebody?");
					}
				}
				getline(cin, nothing);
			}
			system("cls");
		}
	}
	system("cls");
}
void Arcade::goNorth(string& currentRoom) {
	currentRoom = "diningTables";
}
void Arcade::goWest(string& currentRoom) {
	currentRoom = "leftHallway";
}
void Arcade::goSouth(string& currentRoom) {
	cantGoDirection();
}
void Arcade::goEast(string& currentRoom) {
	currentRoom = "rightHallway";
}
void Arcade::useItem(string item) {
	string nothing;
	if (lock.consoleUnlocked)
	{
		print("There's nothing left to do here.");
	}
	else if (lock.coinInserted)
	{
		if (inventory.checkForItem(item, "admin chip"))
		{
			lock.arcadeAdminAccess = true;
			print("You reach behind the arcade machine to put in the chip.");
			print("A black console window pops up, abruptly interrupting the gameplay.");
			print("The console line reads: ADMIN MODE - Insert the 4 secret numbers. Ignore the golden plush.");
			print("You'll most likely have to enter those numbers using the numberpad at the bottom of the machine.");
		}
		else
		{
			print("Can't use that here.");
		}
	}
	else if (inventory.checkForItem(item, "fazcoin"))
	{
		lock.coinInserted = true;
		print("You insert the coin into the machine.");
		print("The arcade lights up, a fun retro style platformer featuring the characters.");
		print("The game itself doesn't seem important to your objectives, however.");
	}
	else
	{
		print("Nothing happens.");
	}
	getline(cin, nothing);
	system("cls");
}
void Arcade::searchRoom() {
	system("cls");
	string nothing;
	if (lock.consoleUnlocked)
	{
		print("With the code correctly entered, the machine turns off, joining the other machines.");
		print("You can't find anything else in the machine's compartment.");
	}
	else if (lock.arcadeAdminAccess)
	{
		print("The console line reads: Insert the 4 secret numbers. Ignore the golden plush.");
		print("The console blinker awaits your input of a 4 number code.");
	}
	else if (lock.coinInserted)
	{
		print("While it is tricked into letting you play Freddy in Space forever, it's not important.");
		print("However, you feel this arcade machine *is* special, but how?");
	}
	else
	{
		print("The machine displays it's Title Screen, prompting to Insert a Coin.");
		print("Maybe inserting one will do something?");
	}
	getline(cin, nothing);
	system("cls");
}
bool Arcade::digitCheck(string input)
{
	for (char i : input)
	{
		if (!isdigit(i))
		{
			return false;
		}
	}
	return true;
}
#pragma endregion

# pragma region LeftHallway
void LeftHallway::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	LeftHallway leftHallwayRoom;
	string input;
	while (currentRoom == "leftHallway")
	{
		track.leftHallway = "Left Hallway";
		print("The left hallway of the security office.");
		print("You see cameras down the hallway, probably for the creepy robots on stage.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.foxysCoveName, track.janitorCloset, track.leftDoorway, track.arcadeName);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			leftHallwayRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			leftHallwayRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			leftHallwayRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			leftHallwayRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			leftHallwayRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			leftHallwayRoom.useItem(input);
			system("cls");
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else if (input.length() == 4)
		{
			string nothing;
			if (input == lock.janitorPassword)
			{
				lock.janitorsOpen = true;
				print("The lock clicks, and unlocks the room.");
				track.janitorCloset = "Janitor's Closet";
			}
			else
			{
				print("Nothing happens.");
			}
			getline(cin, nothing);
			system("cls");
		}
		else
		{
			system("cls");
		}
	}
}
void LeftHallway::goNorth(string& currentRoom) {
	currentRoom = "foxysCove";
}
void LeftHallway::goWest(string& currentRoom) {
	if (lock.janitorsOpen)
	{
		currentRoom = "janitorCloset";
	}
	else
	{
		string nothing;
		print("You try the door, but it's locked, and it doesn't seem to accept a key either.");
		track.janitorCloset = "[*] Janitor's Closet";
		getline(cin, nothing);
	}
	system("cls");
}
void LeftHallway::goSouth(string& currentRoom) {
	currentRoom = "leftDoorway";
}
void LeftHallway::goEast(string& currentRoom) {
	currentRoom = "arcade";
}
void LeftHallway::searchRoom() {
	system("cls");
	string nothing;
	if (lock.janitorsOpen)
	{
		print("You don't see anything notable in this spot of the hallway.");
	}
	else
	{
		print("You notice the Janitor's door is locked with a padlock.");
		print("Seems like it accepts a 4 letter password.");
	}
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

#pragma region LeftDoorway
void LeftDoorway::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	LeftDoorway leftDoorway;
	string input;
	while (currentRoom == "leftDoorway")
	{
		track.leftDoorway = "Left Doorway";
		print("You stand at the end of the hallway, near the security office doors.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.leftHallway, "null", "null", track.securityOffice);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			leftDoorway.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			leftDoorway.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			leftDoorway.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			leftDoorway.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			leftDoorway.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			leftDoorway.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void LeftDoorway::goNorth(string& currentRoom) {
	currentRoom = "leftHallway";
}
void LeftDoorway::goWest(string& currentRoom) {
	cantGoDirection();
}
void LeftDoorway::goSouth(string& currentRoom) {
	cantGoDirection();
}
void LeftDoorway::goEast(string& currentRoom) {
	string nothing;
	if (lock.powerOff)
	{
		currentRoom = "securityOffice";
	}
	else
	{
		print("You are blocked by heavy magnetic metal doors.");
		track.securityOffice = "[*] Security Office";
		getline(cin, nothing);
	}
	system("cls");
}
void LeftDoorway::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "crowbar") && !lock.powerOff && lock.officeCoin)
	{
		lock.officeCoin = false;
		inventory.collectItem("FazCoin");
		track.securityOffice = "[*] Security Office";
		print("You manage to pry the doors ajar and make a tiny gap.");
		print("A gap just barely big enough to fit your arm through.");
		print("No matter how strongly you try, the door's magnetics don't allow you to open it any further.");
		print("You jam a random item from nearby and reach your arm through the gap");
		cout << endl;
		print("Swinging your arm aimlessly, all you manage to find in reach is a FazCoin.");
		if (lock.officeHammer)
		{
			print("You might be able to find something else if you did the same on the other side.");
		}
		print("[+] FazCoin");
	}
	else if (inventory.checkForItem(item, "crowbar") && lock.powerOff)
	{
		print("There's nothing to pry; the doors already open.");
	}
	else if (inventory.checkForItem(item, "crowbar"))
	{
		print("You've already opened it the best you can.");
	}
	else
	{
		print("Didn't work.");
	}
	getline(cin, nothing);
	system("cls");
}
void LeftDoorway::searchRoom() {
	system("cls");
	string nothing;
	if (lock.powerOff)
	{
		print("As you suspected, the magnetic doors are released and travel back upwards without power.");
		print("You're free to walk into the office.");
	}
	else
	{
		print("As far as you're concerned, there's no way to get past the heavy magnetic doors by force.");
		print("You might be able to keep it ajar at best, but nowhere in the capacity to be able to enter the office.");
		print("You suspect the doors might be powered by the building's electricity.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region RightHallway
void RightHallway::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	RightHallway rightHallwayRoom;
	string input;
	while (currentRoom == "rightHallway")
	{
		track.rightHallway = "Right Hallway";
		print("The right hallway of the security office.");
		print("Brand and children posters litter the hallway.");
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", track.arcadeName, track.rightDoorway, track.kitchen);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			rightHallwayRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			rightHallwayRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			rightHallwayRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			rightHallwayRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			rightHallwayRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			rightHallwayRoom.useItem(input);
			system("cls");
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else if (input.length() == 4)
		{
			string nothing;
			if (input == lock.janitorPassword)
			{
				lock.janitorsOpen = true;
				print("The lock clicks, and unlocks the room.");
				track.janitorCloset = "Janitor's Closet";
			}
			else
			{
				print("Nothing happens.");
			}
			getline(cin, nothing);
			system("cls");
		}
		else
		{
			system("cls");
		}
	}
}
void RightHallway::goNorth(string& currentRoom) {
	cantGoDirection();
}
void RightHallway::goWest(string& currentRoom) {
	currentRoom = "arcade";
}
void RightHallway::goSouth(string& currentRoom) {
	currentRoom = "rightDoorway";
}
void RightHallway::goEast(string& currentRoom) {
	if (lock.kitchenUnlocked)
	{
		currentRoom = "kitchen";
	}
	else
	{
		string nothing;
		print("You try the door, but it's locked.");
		track.kitchen = "[*] Kitchen";
		getline(cin, nothing);
		system("cls");
	}
}
void RightHallway::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "kitchen keys") && !lock.kitchenUnlocked) {
		lock.kitchenUnlocked = true;
		inventory.useItem("kitchen keys");
		print("You turn the keys, unlocking the kitchen double doors.");
		print("[-] Kitchen Keys");
		track.kitchen = "Kitchen";
	}
	else if (inventory.checkForItem(item, "crowbar") && !lock.kitchenUnlocked) {
		print("I'm gonna break your crowbar if you keep using it for locked doors.");
	}
	else {
		print("Didn't work.");
	}
	getline(cin, nothing);
	system("cls");
}
void RightHallway::searchRoom() {
	system("cls");
	string nothing;
	if (lock.kitchenUnlocked)
	{
		print("The posters are cool, but there's nothing else to see in this hallway.");
	}
	else
	{
		print("It's a standard door lock, and needs a key like any other door.");
	}
	getline(cin, nothing);
	system("cls");
}
# pragma endregion

#pragma region RightDoorway
void RightDoorway::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	RightDoorway rightDoorway;
	string input;
	while (currentRoom == "rightDoorway")
	{
		track.rightDoorway = "Right Doorway";
		print("You stand at the end of the hallway, near the security office doors.");
		print("You brush past the wires that are hanging on the ceiling for some reason.");
		print("Type help to see all valid commands");
		cout << endl;
		compass(track.rightHallway, track.securityOffice, "null", "null");
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			rightDoorway.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			rightDoorway.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			rightDoorway.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			rightDoorway.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			rightDoorway.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			rightDoorway.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void RightDoorway::goNorth(string& currentRoom) {
	currentRoom = "rightHallway";
}
void RightDoorway::goWest(string& currentRoom) {
	string nothing;
	if (lock.powerOff)
	{
		currentRoom = "securityOffice";
	}
	else
	{
		print("You are blocked by heavy magnetic metal doors.");
		track.securityOffice = "[*] Security Office";
		getline(cin, nothing);
	}
	system("cls");
}
void RightDoorway::goSouth(string& currentRoom) {
	cantGoDirection();
}
void RightDoorway::goEast(string& currentRoom) {
	cantGoDirection();
}
void RightDoorway::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "crowbar") && !lock.powerOff && lock.officeHammer)
	{
		lock.officeHammer = false;
		inventory.collectItem("Sledgehammer");
		track.securityOffice = "[*] Security Office";
		print("You manage to pry the doors ajar and make a tiny gap.");
		print("A gap just barely big enough to fit your arm through.");
		print("No matter how strongly you try, the door's magnetics don't allow you to open it any further.");
		print("You jam a random item from nearby and reach your arm through the gap");
		cout << endl;
		print("Swinging your arm aimlessly, all you manage to find in reach is a sledgehammer.");
		if (lock.officeCoin)
		{
			print("You might be able to find something else if you did the same on the other side.");
		}
		print("[+] Sledgehammer");
	}
	else if (inventory.checkForItem(item, "crowbar") && lock.powerOff)
	{
		print("There's nothing to pry; the doors already open.");
	}
	else if (inventory.checkForItem(item, "crowbar"))
	{
		print("You've already opened it the best you can.");
	}
	else
	{
		print("Didn't work.");
	}
	getline(cin, nothing);
	system("cls");
}
void RightDoorway::searchRoom() {
	system("cls");
	string nothing;
	if (lock.powerOff)
	{
		print("As you suspected, the magnetic doors are released and travel back upwards without power.");
		print("You're free to walk into the office.");
	}
	else
	{
		print("As far as you're concerned, there's no way to get past the heavy magnetic doors by force.");
		print("You might be able to keep it ajar at best, but nowhere in the capacity to be able to enter the office.");
		print("You suspect the doors might be powered by the building's electricity.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

# pragma region JanitorsCloset
void JanitorsCloset::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	JanitorsCloset janitorCloset;
	string input;
	while (currentRoom == "janitorCloset")
	{
		print("The closet is crowded with cleaning supplies and only illuminated by one bulb.");
		cout << endl;
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", "null", "null", track.leftHallway);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			janitorCloset.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			janitorCloset.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			janitorCloset.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			janitorCloset.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			janitorCloset.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			system("cls");
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			janitorCloset.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void JanitorsCloset::goNorth(string& currentRoom) {
	cantGoDirection();
}
void JanitorsCloset::goWest(string& currentRoom) {
	cantGoDirection();
}
void JanitorsCloset::goSouth(string& currentRoom) {
	cantGoDirection();
}
void JanitorsCloset::goEast(string& currentRoom) {
	currentRoom = "leftHallway";
}
void JanitorsCloset::useItem(string item) {
	string nothing;
	if (inventory.checkForItem(item, "sledgehammer") && !lock.janitorsBroken)
	{
		inventory.collectItem("Treasure Keys");
		lock.janitorsBroken = true;
		print("You shatter the pirate-themed glass box, revealing the decorated key inside.");
		print("The foxy motif made itself very clear on the key.");
		print("[+] Treasure Keys");
	}
	else if (inventory.checkForItem(item, "crowbar"))
	{
		print("Your crowbar isn't strong enough to shatter the glass. There's nothing to pry either.");
	}
	else
	{
		print("That didn't seem to work.");
	}
	getline(cin, nothing);
	system("cls");
}
void JanitorsCloset::searchRoom() {
	system("cls");
	string nothing;
	if (lock.janitorsBroken)
	{
		print("Broken glass scatter the floor from the broken pirates box on the wall.");
	}
	else
	{
		print("A pirate-themed glass case hangs on the wall, protecting an equally decorated pirate key.");
	}
	cout << endl;
	if (lock.janitorsItem)
	{
		inventory.collectItem("Cleaning Spray");
		inventory.collectItem("Kitchen Keys");
		inventory.collectItem("Backroom Keys");
		lock.janitorsItem = false;
		print("You find a usable spray bottle with cleaning solution.");
		print("You also see keys hung up on the wall. Only 2 keys remain, however.");
		print("[+] Cleaning Spray");
		print("[+] Kitchen Keys");
		print("[+] Backroom Keys");
	}
	else
	{
		print("Expired or empty cleaning products line the closet shelves.");
		print("The key racks were also empty; it seemed like the janitor had keys for every room.");
		print("It's a shame there were only 2 left.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

#pragma region Kitchen
void Kitchen::inRoomLogic(string& currentRoom) {
	stringUtil stringFunc;
	Kitchen kitchenRoom;
	string input;
	while (currentRoom == "kitchen")
	{
		track.kitchen = "Kitchen";
		print("This is where the magic comes from: the kitchen.");
		print("Pizza was the other main part of the entertainment, surely it must be good right?");
		print("Type help to see all valid commands");
		cout << endl;
		compass("null", track.rightHallway, "null", track.kitchenVents);
		getline(cin, input);
		stringFunc.toLower(input);
		cout << endl;
		system("cls");
		if (stringFunc.boolFind(input, "help")) {
			HelpCommand();
			continue;
		}
		else if (stringFunc.boolFind(input, "search")) {
			kitchenRoom.searchRoom();
			continue;
		}
		else if (stringFunc.boolFind(input, "north")) {
			kitchenRoom.goNorth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "west")) {
			kitchenRoom.goWest(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "south")) {
			kitchenRoom.goSouth(currentRoom);
			break;
		}
		else if (stringFunc.boolFind(input, "east")) {
			kitchenRoom.goEast(currentRoom);
			continue;
		}
		else if (stringFunc.boolFind(input, "use")) {
			string itemString;
			stringUtil stringFunc;
			input = stringFunc.replace(input, "use", " ");
			kitchenRoom.useItem(input);
		}
		else if (stringFunc.boolFind(input, "inventory")) {
			inventory.checkInventory();
			continue;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}
void Kitchen::goNorth(string& currentRoom) {
	cantGoDirection();
}
void Kitchen::goWest(string& currentRoom) {
	currentRoom = "rightHallway";
}
void Kitchen::goSouth(string& currentRoom) {
	cantGoDirection();
}
void Kitchen::goEast(string& currentRoom) {
	if (lock.ventOpen)
	{
		currentRoom = "womensBathroom";
		track.kitchenVents = "Womens Bathroom";
	}
	else
	{
		string nothing;
		print("The vent cover blocks you, although the vent itself is spacious enough for you to crawl through.");
		print("If you get the cover off first, of course.");
		track.kitchenVents = "[*] Vents";
		getline(cin, nothing);
		system("cls");
	}
}
void Kitchen::useItem(string item)
{
	string nothing;
	if (inventory.checkForItem(item, "crowbar") && !lock.ventOpen)
	{
		lock.ventOpen = true;
		track.kitchenVents = "Vents";
		print("Fuck yeah.");
		print("You pry open the vents, letting (nasty) air flow better! Also you can crawl in there now.");
	}
	else
	{
		print("Doesn't work here.");
	}
	getline(cin, nothing);
	system("cls");
}
void Kitchen::searchRoom() {
	string nothing;
	system("cls");
	print("Empty pizza boxes, pizza cutters, rotten ingredients.");
	if (lock.kitchenItem)
	{
		lock.kitchenItem = false;
		inventory.collectItem("Chicas Cupcake");
		print("Out of those, you notice an outlier; a plastic cupcake.");
		print("Maybe this belonged to someone?");
		print("[+] Chica's Cupcake");
	}
	cout << endl;
	if (!lock.ventOpen)
	{
		print("You notice the loose vent cover on the weirdly crawable vent space.");
		print("Not loose enough that you can pull it off by hand...");
	}
	else
	{
		print("Flowing air flows through the open vent space.");
	}
	getline(cin, nothing);
	system("cls");
}
#pragma endregion

void Inventory::collectItem(string newItem) {
	for (int i = 0; i < 15; i++)
	{
		if (Items[i].empty() || Items[i] == " ")
		{
			Items[i] = newItem;
			break;
		}
	}
}
void Inventory::useItem(string Item) {
	stringUtil stringFunc;
	stringFunc.toLower(Item);
	Item = stringFunc.removeSpaces(Item);
	for (int i = 0; i != Item.length(); i++)
	{
		string tempVar = Items[i];
		stringFunc.toLower(tempVar);
		tempVar = stringFunc.removeSpaces(tempVar);
		if (tempVar == Item)
		{
			Items[i] = " ";
		}
		if (Items[i + 1] != " " && Items[i] == " ")
		{
			Items[i] = Items[i + 1];
			Items[i + 1] = " ";
		}
	}
}
bool Inventory::checkForItem(string item) {
	stringUtil stringFunc;
	for (string a : Items)
	{
		string tempVar = a;
		stringFunc.toLower(tempVar);
		if (tempVar == item)
		{
			return true;
		}
	}
	return false;
}
bool Inventory::checkForItem(string typedItem, string requiredItem) {
	stringUtil stringFunc;
	for (string a : Items)
	{
		string tempVar = a;
		stringFunc.toLower(tempVar);
		tempVar = stringFunc.removeSpaces(tempVar);
		typedItem = stringFunc.removeSpaces(typedItem);
		requiredItem = stringFunc.removeSpaces(requiredItem);
		if (tempVar == typedItem)
		{
			if (tempVar == requiredItem)
			{
				return true;
			}
		}
	}
	return false;
}
void Inventory::checkInventory() {
	system("cls");
	print("===== Inventory =====");
	for (int i = 0; i < 15; i++) {
		cout << "[" << i+1 << "] ";
		if (!Items[i].empty())
		{
			print(Items[i]);
		}
		else { cout << endl; }
	}
	cout << endl;
}
void compass(string nameNorth, string nameWest, string nameSouth, string nameEast)
{
	// complicated processing to generate the compass ui
	int compassHoriLength = 10;
	int WestLength;
	if (nameWest == "null") { WestLength = 0; }
	else { WestLength = nameWest.length(); }
	for (int i = 0; i != WestLength + compassHoriLength - (nameNorth.length() / 2) + 1; i++) { cout << " "; }
	if (nameNorth != "null") { print(nameNorth); }
	else { cout << endl; }
	for (int i = 0; i != WestLength + compassHoriLength + 1; i++) { cout << " "; } print("/\\");
	for (int i = 0; i != WestLength + compassHoriLength + 1; i++) { cout << " "; } print("||");
	if (nameWest != "null") { cout << nameWest; }
	cout << " < ======= -- ======= > ";
	if (nameEast != "null") { print(nameEast); }
	else { cout << endl; }
	for (int i = 0; i != WestLength + compassHoriLength + 1; i++) { cout << " "; } print("||");
	for (int i = 0; i != WestLength + compassHoriLength + 1; i++) { cout << " "; } print("\\/");
	for (int i = 0; i != WestLength + compassHoriLength - (nameSouth.length() / 2) + 1; i++) { cout << " "; }
	if (nameSouth != "null") { print(nameSouth); }
	else { cout << endl; }
}
void HelpCommand() {
	system("cls");
	print("north --- Travel North (if possible)");
	print("west --- Travel West (if possible)");
	print("south --- Travel South (if possible)");
	print("east --- Travel East (if possible)");
	print("search --- Search the room");
	print("use [item] --- Use an item that's in your inventory");
	print("inventory --- Shows your current inventory");
	cout << endl;
}
# pragma endregion