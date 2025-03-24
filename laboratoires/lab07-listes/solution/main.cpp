#include <iostream>

#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <array>
#include <chrono>


void loadData(const std::string &path, std::vector<double> &vec, size_t size) {
    std::chrono::_V2::system_clock::time_point start, end;
    int64_t duration;
    
    std::cout << "Loading data in memory..." << std::endl;
    start = std::chrono::high_resolution_clock::now();
    std::ifstream file(path);
    std::string content { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
    size_t pos = 0, current = 0, count = 0;

    while ((current = content.find("\n", pos)) != std::string::npos && count < size) {
        vec.push_back(atoi(content.substr(pos, current - pos - 1).c_str()));
        pos = current + 1;
        count++;
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Data loaded successfully in " << duration << " ms." << std::endl;
}

std::vector<double> pushVector(const std::vector<double> &data) {
    std::chrono::_V2::system_clock::time_point start, end;
    int64_t duration;
    start = std::chrono::high_resolution_clock::now();
    std::vector<double> result;
    for(double val: data) {
        result.push_back(val);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Data loaded successfully in " << duration << " ms." << std::endl;
    return result;
}

std::list<double> pushList(const std::vector<double> &data) {
    std::chrono::_V2::system_clock::time_point start, end;
    int64_t duration;
    start = std::chrono::high_resolution_clock::now();
    std::list<double> result;
    for(double val: data) {
        result.push_back(val);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Data loaded successfully in " << duration << " ms." << std::endl;
    return result;
}


int main(int, char**) {
    // std::vector<double> vec;
    // std::list<double> lst;
    // std::vector<double> mainData, extraData;

    // loadData("data.csv", mainData, 1000000);
    // loadData("data_to_add.csv", extraData, 100000);
    
    // vec = pushVector(mainData);

    // lst = pushList(mainData);


    return 0;
    // std::cout << "Inserting into vector..." << std::endl;

    // std::cout << "All elements inserted in vector" << std::endl;
    // std::cout << "Inserting in list..." << std::endl;

    // std::cout << "All elements inserted in list" << std::endl;
    

    // int option = 0;
    // if (argc == 2) {
    //     option = std::stoi(argv[1]);
    // }

    // std::vector<double> doubleVector;
    // std::list<double> doubleList;

    // std::ifstream inputFile("data.csv");
    // std::string line;

    // std::ifstream extraFile("data_to_add.csv");

    // switch(option) {
    //     case 1:
    //         while (std::getline(inputFile, line)) {
    //             double value = std::stod(line);
    //             doubleVector.push_back(value);
    //         }
    //         break;
    //     case 2:
    //         while (std::getline(inputFile, line)) {
    //             double value = std::stod(line);
    //             doubleList.push_back(value);
    //         }
    //         break;
    //     case 3:
    //         while (std::getline(inputFile, line)) {
    //             double value = std::stod(line);
    //             doubleVector.push_back(value);
    //         }

    //         std::array<double, 100000> extraArray;
    //         for (int i = 0; i < 100000; i++) {
    //             double value;
    //             extraFile >> value;
    //             extraArray[i] = value;
    //         }

    //         for (size_t s = 0; s < extraArray.size(); s++) {
    //             size_t indexMax = 500000;
    //             doubleVector.push_back(doubleVector.back());
    //             for (size_t i = doubleVector.size() - 2; i >= indexMax; i--) {
    //                 doubleVector[i + 1] = doubleVector[i];
    //             }
    //             doubleVector[indexMax] = extraArray[s];
    //         }
        
    //         break;
    //     case 4:
    //         while (std::getline(inputFile, line)) {
    //             double value = std::stod(line);
    //             doubleList.push_back(value);
    //         }

    //         std::array<double, 100000> extraArray;
    //         for (int i = 0; i < 100000; i++) {
    //             double value;
    //             extraFile >> value;
    //             extraArray[i] = value;
    //         }

    //         for (size_t s = 0; s < extraArray.size(); s++) {
    //             size_t indexMax = 500000;
    //             doubleList.push_back(doubleList.back());
    //             for (size_t i = doubleList.size() - 2; i >= indexMax; i--) {
    //                 doubleList.
    //                 doubleList[i + 1] = doubleList[i];
    //             }
    //             doubleList[indexMax] = extraArray[s];
    //         }
    //         break;
    //     default:
    //         std::cerr << "No option specified" << std::endl;
    //         return 1;
    // }


    // return 0;
}
