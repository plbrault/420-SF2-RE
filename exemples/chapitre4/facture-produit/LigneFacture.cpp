#include <iostream>
#include "LigneFacture.h"

using namespace std;

LigneFacture::LigneFacture(Produit produit, int quantite) {
    _produit = produit;
    _quantite = quantite;
}

Produit LigneFacture::getProduit() const {
    return _produit;
}

void LigneFacture::setProduit(Produit produit) {
    _produit = produit;
}

int LigneFacture::getQuantite() const {
    return _quantite;
}

void LigneFacture::setQuantite(int quantite) {
    _quantite = quantite;
}

void LigneFacture::afficher() const {
    cout << _produit.getDescription() << " x " << _quantite << " = " << _produit.getPrix();
}