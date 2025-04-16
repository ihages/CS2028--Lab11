#include<iostream>
#include "Graph.h"
#include "Room.h"

MatrixGraph<Room> gameMap(20);

int main() {
	
	gameMap.generateMap(); //generates map with 20 vertices
	int playerRoom = 0; //player starts in room 1
	int wumpusRoom = rand() % 18 + 2; //randomly generates wumpus room

    std::cout << "\tHunt the Wumpus!" << std::endl;
    int choice = 1;
    while (choice) {
        std::cout << "*****************************" << std::endl;
        std::cout << "Choose one of the following options:\n1: Observe Room\n2: Move Room\n3: Shoot Arrow\n4. Quit" << std::endl;
        std::cin >> choice;
        //menu system 
        switch (choice) {
        case 1: {
            //observe
            break;
        }

        case 2: {
            //move
			std::cout << "You are in room " << playerRoom + 1 << std::endl;
			std::cout << "These are the rooms next to you:" << std::endl;
            for (int i = 0; i < gameMap.neighborRooms(playerRoom); i++) {
                std::cout << gameMap.returnNeighbors(playerRoom)[i] << " " << std::endl;
            }
			std::cout << "Which room would you like to move to?" << std::endl;
			int moveRoom;
			std::cin >> moveRoom;
            if (gameMap.hasEdge(playerRoom, moveRoom - 1)) {
                playerRoom = moveRoom - 1;
				std::cout << "You have moved to room " << playerRoom + 1 << std::endl;
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
			for (int i = 0; i < gameMap.neighborRooms(playerRoom); i++) {
                std::cout << gameMap.returnNeighbors(playerRoom)[i] << " " << std::endl;
			}
        }
        }//switch end
    }//while end
}//main end

