#ifndef BinModel02_h
#define BinModel02_h

// Check the data
int GetInputData(double& S0, double& U, double& D, double& R);

// Compute Q
double ComputeQ(double U, double D, double R);

// Compute Stock Price
double ComputeStockPrice(double S0, double U, double D, double R, int n, int i);

#endif // BinModel02_h
