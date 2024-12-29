//Derrick Subnaik
#include <iostream>
#include <string>
using namespace std;
//created the class called secretType
class secretType
{
  //private members of the class
  private:
  string name;
  int age;
  int weight;
  double height;

  //public members of the class
  public:
  secretType();//default contructor
  secretType(string, int,int,double);//constructor with variables
  void print();//print function
  void setName(string);//set name function
  void setAge(int);//set age function
  void setWeight(int);//set weight function
  void setHeight(double);//set heigth function
  string getName();//get name function
  int getAge();//get age function
  int getWeight();//get weight function
  double getHeight();//get height function
  
};
//default constructor sets blank sring to name and zeros to age,height and weight
secretType::secretType()
{
  name=" ";
  age=0;
  weight=0;
  height=0.0;
}
//constructors calls the functions of using the parameters
secretType::secretType(string n, int a,int w,double h)
{
  setName(n);
  setAge(a);
  setWeight(w);
  setHeight(h);
}
//prints the information that is the the class
void secretType:: print()
{
  cout<<"Name: "<<name<<endl;
  cout<<"Age: "<<age<<endl;
  cout<<"Weight: "<<weight<<endl;
  cout<<"Height: "<<height<<endl;
}
//this function sets the string being passed to name
void secretType::setName(string n)
{
  name=n;
}
//this function sets the int being passed to age
void secretType:: setAge(int a)
{
  age=a;
}
//this function sets the int being passed to weight
void secretType:: setWeight(int w)
{
  weight=w;
}
//this function sets the double  being passed to height
void secretType:: setHeight(double h)
{
  height=h;
}
//this function returns the string name when it is being called
string secretType:: getName()
{
  return name;
}
////this function returns the int when it is being called
int secretType:: getAge()
{
  return age;
}
//this function returns the wieght when it is being called
int secretType:: getWeight()
{
  return weight;
}
//this function returns the heigth when it is being called
double secretType::getHeight()
{
  return height;
}

//main function
int main()
{
  //created a object called my stats
  secretType myStats("Derrick", 19, 200, 5.8);
  myStats.print();//call the print 
  
}