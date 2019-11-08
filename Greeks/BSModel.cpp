#include "BSModel.h"
#include <cmath>
const double pi = 4.0 * atan(1.0);

double Gauss()
{
    double U1 = ( rand() + 1.0 ) / ( RAND_MAX + 1.0 );
    double U2 = ( rand() + 1.0 ) / ( RAND_MAX + 1.0 );

    return sqrt( -2.0 * log(U1) ) * cos( 2 * pi * U2 );
}

void BSModel::GenerateSamplePath(double T, int m, SamplePath &S)
{
    double h = T / m;
    S[0] = S0;
    for(int i=1; i<m; i++)
        S[i] = S[i-1] * exp( ( r - pow(sigma,2)/2 ) * h + sigma * sqrt(h) * Gauss() );
}
