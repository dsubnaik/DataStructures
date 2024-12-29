//Derrick Subnaik
//Data Structures HW3
//Professor: Huyen Le
//11.2.2023

#include <iostream>
#include "myStack.h"

using namespace std;

double evaluate(string s);
string binary(int n);

int main() 
{
  string s="2 3 + 2 4 1 + - *";//string
  
  cout<<s<<" = "<<evaluate(s)<<endl;//cout string and output

  int binaryNumber;
  cout<<"\nEnter a decimal number to find the binary: ";
  cin>>binaryNumber;
  
  cout<<"The binary number of "<<binaryNumber<<" is:"<<binary(binaryNumber)<<endl;
  
  
}
double evaluate(string s)
{
  stackType<int> myStack;
  //loop iterates through entire string
  for(int i =0;i<s.length();i++)
    {
      if(isdigit(s[i]))//checks if it is a digit
      {
        int num=0;
        //this loops covers the case in which the number is greater than 9
        while(i<s.length() && isdigit(s[i]))
          {
            num=num*10+(s[i]-'0');
            i++;
          }
        myStack.push(num);//adds the number to the stack
        i--;//removes the last increment of the while loop to avoid skipping characters
      }
      else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
      {
        if(myStack.isEmptyStack())//invalid case
        {
          cout<<"Invalid Expression"<<endl;
          return 0;
        }
        
        int operand1=myStack.top();//sets operand1 equal to top element of stack
        myStack.pop();//removes the top element

        if(myStack.isEmptyStack())//invalid case
        {
          cout<<"Invalid Expression"<<endl;
          return 0;
        }

        int operand2=myStack.top();//sets operand1 equal to top element of stack
        myStack.pop();//removes the now top element
        
        switch(s[i])
          {
            case '+'://case of addition
                myStack.push(operand2+operand1);
                break;
            case '-'://case of subtraction
                myStack.push(operand2-operand1);
                break;
            case '*'://case of multiplication
                myStack.push(operand2*operand1);
                break;
            case '/'://case of division
                myStack.push(operand2/operand1);
                break;
          }
      }
    }
  return myStack.top();
}
//returns the binary string of the given integer
string binary(int n)
{
  stackType<int> binaryStack;

  //loop iterates until n<0 in this case 0 will end the loop
  while(n>0)
  {
    binaryStack.push(n%2);//push 1 or 0 to stack
    n /=2;//divide n by 2 
  }
  
  string binaryString=" ";
  while(!binaryStack.isEmptyStack())//iterates until stack is empty
    {
      binaryString+=to_string(binaryStack.top());
      binaryStack.pop();//pop the first element so we do not read it again
    }
   return binaryString;//return string
}