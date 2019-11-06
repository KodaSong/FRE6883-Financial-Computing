#ifndef BinModel_h
#define BinModel_h

class BinModel
{
private:
    double S0, r, sigma, T;
public:
    void GetInputData();

    double Cal_U(int N);
    double Cal_D(int N);
    double Cal_R(int N);
    double Cal_S(int N, int n, int i);

    double GetS0() { return S0; }
    double Getr()  { return r; }
    double GetSigma() { return sigma; }
    double GetT()  { return T; }
};
#endif // BinModel_h
