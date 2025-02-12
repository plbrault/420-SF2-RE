#ifndef __QUADRILATERE_H
#define __QUADRILATERE_H

#include <string>

#include "point.h"

#define QUADRILATERE_NB_POINT 4

class Quadrilatere {
private:
    Point *_points;

public:
    Quadrilatere();
    Quadrilatere(const Point &, const Point &, const Point &, const Point &);
    Quadrilatere(const Quadrilatere &);
    ~Quadrilatere();

    Quadrilatere &operator=(const Quadrilatere &);
    Point &operator[](size_t);
    const Point &operator[](size_t) const;

    double getAire() const;
    bool estInterieur(const Point &) const;

    bool estValide() const;
};

#endif
