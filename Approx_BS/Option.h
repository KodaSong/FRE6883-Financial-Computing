#ifndef Option_h
#define Option_h

#include "BinLattice02.h"
#include "BinModel.h"

class AmCall
{
private:
    int N;
    double K;
public:
    void SetN(int N_) { N = N_; }
    void SetK(double K_) { K = K_; }
    void GetInputData();

    int GetN() { return N; }
    double GetK() { return K; }
    double Payoff(double z);
    double PriceBySnell(BinModel Model, BinLattice<double> &PriceTree, BinLattice<bool> &StoppingTree);

};

#endif // Option_h
