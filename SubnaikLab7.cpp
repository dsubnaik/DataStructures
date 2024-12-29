//Derrick Subnaik
//Lab 7-Recursive Functions
//10.11.2023
//Professor Huyen Le

#include <iostream>
using namespace std;

//function prototypes
int sumOfValues(int [],int);
int vowelCount(string,int);
string reverseOrder(string,int,int);
bool palindrome(string,int,int);
int main() 
{
  int myArray[]={1,2,3,4,5,6,7,8};//create array
  int size=sizeof(myArray)/sizeof(myArray[0]);//finds the size of the array
  cout<<"Sum of the array is: "<<sumOfValues(myArray,size)<<endl;//display to user

  //testing of vowelCount function
  string myString="TODAY IS A GOOD DAY";
  int strSize=myString.size(); //size of string
  cout<<"\nNumber of Vowels in "<<myString<<" is "<<vowelCount(myString,strSize)<<endl;

  //testing of reverseOrder function
  string reverseString="Hello";
  int startValue=1;
  int endValue=3;
  cout<<"\n"<<reverseString<<" in reverse order(startvalue= "<<startValue<<" endvalue= "<<endValue<<" is: "<<reverseOrder(reverseString,startValue,endValue)<<endl;

  //teting od palindrome function
  string palindromeString="aabbccccbbaa";
  if(palindrome(palindromeString,0,palindromeString.size()))
    cout<<"\n"<<palindromeString<< " is a palindrome"<<endl;
  else
    cout<<"\n"<<palindromeString<< " is not a palindrome"<<endl;
    
  
}
//sumOfValues function uses recursion to find the sum of an array
int sumOfValues(int array[], int size)
{
  if(size==1)//base case
    return array[0];
  else 
    return array[size-1]+sumOfValues(array,size-1);
}
//this function returns the number of vowels in a string
int vowelCount(string str, int size)
{
  if(size==1)//base case
  {
    str[size-1]=toupper(str[size-1]);//converts to uppercase if the letter was ever lowercase
    if(str[size-1]== 'A' || str[size-1]== 'E' ||str[size-1]== 'I' ||str[size-1]== 'O' ||str[size-1]== 'U')
      return 1;
    else 
      return 0;
  }
  else
  {
    str[size-1]=toupper(str[size-1]);//converts to uppercase if the letter was ever lowercase
    if(str[size-1]== 'A' || str[size-1]== 'E' ||str[size-1]== 'I' ||str[size-1]== 'O' ||str[size-1]== 'U')
      return 1+vowelCount(str,size-1);
    else
      return vowelCount(str,size-1);
  }
}
//reverse the order of the string depending on the values that are passed
string reverseOrder(string str, int begin, int end)
{
  if(begin>=end)//base case
    return str;
  else
  {
    //swap values
    char temp=str[begin];
    str[begin]=str[end];
    str[end]=temp;
    return reverseOrder(str,begin+1,end-1);
  }    
}
//palindrome function returns true if the string is a palindrome and false if it is not
bool palindrome(string str,int start, int size)
{
  if(start>=size)//base case
    return true;
  else if(str[start]==str[size-1])
    return palindrome(str,start+1,size-1);
  else 
    return false;
}