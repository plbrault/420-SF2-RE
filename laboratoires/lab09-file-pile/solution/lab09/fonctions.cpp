#include "fonctions.h"
#include <cstdlib>
#include <iostream>

void effacerEcran()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}
