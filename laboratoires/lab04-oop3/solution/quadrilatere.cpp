#include "quadrilatere.h"

#include <cmath>
#include <stdexcept>

#include "cartesien.h"

/* ========================================================================= */
/*     Constructeurs & Destructeur                                           */
/* ========================================================================= */

Quadrilatere::Quadrilatere() {
    Point temp(2);
    
    this->_points = new Point[QUADRILATERE_NB_POINT];
    for (size_t i = 0; i < QUADRILATERE_NB_POINT; i++) {
        this->_points[i] = temp;
    }
}

Quadrilatere::Quadrilatere(const Point &a, const Point &b, const Point &c, const Point &d) {
    Point temp(2);

    this->_points = new Point[QUADRILATERE_NB_POINT];

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

    if (d.getDimension() == 2) {
        this->_points[3] = d;
    } else {
        this->_points[3] = temp;
    }
}

Quadrilatere::Quadrilatere(const Quadrilatere &quadrilatere) {
    this->_points = new Point[QUADRILATERE_NB_POINT];

    for (size_t i = 0; i < QUADRILATERE_NB_POINT; i++) {
        this->_points[i] = quadrilatere._points[i];
    }
}

Quadrilatere::~Quadrilatere() {
    if (this->_points != nullptr) {
        delete [] this->_points;
    }
}

/* ========================================================================= */
/*     Surcharges d'opérateurs                                               */
/* ========================================================================= */

Quadrilatere &Quadrilatere::operator=(const Quadrilatere &quadrilatere) {
    if (this == &quadrilatere) {
        return *this;
    }

    for (size_t i = 0; i < QUADRILATERE_NB_POINT; i++) {
        this->_points[i] = quadrilatere._points[i];
    }

    return *this;
}

Point &Quadrilatere::operator[](size_t index) {
    if (index < QUADRILATERE_NB_POINT) {
        return this->_points[index];
    } else {
        throw std::out_of_range("Out of range");
    }
}

const Point &Quadrilatere::operator[](size_t index) const {
    if (index < QUADRILATERE_NB_POINT) {
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

bool Quadrilatere::estValide() const {
    return this->getAire() != 0.0;
}

double Quadrilatere::getAire() const {

    double resultat = 0.0;

    for (size_t i = 0; i < QUADRILATERE_NB_POINT; i++) {
        resultat += (*this)[i][0] * ((*this)[(i + 1) % QUADRILATERE_NB_POINT][1] 
                    - (*this)[(i - 1) == MAX_SIZE_T ? QUADRILATERE_NB_POINT - 1 : (i - 1)][1]);
    }

    resultat = abs(resultat);

    if (abs(resultat) < EPSILON) {
        return 0.0;
    }

    return 0.5 * resultat;
}
