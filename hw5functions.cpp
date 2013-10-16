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

void hw5functions::populate_sets(std::ifstream& in, set& A, set& B, set& C)
{
	//move to beginning of file
	in.seekg(in.beg);
	in.clear();

	std::string str;
	std::stringstream ss;
	ss.clear();

	//Get first line, populate A
	std::getline(in, str);
	ss << str;
	int val;
	while (ss >> val)
	{
		A.insert(val);
	}

	//Get line 2, populate B
	std::getline(in, str);
	ss.clear();
	ss << str;
	while (ss >> val)
	{
		B.insert(val);
	}

	//Get line 3, populate C
	std::getline(in, str);
	ss.clear();
	ss << str;
	while (ss >> val)
	{
		C.insert(val);
	}
}
