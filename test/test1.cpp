#include "Array.h"
#include <stdio.h>
#include <string>


using namespace std;


bool test1()
{
    string errors = "";
    
    
    // Print header for this test.
    printf("\n--- Test 1 ---\n");
    
    
    // Array1
    try {
        CKG_Utils::Array1<double> A(0);
        errors += "Array1: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array1: Did not throw correct exception number.\n";
    }
    
    
    // Array2
    try {
        CKG_Utils::Array2<double> A(1,0);
        errors += "Array2: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array2: Did not throw correct exception number.\n";
    }
    
    
    // Array3
    try {
        CKG_Utils::Array3<double> A(1,1,0);
        errors += "Array3: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array3: Did not throw correct exception number.\n";
    }
    
    
    // Array4
    try {
        CKG_Utils::Array4<double> A(1,1,1,0);
        errors += "Array4: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array4: Did not throw correct exception number.\n";
    }
    
    
    // Array5
    try {
        CKG_Utils::Array5<double> A(1,1,1,1,0);
        errors += "Array5: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array5: Did not throw correct exception number.\n";
    }
    
    
    // Array6
    try {
        CKG_Utils::Array6<double> A(1,1,1,1,1,0);
        errors += "Array6: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array6: Did not throw correct exception number.\n";
    }
    
    
    // Array7
    try {
        CKG_Utils::Array7<double> A(1,1,1,1,1,1,0);
        errors += "Array7: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array7: Did not throw correct exception number.\n";
    }
    
    
    // Array8
    try {
        CKG_Utils::Array8<double> A(1,1,1,1,1,1,1,0);
        errors += "Array8: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array8: Did not throw correct exception number.\n";
    }
    
    
    // Array9
    try {
        CKG_Utils::Array9<double> A(1,1,1,1,1,1,1,1,0);
        errors += "Array9: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array9: Did not throw correct exception number.\n";
    }
    
    
    // Array10
    try {
        CKG_Utils::Array10<double> A(1,1,1,1,1,1,1,1,1,0);
        errors += "Array10: Did not catch out of bounds error.\n";
    }
    catch(int error) {
        if (error != -1) 
            errors += "Array10: Did not throw correct exception number.\n";
    }
    
    
    
    // End test
    printf("\n--- Errors reported for test ---\n");
    printf("%s\n", errors.c_str());
    if (errors == "")
        return true;
    return false;
}
