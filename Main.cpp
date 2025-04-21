#include <iostream>
#include <ctime>
#include "Graph.h"
#include "Room.h"

MatrixGraph<Room> gameMap(20);

void enterBatsRoom(Room &playerRoom);
void enterPitRoom();
void enterWumpusRoom(Room &playerRoom, int playerQuiver);
bool shootArrow(int distance, int playerRoomIndex, int& arrows);


int main() {
    srand(time(0));
	
	gameMap.generateMap(); //generates map with 20 vertices

    Room &startingRoom = gameMap.getVertexData(0);
    startingRoom.visitRoom();
    Room playerRoom = startingRoom;

    int playerQuiver = 3;


    std::cout << "\tHunt the Wumpus!" << std::endl;
    int choice = 1;
    while (choice) {
        std::cout << "*****************************" << std::endl;
        /*for (int i{}; i < 20; i++) {   //Show location of hazards TESTING
            Room curRoom = gameMap.getVertexData(i);
            if (!curRoom.isRoomEmpty()) {
                std::cout << curRoom.getRoomNumber() << ": " << curRoom.getRoomType() << std::endl;
            }
        }*/
        std::cout << "You are in room " << playerRoom.getRoomNumber() << std::endl;
        std::cout << "You have " << playerQuiver << " arrows in your quiver." << std::endl;
        std::cout << "Choose one of the following options:\n1: Observe Room\n2: Move Room\n3: Shoot Arrow\n4. Quit" << std::endl;
        std::cin >> choice;
        //menu system 
        switch (choice) {
        case 1: {
            //observe
            std::cout << "These are the rooms next to you:" << std::endl;
            for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomIndex()); i++) {    //Print neighboring room numbers
                Room curRoom = gameMap.getVertexData(gameMap.returnNeighbors(playerRoom.getRoomIndex())[i] - 1);
                std::cout << gameMap.returnNeighbors(playerRoom.getRoomIndex())[i];
                if (curRoom.isVisited()) {  //Check if room is visited
                    std::cout << " (Visited)";
                }
                std::cout << std::endl;
            }
            for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomIndex()); i++) {    //Print room messages
                Room curRoom = gameMap.getVertexData(gameMap.returnNeighbors(playerRoom.getRoomIndex())[i] - 1);
                if (!curRoom.isRoomEmpty()) {
                    std::cout << curRoom.roomMessage() << std::endl;
                }
            }
            break;
        }
        case 2: {
            //move
            playerRoom.visitRoom();
			std::cout << "Which room would you like to move to?" << std::endl;
			int moveRoom;
			std::cin >> moveRoom;
            if (gameMap.hasEdge(playerRoom.getRoomNumber(), moveRoom)) {    //Check if room is a valid move
                Room &nextRoom = gameMap.getVertexData(moveRoom - 1);
                nextRoom.visitRoom();
                playerRoom = nextRoom;

                //Check if new room is a hazard room
                if (playerRoom.getRoomType() == "Bats") {   //Check if entering Bats room
                    enterBatsRoom(playerRoom);
                    
                    // Check if the new room has hazards
                    if (playerRoom.getRoomType() == "Pit") {
                        enterPitRoom();
                        return 0;  // Game over
                    } else if (playerRoom.getRoomType() == "Wumpus") {
                        enterWumpusRoom(playerRoom, playerQuiver);
                        return 0;  // Game over
                    }
                } else if (playerRoom.getRoomType() == "Pit") { //Check if entering Pit room
                    enterPitRoom();
                    return 0;
                } else if (playerRoom.getRoomType() == "Wumpus") {  //Check if entering Wumpus room
                    enterWumpusRoom(playerRoom, playerQuiver);
                    return 0;
                } else {    //Didnt enter a hazard room
                    std::cout << "You have moved to room " << playerRoom.getRoomNumber() << std::endl;
                    if (playerRoom.isArrowHere()) {
                        Room& tempRoom = gameMap.getVertexData(playerRoom.getRoomIndex());
                        std::cout << "You found an arrow!" << std::endl;
                        tempRoom.pickupArrow();
                        playerQuiver++;
                        playerRoom = tempRoom;
                    }
                }
			}
			else {
				std::cout << "You cannot move to that room!" << std::endl;
			}
            break;
        }
        case 3: {
            // Shoot arrow
            if (playerQuiver < 1) {
                std::cout << "You cannot shoot you are out of arrows." << std::endl;
                break;
            }
            
            int distance = 0;
            std::cout << "How far would you like to shoot the arrow? (2 - 4 rooms)" << std::endl;
            std::cin >> distance;
            
            // Fix the condition to use correct comparison for valid range
            while (distance < 2 || distance > 4) {
                std::cout << "Please enter a valid input between 2 and 4." << std::endl;
                std::cin >> distance;
            }
            
            // Call the function that handles both arrow shooting and wumpus movement
            bool hitWumpus = shootArrow(distance, playerRoom.getRoomIndex(), playerQuiver);
            if (hitWumpus) {
                return 0; // Game over, player wins
            }
            
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
			for (int i = 0; i < gameMap.numNeighborRooms(playerRoom.getRoomIndex()); i++) {    //Print game map
                std::cout << gameMap.returnNeighbors(playerRoom.getRoomIndex())[i] << " " << std::endl;
			}
            std::cout << "\nLocation of the different hazards:" << std::endl;
            for (int i{0}; i < 20; i++) {    //Show location of hazards
                Room curRoom = gameMap.getVertexData(i);
                if (!curRoom.isRoomEmpty()) {
                    std::cout << curRoom.getRoomNumber() << ": " << curRoom.getRoomType() << std::endl;
                }
            }
			std::cout << "\nThese are the rooms that have been visited:" << std::endl;
            for (int i{0}; i < 20; i++) {
				Room tempRoom = gameMap.getVertexData(i);
                std::cout << tempRoom.getRoomNumber() << ": " << tempRoom.getVisited() << std::endl;
			}
            std::cout << "\nThese are the rooms that have arrows:" << std::endl;
            for (int i{ 0 }; i < 20; i++) {
                Room tempRoom = gameMap.getVertexData(i);
                std::cout << tempRoom.getRoomNumber() << ": " << tempRoom.isArrowHere() << std::endl;
            }

        }
        }//switch end
    }//while end
}//main end


