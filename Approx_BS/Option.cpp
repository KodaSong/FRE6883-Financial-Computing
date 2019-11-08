#include "BinLattice02.h"
#include "BinModel.h"
#include "Option.h"
#include <iostream>
#include <vector>
using namespace std;

void AmCall::GetInputData()
{
    cout << "Enter K = "; cin >> K;
    cout << "Enter N = ";  cin >> N;
    cout << endl;
}

double AmCall::Payoff(double z)
{
    if(z>K)
        return z-K;
    return 0.0;
}

double AmCall::PriceBySnell(BinModel Model, BinLattice<double> &PriceTree, BinLattice<bool> &StoppingTree)
{
    int N = GetN();
    double U = Model.Cal_U(N), D = Model.Cal_D(N), R = Model.Cal_R(N);
    double q = ( R - D ) / ( U - D );

    PriceTree.SetN(N);
    StoppingTree.SetN(N);

    for(int i=0; i<=N; i++){
        PriceTree.SetNode(N, i, Payoff(Model.Cal_S(N,N,i)));
        StoppingTree.SetNode(N, i, 1);
    }

    double val1, val2;
    for(int n=N-1; n>=0; n--){
        for(int i=0; i<=n; i++){
            val1 = (q*PriceTree.GetNode(n+1,i+1) + (1-q)*PriceTree.GetNode(n+1,i)) / (1+R);

            val2 = Payoff(Model.Cal_S(N,n,i));
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
