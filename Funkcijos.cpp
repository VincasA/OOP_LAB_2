#include "Funkcijos.h"
#include "Studentas.h"

double calculateHomeworkAverage(const std::vector<double>& paz) {
    if (paz.empty()) return 0.0;
    double sum = 0.0;
    for (const auto& p : paz) {
        sum += p;
    }
    return sum / paz.size();
}

double calculateMedian(std::vector<double> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    size_t size = paz.size();
    if (size % 2 == 0) {
        return (paz[size / 2 - 1] + paz[size / 2]) / 2;
    } else {
        return paz[size / 2];
    }
}

double calculateFinalGrade(double ND, double EGZ) {
    return 0.4 * ND + 0.6 * EGZ;
}

int RandomPazymys() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void FailuSukurimas(const std::vector<int>& dydziai) {
    for (int dydis : dydziai) {
        std::ofstream out("studentai_" + std::to_string(dydis) + ".txt");
        if (!out.is_open()) {
            std::cerr << "Neisejo sukurti failo: studentai_" << dydis << ".txt" << std::endl;
            continue;
        }
        out << "Vardas Pavarde ";
        for (int i = 0; i < 15; i++) {
            out << "ND" << i + 1 << " ";
        }
        out << "Egzaminas" << std::endl;

        for (int i = 0; i < dydis; i++) {
            out << "Vardas" << i << " Pavarde" << i << " ";
            for (int j = 0; j < 15; j++) {
                out << RandomPazymys() << " ";
            }
            out << RandomPazymys() << std::endl;
        }
        out.close();
    }
}
