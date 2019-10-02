#ifndef Option02_h
#define Option02_h

// Check the data
int GetInputData(int *PtrN, double *PtrK);

// Check the StockPrice
double CheckStockPrice(double S, double K);

// Compute Call Option Price
double ComputeOptionPrice(double S0, double U, double D, double R, int N, double K);

#endif // Option02_h
