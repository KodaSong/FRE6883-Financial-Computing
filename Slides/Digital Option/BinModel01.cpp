#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(double& S0, double& U, double& D, double& R)
{
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U: ";  cin >> U;
    cout << "Enter D: ";  cin >> D;
    cout << "Enter R: ";  cin >> R;
    // Ensure data is correct

    if( S0<=0 || U<=-1.0 || D<=-1.0 || U<=D || R <=-1.0 )
    {
        cout << "The range of data is wrong. Please input again";
        return 1;
    }

    if( U<=R || R<=D )
    {
        cout<<"Arbitrage Exists"<<endl;
        return 1;
    }

    cout<<"Input data checked. There is no arbitrage."<<endl;
    return 0;
}

double RiskNeutralProb(double U, double D, double R)
{
    return (R-D)/(U-D);
}

double Cal_S(double S0, double U, double D, double R, int n, int i)
{
    return S0 * pow(1+U,i) * pow(1+D,n-i);
}
