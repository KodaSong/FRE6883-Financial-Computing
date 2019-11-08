#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "BinModel.h"
#include "BinLattice02.h"
#include "Option.h"

using namespace std;

int main()
{
    BinModel Model;
    Model.GetInputData();

    AmCall Option1;
    Option1.GetInputData();

    BinLattice<double> PriceTree;
    BinLattice<bool> StoppingTree;

    cout << setiosflags(ios::fixed) << setprecision(5);

    cout << "S0 = "    << Model.GetS0()    << endl;
    cout << "r = "     << Model.Getr()     << endl;
    cout << "sigma = " << Model.GetSigma() << endl;
    cout << "T = "     << Model.GetT()     << endl;
    cout << "K = "     << Option1.GetK()   << endl;
    cout << "N = "     << Option1.GetN()   << endl << endl;

    cout << "U = " << Model.Cal_U(Option1.GetN()) << endl;
    cout << "D = " << Model.Cal_D(Option1.GetN()) << endl;
    cout << "R = " << Model.Cal_R(Option1.GetN()) << endl << endl;

    cout << "American Call Option price = "
         << Option1.PriceBySnell(Model, PriceTree, StoppingTree) << endl;
}

/*
Enter S0 = 106.0
Enter r = 0.058
Enter sigma = 0.46
Enter T = 0.75

Enter K = 100.0
Enter N = 8

S0 = 106.00000
r = 0.05800
sigma = 0.46000
T = 0.75000
K = 100.00000
N = 8

U = 0.14610
D = -0.13526
R = 0.00545

American Call Option price = 21.33399
*/
