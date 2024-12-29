#include <iostream>
#include "arrayListType.h"

int main()
{
  arrayListType<int> myList;
  //list of random numbers
 myList.insert(93);
  myList.insert(14);
  myList.insert(98);
  myList.insert(37);
  myList.insert(36);
  myList.insert(7);
  myList.insert(69);
  myList.insert(18);
  myList.insert(21);
  myList.insert(77);

  //displaying list without sorting
  cout<<"List before sorting"<<endl;
  myList.print();

  myList.quickSort();//quick sort
  
  //displaying list after sorting
  cout<<"\nList after sorting"<<endl;
  myList.print();
 
  
}