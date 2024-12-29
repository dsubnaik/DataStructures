//Derrick Subnaik
//Homework 3 
//COSC 2437-Data Structures
//Professor: Huyen Le
//Due Date:10/22/2023
#include <iostream>
#include "LinkedList.h"

using namespace std;

//constructor sets head equal to null
template<class T>
LinkedList<T>::LinkedList()
{
  head=nullptr;
}
//destructor destroys list
template<class T>
LinkedList<T>::~LinkedList()
{
  ListNode *nodePtr;//used to traverse trough the list
  ListNode *nextNode;//point to the next node

  nodePtr=head;

  while(nodePtr)//iterates as long as nodePtr is not null
    {
      nextNode=nodePtr->next;//traverses the list
      delete nodePtr;//deletes node

      nodePtr=nextNode;
    }

}
//appendNode function adds the value that is being passed to the end of the list
template<class T>
void LinkedList<T>::appendNode(T num)
{
  ListNode *nodePtr;//used to traverse through the list
  ListNode *newNode;//creates a new node

  newNode=new ListNode;//dynamically allocate 

  newNode->value=num;//stores the value of num into newNode
  newNode->next=nullptr;//newNode is the last node

  if(!head)//case of empty list
    head=newNode;
  else
  {
    nodePtr=head;
  while(nodePtr->next)//traverses through the list until null
      nodePtr=nodePtr->next;

  nodePtr->next=newNode;//sets the value of the last node to newNode
  }
}
//insert a node in the list, inserts in order
template<class T>
void LinkedList<T>:: insertNode(T num)
{
  ListNode *nodePtr;//to traverse throught the list
  ListNode *previousNode;//will be used to point to previous node
  ListNode *newNode;//creates a new node
  newNode= new ListNode;//dynamically allocate

  newNode->value=num;//assign value

  //case of an empty list
  if(!head)
  {
    head=newNode;
    newNode->next=nullptr;
  }
  else
  {
    nodePtr=head;
    previousNode=nullptr;

    //this loop iterates until it finds the correct position to insert the node
    while(nodePtr!=nullptr && nodePtr->value<num)
      {
        previousNode=nodePtr;
        nodePtr=nodePtr->next;
      }
    //the case that it is inserted in the beginning of the list
    if(previousNode==nullptr)
    {
      head=newNode;
      newNode->next=nodePtr;;
    }
      //the case that it is inserted in the middle or the end of the list
    else
    {
      previousNode->next=newNode;
      newNode->next=nodePtr;
    }    
  }
}
//the deleteNode function deletes a node with a specific valued
template<class T>
void LinkedList<T>::deleteNode(T num)
{
  ListNode *nodePtr;//to traverse trough the list
  ListNode *previousNode;//will point to the previous node

  //the case that the list is empty
  if(!head)
    return;
//the case that the first node is to be deleted
  if(head->value == num)
  {
    nodePtr=head->next;
    delete head;
    head=nodePtr;
  }
  else
  {
    nodePtr=head;
    //loop iterates until null or num is found
    while(nodePtr && nodePtr->value != num)
      {
        previousNode=nodePtr;
        nodePtr=nodePtr->next;
      }
    if(nodePtr)
    {
      previousNode->next=nodePtr->next;//links the previous node to the node after the node being deleted
      delete nodePtr;//delete the node
    }
  }
}
//displays the elements of the list
template<class T>
void LinkedList<T>:: displayList()
{
  ListNode *nodePtr;//to traverse through the list
  nodePtr=head;

  if(!head)//if the list is empty
  {
    cout<<"The list is empty"<<endl;
  }
  else
  {
    while(nodePtr)//displays the elements of the list
    { 
      cout<<nodePtr->value<<" ";
      nodePtr=nodePtr->next;
    }
    cout<<endl;
  }
}
//numNodes function returns the number of nodes in the list
template<class T>
int LinkedList<T>::numNodes()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;

  int count=0;//counter
  if(!head)
    return 0;//the list is empty
  else
  {
    while(nodePtr)
      {
        nodePtr=nodePtr->next;
        count++;
      }
    return count;
  }
}
//search function returns the position of a node
template<class T>
int LinkedList<T>::search(T num)
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;

  int count=1;
  while(nodePtr)
    {
      if(nodePtr->value==num)
        return count;
      else
      {
        nodePtr=nodePtr->next;
        count++;
      }
    }
  if(!nodePtr)
    return -1;//number not found
}
//getValueAt returns the value at a specific position
template<class T>
T LinkedList<T>::getValueAt(int position)
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  int count=0;
  //traverse until nodePtr==null and count<<position
  while(nodePtr && count<position)
    {
      nodePtr=nodePtr->next;
      count++;
    }
  if(!nodePtr)//invalid position
    cout<<"Position out of range"<<endl;
  else
    return nodePtr->value;//returns the value
}
//the function getTotal returns the sum of all nodes in the list
template<class T>
T LinkedList<T>::getTotal()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T sum=0;
  if(!head)//empty list
    cout<<"The list is empty"<<endl;
  else
  {
  while(nodePtr)
    {
      sum+=nodePtr->value;//adds values
      nodePtr=nodePtr->next;
    }
  }
  return sum;
}
//the function getAverage returns the average of all nodes in the list
template<class T>
T LinkedList<T>::getAverage()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T sum=0;
  T count=0;
  if(!head)
    cout<<"The list is empty"<<endl;
  else
  {
  while(nodePtr)
    {
      sum+=nodePtr->value;//adds values
      nodePtr=nodePtr->next;
      count++;//increases count
    }
  }
  return sum/count;// average=sum/count
}
//the function getLargest returns the largest value of all nodes in the list
template<class T>
T LinkedList<T>::getLargest()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T largest=nodePtr->value;

  if(!head)
    cout<<"The list is empty"<<endl;
  else
  {
  while(nodePtr)
    {
      if(nodePtr->value>largest)//if the value is larger
        largest=nodePtr->value;

      nodePtr=nodePtr->next;//traverse the list
    }
  }
  return largest;//return largest
}
//the function getLargestPosition returns the position of largest value of all nodes in the list
template<class T>
int LinkedList<T>::getLargestPosition()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T largest=nodePtr->value;
  int position=1;
  int tempPosition=1;
  if(!head)
    cout<<"The list is empty"<<endl;
  else
  { 
  while(nodePtr)
    {
      if(nodePtr->value>largest)//if the value is larger
      {
        largest=nodePtr->value;
        position=tempPosition;//position of largest
      }

      nodePtr=nodePtr->next;//traverse the list
      tempPosition++;
    }
  }
  return position;//return largest
}
//the function getSmallest returns the smallest value of all nodes in the list
template<class T>
T LinkedList<T>::getSmallest()
{
  ListNode *nodePtr;//used to traverse the smallest
  nodePtr=head;
  T smallest=nodePtr->value;

  if(!head)
    cout<<"The list is empty"<<endl;
  else
  {
  while(nodePtr)
    {
      if(nodePtr->value<smallest)//if the value is smallest
        smallest=nodePtr->value;

      nodePtr=nodePtr->next;//traverse the list
    }
  }
  return smallest;//return smallest
}
//the function getSmallestPosition returns the position of the smallest value of all nodes in the list
template<class T>
int LinkedList<T>::getSmallestPosition()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T smallest=nodePtr->value;
  int position=1;
  int tempPosition=1;
  if(!head)
    cout<<"The list is empty"<<endl;
  else
  {
  while(nodePtr)
    {
      if(nodePtr->value<smallest)//if the value is smaller
      {
        smallest=nodePtr->value;
        position=tempPosition;
      }


      nodePtr=nodePtr->next;//traverse the list
      tempPosition++;
    }
  }
  return position;//return smallest
}
//insertFront function adds an element to the front of the list
template<class T>
void LinkedList<T>::insertFront(T val)
{
  ListNode *tempNode;
  ListNode *newNode;
  newNode=new ListNode;
  newNode->value=val;
  newNode->next=nullptr;
  //if the list is empty
  if(!head)
    head=newNode;
  //inserting at the beginning of the list
  else
  {
    tempNode=head;
    head=newNode;//makes it the beginning of the list
    head->next=tempNode;//links it to the rest of the list
  }
}
//insertEnd adds an element to the end of the list
template<class T>
void LinkedList<T>::insertEnd(T val)
{
  ListNode *nodePtr;//used to traverse through the list
  ListNode *newNode;//creates a new node

  newNode=new ListNode;//dynamically allocate 

  newNode->value=val;//stores the value of num into newNode
  newNode->next=nullptr;//newNode is the last node

  if(!head)//case of empty list
    head=newNode;
  else
  {
    nodePtr=head;
  while(nodePtr->next)//traverses through the list until null
      nodePtr=nodePtr->next;

  nodePtr->next=newNode;//sets the value of the last node to newNode
  }
}
//deleteLast function deletes the last node and returns the value of the deleted node
template<class T>
T LinkedList<T>::deleteLast()
{
  ListNode *nodePtr;//used to traverse the list
  nodePtr=head;
  T val;//the value that is going to be deleted
  ListNode *previousNode=nullptr;
  if(!head)
    cout<<"The list is empty"<<endl;
    //if there is only one node in the list
  else if(!head->next)
  {
    val=head->value;
    delete head;
    head=nullptr;//keeps it a linked list
    return val;
  }
  else
  {
    while(nodePtr->next)
      {
        previousNode=nodePtr;
        nodePtr=nodePtr->next;
      }
    val=nodePtr->value;
    delete nodePtr;
    previousNode->next=nullptr;//keeps it a linked list
    return val; 
  }
}
//deleteFront function deletes the first node and returns the value of the deleted node
template<class T>
T LinkedList<T>::deleteFront()
{
  ListNode *tempNode;
  tempNode=head;
  T val;//the value that is going to be deleted

  if(!head)
  cout<<"The list is empty"<<endl;
  else
  {
    {
      tempNode=head;
      val=tempNode->value;
      head=head->next;//links head to the rest of the list
      delete tempNode;
      return val;
    }
  }
}
//recursively display the linked list in order
template<class T>
void LinkedList<T>::recursiveInOrder()
{
  recursiveInOrder(head);//calls the function with a parameter
}
template<class T>
void LinkedList<T>::recursiveInOrder(ListNode *nodePtr)
{
  if(nodePtr)//until nodePtr
  {
    cout<<nodePtr->value<<" ";//displays the value
    recursiveInOrder(nodePtr->next);////calls the function with the next node
  }
}  
//recursivley displays the linked list in reverse order
template<class T>
void LinkedList<T>::reverseOrder()
{
  reverseOrder(head);
}
template<class T>
void LinkedList<T>::reverseOrder(ListNode *nodePtr)
{
  if(nodePtr)
  {
    reverseOrder(nodePtr->next);
    cout<<nodePtr->value<<" ";//displays after the function is done being called
  }
}
//recursively displays every other element in a linked list
template<class T>
void LinkedList<T> ::everyOther()
{
  everyOther(head, true);
}
template<class T>
void LinkedList<T> ::everyOther(ListNode *nodePtr, bool check)
{
  if(nodePtr)//as long as node isnt nullptr
  {
    if(check)//if bool check is false it will not display anyhting, which causes it to skip
    {
      cout<<nodePtr->value<<" ";
    }
    everyOther(nodePtr->next,!check);//switches bool each time
  }
}
//returns the count of the linked list using recursion
template<class T>
int LinkedList<T>:: recursiveCount()
{
  return recursiveCount(head);
}
template<class T>
int LinkedList<T>:: recursiveCount(ListNode *nodePtr)
{
  if(!nodePtr)
    return 0;
  else
    return 1 + recursiveCount(nodePtr->next);
}
//return true if the linked list has the value passed in the parameter
template<class T>
bool LinkedList<T>::recursiveSequentialSearch(T val)
{
  return recursiveSequentialSearch(head,val);
}
template<class T>
bool LinkedList<T>::recursiveSequentialSearch(ListNode *nodePtr,T val)
{
  //base case, if the node reaches null, it is not in the list
  if(!nodePtr)
    return 0;
    //chech if the current node == val
  else if(nodePtr->value==val)
    return 1;
  else
    //move through the list
    return recursiveSequentialSearch(nodePtr->next,val);
}