#ifndef __POINT_H
#define __POINT_H

#include <string>

class Point {
private:
    double *_coordonnee;
    size_t _nbDimensions;

public:
    Point();
    Point(size_t);
    Point(const Point &);
    ~Point();

    Point &operator=(const Point &);

    void setCoordonnee(size_t, double);

    double getCoordonnee(size_t) const;
    size_t getDimension() const;
    double getDistance(const Point &) const;
    std::string toString() const;
};

#endif
