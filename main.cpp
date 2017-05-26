#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"
#include "SeqList.h"

using namespace std;
using namespace XXLib;

class Test
{
public:
     const int a = 0;
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
        THROW_EXCEPTION(ArithmeticException,"aaaa");
    }
    catch (ArithmeticException& e)          //因为父子兼容性原则，所以子类的放在上面
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    catch (Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

      SmartPointer<Test> sp = new Test();




    return 0;
}
