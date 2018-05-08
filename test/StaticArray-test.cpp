
#include "StaticArray.h"
#include <assert.h>
#include <iostream>
using namespace std;
using namespace XXLib;

class test
{
public:
  test() {}

  test(const test& obj)
  {

  }

  test& operator = (const test& obj)
  {
    return *this;
  }
};

int main()
{
  StaticArray<test,4> arrayclass;
  StaticArray<int,3> array;

  for(int i=0; i<array.length();++i)
  {
    cout << array[i] << endl;
  }

  array[1] = 3;
  assert(array.set(0,8));

  for(int i=0; i<array.length();++i)
  {
    cout << array[i] << endl;
  }
}
