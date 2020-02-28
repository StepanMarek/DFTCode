#include <math.h>
#include <stdlib.h>

struct cDoubleStruct {
    double real;
    double imaginary;
};
typedef struct cDoubleStruct cdouble;
typedef cdouble (*SHPointer)(double, double);

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

SHPointer getSphericalHarmonic(int l, int m){
    switch(l){
        case 0:
            return Y00;
        case 1:
            return Y11;
    }
}
