#include "Option01.h"
#include "CDF.h"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(double &S, double &K, double &sigma, double &T)
{
    if(S<=0.0 | K<=0.0 | sigma<=0.0 | T<=0.0)
    {
        cout<<"Input Wrong! Check the data!"<<endl;
        return 1;
    }

    else
    {
        cout<<"Data ranges are right. Begin to calculate."<<endl<<endl;
        return 0;
    }
}

class Option
{
private:
    double S, K, sigma, T, Rd, Rf;
public:
    double Cald1(double S, double K, double sigma, double T, double Rd, double Rf);
    double Cald2(double S, double K, double sigma, double T, double Rd, double Rf);
    double CalCallOption(double S, double K, double sigma, double Rd, double Rf, double T);
    double CalPutOption(double S, double K, double sigma, double Rd, double Rf, double T)
};

Option::Cald1(double S, double K, double sigma, double T, double Rd, double Rf)
{
    return (log(S/K)+(Rd-Rf+pow(sigma,2)/2)*T) / (sigma*pow(T,0.5));
}

Option::Cald2(double S, double K, double sigma, double T, double Rd, double Rf)
{
    double d1 = Cald1(S,K,sigma,T,Rd,Rf);
    return d1 - sigma*pow(T,0.5);
}

Option::CalCallOption(double S, double K, double sigma, double Rd, double Rf, double T)
{
    return S*exp((Rd-Rf-Rd)*T)*CDF(Cald1(S,K,sigma,T,Rd,Rf)) - K*exp(-Rd*T)*CDF(Cald2(S,K,sigma,T,Rd,Rf));
}

Option::CalPutOption(double S, double K, double sigma, double Rd, double Rf, double T)
{
    return K*exp(-Rd*T)*CDF(-Cald2(S,K,sigma,T,Rd,Rf)) - S*exp((Rd-Rf-Rd)*T)*CDF(-Cald1(S,K,sigma,T,Rd,Rf));
}

