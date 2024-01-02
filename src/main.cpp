// #include "selfAssign.cpp"
#include "assignOperator.cpp"
// #include "copyMemberAny.cpp"
//  #include "polymorphism.cpp"
//  #include "newAndDelete.cpp"
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <thread>
#include <vector>
using namespace std;
const int& func( const int& a ) {
    return const_cast< const int& >( a );
}
int main( int argc, char** argv ) {
    test();
    return 0;
}