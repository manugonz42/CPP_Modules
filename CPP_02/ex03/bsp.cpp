#include "Point.hpp"

/* Barycentric Coordinate Test *
   α = Area(ABC) / Area(PBC)
   β = Area(ABC) / Area(PCA)
   γ = Area(ABC) / Area(PAB)
*/

Fixed   area(Point const a, Point const b, Point const c){
    Fixed   area((a.getX() * (b.getY() - c.getY()) + b.getX() * \
            (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
    if (area.getRawBits() < 0)
        area.setRawBits(-area.getRawBits());
    return area;
}

bool    bsp(Point const a, Point const b, Point const c, Point const point){
    Fixed alpha, betha, gamma, zero(0), one(1);
    bool  sum, limit;

    alpha = area(a, b, c) / area(point, b, c);
    betha = area(a, b, c) / area(point, c, a);
    gamma = area(a, b, c) / area(point, a, b);

    sum = alpha + betha + gamma == one;
    limit = (zero <= alpha && alpha <= one && \
             zero <= betha && betha <= one && \
             zero <= gamma && gamma <= one);

    return (sum && limit);
}
