#include "Solutionneur.h"
#include <cstdint>

using namespace std;

Solutionneur::Solutionneur(const vector<vector<int>>* carte) {
    _carte = carte;
    vector<int> nordOuest = { -1, -1 },
                nord = { -1, 0 },
                nordEst = { -1, 1 },
                est = { 0, 1 },
                sudEst = { 1, 1 },
                sud = { 1, 0 },
                sudOuest = { 1, -1 },
                ouest = { 0, -1 };
    _directions = { nordOuest, nord, nordEst, est, sudEst, sud, sudOuest, ouest };
}

int Solutionneur::_trouverSommet(const vector<int>& pos) {
    vector<int> nouvellePos;
    int altitudeSommet, altitudePlusHautSommet = (*_carte)[pos[0]][pos[1]];

    for (vector<int> direction : _directions) {
        nouvellePos = { pos[0] + direction[0], pos[1] + direction[1] };
        if (
            nouvellePos[0] >= 0
            && nouvellePos[0] < (int64_t)_carte->size()
            && nouvellePos[1] >= 0
            && nouvellePos[1] < (int64_t)(*_carte)[0].size()
            && (*_carte)[nouvellePos[0]][nouvellePos[1]] == 1 + (*_carte)[pos[0]][pos[1]]
            ) {
            altitudeSommet = _trouverSommet(nouvellePos);
            if (altitudeSommet > altitudePlusHautSommet) {
                altitudePlusHautSommet = altitudeSommet;
            }
        }
    }

    return altitudePlusHautSommet;
}

int Solutionneur::trouverPlusHautSommet() {
    int altitudeSommet, altitudePlusHautSommet = 0;

    for (int y = 0; y < _carte->size(); y++) {
        for (int x = 0; x < (*_carte)[0].size(); x++) {
            if ((*_carte)[y][x] == 0) {
                altitudeSommet = _trouverSommet({ y, x });
                if (altitudeSommet > altitudePlusHautSommet) {
                    altitudePlusHautSommet = altitudeSommet;
                }
            }
        }
    }

    return altitudePlusHautSommet;
}