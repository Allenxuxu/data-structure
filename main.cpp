#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
#include "SeqList.h"
#include "StaticList.h"
#include "DynamicList.h"
#include "StaticArray.h"
#include "DynamicArray.h"

using namespace std;
using namespace XXLib;

int main(void)
{
    DynamicArray<int> a(10);
    for(int i=0; i<a.length();i++)
    {
        a[i] = 1+i;
    }

    for(int i=0; i<a.length();i++)
    {
        cout <<  "a" <<a[i]<< endl;
    }

   DynamicArray<int> b = a;
   for(int i=0; i<b.length();i++)
   {
       cout <<  "b" <<b[i]<< endl;
   }

   DynamicArray<int> c(5);
   c = a;

   for(int i=0; i<c.length();i++)
   {
       cout << "c" <<c[i]<< endl;
   }


    return 0;
}
