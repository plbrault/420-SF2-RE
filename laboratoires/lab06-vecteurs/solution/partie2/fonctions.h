#pragma once

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> split(const std::string& str, char delimiter);

int parcourir(const std::vector<std::vector<int>>& carte, const std::vector<int>& pos);

int trouverPlusHautSommet(const std::vector<std::vector<int>>& carte);
