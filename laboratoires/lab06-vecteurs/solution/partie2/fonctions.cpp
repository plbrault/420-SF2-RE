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

vector<vector<int>> parcourir(const vector<vector<int>>& carte, const vector<int>& pos) {
    vector<vector<int>> chemin = { pos }, cheminPossible, plusHautSommet;
    vector<int> nouvellePos;

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
            cheminPossible = parcourir(carte, nouvellePos);
            if (plusHautSommet.empty()) {
				plusHautSommet = cheminPossible;
			}
            else if (
                carte[cheminPossible.back()[0]][cheminPossible.back()[1]]
                > carte[plusHautSommet.back()[0]][plusHautSommet.back()[1]]
            ) {
                plusHautSommet = cheminPossible;
            }
		}
    }

    chemin.insert(chemin.end(), plusHautSommet.begin(), plusHautSommet.end());
    return chemin;
}

vector<vector<int>> trouverChemin(const vector<vector<int>>& carte) {
    vector<vector<int>> cheminPossible, plusHautSommet;

    for (int y = 0; y < carte.size(); y++) {
        for (int x = 0; x < carte[y].size(); x++) {
            if (carte[y][x] == 0) {
                cheminPossible = parcourir(carte, { y, x });
                if (plusHautSommet.empty()) {
                    plusHautSommet = cheminPossible;
                }
                else if (
                    carte[cheminPossible.back()[0]][cheminPossible.back()[1]]
                    > carte[plusHautSommet.back()[0]][plusHautSommet.back()[1]]
                ) {
					plusHautSommet = cheminPossible;
				}
            }
        }
    }

    return plusHautSommet;
}

bool estDansChemin(const vector<int>& pos, const vector<vector<int>>& chemin) {
    for (vector<int> position : chemin) {
        if (pos == position) {
			return true;
		}
	}
	return false;
}

void afficherChemin(ostream& out, const vector<vector<int>>& carte, const vector<vector<int>>& chemin) {
    for (int y = 0; y < carte.size(); y++) {
        for (int x = 0; x < carte[y].size(); x++) {
            if (estDansChemin({ y, x }, chemin)) {
                out << "(" << carte[y][x] << ") ";
			}
            else {
				out << carte[y][x]<< " ";
			}
		}
		out << endl;
	}
}