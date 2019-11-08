#include <iostream>
#include "Option.h"

using namespace std;

int main()
{
    Call Option1;
    if(Option1.GetInputData()==1)    return 1;

    cout << "The d1 is:" << Option1.Cal_d1() << endl;
    cout << "The d2 is:" << Option1.Cal_d2() << endl;
    cout << "The call option price is:" << Option1.Price() << endl << endl;

    Put Option2;
    if(Option2.GetInputData()==1)    return 1;

    cout << "The d1 is:" << Option2.Cal_d1() << endl;
    cout << "The d2 is:" << Option2.Cal_d2() << endl;
    cout << "The put option price is:" << Option2.Price() << endl << endl;

    return 0;
}

