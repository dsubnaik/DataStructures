//Derrick Subnaik
//September 13, 2023
//Lab3

#include <iostream>
#include <string>// allows us to use string in program
using namespace std;

class Animal
{
//private function variables
  private:
    string name;//string name variable
    int numLegs;//in number of legs variable
  public:
    Animal();//animal default constructor 
    Animal(string,int);//animal constructor with parameters
    void setName(string);//set name function
    void setLegs(int);//set legs function
    string getName();//get name function
    int getLegs();// get legs function
    virtual string move();//virtual move function
    virtual string speak();//virtual speak function
    void print();// print function
};
//default constructor sets name to empty string and legs to 0
Animal:: Animal()
{
  name=" ";
  numLegs=0;
}
//constrcutor with parameters, uses values sub,itted by user
Animal::Animal(string n,int num)
{
  name=n;
  numLegs=num;
}
//sets the name equal to whatevers passed by user
void Animal::setName(string n)
{
  name=n;
}
//sets the legs passed to whatevers passed by user
void Animal::setLegs(int num)
{
  numLegs=num;
}
//returns the name
string Animal::getName()
{
  return name;
}
//returns the number of legs
int Animal:: getLegs()
{
  return numLegs;
}
//return empty string for animal class function speak
string Animal:: speak()
{
  return " ";
}
//return empty string for animal class function move
string Animal:: move()
{
  return " ";
}
//displays all information for animal
void Animal:: print()
{
  cout<<"\nMy name is "<<name<<endl;
  cout<<"I have "<<numLegs<<" legs"<<endl;
  cout<<speak()<<endl;
  cout<<move()<<endl;
}
// class cat derived from base class animal
class Cat: public Animal
{
  public:
    Cat(string,int);// cat cunctructor
    string move();//redefining move function
    string speak();//redefinig speak function
};
//Cat cunstroctor redefined from animal constructor
Cat::Cat(string n, int num):Animal(n, num)
{
}
//redefined move function in cat class
string Cat:: move()
{
  return "I slink around stealthly!";
}
//redefined speak function in cat class
string Cat:: speak()
{
  return "I say meow!";
}
//Dog class derived from animal class
class Dog: public Animal
{
  public:
    Dog(string,int);
    string move();
    string speak();
};
//redefined dog cunstroctor
Dog::Dog(string n, int num): Animal(n, num)
{
}
//redefined move function in dog class
string Dog:: move()
{
  return "I run with my tounge hanging out!";
}
//redefined speak function in dog class
string Dog:: speak()
{
  return "I say Woof!";
}

//this function is used to diaplay information
void display(Animal &dawg);

//main function
int main()
{
  
  Animal AnimalObj;//animal object
  Dog dawgObj("Dog",4);//dog object
  Cat catObj("Cat",4);//cat  object

  //call the function
  display(AnimalObj);
  display(catObj);
  display(dawgObj);
  
} 
//display function for objects
void display(Animal &dawg)
{
  dawg.print();
}