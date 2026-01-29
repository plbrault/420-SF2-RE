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

    return flux.str();
}
