#include "triangle.h"

#include <cmath>
#include <stdexcept>

#include "cartesien.h"

/* ========================================================================= */
/*     Constructeurs & Destructeur                                           */
/* ========================================================================= */

Triangle::Triangle(const Point &a, const Point &b, const Point &c) : Forme2D(TRIANGLE_NB_POINT) {
    if (this->_checkPoint(a) && this->_checkPoint(b) && this->_checkPoint(c)) {
        this->_points[0] = a;
        this->_points[1] = b;
        this->_points[2] = c;
    } else {
        throw std::invalid_argument("Points doivent être en 2 dimensions");
    }
}

/* ========================================================================= */
/*     Surcharges d'opérateurs                                               */
/* ========================================================================= */

/* ========================================================================= */
/*     Accesseurs et mutateurs                                               */
/* ========================================================================= */

/* ========================================================================= */
/*     Méthodes                                                              */
/* ========================================================================= */

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
/*     Méthodes virtuelles                                                   */
/* ========================================================================= */

size_t Triangle::getNombrePointRequis() const {
    return TRIANGLE_NB_POINT;
}