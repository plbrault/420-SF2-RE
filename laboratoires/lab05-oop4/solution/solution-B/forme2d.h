#ifndef __FORME2D_H
#define __FORME2D_H

#include "point.h"

class Forme2D {
private:
protected:
    Point *_points;

    bool _checkPoint(const Point &);

    void initialize();

public:
    Forme2D();
    Forme2D(const Forme2D &);
    virtual ~Forme2D();

    Forme2D &operator=(const Forme2D &);
    Point &operator[](size_t);
    const Point &operator[](size_t) const;

    double getAire() const;
    bool estValide() const;
    virtual size_t getNbPoints() const = 0;
};

#endif
