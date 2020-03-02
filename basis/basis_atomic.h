struct cDoubleStruct {
    double real;
    double imaginary;
};
typedef struct cDoubleStruct cdouble;
typedef cdouble (*SHPointer)(double, double);
typedef cdouble (*RFPointer)(double, double, double, double);

SHPointer getSphericalHarmonic(int l, int m);
RFPointer NCollection[4];
