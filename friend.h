/************************************************
   This is the header file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member
   functions are just accessors and input/output functions.
       John Dolan	Spring 2014	Ohio University
***********************************************************/

#include<iostream>
#include<string>
#include "date.h"
#ifndef FRIEND_H
#define FRIEND_H


class Friend{
    public:
	Friend();
  /****************************************************************************
  Initilizes name to None
  *****************************************************************************/
	std::string get_name()const;
  /****************************************************************************
  Returns the name of the friend
  *****************************************************************************/
  Date get_bday()const;
  /****************************************************************************
  Returns the birthday date of the friend
  *****************************************************************************/
	bool operator == (const Friend& other)const;
  /****************************************************************************
  compares two friends birthdays to determine if they are equal or not
  *****************************************************************************/
  bool operator != (const Friend& other)const;
  /****************************************************************************
  compares two friends birthdays to determine if they are equal or not
  *****************************************************************************/
//  Friend operator = (Friend &f);
	void input(std::istream& ins);
  /*****************************************************************************
  Reads in friends from an input operator or from user input
  *****************************************************************************/
	void output(std::ostream& outs)const;
  /****************************************************************************
  Outputs friends to either a txt file or to the screen depending on what is
  passed in
  *****************************************************************************/
    private:
	std::string name;
	Date bday;
};

std::istream& operator >>(std::istream& ins,Friend& f);
std::ostream& operator <<(std::ostream& outs,const Friend& f);

#endif
