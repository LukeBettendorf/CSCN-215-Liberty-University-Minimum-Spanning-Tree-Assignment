//Luke Bettendorf
//CSCN 215 - 003
//Programming Assignment 5: Minimum Spanning Tree

//Source File

#include <iostream>
using namespace std;

//Function Prototypes
void wait();

int main()
{
	cout << "Luke Bettendorf - CSCN 215 (003)\n";
	cout << "Programming Assignment 5: Minimum Spanning Tree\n\n";





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
