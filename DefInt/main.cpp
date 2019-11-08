#include <iostream>
#include "DefInt.h"
#include <cmath>
#include<iomanip>

using namespace std;

int main()
{
    int N;
    double a,b;

    GetInputData(a,b,N);
    DefInt MyInt(a, b, *my_func);

    cout << setiosflags(ios::fixed) << setprecision(4);

    cout << "Trapzoid Result is:";
    cout << MyInt.ByTrapzoid(N) << endl;

    cout << "Simpson Result is:";
    cout << MyInt.BySimpson(N) << endl;

    cout<<endl;

    if( MyInt.ByTrapzoid(N) - MyInt.BySimpson(N) < 0.0001 )
        cout << "The results of these two methods are the same.";
    else
        cout << "The results of these two methods are different.";

    cout << endl;

    return 0;
}

/*
Enter the number of rectangles you want: 1000
Enter the startpoint a: 1
Enter the endpoint b:2

Trapzoid Result is:2.4167
Simpson Result is:2.4167

The results of these two methods are the same.
*/
