#include <iostream>;
#include <string>;
#include <stdlib.h>;
#include <windows.h>;
#include "Header.h";
using namespace std;


// escape room bitches
int main()
{
	Entrance entranceRoom;
	CarTrunk carTrunkRoom;
	PizzeriaDoors pizzeriaDoorsRoom;
	FrontDesk frontDeskRoom;
	DiningArea diningArea;
	DiningTables diningTable;
	ShowStage showStage;
	BackRoom backroomArea;
	FoxysCove foxysCove;
	Bathrooms bathroomHall;
	MensBathroom mensRestroom;
	WomensBathroom womensRestroom;
	Arcade arcadeRoom;
	LeftHallway lefthall;
	LeftDoorway leftdoor;
	RightHallway righthall;
	RightDoorway rightdoor;
	Kitchen kitchenRoom;
	JanitorsCloset janitorsCloset;
	ControlRoom controlRoom;
	SecurityOffice office;
	string currentRoom = "entranceRoom";
	bool gameLoop = true;
	string nada;
	print("September, 2003");
	getline(cin, nada);
	print("20 years since the opening of the now foreclosed Freddy's Fazbears Pizza");
	getline(cin, nada);
	print("You've been tasked to investigate the unresolved case of the five missing children");
	getline(cin, nada);
	print("You drive up to the abandoned Pizzeria establishment");
	getline(cin, nada);
	print("(I'm no writer or whatever so you're supposed to get like lore bits throughout the game)");
	getline(cin, nada);
	print("You won't tho");
	getline(cin, nada);
	system("cls");
	while (gameLoop) {
		entranceRoom.inRoomLogic(currentRoom);
		carTrunkRoom.inRoomLogic(currentRoom);
		pizzeriaDoorsRoom.inRoomLogic(currentRoom);
		frontDeskRoom.inRoomLogic(currentRoom);
		diningArea.inRoomLogic(currentRoom);
		diningTable.inRoomLogic(currentRoom);
		showStage.inRoomLogic(currentRoom);
		backroomArea.inRoomLogic(currentRoom);
		foxysCove.inRoomLogic(currentRoom);
		bathroomHall.inRoomLogic(currentRoom);
		mensRestroom.inRoomLogic(currentRoom);
		womensRestroom.inRoomLogic(currentRoom);
		arcadeRoom.inRoomLogic(currentRoom);
		lefthall.inRoomLogic(currentRoom);
		leftdoor.inRoomLogic(currentRoom);
		righthall.inRoomLogic(currentRoom);
		rightdoor.inRoomLogic(currentRoom);
		kitchenRoom.inRoomLogic(currentRoom);
		janitorsCloset.inRoomLogic(currentRoom);
		controlRoom.inRoomLogic(currentRoom);
		office.inRoomLogic(currentRoom);
		if (currentRoom == "secretRoom")
		{
			gameLoop = false;
		}
	}
	print("If I were a Game Designer or Writer there would be some big reveal here");
	print("Unfortunately, I'm not. In fact, there should've been lore pieces scattered around the game.");
	print("It'd be some dope ass worldbuilding, right? Oh well, this is the best you're gonna get in a console.");
	print("Thank you for fully completing my game ^^");
}