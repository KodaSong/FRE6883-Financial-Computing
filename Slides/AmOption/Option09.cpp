#include "Option09.h"
#include "BinLattice02.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double EurOption::PriceByCRR(BinModel Model, BinLattice<double> & StockTree, BinLattice<double> & PriceTree)
{
    double q = Model.RiskNeutralProb(), R = Model.GetR();
    int N = GetN();

    // Create the lattice
    StockTree.SetN(N);
    PriceTree.SetN(N);

    // Calculate every Node(i,n) of stock price tree, S * (1+U)^(n-i) * (1+D)^i
    for(int i=0; i<=N; i++){
        for(int n=i; n<=N; n++)
            StockTree.SetNode(i, n, Model.Cal_S(n, n-i));
    }

    // Calculate the payoff of the last day
    for(int i=0; i<=N; i++){
        double val1 = StockTree.GetNode(i, N);
        PriceTree.SetNode(i, N, Payoff(val1));
    }

    // Calculate every Node of option payoff tree
    for(int i=N-1; i>=0; i--){
        for(int n=0; n<=i; n++){
            double val2 = (q*PriceTree.GetNode(n, i+1) + (1-q)*PriceTree.GetNode(n+1, i+1)) / (1+R);
            PriceTree.SetNode(n, i, val2);
        }
    }

    return PriceTree.GetNode(0,0);
}

double AmOption::PriceBySnell(BinModel Model, BinLattice<double> & PriceTree,BinLattice<string> & StoppingTree, BinLattice<double> & StockTree)
{
    double q = Model.RiskNeutralProb(), R = Model.GetR();
    int N = GetN();

    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    StockTree.SetN(N);

    // Calculate every Node(i,n) of stock price tree, S * (1+U)^(n-i) * (1+D)^i
    double val;
    for(int i=0; i<=N; i++){
        for(int n=i; n<=N; n++){
            val = Model.Cal_S(n, n-i);
            StockTree.SetNode(i, n, val);
        }
    }

    // Calculate the payoff of the last day
    // Last day we set "yes" for exercise policy
    for(int i=0; i<=N; i++){
        double val_ = StockTree.GetNode(i, N);
        PriceTree.SetNode(i, N, Payoff(val_));
        StoppingTree.SetNode(i, N, "yes");
    }

    double val1, val2;
    for(int i=N-1; i>=0; i--){
        for(int n=0; n<=i; n++){
            val1 = (q*PriceTree.GetNode(n,i+1) + (1-q)*PriceTree.GetNode(n+1,i+1)) / (1+R);
            val2 = Payoff(StockTree.GetNode(n,i));

            PriceTree.SetNode(n, i, val2);   // we first set val2 as the price
            StoppingTree.SetNode(n, i, "yes");  // we first set "yes" for the node

            // Set the larger one to the node of price tree
            if(val1 > val2){
                PriceTree.SetNode(n, i, val1);
                StoppingTree.SetNode(n, i, "no"); // if val1>val2, we do not exercise, "no"
            }
            else if(val2 == 0.0){  // if val2>val1 but val2==0, we do not exercise, set "no"
                PriceTree.SetNode(n, i, val2);
                StoppingTree.SetNode(n, i, "no");
            }
        }
    }
    return PriceTree.GetNode(0,0);
}

int Call::GetInputData()
{
    cout << "Enter call option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin>>N;
    SetN(N);
    cout << "Enter strike price K: "; cin>>K;
    cout << endl;
    return 0;
}

int Put::GetInputData()
{
    cout << "Enter put option data: " << endl;
    int N;
    cout << "Enter steps to expiry N: "; cin>>N;
    SetN(N);
    cout << "Enter strike price K: "; cin>>K;
    cout << endl;
    return 0;
}
