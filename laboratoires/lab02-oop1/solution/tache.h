#ifndef TACHE_H
#define TACHE_H

#include <string>

class Tache {
private:

    std::string description;
    bool fait;

public:

    Tache(void);

    Tache(std::string &);

    std::string obtenirDescription(void);

    void donnerDescription(std::string &);

    bool estFait(void);

    void marquerFait(void);

    void marquerNonFait(void);

    std::string obtenirChaine(int);

};

#endif