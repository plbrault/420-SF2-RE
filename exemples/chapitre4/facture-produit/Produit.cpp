#include "Produit.h"

Produit::Produit(std::string description, float prix) {
    _description = description;
    _prix = prix;
}

std::string Produit::getDescription() const {
    return _description;
}

void Produit::setDescription(std::string description) {
    _description = description;
}

float Produit::getPrix() const {
    return _prix;
}

void Produit::setPrix(float prix) {
    _prix = prix;
}
