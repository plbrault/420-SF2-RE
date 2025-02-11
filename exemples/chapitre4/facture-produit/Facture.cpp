#include "Facture.h"

Facture::Facture() {
    _nombreLignes = 0;
    _tailleTableau = 10;
    _lignes = new LigneFacture[_tailleTableau];
}

Facture::~Facture() {
    delete[] _lignes;
}

void Facture::agrandirTableau() {
    _tailleTableau *= 2;
    LigneFacture *nouveauTableau = new LigneFacture[_tailleTableau];

    for (int i = 0; i < _nombreLignes; i++) {
        nouveauTableau[i] = _lignes[i];
    }

    delete[] _lignes;
    _lignes = nouveauTableau;
}

int Facture::getNombreLignes() const {
    return _nombreLignes;
}

void Facture::ajouterLigne(const Produit &produit, int quantite) {
    if (_nombreLignes == _tailleTableau) {
        agrandirTableau();
    }

    _lignes[_nombreLignes] = LigneFacture(produit, quantite);
    _nombreLignes++;
}

LigneFacture Facture::getLigne(int index) const {
    return _lignes[index];
}

float Facture::getTotal() const {
    float total = 0.0;

    for (int i = 0; i < _nombreLignes; i++) {
        total += _lignes[i].getProduit().getPrix() * _lignes[i].getQuantite();
    }

    return total;
}
