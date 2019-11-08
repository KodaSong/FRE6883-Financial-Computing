#ifndef PathDepOption_h
#define PathDepOption_h
#include "BSModel.h"

class PathDepOption
{
private:
    double h;
public:
    PathDepOption(double h_) : h(h_) {}
    double PriceByMC(BSModel Model, long N);
    virtual double Payoff(double St)=0;
};

class EuroCall : public PathDepOption
{
private:
    double K;
public:
    EuroCall(double h_, double K_) : PathDepOption(h_), K(K_) {}
    double Payoff(double St);
};

class EuroPut : public PathDepOption
{
private:
    double K;
public:
    EuroPut(double h_, double K_) : PathDepOption(h_), K(K_) {}
    double Payoff(double St);
};
#endif // PathDepOption_h
