#ifndef Option06_h
#define Option06_h
#include "BinModel02.h"

class EuroOpt
{
private:
    int N;
public:
    void SetN(int N) {this->N = N;}
    virtual double Payoff(double z) {return 0.0;}
    double PriceByCRR(BinModel Model);
};

class BullSpread:public EuroOpt
{
private:
    double K1, K2;
public:
    void SetK12(double K1, double K2)
    {
        this->K1 = K1;
        this->K2 = K2;
    }
    int GetInputData();
    double Payoff(double z);
};

class BearSpread:public EuroOpt
{
private:
    double K1, K2;
public:
    void SetK12(double K1, double K2)
    {
        this->K1 = K1;
        this->K2 = K2;
    }
    int GetInputData();
    double Payoff(double z);
};


class EuroCall:public EuroOpt
{
private:
    double K;
public:
    void SetK(double K) {this->K = K;}
    int GetInputData();
    double Payoff(double z);
};

class EuroPut:public EuroOpt
{
private:
    double K;
public:
    void SetK(double K) {this->K = K;}
    int GetInputData();
    double Payoff(double z);
};

#endif // Option06_h
