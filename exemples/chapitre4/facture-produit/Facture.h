#pragma once

#include "LigneFacture.h"

class Facture {
private:
    LigneFacture *_lignes;
    int _nombreLignes;
    int _tailleTableau;

    void _agrandirTableau();
public:
    Facture();
    ~Facture();

    int getNombreLignes() const;
    void ajouterLigne(const Produit &produit, int quantite);
    const LigneFacture& getLigne(int index) const;
    float getTotal() const;
};