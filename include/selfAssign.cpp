#include <iostream>
#include <stdlib.h>
#include <string.h>

class selfAssign {
public:
    selfAssign( const char* str = nullptr ) {
        if ( str == nullptr ) {
            m_data = new char;
            strcpy_s( m_data, 1, "\0" );
        }
        int len = strlen( str );
        m_data  = new char[ len + 1 ];
        strcpy_s( m_data, strlen( str ) + 1, str );
    }
    selfAssign& operator=( const selfAssign& other ) {
        // 判断自我赋值的情况
        if ( m_data == other.m_data ) {
            return *this;
        }
        // 如果未做判断，在此会将数据删除
        if ( m_data ) {
            delete[] m_data;
            m_data = nullptr;
        }
        // 在此拷贝会出现未定义行为
        int len = strlen( other.m_data ) + 1;
        m_data  = new char[ len ];
        strcpy_s( m_data, len, other.m_data );
        return *this;
    }
    ~selfAssign() {
        delete[] m_data;
        m_data = nullptr;
    }
    friend std::ostream& operator<<( std::ostream& os, const selfAssign& obj ) {
        std::cout << obj.m_data;
        return os;
    }

private:
    char* m_data;
};
void test() {
    selfAssign s( "hello world" );
    selfAssign s1( "nihao shijie" );
    s = s;
    std::cout << s;
}