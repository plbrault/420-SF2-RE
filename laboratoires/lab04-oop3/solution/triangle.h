#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <string>

#include "point.h"

#define TRIANGLE_NB_POINT 3

class Triangle {
private:
    Point *_points;

    bool _checkPoint(const Point &);

public:
    Triangle();
    Triangle(const Point &, const Point &, const Point &);
    Triangle(const Triangle &);
    ~Triangle();

    Triangle &operator=(const Triangle &);
    Point &operator[](size_t);
    const Point &operator[](size_t) const;

    double getAire() const;
    bool estInterieur(Point &);

    bool estValide() const;
    bool estRectangle() const;
};

#endif