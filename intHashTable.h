//Integer hash table
#include<iostream>
#include<iomanip>
using namespace std;

const int DEFAULT_TABLE_SIZE = 17;

class intHashTable 
{
  public:
    ~intHashTable();
    intHashTable(int parameterSize = DEFAULT_TABLE_SIZE);
    int hashFunc(int);
    int add(int);
    bool search(int);
    void print();

  private:
    int *arr;
    int arrSize;
};

// Destructor 
intHashTable::~intHashTable()
{
  delete [] arr;
}

// Constructor
intHashTable::intHashTable (int parameterSize)
{
  if (parameterSize < 1)
  {
    cout << "Size of the hash table must be positive." << endl;
    cout << "Creating a hash table of size " << DEFAULT_TABLE_SIZE << "." << endl;
    arrSize = DEFAULT_TABLE_SIZE;
  }
  else
    arrSize = parameterSize; //set hash table size to parameter

  //***fill in the missing code here to declare the array and initialize all array elements to -1


  arr= new int[arrSize];//dynamic allocation of array

  for(int i=0;i<arrSize;i++)//setting each element to -1 for empty
    arr[i]=-1;



}

//---------------------------------------------------
// hashFunc
// Based on the value of new element, determine its index
//---------------------------------------------------
int intHashTable::hashFunc(int newVal) 
{
  //***fill in the missing code here to implement the division hashing function

  return newVal % arrSize;//returns the remainder

}	

//---------------------------------------------------
// add
// Adds a new node to the intHashTable
// Collisions are resolved by linear probing.
// Returns number of collisions too
//---------------------------------------------------
int intHashTable::add(int newVal) 
{
  //***fill in the missing code here to implement this function as requested
    int collisionCount=0;//keeps count of collisions
    int index=hashFunc(newVal);//where we will be inserting if available
    bool found=false;
    while(arr[index]!=-1 && !found)
      {
        if(arr[index]==newVal)
        {
          found=true;
        }
        else
        {
          collisionCount++;//collision occurred
         index=(index+1)%arrSize;
        }
          
      }
    if(found)
      cout<<"Duplicate items are not allowed"<<endl;
    else
      arr[index]=newVal;//inserting

    return collisionCount;//returns the number of collisions
}


//---------------------------------------------------
// search
// Searches through the intHashTable for 'key'. 
// Returns true if found and false otherwise
//---------------------------------------------------


bool intHashTable::search(int key) 
{
  //***fill in the missing code here to implement this function as requested
  int index=hashFunc(key);
  int start=index;

  while(true)
    {
      if(arr[index]==-1)//case that is false because empty index
        return false;
      if(arr[index]==key)//true case
      {
        return true;
      }
      index=(index+1)%arrSize;//covers circular array
      if(index==start)//false case went throught entire array
        return false;
    }
}


//---------------------------------------------------
// Outputs the entire list to the screen
//---------------------------------------------------
void intHashTable::print() 
{
  for(int i = 0; i < arrSize; i++)
    cout << setw(3) << i << ": " << setw(6) << arr[i] << endl;

  return;
}
