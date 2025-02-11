#pragma once

#include <string>

class Produit {
private:
    std::string _description;
    float _prix;
public:
    Produit(): Produit("", 0.0) {};
    Produit(const std::string &description, float prix);

    std::string getDescription() const;
    void setDescription(const std::string &description);

    float getPrix() const;
    void setPrix(float prix);
};