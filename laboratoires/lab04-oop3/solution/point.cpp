#include "point.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

Point::Point() : Point(2) { } 

Point::Point(size_t nbDimension) {
    this->_nbDimensions = nbDimension;
    if (this->_nbDimensions > 1) {
        this->_coordonnee = new double[this->_nbDimensions];
        
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            this->_coordonnee[i] = 0.0;
        }
    }
}

Point::Point(const Point &point) {
    this->_nbDimensions = point._nbDimensions;
    this->_coordonnee = new double[this->_nbDimensions];

    for (size_t i = 0; i < this->_nbDimensions; i++) {
        this->_coordonnee[i] = point._coordonnee[i];
    }
}

Point::~Point() {
    if (this->_coordonnee != nullptr) {
        delete [] this->_coordonnee;
    }
}

Point &Point::operator=(const Point &point) {
    if (this == &point) {
        return *this;
    }

    if (this->_nbDimensions == point._nbDimensions) {
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            this->_coordonnee[i] = point._coordonnee[i];
        }
    } else {
        delete [] this->_coordonnee;
        
        this->_nbDimensions = point._nbDimensions;
        this->_coordonnee = new double[this->_nbDimensions];

        for (size_t i = 0; i < this->_nbDimensions; i++) {
            this->_coordonnee[i] = point._coordonnee[i];
        }
    }

    return *this;
}

void Point::setCoordonnee(size_t dimension, double valeur) {
    if (dimension < this->_nbDimensions) {
        this->_coordonnee[dimension] = valeur;
    }
}

double Point::getCoordonnee(size_t dimension) const {
    if (dimension < this->_nbDimensions) {
        return this->_coordonnee[dimension];
    } else {
        return NAN;
    }
}

size_t Point::getDimension() const {
    return this->_nbDimensions;
}

double Point::getDistance(const Point &point) const {
    if (this->_nbDimensions == point._nbDimensions) {
        double resultat = 0.0;

        for (size_t i = 0; i < this->_nbDimensions; i++) {
            resultat += pow(point._coordonnee[i] - this->_coordonnee[i], 2);
        }

        resultat = sqrt(resultat);

        return resultat;
    } else {
        return NAN;
    }
}

Point &Point::operator+=(const Point &point) {
    if (this->_nbDimensions == point._nbDimensions) {
        for (size_t i = 0; i < this->_nbDimensions; i++) {
            this->_coordonnee[i] += point._coordonnee[i];
        }
    }

    return *this;
}

const Point Point::operator+(const Point &point) {
    Point resultat = *this;
    resultat += point;
    return resultat;
}

double &Point::operator[](size_t index) {
    if (index <= this->_nbDimensions) {
        return this->_coordonnee[index];
    } else {
        throw std::out_of_range("Out of range");
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

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.toString();

    return os;
}
