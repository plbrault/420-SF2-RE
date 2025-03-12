#ifndef CHAT_H
#define CHAT_H

#include "Felin.h"

class Chat : public Felin {
public:
    Chat() : Felin(50, 10) {};
    void faireUnSon() override;
    void dormir() override; // On ajoute le mot-clé `override` seulement dans le .h
};

#endif // CHAT_H
