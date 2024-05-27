#include "Funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <random>
#include <chrono>

// Define non-template functions

double calculateHomeworkAverage(const std::vector<double>& paz) {
    double sum = 0.0;
    for (auto pazymys : paz) {
        sum += pazymys;
    }
    return paz.empty() ? 0.0 : sum / paz.size();
}

double calculateMedian(std::vector<double> paz) {
    if (paz.empty()) return 0.0;

    size_t size = paz.size();
    sort(paz.begin(), paz.end());

    if (size % 2 == 0) {
        return (paz[size / 2 - 1] + paz[size / 2]) / 2.0;
    } else {
        return paz[size / 2];
    }
}

double calculateFinalGrade(double ND, double EGZ) {
    return 0.4 * ND + 0.6 * EGZ;
}

int RandomPazymys() {
    static std::mt19937 generator(static_cast<unsigned>(time(0)));
    std::uniform_int_distribution<int> distribution(1, 10);
    return distribution(generator);
}

void FailuSukurimas(const std::vector<int>& dydziai) {
    for (int dydis : dydziai) {
        std::ofstream out("studentai_" + std::to_string(dydis) + ".txt");
        if (!out.is_open()) {
            std::cerr << "Neisejo sukurti failo: studentai_" << dydis << ".txt" << std::endl;
            continue;
        }
        out << "Vardas Pavarde ";   // Header
        for (int i = 1; i <= 15; i++) out << "ND" << i << " ";   // Homework header
        out << "Egz" << std::endl;  // Exam header

        for (int i = 0; i <= dydis; i++) {
            out << "Vardas" << i << " Pavarde" << i << " ";
            for (int j = 0; j < 15; j++) {
                out << RandomPazymys() << " ";      // Random homework grades
            }
            out << RandomPazymys() << std::endl;    // Random exam grade
        }
        out.close();
    }
}
