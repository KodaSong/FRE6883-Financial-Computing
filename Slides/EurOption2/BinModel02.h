#ifndef BinModel02_h
#define BinModel02_h

// Check the data
int GetInputData(double& S0, double& U, double& D, double& R);

// Compute Q
double RiskNeutralProb(double U, double D, double R);

// Compute Stock Price
double Cal_S(double S0, double U, double D, double R, int n, int i);

#endif // BinModel02_h
