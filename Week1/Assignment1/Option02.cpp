#include "Option02.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
    cout<<"Enter Steps to expiry N:"; cin>>N;
    cout<<"Enter strike price K:"; cin>>K;
    cout<<endl;
    return 0;
}

double CheckStockPrice(double S, double K)
{
    if(S>K)   return S-K;
    return 0.0;
}

int ConMulti(int N)
{
    int res=1;
    if(N==0)  return 1;
    else
    {
        for(int i=1;i<=N;i++)
        {
            res*=i;
        }
    }
    return res;
}

double ComputeOptionPrice(double S0, double U, double D, double R, int N, double K)
{
    double q=ComputeQ(U,D,R);
    double Price[N+1];

    // Compute the option prices of the last periods
    for(int i=0;i<=N;i++)
    {
        Price[i] = CheckStockPrice(ComputeStockPrice(S0,U,D,R,N,i), K);
    }

    // Use loop to compute option price of the first period
    double result=0;
    int N_factorial = ConMulti(N);
    for(int i=0;i<=N;i++)
    {
        result += N_factorial/(ConMulti(i)*ConMulti(N-i))*pow(q,i)*pow(1-q,N-i)*Price[i];
    }

    result /= pow(1+R,N);

    return result;
}

