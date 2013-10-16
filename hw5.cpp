//Patrick Whetsel
//CSCI 2421 Fall 2013
//hw5.cpp
//This program accesses a file passed 
//as a command line argument and stores 3 sets
//of ints, one per line.  The sets are then 
//displayed and a combination of union,
//intersection, and difference operations
//are performed and the results are displayed.

#include "hw5functions.h"

int main(int argc, char* argv[])
{
	//Display greeting
	hw5functions::greeting();

	//Check for valid number of command line arguments
	hw5functions::confirm_cmdline_args(argc);

	//Open file stream
	std::ifstream input;
	hw5functions::open_file(input, argv[1]);

	//Populate Sets A, B, and C
	set A;
	set B;
	set C;
	hw5functions::populate_sets(input,A,B,C);

	//Display A, B, and C
	std::cout << "\nA = " << A;
	std::cout << "\nB = " << B;
	std::cout << "\nC = " << C;
	
	return EXIT_SUCCESS;
}