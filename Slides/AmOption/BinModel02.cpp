#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

int BinModel::GetInputData()
{
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U: ";  cin >> U;
    cout << "Enter D: " ; cin >> D;
    cout << "Enter R: ";  cin >> R;
    cout << endl;

    // Check data range
    if(S0<=0.0 || U<=-1.0 || D<=-1.0 || U<=D || R<=-1.0)
    {
        cout << "Illegal Data ranges." << endl;
        cout << "Terminating program." << endl;
        return 1;
    }
    // Check Arbitrage Opportunity
    if(U<=R || R<=D)
    {
        cout << "Arbitrage Exits."     << endl;
        cout << "Terminating Program." << endl;
        return 1;
    }
    cout << "Input Data Checked."    << endl;
    cout << "There is no arbitrage." << endl;
    cout << endl;

    return 0;
}

double BinModel::RiskNeutralProb()
{
    return (R-D) / (U-D);
}

double BinModel::Cal_S(int N, int i)
{
    return S0*pow(1+U, i)*pow(1+D, N-i);
}

double BinModel::GetR()
{
    return R;
}
