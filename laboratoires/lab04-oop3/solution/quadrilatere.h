#ifndef __QUADRILATERE_H
#define __QUADRILATERE_H

#include <string>

#include "point.h"

class Quadrilatere {
private:
    Point *_points;

public:
    Quadrilatere();
    Quadrilatere(const Point &, const Point &, const Point &, const Point &);
    Quadrilatere(const Quadrilatere &);
    ~Quadrilatere();

    Quadrilatere &operator=(const Quadrilatere &);

    double getAire() const;
    bool estInterieur(const Point &) const;

    bool estValide() const;
    bool estRectangle() const;
};

#endif

