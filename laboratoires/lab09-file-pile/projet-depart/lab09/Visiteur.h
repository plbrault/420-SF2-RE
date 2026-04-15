//
// Created by braultpi on 2026-04-08.
//

#ifndef LAB09_VISITEUR_H
#define LAB09_VISITEUR_H

#include "Tube.h"

class Visiteur {
private:
    Tube* _tube;
public:
    void prendreTube(Tube* tube);
    Tube* retournerTube();
    bool aUnTube() const;
};


#endif //LAB09_VISITEUR_H