//Luke Bettendorf
//CSCN 215 - 003
//Programming Assignment 5: Minimum Spanning Tree
//Last Modified: 4/24/2024

//Source File
// This is the test file for the MST class. 
// It reads a matrix from a file, creates a graph from the matrix, 
// and then finds the minimum spanning tree for the graph.
// 
//Note: Smart pointers are also utilized in the MST class to prevent memory leaks.
#include <iostream>
#include <fstream>
#include "MST.h"
#include "Graphm.h"
using namespace std;

//Length and width of the matrix
int const SIZE = 6;

//Function Prototypes
void wait();

//Main Function
int main()
{
    cout << "Luke Bettendorf - CSCN 215 (003)\n";
    cout << "Programming Assignment 5: Minimum Spanning Tree\n\n";
    //Initialize each graph as smart pointers.
    std::unique_ptr<Graphm> graph1 = std::make_unique<Graphm>(SIZE);
    std::unique_ptr<Graphm> graph2 = std::make_unique<Graphm>(SIZE);
    std::unique_ptr<Graphm> graph3 = std::make_unique<Graphm>(SIZE);

    //Initialize 3 mst objects as smart pointers.
    std::unique_ptr<MST> mst1 = std::make_unique<MST>(SIZE);
    std::unique_ptr<MST> mst2 = std::make_unique<MST>(SIZE);
    std::unique_ptr<MST> mst3 = std::make_unique<MST>(SIZE);

    //Read a matrix from input.txt into a 2d array
    //Open the file
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile)
    {
        cout << "Error: Unable to open file input.txt\n";
        wait();
        return 1;
    }
    //Initialize a2d array
    int matrix[SIZE][SIZE];
    //Read the matrix from the file
    //I used this method in Lab 8 of CSCN 111.
    cout << "Reading matrix from input file...\n";
    //Read the matrix into the 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            inFile >> matrix[i][j];
        }
    }
    inFile.close();

    //Add the edges to the graph
    for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != 0) {
                graph1->setEdge(i, j, matrix[i][j]);
                graph2->setEdge(i, j, matrix[i][j]);
                graph3->setEdge(i, j, matrix[i][j]);
            }
		}
	}
    cout << "\nGraph created from the input file:\n";
    graph2->printMatrix();

    //Find the minimum spanning tree
    cout << "\nBegin MST 1 starting at vertex 0:\n";
    mst1->Prim(graph1.get(), new int[SIZE], 0);
    //Print the MST
    mst1->printMST();
    //Output the MST to a file
    mst1->printMSTtoFile("output1.txt");

    //Find the MST for vertex 3
    cout << "\nBegin MST 2 starting at vertex 3:\n";
    mst2->Prim(graph2.get(), new int[SIZE], 3);
    //Print the MST
    mst2->printMST();
    //Output the MST to a file
    mst2->printMSTtoFile("output2.txt");

    //Find the MST for vertex 5
    cout << "\nBegin MST 3 starting at vertext 5:\n";
    mst3->Prim(graph3.get(), new int[SIZE], 5);
    //Print the MST
    mst3->printMST();
    //Output the MST to a file
    mst3->printMSTtoFile("output3.txt");
    cout << endl;
   
    
    wait();
    return 0;
}



//Wait Function (used in CSCN 111-112)
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (std::cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear the input buffer 
	}
	std::cout << "Press the Enter key to continue ... ";
	std::cin.get();
}
