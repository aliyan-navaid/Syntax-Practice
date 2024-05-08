#include <iostream>
using std::cout, std::endl;

int main() {
    /* 
        Favour References for Dereferencing NULL Pointers  
        and Reseating Pointers (more likely to encounter
        dangling pointers) are dangerous
    */

    int x{10};

    /* Address Of | Dereferencing */
    cout << &x << endl;
    cout << *(&x) << endl;

    /* Pointer is an Object itself */
    int* intPointer; // Wild Pointer
    cout << "Pointer's Address: "<<&intPointer << endl;

    intPointer = nullptr; // Avoid 0 (Architecture Based), NULL (C)
    intPointer = &x;
    cout << *intPointer << endl;

    /* Dangling Pointer - Undefined Behavior */
    {
        // Pointer can be reseated
        intPointer = new int;
        *intPointer = 5;
        cout << *intPointer << endl;
    }
    cout << "Dangling Pointer: " << *intPointer << endl;

    const int* pointerToConstInt {};
    int* const constPointer {};
    const int* const constPtrToConstInt {};
}