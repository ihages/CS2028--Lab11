#pragma once
#include <iostream>

template<class T>
class MatrixGraph {
private:
	bool** matrix;
	int numVertices;
	
public:
	//constructor (sets all to zero)
	Graph(int numVertices) {
		this->numVertices = numVertices;
		matrix = new bool* [numVertices];
		for (int i = 0; i < numVertices; i++) {
			matrix[i] = new bool[numVertices];
			for (int j = 0; j < numVertices; j++) {
				matrix[i][j] = false;
			}
		}
	}

	void addEdge(int start, int end) {
		if (start >= 0 && start < numVertices && end >= 0 && end < numVertices) {
			matrix[start][end] = true;
			matrix[end][start] = true; // for undirected graph
		}
	}

	void printMatrix() {
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void generateMap() {
		addEdge(1, 2); addEdge(1, 5); addEdge(1, 8);
		
		addEdge(2, 3); addEdge(2, 10);

		addEdge(3, 4); addEdge(3, 12);

		addEdge(4, 5); addEdge(4, 14);

		addEdge(5, 6);
		
		addEdge(6, 7); addEdge(6, 15);

		addEdge(7, 8); addEdge(7, 17);
		
		addEdge(8, 9);
		
		addEdge(9, 10); addEdge(9, 18);
		
		addEdge(10, 11);
		
		addEdge(11, 12); addEdge(11, 19);
		
		addEdge(12, 13);

		addEdge(13, 14); addEdge(13, 20);
		
		addEdge(14, 15);
		
		addEdge(15, 16);
		
		addEdge(16, 17);
		
		addEdge(17, 18);
		
		addEdge(18, 19);
		
		addEdge(19, 20);
	}

	//destructor
	~Graph() {
		for (int i = 0; i < numVertices; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		}

};

template<class T>
class vert {
	T data;
};

template<class T>
class edge {
	T data;
};