#include "Simulateur.h"
#include <fstream>

const unsigned long DUREE_JOURNEE = 28800;
const int VITESSE_MAX = 1000;

int main() {
    std::ifstream fichierConfig("../configuration.json");
    Simulateur(fichierConfig).simuler();
    return 0;
}
