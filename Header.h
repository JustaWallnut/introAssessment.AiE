#pragma once
#include <iostream>;


using namespace std;

void print(string msg);
void printAndWait(float seconds, string msg);

class stringUtil {
	public:
		int length(string msg);
		char charAt(string msg, int index);
		bool equalTo(string msg1, string msg2);
		void equalTo(string msg1, string msg2, string yesmsg, string nomsg);
		void append(string& msg, string append);
		void prepend(string& msg1, string append);
		void toUpper(string& msg);
		void toLower(string& msg);
		int find(string msg, string findString);
		bool boolFind(string msg, string findString);
		int find(int index, string msg, string findString);
		string replace(string msg, string findString, string replaceString);
		string removeSpaces(string msg);
		string ReadFromConsole();
		void WriteToConsole(string msg);
};

class stringTestUtil {
	private:
		int totalSucceed = 0;
		int total = 0;
	public:
		void testLength();
		void testCharAt();
		void testEqualTo1();
		/*void testEqualTo2();*/
		void testAppend();
		void testPrepend();
		void testtoUpper();
		void testtoLower();
		void testFind1();
		void testFind2();
		void testReplace();
		void testResults();
		/*void testReadFromConsole();*/
		/*void testWriteToConsole();*/
};

class fileHandle {
	public:
		bool fileExists(string filename);
		void appendToLogFile(string msg, bool result);
};
void runAllTests();

class Rooms {
	public:
		virtual void inRoomLogic(string& currentRoom) = 0;
		void cantGoDirection();
		virtual void goNorth(string &currentRoom) = 0;
		virtual void goWest(string& currentRoom) = 0;
		virtual void goSouth(string& currentRoom) = 0;
		virtual void goEast(string& currentRoom) = 0;
		virtual void useItem(string item);
		virtual void searchRoom();
};
class Entrance : public Rooms {
	public:
		void inRoomLogic(string &currentRoom) override;
		void goNorth(string &currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void searchRoom() override;
};
class CarTrunk : public Rooms {
	public:
		void inRoomLogic(string &currentRoom) override;
		void goNorth(string& currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void searchRoom() override;
};
class PizzeriaDoors : public Rooms {
	public:
		void inRoomLogic(string& currentRoom) override;
		void goNorth(string& currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void useItem(string item) override;
		void searchRoom() override;
};
class FrontDesk : public Rooms {
	public:
		void inRoomLogic(string& currentRoom) override;
		void goNorth(string& currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void searchRoom() override;
};
class DiningArea : public Rooms {
	public:
		void inRoomLogic(string& currentRoom) override;
		void goNorth(string& currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void searchRoom() override;
};

class Inventory {
	private:
		string Items[10];
	public:
		void collectItem(string newItem);
		void useItem(string Item);
		bool checkForItem(string item);
		bool checkForItem(string typedItem, string requiredItem);
		void checkInventory();
};
struct Locks
{
	bool frontDoorUnlocked = false;
};
struct RoomsVisited {
	string entranceName = "???";
	string carTrunkName = "???";
	string pizzeriaDoorsName = "???";
	string frontDeskName = "???";
	string diningAreaName = "???";
	string showStageName = "???";
	string diningTablesName = "???";
	string bathroomsName = "???";
};
void compass(string nameNorth, string nameWest, string nameSouth, string nameEast);
void HelpCommand();