#include "Mass.h"
#include <iostream>
using namespace std;

//Mass default constructor
Mass::Mass()
{
  tonne=0;
  kilogram=0;
  gram=0;
}
//constructor with a parameters
Mass::Mass(double t)
{
  tonne=t;
  kilogram=t*1000;
  gram=t*1000000;
}
//getTonne function
double Mass::getTonne()const
{
  return tonne;
}
//getKilogram function
double Mass::getKilogram()const
{
  return kilogram;
}
//getGram function
double Mass:: getGram()const
{
  return gram;
}
//Mass operator+ function adds two MAss objects
Mass Mass::operator+(Mass &m)
{
  return Mass(tonne + m.tonne);
}
//Mass operator+ functions adds grams to object
Mass Mass::operator+(int g)
{
  tonne=tonne + g/1000000.0;
  kilogram=kilogram+g/1000.0;
  gram=gram+g;
  return *this;
}
//Subtracts to mass objects
Mass Mass::operator-(Mass &m)
{
  return Mass(tonne-m.tonne);
}
//Sets a mass object equal to another one
Mass Mass::operator=(Mass &m)
{
  return Mass(tonne=m.tonne);
}
//checks if two mass objects are equal to each other
bool Mass::operator==(Mass &m)
{
  return(tonne==m.getTonne());
}
//checks if a mass object is less than another mass object
bool Mass::operator>(Mass &m)
{
  return(tonne>m.getTonne());
}
//checks if a mass object is greater than another mass object
bool Mass::operator<(Mass &m)
{
  return(tonne<m.getTonne());
}
//checks if a mass object is not equal to another mass object
bool Mass::operator!=(Mass &m)
{
  return(tonne!=m.getTonne());
}
//using += operator to add two mass objects
Mass Mass::operator+=(Mass &m)
{
  tonne+=m.tonne;
  return *this;
}
//using += to add grams to a mass object
Mass Mass::operator+=(int g)
{
  tonne += g/1000000.0;
  kilogram+=g/1000.0;
  gram+=g;
  return *this;
}
//displays information
void Mass::display() const
{
  cout<<"Tonne: "<<tonne<<endl;
  cout<<"Kilogram: "<<kilogram<<endl;
  cout<<"Gram: "<<gram<<endl;
}