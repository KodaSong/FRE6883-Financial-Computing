#include <iostream>
#include <iomanip>
#include <cmath>
#include "Solver03.h"

using namespace std;

class F1
{
public:
    double value(double x) { return x*x - 2; }
    double deriv(double x) { return 2*x; }
};

class F2
{
private:
    double a;
public:
    F2(double a_) : a(a_) {}
    double value(double x) { return x*x - a; }
    double deriv(double x) { return 2*x; }
};

class F3
{
private:
    double c0, c1, c2, F, T, T0, T1, T2;
public:
    F3(double c0_, double c1_, double c2_, double F_,
       double T_, double T0_, double T1_, double T2_) : c0(c0_), c1(c1_), c2(c2_), F(F_), T(T_), T0(T0_), T1(T1_), T2(T2_) {}

    double value(double y)
    {
        return c0*exp(-T0*y) + c1*exp(-T1*y) + c2*exp(-T2*y) + F*exp(-T2*y);
    }

    double deriv(double y)
    {
        return -c0*T0*exp(-T0*y) - c1*T1*exp(-T1*y) - c2*T2*exp(-T2*y) - F*T2*exp(-T2*y);
    }

    double GetF()  { return F;  }
    double GetT()  { return T;  }
    double Getc0() { return c0; }
    double Getc1() { return c1; }
    double Getc2() { return c2; }
    double GetT0() { return T0; }
    double GetT1() { return T1; }
    double GetT2() { return T2; }
};

int main()
{
    F1 MyF1;
    F2 MyF2(3.0);

    double Acc = 0.001;
    double LEnd = 0.0, REnd = 2.0;
    double Tgt = 0.0;

    cout << fixed << setprecision(4);

    cout << "Q1:" << endl;
    cout << "Root of F1 by bisect: " << SolveByBisect(MyF1, Tgt, LEnd, REnd, Acc) << endl;
    cout << "Root of F2 by bisect: " << SolveByBisect(MyF2, Tgt, LEnd, REnd, Acc) << endl;

    double Guess = 1.0;

    cout << "Root of F1 by Newton-Raphson: " << SolveByNR(MyF1, Tgt, Guess, Acc) << endl;
    cout << "Root of F2 by Newton-Raphson: " << SolveByNR(MyF2, Tgt, Guess, Acc) << endl << endl;

    F3 MyF3(1.2, 1.2, 1.2, 100, 3, 1, 2, 3);
    double Tgt_ = 98.56;

    cout << "Q2:" << endl;
    cout << "F = " << MyF3.GetF() << endl;
    cout << "T = " << MyF3.GetT() << endl;

    cout << "coupons:" << endl;
    cout << "C0 = " << MyF3.Getc0() << endl;
    cout << "C1 = " << MyF3.Getc1() << endl;
    cout << "C2 = " << MyF3.Getc2() << endl;

    cout << "tenors:" << endl;
    cout << "T0 = " << MyF3.GetT0() << endl;
    cout << "T1 = " << MyF3.GetT1() << endl;
    cout << "T2 = " << MyF3.GetT2() << endl;

    cout << "P = " << Tgt_ << endl << endl;

    double Acc_ = 0.0001;

    cout << "Yield by bisection method: " << SolveByBisect(MyF3, Tgt_, LEnd, REnd, Acc_) << endl;
    cout << "Yield by Newton-Raphson method: " << SolveByNR(MyF3, Tgt_, Guess, Acc_) << endl;
    cout << endl;

    return 0;
}

/*
Q1:
Root of F1 by bisect: 1.4150
Root of F2 by bisect: 1.7314
Root of F1 by Newton-Raphson: 1.4142
Root of F2 by Newton-Raphson: 1.7321

Q2:
F = 100.0000
T = 3.0000
coupons:
C0 = 1.2000
C1 = 1.2000
C2 = 1.2000
tenors:
T0 = 1.0000
T1 = 2.0000
T2 = 3.0000
P = 98.5600

Yield by bisection method: 0.0168
Yield by Newton-Raphson method: 0.0168
*/
