/*
    Should fail compiling because copy constructor is not allowed.
*/

#include "Array.h"


int main()
{
    CKG_Utils::Array1<double> A(2);
    CKG_Utils::Array1<double> B(A);
    
    CKG_Utils::Array2<double> C(3,2);
    CKG_Utils::Array2<double> D(C);
    
    return 0;
}
