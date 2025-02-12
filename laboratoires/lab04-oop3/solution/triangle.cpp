#include "triangle.h"

#include <cmath>
#include <stdexcept>

#include "cartesien.h"

/* ========================================================================= */
/*     Constructeurs & Destructeur                                           */
/* ========================================================================= */

Triangle::Triangle() {
    this->_points = new Point[TRIANGLE_NB_POINT];
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c) {
    this->_points = new Point[TRIANGLE_NB_POINT];

    if (this->_checkPoint(a) && this->_checkPoint(b) && this->_checkPoint(c)) {
        this->_points[0] = a;
        this->_points[1] = b;
        this->_points[2] = c;
    } else {
        throw std::invalid_argument("Points doivent être en 2 dimensions");
    }
}

Triangle::Triangle(const Triangle &triangle) {
    for (size_t i = 0; i < TRIANGLE_NB_POINT; i++) {
        this->_points[i] = triangle._points[i];
    }
}

Triangle::~Triangle() {
    if (this->_points != nullptr) {
        delete [] this->_points;
    }
}

/* ========================================================================= */
/*     Surcharges d'opérateurs                                               */
/* ========================================================================= */

Triangle &Triangle::operator=(const Triangle &triangle) {
    if (this == &triangle) {
        return *this;
    }

    for (size_t i = 0; i < TRIANGLE_NB_POINT; i++) {
        this->_points[i] = triangle._points[i];
    }

    return *this;
}

Point &Triangle::operator[](size_t index) {
    if (index < TRIANGLE_NB_POINT) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

const Point &Triangle::operator[](size_t index) const {
    if (index < TRIANGLE_NB_POINT) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

/* ========================================================================= */
/*     Accesseurs et mutateurs                                               */
/* ========================================================================= */

/* ========================================================================= */
/*     Méthodes                                                              */
/* ========================================================================= */

bool Triangle::estValide() const {
    return this->getAire() != 0.0;
}

double Triangle::getAire() const {

    double resultat = 0.0;

    for (size_t i = 0; i < TRIANGLE_NB_POINT; i++) {
        resultat += (*this)[i][0] * ((*this)[(i + 1) % TRIANGLE_NB_POINT][1] 
                    - (*this)[(i - 1) == MAX_SIZE_T ? TRIANGLE_NB_POINT - 1 : (i - 1)][1]);
    }

    resultat = abs(resultat);

    if (abs(resultat) < EPSILON) {
        return 0.0;
    }

    return 0.5 * resultat;
}

bool Triangle::estInterieur(Point &point) {    
    if (!this->estValide()) {
        return false;
    }

    double c0 = ((*this)[1][0] - (*this)[0][0]) 
                * (point[1] - (*this)[0][1]) 
                - ((*this)[1][1] - (*this)[0][1]) 
                * (point[0] - (*this)[0][0]);
    double c1 = ((*this)[2][0] - (*this)[1][0]) 
                * (point[1] - (*this)[1][1]) 
                - ((*this)[2][1] - (*this)[1][1]) 
                * (point[0] - (*this)[1][0]);
    double c2 = ((*this)[0][0] - (*this)[2][0]) 
                * (point[1] - (*this)[2][1]) 
                - ((*this)[0][1] - (*this)[2][1]) 
                * (point[0] - (*this)[2][0]);

    return ((c0 > 0.0 && c1 > 0.0 && c2 > 0.0) || (c0 < 0.0 && c1 < 0.0 && c2 < 0.0));
}

bool Triangle::estRectangle() const {
    if (!this->estValide()) {
        return false;
    }

    double vAC = ((*this)[1][0] - (*this)[0][0]) * ((*this)[0][0] - (*this)[2][0]) 
                    + ((*this)[1][1] - (*this)[0][1]) * ((*this)[0][1] - (*this)[2][1]);
    double vAB = ((*this)[1][0] - (*this)[0][0]) * ((*this)[2][0] - (*this)[1][0]) 
                    + ((*this)[1][1] - (*this)[0][1]) * ((*this)[2][1] - (*this)[1][1]);
    double vBC = ((*this)[2][0] - (*this)[1][0]) * ((*this)[0][0] - (*this)[2][0]) 
                    + ((*this)[2][1] - (*this)[1][1]) * ((*this)[0][1] - (*this)[2][1]);

    return (abs(vAC) <= EPSILON || abs(vAB) <= EPSILON || abs(vBC) <= EPSILON);
}

/* ========================================================================= */
/*     Méthodes privées                                                      */
/* ========================================================================= */

bool Triangle::_checkPoint(const Point &point) {
    return point.getDimension() == 2;
}