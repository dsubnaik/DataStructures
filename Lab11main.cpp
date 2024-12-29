#include <iostream>
#include <string>
#include "myStack.h"
#include "queueType.h"

using namespace std;

bool balance(string);
void reverseQueue(queueType<int> &, int);
void binarySequences(int,string);

int main()
{
  string string1="{ }";
  string string2="( )";
  string string3="{ }";
  
  cout<<string1<<"is ";
  if(balance(string1))
    cout<<"balanced"<<endl;
  else
    cout<<"not balanced"<<endl;
  
  cout<<string2<<"is ";
  if(balance(string2))
    cout<<"balanced"<<endl;
  else
    cout<<"not balanced"<<endl;

  cout<<string3<<"is ";
  if(balance(string3))
    cout<<"balanced"<<endl;
  else
    cout<<"not balanced"<<endl;
  

  queueType<int> myQueue;
  myQueue.addQueue(1);
  myQueue.addQueue(2);
  myQueue.addQueue(3);
  myQueue.addQueue(4);
  myQueue.addQueue(5);
  cout<<"\nBefore reverse"<<endl;
  myQueue.printQueue();

  cout<<"\nAfter reversing 3 elements"<<endl;
  reverseQueue(myQueue,3);
  myQueue.printQueue();

  cout<<"Binary Sequences of length 3 without repeating 1"<<endl;
  binarySequences(3,"");
  
}
//balanced brackets check
bool balance(string s)
{
  stackType<char> myStack;

  for(int i=0;i<s.length();i++)
    {
      //pushes the opening brackets onto the stack
      if(s[i]=='('||s[i]=='['||s[i]=='{')
        myStack.push(s[i]);
      //if the closing brackets are found, it checks to see if the top of the stack matches the
      else if(s[i]==')'||s[i]==']'||s[i]=='}')
      {
        //if the stack is empty, it returns false
        if(myStack.isEmptyStack())
        {
          return false;
        }
      }
        //if the top of the stack is a closing bracket, it checks 
        //to see if the top of the stack matches the closing bracket
        else
        {
          char symbol=myStack.top();
          myStack.pop();//pops stack because if it is equal the it will need to check the rest of brackets
          if((s[i]==')' && symbol!='(' )||(s[i]=='}' && symbol!='{' )||(s[i]==']' && symbol!='['))
          {
            return false;
          }
        }
      }

  return myStack.isEmptyStack();
  //if the stack is empty then returns true otherwise false because 
  //there would be something in the queue that wasnt checked
}
//reverse queue function
void reverseQueue(queueType<int> & theQueue, int k)
{
  //if the queue is empty or invalid input
  if(theQueue.isEmptyQueue() || k<0)
    cout<<"Error!!!"<<endl;
  else
  {
    
    queueType<int> tempQueue;
    //adds the first three elements of the orginal queue to an temporary queue
    for(int i=0;i<k;i++)
      {
        int temp=theQueue.front();
        tempQueue.addQueue(temp);
        theQueue.deleteQueue();
      }
    stackType<int> tempStack;
    //adds the temporary queue to a temporary stack
    for(int i=0;i<k;i++)
      {
        tempStack.push(tempQueue.front());
        tempQueue.deleteQueue();
      }
    //adds the top of the stack to the temporary queue  and then pops the stack
    for(int i=0;i<k;i++)
      {
        tempQueue.addQueue(tempStack.top());
        tempStack.pop();
      }
    //adds the rest of the elements from original queue to the temporary queue
    while(!theQueue.isEmptyQueue())
      {
        tempQueue.addQueue(theQueue.front());
        theQueue.deleteQueue();
      }
    //puts the temporary elements into the original queue
    while(!tempQueue.isEmptyQueue())
    {
      theQueue.addQueue(tempQueue.front());  
      tempQueue.deleteQueue();
    }
  }
  
}
void binarySequences(int n, string s="")
{
  if(s.length()==n)//base case
  {
    cout<<s<<", ";
    return;//returns to previous call
  }
  if(s.length()<n)// if string is less than n then add 0 to stirng
    binarySequences(n,s+"0");
  
  if(s.empty() || s[s.length()-1]=='0')//if stack is empty or if the last element is 0 then add 1 to the string
    binarySequences(n,s+"1");
  
}