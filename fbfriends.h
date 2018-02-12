/*****************************************************
   This class is a container that holds Friends of the
   class Friend. It uses an internal iterator to give the
   application the ability to order the container as well
   as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.
     John Dolan		Spring 2014	Ohio University
*********************************************************/
/******************************************************************************
David Wisniewski
09/25/2017
Project2
Description: this is a sequence class that holds a dynamic array of the users
Facenook friends and allows the user to keep track of those friends
*******************************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include "friend.h"
#include<cassert>
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

class FBFriends
{
    public:
	FBFriends();

	//The functions known as the Big 3
	~FBFriends();
	FBFriends(const FBFriends& other);
	void operator = (const FBFriends& other);
///////////////////////////////////////////////////////////////////////////////
	// Functions for the internal iterator
	void start();
/****************************************************************************
Initilizes the current index to zero.
*****************************************************************************/
	void advance();
/****************************************************************************
Increments the current index by one.
*****************************************************************************/
	bool is_item();
/****************************************************************************
Returns true if the current index is less than used.
*****************************************************************************/
  Friend current();
/****************************************************************************
Returns the current index
*****************************************************************************/
  void remove_current();
/****************************************************************************
Removes the current index by forcing it to the end of the array then
decrementing used forcing it to the outside of the array
*****************************************************************************/
	void insert(const Friend& f);
/****************************************************************************
Places the new item in the array before the the current_index
*****************************************************************************/
	void attach(const Friend& f);
/****************************************************************************
Places the new item after the current_index in the array
*****************************************************************************/
	void show_all(std::ostream& outs)const;
/****************************************************************************
Displays all of the iteams in the array
*****************************************************************************/
	void bday_sort();
/*******************************************************************************
Sorts the Friendsby birthay from lowest to highest
*******************************************************************************/
	Friend find_friend(const std::string& name)const;
/*******************************************************************************
Returns the friends name and birthday
*******************************************************************************/
  bool is_friend(const Friend& f) const;
/*******************************************************************************
If you are friends with them it returns true otherwise it returns false
*******************************************************************************/
	void load(std::istream& ins);
/*******************************************************************************
Loads the text file into the array
*******************************************************************************/

  void save(std::ostream& outs);
    private:
	    void resize(); // increases the capacity of the container by 5
	    Friend *data;
	    int used;
	    int capacity;
	    int current_index;
};

#endif
