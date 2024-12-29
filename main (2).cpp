#include <iostream>
#include "arrayListType.h"

using namespace std;

int main() 
{
  arrayListType<int> myList(10);
  //insrting random numbers
  myList.insert(10);
  myList.insert(5);
  myList.insert(8);
  myList.insert(3);
  myList.insert(9);
  myList.insert(1);
  myList.insert(6);
  myList.insert(2);
  myList.insert(7);
  myList.insert(4);

  //displaying the list without sorting
  cout<<"List before sorting"<<endl;
  myList.print();

  
  myList.selectionSort();
  //displaying the list after selection sort
  cout<<"List after selection sort"<<endl;
  myList.print();


  myList.selectionSortDesc();
  //displaying the list after descendingselection sort
  cout<<"List after selection sort descending"<<endl;
  myList.print();

  //part c
  arrayListType<int> myList2(9);
  myList2.insert(34);
  myList2.insert(46);
  myList2.insert(19);
  myList2.insert(66);
  myList2.insert(27);
  myList2.insert(56);
  myList2.insert(13);
  myList2.insert(18);

  cout<<"Each iteration of selection sort"<<endl;
  myList2.selectionSortSteps();
//38, 28, 31, 20, 35, 40, 22, 81, 42, 68, 25
  arrayListType<int> myList3(11);
  myList3.insert(38);
  myList3.insert(28);
  myList3.insert(31);
  myList3.insert(20);
  myList3.insert(35);
  myList3.insert(40);
  myList3.insert(22);
  myList3.insert(81);
  myList3.insert(42);
  myList3.insert(68);
  myList3.insert(25);

  cout<<"Each iteration of insertion sort"<<endl;
  myList3.insertionSort();
  
  //Part C
  //selection sort
 /*After iteration 1: 13 46 19 66 27 56 34 18 
  After iteration 2:13 18 19 66 27 56 34 46 
  After iteration 3:13 18 19 66 27 56 34 46 
  After iteration 4:13 18 19 27 66 56 34 46 
  After iteration 5:13 18 19 27 34 56 66 46 
  After iteration 6:13 18 19 27 34 46 66 56 
  After iteration 7:13 18 19 27 34 46 56 66         */

  //38, 28, 31, 20, 35, 40, 22, 81, 42, 68, 25
  //insertion sort
  /* 
  After iteration 1:28 38 31 20 35 40 22 81 42 68 25 
  After iteration 2:28 31 38 20 35 40 22 81 42 68 25 
  After iteration 3:20 28 31 38 35 40 22 81 42 68 25 
  After iteration 4:20 28 31 35 38 40 22 81 42 68 25 
  After iteration 5:20 28 31 35 38 40 22 81 42 68 25 
  After iteration 6:20 22 28 31 35 38 40 81 42 68 25 
  After iteration 7:20 22 28 31 35 38 40 81 42 68 25 
  After iteration 8:20 22 28 31 35 38 40 42 81 68 25 
  After iteration 9:20 22 28 31 35 38 40 42 68 81 25 
  After iteration 10:20 22 25 28 31 35 38 40 42 68 81 
  
  
  
  
  
  */
}