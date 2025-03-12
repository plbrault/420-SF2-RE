#pragma once

class Felin {
protected:
    int _appetit;
    int _sommeil;

public:
    Felin() : Felin(0, 0) {}
    Felin(int appetit, int sommeil);
    void manger();
    virtual void dormir();
    virtual void faireUnSon() = 0; // On n'implémente pas cette méthode dans felin.cpp
};