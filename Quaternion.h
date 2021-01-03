#include <iostream>
#include <immintrin.h>
#include "malloc.h"

#define SIMD

class Quaternion
{

private:
    struct Components{
        double a;
        double b;
        double c;
        double d;
    };
    Components comp;
public:
    Quaternion(double a, double b, double c, double d);
    ~Quaternion();
    Quaternion operator +(Quaternion &q1);
    void operator =(Quaternion &q1);
};




