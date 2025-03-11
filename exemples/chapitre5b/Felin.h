#pragma once

class Felin {
protected:
    int _appetit;
    int _sommeil;

public:
    Felin() : Felin(0, 0) {}
    Felin(int appetit, int sommeil);
    void manger();
    void dormir();
    virtual void faireUnSon() = 0;
};