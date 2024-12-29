#ifndef H_arrayListType
#define H_arrayListType

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of array-based lists.
//***********************************************************

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class arrayListType
{
  public:
    const arrayListType<elemType>& operator=
               (const arrayListType<elemType>&);
      //Overloads the assignment operator
    bool isEmpty() const;
      //Function to determine whether the list is empty
      //Postcondition: Returns true if the list is empty; 
      //    otherwise, returns false.
    bool isFull() const;
      //Function to determine whether the list is full.
      //Postcondition: Returns true if the list is full; 
      //    otherwise, returns false.
    int listSize() const;
      //Function to determine the number of elements in the list
      //Postcondition: Returns the value of length.
    int maxListSize() const;
      //Function to determine the size of the list.
      //Postcondition: Returns the value of maxSize.
    void print() const;
      //Function to output the elements of the list
      //Postcondition: Elements of the list are output on the 
       //   standard output device.
    void clearList();
      //Function to remove all the elements from the list. 
      //After this operation, the size of the list is zero.
      //Postcondition: length = 0;
    int seqSearch(const elemType& item) const;
      //Function to search the list for a given item. 
      //Postcondition: If the item is found, returns the location 
      //    in the array where the item is found; otherwise,
      //    returns -1.
    void insert(const elemType& insertItem);
      //Function to insert the item specified by the parameter 
      //insertItem at the end of the list. However, first the
      //list is searched to see whether the item to be inserted 
      //is already in the list. 
      //Postcondition: list[length] = insertItem and length++
      //     If the item is already in the list or the list
      //     is full, an appropriate message is displayed.
    arrayListType(int size = 100);
      //constructor
      //Creates an array of the size specified by the 
      //parameter size. The default array size is 100.
      //Postcondition: The list points to the array, length = 0, 
      //    and maxSize = size
    arrayListType(const arrayListType<elemType>& otherList); 
      //copy constructor
    ~arrayListType();
      //destructor
      //Deallocates the memory occupied by the array.


      //TODO: add sorting functions here
      //add the selection sort functions
      void selectionSort();
      //add descending sort function here
      void selectionSortDesc();

      void selectionSortSteps();//same as selectionsort but prints after each iteration

      void insertionSort();//insertion sort function

  private:

  protected:
    elemType *list;  //array to hold the list elements
    int length;      //to store the length of the list
    int maxSize;     //to store the maximum size of the list
    //part a two helper functions
    void swap(int,int);
    int minLocation(int, int);
    int maxLocation(int,int);
};

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;

    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)    //the item to be inserted does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
                 << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{	
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}


//copy constructor
template <class elemType>
arrayListType<elemType>::arrayListType
                   (const arrayListType<elemType>& otherList)
{
  maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate memory space

    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
}

// overloading assignment operator (equals sign)
template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
                      (const arrayListType<elemType>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete [] list; 

        list = new elemType[maxSize];  //create the array
        assert(list != NULL);   //if unable to allocate memory space, terminate the program 
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i]; 
    }

    return *this; 
}

template <class elemType>
void arrayListType<elemType>::selectionSort() {
  /**************************
  complete this function with your implementation
  ***************************/
  int lowestIndex;
  for(int i=0;i<length-1;i++)
    {
      lowestIndex=minLocation(i,length);//finds the index of the lowest value
      swap(lowestIndex,i);//swaps the index of the lowest value and the current index
    }
}

template <class elemType>
void arrayListType<elemType>::selectionSortDesc() {
  /**************************
  complete this function with your implementation
  ***************************/
  int maxIndex;
  for(int i=0;i<length-1;i++)
    {
      maxIndex=maxLocation(i,length);//find the highest index
      swap(i,maxIndex);//swaps the index of the highest value and the current value
    }
}
//part a swap helper function
//swaps the two values being passed
template<class elemType>
void arrayListType<elemType>::swap(int first,int last)
{
  elemType temp=list[first];
  list[first]=list[last];
  list[last]=temp;
}
//part a minLocation helper function
//returns the index of the lowest element
template<class elemType>
int arrayListType<elemType>::minLocation(int first, int last)
{
  int lowestIndex=first;
  for(int i=first+1;i<last;i++)
    {
      if(list[i]<list[lowestIndex])
        lowestIndex=i;
    }
  return lowestIndex;
}
//this function returns the highest index in the list
template<class elemType>
int arrayListType<elemType>::maxLocation(int first, int last)
{
  int maxIndex=first;
  for(int i=first+1;i<last;i++)
    {
      if(list[i]>list[maxIndex])
        maxIndex=i;
    }
  return maxIndex;
}
//this function does a selection sort but displays the list after each loop iteration
template <class elemType>
void arrayListType<elemType>::selectionSortSteps() {
  /**************************
  complete this function with your implementation
  ***************************/
  int lowestIndex;
  for(int i=0;i<length-1;i++)
    {
      lowestIndex=minLocation(i,length);//finds the index of the lowest value
      swap(lowestIndex,i);//swaps the index of the lowest value and the current index
      print();
      
    }
}
//insertionSort function
template <class elemType>
void arrayListType<elemType>::insertionSort()
{
  int pivot=1;
  while(pivot<length)
    {
      elemType temp=list[pivot];
      int i=pivot-1;
      while(i>=0 && list[i]>temp)
        {
          list[i+1]=list[i];
          i--;
        }
      
      list[i+1]=temp;
      print();
      pivot++;
    }
}
#endif