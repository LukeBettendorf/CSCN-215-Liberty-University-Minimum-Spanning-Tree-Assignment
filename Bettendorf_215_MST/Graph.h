#pragma once

#include "GraphADT.h"
#include "Edge.h"
#include <assert.h>
//This entire class is copied from our textbook:
//
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 
// Used by: Luke Bettendorf, CSCN 215-003
// Date: 4/23/2024

// Implementation for the adjacency matrix representation
const int UNVISITED = 0; // For nodes
class Graphm : public Graph {
private:
	int numVertex, numEdge; // Store number of vertices, edges
	int** matrix;
	// Pointer to adjacency matrix
	int* mark;
public:
	Graphm(int numVert)
	{
		Init(numVert);
	}
	~Graphm() {
		// Pointer to mark array
		// Constructor
		// Destructor
		delete[] mark; // Return dynamically allocated memory
		for (int i = 0; i < numVertex; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	void Init(int n) { // Initialize the graph
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		// Initialize mark array
		for (i = 0; i < numVertex; i++)
			mark[i] = UNVISITED;
		matrix = (int**) new int* [numVertex]; // Make matrix
		for (i = 0; i < numVertex; i++)
			matrix[i] = new int[numVertex];
		for (i = 0; i < numVertex; i++) // Initialize to 0 weights
			for (int j = 0; j < numVertex; j++)
				matrix[i][j] = 0;
	}
	int n() { return numVertex; } // Number of vertices
	int e() { return numEdge; } // Number of edges
	// Return first neighbor of "v"
	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
		// Return n if none
	}
	// Return v�s next neighbor after w
	int next(int v, int w) {
		for (int i = w + 1; i < numVertex; i++)
			if (matrix[v][i] != 0)
				return i;
		return numVertex;
		// Return n if none
	}

	// Set edge (v1, v2) to "wt"
	void setEdge(int v1, int v2, int wt) {
		assert(wt > 0, "Illegal weight value");
		if (matrix[v1][v2] == 0) numEdge++;
		matrix[v1][v2] = wt;
	}
		void delEdge(int v1, int v2) { // Delete edge (v1, v2)
		if (matrix[v1][v2] != 0) numEdge--;
		matrix[v1][v2] = 0;
	}
	bool isEdge(int i, int j) // Is (i, j) an edge?
	{
		return matrix[i][j] != 0;
	}
	int weight(int v1, int v2) { return matrix[v1][v2]; }
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
};
