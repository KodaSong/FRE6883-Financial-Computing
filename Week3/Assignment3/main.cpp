#include <iostream>
#include "DefInt.h"
#include <cmath>

using namespace std;

int MyFun1(int x)
{
   cout<<"test"<<endl;
   return 0;
}



int main()
{
    int N;
    double a,b;

    GetInputData(a,b,N);

    DefInt MyInt(a, b, *my_func);
    cout<<"The result of the integration is:"<<MyInt.ByTrapzoid(N);

}
