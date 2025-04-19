#include <iostream>
#include <ctime>
#include "Graph.h"
#include "Room.h"

MatrixGraph<Room> gameMap(20);

void enterBatsRoom(Room &playerRoom);
void enterPitRoom();
void enterWumpusRoom(Room &playerRoom);

int main() {
    srand(time(0));
	
	gameMap.generateMap(); //generates map with 20 vertices

    Room playerRoom = gameMap.getVertexData(0);
    playerRoom.visitRoom();

    for (int i{}; i < 20; i++) {
        Room curRoom = gameMap.getVertexData(i);
        if (!curRoom.isRoomEmpty()) {
            std::cout << curRoom.getRoomNumber() << ": " << curRoom.getRoomType() << std::endl;
        }
    }

	int wumpusRoom = rand() % 18 + 2; //randomly generates wumpus room

    std::cout << "\tHunt the Wumpus!" << std::endl;
    int choice = 1;
    while (choice) {
        std::cout << "*****************************" << std::endl;
        std::cout << "You are in room " << playerRoom.getRoomNumber() << std::endl;
        std::cout << "Choose one of the following options:\n1: Observe Room\n2: Move Room\n3: Shoot Arrow\n4. Quit" << std::endl;
        std::cin >> choice;
        //menu system 
        switch (choice) {
        case 1: {
            //observe
            std::cout << "These are the rooms next to you:" << std::endl;
            for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomNumber()); i++) {
                std::cout << gameMap.returnNeighbors(playerRoom.getRoomNumber() - 1)[i] << std::endl;
            }
            for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomNumber()); i++) {
                Room curRoom = gameMap.getVertexData(gameMap.returnNeighbors(playerRoom.getRoomNumber() - 1)[i] - 1);
                if (!curRoom.isRoomEmpty()) {
                    std::cout << curRoom.roomMessage() << std::endl;
                }
            }
            break;
        }
        case 2: {
            //move
			std::cout << "Which room would you like to move to?" << std::endl;
			int moveRoom;
			std::cin >> moveRoom;
            if (gameMap.hasEdge(playerRoom.getRoomNumber(), moveRoom)) {
                playerRoom = gameMap.getVertexData(moveRoom - 1);
                playerRoom.visitRoom();
                if (playerRoom.getRoomType() == "Bats") {
                    enterBatsRoom(playerRoom);
                    playerRoom.visitRoom();
                } else if (playerRoom.getRoomType() == "Pit") {
                    enterPitRoom();
                    return 0;
                } else if (playerRoom.getRoomType() == "Wumpus") {
                    enterWumpusRoom(playerRoom);
                } else {
                    std::cout << "You have moved to room " << playerRoom.getRoomNumber() << std::endl;
                }
                //make it so that it marks the previous player room as visited and you cannot return to it. update the if/else and print to account for it
                //add in the room conditions here
			}
			else {
				std::cout << "You cannot move to that room!" << std::endl;
			}
            break;
        }
        case 3: {
            //shoot
            break;
        }
        case 4: {
            //quit
            return 0;
            break;
        }
        case 5: { //secret unit test
            std::cout << "Here is the matrix:" << std::endl;
            gameMap.printMatrix(); //prints for sake of testing
			std::cout << "\nThese are the rooms next to the player at spawn:" << std::endl;
			for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomNumber()); i++) {
                std::cout << gameMap.returnNeighbors(playerRoom.getRoomNumber())[i] << " " << std::endl;
			}

        }
        }//switch end
    }//while end
}//main end


void enterBatsRoom(Room &playerRoom) {
    std::cout << "Oh no! You entered a room full of bats!" << std::endl;
    std::cout << "The bats disorient you sending you in a random direction..." << std::endl;
    int randRoom = rand() % gameMap.numNeighborRooms(playerRoom.getRoomNumber() - 1);
    playerRoom = gameMap.getVertexData(gameMap.returnNeighbors(playerRoom.getRoomNumber())[randRoom]);
}

void enterPitRoom() {
    std::cout << "Oh no! You entered a room with a pit..." << std::endl;
    std::cout << "You fell into the pit!" << std::endl;
    std::cout << "Game Over :(" << std::endl;
}

void enterWumpusRoom(Room &playerRoom) {
    std::cout << "You entered the room with the Wumpus!" << std::endl;
}