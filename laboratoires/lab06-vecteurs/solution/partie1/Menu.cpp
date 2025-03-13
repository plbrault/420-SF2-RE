#include "Menu.h"

#include <sstream>

/** ===========================================================================
 * Constructeur(s) et destructeur
 * ========================================================================= */

Menu::Menu(const std::string &titre, const std::string &question, bool peutQuitter) {
    this->_titre = titre;
    this->_question = question;

    this->_peutQuitter = peutQuitter;
    this->_quantite = 0;

    this->_selection = -1;
}

Menu::Menu(const std::string &titre, const std::string &question) : Menu::Menu(titre, question, false) { }

/** ===========================================================================
 * Accesseur et mutateur
 * ========================================================================= */

std::string Menu::obtenirTitre(void) {
    return this->_titre;
}

int Menu::obtenirSelection(void) {
    return this->_selection;
}

std::string Menu::obtenirChaine(void) {
    std::ostringstream flux;

    flux << this->_titre << std::endl << std::endl;

    uint8_t i = 0;

    for (; i < this->_quantite; i++) {
        flux << (i + 1) << " " << this->_options[i] << std::endl;
    }

    if (this->_peutQuitter) {
        flux << (i + 1) << " Quitter" << std::endl << std::endl;
        i++;
    }

    flux << this->_question << " ";

    return flux.str();
}

std::string Menu::obtenirQuestion(void) {
    return this->_question;
}

void Menu::changerQuestion(const std::string &question) {
    this->_question = question;
}

/** ===========================================================================
 * Autres fonctions publiques
 * ========================================================================= */

bool Menu::ajouterOption(const std::string &option) {
    bool resultat = this->_quantite < TAILLE_LISTE_OPTION_MAXIMAL;

    if (resultat) {
        this->_options[this->_quantite] = option;
        this->_quantite++;
    }

    return resultat;
}

bool Menu::validerSelection(int index) {
    // On reçoit un index débuttant à 1 au lieu de 0
    index--;

    int qt = this->valeurMaximale();

    return index < qt;
}

int Menu::valeurMaximale(void) {
    int resultat = this->_quantite;

    if (this->_peutQuitter) {
        resultat++;
    }

    return resultat;
}

/** ===========================================================================
 * Méthodes privées
 * ========================================================================= */
