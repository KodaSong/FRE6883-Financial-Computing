#ifndef PathDepOption_h
#define PathDepOption_h

#include "BSModel.h"

class PathDepOption
{
private:
    double T, Price, PricingError, delta, gamma;
    int m;
public:
    PathDepOption(double T_, int m_) : T(T_), m(m_) {}

    double GetPrice() { return Price; }
    double GetError() { return PricingError; }
    double Getdelta() { return delta; }
    double Getgamma() { return gamma; }

    double PriceByMC(BSModel Model, long N, double epsilon);
    virtual double Payoff(SamplePath &S)=0;
};

class ArthmAsianCall : public PathDepOption
{
private:
    double K;
public:
    ArthmAsianCall(double T_, int m_, double K_) : PathDepOption(T_, m_), K(K_) {}
    double Payoff(SamplePath &S);
};

#endif // PathDepOption_h
