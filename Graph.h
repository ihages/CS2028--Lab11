#pragma once
#include <iostream>

template<class T>
class MatrixGraph {
private:
	bool** matrix;
	int numVertices;
	
public:
	//constructor (sets all to zero)
	MatrixGraph(int numVertices) {
		this->numVertices = numVertices;
		matrix = new bool* [numVertices];
		for (int i = 0; i < numVertices; i++) {
			matrix[i] = new bool[numVertices];
			for (int j = 0; j < numVertices; j++) {
				matrix[i][j] = false;
			}
		}
	}
	
	//destructor
	~MatrixGraph();

	//funtions
	void addEdge(int start, int end);
	void printMatrix();
	void generateMap();
	bool hasEdge(int start, int end);
	int neighborRooms(int room);
	int* returnNeighbors(int room);

};

template<class T>
class vert {
	T data;
};

template<class T>
class edge {
	T data;
};