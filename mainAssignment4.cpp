//Derrick Subnaik
//COSC 2437 Assignment 4
//Professor: Huyen Le
//November 12, 2023

#include <iostream>
#include "linkedQueueType.h"
#include "myStack.h"

using namespace std;

//removes the nth element and returns the value of that element
template<class Type>
Type removeNthElement(linkedQueueType<Type> &, int);

//returns true if two queuesare equal
template<class Type>
bool queueCheck(linkedQueueType<Type> &, linkedQueueType<Type> &);

//splits an even number array into two different arrays
template<class Type>
void splitQueue(linkedQueueType<Type> &);

//returns true if a string of characters is a palindrome or not
bool isPalindrome(string);

int main()
{

  linkedQueueType<int> queue;
  for(int i=1;i<5;i++)
    {
      queue.addQueue(i);
    }

  linkedQueueType<int> queue2;//another queue
  for(int i=1;i<5;i++)
  {
    queue2.addQueue(i+1);
  }
  //display current list to user
  cout<<"The elements in the queue 1 are: ";
  queue.printQueue();

  cout<<"The elements in queue 2 are: ";
  queue2.printQueue();
  
  int removeIndex;
  cout<<"Enter the index of the element you would like to remove in queue 1: ";
  cin>>removeIndex;

  //removing the element entered by user
  cout<<"The value of index "<<removeIndex<<" is "<<removeNthElement(queue,removeIndex)<<endl;

  //display to user after deleting the element
  cout<<"Now the elements in the queue are: "<<endl;
  queue.printQueue();

  
  
  //checks if the queues are equal
  cout<<"Testing if Queue 1 and Queue 2 are equal: "<<endl;
  cout<<"Queue 1 and Queue 2 are ";
  if(queueCheck(queue,queue2))
    cout<<"equal"<<endl;
  else
    cout<<"not equal"<<endl;

  //will use for problem 1 part c
  linkedQueueType<int> queue3;
  for(int i=1;i<11;i++)
    {
      queue3.addQueue(i);
    }

  cout<<"Queue 3:";
  queue3.printQueue();
  //testing problem 1 part c
  cout<<"Splitting Queue 3"<<endl;
  splitQueue(queue3);


  //palindrome test
  string s;
  cout<<"Enter a string to see if is a palindrome"<<endl;
  cin>>s;
  if(isPalindrome(s))
    cout<<s<<" is a palindrome"<<endl;
  else
    cout<<s<<" is not a a palindrome"<<endl;
  
}

//this function removes the nth element of the queue and returns that element to main
template< class Type>
Type removeNthElement(linkedQueueType<Type> &myQueue, int n)
{
  nodeType <Type> *nodePtr=myQueue.frontNode();//used to traverse the list
  nodeType <Type> *previousNode=nullptr;
  
  int count=0;
  while(nodePtr && n !=count)//ends when list is done or n is reached
    {
      previousNode=nodePtr;
      nodePtr=nodePtr->link;
      count++;
    }
  Type temp=Type();
  if(!nodePtr)//reached the end of list and n was not reached
    cout<<" not in range"<<endl;
  else
  {
    temp=nodePtr->info;
    if(previousNode)
    {
      previousNode->link=nodePtr->link;
      delete nodePtr;
    }
    else
      myQueue.deleteQueue();//the first element needed to be deleted
    
  }

  return temp;//returns the value of the removed element
}

//this function returns true if both queues are equal and false if they are not 
template<class Type>
bool queueCheck(linkedQueueType<Type> & queue1, linkedQueueType<Type> & queue2)
{
  //used to traverse the list
  nodeType<Type> *currentNode1=queue1.frontNode();
  nodeType<Type> *currentNode2=queue2.frontNode();

  while(currentNode1 && currentNode2) //iterates until null
    {
      if(currentNode1->info != currentNode2->info)//if the elements are not equal then false will be returned
        return false;

      currentNode1=currentNode1->link;
      currentNode2=currentNode2->link;

    }

  if(currentNode1 || currentNode2)//if they aren't both null then they are not equal
    return false;
  else 
    return true;
}
//this fucntion splits an even queue into two queues
template<class Type>
void splitQueue(linkedQueueType<Type> & myQueue)
{
  linkedQueueType<Type> queue1;
  linkedQueueType<Type> queue2;

  int count=0;
  nodeType<Type> *nodePtr=myQueue.frontNode();

  //finds how many elements in the original queue
  while(nodePtr)
    {
      nodePtr=nodePtr->link;
      count++;
    }

  if(count%2==0)//makes sure the size is an even number
  {
    nodePtr=myQueue.frontNode();
    for(int i=0;i<count/2;i++)//adds the first half of the elements to the queue
      {
        queue1.addQueue(nodePtr->info);
        nodePtr=nodePtr->link;
      }
    for(int i=count/2;i<count;i++)//adds the second half of elements to a different queue
      {
        queue2.addQueue(nodePtr->info);
        nodePtr=nodePtr->link;
      }
    cout<<"First half of queue: "<<endl;
    queue1.printQueue();
    cout<<"Second half of queue"<<endl;
    queue2.printQueue();
  }
  else
    cout<<"Odd number of elements in queue"<<endl;
}

//using a stack and a queue to check if a string is a palindrome
bool isPalindrome(string s)
{
  //converts any capital letters to lowercase
  for(int i=0;i<s.length();i++)
    {
      s[i]=tolower(s[i]);
    }

  stackType <char> stack1;//create stack
  linkedQueueType<char> queue1;//create queue

  //adds alpahbet letters of string to stack and queue
  for(int i=0;i<s.length();i++)
    {
      if(isalpha(s[i]))
      {
        stack1.push(s[i]);
        queue1.addQueue(s[i]);
      }
    }

  //checks if the top element of stack is equal to the front element of queue
  while(!stack1.isEmptyStack() && !queue1.isEmptyQueue())
    {
      if(stack1.top() != queue1.front())
        return false;//returns false if not equal
      else
      {
        stack1.pop();
        queue1.deleteQueue();
      }
    }
  
  return true;//returns true if it is a palindrome
}