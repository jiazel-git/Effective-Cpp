#include <iostream>
struct Point {
    void set( int x, int y ) {
        m_x = x;
        m_y = y;
    }
    Point( int x, int y ) : m_x( x ), m_y( y ) {}
    int m_x;
    int m_y;
};
class Rectangle {
public:
    Rectangle( const Point& l, const Point& r ) : m_l( l ), m_r( r ) {}
    Point& upperLeft() const {
        return const_cast< Point& >( m_l );
    }
    Point& lowerRight() const {
        return const_cast< Point& >( m_r );
    }

private:
    Point m_l;
    Point m_r;
};

void test() {
    Rectangle r( Point( 1, 2 ), Point( 3, 4 ) );
    r.upperLeft().set( 3, 4 );
}