void enterBatsRoom(Room &playerRoom) {
    std::cout << "Oh no! You entered a room full of bats!" << std::endl;
    std::cout << "The bats disorient you sending you in a random direction..." << std::endl;
    int randRoom = rand() % gameMap.numNeighborRooms(playerRoom.getRoomIndex());
    int nextRoomNumber = gameMap.returnNeighbors(playerRoom.getRoomIndex())[randRoom];
    
    // Get a reference to the actual room in the graph
    Room& nextRoom = gameMap.getVertexData(nextRoomNumber - 1);
    nextRoom.visitRoom();

    playerRoom = nextRoom;

    std::cout << "You've ended up in room " << playerRoom.getRoomNumber() << std::endl;
}

void enterPitRoom() {
    std::cout << "Oh no! You entered a room with a pit..." << std::endl;
    std::cout << "You fell into the pit!" << std::endl;
    std::cout << "Game Over :(" << std::endl;
}

void enterWumpusRoom(Room &playerRoom, int playerQuiver) {
    std::cout << "You entered the room with the Wumpus!" << std::endl;
    if (playerQuiver > 0) {
        std::cout << "You were able to slay the Wumpus! You Win!" << std::endl;
    } else {
        std::cout << "You were out of arrows. You were taken out by the Wumpus. You Lose." << std::endl;
    }
}

