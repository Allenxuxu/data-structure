#include "LinkList.h"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace XXLib;

int main()
{
  LinkList<int> list;
  list.insert(0,100);
  list.push_back(12);
  list.push_back(88);
  list.push_back(999);

  for(LinkList<int>::iterator it = list.begin();
      it != list.end(); ++it)
  {
    cout << *it << endl;
  }

  LinkList<int>::iterator it = list.begin();
  assert(*it == 100);
  it++;
  assert(*it == 12);
  ++it;
  assert(*it == 88);
//  it--;
}
