#include "forme2d.h"

#include <stdexcept>

#include "cartesien.h"

Forme2D::Forme2D() { 
    this->_points = nullptr;
}

Forme2D::~Forme2D() {
    delete [] this->_points;
}

Forme2D &Forme2D::operator=(const Forme2D &forme2d) {
    if (this == &forme2d) {
        return *this;
    }

    if (this->getNbPoints() != forme2d.getNbPoints()){
        throw std::invalid_argument("Pas la même forme 2d.");
    }


    delete[] this->_points;
    this->_points = new Point[this->getNbPoints()];

    for (size_t i = 0; i < this->getNbPoints(); i++) {
        this->_points[i] = forme2d._points[i];
    }

    return *this;
}

Point &Forme2D::operator[](size_t index) {
    if (index < this->getNbPoints()) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

const Point &Forme2D::operator[](size_t index) const {
    if (index < this->getNbPoints()) {
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

    for (size_t i = 0; i < this->getNbPoints(); i++) {
        resultat += (*this)[i][0] * ((*this)[(i + 1) % this->getNbPoints()][1] 
                    - (*this)[(i - 1) == MAX_SIZE_T ? this->getNbPoints() - 1 : (i - 1)][1]);
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

void Forme2D::initialize() {
    this->_points = new Point[this->getNbPoints()];
}