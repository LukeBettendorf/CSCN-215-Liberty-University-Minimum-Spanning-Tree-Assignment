//Luke Bettendorf
//CSCN 215 - 003
//Programming Assignment 5: Minimum Spanning Tree

//Source File
#include <iostream>
#include <fstream>
#include "MST.h"
#include "Graphm.h"
using namespace std;

//Length and width of the matrix
int const SIZE = 6;

//Function Prototypes
void wait();

int main()
{
    cout << "Luke Bettendorf - CSCN 215 (003)\n";
    cout << "Programming Assignment 5: Minimum Spanning Tree\n\n";
    //Initialize a graph as a pointer.
    Graphm* graph = new Graphm(SIZE);

    //Initialize an MST object
    MST mst(SIZE);
    MST mst2(SIZE);
    MST mst3(SIZE);

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
    cout << "Reading matrix from input file...\n";
    //Read the matrix into the 2d array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            inFile >> matrix[i][j];
        }
    }
    inFile.close();
    //Print the matrix
    cout << "Matrix read from input file:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //Add the edges to the graph
    for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
            if(matrix[i][j] != 0)
       graph->setEdge(i, j, matrix[i][j]);
		}
	}
    cout << "\nGraph created from the input file:\n";
    graph->printMatrix();

    //Find the minimum spanning tree
    cout << "MST from vertex 0:\n";
    mst.Prim(graph, new int[SIZE], 0);
    //Print the MST
    mst.printMST();
    //Output the MST to a file
    mst.printMSTtoFile("output1.txt");
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
