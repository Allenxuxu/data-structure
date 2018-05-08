#include "StaticList.h"
#include <assert.h>
#include <iostream>
using namespace std;
using namespace XXLib;

int main()
{
  StaticList<int,3> list;

  list.push_back(1);
  list.push_back(2);

  for(StaticList<int,3>::iterator it = list.begin();
      it != list.end(); ++it)
  {
    cout << *it << endl;
  }

  StaticList<int,3>::iterator it = list.begin();
  assert(*it == 1);
  it++;
  assert(*it == 2);
  it--;
  assert(*it == 1);

  ++it;
  assert(*it == 2);
  --it;
  assert(*it == 1);
}
