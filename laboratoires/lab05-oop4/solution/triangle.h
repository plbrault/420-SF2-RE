#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <string>

#include "forme2d.h"
#include "point.h"

#define TRIANGLE_NB_POINT 3

class Triangle : public Forme2D {
private:

public:
    Triangle(): Forme2D(3) { }
    Triangle(const Point &, const Point &, const Point &);
    ~Triangle() { }

    bool estInterieur(Point &);
    bool estRectangle() const;
};

#endif