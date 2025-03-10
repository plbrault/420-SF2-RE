#ifndef __QUADRILATERE_H
#define __QUADRILATERE_H

#include <string>

#include "forme2d.h"
#include "point.h"

#define QUADRILATERE_NB_POINT 4

class Quadrilatere : public Forme2D {
private:

public:
    Quadrilatere(): Forme2D() { }
    Quadrilatere(const Point &, const Point &, const Point &, const Point &);
    ~Quadrilatere() { }

    size_t getNbPoints() const;
};

#endif
