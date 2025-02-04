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
    double resultat = abs(
        this->_points[0].getCoordonnee(0) * (this->_points[1].getCoordonnee(1) - this->_points[2].getCoordonnee(1)) + 
        this->_points[1].getCoordonnee(0) * (this->_points[2].getCoordonnee(1) - this->_points[0].getCoordonnee(1)) + 
        this->_points[2].getCoordonnee(0) * (this->_points[0].getCoordonnee(1) - this->_points[1].getCoordonnee(1))
    );

    if (abs(resultat) < EPSILON) {
        return 0.0;
    }

    return 0.5 * resultat;
}

bool Triangle::estInterieur(const Point &point) const {    
    if (!this->estValide()) {
        return false;
    }

    double c0 = (this->_points[1].getCoordonnee(0) - this->_points[0].getCoordonnee(0)) 
                * (point.getCoordonnee(1) - this->_points[0].getCoordonnee(1)) 
                - (this->_points[1].getCoordonnee(1) - this->_points[0].getCoordonnee(1)) 
                * (point.getCoordonnee(0) - this->_points[0].getCoordonnee(0));
    double c1 = (this->_points[2].getCoordonnee(0) - this->_points[1].getCoordonnee(0)) 
                * (point.getCoordonnee(1) - this->_points[1].getCoordonnee(1)) 
                - (this->_points[2].getCoordonnee(1) - this->_points[1].getCoordonnee(1)) 
                * (point.getCoordonnee(0) - this->_points[1].getCoordonnee(0));
    double c2 = (this->_points[0].getCoordonnee(0) - this->_points[2].getCoordonnee(0)) 
                * (point.getCoordonnee(1) - this->_points[2].getCoordonnee(1)) 
                - (this->_points[0].getCoordonnee(1) - this->_points[2].getCoordonnee(1)) 
                * (point.getCoordonnee(0) - this->_points[2].getCoordonnee(0));

    return ((c0 > 0.0 && c1 > 0.0 && c2 > 0.0) || (c0 < 0.0 && c1 < 0.0 && c2 < 0.0));
}


bool Triangle::estRectangle() const {
    if (!this->estValide()) {
        return false;
    }

    double vAC = (this->_points[1].getCoordonnee(0) - this->_points[0].getCoordonnee(0)) 
                    * (this->_points[0].getCoordonnee(0) - this->_points[2].getCoordonnee(0)) 
                    + (this->_points[1].getCoordonnee(1) - this->_points[0].getCoordonnee(1)) 
                    * (this->_points[0].getCoordonnee(1) - this->_points[2].getCoordonnee(1));
    double vAB = (this->_points[1].getCoordonnee(0) - this->_points[0].getCoordonnee(0)) 
                    * (this->_points[2].getCoordonnee(0) - this->_points[1].getCoordonnee(0)) 
                    + (this->_points[1].getCoordonnee(1) - this->_points[0].getCoordonnee(1)) 
                    * (this->_points[2].getCoordonnee(1) - this->_points[1].getCoordonnee(1));
    double vBC = (this->_points[2].getCoordonnee(0) - this->_points[1].getCoordonnee(0)) 
                    * (this->_points[0].getCoordonnee(0) - this->_points[2].getCoordonnee(0)) 
                    + (this->_points[2].getCoordonnee(1) - this->_points[1].getCoordonnee(1)) 
                    * (this->_points[0].getCoordonnee(1) - this->_points[2].getCoordonnee(1));

    return (abs(vAC) <= EPSILON || abs(vAB) <= EPSILON || abs(vBC) <= EPSILON);
}