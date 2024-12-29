//Derrick Subnaik Lab2 
//September 6, 2023
#include <iostream>
using namespace std;

//Base class Polygon
class Polygon
{
  protected:
    int width;
    int height;
  public:
    void set_values(int,int);
    virtual int area();//virtual function
};
//setHeigth function
void Polygon:: set_values(int h,int w)
{
  height=h;
  width=w;
}
//polygon area will always return 0
int Polygon:: area()
{
   cout<<"Area as a Polygon object: ";
  return 0;
}
//Derived class Rectangle from Polygon class
class Rectangle: public Polygon
{
  public:
//area of rectangle
    int area()
   {
      cout<<"Area as a Rectangle object: ";
      return width*height;//calculate area
   }
  
};
//Derived class Triangle from Polygon class
class Triangle: public Polygon
{
  public:
//area function of triangle
    int area()
       {
         cout<<"Area as a Triangle object: ";
         return (height*width)/2;//area of triangle formula
       }
};
void print(Polygon &g);//function prototype
int main() 
{
  //createobjects
  Polygon obj;
  Triangle obj2;
  Rectangle obj3;
  //call functions with 4 and 5
  obj.set_values(4,5);
  obj2.set_values(4,5);
  obj3.set_values(4,5);

  //call function 
  print(obj);
  print(obj2);
  print(obj3);
  
}
void print(Polygon &g)//pass object 
{
  cout<<g.area()<<endl;//call area to display
}