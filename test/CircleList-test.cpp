#include "CircleList.h"
#include <iostream>
#include <assert.h>
using namespace std;
using namespace XXLib;
int main()
{
  CircleList<int> list;
  list.push_back(3);
  list.push_front(30);
  list.push_back(100);
  for(CircleList<int>::iterator it = list.begin();
      it != list.end(); ++it)
  {
    cout << *it << endl;
  }

  CircleList<int>::iterator it = list.begin();
  assert(*it == 30);
  it++;
  assert(*it == 3);

  ++it;
  assert(*it == 100);
}
