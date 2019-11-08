#include <iostream>
#include <iomanip>
#include "BSModel.h"
#include "PathDepOption.h"

using namespace std;

int main()
{
    double S0 = 106.0;
    double r = 0.058;
    double sigma = 0.46;
    double T = 9.0;
    double K = 100.0;
    int N1 = 12;

    cout << fixed << setprecision(4);

    BSModel Model(S0, r, sigma);

    EuroCall CallOption(T/N1, K);
    EuroPut PutOption(T/N1, K);

    long N2 = 30000;

    cout << "Eur Option Price By Monte Carlo:" << endl << endl;

    cout << "Input:"   << endl;
    cout << "   double S0 = "    << S0    << endl;
    cout << "   double r = "     << r     << endl;
    cout << "   double sigma = " << sigma << endl;
    cout << "   double T = "     << T/N1  << endl;
    cout << "   double K = "     << K     << endl;
    cout << endl;

    cout << "Output:" << endl << endl;
    cout << "Eur Call Price = " << CallOption.PriceByMC(Model, N2) << endl;
    cout << "Eur Put Price = " << PutOption.PriceByMC(Model, N2) << endl;
    cout << endl;

    return 0;
}

/*
HW1:

Input:
   double S0 = 106.0000
   double r = 0.0580
   double sigma = 0.4600
   double T = 0.7500
   double K = 100.0000

Output:

Eur Call Price = 21.4703
Eur Put Price = 11.4331
*/
