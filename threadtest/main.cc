#include <iostream>
//
// 2015.5, by Penguin
// This test will be used to test thread mechnism of Linux
// It is also the first c++ code of penguin's test code
//

#include <iostream>
#include <unistd.h>

// Namespaces
using namespace std;

class thread_test
{

}

int main(int argc, char** argv)
{
  int option;

  cout << "Here is Penguin's Thread test writed by c++" << endl;

  while ((option = getopt(argc, argv, "ht:")) != -1)
  {
    switch (option)
    {
      case 'h':
        cout << "list help info" << endl; break;
      case 't':
        cout << "choose test : " << optarg << endl; break;
      default:
        break;
    }
  }
}
