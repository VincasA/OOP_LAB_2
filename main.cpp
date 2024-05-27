#include "Studentas.h"
#include "Funkcijos.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<Studentas> studentai;
    std::vector<int> dydziai = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << "Pasirinkite kaip skaityti duomenis (failas/vartotojas/generuoti): ";
    std::string pasirinkimas;
    std::cin >> pasirinkimas;

    if(pasirinkimas == "failas"){
        std::string filename;
        std::cout << "Iveskite failo pavadinima: ";
        std::cin >> filename;

        try{
            readDataFromFile(filename, studentai);
        } catch(const std::runtime_error& e){
            std::cerr << "Klaida: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } else if (pasirinkimas == "vartotojas"){
        readDataFromUser(studentai);
    } else if (pasirinkimas == "generuoti"){
        int strategy;
        std::cout << "Pasirinkite strategija (1, 2, 3)" << std::endl;
        std::cin >> strategy;
        
        if (strategy == 1 || strategy == 2 || strategy == 3) {
            LaikoMatavimas<std::vector<Studentas>>(dydziai, strategy);
        } else std::cout << "Netinkamas pasirinkimas" << std::endl;
    } else {
        std::cerr << "Netinkamas pasirinkimas. Prasau pasirinkite 'failas' arba 'vartotojas'." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}