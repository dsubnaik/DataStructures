//Derrick Subnaik
//Homework 3 
//COSC 2437-Data Structures
//Professor: Huyen Le
//Due Date:10/22/2023
#ifndef LinkedList_h
#define LinkedList_h
//class declaration
template <class T>
class LinkedList
{
private:
 struct ListNode
{
 T value;
 struct ListNode *next;
 };
 ListNode *head; // List head pointer

public:
 LinkedList();// Constructor
 ~LinkedList(); // Destructor
 void appendNode(T);
 void insertNode(T);
 void deleteNode(T);
 void displayList();
 int numNodes();
 int search(T);
 T getValueAt(int position);
 T getTotal();
 T getAverage();
 T getLargest();
 int getLargestPosition();
 T getSmallest();
 int getSmallestPosition();
 void insertFront(T val);
 void insertEnd(T val);
 T deleteLast();
 T deleteFront();
 void recursiveInOrder();
 void recursiveInOrder(ListNode*);
 void reverseOrder();
 void reverseOrder(ListNode *);
 void everyOther();
 void everyOther(ListNode*,bool);
 int recursiveCount();
 int recursiveCount(ListNode*);
  bool recursiveSequentialSearch(T);
  bool recursiveSequentialSearch(ListNode*, T);
  ListNode* getHead()
  {
    return head;
  }
};
#endif