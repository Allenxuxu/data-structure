#include "DynamicList.h"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace XXLib;

int main()
{
  DynamicList<int> list(3);
  assert(list.capacity() == 3);
  list.resize(6);
  assert(list.capacity() == 6);

  list.push_back(3);
  list.push_back(100);

  for(DynamicList<int>::iterator it = list.begin();
      it != list.end(); ++it)
  {
    cout << *it << endl;
  }

  DynamicList<int>::iterator it = list.begin();
  assert(*it == 3);
  it++;
  assert(*it == 100);
  it--;
  assert(*it == 3);

  ++it;
  assert(*it == 100);
  --it;
  assert(*it == 3);
}
