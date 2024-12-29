//Derrick Subnaik
//Data Structures Homework 1 Problem 2
//Fall 2023 Professor Huyen Le

#include <iostream>
#include"Date.h"
using namespace std;

int main()
{
  Date obj;
  cout<<"The default constructor prints: ";
  obj.printDate();
  
  cout<<"\nLets use my Birthday to test the constructor with parameter: ";
  Date obj2(5,12,2004); 
  obj2.printDate();
  
  cout<<"\nThe month of my birthday is: ";
  cout<<obj2.getMonth();
  cout<<"\nThe day of my birthday is: ";
  cout<<obj2.getDay();
  cout<<"\nThe year of my birthday is:";
  cout<<obj2.getYear()<<endl;
  
  cout<<"\nLet's use the setDate function to set Independence day: ";
  Date obj3;
  obj3.setDate(7,4,1774);
  obj3.printDate();
  
  cout<<"\nLets add 30 days to Independence day: ";
  obj3.addDays(30);
  cout<<"\n30 days after Independence day is ";
  obj3.printDate();

  cout<<"\nLets subtract 30 days from my birthday ";
  obj2.subtractDays(30);
  cout<<"30 days after my birthday is ";
  obj2.printDate();
  
  
  
}