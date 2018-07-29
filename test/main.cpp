#include "Sort.h"
#include <iostream>

using namespace XXLib;
using namespace std;


int main()
{
  int arrs[] = { 23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61 };
  int arrLen = sizeof(arrs) / sizeof(arrs[0]);

  Sort::Heap(arrs, arrLen,false);
  for (int i = 0; i < arrLen; i++)
    cout << arrs[i] << endl;
  return 0;
}
