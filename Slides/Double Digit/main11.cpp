#include "BinModel02.h"
#include "Option06.h"
#include <iostream>

using namespace std;

int main()
{
    BinModel Model;
    if(Model.GetInputData()==1) return 1;

    // Euro Call Option
    EuroCall Option1;
    Option1.GetInputData();
    cout << "European Call Option Price = " << Option1.PriceByCRR(Model);
    cout << endl << endl;

    // Euro Put Option
    EuroPut Option2;
    Option2.GetInputData();
    cout << "European Put Option Price = " << Option2.PriceByCRR(Model);
    cout << endl << endl;

    // Euro Double-Digital
    DoubleDigit Option3;
    Option3.GetInputData();
    cout << "European double-digital Option Price = " << Option3.PriceByCRR(Model);
    cout << endl << endl;

    // Euro strangle spread Option
    Strangle Option4;
    Option4.GetInputData();
    cout << endl;
    cout << "N = "  << Option4.GetN() << endl;
    cout << "K1 = " <<Option4.GetK1() << endl;
    cout << "K2 = " <<Option4.GetK2() << endl <<endl;

    cout << "European strangle spread Price = " << Option4.PriceByCRR(Model);
    cout << endl << endl;

    // Euro butterfly spread Option
    Butterfly Option5;
    Option5.GetInputData();
    cout << endl;
    cout << "N = "  << Option5.GetN()  << endl;
    cout << "K1 = " << Option5.GetK1() << endl;
    cout << "K2 = " << Option5.GetK2() << endl << endl;

    cout << "European butterfly spread Price = " << Option5.PriceByCRR(Model);
    cout << endl << endl;
}

/*
Enter S0: 106
Enter U: 0.15125
Enter D: -0.13138
Enter R: 0.00545

Input Data Checked.
There is no arbitrage.

Enter call option data:
Enter Steps to Expiry N: 8
Enter Strike Price K: 100
European Call Option Price = 21.6811

Enter put option data:
Enter Steps to Expiry N: 8
Enter Strike Price K: 100
European Put Option Price = 11.4261

Enter European bull spread data:
Enter Steps to Expiry N: 8
Enter parameter K1: 100
Enter parameter K2: 110
European bull spread Price = 4.71584

Enter European bear spread data:
Enter Steps to Expiry N: 8
Enter parameter K1: 100
Enter parameter K2: 110
European bear spread Price = 4.85866
*/
