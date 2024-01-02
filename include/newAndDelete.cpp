#include <iostream>

struct A {
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};
A* func( size_t size ) {
    if ( size > 1 ) {
        return new A[ size ];
    }
    return new A;
}
void test() {
    A* a_arr = func( 2 );
    delete[] a_arr;
}