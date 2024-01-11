#include <iostream>
#include <memory>
void f1() {
    std::shared_ptr< int > sp( new int( 5 ) );
    throw( 1 );
}

void test() {
    try {
        f1();
    }
    catch ( ... ) {
        std::cout << "catch exception" << std::endl;
    }
}