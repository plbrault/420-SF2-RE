#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <string>

#include "forme2d.h"
#include "point.h"

#define TRIANGLE_NB_POINT 3

class Triangle : public Forme2D {
private:

public:
    Triangle(): Forme2D() { }
    Triangle(const Triangle &);
    Triangle(const Point &, const Point &, const Point &);

    bool estInterieur(Point &);
    bool estRectangle() const;

    size_t getNbPoints() const;
};

#endif