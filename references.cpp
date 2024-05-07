#include <iostream>

int main() {
    int x {1};
    int& ref {x}; // Must be initialized
    std::cout << ref;

    ref++; // same as x++
    std::cout << ref;

    int y {10};
    ref = y; // can't be reseated (std::reference_wrapper can)
    std::cout << ref;

    int& ref2 {ref}; // Bounded to lval to which ref is bounded
    ref2++;
    std::cout << ref2;
    

    /* 
        Const LVal refs can hold const/non-const lVals and RVals
        Non-Const can only hold non-const LVals
    */
    const int z {100};
    const int& constRef {z};

    int a {100};
    const int& constRef2 {a};
    
    const int& rvalRef {3};
}