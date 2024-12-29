//The function returns 24 when it is called with a value of 4
//Derrick Subnaik

#include <iostream>
using namespace std;
//mystery function
int mystery(int);

//main function
int main() 
{
  //display the number
  cout<<"The number with a for loop is "<<mystery(4);
}

//mystery function using a for loop
int mystery ( int number )
{  
  int total=number;//sets total equal to number
  
  //for loop to get the factorial number
  for(int i=number;i>1;i--)
    {
      total *=(number-1);
      number-=1;
    }
  return total;//return the total
}