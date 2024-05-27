#include "Studentas.h"
#include "Funkcijos.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<Studentas> studentai;
    std::vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << "Pasirinkite strategija (1, 2, 3): ";
    int strategy;
    std::cin >> strategy;

    LaikoMatavimas<std::vector<Studentas>>(dydziai, strategy);

    return EXIT_SUCCESS;
}