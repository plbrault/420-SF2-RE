#include <iostream>
#include <thread>
#include <chrono>
#include "fonctions.h"
#include "GlissadeEau.h"

int main()
{
    GlissadeEau glissade;

    while (true)
    {
        std::cout << glissade;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        effacerEcran();
        glissade.mettreAJour(Duration(1));
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}