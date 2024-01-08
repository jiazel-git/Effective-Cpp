#include <iostream>
class Base {
public:
    Base( const std::string& data ) : m_data( data ) {}
    Base()                               = default;
    Base( const Base& other )            = default;
    Base& operator=( const Base& other ) = default;

protected:
    std::string m_data;
};
class Derived : public Base {
public:
    Derived( const std::string& data, const int& i ) : Base( data ), m_data1( i ) {}
    Derived( const Derived& other ) : Base( other ), m_data1( other.m_data1 ) {}  // 1
    Derived& operator=( const Derived& other ) {
        Base::operator=( other );                                                 // 2
        m_data1 = other.m_data1;
        return *this;
    }
    friend std::ostream& operator<<( std::ostream& os, const Derived& obj ) {
        std::cout << obj.m_data << " " << obj.m_data1;
        return os;
    }

private:
    int m_data1;
};
void test() {
    Derived d{ "hello", 2 };
    Derived d1{ d };
    Derived d2{ "nihao", 3 };
    Derived d3{ "world", 4 };
    d2 = d;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
}
