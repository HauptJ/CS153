#include <iostream>
#include "MyBSTree.cpp"
#include "gtest/gtest.h"
using namespace std;


//------------------------------------------------------
void test1()
{
  MyBSTree<int>  t;
  
  cout << endl << endl << "***** " << "Test #1" << endl;
  
  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
  EXPECT_TRUE(t.isEmpty());
    
  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);

  
  t.print();
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;
  EXPECT_FALSE(t.isEmpty());
  cout << "--" << endl;
  cout << "height = " << t.height() << endl;
  EXPECT_EQ(t.height(), 4);
  cout << "size = " << t.size() << endl;
  EXPECT_EQ(t.size(), 7);
  cout << "--" << endl;


  return;
}


//------------------------------------------------------
void test2()
{
  MyBSTree<char> t;
  
  cout << endl << endl << "***** " << "Test #2" << endl;
  
  t.insert('F');
  t.insert('A');
  t.insert('C');
  t.insert('G');
  t.insert('B');
  t.insert('S');
  t.insert('K');
  t.insert('U');
  t.insert('L');
  t.insert('K');
  
  t.print();
  cout << "--" << endl;
  cout << "Min = " << t.findMin() << endl;
  EXPECT_EQ(t.findMin(), 'A');
  cout << "Max = " << t.findMax() << endl;
  EXPECT_EQ(t.findMax(), 'U');

  return;
}


//------------------------------------------------------
void test3()
{
  MyBSTree<string> t;
  MyBSTree<string> t2;
  
  cout << endl << endl << "***** " << "Test #3" << endl;

  t.insert(string("Paul"));
  t.insert(string("John"));
  t.insert(string("George"));
  t.insert(string("Ringo"));
  t.insert(string("Fry"));
  t.insert(string("Leela"));
  t.insert(string("Zoidberg"));

  
  t.print();
  cout << "--" << endl;
  cout << "Testing Operator = " << endl;
  t2 = t;
  t2.print();
  
  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("George"));
  t2.remove(string("John"));
  t2.remove(string("Ringo"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();
  EXPECT_NE(t2.size(), t.size());
  EXPECT_LT(t2.contains("George"), 0);
  EXPECT_LT(t2.contains("John"), 0);
  EXPECT_LT(t2.contains("Ringo"), 0);

  return;
}


//------------------------------------------------------
void test4()
{
  MyBSTree<string> t;
  
  cout << endl << endl << "***** " << "Test #4" << endl;

  t.insert(string("Pizza"));
  t.insert(string("Burger"));
  t.insert(string("HotDog"));
  t.insert(string("Shake"));
  t.insert(string("Fry"));
  t.insert(string("Salad"));
  t.insert(string("Soda"));

  
  t.print();
  cout << "--" << endl;
  cout << "Testing Copy COnstructor " << endl;
  MyBSTree<string> t2(t);
  t2.print();
  
  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  t2.remove(string("Pizza"));
  t2.remove(string("Salad"));
  t2.remove(string("Fry"));
  cout << "-- copy:" << endl;
  t2.print();
  cout << "-- original:" << endl;
  t.print();
  EXPECT_NE(t2.size(), t.size());
  EXPECT_LT(t2.contains("Pizza"), 0);
  EXPECT_LT(t2.contains("Salad"), 0);
  EXPECT_LT(t2.contains("Fry"), 0);

  return;
}

void test5()
{
  MyBSTree<int> t;
  
  cout << endl << endl << "***** " << "Test #5" << endl;
  cout << "Tree empty? " << boolalpha << t.isEmpty() << endl;  
  cout << "--" << endl;
  
  try {
    t.findMin();
  }
  catch (string errmsg)
  {
    cout << errmsg << endl;
    EXPECT_ANY_THROW(t.findMin());
  }

  try {
    t.findMax();
  }
  catch (string errmsg)
  {
    cout << errmsg << endl;
    EXPECT_ANY_THROW(t.findMax());
  }

  return;
}


//------------------------------------------------------
void test6()
{
  MyBSTree<int> t;
  
  cout << endl << endl << "***** " << "Test #6" << endl;
 
  cout << "--" << endl;

  t.insert(7);
  t.insert(5);
  t.insert(9);
  t.insert(4);
  t.insert(6);
  t.insert(13);
  t.insert(10);

  
  t.print();
  
  cout << "--" << endl;
  cout << "Pre Order:" << endl;
  t.printPreOrder();
  
  cout << "--" << endl;
  cout << "Post Order" << endl;
  t.printPostOrder();

  return;
}
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------

int main ()
{
  cout << "Hello Tree Tester!! " << endl;

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  //cin.ignore();
  //cin.get();
  return 0; 
}