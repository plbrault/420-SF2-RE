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

    Point &operator+=(const Point &);
    Point &operator-=(const Point &);
    const Point operator+(const Point &);
    const Point operator-(const Point &);

    double operator*(Point &);
    double &operator[](size_t);
    const double &operator[](size_t) const;

    int testConstant() const;
    size_t getDimension() const;
    double getDistance(const Point &) const;
    std::string toString() const;

    friend std::ostream &operator<<(std::ostream&, const Point &);
};

#endif
