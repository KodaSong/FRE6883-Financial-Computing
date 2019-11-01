#include "Option09.h"
#include "BinLattice02.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

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

double EurOption::PriceByCRR(BinModel Model)
{
    double q = Model.Cal_q(), R = Model.GetR();
    int N = GetN();
    vector<double> Price(N+1);
    for(int i=0; i<=N; i++)
        Price[i] = Payoff(Model.Cal_S(N, i));

    for(int n=N-1; n>=0; n--){
        for(int i=0; i<=n; i++)
            Price[i] = ( q * Price[i+1] + (1-q) * Price[i] ) / (1+R);
    }

    return Price[0];
}

double EurOption::PriceByCRRHW6(BinModel Model, BinLattice<double> & PriceTree, BinLattice<double> & XTree, BinLattice<double> & YTree)
{
    double q = Model.Cal_q(), R = Model.GetR();
    int N = GetN();

    BinLattice<double> StockTree;

    PriceTree.SetN(N);
    XTree.SetN(N);
    YTree.SetN(N);
    StockTree.SetN(N);

    // Calculate each node of Stock tree
    for(int n=0; n<=N; n++){
        for(int i=0; i<=n; i++){
            StockTree.SetNode(n, i, Model.Cal_S(n, i));
        }
    }

    // Calculate payoff of the last day
    for(int i=0; i<=N; i++){
        PriceTree.SetNode( N, i, Payoff( StockTree.GetNode(N,i) ) );
    }

    // Calculate each node of price tree
    double val1;
    for(int n=N-1; n>=0; n--){
        for(int i=0; i<=n; i++){
            val1 = ( q * PriceTree.GetNode(n+1,i+1) + (1-q) * PriceTree.GetNode(n+1,i) ) / (1+R);
            PriceTree.SetNode(n, i, val1);
        }
    }

    // Calculate each node of X Tree and Y Tree
    double val2, val3, val4;
    for(int n=N-1; n>=0; n--){
        for(int i=0; i<=n; i++){
            val2 = PriceTree.GetNode(n+1, i+1) - PriceTree.GetNode(n+1, i);
            val3 = StockTree.GetNode(n+1, i+1) - StockTree.GetNode(n+1, i);
            XTree.SetNode(n, i, val2/val3);

            val4 = PriceTree.GetNode(n+1, i) - (val2/val3) * StockTree.GetNode(n+1, i);
            YTree.SetNode( n, i, val4 / (1+R) );
        }
    }
    return PriceTree.GetNode(0,0);
}

double AmOption::PriceBySnell(BinModel Model, BinLattice<double> & PriceTree, BinLattice<bool> & StoppingTree)
{
    double q = Model.Cal_q(), R = Model.GetR();
    int N = GetN();

    PriceTree.SetN(N);
    StoppingTree.SetN(N);

    for(int i=0; i<=N; i++){
        PriceTree.SetNode(N, i, Payoff(Model.Cal_S(N, i)));
        StoppingTree.SetNode(N, i, 1);
    }

    double val1, val2;
    for(int n=N-1; n>=0; n--){
        for(int i=0; i<=n; i++){
            val1 = (q*PriceTree.GetNode(n+1,i+1) + (1-q)*PriceTree.GetNode(n+1,i)) / (1+R);

            val2 = Payoff(Model.Cal_S(n,i));
            PriceTree.SetNode(n, i, val2);
            StoppingTree.SetNode(n, i, 1);

            if(val1 > val2){   // if val1>val2, we do not exercise
                PriceTree.SetNode(n, i, val1);
                StoppingTree.SetNode(n, i, 0);
            }
            else if(val2==0.0){   // if val2>val1 but val2==0, we also do not exercise
                StoppingTree.SetNode(n, i, 0);
            }
        }
    }
    return PriceTree.GetNode(0,0);
}
