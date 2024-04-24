#pragma once
#include <string>
#include "Graphm.h"
#include "book.h"

//MST Class

class MST {
private:
	//Make the variable graph a smart pointer to the Graphm object
	std::unique_ptr<Graphm> graph;

public:
	MST(int n=5) {
		//Make a smart pointer to G
        //MST Class
		graph = std::make_unique<Graphm>(n); // Assign the unique_ptr to "graph"
	}
	~MST() {
	}
	//Page 401
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

	//Page 405
	void Prim(Graphm* G, int* D, int s) { // Prim’s MST algorithm
		//Make the variable V a smart pointer to the array
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
			// Store closest vertex
			// Initialize
			// Process the vertices
			// Add edge to MST
			// Unreachable vertices
			for (w = G->first(v); w < G->n(); w = G->next(v, w))
				if (D[w] > G->weight(v, w)) {
					D[w] = G->weight(v, w);
					// Update distance
					V[w] = v;
				}
		}
	}

	//Add edge to MST
	void AddEdgetoMST(int x, int y, int w) {
		//Add edge to MST
		graph->setEdge(x, y, w);
		graph->setEdge(y, x, w);
		std::cout << "Added edge " << x << " to " << y << " with a weight of " << w << "\n";
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