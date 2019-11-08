#include <iostream>
#include <string>
#include "BinLattice02.h"
#include "BinModel02.h"
#include "Option09.h"
using namespace std;

int main()
{
    BinModel Model;
    if( Model.GetInputData()==1 ) return 1;

    Put Option;
    Option.GetInputData();

//    BinLattice<double> PriceTree;
//    BinLattice<double> StockTree;
//    Option.PriceByCRR(Model, StockTree, PriceTree);
//
//    cout << "Stock prices:" << endl << endl;
//    StockTree.Display();
//
//    cout << "American put prices:" << endl << endl;
//    PriceTree.Display();

    BinLattice<double> PriceTree;
    BinLattice<string> StoppingTree;
    BinLattice<double> StockTree;
    Option.PriceBySnell(Model, PriceTree, StoppingTree, StockTree);

    cout << "Stock prices:" << endl << endl;
    StockTree.Display();

    cout << "American put prices:" << endl << endl;
    PriceTree.Display();

    cout << "American put exercise policy:" << endl << endl;
    StoppingTree.Display();

    return 0;
}

/*
Enter S0: 106
Enter U: 0.15125
Enter D: -0.13138
Enter R: 0.00545

Input Data Checked.
There is no arbitrage.

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K: 100

Stock prices:

   106.000   122.033   140.490   161.739   186.202   214.365   246.788   284.114   327.087
    -1.000    92.074   106.000   122.032   140.490   161.739   186.202   214.365   246.788
    -1.000    -1.000    79.977    92.074   106.000   122.032   140.490   161.739   186.202
    -1.000    -1.000    -1.000    69.470    79.977    92.073   106.000   122.032   140.489
    -1.000    -1.000    -1.000    -1.000    60.343    69.470    79.977    92.073   105.999
    -1.000    -1.000    -1.000    -1.000    -1.000    52.415    60.343    69.470    79.977
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    45.529    52.415    60.343
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    39.547    45.529
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    34.351

American put prices:

    11.724     6.517     2.799     0.712     0.000     0.000     0.000     0.000     0.000
    -1.000    16.734    10.075     4.788     1.388     0.000     0.000     0.000     0.000
    -1.000    -1.000    23.161    15.143     8.030     2.704     0.000     0.000     0.000
    -1.000    -1.000    -1.000    30.930    21.978    13.113     5.271     0.000     0.000
    -1.000    -1.000    -1.000    -1.000    39.657    30.530    20.611    10.273     0.000
    -1.000    -1.000    -1.000    -1.000    -1.000    47.585    39.657    30.530    20.023
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    54.471    47.585    39.657
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    60.453    54.471
    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    -1.000    65.649

American put exercise policy:

        no        no        no        no        no        no        no        no       yes
                  no        no        no        no        no        no        no       yes
                            no        no        no        no        no        no       yes
                                      no        no        no        no        no       yes
                                               yes       yes        no        no       yes
                                                         yes       yes       yes       yes
                                                                   yes       yes       yes
                                                                             yes       yes
                                                                                       yes
*/
