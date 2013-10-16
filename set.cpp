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
	
bool set::search(int query)
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
	set return_set;
	//check for two empty sets, return empty set if true
	if (this->empty() == true && rhs.empty() == true)
	{
		return return_set;
	}
	//insert elements from lhs up to tail node
	node<int> temp = *this->set_bag.head_ptr;
	while (temp.link() != NULL)
	{
		return_set.insert(temp.data());
		temp = *temp.link();
	}
	//insert tail node of lhs
	if (temp.link() == NULL)
	{
		return_set.insert(temp.data());
	}
	
	//insert elements from rhs up to tail node
	temp = *rhs.set_bag.head_ptr;
	while (temp.link() != NULL)
	{
		return_set.insert(temp.data());
		temp = *temp.link();
	}
	//insert tail node of rhs
	if (temp.link() == NULL)
	{
		return_set.insert(temp.data());
	}
	return return_set;
}
set set::operator - (const set& rhs)
{
	//new empty set
	set return_set;
	//check for two empty sets, return empty set if true
	if (this->empty() == true && rhs.empty() == true)
	{
		return return_set;
	}

	//each item present in lhs but not rhs inserted in new set up to tail node
	node<int> temp = *this->set_bag.head_ptr;
	set rhs_temp = rhs;
	while (temp.link() != NULL)
	{
		if (rhs_temp.search(temp.data()) == false) {return_set.insert(temp.data());}
		temp = *temp.link();
	}
	//insert tail node if present in lhs but not rhs
	if (temp.link() == NULL)
	{
		if (rhs_temp.search(temp.data()) == false)
		{
			return_set.insert(temp.data());
		}
	}
	
	return return_set;
}
set set::operator & (const set& rhs)
{
	set return_set;
	//check for two empty sets, return empty set if true
	if (this->empty() == true && rhs.empty() == true)
	{
		return return_set;
	}
	//each item present in lhs and rhs inserted into intersection up to tail node
	node<int> temp = *this->set_bag.head_ptr;
	set rhs_temp = rhs;
	while (temp.link() != NULL)
	{
		if (rhs_temp.search(temp.data()) == true) {return_set.insert(temp.data());}
		temp = *temp.link();
	}
	//insert tail node if present in both lhs and rhs
	if (temp.link() == NULL)
		if (rhs_temp.search(temp.data()) == true) {return_set.insert(temp.data());}
	return return_set;
}
set& set::operator = (const set& rhs)
{
	set temp(rhs);

	std::swap(this->set_bag, temp.set_bag);
	return *this;
}
bool set::operator == (const set& rhs)
{
	//check for two empty sets
	if (this->empty() == true && rhs.empty() == true)
	{
		return true;
	}
	//confirm each item is present in rhs up to tail node
	node<int> temp = *this->set_bag.head_ptr;
	set rhs_temp = rhs;
	while (temp.link() != NULL)
	{
		if (rhs_temp.search(temp.data()) == false) {return false;}
		temp = *temp.link();
	}
	//confirm tail node is present in rhs
	if (temp.link() == NULL)
		if (rhs_temp.search(temp.data()) == false) 
		{
			return false;
		}
	
	//confirm each item is present in lhs up to tail node
	temp = *rhs.set_bag.head_ptr;
	set lhs_temp = *this;
	while (temp.link() != NULL)
	{
		if (lhs_temp.search(temp.data()) == false) {return false;}
		temp = *temp.link();
	}
	//confirm tail node is present in rhs
	if (temp.link() == NULL)
		if (lhs_temp.search(temp.data()) == false) {return false;}
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
		temp = *temp.link();
	}
	if (temp.link() == NULL)
	target << ", " << temp.data() << "}";
	return target;
}