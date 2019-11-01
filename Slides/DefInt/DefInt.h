#ifndef DefInt_h
#define DefInt_h

// Function for integration
double my_func(double x);

// Input Data
void GetInputData(double &a, double &b, int &N);

// Create a class
class DefInt
{
private:
    double (*f)(double), a, b;
public:
    DefInt(double a_, double b_, double (*f_)(double)) : a(a_), b(b_), f(f_) {}
    double ByTrapzoid(int N);
    double BySimpson(int N);

};

#endif // DefInt_h

