#include "fonctions.h"

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    string current;
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(current);
            current.clear();
        }
        else {
            current += c;
        }
    }
    result.push_back(current);
    return result;
}

int parcourir(const vector<vector<int>>& carte, const vector<int>& pos) {
    vector<int> nouvellePos;
    int altitudeSommet, altitudePlusHautSommet = carte[pos[0]][pos[1]];

    vector<int> nordOuest = { -1, -1 },
                nord = { -1, 0 },
                nordEst = { -1, 1 },
                est = { 0, 1 },
                sudEst = { 1, 1 },
                sud = { 1, 0 },
                sudOuest = { 1, -1 },
                ouest = { 0, -1 };
    vector<vector<int>> directions = { nordOuest, nord, nordEst, est, sudEst, sud, sudOuest, ouest };

    for (vector<int> direction : directions) {
        nouvellePos = { pos[0] + direction[0], pos[1] + direction[1] };
        if (
            nouvellePos[0] >= 0
            && nouvellePos[0] < carte.size()
            && nouvellePos[1] >= 0
            && nouvellePos[1] < carte[0].size()
            && carte[nouvellePos[0]][nouvellePos[1]] == 1 + carte[pos[0]][pos[1]]
        ) {
            altitudeSommet = parcourir(carte, nouvellePos);
            if (altitudeSommet > altitudePlusHautSommet) {
				altitudePlusHautSommet = altitudeSommet;
			}
		}
    }

    return altitudePlusHautSommet;
}

int trouverPlusHautSommet(const vector<vector<int>>& carte) {
    int altitudeSommet, altitudePlusHautSommet = 0;
    
    for (int y = 0; y < carte.size(); y++) {
        for (int x = 0; x < carte[0].size(); x++) {
            if (carte[y][x] == 0) {
				altitudeSommet = parcourir(carte, { y, x });
                if (altitudeSommet > altitudePlusHautSommet) {
					altitudePlusHautSommet = altitudeSommet;
                }
			}
		}
    }

    return altitudePlusHautSommet;
}
