#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"
#include"fbfriends.h"
using namespace std;
///////////////////////////////////////////////////////////////////////////////
FBFriends::FBFriends()
{
    capacity = 6;
    used=0;
    data = new Friend[capacity];

}
///////////////////////////////////////////////////////////////////////////////
FBFriends::FBFriends(const FBFriends& other)
{
  used = other.used;
  capacity= other.capacity;
  data = new Friend[capacity];
  //copy(other.data,other.data+used,data);
  for(size_t i =0; i< used;i++)
  {
    data[i] =other.data[i];
  }
}
///////////////////////////////////////////////////////////////////////////////
FBFriends::~FBFriends()
{
  delete[]data;//Frees Up allocated space
}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::operator =(const FBFriends& other)
{
  if(this == &other)
  {
    return;
  }
  if(capacity!= other.capacity)
    {
      delete[]data;
      capacity =other.capacity;
      data = new Friend[capacity];
    }
  used = other.used;
  //copy(other.data,other.data+used,data);
  for(size_t i =0; i< used;i++)
  {
    data[i] =other.data[i];
  }

}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::start()
{
    current_index = 0;
}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::advance()
{
  assert(is_item());
   ++current_index;
}
///////////////////////////////////////////////////////////////////////////////
bool FBFriends::is_item()
{
  return (current_index < used);
}
///////////////////////////////////////////////////////////////////////////////
Friend FBFriends::current()
{
  return data[current_index];
}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::remove_current()
{
// swaps the friend you want to remove with the last item in the array then
// decrementsused.

      Friend temp;
      temp=data[current_index];
      for (size_t i = current_index; i < used; ++i)
      {
        data[i] = data[i+1];
      }
      temp = data[used-1];
      --used;
    //  bday_sort();
}
///////////////////////////////////////////////////////////////////////////////
Friend FBFriends::find_friend(const std::string& name)const
{
Friend Not_found;
 try
 {
    for (size_t i = 0; i < used; ++i)
    {
        if (name == data[i].get_name())
        {
          return data[i];
        }
    }
  }

  catch(const std::string& name)
    {

    std::cout << "That friend was not found" << '\n';
    return Not_found;
    }
  return Not_found;
  }
///////////////////////////////////////////////////////////////////////////////
void FBFriends::insert(const Friend& f)
{

  if(used == capacity)
  {
    resize();
  }
  used++;
  for (size_t i = used-1; i > current_index; --i)
  {
    data[i] = data[i-1];
  }
    data[current_index]= f;


    /*  if(used == capacity)
      {
        resize();
      }

      used++;
      std::cout << used << '\n';
      for (size_t i = current_index; i < used; --i)
      {
        data[i+1]= data[i];
      }
        data[current_index+1] = f;*/
}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::attach(const Friend& f)
{

    if(used == capacity)
    {
    resize();
    }
    ++used;
    for (size_t i = used-1; i > current_index; --i)
    {
    data[i]= data[i-1];
    }
    data[current_index+1] = f;

}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::show_all(std::ostream& outs)const
{
  for (size_t i = 0; i < used; ++i)
  {
    if(&outs == &cout)
    {
      std::cout << data[i] << '\n';
    }
    else
    outs << data[i];
  }
}

///////////////////////////////////////////////////////////////////////////////
void FBFriends::bday_sort()
{
   Friend temp;
   bool done = false;
   while(!done)
  {             // holding variable
    done = true;
       for (size_t j=0; j < used-1; ++j)
      {
            if (data[j+1].get_bday() < data[j].get_bday())
           {
                 temp = data[j];             // swap elements
                 data[j] = data[j+1];
                 data[j+1] = temp;
                 done=false;
            }

       }

     }
}

///////////////////////////////////////////////////////////////////////////////
bool FBFriends::is_friend(const Friend& f) const
{
  for (size_t i = 0; i < used; ++i)
  {
      if (f.get_name() == data[i].get_name())
      {
        return true;
      }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

void FBFriends::load(std::istream& ins)
{
/*******************************************************************************
  Loads data into the dynamic array when it runs out of space it resizes the
  array.
*******************************************************************************/
  Friend temp;
  while(!ins.eof())
  {
    if(used==capacity)
  {
    resize();
  }
  used++;
  ins >> temp;
  while((ins.peek()=='\n')||(ins.peek()=='\r'))
   {
     ins.ignore();
   }
  if(temp.get_name() == "None")
  {
    --used;
  }
  data[used-1] = temp;
//  std::cout << data[used-1] << '\n';

  }


}
///////////////////////////////////////////////////////////////////////////////
void FBFriends::save(std::ostream& outs)
{
  for (size_t i = 0; i < used; ++i)
  {
    outs << data[i];
  }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void FBFriends::resize()
{
  Friend *tmpd;
  tmpd = new Friend[capacity+5];
//  copy(data,data+used,tmpd);
for(size_t i =0; i< used;i++)
{
  tmpd[i] = data[i];
}
  delete[]data;
  capacity+=5;
  data = tmpd;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
