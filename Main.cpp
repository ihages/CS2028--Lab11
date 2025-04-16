#include<iostream>
#include "Graph.h"

MatrixGraph<int> gameMap;

int main() {
	gameMap.generateMap();
	gameMap.printMatrix();
}

