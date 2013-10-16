//Patrick Whetsel
//CSCI 2421 Fall 2013
//set.cpp
//Definition of set class that uses a dynamic bag

#include "set.h"

set::set ()
{
	set_bag = bag<int>();
}

set::set (const set& source)
{
	bag<int> temp;
	temp = source.set_bag;
	this->set_bag = temp;
}
 
void set::insert(int element)
{
	if (list_search(this->set_bag.head_ptr, element) == NULL)
	{
		this->set_bag.insert(element);
	}
}
	
bool set::search(int& query)
{	
	node<int>* temp = this->set_bag.head_ptr;
	node<int>* search_result = list_search(temp,query);
	if (search_result != NULL)
	{	
		return true;
	}
	return false;
}

bool set::empty() const
{
	if (this->set_bag.size() == 0)
	{
		return true;
	}
	return false;
}
int set::size() const
{
	return this->set_bag.size();
}

//Operators
set set::operator + (const set& rhs)
{
	return rhs;
}
set set::operator - (const set& rhs)
{
	return rhs;
}
set& set::operator = (const set& rhs)
{
	set temp(rhs);

	std::swap(this->set_bag, temp.set_bag);
	return *this;
}
bool set::operator == (const set& rhs)
{
	return true;
}
std::ostream& operator << (std::ostream& target, const set& source)
{
	target << "{";
	
	node<int> temp = *source.set_bag.head_ptr;
	if (temp.link() != NULL)
	{
		std::cout << temp.data();
		temp = *temp.link();
	}
	while (temp.link() != NULL)
	{
		std::cout  << ", " << temp.data();
	}

	target << "}";
	return target;
}