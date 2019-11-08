#include <iostream>
#include "BSModel.h"
#include "PathDepOption.h"
using namespace std;

int main()
{
    double S0 = 100.0;
    double r = 0.03;
    double sigma = 0.2;

    BSModel Model(S0, r, sigma);

    int m = 30;
    double T = 1.0/12.0;
    double K = 100.0;
    ArthmAsianCall Option(T, m, K);

    long N = 30000;
    double epsilon = 0.001;

    Option.PriceByMC(Model, N, epsilon);

    cout << "Greeks:" << endl << endl;

    cout << "Input:" << endl
         << "   double S0=" << S0 << ".,"
         << " r=" << r << ","
         << " sigma=" << sigma << ";" << endl;

    cout << "   double T=1.0/12.0, "
         << "K=" << K << ";" << endl;

    cout << "   int m="  << m << ";" << endl
         << "   long N=" << N << ";" << endl
         << "   double epsilon="     << epsilon << ";"
         << endl << endl;

    cout << "Output:" << endl;

    cout << "Asian Call Price = " << Option.GetPrice() << endl
         << "   Pricing Error = " << Option.GetError() << endl
         << "           delta = " << Option.Getdelta() << endl
         << "           gamma = " << Option.Getgamma() << endl;

    return 0;
}

/*
Greeks:

Input:
   double S0=100., r=0.03, sigma=0.2;
   double T=1.0/12.0, K=100;
   int m=30;
   long N=30000;
   double epsilon=0.001;

Output:
Asian Call Price = 1.36316
   Pricing Error = 0.0114916
           delta = 0.526865
           gamma = 0.131469
*/
