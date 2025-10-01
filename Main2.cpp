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
	string currentRoom = "entranceRoom";
	bool gameLoop = true;
	/*printAndWait(2, "September, 2003");
	printAndWait(4, "20 years since the opening of the now foreclosed Freddy's Fazbears Pizza");
	printAndWait(4.5f, "You've been tasked to investigate the unresolved case of the five missing children");
	printAndWait(3.5f, "You drive up to the abandoned Pizzeria establishment");
	system("cls");*/
	while (gameLoop) {
		entranceRoom.inRoomLogic(currentRoom);
		carTrunkRoom.inRoomLogic(currentRoom);
		pizzeriaDoorsRoom.inRoomLogic(currentRoom);
		frontDeskRoom.inRoomLogic(currentRoom);
		diningArea.inRoomLogic(currentRoom);
	}

}