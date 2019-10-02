#ifndef DefInt_h
#define DefInt_h

// Function for integration
double my_func(double x);

// Input Data
int GetInputData(double &a, double &b, int &N);

// Create a class
class DefInt
{
private:
    double (*f)(double), a, b;
public:
    DefInt();
    DefInt(double a, double b, double (*f)(double));
    double ByTrapzoid(int N);

};

#endif // DefInt_h

