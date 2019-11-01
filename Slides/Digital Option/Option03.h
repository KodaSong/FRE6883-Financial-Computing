#ifndef Option03_h
#define Option03_h

// Check the data
int GetInputData(int &N, double &K);

// Compute CallPayoff
double CallPayoff(double S, double K);

// Compute Digital Call Payoff
double DigiCall(double S, double K);

// Compute Digital Put Payoff
double DigiPut(double S, double K);

// Compute PutPayoff
double PutPayoff(double S, double K);

// Compute Call Option Price
double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double S, double K));

#endif // Option03_h
