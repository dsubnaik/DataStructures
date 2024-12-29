//Derrick Subnaik
//Data Structures 
//Fall 2023 Prof:Huyen Le
//Lab 5 Part A
//9.27.2023

#include <iostream>
using namespace std;


template<class elemType>//template
//arrayList class
class arrayList
{
  protected:
    //memeber members
    elemType *list;
    int length;
    int maxSize;
  public:
    //public members
    arrayList(int size);
    arrayList(const arrayList<elemType>& otherList);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    void insertAt(int location, const elemType& insertItem);
    void removeAt(int location);
    void remove(const elemType& removeItem);
    void removeAll(const elemType& removeItem);
};
//arrayList constrcutor
template<class elemType>
arrayList<elemType>::arrayList(int size)
{
  //checks array size
  if(size<0)
  {
    cout<<"Array Size must be positive, setting array size to 100"<<endl;
    maxSize=100;//sets to zero if number passed is negative
  }
  else
    maxSize=size;
  length=0;
  list = new elemType[maxSize];//dynamically allocate array
}
//copy constructor
template<class elemType>
arrayList<elemType>::arrayList(const arrayList<elemType>& otherList)
{
  maxSize=otherList.maxSize;
  length=otherList.length;
  list= new elemType[maxSize];
  assert(list!=NULL);
  for (int j = 0; j < length; j++)
    list [j] = otherList.list[j];
}
//returns if the list is empty
template<class elemType>
bool arrayList<elemType>::isEmpty()const
{
  return(length==0);
}
//returns of the list if full
template<class elemType>
bool arrayList<elemType>::isFull()const
{
  return(length==maxSize); 
}
//returns the length of the array
template<class elemType>
int arrayList<elemType>::listSize()const
{
  return length;
}
//returns the maxSize of the array
template<class elemType>
int arrayList<elemType>::maxListSize()const
{
  return maxSize;
}
//displays elements in the array
template<class elemType>
void arrayList<elemType>::print()const
{
  for(int i=0;i<length;i++)
    cout<<list[i]<<" ";
}
//inserts a Item at a specific location
template<class elemType>
void arrayList<elemType>::insertAt(int location, const elemType& insertItem)
{
//checks if list is full
  if(length>maxSize)
    cout<<"The list is full, cannotInsert"<<endl;
    //checks if location is whithin in the array
  else if(location<0 || location>=maxSize)
    cout<<"The location is not within range"<<endl;
  else
  {
    //shifts elements over
    for(int i=length;i>location;i--)
      list[i]=list[i-1];
    list[location]=insertItem;//sets array location to item being passed
    length++;//increases length
  }
}
//removes a specefic location in the array
template<class elemType>
void arrayList<elemType>::removeAt(int location)
{
  //checks if location is range
  if(location<0 || location>=length)
    cout<<"location is out of range"<<endl;
  else
  {
    //swaps the location with the last element in the array 
    elemType temp=list[location];
    list[location]=list[length-1];
    list[length-1]=temp;
    length--;//decreases the array length by one
  }
}
//removes the first of the item that is being passed
template<class elemType>
void arrayList<elemType>::remove(const elemType& removeItem)
{
  for(int i=0;i<length;i++)
    {
      if(list[i]==removeItem)//checks if array element is equal to item
      {
        //if the array element is found then this array will shift everything
        for(int j=i;j<length;j++)
          {
            list[j]=list[j+1];
          }
        length--;//decreases array size by one because we removed one
        break;//exits the loop because we are removing only one
      }
         
    }
}
//removes all of the number being passed
template<class elemType>
void arrayList<elemType>::removeAll(const elemType& removeItem)
{
  for(int i=0;i<length;i++)
    {
      if(list[i]==removeItem)//checks if array element is equal to item
      {
        //if the array element is found then this array will shift everything
        for(int j=i;j<length;j++)
          {
            list[j]=list[j+1];
       
          }
        length--;//decreases array size by one because we removed one
            i--;//makes sure that after shifting the current index doesn't have the number we are removing
      }
    }
}
int main() 
{
  int num;
  int insertNum;
  int insertPosition;
  int removePos;
  int removeNum;
  int removeAll;
  int arraySize;
  int numsToBeEntered;
  cout<<"How big is your array"<<endl;
  cin>>arraySize;
  arrayList<int> myList(arraySize);//create the list of arraySize elements
  cout<<"How many numbers are you entering?"<<endl;
  cin>>numsToBeEntered;
  cout<<"Enter "<<numsToBeEntered<<" numbers"<<endl;//asks the user to enter 5 elements
  //adds each number entered into array
  for(int i=0;i<numsToBeEntered;i++)
    {
      cin>>num;
      myList.insertAt(i,num);//calls function
    }
  //display the list
  cout<<"\nThe list you entered is: ";
  myList.print();

  //check and display if the list is empty
  cout<<"\nLets check if the array is empty"<<endl;;
  
  if(myList.isEmpty())
    cout<<"The array is empty"<<endl;
  else
    cout<<"The array is not empty"<<endl;

  //check and display if the array is full
  cout<<"\nIs the array full?"<<endl;
  if(myList.isFull())
    cout<<"The array is full"<<endl;
  else
    cout<<"The array is not full"<<endl;

  //displays the size of the array
  cout<<"\nThe array size is: ";
  cout<<myList.listSize(); 
//displays the max amount elements in the array
  cout<<"\nThe max amount of elements in this list is ";
  cout<<myList.maxListSize()<<endl;

  //insert a number at a specific position
  cout<<"\nWhat number would you like to add?"<<endl;
  cin>>insertNum;
  cout<<"What position would you like to add it?"<<endl;
  cin>>insertPosition;
  myList.insertAt(insertPosition-1,insertNum);
  myList.print();

  //remove a specific position
  cout<<"\nWhat is the position of the element you want to remove"<<endl;
  cin>>removePos;
  myList.removeAt(removePos-1);
  myList.print();

  //remoce a specific number
  cout<<"\nWhat number would you like to remove?"<<endl;
  cin>>removeNum;
  myList.remove(removeNum);
  myList.print();

  cout<<"\nLets remove all of a specific number"<<endl;
  cin>>removeAll;
  myList.removeAll(removeAll);
  myList.print();
  

}
