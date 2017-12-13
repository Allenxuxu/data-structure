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
#include"StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"
#include "XXString.h"
#include <cstring>
#include "Sort.h"
#include <ctime>
#include "Gtree.h"
#include "Btree.h"
using namespace std;
using namespace XXLib;

int* pmt(const char* p)
{
    int len = strlen(p);
    int * ret =  static_cast<int*>(malloc(sizeof(int) *len ));
    if( ret != NULL)
    {
        int ll = 0;
        ret[0] = 0;

        for (int i=1; i<len; i++)
        {
            while((ll > 0) && (p[ll] != p[i]))
            {
                ll = ret[ll-1];
            }

            if (p[ll] == p[i])
            {
                ll++;
            }
            ret[i] = ll;
        }
    }
    return ret;


}



int main(void)
{
    BTree<int> btree;
    BTreeNode<int>* n = NULL;

    btree.insert(1,NULL);

    n = btree.find(1);

    btree.insert(11,n);
    btree.insert(12,n);

    n=btree.find(11);
    btree.insert(21,n);
    btree.insert(22,n);


    cout << btree.find(22);



}
