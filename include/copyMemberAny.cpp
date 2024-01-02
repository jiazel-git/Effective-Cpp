#include <iostream>
class Base {
public:
    Base( const std::string& data = "null" ) : m_data( data ) {}
    Base( const Base& other )            = default;
    Base& operator=( const Base& other ) = default;

protected:
    std::string m_data;
};
class Divered : public Base {
public:
    Divered( const std::string& data = "null", const int& i = 0 ) : Base( data ), m_data1( i ) {}
    Divered( const Divered& other ) : Base( other ), m_data1( other.m_data1 ) {}  // 1
    Divered& operator=( const Divered& other ) {
        Base::operator=( other );                                                 // 2
        m_data1 = other.m_data1;
        return *this;
    }
    friend std::ostream& operator<<( std::ostream& os, const Divered& obj ) {
        std::cout << obj.m_data << " " << obj.m_data1;
        return os;
    }

private:
    int m_data1;
};
void test() {
    Divered d{ "hello", 2 };
    Divered d1{ d };
    Divered d2{ "nihao", 3 };
    Divered d3{ "world", 4 };
    d2 = d;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
}
