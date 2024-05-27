#ifndef FUNKCIJOS_IMPL_H
#define FUNKCIJOS_IMPL_H

#include "Funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <random>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <list>

// Function Definitions
template <typename Container>
bool readDataFromFile(const std::string& filename, Container& studentai) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Neisejo atidaryti ivesties failo");
    }

    std::string line;
    std::getline(file, line);  // Ignoruojama pirma eilute (Antraste)

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Studentas temp;
        iss >> temp.Vardas >> temp.Pavarde;

        double grade;
        while (iss >> grade) {
            temp.ND.push_back(grade);
        }

        if (!temp.ND.empty() && temp.ND.back() >= 1.0 && temp.ND.back() <= 10.0) {
            temp.EGZ = temp.ND.back();
            temp.ND.pop_back();
        } else {
            std::cerr << "Klaida: Netinkamas arba nera egzamino ivertinimo studentui: " << temp.Vardas << " " << temp.Pavarde << std::endl;
            continue;
        }

        temp.ND.erase(std::remove_if(temp.ND.begin(), temp.ND.end(), [](double g) { return g < 1.0 || g > 10.0; }), temp.ND.end());

        temp.GalutinisVid = calculateFinalGrade(calculateHomeworkAverage(temp.ND), temp.EGZ);
        temp.GalutinisMed = calculateFinalGrade(calculateMedian(temp.ND), temp.EGZ);

        studentai.push_back(temp);
    }

    file.close();
    return true;
}

template <typename Container>
void readDataFromUser(Container& studentai) {
    std::string line;
    while (true) {
        Studentas temp;

        std::cout << "Iveskite studento varda (arba '0' jei norite uzbaigti): ";
        std::cin >> temp.Vardas;
        if (temp.Vardas == "0") break;

        std::cout << "Iveskite studento pavarde: ";
        std::cin >> temp.Pavarde;

        std::cout << "Iveskite egzmaino ivertinima (1-10): ";
        std::cin >> temp.EGZ;
        if (temp.EGZ < 1.0 || temp.EGZ > 10.0) {
            std::cerr << "Netinkamas egzamino ivertinimas. Bandykite dar." << std::endl;
            continue;
        }

        std::cout << "Iveskite namu darbu ivertinimus (1-10). Iveskite '-1' jei norite uzbaigti: ";
        double grade;
        while (std::cin >> grade) {
            if (grade == -1) break;
            if (grade >= 1.0 && grade <= 10.0) {
                temp.ND.push_back(grade);
            } else {
                std::cerr << "Netinkamas ivertinimas. Iveskite ivertinima nuo 1 iki 10." << std::endl;
            }
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        temp.GalutinisVid = calculateFinalGrade(calculateHomeworkAverage(temp.ND), temp.EGZ);
        temp.GalutinisMed = calculateFinalGrade(calculateMedian(temp.ND), temp.EGZ);

        studentai.push_back(temp);
    }

    sortStudents(studentai);

    try {
        std::ofstream outfile("studentai_rezultatai.txt");
        if (!outfile.is_open()) {
            throw std::runtime_error("Neisejo atidaryti isvesties failo");
        }

        outfile << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas"
                << std::setw(20) << "Galutinis ivertinimas (Vid.)" << std::setw(20) << "Galutinis ivertinimas (Med.)" << std::endl;
        outfile << std::string(70, '-') << std::endl;

        for (const auto& student : studentai) {
            outfile << std::setw(15) << student.Pavarde << std::setw(15) << student.Vardas
                    << std::fixed << std::setprecision(2) << std::setw(20) << student.GalutinisVid
                    << std::setw(20) << student.GalutinisMed << std::endl;
        }

        outfile.close();
    } catch (const std::runtime_error& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
    }
}

inline void sortStudents(std::list<Studentas>& studentai) {
    std::cout << "Pasirinkite rusiavimo metoda (studentu skaicius: " << studentai.size() + 1 << "): " << std::endl;
    std::cout << "1. Vardas" << std::endl;
    std::cout << "2. Pavarde" << std::endl;
    std::cout << "3. Galutinis ivertinimas (Vid.)" << std::endl;
    std::cout << "4. Galutinis ivertinimas (Med.)" << std::endl;

    int method;
    std::cin >> method;

    if (method == 1) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.Vardas < b.Vardas;
        });
    } else if (method == 2) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.Pavarde < b.Pavarde;
        });
    } else if (method == 3) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.GalutinisVid < b.GalutinisVid;
        });
    } else if (method == 4) {
        studentai.sort([](const Studentas& a, const Studentas& b) {
            return a.GalutinisMed < b.GalutinisMed;
        });
    } else {
        std::cerr << "Netinkamas metodas. Bandykite dar." << std::endl;
    }
}

template <typename Container>
void sortStudents(Container& studentai) {
    std::cout << "Pasirinkite rusiavimo metoda (studentu skaicius: " << studentai.size() + 1 << "): " << std::endl;
    std::cout << "1. Vardas" << std::endl;
    std::cout << "2. Pavarde" << std::endl;
    std::cout << "3. Galutinis ivertinimas (Vid.)" << std::endl;
    std::cout << "4. Galutinis ivertinimas (Med.)" << std::endl;

    int method;
    std::cin >> method;

    if (method == 1) {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.Vardas < b.Vardas;
        });
    } else if (method == 2) {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.Pavarde < b.Pavarde;
        });
    } else if (method == 3) {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.GalutinisVid < b.GalutinisVid;
        });
    } else if (method == 4) {
        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.GalutinisMed < b.GalutinisMed;
        });
    } else {
        std::cerr << "Netinkamas metodas. Bandykite dar." << std::endl;
    }
}

