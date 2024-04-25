#include "Point.hpp"

Point::Point(){
}
Point::Point(const Fixed& other){
    *this = other;
}
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y){
}
Point&  Point::operator=( const Point &rhs ) {
    return *this;
}
Point::~Point(){
}

/*
Point&  Point::operator=( const Point &rhs ) {
    if ( this != &rhs ) {
        // const_cast< Fixed& >(this->_x) = rhs.getX();
        // const_cast< Fixed& >(this->_y) = rhs.getY();
        ( Fixed ) this->_x = rhs.getX();
        ( Fixed ) this->_y = rhs.getY();
    }
    return *this;
}
*/