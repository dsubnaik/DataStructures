//Header file linkedQueue.h

#ifndef NodeType
#define NodeType

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

#endif

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>

using namespace std;

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a
// linked list.
//*************************************************************

template <class Type>
class linkedQueueType {
public:
    const linkedQueueType<Type>& operator=
  (const linkedQueueType<Type>&);
  //Overload the assignment operator.

    bool isEmptyQueue() const;
  //Function to determine whether the queue is empty.
  //Postcondition: Returns true if the queue is empty,
  //    otherwise returns false.

    bool isFullQueue() const;
  //Function to determine whether the queue is full.
  //Postcondition: Returns true if the queue is full,
  //    otherwise returns false.

    void initializeQueue();
  //Function to initialize the queue to an empty state.
  //Postcondition: queueFront = NULL; queueRear = NULL

    Type front() const;
  //Function to return the first element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: If the queue is empty, the program
  //    terminates; otherwise, the first element of the
  //    queue is returned.

    Type back() const;
  //Function to return the last element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: If the queue is empty, the program
  //    terminates; otherwise, the last element of the
  //    queue is returned.

    void addQueue(const Type& queueElement);
  //Function to add queueElement to the queue.
  //Precondition: The queue exists and is not full.
  //Postcondition: The queue is changed and queueElement is
  //    added to the queue.

    void deleteQueue();
  //Function  to remove the first element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: The queue is changed and the first element
  //    is removed from the queue.

  void copyQueue(const linkedQueueType<Type>& otherQueue);
  // copy queue written by Yoav Kadosh (Therefore, be carefull!)


  linkedQueueType();
  //Default constructor

    linkedQueueType(const linkedQueueType<Type>& otherQueue);
  //Copy constructor

    ~linkedQueueType();
  //Destructor

    void moveNthFront(int);
    //move an element of the list to the front of the list

  void printQueue()const;

  nodeType<Type> *frontNode() const
  { return queueFront;}

private:
    nodeType<Type> *queueFront; //pointer to the front of the queue
    nodeType<Type> *queueRear;  //pointer to the rear of the queue
};

//Default constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = NULL; //set front to null
    queueRear = NULL;  //set rear to null
} //end default constructor

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == NULL);
} //end

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;

    while (queueFront!= NULL)  //while there are elements left
    //in the queue
    {
        temp = queueFront;  //set temp to point to the
    //current node
        queueFront = queueFront->link;  //advance first to
    //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = NULL;  //set rear to NULL
} //end initializeQueue


template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = NULL;  //initialize the link field to NULL

    if (queueFront == NULL) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != NULL);
    return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert(queueRear!= NULL);
    return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the
    //first node
        queueFront = queueFront->link; //advance queueFront

        delete temp;    //delete the first node

        if (queueFront == NULL) //if after deletion the
      //queue is empty
            queueRear = NULL;   //set queueRear to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


//Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
  initializeQueue();
} //end destructor

template <class Type>
void linkedQueueType<Type>::copyQueue
(const linkedQueueType<Type>& otherQueue) {

  nodeType<Type> *newNode, *current, *last;

    if (queueFront != NULL) //if queue is nonempty, make it empty
        initializeQueue();

    if (otherQueue.queueFront == NULL)
        queueFront = NULL;
    else {
        current = otherQueue.queueFront;  //set current to point
    //to the queue to be copied

        queueFront = new nodeType<Type>;  //create the node

        queueFront->info = current->info; //copy the info
        queueFront->link = NULL;  //set the link field of the
    //node to NULL
        last = queueFront;        //set last to point to the node
        current = current->link;    //set current to point to
    //the next node

    //copy the remaining queue
        while (current != NULL) {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while

    queueRear = last;
    }//end else

}


template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue) {

  if (this != &otherQueue) //avoid self-copy
        copyQueue(otherQueue);

    return *this;

} //end assignment operator

//copy constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) {
    queueFront = NULL;
    copyQueue(otherQueue);
}//end copy constructor

//move an element of the list to the front of the list
template<class Type>
void linkedQueueType<Type>::moveNthFront(int index)
{
  cout<<"\nMoving Element["<<index<<"] to the front"<<endl;

  nodeType<Type> *currentNode;//used to traverse the list
  nodeType<Type> *previousNode;

  currentNode=queueFront;
  previousNode=nullptr;

  int count=0;

  //traverse through the list until index is found
  while(currentNode!=nullptr && count!=index-1)
    {
      previousNode=currentNode;
      currentNode=currentNode->link;
      count++;
    }
  //if index is not found
  if(currentNode==nullptr)
  {
    cout<<"Invalid Index"<<endl;
  }
    //when index is found
  else
  {
    previousNode->link=currentNode->link;//links the previous node to the next node
    currentNode->link=queueFront;//current node to the front of the list
    queueFront=currentNode;//assigns queueFront to node when index was found
  }


}
//display the list
template<class Type>
void linkedQueueType<Type>::printQueue()const
{
  nodeType<Type> *nodePtr;//traverses through the list
  nodePtr=queueFront;

  int i=0;
  cout<<"\nLinked Queue Elements:"<<endl;
  cout<<"-------------------------"<<endl;
  while(nodePtr)
    {
      cout<<"Index["<<i<<"]: "<<nodePtr->info<<endl;
      nodePtr=nodePtr->link;
      i++;
    }
}
#endif