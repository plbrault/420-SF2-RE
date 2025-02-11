#include <iostream>
#include "Facture.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Produit produit1, produit2;
    Facture facture;

    produit1.setDescription("Hamburger");
    produit1.setPrix(5.99);

    produit2.setDescription("Hot dog");
    produit2.setPrix(3.99);

    facture.ajouterLigne(produit1, 2);
    facture.ajouterLigne(produit2, 3);

    for (int i = 0; i < facture.getNombreLignes(); i++) {
        facture.getLigne(i).afficher();
        cout << endl;
    }
    cout << "TOTAL: " << facture.getTotal();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.