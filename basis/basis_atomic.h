struct cDoubleStruct {
    double real;
    double imaginary;
};
typedef struct cDoubleStruct cdouble;
typedef cdouble (*SHPointer)(double, double);

SHPointer getSphericalHarmonic(int l, int m);
