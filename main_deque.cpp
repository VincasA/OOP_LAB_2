#include "Studentas.h"
#include "Funkcijos.h"

#include <iostream>
#include <string>
#include <deque>
#include <stdexcept>

int main(){
    std::deque<Studentas> studentai;
    std::vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << "Pasirinkite strategija (1, 2, 3): ";
    int strategy;
    std::cin >> strategy;

    LaikoMatavimas<std::deque<Studentas>>(dydziai, strategy);
    
    return EXIT_SUCCESS;
}