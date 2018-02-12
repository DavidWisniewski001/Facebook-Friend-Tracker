
#include<iostream>
#include<string>
#include "date.h"
#include"friend.h"
#include<string>
#ifndef FRIEND_CC
#define FRIEND_CC
using namespace std;
////////////////////////////////////////////////////////////////////////////////
Friend::Friend()
{
  name = "None";
}
////////////////////////////////////////////////////////////////////////////////
Date Friend::get_bday()const
{
  return bday;
}
////////////////////////////////////////////////////////////////////////////////
std::string Friend::get_name()const
{
 return name;
}
////////////////////////////////////////////////////////////////////////////////
bool Friend::operator == (const Friend& other)const
{
  if((other.bday == bday) && (other.name == name))
  return true;
  else
  return false;
}
////////////////////////////////////////////////////////////////////////////////
bool Friend::operator != (const Friend& other)const
{
	return other.bday != bday;
}
////////////////////////////////////////////////////////////////////////////////
void Friend::input(std::istream& ins)
 {
     if (&std::cin == &ins)
     {
       cout<<"Enter the name of your friend:\n";
 			if(cin.peek() == '\n') cin.ignore();
 			getline(cin, name);
       std::cout << "Enter their birthday date meaning the year they were born" << '\n';
       std::cin >> bday;
     }
     else
     {
      if(ins.peek()=='\n')
       {
         ins.ignore();
       }
       getline(ins,name);
       ins >> bday;
     }

 }
////////////////////////////////////////////////////////////////////////////////
void Friend::output(std::ostream& outs)const
{
      if (&std::cout == &outs)
      {
        std::cout << name <<endl;
        std::cout << bday <<endl;

      }
      else
      {

        outs << name <<endl;
        outs << bday <<endl;

      }
}
////////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& outs, const Friend& f)
{
        f.output(outs);
        return outs;
}
////////////////////////////////////////////////////////////////////////////////
std::istream& operator >> (istream& ins, Friend& f)
{
        f.input(ins);
        return ins;
}
////////////////////////////////////////////////////////////////////////////////
/*Friend Friend::operator =(Friend&f)
{
  f.name = name;
  f.bday = bday;
}*/
////////////////////////////////////////////////////////////////////////////////

#endif
