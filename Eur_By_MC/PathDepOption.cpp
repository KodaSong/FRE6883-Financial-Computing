#include "PathDepOption.h"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N)
{
    double St, H = 0.0;

    for(int i=0; i<N; i++)
    {
        St = Model.GenerateSt(h);
        H += Payoff(St);
    }

    return exp( -Model.Getr() * h ) * H / N;
}

double EuroCall::Payoff(double St)
{
    if( St < K )
        return 0.0;

    return St - K;
}

double EuroPut::Payoff(double St)
{
    if( St > K )
        return 0.0;

    return K - St;
}
