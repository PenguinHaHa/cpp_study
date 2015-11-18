#include <iostream>
using namespace std;

void swap(int&, int&);

int main()
{
  int apple;
  int pear;

  cout << "Please enter a number for apple: ";
  cin >> apple;
  cout << "Please enter a number for pear: ";
  cin >> pear;

  cout << "before swap :" << "apple" << apple << " pear" << pear << endl;
  swap(apple, pear);
  cout << "after swap :" << "apple" << apple << " pear" << pear << endl;
}

void swap(int &a, int &b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}
