//Patrick Whetsel
//CSCI 2421 Fall 2013
//set.h
//Declaration of set class that uses a dynamic bag

#include "bag.h"
#include <iostream>
#include <cstdlib>

#ifndef _set_h
#define _set_h

class set
{
public:
	//Constructors
	set ();
	set (const set&);

	//Setter
	//Pre: int value to insert into set
	//Post: if value is not already present in set will have been inserted
	void insert(int);
	
	//Constant Getters
	//Pre: int to search for in set
	//Post: true returned if int is in set, false otherwise
	bool search(int);
	//Pre: none
	//Post: true returned if set is empty, false otherwise
	bool empty() const;
	//Pre: none
	//Post: count of elements in set returned
	int size() const;

	//Operators
	set operator + (const set&);
	set operator - (const set&);
	set operator & (const set&);
	set& operator = (const set&);
	bool operator == (const set&);
	friend std::ostream& operator << (std::ostream&, const set&);

private:
	bag<int> set_bag;
};

#endif