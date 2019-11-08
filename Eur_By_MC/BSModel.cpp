#include "BSModel.h"
#include <cmath>

const double pi = 4 * atan(1);

double Gauss()
{
    double U1 = ( rand() + 1.0 ) / ( RAND_MAX + 1.0 );
    double U2 = ( rand() + 1.0 ) / ( RAND_MAX + 1.0 );

    return sqrt( -2.0 * log(U1) ) * cos( 2.0 * pi * U2 );
}

double BSModel::GenerateSt(double h)
{
    return S0 * exp( ( r - pow(sigma,2)/2 ) * h + sigma * sqrt(h) * Gauss() );
}
