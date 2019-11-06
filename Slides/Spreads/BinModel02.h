#ifndef BinModel02_h
#define BinModel02_h

class BinModel
{
private:
    double S0, U, D, R;
public:
    int GetInputData();
    double RiskNeutralProb();
    double Cal_S(int N, int i);
    double GetR();
};
#endif // BinModel02_h
