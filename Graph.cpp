#include"Graph.h"
#include"Room.h"
#include <iostream>

template<class T>
MatrixGraph<T>::~MatrixGraph() {
	for (int i = 0; i < numVertices; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] vertices;
}

template<class T>
void MatrixGraph<T>::addEdge(int start, int end) {
	start = start;
	end = end;
	if (start >= 0 && start < numVertices && end >= 0 && end < numVertices) {
		matrix[start][end] = true;
		matrix[end][start] = true; // for undirected graph
	}
}

template<class T>
void MatrixGraph<T>::printMatrix() {
	std::cout << "  1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << std::endl;
	for (int i = 0; i < numVertices; i++) {
		std::cout << (i + 1) % 10 << " ";
		for (int j = 0; j < numVertices; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<class T>
void MatrixGraph<T>::generateMap() {

	addEdge(0, 1); addEdge(0, 4); addEdge(0, 7);
	addEdge(1, 2); addEdge(1, 9);
	addEdge(2, 3); addEdge(2, 11);
	addEdge(3, 4); addEdge(3, 13);
	addEdge(4, 5);
	addEdge(5, 6); addEdge(5, 14);
	addEdge(6, 7); addEdge(6, 16);
	addEdge(7, 8);
	addEdge(8, 9); addEdge(8, 17);
	addEdge(9, 10);
	addEdge(10, 11); addEdge(10, 18);
	addEdge(11, 12);
	addEdge(12, 13); addEdge(12, 19);
	addEdge(13, 14);
	addEdge(14, 15);
	addEdge(15, 16); addEdge(15, 19);
	addEdge(16, 17);
	addEdge(17, 18);
	addEdge(18, 19);

	for (int i{}; i < numVertices; i++) {
		T* temp = new T(" ", i+1);
		vertices[i] = *temp;
		delete temp;
	}

    int batsRoom, pitRoom, wumpusRoom;
    
    do {
        batsRoom = 1 + (rand() % (numVertices - 1));
        pitRoom = 1 + (rand() % (numVertices - 1));
        wumpusRoom = 1 + (rand() % (numVertices - 1));
    } while (batsRoom == pitRoom || batsRoom == wumpusRoom || pitRoom == wumpusRoom);

    T* bats = new T("Bats", batsRoom+1);
    T* pit = new T("Pit", pitRoom+1);
    T* wumpus = new T("Wumpus", wumpusRoom+1);
    
    vertices[batsRoom] = *bats;
    vertices[pitRoom] = *pit;
    vertices[wumpusRoom] = *wumpus;
    
    delete bats;
    delete pit;
    delete wumpus;
}

template<class T>
bool MatrixGraph<T>::hasEdge(int start, int end) {
	return matrix[start- 1][end - 1];
}

template<class T>
int MatrixGraph<T>::numNeighborRooms(int room) {
	int numNeighbors = 0;
	for (int i = 0; i < numVertices; i++) {
		if (matrix[room][i]) {
			numNeighbors++;
		}
	}
	return numNeighbors;
}

template<class T>
int* MatrixGraph<T>::returnNeighbors(int room) {
	int numNeighbors = numNeighborRooms(room);
	int* neighbors = new int[numNeighbors];
	int j = 0;
	for (int i = 0; i < numVertices; i++) {
		if (matrix[room][i]) {
			neighbors[j] = i + 1; 
			j++;
		}
	}
	return neighbors;
}

template<class T>
void MatrixGraph<T>::setVertexData(int vertex, const T& data) {
    if (vertex >= 0 && vertex < numVertices) {
        vertices[vertex] = data;
    }
}

template<class T>
T& MatrixGraph<T>::getVertexData(int vertex) {
    return vertices[vertex];
}

template class MatrixGraph<Room>;

