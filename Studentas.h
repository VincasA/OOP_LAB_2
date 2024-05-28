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
    // Default constructor
    Studentas() : Vardas(""), Pavarde(""), EGZ(0), GalutinisVid(0), GalutinisMed(0) {}

    // Parameterized constructor
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<double>& nd, double egz)
        : Vardas(vardas), Pavarde(pavarde), ND(nd), EGZ(egz), GalutinisVid(0), GalutinisMed(0) {}

    // Rule of Five
    ~Studentas() = default;
    
    // Copy constructor
    Studentas(const Studentas& other)
        : Vardas(other.Vardas), Pavarde(other.Pavarde), ND(other.ND), EGZ(other.EGZ), GalutinisVid(other.GalutinisVid), GalutinisMed(other.GalutinisMed) {}
    
    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this == &other) return *this;
        Vardas = other.Vardas;
        Pavarde = other.Pavarde;
        ND = other.ND;
        EGZ = other.EGZ;
        GalutinisVid = other.GalutinisVid;
        GalutinisMed = other.GalutinisMed;
        return *this;
    }
    
    // Move constructor
    Studentas(Studentas&& other) noexcept
        : Vardas(std::move(other.Vardas)), Pavarde(std::move(other.Pavarde)), ND(std::move(other.ND)), EGZ(other.EGZ), GalutinisVid(other.GalutinisVid), GalutinisMed(other.GalutinisMed) {
        other.EGZ = 0;
        other.GalutinisVid = 0;
        other.GalutinisMed = 0;
    }
    
    // Move assignment operator
    Studentas& operator=(Studentas&& other) noexcept {
        if (this == &other) return *this;
        Vardas = std::move(other.Vardas);
        Pavarde = std::move(other.Pavarde);
        ND = std::move(other.ND);
        EGZ = other.EGZ;
        GalutinisVid = other.GalutinisVid;
        GalutinisMed = other.GalutinisMed;
        other.EGZ = 0;
        other.GalutinisVid = 0;
        other.GalutinisMed = 0;
        return *this;
    }

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

#endif