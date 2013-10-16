//Patrick Whetsel
//CSCI 2421 Fall 2013
//set.h
//Declaration of set class that uses a dynamic bag

#include "bag.h"
#include "node.h"
#include <iostream>
#include <cstdlib>

#ifndef _set_h
#define _set_h

class set
{
public:
	//Constructor
	set ();

	//Copy Constructor
	set (const set&);

	//Setter
	void insert(int);
	
	//Constant Getters
	/*bool search(const int&);*/
	bool empty() const;
	int size() const;

	//Operators
	set operator + (const set&);
	set operator - (const set&);
	set& operator = (const set&);
	bool operator == (const set&);
	friend std::ostream& operator << (std::ostream&, const set&);

private:
	bag<int> set_bag;
};

#endif