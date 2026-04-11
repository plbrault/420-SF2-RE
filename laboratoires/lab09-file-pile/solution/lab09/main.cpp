#include <iostream>
#include <list>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "fonctions.h"
#include "GlissadeEau.h"

int main()
{

    srand(time(nullptr));
    GlissadeEau glissade;
    std::list<Visiteur*> visiteurs;

    while (!touchePressee())
    {
        effacerEcran();
        std::cout << glissade;
        std::cout << "Appuyez sur n'importe quelle touche pour quitter." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        glissade.mettreAJour();
        if (rand() % 3 == 0)
        {
            visiteurs.push_back(new Visiteur());
            glissade.ajouterVisiteur(visiteurs.back());
        }
    }

    for (Visiteur* visiteur : visiteurs)
    {
        delete visiteur;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}