//Derrick Subnaik
//Data Structures Lab 4

#include <iostream>
using namespace std;

//myClass class 
class myArray
{
  private:
    int *arr; // points to the array
    int maxSize; // the capacity
    int nextIndex; // the index of the next available element
  public:
    myArray(int size); // the constructor
    ~myArray(); // the destructor
    void display(); //display the array
    void add(int val); // add a new value to the end
    void remove(); // remove an item at the end
};
//myClass constructor
myArray::myArray(int size)
{
  //checling that we do not have a negative array
  if(size<0)
  {
    cout<<"The array must be greater than 0"<<endl;
    cout<<"Please enter a number greater than 0"<<endl;
    cin>>size;
  }
    //when the array is greater than 0
  else
    maxSize=size;
  nextIndex=0;
  arr= new int[maxSize];
};
//array destructor
myArray::~myArray()
{
  delete [] arr;
}
//display the array elements
void myArray::display()
{
  for(int i=0;i<nextIndex;i++)
    {
      cout<<arr[i]<<" ";
    }
};
//insert a value to end of the list
void myArray::add(int val)
{
  //checks to see if the array is full
  if(nextIndex>=maxSize)
    cout<<"Cannot insert in a full list"<<endl;
  else
  {
    arr[nextIndex]=val;//adds the calue to the end of the array
    nextIndex++;//makes the array one size bigger
  }
};
//remove function, remoces the last element of the array
void myArray::remove()
{
  nextIndex--;
  while(nextIndex>0)
    {
      cout<<"\nAfter removing, the list is: ";
      display();
      nextIndex--;
    }
  cout<<"\nAfter removing, the list is: Empty List!"<<endl;
    cout<<"Cannot remove from an empty array."<<endl;
  
  }

//main function
int main()
{
  int x,y,z;
  int arraySize;

  //asks the user for array size
  cout<<"Enter size of the array: ";
  cin>>arraySize;
  
  myArray obj(arraySize);//create an object and pass array size to constructor

  //recieve three integers from the user
  cout<<"\nEnter three integer: ";
  cin>>x;
  cin>>y;
  cin>>z;

  //add the three values entered by the user
  obj.add(x);
  obj.add(y);
  obj.add(z);

  //display the aray to user
  cout<<"The array you entered is ";
  obj.display();
  
  obj.remove();//remove function of array
 
 
  
}