#ifndef BSModel_h
#define BSModel_h

#include <cstdlib>
#include <ctime>

class BSModel
{
private:
    double S0, r, sigma;
public:
    BSModel(double S0_, double r_, double sigma_) : S0(S0_), r(r_), sigma(sigma_)
    {
        srand(time(NULL));
    }
    double Getr() { return r; }
    double GenerateSt(double h);
};
#endif // BSModel_h
