//Derrick Subnaik
//COSC-2437 Fall 2023
//Professor Huyen Le
//Homework 1 Problem 1

#include <iostream>
using namespace std;

//triangle class
class Triangle
{
  private:
    double base;
    double height;
    double area;
  public:
    void setBase(int);
    void setHeight(int);
    double getBase();
    double getHeight();
    double calcArea();
};
//sets the base of the triangle from user input
void Triangle::setBase(int b)
{
  base=b;
}
//sets the height of the triangle from user input
void Triangle::setHeight(int h)
{
  height=h;
}
//returns the base of the class
double Triangle::getBase()
{
  return base;
}
//returns the height of the triangle
double Triangle::getHeight()
{
  return height;
}
//calculates and returns the are of rectangle
double Triangle::calcArea()
{
  area=(base*height)/2;
  return area;
}
//main 
int main()
{
  int arraySize;
  
  //displays to user
  cout<<"Let's create an array of triangles!\n";
  cout<<"How many triangles would you like to create? ";
  cin>>arraySize;
  
  //dynamically allocate the array 
  Triangle *triArray= nullptr;
  triArray=new Triangle[arraySize];

  //for loop for getting the base and height of each triangle
  cout<<"\n";
  for(int i=0;i<arraySize;i++)
    {
      double base,height;

      //getting information from user
      cout<<"Enter the base for triangle "<<i+1<<": ";
      cin>>base;
      
      cout<<"Enter the height for triangle "<<i+1<<": ";
      cin>>height;

      //calls the setBase function in the class with user input
      triArray[i].setBase(base);
      triArray[i].setHeight(height);
    }

  
  double greatestArea=-1;//used to find the greatest area in the array of triangles
  int triangleNum;//used to find which triangle has the greatest area

  //for loop to search which triangle has the greatest area
  for(int i=0;i<arraySize;i++)
    {
     
      if(triArray[i].calcArea()>greatestArea)
      {
        greatestArea=triArray[i].calcArea();//sets area 
        triangleNum=i+1;//for displaying which triangle is the biggest one
      }
    }

  //display to user
  cout<<"\nThe triangle with the greatest area is traingle "<<triangleNum<<" with an area of " <<greatestArea<<endl;;
  delete [] triArray;
}