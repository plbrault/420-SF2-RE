#include "triangle.h"

#include <cmath>

#include "cartesien.h"

Triangle::Triangle() {
    Point temp(2);
    
    this->_points = new Point[3];
    for (size_t i = 0; i < 3; i++) {
        this->_points[i] = temp;
    }
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c) {
    Point temp(2);

    this->_points = new Point[3];

    if (a.getDimension() == 2) {
        this->_points[0] = a;
    } else {
        this->_points[0] = temp;
    }

    if (b.getDimension() == 2) {
        this->_points[1] = b;
    } else {
        this->_points[1] = temp;
    }

    if (c.getDimension() == 2) {
        this->_points[2] = c;
    } else {
        this->_points[2] = temp;
    }
}

Triangle::Triangle(const Triangle &triangle) {
    for (size_t i = 0; i < 3; i++) {
        this->_points[i] = triangle._points[i];
    }
}

Triangle::~Triangle() {
    if (this->_points != nullptr) {
        delete [] this->_points;
    }
}

bool Triangle::estValide() const {
    return this->getAire() != 0.0;
}

double Triangle::getAire() const {
    double x00 = this->_points[0].getCoordonnee(0);
    double x10 = this->_points[1].getCoordonnee(0);
    double x20 = this->_points[2].getCoordonnee(0);

    double x01 = this->_points[0].getCoordonnee(1);
    double x11 = this->_points[1].getCoordonnee(1);
    double x21 = this->_points[2].getCoordonnee(1);

    double resultat = abs(x00 * (x11 - x21) + x10 * (x21 - x01) + x20 * (x01 - x11));
    if (resultat < EPSILON) {
        return 0.0;
    }

    return 0.5 * resultat;
}

bool Triangle::estInterieur(const Point &point) const {    
    if (!this->estValide()) {
        return false;
    }
    
    double x00 = this->_points[0].getCoordonnee(0);
    double x10 = this->_points[1].getCoordonnee(0);
    double x20 = this->_points[2].getCoordonnee(0);

    double x01 = this->_points[0].getCoordonnee(1);
    double x11 = this->_points[1].getCoordonnee(1);
    double x21 = this->_points[2].getCoordonnee(1);

    double x0 = point.getCoordonnee(0);
    double x1 = point.getCoordonnee(1);

    double c0 = (x10 - x00) * (x1 - x01) - (x11 - x01) * (x0 - x00);
    double c1 = (x20 - x10) * (x1 - x11) - (x21 - x11) * (x0 - x10);
    double c2 = (x00 - x20) * (x1 - x21) - (x01 - x21) * (x0 - x20);

    return ((c0 > 0.0 && c1 > 0.0 && c2 > 0.0) || (c0 < 0.0 && c1 < 0.0 && c2 < 0.0));
}


bool Triangle::estRectangle() const {
    if (!this->estValide()) {
        return false;
    }

    double x00 = this->_points[0].getCoordonnee(0);
    double x10 = this->_points[1].getCoordonnee(0);
    double x20 = this->_points[2].getCoordonnee(0);

    double x01 = this->_points[0].getCoordonnee(1);
    double x11 = this->_points[1].getCoordonnee(1);
    double x21 = this->_points[2].getCoordonnee(1);

    double vAC = (x10 - x00) * (x00 - x20) + (x11 - x01) * (x01 - x21);
    double vAB = (x10 - x00) * (x20 - x10) + (x11 - x01) * (x21 - x11);
    double vBC = (x20 - x10) * (x00 - x20) + (x21 - x11) * (x01 - x21);

    return (abs(vAC) <= EPSILON || abs(vAB) <= EPSILON || abs(vBC) <= EPSILON);
}