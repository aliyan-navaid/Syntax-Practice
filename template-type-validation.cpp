#include <type_traits> // For type traits like is_integral
#include <typeinfo> // For type name

// First Technique: Using Type Traits

/* 
    `enable_if_t` is an alias for `enable_if::value`.
*/
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void foo(T value) {
    return;
}

// Second Technique: Using Static Assert

/*
    This function template asserts that the type `T` passed to it is integral.
    If the assertion fails, a static assertion error will occur at compile time.
*/
template <typename T>
void poo(T value) {
    static_assert(std::is_integral_v<T>, "Data Type must be integral");
}

// Third Technique: Using Type Name

/*
    Implements SFINAE (Substitution Failure is Not an Error).
    Other methods will cause program to crash, this won't.
*/
template <typename T>
void boo(T value) {
    if (std::is_same_v<T, int>) {

    }
    if (typeid(value).name()=='i') {

    }
}

int main() {
    // Usage examples for `foo`, `boo`, and 'poo' functions

    foo(3);       // Correct usage
    foo("hello"); // Incorrect usage

    boo(3);       // Correct usage
    boo("hello"); // Incorrect usage

    poo(3);       // Correct usage
    poo("hello")  // Incorrect usage
}
