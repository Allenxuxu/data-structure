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
using namespace std;
using namespace XXLib;

int main(void)
{
  LinkStack<int > a;

  for(int i =0; i< 6; i++)
  a.push(i);
for(int i =0; i< 9; i++)
{
  cout <<a.top();
    a.pop();
}
  return 0;
}
