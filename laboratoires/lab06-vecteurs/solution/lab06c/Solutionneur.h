#pragma once

#include <vector>

class Solutionneur {
private:
    const std::vector<std::vector<int>> *_carte;
    std::vector<std::vector<int>> _directions;

    int _trouverSommet(const std::vector<int>& pos);
public:
    Solutionneur(const std::vector<std::vector<int>>* carte);
    int trouverPlusHautSommet();
};