template <typename Container>
void splitStrategy1(const Container& studentai, Container& vargsiai, Container& kietekai) {
    for (const auto& student : studentai) {
        if (student.GalutinisVid < 5.0) {
            vargsiai.push_back(student);
        } else {
            kietekai.push_back(student);
        }
    }
}

template <typename Container>
void splitStrategy2(Container& studentai, Container& vargsiai) {
    for (auto it = studentai.begin(); it != studentai.end(); ) {
        if (it->GalutinisVid < 5.0) {
            vargsiai.push_back(std::move(*it));
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
}

template <typename Container>
void splitStrategy3(Container& studentai, Container& vargsiai) {
    std::partition_copy(studentai.begin(), studentai.end(), std::back_inserter(vargsiai), studentai.begin(),
                        [](const Studentas& student) { return student.GalutinisVid < 5.0; });
    studentai.erase(std::remove_if(studentai.begin(), studentai.end(),
                                   [](const Studentas& student) { return student.GalutinisVid < 5.0; }), studentai.end());
}

template <typename Container>
void processStudents(const std::string& filename, double& sortTime, double& splitTime, double& writeTime, int strategy) {
    Container studentai;
    if (!readDataFromFile(filename, studentai)) {
        return;
    }

    auto sortStart = std::chrono::high_resolution_clock::now();
    sortStudents(studentai);
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = sortEnd - sortStart;
    sortTime = sortDuration.count();

    auto splitStart = std::chrono::high_resolution_clock::now();
    Container vargsiai;
    Container kietekai;

    if (strategy == 1) {
        splitStrategy1(studentai, vargsiai, kietekai);
    } else if (strategy == 2) {
        splitStrategy2(studentai, vargsiai);
    } else if (strategy == 3) {
        splitStrategy3(studentai, vargsiai);
    }
    auto splitEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> splitDuration = splitEnd - splitStart;
    splitTime = splitDuration.count();

    auto writeStart = std::chrono::high_resolution_clock::now();
    std::ofstream vargsiaiFile("vargsiai_" + filename);
    std::ofstream kietekaiFile("kietekai_" + filename);

    vargsiaiFile << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas"
                 << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    vargsiaiFile << std::string(70, '-') << std::endl;

    for (const auto& student : vargsiai) {
        vargsiaiFile << std::setw(15) << student.Pavarde << " " << std::setw(15) << student.Vardas << " "
                     << std::fixed << std::setprecision(2) << std::setw(20) << student.GalutinisVid << " "
                     << std::setw(20) << student.GalutinisMed << "\n";
    }

    kietekaiFile << std::left << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas"
                 << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    kietekaiFile << std::string(70, '-') << std::endl;

    for (const auto& student : kietekai) {
        kietekaiFile << std::setw(15) << student.Pavarde << " " << std::setw(15) << student.Vardas << " "
                     << std::fixed << std::setprecision(2) << std::setw(20) << student.GalutinisVid << " "
                     << std::setw(20) << student.GalutinisMed << "\n";
    }

    vargsiaiFile.close();
    kietekaiFile.close();
    auto writeEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> writeDuration = writeEnd - writeStart;
    writeTime = writeDuration.count();
}

template <typename Container>
void LaikoMatavimas(const std::vector<int>& dydziai, int strategy) {
    for (int dydis : dydziai) {
        auto totalStart = std::chrono::high_resolution_clock::now();

        auto fileCreationStart = std::chrono::high_resolution_clock::now();
        std::ofstream out("studentai_" + std::to_string(dydis) + ".txt");
        if (!out.is_open()) {
            std::cerr << "Neisejo sukurti failo: studentai_" << dydis << ".txt" << std::endl;
            continue;
        }
        for (int i = 0; i < dydis; i++) {
            out << "Vardas" << i << " Pavarde" << i << " ";
            for (int j = 0; j < 15; j++) {
                out << RandomPazymys() << " ";
            }
            out << RandomPazymys() << std::endl;
        }
        out.close();
        auto fileCreationEnd = std::chrono::high_resolution_clock::now();

        auto dataReadStart = std::chrono::high_resolution_clock::now();
        double sortTime = 0.0;
        double splitTime = 0.0;
        double writeTime = 0.0;
        processStudents<Container>("studentai_" + std::to_string(dydis) + ".txt", sortTime, splitTime, writeTime, strategy);
        auto dataReadEnd = std::chrono::high_resolution_clock::now();

        auto totalEnd = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> fileCreationDuration = fileCreationEnd - fileCreationStart;
        std::chrono::duration<double> dataReadDuration = dataReadEnd - dataReadStart;
        std::chrono::duration<double> totalDuration = totalEnd - totalStart;

        std::cout << "Failas su " << dydis << " duomenu:\n";
        std::cout << "Failo sukurimo laikas: " << fileCreationDuration.count() << " s\n";
        std::cout << "Failo skaitymo laikas: " << dataReadDuration.count() - sortTime - splitTime - writeTime << " s\n";
        std::cout << "Studentu rusiavimo laikas: " << sortTime << " s\n";
        std::cout << "Studentu atskyrimo laikas: " << splitTime << " s\n";
        std::cout << "Duomenu rasymo laikas: " << writeTime << " s\n";
        std::cout << "Visas laikas: " << totalDuration.count() << " s\n";
        std::cout << std::endl;
    }
}

#endif
