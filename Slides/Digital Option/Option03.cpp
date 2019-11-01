#include "Option03.h"
#include "BinModel01.h"
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

double CallPayoff(double S, double K)
{
    if(S>K)   return S-K;
    return 0.0;
}

double PutPayoff(double S, double K)
{
    if(S<K)   return K-S;
    return 0.0;
}

double DigiCall(double S, double K)
{
    if (S>K)    return 1.0;
    return 0.0;
}

double DigiPut(double S, double K)
{
    if (S<K)    return 1.0;
    return 0.0;
}

double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double S, double K))
{
    double q = RiskNeutralProb(U,D,R);
    double Price[N+1];

    // Compute the option prices of the last periods
    for(int i=0;i<=N;i++)
        Price[i] = Payoff( Cal_S(S0,U,D,R,N,i), K );

    // Use loop to compute option price of the first period
    for(int n=N-1;n>=0;n--)
    {
        for(int i=0;i<=n;i++)
            Price[i] = ( q * Price[i+1] + (1-q) * Price[i] ) / ( 1 + R );
    }

    return Price[0];
}
