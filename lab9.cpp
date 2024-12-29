#include <iostream>
#include "myStack.h"
#include "linkedStack.h"

using namespace std;

int main()
{
  // ******** array based ********	
  stackType<int> arrayStack1;
  stackType<int> arrayStack2;

  arrayStack1.push(10);
  arrayStack1.push(20);	
  arrayStack2.push(10);
  arrayStack2.push(20);

  /*
  Comparing the stacks at this point should return true
  Display a message to the screen indicating the result of the comparison
  */

  //calls the function to compare stacks
  if(arrayStack1.operator==(arrayStack2))
    cout<<"The array stacks are equal"<<endl;
  else
    cout<<"The array stacks are not equal"<<endl;

  arrayStack2.push(30);	//adds another element to the stack

  // Compare again, now it should be false
  cout<<"After adding another element to the second stack"<<endl;
  if(arrayStack1.operator==(arrayStack2))
    cout<<"The array stacks are equal"<<endl;
  else
    cout<<"The array stacks are not equal"<<endl;

  // ******** linked based ********
  linkedStackType<int> linkedStack1;
  linkedStackType<int> linkedStack2;

  linkedStack1.push(10);
  linkedStack1.push(20);	
  linkedStack2.push(10);
  linkedStack2.push(20);	

  /*
  Comparing the stacks at this point should return true
  Display a message to the screen indicating the result of the comparison
  */

  if(linkedStack1.operator==(linkedStack2))//calls the function to compare elements
    cout<<"\nThe linkedlist stacks are equal"<<endl;
  else
    cout<<"\nThe linkedlist stacks are not equal"<<endl;

  linkedStack2.push(30);	
  
  // Compare again, now it should be false
  cout<<"After adding an element to the second linkedlist stack"<<endl;
  
  if(linkedStack1.operator==(linkedStack2))//calls the function to compare elements
    cout<<"The linkedlist stacks are equal"<<endl;
  else
    cout<<"The linkedlist stacks are not equal"<<endl;


  return 0;
}