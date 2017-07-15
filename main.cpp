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
#include "DualCircleList.h"
using namespace std;
using namespace XXLib;

int main(void)
{
    DualCircleList<int> a;
    for(int i = 0; i < 5; i++)
    {
        a.insert(i);
        cout << i <<endl;
        //a.insert(1,1);
    }
    cout <<"length: " << a.length() << endl;
   for(a.move(a.length()-1); !a.end(); a.next())
    {
        cout << a.current() <<endl;
        a.remove(a.find(a.current()));
    }

    return 0;
}
