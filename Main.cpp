#include<iostream>
#include "Graph.h"

MatrixGraph<int> gameMap;

int main() {
	gameMap.generateMap(20); //generates map with 20 vertices
	gameMap.printMatrix();
}

