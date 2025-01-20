#include "menu.h"

#include <sstream>

/** ===========================================================================
 * Constructeur(s) et destructeur
 * ========================================================================= */

Menu::Menu(const std::string &titre, const std::string &question, bool peutQuitter) {
    this->titre = titre;
    this->question = question;

    this->peutQuitter = peutQuitter;
    this->quantite = 0;

    this->selection = -1;
}

Menu::Menu(const std::string &titre, const std::string &question) : Menu::Menu(titre, question, false) { }

/** ===========================================================================
 * Accesseur et mutateur
 * ========================================================================= */

std::string Menu::obtenirTitre(void) {
    return this->titre;
}

int Menu::obtenirSelection(void) {
    return this->selection;
}

std::string Menu::obtenirChaine(void) {
    std::ostringstream flux;
    
    flux << this->titre << std::endl << std::endl;

    uint8_t i = 0;

    for (; i < this->quantite; i++) {
        flux << (i + 1) << " " << this->options[i] << std::endl;
    }

    if (peutQuitter) {
        flux << (i + 1) << " Quitter" << std::endl << std::endl;
        i++;
    }

    flux << this->question << " ";
    
    return flux.str();
}

void Menu::changerQuestion(const std::string &question) {
    this->question = question;
}

/** ===========================================================================
 * Autres fonctions publiques
 * ========================================================================= */

bool Menu::ajouterOption(const std::string &option) {
    bool resultat = this->quantite < TAILLE_LISTE_OPTION_MAXIMAL;

    if (resultat) {
        this->options[this->quantite] = option;
        this->quantite++;
    }
    
    return resultat;
}

bool Menu::validerSelection(int index) {
    // On reçoit un index débuttant à 1 au lieu de 0
    index--;

    quantite = this->quantite;

    // Une option de plus si on peut quitter
    if (peutQuitter) {
        quantite++;
    }

    return index < quantite;
}

/** ===========================================================================
 * Méthodes privées
 * ========================================================================= */
