#pragma once

//This entire class is copied from our textbook:
//
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 
// Used by: Luke Bettendorf, CSCN 215-003
// Date: 4/23/2024
// Edge class for Adjacency List graph representation
class Edge {
	int vert, wt;
public:
	Edge() { vert = -1; wt = -1; }
	Edge(int v, int w) { vert = v; wt = w; }
	int vertex() { return vert; }
	int weight() { return wt; }
};