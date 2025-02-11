#include "point.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

/* ========================================================================= */
/*     Constructeurs & Destructeur                                           */
/* ========================================================================= */

Point::Point() : Point(2) { } 

Point::Point(size_t nbDimension) {
    this->_nbDimensions = nbDimension;
    if (this->_nbDimensions > 1) {
        this->_coordonnee = new double[this->_nbDimensions];
        
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            (*this)[i] = 0.0;
        }
    }
}

Point::Point(const Point &point) {
    this->_nbDimensions = point._nbDimensions;
    this->_coordonnee = new double[this->_nbDimensions];

    for (size_t i = 0; i < this->_nbDimensions; i++) {
        (*this)[i] = point._coordonnee[i];
    }
}

Point::~Point() {
    if (this->_coordonnee != nullptr) {
        delete [] this->_coordonnee;
    }
}

/* ========================================================================= */
/*     Surcharges d'opérateurs                                               */
/* ========================================================================= */

Point &Point::operator=(const Point &point) {
    if (this == &point) {
        return *this;
    }

    if (this->_nbDimensions == point._nbDimensions) {
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            (*this)[i] = point[i];
        }
    } else {
        delete [] this->_coordonnee;
        
        this->_nbDimensions = point._nbDimensions;
        this->_coordonnee = new double[this->_nbDimensions];

        for (size_t i = 0; i < this->_nbDimensions; i++) {
            (*this)[i] = point[i];
        }
    }

    return *this;
}

Point &Point::operator+=(const Point &point) {
    if (this->_nbDimensions == point._nbDimensions) {
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            (*this)[i] += point[i];
        }
    }

    return *this;
}

Point &Point::operator-=(const Point &point) {
    if (this->_nbDimensions == point._nbDimensions) {
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            (*this)[i] -= point[i];
        }
    }

    return *this;
}

const Point Point::operator+(const Point &point) {
    Point resultat = *this;
    resultat += point;
    return resultat;
}

const Point Point::operator-(const Point &point) {
    Point resultat = *this;
    resultat -= point;
    return resultat;
}

double Point::operator*(Point &point) {
    double resultat = 0.0;

    for (size_t i = 0; i < this->_nbDimensions; i++) {
        resultat += ((*this)[i] * point[i]);
    }

    return resultat;
}

double &Point::operator[](size_t index) {
    if (index < this->_nbDimensions) {
        return this->_coordonnee[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

const double &Point::operator[](size_t index) const {
    if (index < this->_nbDimensions) {
        return this->_coordonnee[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

/* ========================================================================= */
/*     Accesseurs et mutateurs                                               */
/* ========================================================================= */

int Point::testConstant() const {
    int a = (int)(*this)[0];
    return a;
}

size_t Point::getDimension() const {
    return this->_nbDimensions;
}

double Point::getDistance(const Point &point) const {
    if (this->_nbDimensions == point._nbDimensions) {
        double resultat = 0.0;

        for (size_t i = 0; i < this->_nbDimensions; i++) {
            resultat += pow(point[i] - (*this)[i], 2);
        }

        resultat = sqrt(resultat);

        return resultat;
    } else {
        return NAN;
    }
}

std::string Point::toString() const {
    std::stringstream flux;

    flux << "(";

    for (size_t i = 0; i < this->_nbDimensions; i++) {
        flux << this->_coordonnee[i];
        if (i != this->_nbDimensions - 1) {
            flux << ", ";
        }
    }

    flux << ")";

    return flux.str();
}

/* ========================================================================= */
/*     Fonctions amies                                                       */
/* ========================================================================= */

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.toString();

    return os;
}
