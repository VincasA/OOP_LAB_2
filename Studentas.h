#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas {
private:
    std::string Vardas;
    std::string Pavarde;
    std::vector<double> ND;
    double EGZ;
    double GalutinisVid;
    double GalutinisMed;

public:
    // Getters
    std::string getVardas() const { return Vardas; }
    std::string getPavarde() const { return Pavarde; }
    const std::vector<double>& getNd() const { return ND; }
    double getEgz() const { return EGZ; }
    double getGalutinisVid() const { return GalutinisVid; }
    double getGalutinisMed() const { return GalutinisMed; }

    // Setters
    void setVardas(const std::string& v) { Vardas = v; }
    void setPavarde(const std::string& p) { Pavarde = p; }
    void setNd(const std::vector<double>& nd) { ND = nd; }
    void setEgz(double e) { EGZ = e; }
    void setGalutinisVid(double g) { GalutinisVid = g; }
    void setGalutinisMed(double g) { GalutinisMed = g; }

    void addNd(double grade) { ND.push_back(grade); }
};

#endif // STUDENTAS_H
