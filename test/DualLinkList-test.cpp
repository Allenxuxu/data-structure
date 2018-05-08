#include "DualLinkList.h"
#include "iostream"
#include <assert.h>
using namespace std;
using namespace XXLib;

int main()
{
  DualLinkList<int> list;
  list.insert(3);
  list.push_front(12);

  for(DualLinkList<int>::iterator it = list.begin();
      it != list.end(); ++it)
  {
    cout << *it << endl;
  }

  DualLinkList<int>::iterator it = list.begin();
  assert(*it == 12);
  it++;
  assert(*it == 3);
  it--;
  assert(*it == 12);

  ++it;
  assert(*it == 3);
  --it;
  assert(*it == 12);
}
