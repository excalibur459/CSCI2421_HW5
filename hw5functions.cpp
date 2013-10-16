//Patrick Whetsel
//CSCI 2421 Spring 2013
//hw5fuctions.cpp
//definitions of global functions

#include "hw5functions.h"

void hw5functions::greeting()
{
	std::cout << "This program accesses a file passed\n";
	std::cout << "as a command line argument and stores 3 sets\n";
	std::cout << "of ints, one per line.  The sets are then \n";
	std::cout << "displayed and a combination of union,\n";
	std::cout << "intersection, and difference operations\n";
	std::cout << "are performed and the results are displayed.\n";
	std::cout << "\nPlease press any key followed by ENTER to continue.\n";

	//hold for user input
	int x;
	std::cin >> x;
	std::cout << '\n';
	std::cin.ignore(255, '\n');
}

void hw5functions::confirm_cmdline_args(int count)
{
	if (count != 2)
	{
		std::cerr << "\nUsage: a.out filename_in";
		return exit(-1);
	}
}

void hw5functions::open_file(std::ifstream& in,char* file)
{
	in.open(file);
	if (!in.is_open())
	{
		std::cerr << "\nFile could not be opened";
		return exit(-1);
	}
}

void hw5functions::find_sizes(std::ifstream& in,int& A_size,int& B_size,int& C_size)
{
	//set indexes to zero
	A_size = 0;
	B_size = 0;
	C_size = 0;

	//get first line
	std::string str;
	std::getline(in,str);
	//count number of spaces in line (n-1 spaces for n coefficients)
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') ++A_size;
	}
	//+1 to get number of elements
	++A_size;

	//count line 2
	std::getline(in,str);
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') ++B_size;
	}
	//+1 to get number of elements
	++B_size;

	//count line 3
	std::getline(in,str);
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') ++C_size;
	}
	//+1 to get number of elements
	++C_size;
	
	//reset eof flag
	in.clear();
}

void hw5functions::populate_sets(std::ifstream& in, set& A, set& B, set& C,int& A_size,int& B_size,int& C_size)
{
	//move to beginning of file
	in.clear();
	in.seekg(0, in.beg);

	std::string str;
	std::stringstream ss;

	//Get first line, populate A
	std::getline(in, str);
	ss << str;
	int ctr = A_size;
	int element;
	while (ctr > 0)
	{
		
		ss >> element;
		A.insert(element);
		--ctr;
	}

	//Get line 2, populate B
	std::getline(in, str);
	ss << str;
	ctr = B_size;
	while (ctr > 0)
	{
		ss >> element;
		B.insert(element);
		--ctr;
	}

	//Get line 3, populate C
	std::getline(in, str);
	ss << str;
	ctr = C_size;
	while (ctr > 0)
	{
		ss >> element;
		C.insert(element);
		--ctr;
	}
}
