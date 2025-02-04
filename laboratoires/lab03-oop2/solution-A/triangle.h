#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <string>

#include "point.h"

class Triangle {
private:
    Point *_points;

public:
    Triangle();
    Triangle(const Point &, const Point &, const Point &);
    Triangle(const Triangle &);
    ~Triangle();

    Triangle &operator=(const Triangle &);

    double getAire() const;
    bool estInterieur(const Point &) const;

    bool estValide() const;
    bool estRectangle() const;
};

#endif