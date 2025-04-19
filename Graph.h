#pragma once
#include <iostream>
#include <ctime>

#include "Room.h"

template<class T>
class MatrixGraph {
private:
	bool** matrix;
	int numVertices;
	T* vertices;
	
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
		vertices = new T[numVertices];
	}
	
	//destructor
	~MatrixGraph();

	//funtions
	void addEdge(int start, int end);
	void printMatrix();
	void generateMap();
	bool hasEdge(int start, int end);
	int numNeighborRooms(int room);
	int* returnNeighbors(int room);

	void setVertexData(int vertex, const T& data);
	T& getVertexData(int vertex);

};

template<class T>
class vert {
	T data;
};

template<class T>
class edge {
	T data;
};