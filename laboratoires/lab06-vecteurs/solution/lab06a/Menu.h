#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <string>

#define TAILLE_LISTE_OPTION_MAXIMAL 18

class Menu {
private:

    bool _peutQuitter;

    std::string _titre;
    std::string _question;
    std::string _options[TAILLE_LISTE_OPTION_MAXIMAL];
    uint8_t _quantite;

public:

    Menu(const std::string &, const std::string &);

    Menu(const std::string &, const std::string &, bool);

    std::string obtenirChaine(void);

    std::string obtenirTitre(void);

    std::string obtenirQuestion(void);

    void changerQuestion(const std::string &);

    bool validerSelection(int);

    int valeurMaximale(void);

    bool ajouterOption(const std::string &);

};

#endif