#pragma once

#include "GraphADT.h"
#include <assert.h>
#include <fstream>
#include <string>
//This class is copied from our textbook:
//
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 
// Modified by: Luke Bettendorf, CSCN 215-003
// Date: 4/24/2024

// Implementation for the adjacency matrix representation
//Constants:
const int UNVISITED = 1; // For nodes
const int VISITED = 0; // For nodes
class Graphm : public Graph {
private:
	int numVertex, numEdge; // Store number of vertices, edges
	int** matrix;
	// Pointer to adjacency matrix
	int* mark;
public:
	//Default constructor
	Graphm(int numVert=5)
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
	// Return v’s next neighbor after w
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

	//Functions NOT copied from the textbook:
	//This function prints out the matrix.
	void printMatrix()
	{
		std::cout << std::endl;
		//Print the number of vertices and edges
		std::cout << "Number of Vertices is " << numVertex << std::endl;
		std::cout << "Number of Edges is " << numEdge << std::endl;
		//Print the matrix
		for (int i = 0; i < numVertex; i++)
		{
			for (int j = 0; j < numVertex; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	//This function prints the matrix to a new file.
	//The 1 argument accepted is the name of the file to write to.
	//If the file already exists, it will be overwritten.
	void printToFile(std::string fileName)
	{
		//Open the file
		std::ofstream file;
		file.open(fileName);
		//Write the matrix to the file
		for (int i = 0; i < numVertex; i++)
		{
			for (int j = 0; j < numVertex; j++)
			{
				file << matrix[i][j] << " ";
			}
			file << std::endl;
		}
		//Close the file
		file.close();
	}
};

