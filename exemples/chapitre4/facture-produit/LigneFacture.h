#pragma once

#include "Produit.h"

class LigneFacture {
private:
    Produit _produit;
    int _quantite;
public:
    LigneFacture(): LigneFacture(Produit(), 0) {};
    LigneFacture(const Produit& produit, int quantite);

    const Produit& getProduit() const;
    void setProduit(const Produit& produit);

    int getQuantite() const;
    void setQuantite(int quantite);

    void afficher() const;
};
