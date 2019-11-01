#ifndef BinModel02_h
#define BinModel02_h

class BinModel
{
private:
    double S0, U, D, R;
public:
    int GetInputData();

    double Cal_q();
    double Cal_S(int N, int i);

    double GetR()   {return R;}
    double GetS0()  {return S0;}
    double GetU()   {return U;}
    double GetD()   {return D;}
};
#endif // BinModel02_h
