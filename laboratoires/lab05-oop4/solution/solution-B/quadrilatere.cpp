#include "quadrilatere.h"

#include <cmath>
#include <stdexcept>

#include "cartesien.h"

/* ========================================================================= */
/*     Constructeurs & Destructeur                                           */
/* ========================================================================= */

Quadrilatere::Quadrilatere(const Point &a, const Point &b, const Point &c, const Point &d) : Forme2D() {
    this->initialize();

    if (this->_checkPoint(a) && this->_checkPoint(b) && this->_checkPoint(c) && this->_checkPoint(d)) {
        this->_points[0] = a;
        this->_points[1] = b;
        this->_points[2] = c;
        this->_points[3] = d;
    } else {
        throw std::invalid_argument("Tous les points doivent être en 2 dimensions");
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
size_t Quadrilatere::getNbPoints() const {
    return QUADRILATERE_NB_POINT;
}