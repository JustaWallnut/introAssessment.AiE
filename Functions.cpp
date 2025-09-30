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
	printAndWait(3, "There's nowhere to go in this direction!");
}
void Rooms::useItem(string item) {
	printAndWait(2.5, "Hm, didn't seem to work.");
}
void Rooms::searchRoom() {

}

# pragma region Entrance
// Parking Lot
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
			cout << endl;
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
	print("In the dark of night, it's hard to find anything out here");
	printAndWait(6.5, "At the very least, you should try to approach the pizzeria");
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
	system("cls");
	if (inventory.checkForItem("Crowbar") && inventory.checkForItem("Pizzeria Keys"))
	{
		print("There's nothing else to find here");
		printAndWait(4, "Only your lint and an old water bottle");
	}
	else
	{
		inventory.collectItem("Crowbar");
		inventory.collectItem("Pizzeria Keys");
		print("It's a good thing you checked your car!");
		print("You pick up your crowbar and pizzeria keys from your car");
		printAndWait(7.5, "Can't explore without these!");
	}
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
	if (lock.frontDoorUnlocked)
	{
		currentRoom = "frontDesk";
	}
	else
	{
		system("cls");
		printAndWait(4, "You try the front doors, but it seems to be locked.");
	}
}
void PizzeriaDoors::goEast(string& currentRoom) {
	cantGoDirection();
}
void PizzeriaDoors::useItem(string item) {
	if (inventory.checkForItem(item, "pizzeria keys")) {
		lock.frontDoorUnlocked = true;
		inventory.useItem("pizzeria keys");
		printAndWait(4, "You turn the keys, unlocking the doors to the pizzeria.");
	}
	else if (inventory.checkForItem(item, "crowbar")) {
		printAndWait(4, "As much as you'd love to use your crowbar, you'd rather save it for later.");
	}
	else {
		printAndWait(2.5, "Doesn't seem like you can use these here.");
	}
	system("cls");
}
void PizzeriaDoors::searchRoom() {
	system("cls");
	print("The sign reads: Freddy's Fazbear Pizzeria");
	if (lock.frontDoorUnlocked)
	{
		printAndWait(4.5, "The nasty door stands ajar, a horrifying aura eminating from inside the pizzeria.");
	}
	else
	{
		printAndWait(4.5, "The doors stand there, rigid and closed, its glass doors dirtied and scratched.");
	}
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
			cout << endl;
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
	system("cls");
	print("Rummaging through the desk, you can't find anything useful.");
	printAndWait(6.5, "Just old paperwork, office supplies, and an empty cash register.");
	system("cls");
}
# pragma endregion

void Inventory::collectItem(string newItem) {
	for (int i = 0; i < 10; i++)
	{
		if (Items[i].empty())
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
			Items[i] = "";
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
	for (int i = 0; i < 10; i++) {
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
	for (int i = 0; i != WestLength + compassHoriLength - (nameNorth.length() / 2); i++) { cout << " "; }
	if (nameNorth != "null") { print(nameNorth); }
	else { cout << endl; }
	for (int i = 0; i != WestLength + compassHoriLength; i++) { cout << " "; } print("/\\");
	for (int i = 0; i != WestLength + compassHoriLength; i++) { cout << " "; } print("||");
	if (nameWest != "null") { cout << nameWest; }
	print("< ======= -- ======= >");
	if (nameEast != "null") { print(nameEast); }
	for (int i = 0; i != WestLength + compassHoriLength; i++) { cout << " "; } print("||");
	for (int i = 0; i != WestLength + compassHoriLength; i++) { cout << " "; } print("\\/");
	for (int i = 0; i != WestLength + compassHoriLength - (nameSouth.length() / 2); i++) { cout << " "; }
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