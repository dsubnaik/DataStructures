//Derrick Subnaik
//Homework 3 
//COSC 2437-Data Structures
//Professor: Huyen Le
//Due Date:10/22/2023
#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

template<class T>
LinkedList<T> function1(LinkedList<T> &,LinkedList<T> &);
template<class T>
bool function2(LinkedList<T> &,LinkedList<T> &);
int main()
{
  LinkedList<double> obj;
  LinkedList<double>obj2;
  obj2.appendNode(10);
  obj2.appendNode(8);
  obj2.appendNode(6);
  obj2.appendNode(4);
  obj2.appendNode(2);
  //append values
  obj.appendNode(1);
  obj.appendNode(3);
  obj.appendNode(5);
  obj.appendNode(7);
  obj.appendNode(9);
  cout<<"The list after appending odd integers less than 10: "<<endl;
  obj.displayList();

  //inserting the number 2
  cout<<"\nThe list after inserting the number 2: "<<endl;
  obj.insertNode(2);
  obj.displayList();

  //deleting the number 5
  cout<<"\nThe list after deleting the number 5: "<<endl;
  obj.deleteNode(5);
  obj.displayList();

  //displayig the number of nodes
  cout<<"\nThe number of nodes in the list: "<<obj.numNodes()<<endl;

  //searching and displaying the position of number 7
  cout<<"\nThe number 7 is located at position: "<<obj.search(7)<<endl;

  //displaying the third position in the list
  cout<<"\nThe third node in this list: "<<obj.getValueAt(2)<<endl;

  //adding all values in the linked list
  cout<<"\nThe sum of all values: "<<obj.getTotal()<<endl;

  //displaying the average of all the nodes
  cout<<"\nThe average of all the nodes: "<<obj.getAverage()<<endl;
  //display the largest value in the list
  cout<<"\nThe largest value in the list: "<<obj.getLargest()<<endl;

  //displaying the position of the largest value
  cout<<"\nThe largest value is at position "<<obj.getLargestPosition()<<endl;

  //display the smallest value in the list
  cout<<"\nThe smallest value in the list: "<<obj.getSmallest()<<endl;

  //displaying the position of the smallest value
  cout<<"\nThe smallest value is at position: "<<obj.getSmallestPosition()<<endl;

  //inserting an element in the begining of list
  obj.insertFront(0);
  obj.insertEnd(10);
  cout<<"\nThe list after inserting 0 int the beginning 10 at the end is: ";
  obj.displayList();
  
  cout<<"\nDeleting the last value in the list which is:"<<obj.deleteLast()<<endl;

  cout<<"\nDeleting the first value which is: "<<obj.deleteFront()<<endl;

  cout<<"\nDisplay the list after deleting the first and last values"<<endl;
  obj.displayList();

  cout<<"\nDisplaying using recursing: ";
  obj.recursiveInOrder();

  cout<<"\nDisplaying in reverse order using recursion: ";
  obj.reverseOrder();

  cout << "\nDisplaying every other node in the linked list: ";
  obj.everyOther(); 

  cout<<"\nThe number of nodes in this list: "<<obj.recursiveCount();

  cout<<"\nLets search for number 7:"<<endl;
  if(obj.recursiveSequentialSearch(7))
    cout<<"Number 7 is in the list"<<endl;
  else
    cout<<"Number 7 is not in the list"<<endl;

  LinkedList<double> mergedAndSorted = function1(obj, obj2);
  cout<<"Merged and sorted list:";
  mergedAndSorted.displayList();

  bool check;
  check=function2(obj,obj2);
  if(check)
    cout<<"The list are equal"<<endl;
  else
    cout<<"The list are not equal"<<endl;
}
//functions1 accepts two linkedList objects and merges the two and then sorts the new list
template<class T>
LinkedList<T> function1(LinkedList<T> &list1, LinkedList<T> &list2)
{
  LinkedList<T> obj3;//create a new obj for the list

  //creates a new node that is used to traverse the list
  typename LinkedList<T> ::ListNode *nodePtr;
  typename LinkedList<T> ::ListNode *nodePtr2;
  //assigns the nodes to the beginning
  nodePtr=list1.getHead();
  nodePtr2=list2.getHead();

  //adds the contents of the first and second list to the new list
  while(nodePtr || nodePtr2)
    {
      if(nodePtr)
      {
        obj3.appendNode(nodePtr->value);
        nodePtr=nodePtr->next;
      }
      if(nodePtr2)
      {
        obj3.appendNode(nodePtr2->value);
        nodePtr2=nodePtr2->next;
      }
    }

  //sorts the obj3
  typename LinkedList<T> ::ListNode *currentNode;
  typename LinkedList<T> ::ListNode *previousNode;
  currentNode=obj3.getHead();
  previousNode=nullptr;
  
  if(!currentNode)
    cout<<"list is empty"<<endl;

  T temp;
  //swapping loop
  bool check=true;
  while(check)
    {
      check=false;
      while(currentNode->next)
      {
      if(currentNode->value > currentNode->next->value)
      {
        temp=currentNode->value;
        currentNode->value=currentNode->next->value;
        currentNode->next->value=temp;
        check=true;
      }
        currentNode=obj3.getHead();
      }
      previousNode=currentNode;
      currentNode=currentNode->next;
    }
  return obj3;
} 
//checks if the linked list are equal
template<class T>
bool function2(LinkedList<T> & list1,LinkedList<T> & list2)
{

  if(list1.getTotal()!=list2.getTotal())
  {
    return false;
  }
  else 
  {
    typename LinkedList<T> ::ListNode *nodePtr=list1.getHead();
    typename LinkedList<T> ::ListNode *nodePtr2=list2.getHead();

    while(nodePtr && nodePtr2)
      {
        if(nodePtr->value!=nodePtr2->value)
        {
          return false;
        }
          nodePtr=nodePtr->next;
          nodePtr2=nodePtr2->next;
      }
    //if they are equal to each other
    return true;
  }
    
}



