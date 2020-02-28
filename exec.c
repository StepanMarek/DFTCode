#include <stdio.h>
#include <basis/basis_atomic.h>

int main(){
    SHPointer Y11 = getSphericalHarmonic(1, 1);
    cdouble retVal = (*Y11)(20.0, 30.0);
    printf("%g, %g\n", retVal.real, retVal.imaginary);
    return 0;
}
