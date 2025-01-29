#ifndef TACHE_H
#define TACHE_H

#include <string>

#define DESCRIPTION_CARACTERE_LIMITE 32

#include <string>

class Tache {
private:
    std::string _description;
    bool _estCompletee;
    
public:
    Tache() : Tache("", false) { };
    Tache(std::string description, bool fait);

    void marquerCompletee();
    void marquerNonCompletee();
    bool estFait();

    void changerDescription(const std::string &);
    std::string obtenirDescription();

    std::string obtenirChaine(int indiceTache);
};

#endif