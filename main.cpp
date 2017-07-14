#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
#include "SeqList.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "StaticLinkList.h"
#include "SharedPointer.h"
#include "CircleList.h"
#include "DualLinkList.h"
using namespace std;
using namespace XXLib;

int main(void)
{
    DualLinkList<int> a;
    for(int i = 0; i < 5; i++)
    {
       cout<< a.insert(i) << endl;;
        cout << i <<endl;
        //a.insert(1,1);
    }
    cout <<"length: " << a.length() << endl;
    for(a.move(0); !a.end(); a.next())
    {
        cout << a.current() <<endl;
        a.remove(a.find(a.current()));
    }

    return 0;
}
