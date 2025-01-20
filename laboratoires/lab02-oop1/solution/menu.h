#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <string>

#define TAILLE_LISTE_OPTION_MAXIMAL 18

class Menu {
private:

    bool peutQuitter;

    std::string titre;
    std::string question;
    std::string options[TAILLE_LISTE_OPTION_MAXIMAL];
    uint8_t quantite;

    int selection;

    bool aggrandirListeOptions(void);

public:

    Menu(const std::string &, const std::string &);

    Menu(const std::string &, const std::string &, bool);

    std::string obtenirChaine(void);

    std::string obtenirTitre(void);

    std::string obtenirQuestion(void);

    void changerQuestion(const std::string &);
    
    int obtenirSelection(void);

    bool validerSelection(int);

    bool ajouterOption(const std::string &); 

};

#endif