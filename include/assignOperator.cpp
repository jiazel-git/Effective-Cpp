#include <iomanip>
#include <iostream>

// return a value to *this
struct A {
    A() = default;
    A operator=( const A& ) {
        return *this;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};
// return a reference to *this
struct B {
    B() = default;
    B& operator=( const B& ) {
        return *this;
    }
    ~B() {
        std::cout << "~B()" << std::endl;
    }
};
// return a void
struct C {
    C() = default;
    void operator=( const C& ) {
        return;
    }
    ~C() {
        std::cout << "~C()" << std::endl;
    }
};
void test() {
    {
        A a, a1, a2;
        // a = a1 = a2;
        a.operator=( a1.operator=( a2 ) );
    }
    std::cout << std::setw( 10 ) << std::setfill( '-' ) << "" << std::endl;
    {
        B b, b1, b2;
        b = b1 = b2;
    }
    std::cout << std::setw( 10 ) << std::setfill( '-' ) << "" << std::endl;
    {
        C c, c1, c2;
        c = c1;
        // c = c1 = c2;
    }
}