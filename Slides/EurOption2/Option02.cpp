#include "Option02.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K)
{
    cout << "Enter Steps to expiry N: "; cin >> N;
    cout << "Enter strike price K: ";    cin >> K;
    cout << endl;
    return 0;
}

double Payoff(double S, double K)
{
    if(S>K)   return S-K;
    return 0.0;
}

int Factorial(int N)
{
    if(N<=1)  return 1;

    int res = 1;
    for(int i=2; i<=N; i++)
        res*=i;

    return res;
}

double PriceByCRR1(double S0, double U, double D, double R, int N, double K)
{
    double q = RiskNeutralProb(U,D,R);
    double Price[N+1];

    // Compute the option prices of the last periods
    for(int i=0;i<=N;i++)
    {
        Price[i] = Payoff( Cal_S(S0,U,D,R,N,i), K );
    }

    // Use loop to compute option price of the first period
    double result=0;
    int N_factorial = Factorial(N);
    for(int i=0; i<=N; i++)
        result += N_factorial / ( Factorial(i) * Factorial(N-i) ) * pow(q,i) * pow(1-q,N-i) * Price[i];

    result /= pow(1+R,N);

    return result;
}

