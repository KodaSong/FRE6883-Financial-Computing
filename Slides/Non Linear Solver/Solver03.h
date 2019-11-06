#ifndef Solver03_h
#define Solver03_h

#include <cmath>

template<typename Function>
double SolveByBisect(Function & Fct, double Tgt, double LEnd, double REnd, double Acc)
{
    double left = LEnd, right = REnd, mid = (left+right)/2;
    double y_left = Fct.value(left)-Tgt, y_right = Fct.value(right)-Tgt, y_mid = Fct.value(mid)-Tgt;
    while( mid - left >= Acc ){
        if( y_left * y_mid > 0 ){
            left = mid;
            y_left = Fct.value(left) - Tgt;
        }
        else{
            right = mid;
            y_right = Fct.value(right) - Tgt;
        }
        mid = ( left + right ) / 2;
        y_mid = Fct.value(mid) - Tgt;
    }
    return mid;
}

template<typename Function>
double SolveByNR(Function & Fct, double Tgt, double Guess, double Acc)
{
    double x_prev = Guess;
    double x_next = x_prev - ( Fct.value(x_prev) - Tgt ) / Fct.deriv(x_prev);
    while( ( x_prev - x_next ) >= Acc || ( x_prev - x_next ) <= -Acc ){
        x_prev = x_next;
        x_next = x_prev - ( Fct.value(x_prev) - Tgt ) / Fct.deriv(x_prev);
    }
    return x_next;
}

#endif // Solver03_h
