#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point();
        Point(const Fixed& x, const Fixed& y);
        Point(const Fixed& other);
        Point& operator=(const Point& other);
        ~Point();

        const Fixed&  getX(void) const;
        const Fixed&  getY(void) const;
};
#endif