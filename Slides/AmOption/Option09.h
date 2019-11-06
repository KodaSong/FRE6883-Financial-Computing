#ifndef Option09_h
#define Option09_h

#include "BinLattice02.h"
#include "BinModel02.h"
#include <string>

class Option
{
private:
    int N;
public:
    void SetN(int N_) {N = N_;}
    int GetN() {return N;}
    virtual double Payoff(double z)=0;
};

class EurOption : public virtual Option
{
public:
    double PriceByCRR(BinModel Model, BinLattice<double> & StockTree, BinLattice<double> & PriceTree);
};

class AmOption : public virtual Option
{
public:
    double PriceBySnell(BinModel Model, BinLattice<double> & PriceTree,
                        BinLattice<string> & StoppingTree, BinLattice<double> & StockTree);
};

class Call : public EurOption, public AmOption
{
private:
    double K;
public:
    void SetK(int K_) {K = K_;}
    //double GetK() {return K;}
    int GetInputData();
    double Payoff(double z)
    {
        if(z>K) return z-K;
        else    return 0.0;
    }
};

class Put : public EurOption, public AmOption
{
private:
    double K;
public:
    void SetK(int K_) {K = K_;}
    //double GetK() {return K;}
    int GetInputData();
    double Payoff(double z)
    {
        if(z<K) return K-z;
        else    return 0.0;
    }
};

#endif // Option09_h
