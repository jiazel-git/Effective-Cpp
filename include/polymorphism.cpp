
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Base {
public:
    Base() : m_str( new string{ "nihao" } ){};
    virtual ~Base() {
        delete m_str;
        std::cout << "~Base()\n";
    }
    virtual void f() {
        cout << "I am Base Class\n";
    }
    virtual void d() {
        cout << "~~~~~~~\n";
    }

private:
    string* m_str;
};
class Divered : public Base {
public:
    Divered()
        : m_data( new int{ 5 } ){
              // f();
          };
    void f() {
        cout << "I am Divered Class\n";
    }
    void d() {
        *m_data = 5;
        cout << "-------\n";
    }
    ~Divered() {
        delete m_data;
        m_data = nullptr;
        d();
    }

private:
    int* m_data;
};
void interface( Base& obj ) {
    obj.f();
}
void interface( Base* obj ) {
    obj->f();
}
