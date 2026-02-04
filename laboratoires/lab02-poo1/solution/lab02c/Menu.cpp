//
// Created by plbrault on 2026-01-29.
//

#include <sstream>
#include "Menu.h"

Menu::Menu() {
    this->_options = nullptr;
    this->_nombreOptions = 0;
    this->_optionQuitter = false;
}

Menu::Menu(bool optionQuitter) : Menu() {
    this->_optionQuitter = optionQuitter;
}

Menu::~Menu() {
    delete[] this->_options;
}

void Menu::ajouterOption(std::string option) {
    std::string* ancienOptions = this->_options;
    this->_options = new std::string[this->_nombreOptions + 1];
    for (size_t i = 0; i < this->_nombreOptions; i++) {
        this->_options[i] = ancienOptions[i];
    }
    delete[] ancienOptions;

    this->_options[this->_nombreOptions] = option;
    this->_nombreOptions++;
}

std::string Menu::obtenirChaine() {
    std::stringstream flux;

    flux << "MENU" << std::endl << "====================" << std::endl;
    for (size_t i = 0; i < this->_nombreOptions; i++) {
        flux << (i + 1) << ". " << this->_options[i] << std::endl;
    }

    if (this->_optionQuitter) {
        flux << (_nombreOptions + 1) << ". " << "Quitter" << std::endl;
    }

    return flux.str();
}

int Menu::demanderChoix() {
    int choix;
    int max = this->_optionQuitter ? (this->_nombreOptions + 1) : this->_nombreOptions;
    do {
        std::cout << "Entrez un choix entre 1 et " << max << ": ";
        std::cin >> choix;

        if (choix < 1 || choix > max) {
            std::cout << "Votre choix est invalide." << std::endl;
        }
    } while (choix < 1 || choix > max);
    std::cout << std::endl;
    return choix;
}

bool Menu::estQuitter(int option) {
    return this->_optionQuitter && option == (this->_nombreOptions + 1);
}
