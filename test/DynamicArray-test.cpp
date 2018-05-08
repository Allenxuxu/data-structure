

#include "DynamicArray.h"
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
  DynamicArray<test> arrayclass(10);
  DynamicArray<int> array(2);

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

  array.resize(100);
  for(int i=0; i<array.length();++i)
  {
    cout << array[i] << " ";
  }
  cout << endl;

}
