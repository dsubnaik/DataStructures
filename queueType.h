//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operation on a queue as an
// array.
//*************************************************************
#include<iostream>
using namespace std; 
template <class Type>
class queueType
{
public:
  const queueType<Type>& operator=(const queueType<Type>&);
  //Overload the assignment operator.

  bool isEmptyQueue() const;
  //Function to determine whether the queue is empty.
  //Postcondition: Returns true if the queue is empty,
  // otherwise returns false.

  bool isFullQueue() const;
  //Function to determine whether the queue is full.
  //Postcondition: Returns true if the queue is full,
  // otherwise returns false.

  void initializeQueue();
  //Function to initialize the queue to an empty state.
  //Postcondition: The queue is empty.

  Type front() const;
  //Function to return the first element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: If the queue is empty, the program
  // terminates; otherwise, the first element of the
  // queue is returned.

  Type back() const;
  //Function to return the last element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: If the queue is empty, the program
  // terminates; otherwise, the last element of the queue
  // is returned.

  void addQueue(const Type& queueElement);
  //Function to add queueElement to the queue.
  //Precondition: The queue exists and is not full.
  //Postcondition: The queue is changed and queueElement is
  // added to the queue.

  void deleteQueue();
  //Function to remove the first element of the queue.
  //Precondition: The queue exists and is not empty.
  //Postcondition: The queue is changed and the first element
  // is removed from the queue.



  queueType(int queueSize = 100);
  //Constructor

  queueType(const queueType<Type>& otherQueue);
  //Copy constructor

  ~queueType();
  //Destructor


  void copyQueue(const queueType<Type> &otherQueue );
  //copyQueue function

  void moveNthFront(int);
  //move an element of the list to the front of the list

  void printQueue()const;
  //prints the elements of the queue

private:
  int maxQueueSize; //variable to store the maximum queue size
  int count; 		  //variable to store the number of elements in the queue
  int queueFront;   //variable to point to the first element of the queue
  int queueRear; 	  //variable to point to the last element of the queue
  Type *list; 	  //pointer to the array that holds the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
  return (count == 0);
} //end isEmptyQueue

template <class Type>
bool queueType<Type>::isFullQueue() const
{
  return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void queueType<Type>::initializeQueue()
{
  queueFront = 0;
  queueRear = maxQueueSize - 1;
  count = 0;
} //end initializeQueue

template <class Type>
Type queueType<Type>::front() const
{
  assert(!isEmptyQueue());
  return list[queueFront];
} //end front

template <class Type>
Type queueType<Type>::back() const
{
  assert(!isEmptyQueue());
  return list[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
  if (!isFullQueue())
  {
    queueRear = (queueRear + 1) % maxQueueSize; //use the
    //mod operator to advance queueRear
    //because the array is circular
    count++;
    list [queueRear] = newElement;
  }
  else 
    cout << "Cannot add to a full queue." << endl;
} //end addQueue

template <class Type>
void queueType<Type>::deleteQueue()
{
  if (!isEmptyQueue())
  {
    count--;
    queueFront = (queueFront + 1) % maxQueueSize; //use the
    //mod operator to advance queueFront
    //because the array is circular
  }
  else
    cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

template <class Type>
queueType<Type>::queueType(int queueSize)
{
  if (queueSize <= 0)
  {
    cout << "Size of the array to hold the queue must "
    << "be positive." << endl;
    cout << "Creating an array of size 100." << endl;
    maxQueueSize = 100;
  }
  else
    maxQueueSize = queueSize; //set maxQueueSize to queueSize

  queueFront = 0; //initialize queueFront
  queueRear = maxQueueSize - 1; //initialize queueRear
  count = 0;
  list = new Type [maxQueueSize]; //create the array to
  //hold the queue elements
} //end constructor

template <class Type>
queueType<Type>::~queueType()
{
  delete [] list;
}
//copy function
template<class Type>
void queueType<Type>::copyQueue(const queueType<Type> &otherQueue)
{
  //delete the contents of current list
  delete[] list;

  //assign the values
  maxQueueSize=otherQueue.maxQueueSize;
  count=otherQueue.count;
  queueFront=otherQueue.queueFront;
  queueRear=otherQueue.queueRear;

  list =new Type[maxQueueSize];//dynamic memory allocation

  //assign the contents of otherQueue to list
  for(int i=0;i<maxQueueSize;i++)
    {
      list[i]=otherQueue.list[i];
    }
}
//move an element of the list to the front of the list
template<class Type>
void queueType<Type>::moveNthFront(int index)
{
  //invalid index
  if(index<0 || index>=maxQueueSize || index<=queueFront )
    cout<<"Invalid Index"<<endl;

  Type temporary=list[index-1];
  int next=(queueFront+1) % maxQueueSize;//covers circular list

  while(next !=index-1)//shifts everything over until index
    {
      list[next]=list[next-1];
      next=(next+1) % maxQueueSize;
    }
  list[queueFront]=temporary;//the front is now what the index was
}
//prints the elements of the queue
template<class Type>
void queueType<Type>::printQueue()const
{
  cout<<"-------------------------"<<endl;
  //covers a circular list
  for(int i=queueFront;i<(queueRear+1)% maxQueueSize;i=(i+1) % maxQueueSize)
    {
      cout<<"Index["<<i<<"]: "<<list[i]<<endl;
    }
}









