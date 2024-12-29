#include <iostream>
#include "orderedArrayListType.h"
using namespace std;

int main() 
{
  orderedArrayListType<int> myArray;//create the array

  //get array elements from user
   int n;
  cout << "Enter a list random numbers. Terminate with -1"<<endl;
  cin>>n;
  while(n!=-1)
    {
      
      myArray.insert(n);
      cout << "Enter a list random numbers. Terminate with -1"<<endl;;
      cin>>n;
    }

  //show the array of elements
  cout<<"\nThe order list of numbers you entered is:"<<endl;
  cout<<"List:";
  myArray.print();
  cout<<"List Size:"<<myArray.listSize()<<endl;
  cout<<"Max List Size:"<<myArray.maxListSize()<<endl;

  //seqOrdSearch
  int value;
  cout<<"What value are you searching for?"<<endl;
  cin>>value;

  if(myArray.seqSearch(value)==-1)
    cout<<value<<" is not in the list"<<endl;
  else
    cout<<value<<" is at index " <<myArray.seqSearch(value)<<endl;

  //removeOrd
  int deleteValue;
  cout<<"What value would you like to delete?"<<endl;
  cin>>deleteValue;
  myArray.removeOrd(deleteValue);

  cout<<"The updated list after deletion is"<<endl;
  cout<<"List:";
  myArray.print();
  cout<<"List Size:"<<myArray.listSize()<<endl;
  cout<<"Max List Size:"<<myArray.maxListSize()<<endl;
  
  return 0;
  
}