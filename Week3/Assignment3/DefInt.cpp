#include "DefInt.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(double &a, double &b, int &N)
{
    cout<<"Enter the number of rectangles you want:"; cin>>N;
    cout<<"Enter the startpoint a:"; cin>>a;
    cout<<"Enter the endpoint b:"; cin>>b;
    cout<<endl;
    return 0;
}

double my_func(double x)
{
    return x*x*x - x*x + 1;
}

DefInt::DefInt()
{

}

DefInt::DefInt(double a, double b, double (*f)(double))
{
    this->a = a;
    this->b = b;
    this->f = f;
}

double DefInt::ByTrapzoid(int N)
{
    double sum = 0, h = (b-a)/N;
    for(int k=0;k<=N-1;k++)
    {
        sum += h*(f(a+k*h) + f(a+k*h+h)) / 2;
    }

    return sum;
}
