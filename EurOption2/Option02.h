#ifndef Option02_h
#define Option02_h

// Check the data
int GetInputData(int& N, double& K);

// Check the StockPrice
double Payoff(double S, double K);

// Compute Call Option Price
double PriceByCRR1(double S0, double U, double D, double R, int N, double K);

// Consecutive Multiply
int Factorial(int N);

#endif // Option02_h

