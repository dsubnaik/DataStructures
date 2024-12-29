#include <iostream>
#include <fstream>
#include <vector>
#include "intHashTable.h"
using namespace std;

int main()
{
  intHashTable theTable(13);//create hash table

  ifstream myFile;
  myFile.open("data.txt");//open file
  if(!myFile.is_open())
    cout<<"File is not open"<<endl;

  //reading data from file and storing into vector
  vector <int> data;
  int number;
  while(myFile>>number)
    {
      data.push_back(number);
    }
  myFile.close();

  int sum=0;//keeps track of number of collisions
  //adds data to the hash table
  for(int i=0;i<data.size();i++)
    sum +=theTable.add(data[i]);//sums the number of collisions

  cout<<"The total number of collisions is "<<sum<<endl;
  
  theTable.print();//print table

  //testing if 1 is in the table
  if(theTable.search(1))
    cout<<"1 is in the table"<<endl;
  else
    cout<<"1 is not in the table"<<endl;

  //testing if 18 is in the table
  if(theTable.search(18))
    cout<<"18 is in the table"<<endl;
  else
    cout<<"18 is not in the table"<<endl;

  //testing if 21 is in the table
  if(theTable.search(21))
    cout<<"21 is in the table"<<endl;
  else
    cout<<"21 is not in the table"<<endl;

  //testing if 1952 is in the table
  if(theTable.search(1952))
    cout<<"1952 is in the table"<<endl;
  else
    cout<<"1952 is not in the table"<<endl;

  //testing if 4507 is in the table
  if(theTable.search(4507))
    cout<<"4507 is in the table"<<endl;
  else
    cout<<"4507 is not in the table"<<endl;

  //testing if 3529 is in the table
  if(theTable.search(3529))
    cout<<"3529 is in the table"<<endl;
  else
    cout<<"3529 is not in the table"<<endl;
}