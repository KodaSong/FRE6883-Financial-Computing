#include "PathDepOption.h"
#include <cmath>

void Rescale(SamplePath &S, double x)
{
    int n = S.size();

    for(int i=0; i<n; i++)
        S[i] = S[i] * x;
}

double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon)
{
    SamplePath S(m);
    double r = Model.Getr(), S0 = Model.GetS0();
    double H = 0.0, Hsq = 0.0, Heps1 = 0.0, Heps2 = 0.0;

    for(int i=0; i<N; i++)
    {
        Model.GenerateSamplePath(T, m, S);
        H += Payoff(S); // N * E(X)
        Hsq += pow( Payoff(S), 2.0 );   // N * E(X^2)

        Rescale(S, 1+epsilon);  // S * (1+epsilon)
        Heps1 += Payoff(S);

        Rescale(S, (1-epsilon)/(1+epsilon));  // S * (1-epsilon)
        Heps2 += Payoff(S);
    }

    H /= N;
    Hsq /= N;
    Heps1 /= N;
    Heps2 /= N;

    Price = exp( -r * T ) * H;
    PricingError = exp( -r * T ) * sqrt( Hsq - H*H ) / sqrt( N-1.0 );
    delta = exp( -r * T ) * ( Heps1 - H ) / ( epsilon * S0 );
    gamma = exp( -r * T ) * ( Heps1 - 2*H + Heps2 ) / pow( epsilon * S0, 2.0 );

    return Price;
}

double ArthmAsianCall::Payoff(SamplePath &S)
{
    double Ave = 0.0;
    int n = S.size();

    for(int i=0; i<n; i++)
        Ave += S[i];
    Ave /= n;

    if( Ave < K )
        return 0.0;
    return Ave - K;
}
