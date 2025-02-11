#pragma once

#include "Produit.h"

class LigneFacture {
private:
    Produit _produit;
    int _quantite;
public:
    LigneFacture(): LigneFacture(Produit(), 0) {};
    LigneFacture(Produit produit, int quantite);

    Produit getProduit() const;
    void setProduit(Produit produit);

    int getQuantite() const;
    void setQuantite(int quantite);

    void afficher() const;
};
