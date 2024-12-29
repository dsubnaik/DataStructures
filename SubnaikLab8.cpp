//Derrick Subnaik
//Lab 8
//Fall 2023
//Prof:Huyen Le
#include <iostream>
using namespace std;

string decimalToBinary(int);
int binarySequences(int, string,int,int);
int main()
{
  int decimal;
  cout << "Enter an integer number n:";
  cin>>decimal;
  cout<<"The binary version of "<<decimal<<" is: "<<decimalToBinary(decimal)<<endl;

  int num;
  cout<<"Enter an integer n:";
  cin>>num;
  cout<<"All binary sequences of "<<num*2<<" such that the sum of first "<<num<<" is same as sum of last "<<num<<" bits are: ";
    char str[2*num+1];
  
    cout<<binarySequences(0,str,0,2*num-1)<<endl;
  
  

  
}
//decimal to binary conversion
string decimalToBinary(int num)
{
  if(num==0)//base case
  {
    return "0";
  }
  else if(num%2)//if the ramainder of num/2 is 1
  {
    return decimalToBinary(num/2)+"1";
  }
  else//if the remainder of num/2 is 0
  {
    return decimalToBinary(num/2)+"0";
  }
}
//binary sequences returns all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits
int binarySequences(int n, string str, int start, int end)
{
  if(start>end)//base case
  {
    int leftSum=0,rightSum=0;
      //calculates the sum of the left and right bits
    for(int i=0;i<n;i++)
      {
        leftSum+=(str[i]-'0');
        rightSum+=(str[i+1]-'0');
      }
    if(leftSum==rightSum)//displaying the binary sequence 
      cout<<str<<" ";
  }
  //fix the first and last values
  str[start]='1';
  str[end]='1';
  binarySequences( n,  str,  start+1,  end-1);
  
  str[start]='0';
  str[end]='0';
   binarySequences( n,  str,  start+1,  end-1);

  str[start]='1';
  str[end]='0';
   binarySequences( n,  str,  start+1,  end-1);

  str[start]='0';
  str[end]='1';
   binarySequences( n,  str,  start+1,  end-1);

  
  
}
