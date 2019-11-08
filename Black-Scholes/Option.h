#ifndef Option_h
#define Option_h

class EurOption
{
public:
    double S, K, sigma, T, b, r;
    int GetInputData();
    double Cal_d1();
    double Cal_d2();
};

class Call : public EurOption
{
public:
    double Price();
};

class Put : public EurOption
{
public:
    double Price();
};

#endif // Option_h

