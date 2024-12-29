#include "Date.h"
#include <iostream>
using namespace std;
//default constructor for Date class
Date::Date()
{
  month=1;
  date=1;
  year=1999;
}

//constructor with parameters for Date class
Date::Date(int m, int d, int y)
{
  //checks if the month is between 1 and 12 
  if(m>0 && m<13)
    month=m;
  //if it is an invalid month it sets month equal to zero
  else
    month=1;

  //checks if month has 31 days
  if(month==1 || month==3 || month==5|| month==7|| month==8|| month==10||month==12)
  {
    //checks if date is 1 and 31
    if(d>0 && d<32)
      date=d;
      
    //if month is not valid it is date is set to 1
    else
      date=1;
  }
    
  //checks if month has 30 days
  else if(month==4 || month==6||month==9||month==11)
  {
    //checks if date is between 1 and 30
    if(d>0 && d<31)
      date=d;

    //if date is not valid the it is set to 1
    else
      date=1;
  }

  //if month is february
  else
  {
    if(d>0 && d<29)
      date=d;
    else
      date=1;
  }
  if(y>0 && y<9999)
    year=y;
  else
    year=1999;
}
//this function sets the date of the function
void Date::setDate(int m, int d, int y)
{
  //checks if the month is valid
   if(m>0 && m<13)
    month=m;
  else
    month=1;
  //if the month has 31 days
  if(month==1 || month==3 || month==5|| month==7|| month==8|| month==10||month==12)
  {
    if(d>0 && d<32)
      date=d;
    else
      date=1;//if date is invaled
  }
    //if the month has 30 days
  else if(month==4 || month==6||month==9||month==11)
  {
    if(d>0 && d<31)
      date=d;
    else
      date=1;//if date is invalid
  }
    //if the month is february
  else
  {
    if(d>0 && d<29)
      date=d;
    else
      date=1;//ff date is invalid 
  }
  //valid year check
  if(y>0 && y<9999)
    year=y;
  else
    year=1999;//if year is invalid
}
void Date:: addDays(int d)
{
  int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};//array of months

  //checks if it is a leap year
  if(year%4==0)
    daysInMonth[1]=29;

  
  int arrayValue=month-1;
  date +=d;//adds number that is passed to date

  //this loop iterates until a valid date is available
  while(date>daysInMonth[arrayValue])
    {
     date-=daysInMonth[arrayValue];//subtracts the date until valid
      month++;//increments month everytime the month changes
      arrayValue++;//increments the arrayValue because of loop

      //for incrementing the year
      if(month>12)//makes sure the months doesn't go above 12
      {
        month=1;//sets equal to
        arrayValue=0;//array value is 0
        year++;//increments year
      }
    }
}

void Date:: subtractDays(int d)
{
   int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};//array for days in month
  if(year%4==0)//loop year check
    daysInMonth[1]=29;
  
  int arrayValue=month-1;
  date -=d;//subtracts what is passed from d

  //subtracting days so it will be while it is negative
  while(date<1)
    {
     date+=daysInMonth[arrayValue-1];//adds the date until valid
      month--;//decreases month 
      arrayValue--;//decreases arrayValue

      //makes sure the array value isnt negative
      if(arrayValue<0)
        arrayValue=11;
      //makes sures the year is decreased if that many days is subtracted 
      if(month<1)
      {
        month=12;//sets month to 12 
        year--;//descreases the year
      }
    }
}
//returns the date
int Date::getDay()const
{
  return date;
}
//returns the month
int Date:: getMonth()const
{
  return month;
}
//returns the year
int Date:: getYear()const
{
  return year;
}
//prints the date
void Date::printDate()const
{
  cout<<month<<"/"<<date<<"/"<<year<<endl;
}