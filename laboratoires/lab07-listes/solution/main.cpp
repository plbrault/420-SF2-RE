#include <iostream>

#include <vector>
#include <list>
#include <fstream>
#include <array>


int main(int argc, char** argv) {
    int option = 0;
    if (argc == 2) {
        option = std::stoi(argv[1]);
    }

    std::vector<double> doubleVector;
    std::list<double> doubleList;

    std::ifstream inputFile("data.csv");
    std::string line;

    std::ifstream extraFile("data_to_add.csv");

    switch(option) {
        case 1:
            while (std::getline(inputFile, line)) {
                double value = std::stod(line);
                doubleVector.push_back(value);
            }
            break;
        case 2:
            while (std::getline(inputFile, line)) {
                double value = std::stod(line);
                doubleList.push_back(value);
            }
            break;
        case 3:
            while (std::getline(inputFile, line)) {
                double value = std::stod(line);
                doubleVector.push_back(value);
            }

            std::array<double, 100000> extraArray;
            for (int i = 0; i < 100000; i++) {
                double value;
                extraFile >> value;
                extraArray[i] = value;
            }

            for (size_t s = 0; s < extraArray.size(); s++) {
                size_t indexMax = 500000;
                doubleVector.push_back(doubleVector.back());
                for (size_t i = doubleVector.size() - 2; i >= indexMax; i--) {
                    doubleVector[i + 1] = doubleVector[i];
                }
                doubleVector[indexMax] = extraArray[s];
            }
        
            break;
        case 4:
            while (std::getline(inputFile, line)) {
                double value = std::stod(line);
                doubleList.push_back(value);
            }

            std::array<double, 100000> extraArray;
            for (int i = 0; i < 100000; i++) {
                double value;
                extraFile >> value;
                extraArray[i] = value;
            }

            for (size_t s = 0; s < extraArray.size(); s++) {
                size_t indexMax = 500000;
                doubleList.push_back(doubleList.back());
                for (size_t i = doubleList.size() - 2; i >= indexMax; i--) {
                    doubleList[i + 1] = doubleList[i];
                }
                doubleList[indexMax] = extraArray[s];
            }
            break;
        default:
            std::cerr << "No option specified" << std::endl;
            return 1;
    }


    return 0;
}
