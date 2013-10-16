//Patrick Whetsel
//CSCI 2421 Fall 2013
//hw5functions.h
//declaration of global functions
//to be included with hw5functions.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include "bag.h"
#include "node.h"
#include "set.h"

#ifndef _hw5functions_h
#define _hw5functions_h

namespace hw5functions
{
	//Pre:None
	//Post:Displays program gretting
	void greeting();
	//Pre:Argument count passed as int
	//Post:Displays error message and returns exit_failure if not enough commandline args
	void confirm_cmdline_args(int);
	//Pre:File name passed in argv[1]
	//Post:File is opened with ifstream
	void open_file(std::ifstream&,char*);
	//Pre:File opened successfully in ifstream, 3 ints to store number of values in each set
	//Post:ints store number of values in each set
	void find_sizes(std::ifstream&,int&,int&,int&);
	//Pre:File opened successfully in ifstream, 3 lines of space delimited ints in file
	//Post:3 sets are populated, one from each line of file
	void populate_sets(std::ifstream&,set&,set&,set&);
};

#endif