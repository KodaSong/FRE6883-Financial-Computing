#include <iostream>
#include <fstream>
#include "BinLattice02.h"
#include "BinModel02.h"
#include "Option09.h"
using namespace std;

int main()
{
    BinModel Model;
    if(Model.GetInputData()==1) return 1;

    ofstream fout;
    fout.open("Result.txt");

    Call Option1;
    Option1.GetInputData();

    BinLattice<double> PriceTree;
    BinLattice<double> XTree;
    BinLattice<double> YTree;

    fout << "S0 = " << Model.GetS0()  << endl
         << "U = "  << Model.GetU()   << endl
         << "D = "  << Model.GetD()   << endl
         << "R = "  << Model.GetR()   << endl
         << "N = "  << Option1.GetN() << endl
         << "K = "  << Option1.GetK() << endl << endl;

    fout << "European call prices by PriceByCRR: "
         << Option1.PriceByCRR(Model) << endl << endl;

    fout << "European call Prices by PriceByCRRHW6:"
         << Option1.PriceByCRRHW6(Model, PriceTree, XTree, YTree)
         << endl << endl;

    fout << "European call option prices:" << endl << endl;
    PriceTree.Display(fout);

    fout << "Stock positions in replicating strategy: " << endl << endl;
    XTree.Display1(fout);

    fout << "Money market account positions in replicating strategy: " << endl << endl;
    YTree.Display1(fout);

    Put Option2;
    Option2.GetInputData();

    fout << "N = " << Option2.GetN() << endl
         << "K = " << Option2.GetK() << endl << endl;

    fout << "European put prices by PriceByCRR: "
         << Option2.PriceByCRR(Model) << endl << endl;

    fout << "European put Prices by PriceByCRRHW6: "
         << Option2.PriceByCRRHW6(Model, PriceTree, XTree, YTree)
         << endl << endl;

    fout << "European put option prices:" << endl << endl;
    PriceTree.Display(fout);

    fout << "Stock positions in replicating strategy: " << endl << endl;
    XTree.Display1(fout);

    fout << "Money market account positions in replicating strategy: " << endl << endl;
    YTree.Display1(fout);

    return 0;
}

/*
Enter S0: 106
Enter U: 0.15125
Enter D: -0.13138
Enter R: 0.00545

Input Data Checked.
There is no arbitrage.

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K: 100

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K: 100
*/

/*
S0 = 106
U = 0.15125
D = -0.13138
R = 0.00545
N = 8
K = 100

European call prices by PriceByCRR: 21.6811

European call Prices by PriceByCRRHW6:21.6811

European call option prices:

      21.681102
      12.057136      32.180046
       5.573885      19.101133      46.478617
       1.875302       9.577678      29.463932      65.131937
       0.322496       3.551014      16.107243      44.027913      88.352660
       0.000000       0.669763       6.661122      26.353936      63.356156     115.982439
       0.000000       0.000000       1.390973      12.351745      41.570725      87.282967     147.868975
       0.000000       0.000000       0.000000       2.888792      22.574097      62.280665     114.906883     184.656525
       0.000000       0.000000       0.000000       0.000000       5.999481      40.489399      86.201585     146.787519     227.086795

Stock positions in replicating strategy:

       0.671687
       0.519823       0.793779
       0.340754       0.663788       0.898288
       0.164433       0.482509       0.809529       0.969646
       0.039272       0.265059       0.657332       0.931891       1.000000
       0.000000       0.070844       0.421200       0.847173       1.000000       1.000000
       0.000000       0.000000       0.127801       0.657082       1.000000       1.000000       1.000000
       0.000000       0.000000       0.000000       0.230548       1.000000       1.000000       1.000000       1.000000

Money market account positions in replicating strategy:

     -49.517673
     -35.804903     -64.686828
     -21.678622     -51.260309     -79.721732
      -9.547825     -34.848707     -69.324838     -91.697652
      -2.047258     -17.647580     -53.569769     -86.893151     -97.849382
       0.000000      -4.251772     -32.120224     -77.028506     -98.382661     -98.382661
       0.000000       0.000000      -8.830135     -57.298701     -98.918846     -98.918846     -98.918846
       0.000000       0.000000       0.000000     -18.338539     -99.457954     -99.457954     -99.457954     -99.457954

N = 8
K = 100.000000

European put prices by PriceByCRR: 11.426118

European put Prices by PriceByCRRHW6: 11.426118

European put option prices:

      11.426118
      16.250242       6.414371
      22.388290       9.892742       2.780181
      29.724608      14.823064       4.750575       0.711914
      37.829118      21.423419       7.956885       1.387551       0.000000
      45.967733      29.582823      12.970288       2.704396       0.000000       0.000000
      53.390192      38.576161      20.332941       5.270981       0.000000       0.000000       0.000000
      59.910854      47.043091      29.988438      10.273364       0.000000       0.000000       0.000000       0.000000
      65.648598      54.471401      39.657389      20.023219       0.000000       0.000000       0.000000       0.000000       0.000000

Stock positions in replicating strategy:

      -0.328313
      -0.480177      -0.206221
      -0.659246      -0.336212      -0.101712
      -0.835567      -0.517491      -0.190471      -0.030354
      -0.960728      -0.734941      -0.342668      -0.068109       0.000000
      -1.000000      -0.929156      -0.578800      -0.152827       0.000000       0.000000
      -1.000000      -1.000000      -0.872199      -0.342918       0.000000       0.000000       0.000000
      -1.000000      -1.000000      -1.000000      -0.769452       0.000000       0.000000       0.000000       0.000000

Money market account positions in replicating strategy:

      46.227343
      60.461923      31.579997
      75.112857      45.531171      17.069748
      87.771169      62.470286      27.994156       5.621341
      95.802124      80.201802      44.279612      10.956231       0.000000
      98.382661      94.130889      66.262437      21.354155       0.000000       0.000000
      98.918846      98.918846      90.088712      41.620146       0.000000       0.000000       0.000000
      99.457954      99.457954      99.457954      81.119415       0.000000       0.000000       0.000000       0.000000

*/
