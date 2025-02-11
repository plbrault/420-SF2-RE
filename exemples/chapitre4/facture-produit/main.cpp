#include <iostream>
#include "Facture.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Facture facture;

    Produit produit1("Bananes", 5.0);
    Produit produit2("Pommes", 3.0);

    facture.ajouterLigne(produit1, 2);
    facture.ajouterLigne(produit2, 3);

    for (int i = 0; i < facture.getNombreLignes(); i++) {
        LigneFacture ligne = facture.getLigne(i);
        ligne.afficher();
        cout << endl;
    }

    std::cout << "Total: " << facture.getTotal() << std::endl;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.