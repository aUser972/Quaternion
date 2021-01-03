#include "Quaternion.h"

Quaternion::Quaternion(double a, double b, double c, double d)
{
    this->comp.a = a;
    this->comp.b = b;
    this->comp.c = c;
    this->comp.d = d;
}

Quaternion::~Quaternion()
{
}

Quaternion Quaternion::operator +(Quaternion &q1)
{
#ifndef SIMD
    return Quaternion(this->comp.a+q1.comp.a,
                      this->comp.b+q1.comp.b,
                      this->comp.c+q1.comp.c,
                      this->comp.d+q1.comp.d);
#else
    double d1[4] = {1.1, 2.2, 3.3, 4.4};
    double d2[4] = {1.1, 2.2, 3.3, 4.4};
    __m256d* thisSIMD = reinterpret_cast<__m256d*>(d1);
    __m256d* q1SIMD = reinterpret_cast<__m256d*>(d2);

    auto size = sizeof(Components);
    void *ptr = aligned_alloc(size, 32);
    double* c = reinterpret_cast<double*>(ptr);
    _mm256_store_pd(c, _mm256_add_pd(*thisSIMD, *q1SIMD));

    return Quaternion(1,2,3,4);
#endif
}

void Quaternion::operator =(Quaternion &q1)
{
    this->comp.a = q1.comp.a;
    this->comp.b = q1.comp.b;
    this->comp.c = q1.comp.c;
    this->comp.d = q1.comp.d;
}
