#include "Array_new.h"
#include <stdio.h>

int main()
{
    CKG_Utils::Array2<double> A(3,4);
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        A(i,j) = i+j;
    }}
    
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        printf("(%d,%d): %f\n", i, j, A(i,j));
    }}
    
    return 0;
}