bool shootArrow(int distance, int playerRoomIndex, int& arrows) {
    // Store current room and track path
    int curRoomIndex = playerRoomIndex;
    
    // Create an array to track visited rooms
    bool visitedByArrow[20] = {false};
    visitedByArrow[curRoomIndex] = true;  // Mark starting room as visited
    
    // Track the final landing spot
    int landingSpotIndex = curRoomIndex;
    
    // Shoot through rooms
    for (int i = 0; i < distance; i++) {
        // Get all neighboring rooms
        int numNeighbors = gameMap.numNeighborRooms(curRoomIndex);
        int* neighbors = gameMap.returnNeighbors(curRoomIndex);
        
        // Find unvisited neighbors
        int unvisitedNeighbors[20];
        int unvisitedCount = 0;
        
        for (int j = 0; j < numNeighbors; j++) {
            int neighborIndex = neighbors[j] - 1;  // Convert room number to index
            if (!visitedByArrow[neighborIndex]) {
                unvisitedNeighbors[unvisitedCount++] = neighborIndex;
            }
        }
        
        // Free the neighbors array
        delete[] neighbors;
        
        // If no unvisited neighbors, arrow stops here
        if (unvisitedCount == 0) {
            std::cout << "The arrow hit a dead end and landed in room " 
                      << (curRoomIndex + 1) << std::endl;
            break;
        }
        
        // Choose random unvisited neighbor
        int nextRoomIndex = unvisitedNeighbors[rand() % unvisitedCount];
        
        // Move arrow to next room
        curRoomIndex = nextRoomIndex;
        visitedByArrow[curRoomIndex] = true;
        landingSpotIndex = curRoomIndex;
        
        // Check if it hit the Wumpus
        Room& nextRoom = gameMap.getVertexData(curRoomIndex);
        if (nextRoom.getRoomType() == "Wumpus") {
            std::cout << "Congratulations! Your arrow hit the Wumpus! You Win!" << std::endl;
            return true;  // Arrow hit the wumpus
        }
    }
    
    // Move the wumpus if it wasn't hit
    Room wumpusRoom;
    int wumpusRoomIndex = -1;
    
    // Find the Wumpus's current location
    for (int i = 0; i < 20; i++) {
        Room curRoom = gameMap.getVertexData(i);
        if (curRoom.isWumpusRoom()) {
            wumpusRoom = curRoom;
            wumpusRoomIndex = i;
            break;
        }
    }
    
    if (wumpusRoomIndex != -1) {  // If Wumpus was found
        std::cout << "The Wumpus was startled by your arrow and moved!" << std::endl;
        
        // Get neighbors of Wumpus room
        int* wumpusNeighbors = gameMap.returnNeighbors(wumpusRoomIndex);
        int numWumpusNeighbors = gameMap.numNeighborRooms(wumpusRoomIndex);
        
        // Collect valid neighbors (not player's room)
        int validNeighbors[20];
        int validCount = 0;
        
        for (int i = 0; i < numWumpusNeighbors; i++) {
            int neighborIndex = wumpusNeighbors[i] - 1;
            if (neighborIndex != playerRoomIndex) {
                validNeighbors[validCount++] = neighborIndex;
            }
        }
        
        delete[] wumpusNeighbors;  // Free the array
        
        // If there are valid neighbors to move to
        if (validCount > 0) {
            // First, remove Wumpus from current room
            Room emptyRoom(" ", wumpusRoom.getRoomNumber());
            gameMap.setVertexData(wumpusRoomIndex, emptyRoom);
            
            // Choose random neighbor and try to place Wumpus
            bool placedWumpus = false;
            int attempts = 0;
            int maxAttempts = validCount * 3;  // Limit attempts to prevent infinite loops
            
            while (!placedWumpus && attempts < maxAttempts) {
                int randomIndex = validNeighbors[rand() % validCount];
                Room neighborRoom = gameMap.getVertexData(randomIndex);
                
                // If room is empty (no hazards), place Wumpus
                if (neighborRoom.isRoomEmpty()) {
                    Room newWumpusRoom("Wumpus", neighborRoom.getRoomNumber());
                    if (neighborRoom.isVisited()) {
                        newWumpusRoom.visitRoom();  // Preserve visited status
                    }
                    if (neighborRoom.isArrowHere()) {
                        newWumpusRoom.arrowLanded();  // Preserve arrow status
                    }
                    
                    gameMap.setVertexData(randomIndex, newWumpusRoom);
                    placedWumpus = true;
                    //std::cout << "The Wumpus has moved to a new location." << std::endl;
                } else {
                    // Room has a hazard, try again with another neighbor
                    attempts++;
                    
                    // If we've tried all neighbors, get neighbors of neighbors
                    if (attempts >= validCount) {
                        int* newNeighbors = gameMap.returnNeighbors(randomIndex);
                        int numNewNeighbors = gameMap.numNeighborRooms(randomIndex);
                        
                        // Add new valid neighbors
                        for (int i = 0; i < numNewNeighbors; i++) {
                            int newNeighborIndex = newNeighbors[i] - 1;
                            if (newNeighborIndex != playerRoomIndex && 
                                newNeighborIndex != wumpusRoomIndex) {
                                // Check if this neighbor is already in our list
                                bool alreadyAdded = false;
                                for (int j = 0; j < validCount; j++) {
                                    if (validNeighbors[j] == newNeighborIndex) {
                                        alreadyAdded = true;
                                        break;
                                    }
                                }
                                
                                // Add to list if not already there
                                if (!alreadyAdded) {
                                    validNeighbors[validCount++] = newNeighborIndex;
                                }
                            }
                        }
                        
                        delete[] newNeighbors;  // Free the array
                    }
                }
            }
            
            // If after all attempts, couldn't place Wumpus
            if (!placedWumpus) {
                // Put Wumpus back in original room
                gameMap.setVertexData(wumpusRoomIndex, wumpusRoom);
                std::cout << "The Wumpus couldn't find a safe place to move and returned to its original room." << std::endl;
            }
        }
    }
    
    // Update the room where the arrow landed
    Room& landingRoom = gameMap.getVertexData(landingSpotIndex);
    landingRoom.arrowLanded();
    std::cout << "Your arrow landed in room " << (landingSpotIndex + 1) << std::endl;
    arrows--;  // Decrease arrow count
    
    return false;  // Arrow didn't hit the wumpus
}