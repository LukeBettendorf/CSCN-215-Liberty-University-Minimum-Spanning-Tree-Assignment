#pragma once
#include <string>
#include "Graphm.h"
#include "book.h"

//MST Class
//This class is used to create a minimum spanning tree from a graph.

//Several function have been copied from the textbook:
//
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 
// Modified by: Luke Bettendorf, CSCN 215-003
// Date: 4/24/2024

class MST {
private:
	//Make the variable graph a smart pointer to the Graphm object.
	//This ensures memory is deallocated when the destructor runs.
	std::unique_ptr<Graphm> graph;

public:
	MST(int n=5) {
		//Make a smart pointer to G
        //MST Class
		graph = std::make_unique<Graphm>(n); // Assign the unique_ptr to "graph"
	}
	~MST() {
	}
	//This function is taken from page 401 of the text.
	int minVertex(Graphm* G, int* D) { // Find min cost vertex
		int i, v = -1;
		// Initialize v to some unvisited vertex
		for (i = 0; i < G->n(); i++)
			if (G->getMark(i) == UNVISITED) { v = i; break; }
		for (i++; i < G->n(); i++) // Now find smallest D value
			if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
				v = i;
		return v;
	}

	//This function is taken from page 405 of the text.
	void Prim(Graphm* G, int* D, int s) { // Prim’s MST algorithm
		std::unique_ptr<int[]> V(new int[G->n()]);

		int i, w;
		for (int i = 0; i < G->n(); i++)
			D[i] = INFINITY;
		D[s] = 0;
		for (i = 0; i < G->n(); i++) {
			int v = minVertex(G, D);
			G->setMark(v, VISITED);
			if (v != s)
				AddEdgetoMST(V[v], v, D[v]);
			if (D[v] == INFINITY) return;
			for (w = G->first(v); w < G->n(); w = G->next(v, w))
				if (D[w] > G->weight(v, w)) {
					D[w] = G->weight(v, w);
					V[w] = v;
				}
		}
	}


	//Add edge to MST
	void AddEdgetoMST(int x, int y, int w) {
		//Add edge to MST
		graph->setEdge(x, y, w);
		graph->setEdge(y, x, w);
		std::cout << "Added edge " << x << " to " << y << std::endl;
	}

	//Print MST
	void printMST() {
		graph->printMatrix();
	}

	//Print MST to file
	void printMSTtoFile(std::string filename) {
		graph->printToFile(filename);
	}
};