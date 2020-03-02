#include <math.h>
#include <stdlib.h>

struct cDoubleStruct {
    double real;
    double imaginary;
};
typedef struct cDoubleStruct cdouble;
typedef cdouble (*SHPointer)(double, double);
typedef cdouble (*RFPointer)(double, double, double, double);

cdouble Y00(double theta, double phi){
    cdouble retval;
    retval.real = sqrt(1/(4*M_PI));
    retval.imaginary = 0.0;
    return retval;
}

cdouble Y11(double theta, double phi){
    cdouble retval;
    retval.real = -0.5*sqrt(3/(2*M_PI))*cos(phi)*sin(theta);
    retval.imaginary = -0.5*sqrt(3/(2*M_PI))*sin(phi)*sin(theta);
    return retval;
}

cdouble Y10(double theta, double phi){
    cdouble retval;
    retval.real = 0.5*sqrt(3/M_PI)*cos(theta);
    retval.imaginary = 0.0;
    return retval;
}

cdouble Y1m1(double theta, double phi){
    cdouble retval;
    retval.real = 0.5*sqrt(3/(2*M_PI))*cos(phi)*sin(theta);
    retval.imaginary = -0.5*sqrt(3/(2*M_PI))*sin(phi)*sin(theta);
    return retval;
}

// Can be expanded as needed
SHPointer LCollection[4] = {&Y00, &Y11, &Y10, &Y1m1};

SHPointer getSphericalHarmonic(int l, int m){
    return LCollection[l * l + l - m];
}

// Given in units of Bohr radii and neglecting the mass of the electron with respect to
// the mass of the nucleus
double R10(double r, double Z){
    double retval;
    retval = sqrt(4*Z*Z*Z)*exp(-Z*r);
    return retval;
}

double R20(double r, double Z){
    double retval;
    retval = sqrt(Z*Z*Z/32)*exp(-Z*r/2)*(2-Z*r);
    return retval;
}

double R21(double r, double Z){
    double retval;
    retval = sqrt(Z*Z*Z/864)*exp(-Z*r/2)*Z*r;
    return retval;
}

cdouble mixedProduct(double a, cdouble b){
    cdouble retval;
    retval.real = a * b.real;
    retval.imaginary = a * b.imaginary;
    return retval;
}

cdouble s100(double r, double theta, double phi, double Z){
    return mixedProduct(R10(r, Z), Y00(theta, phi));
}
cdouble s200(double r, double theta, double phi, double Z){
    return mixedProduct(R20(r, Z), Y00(theta, phi));
}
cdouble p211(double r, double theta, double phi, double Z){
    return mixedProduct(R21(r, Z), Y11(theta, phi));
}
cdouble p210(double r, double theta, double phi, double Z){
    return mixedProduct(R21(r, Z), Y10(theta, phi));
}

RFPointer NCollection[4] = {&s100, &s200, &p211, &p210};

// TODO : Properly rewrite
// RFPointer getHydrogenicWavefunction(int n, int l, int m){
//     int extraOffset = 0;
//     if(l > 0){
//         extraOffset = 2*(l-1)+1
//     }
//     return NCollection[(n-1)*(n-1) + extraOffset + l-m]
// }
