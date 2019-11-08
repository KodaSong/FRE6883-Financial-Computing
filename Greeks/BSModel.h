#ifndef BSModel_h
#define BSModel_h
using namespace std;
#include <vector>
#include <cstdlib>
#include <ctime>
typedef vector<double> SamplePath;

class BSModel
{
private:
    double S0, r, sigma;
public:
    BSModel(double S0_, double r_, double sigma_) : S0(S0_), r(r_), sigma(sigma_)
    {
        srand(time(NULL));
    }

    double GetS0() { return S0; }
    double Getr() { return r; }
    double Getsigma() { return sigma; }

    void GenerateSamplePath(double T, int m, SamplePath &S);
};
#endif // BSModel_h
