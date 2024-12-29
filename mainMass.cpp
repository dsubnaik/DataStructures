//Derrick Subnaik
//Homework 1 Problem 3

#include<iostream>
#include "Mass.h"
using namespace std;
//main function
int main() 
{
  //create two objects
  Mass obj1(5);
  Mass obj2(10);

  //display the two initial values of the first two objects
  cout<<"Inital Values:"<<endl;
  cout<<"Mass 1:"<<endl;
  obj1.display();
  cout<<"\nMass 2:"<<endl;
  obj2.display();

  //creates another object and sets it equal to the sum of the first two objects
  Mass obj3= obj1+obj2;
  cout<<"\nThe addition of obj1 and obj2:"<<endl;
  obj3.display();//display objects three

  Mass obj4=obj3+800;//object 4 is equal to object 3 plus grams
  cout<<"\nCreated obj4 which is obj3 plus 800 grams"<<endl;
  obj4.display();//display object 4

  //subtract object is equal to obj2-obj1
  Mass subtract= obj2-obj1;
  cout<<"\nThe subtraction of obj2 and obj1:"<<endl;
  subtract.display();//display subtract object

  //assign object is assigned to obj1
  Mass assign =obj1;
  cout<<"\nThe assignment of obj1:"<<endl;
  assign.display();//display assign object

  //checks if the two objects are equivalent and displays it
  bool equivalentCheck=obj1==obj2;
  if(equivalentCheck)
    cout<<"\nObj1 and Obj2 are equivalent"<<endl;
  else
    cout<<"\nObj1 and Obj2 are not equivalent"<<endl;

  //checks if obj1 is greater than obj2
  bool greaterThanCheck=obj1>obj2;
  if(greaterThanCheck)
    cout<<"\nObj1 is greater than Obj2"<<endl;
  else
    cout<<"\nObj1 is not greater than Obj2"<<endl;

  //checks if obj1 is less than obj2
  bool lessThanCheck=obj1<obj2;
  if(lessThanCheck)
    cout<<"\nObj1 is less than Obj2"<<endl;
  else
    cout<<"\nOb1 is not less than Obj2"<<endl;

  //checks if obj1 !=obj2
  bool notEquivalentCheck=obj1!=obj2;
  if(notEquivalentCheck)
    cout<<"\nObj1 and Obj2 are not equivalent"<<endl;
  else
    cout<<"\nObj1 and Obj2 are equivalent"<<endl;

  //adds obj1 and obj2
  obj1+=obj2;
  cout<<"\nAdding obj1 and obj2"<<endl;
  obj1.display();

  //adds 900 grams to obj1
  obj1+=900;
  cout<<"\nAdding 900 grams to obj1"<<endl;
  obj1.display();
  
  
  
}