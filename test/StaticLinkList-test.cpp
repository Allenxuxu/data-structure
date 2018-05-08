#include "StaticLinkList.h"
#include <iostream>
#include <assert.h>
using namespace std;
using namespace XXLib;
int main()
{
    StaticLinkList<int,3> list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(12);

    for(StaticLinkList<int,3>::iterator it = list.begin();
        it != list.end(); ++it)
    {
        cout << *it << endl;
    }

    LinkList<int>::iterator it = list.begin();
    assert(*it == 2);
    it++;
    assert(*it == 3);
    ++it;
    assert(*it == 12);
}
