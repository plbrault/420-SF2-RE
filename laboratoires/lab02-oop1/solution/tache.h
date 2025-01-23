#ifndef TACHE_H
#define TACHE_H

#include <string>

#define DESCRIPTION_CARACTERE_LIMITE 32

#include <string>

class Tache {
private:
    std::string _description;
    bool _fait;
public:
    Tache() : Tache("", false) { };
    Tache(std::string description, bool fait);

    void marquerFait();
    void demarquerFait();
    void changerDescription(const std::string &);
    std::string obtenirDescription();
    std::string obtenirChaine(int index);
};

#endif