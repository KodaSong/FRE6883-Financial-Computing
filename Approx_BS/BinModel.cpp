#include "BinModel.h"
#include <iostream>
#include <cmath>
using namespace std;

void BinModel::GetInputData()
{
    cout << "Enter S0 = ";    cin >> S0;
    cout << "Enter r = ";     cin >> r;
    cout << "Enter sigma = "; cin >> sigma;
    cout << "Enter T = ";     cin >> T;
    cout << endl;
}

double BinModel::Cal_U(int N)
{
    return exp( ( r - pow(sigma,2)/2) * (T/N) + sigma * sqrt(T/N) ) - 1;
}

double BinModel::Cal_D(int N)
{
    return exp( ( r - pow(sigma,2)/2) * (T/N) - sigma * sqrt(T/N) ) - 1;
}

double BinModel::Cal_R(int N)
{
    return exp( r * T / N ) - 1;
}

double BinModel::Cal_S(int N, int n, int i)
{
    double U = Cal_U(N), D = Cal_D(N);
    return S0 * pow(1+U,i) * pow(1+D,n-i);
}
