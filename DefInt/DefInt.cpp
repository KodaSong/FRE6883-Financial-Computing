#include "DefInt.h"
#include <iostream>
#include <cmath>
using namespace std;

double DefInt::ByTrapzoid(int N)
{
    double sum = 0, h = (b-a)/N;

    for(int k=0;k<=N-1;k++)
        sum += h*(f(a+k*h) + f(a+k*h+h)) / 2;

    return sum;
}

double DefInt::BySimpson(int N)
{
    double sum = f(a)+f(b), h = (b-a)/N;

    for(int k=1;k<=N-1;k++)
    {
        if(k%2==1)
            sum += 4*f(a+k*h);
        else
            sum += 2*f(a+k*h);
    }

    return sum*h/3;
}

void GetInputData(double &a, double &b, int &N)
{
    // For Simpson Approximation, results would be accurate if N is even
    cout << "Enter the number of rectangles you want: "; cin >> N;

    if(N%2==1)
        N++;

    cout << "Enter the startpoint a: "; cin >> a;
    cout << "Enter the endpoint b:";    cin >> b;
    cout << endl;
}

// Define my f(x)
double my_func(double x)
{
    return x*x*x - x*x + 1;
}
