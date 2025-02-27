#include "forme2d.h"

#include <stdexcept>

#include "cartesien.h"

Forme2D::Forme2D(size_t nbPoints) {
    this->_nbPoints = nbPoints;
    this->_points = new Point[this->_nbPoints];
}

Forme2D::Forme2D(const Forme2D &forme2d) : Forme2D(forme2d._nbPoints) {
    for (size_t i = 0; i < this->_nbPoints; i++) {
        this->_points[i] = forme2d._points[i];
    }
}

Forme2D::~Forme2D() {
    if (this->_points == nullptr) {
        delete [] this->_points;
        this->_points = nullptr;
    }
}

Forme2D &Forme2D::operator=(const Forme2D &forme) {
    if (this == &forme) {
        return *this;
    }

    for (size_t i = 0; i < this->_nbPoints; i++) {
        this->_points[i] = forme._points[i];
    }

    return *this;
}

Point &Forme2D::operator[](size_t index) {
    if (index < this->_nbPoints) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

const Point &Forme2D::operator[](size_t index) const {
    if (index < this->_nbPoints) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

bool Forme2D::estValide() const {
    return this->getAire() != 0.0;
}

double Forme2D::getAire() const {

    double resultat = 0.0;

    for (size_t i = 0; i < this->_nbPoints; i++) {
        resultat += (*this)[i][0] * ((*this)[(i + 1) % this->_nbPoints][1] 
                    - (*this)[(i - 1) == MAX_SIZE_T ? this->_nbPoints - 1 : (i - 1)][1]);
    }

    resultat = abs(resultat);

    if (abs(resultat) < EPSILON) {
        return 0.0;
    }

    return 0.5 * resultat;
}

/* ========================================================================= */
/*     Méthodes privées                                                      */
/* ========================================================================= */

bool Forme2D::_checkPoint(const Point &point) {
    return point.getDimension() == 2;
}
