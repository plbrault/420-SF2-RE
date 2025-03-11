#ifndef __FORME2D_H
#define __FORME2D_H

#include "point.h"

class Forme2D {
private:
protected:
    Point *_points;

    bool _checkPoint(const Point &);

public:
    Forme2D(size_t);
    Forme2D(const Forme2D &);
    ~Forme2D();

    Forme2D &operator=(const Forme2D &);
    Point &operator[](size_t);
    const Point &operator[](size_t) const;

    double getAire() const;
    bool estValide() const;

    virtual size_t getNombrePointRequis() const = 0;
};

#endif