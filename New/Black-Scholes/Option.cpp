#include "Option.h"
#include <iostream>
#include <cmath>
using namespace std;

double Normal_CDF(double x)
{
    return 0.5 * erfc( -x * M_SQRT1_2 );
}

int EurOption::GetInputData()
{
    cout << "Enter spot price: ";     cin >> S;
    cout << "Enter strike price: ";   cin >> K;
    cout << "Enter sigma: ";          cin >> sigma;
    cout << "Enter period: ";         cin >> T;
    cout << "Enter risk-free rate: "; cin >> r;
    cout << "Enter b: ";              cin >> b;

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

double EurOption::Cal_d1()
{
    return ( log(S/K) + ( b + pow(sigma,2)/2 ) * T ) / ( sigma * pow(T,0.5) );
}

double EurOption::Cal_d2()
{
    double d1 = Cal_d1();
    return d1 - sigma * pow(T,0.5);
}

double Call::Price()
{
    return S * exp( (b-r)*T ) * Normal_CDF( Cal_d1() ) - K * exp( -r*T ) * Normal_CDF( Cal_d2() );
}

double Put::Price()
{
    return K * exp( -r*T ) * Normal_CDF( -Cal_d2() ) - S * exp( (b-r) * T ) * Normal_CDF( -Cal_d1() );
}
