#pragma once

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(const std::string& str, char delimiter);

std::vector<std::vector<int>> parcourir(const std::vector<std::vector<int>>& carte, const std::vector<int>& pos);

std::vector<std::vector<int>> trouverChemin(const std::vector<std::vector<int>>& carte);

bool estDansChemin(const std::vector<int>& pos, const std::vector<std::vector<int>>& chemin);

void afficherChemin(std::ostream& out, const std::vector<std::vector<int>>& carte, const std::vector<std::vector<int>>& chemin);