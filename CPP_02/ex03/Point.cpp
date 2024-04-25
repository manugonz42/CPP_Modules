#include "Point.hpp"

Point::Point(){
}
Point::Point(const Fixed& other){
    *this = other;
}
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y){
}
Point&  Point::operator=( const Point &other) {
    if (this != &other)
        return *this;
    return *this;
}
Point::~Point(){
}

const Fixed&   Point::getX(void) const{
    return (this->_x);
}
const Fixed&   Point::getY(void) const{
    return (this->_y);
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