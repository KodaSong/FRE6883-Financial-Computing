#include "Option06.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

double EuroOpt::PriceByCRR(BinModel Model)
{
    double Price[N+1];
    for(int i=0;i<=N;i++)
    {
        Price[i] = Payoff(Model.Cal_S(N,N-i));
    }

    double q = Model.RiskNeutralProb();
    double R = Model.GetR();
    for(int n=N-1;n>=0;n--)
    {
        for(int i=0;i<=n;i++)
        {
            Price[i] = ( q * Price[i] + (1-q) * Price[i+1] ) / ( 1 + R );
        }
    }

    return Price[0];
}

int DoubleDigit::GetInputData()
{
    cout << "Enter double-digital option data: " << endl;
    int N;
    cout << "Enter Steps to Expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter parameter K1: "; cin >> K1;
    cout << "Enter parameter K2: "; cin >> K2;
    SetK12(K1, K2);
    return 0;
}

double DoubleDigit::Payoff(double z)
{
    if(z>K1 && z<=K2)
        return 1.0;
    else
        return 0.0;
}

int Strangle::GetInputData()
{
    cout << "Enter European bull spread data: " << endl;
    int N;
    cout << "Enter Steps to Expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter parameter K1: "; cin >> K1;
    cout << "Enter parameter K2: "; cin >> K2;
    SetK12(K1, K2);
    return 0;
}

double Strangle::Payoff(double z)
{
    if(z<=K1)
        return K1-z;
    else if(z>K1 && z<=K2)
        return 0;
    else
        return z-K2;
}

int Butterfly::GetInputData()
{
    cout << "Enter European bear spread data: " << endl;
    int N;
    cout << "Enter Steps to Expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter parameter K1: "; cin >> K1;
    cout << "Enter parameter K2: "; cin >> K2;
    SetK12(K1, K2);
    return 0;
}

double Butterfly::Payoff(double z)
{
    if(z>K1 && z<=(K1+K2)/2)
        return z-K1;
    else if(z>(K1+K2)/2 && z<=K2)
        return K2-z;
    else
        return 0.0;
}


int EuroCall::GetInputData()
{
    cout << "Enter call option data: " << endl;
    int N;
    cout << "Enter Steps to Expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter Strike Price K: "; cin >> K;
    SetK(K);
    return 0;
}

int EuroPut::GetInputData()
{
    cout << "Enter put option data:" << endl;
    int N;
    cout << "Enter Steps to Expiry N: "; cin >> N;
    SetN(N);

    cout << "Enter Strike Price K: "; cin >> K;
    SetK(K);
    return 0;
}

double EuroCall::Payoff(double z)
{
    if(z>K)
        return z-K;
    else
        return 0.0;
}

double EuroPut::Payoff(double z)
{
    if(z<K)
        return K-z;
    else
        return 0.0;
}
