#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <string>

#define TAILLE_LISTE_OPTION_INCREMENT 6
#define TAILLE_LISTE_OPTION_MAXIMAL 18

class Menu {
private:

    bool peutQuitter;

    std::string titre;
    std::string question;
    std::string *options;
    uint8_t taille;
    uint8_t quantite;

    int selection;

    bool aggrandirListeOptions(void);

public:

    Menu(const std::string &, const std::string &);

    Menu(const std::string &, const std::string &, bool);

    ~Menu(void);

    std::string obtenirChaine(void);

    std::string obtenirTitre(void);

    std::string obtenirQuestion(void);

    void changerQuestion(const std::string &);
    
    int obtenirSelection(void);

    bool validerSelection(int);

    void ajouterOption(const std::string &); 

};

#endif