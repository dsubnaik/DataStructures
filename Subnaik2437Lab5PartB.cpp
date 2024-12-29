//Derrick Subnaik
//Data Structures 
//Fall 2023 Prof:Huyen Le
//Lab 5 Part B
//9.27.2023

#include <iostream>
using namespace std;

//class numberList
class NumberList
{
  private:
    struct ListNode
  {
    double value; // The value in this node
    struct ListNode *next; //To point to the next node
  };
    ListNode *head;
  public:
    NumberList(){ head = NULL; } //Constructor
    void appendNode(double); //Append a node to the end
    void displayList() const;
};
//adds a node at the end of the list
void NumberList::appendNode(double x)
{
 
  ListNode *newNode=new ListNode;
  ListNode *nodePtr;//for traversing throught the list
  newNode->value=x;//assign the newNode value to x
  newNode->next=nullptr;
   
  //if the list is empty it makes the first element the value being passed
  if(!head)
    head=newNode;
  else
  {
     
    nodePtr=head;
    while(nodePtr->next)
      {
        nodePtr=nodePtr->next;
      }
  nodePtr->next= newNode;//assign the new node
  }
}

//displays the elements of a linked list
void NumberList::displayList()const
{
 ListNode *nodePtr;
 nodePtr=head;
 while(nodePtr)
   {
     cout<<nodePtr->value<<endl;
     nodePtr=nodePtr->next;
   }

}
int main()
{
  NumberList obj;//create object
  //append numbers
  obj.appendNode(2.5);
  obj.appendNode(7.9);
  obj.appendNode(12.6);
  //display to user
  cout<<"Your linked list is:"<<endl;
  obj.displayList();
  
}