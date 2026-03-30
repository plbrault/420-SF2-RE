#ifndef LAB01C_MENU_H
#define LAB01C_MENU_H

#include <iostream>

class Menu {
private:
    std::string* _options;
    size_t _nombreOptions;
    bool _optionQuitter;
public:
    Menu();
    Menu(bool optionQuitter);
    Menu(const Menu& autreMenu);
    ~Menu();
    Menu& operator=(const Menu& autreMenu);

    void ajouterOption(std::string option);
    std::string obtenirChaine();
    int demanderChoix();
    bool estQuitter(int idOption);
};


#endif //LAB01C_MENU_H