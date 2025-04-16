#include<iostream>
#include "Graph.h"
#include "Room.h"

MatrixGraph<Room> gameMap(20);

int main() {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> da845027e7f0effdde5becf99755c98f42ac2498
	
	gameMap.generateMap(); //generates map with 20 vertices

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
            gameMap.printMatrix(); //prints for sake of testing
        }
        }//switch end
    }//while end
}//main end
<<<<<<< HEAD
=======
	gameMap.generateMap(20); //generates map with 20 vertices
	gameMap.printMatrix();
}
>>>>>>> 74c5effe5a8bc81160ff008989a4bb8412687e20
=======
>>>>>>> da845027e7f0effdde5becf99755c98f42ac2498

