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
class DiningTables : public Rooms {
	public:
		void inRoomLogic(string& currentRoom) override;
		void goNorth(string& currentRoom) override;
		void goWest(string& currentRoom) override;
		void goSouth(string& currentRoom) override;
		void goEast(string& currentRoom) override;
		void searchRoom() override;
};
class ShowStage : public Rooms {
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
	bool backRoomUnlocked = false;
	bool controlRoomUnlocked = false;
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
	string arcadeName = "???";
	string foxysCoveName = "???";
	string controlRoom = "???";
	string backRoom = "???";
};
void compass(string nameNorth, string nameWest, string nameSouth, string nameEast);
void HelpCommand();

//yes
//Frozen stairs, carpet in blood red
//Seating goodbyes left unsaid, goodbyes left unsaid
//Despite our promises, here I am following your steps
//I’m following your steps
//
//Drop by drop
//As your unchanging reality dampen my sleeve
//You kissed them off
//Through the fibers of my handkerchief
//
//I am fire
//Burn those who dare to care for me
//And my fuel are memories, fuel are memories of you
//They perish with the heat, perish with the heat
//So I can move on
//Flower of iron
//Shrivelled up to hide the imposter in me
//“Hey, why did you leave ? Why did you leave ? ”
//Don’t let those words out of me
//Imposter’s about to speak
//So I chewed on Huameitang
//
//For whom the shelves hold on to the pages, hold on to the pages
//Their pain, their joy were given value as they were rated
//Isn’t it ironic ?
//Greed is unlimited; freedom is a limited resource
//Extra large for you means less for me
//There’ll be less for me
//
//I banged the drums
//(Weiwu…)
//Court of hell
//(Weiwu…)
//Demanding a new trial
//(Weiwu…)
//You got the wrong head
//Would you take mine instead, take mine instead ?
//Stop leading me on
//
//World of titan allows me to live
//Only in the mud down its feet
//Though you’re not with me, you’re not with me
//I’ll never admit defeat
//Cause when I thought that every nice thing about me has become Canxiang
//You showed me I still had an umbrella full of love inside me
//Without you I could never be
//So sincerely thank you for everything
//It pains me to think
//That my happiness turned out to be one of those fingers that strangled you until you couldn’t breathe
//Not ashamed to go this way
//I just want to choose my fate
//I’m on my last white rabbit Naitang
//
//I am iron
//In my blood it streams roots deep
//With bruises on my knees, bruises on my knees
//And ribs crushed down to pieces, crushed down to pieces
//Nothing left to hold on
//Actually wait
//I do have one regret
//That day before you left me
//“You’re my everything”
//Before my thoughts began to speak
//I bit my lip, said nothing
//And just sucked on Maiyatang