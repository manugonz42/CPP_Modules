#include "Fixed.hpp"

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

        void    getX(void) const;
        void    getY(void) const;
        bool    bsp( Point const a, Point const b, Point const c, Point const point);
};