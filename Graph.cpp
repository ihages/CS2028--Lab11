#include"Graph.h"
#include"Room.h"
#include <iostream>

template<class T>
void MatrixGraph<T>::addEdge(int start, int end) {
	start = start - 1;
	end = end - 1;
	if (start >= 0 && start < numVertices && end >= 0 && end < numVertices) {
		matrix[start][end] = true;
		matrix[end][start] = true; // for undirected graph
	}
}

template<class T>
void MatrixGraph<T>::printMatrix() {
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<class T>
void MatrixGraph<T>::generateMap() {
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

	addEdge(16, 17); addEdge(16, 20);

	addEdge(17, 18);

	addEdge(18, 19);

	addEdge(19, 20);
}

bool hasEdge(int start, int end) {
	return matrix[start][end];
}

template<class T>
MatrixGraph<T>::~MatrixGraph() {
	for (int i = 0; i < numVertices; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template class MatrixGraph<Room>;

