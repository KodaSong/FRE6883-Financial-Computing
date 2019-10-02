#include "BinModel01.h"
#include "Option03.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double S0, U, D, R;
    if(GetInputData(S0,U,D,R)==1)   return 1;

    double K; // strike price
    int N;  // steps to expiry

    cout<<"Enter call option data:"<<endl;
    GetInputData(N,K);
    cout<<"European call option price ="<<ComputeOptionPrice(S0,U,D,R,N,K,CallPayoff)<<endl;
    cout<<"European digital call option price ="<<ComputeOptionPrice(S0,U,D,R,N,K,DCallPayoff)<<endl;

    cout<<"Enter put option data:"<<endl;
    GetInputData(N,K);
    cout<<"European put option price ="<<ComputeOptionPrice(S0,U,D,R,N,K,PutPayoff)<<endl;
    cout<<"European digital put option price ="<<ComputeOptionPrice(S0,U,D,R,N,K,DPutPayoff)<<endl;

    return 0;
}
