#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
using namespace std;
using namespace XXLib;

class Test
{
public:
    Test()
    {
        cout <<"Tes()"<< endl;
    }
    ~Test()
    {
        cout << "~test()"<<endl;
    }
};


int main(void)
{
    try
    {
        throw Exception("test", __FILE__, __LINE__);
    }
    catch (Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
      SmartPointer<Test> sp = new Test();

    return 0;
}
