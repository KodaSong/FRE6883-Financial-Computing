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
    cout<<"European Call Option Price = "<<Option1.PriceByCRR(Model)<<endl;
    cout<<endl;

    // Euro Put Option
    EuroPut Option2;
    Option2.GetInputData();
    cout<<"European Put Option Price = "<<Option2.PriceByCRR(Model)<<endl;
    cout<<endl;

    // Euro bull spread Option
    BullSpread Option3;
    Option3.GetInputData();
    cout<<"European bull spread Price = "<<Option3.PriceByCRR(Model)<<endl;
    cout<<endl;

    // Euro bear spread Option
    BearSpread Option4;
    Option4.GetInputData();
    cout<<"European bear spread Price = "<<Option4.PriceByCRR(Model)<<endl;
    cout<<endl;
}
