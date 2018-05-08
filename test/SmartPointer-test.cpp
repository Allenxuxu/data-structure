#include "ScopedPointer.h"
#include "SharedPointer.h"

#include <iostream>
using namespace std;
using namespace XXLib;

class test
{
public:
  test()
  {
    cout << "test" << endl;
  }

  ~test()
  {
    cout << "~test" << endl;
  }
};

class testUncomple;

int main()
{
  {
    ScopedPointer<test> scopedp(new test);
    scopedp.reset(new test);

    cout << "exit" << endl;
  }

  cout << endl;

  {
    SharedPointer<test> sharedp(new test);
    sharedp.reset(new test);

    SharedPointer<test> sharedp2(sharedp);

    cout << "use count "<< sharedp.useCount() << endl;
    cout << "exit" << endl;
    sharedp.reset();
    cout << "use count "<< sharedp.useCount() << endl;
  }

  ScopedPointer<test> scp;
  SharedPointer<test> shp;
//  ScopedPointer<testUncomple> p1;
//  SharedPointer<testUncomple> p2;
}
