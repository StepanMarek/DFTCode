#include <stdio.h>
#include <basis/basis_atomic.h>

int main(){
    SHPointer Y11 = getSphericalHarmonic(1, -1);
    cdouble retVal = (*Y11)(20.0, 40.0);
    printf("%g, %g\n", retVal.real, retVal.imaginary);
    RFPointer s1 = NCollection[0];
    retVal = (*s1)(1.0, 0.0, 0.0, 1.0);
    printf("%g, %g\n", retVal.real, retVal.imaginary);
    return 0;
}
