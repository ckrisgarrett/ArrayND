#include <stdio.h>

/*
    Test1 - Constructor Bounds
    Test2 - operator() and operator[] with constructor supplying data
    Test3 - operator() and operator[] with constructor not supplying data
    Test4 - Check bounds on operator() and operator[]
    Test5 - getData
    Test6 - getDims
*/

bool test1();
//bool test2();
//bool test3();
//bool test4();
//bool test5();
//bool test6();


static
void printResult(bool result, int test)
{
    if(result == false)
        printf("   Test %d: failed\n", test);
    else
        printf("   Test %d: passed\n", test);
}


int main()
{
    printf("\n\n");  bool result1 = test1();
    //printf("\n\n");  bool result2 = test2();
    //printf("\n\n");  bool result3 = test3();
    //printf("\n\n");  bool result4 = test4();
    //printf("\n\n");  bool result5 = test5();
    //printf("\n\n");  bool result6 = test6();
    
    
    printf("\n\n****** TEST RESULTS ******\n");
    printResult(result1, 1);
    //printResult(result2, 2);
    //printResult(result3, 3);
    //printResult(result4, 4);
    //printResult(result5, 5);
    //printResult(result6, 6);
    printf("\n\n");
    
    return 0;
}
