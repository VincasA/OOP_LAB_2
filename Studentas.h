#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Zmogus {
protected:
    std::string Vardas;
    std::string Pavarde;

public:
    Zmogus() : Vardas(""), Pavarde("") {}
    Zmogus(const std::string& vardas, const std::string& pavarde) : Vardas(vardas), Pavarde(pavarde) {}

    virtual ~Zmogus() = default;  // Virtual destructor

    // Pure virtual functions make this an abstract class
    virtual std::string getVardas() const = 0;
    virtual std::string getPavarde() const = 0;
    virtual void setVardas(const std::string& vardas) = 0;
    virtual void setPavarde(const std::string& pavarde) = 0;
};

class Studentas : public Zmogus {
private:
    std::vector<double> ND;
    double EGZ;
    double GalutinisVid;
    double GalutinisMed;

public:
    // Default constructor
    Studentas() : Zmogus(), EGZ(0), GalutinisVid(0), GalutinisMed(0) {}

    // Parameterized constructor
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<double>& nd, double egz)
        : Zmogus(vardas, pavarde), ND(nd), EGZ(egz), GalutinisVid(0), GalutinisMed(0) {}

    // Destructor
    ~Studentas() override = default;

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other.Vardas, other.Pavarde), ND(other.ND), EGZ(other.EGZ), GalutinisVid(other.GalutinisVid), GalutinisMed(other.GalutinisMed) {}
    
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
        : Zmogus(std::move(other.Vardas), std::move(other.Pavarde)), ND(std::move(other.ND)), EGZ(other.EGZ), GalutinisVid(other.GalutinisVid), GalutinisMed(other.GalutinisMed) {
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
    std::string getVardas() const override { return Vardas; }
    std::string getPavarde() const override { return Pavarde; }
    const std::vector<double>& getNd() const { return ND; }
    double getEgz() const { return EGZ; }
    double getGalutinisVid() const { return GalutinisVid; }
    double getGalutinisMed() const { return GalutinisMed; }

    // Setters
    void setVardas(const std::string& v) override { Vardas = v; }
    void setPavarde(const std::string& p) override { Pavarde = p; }
    void setNd(const std::vector<double>& nd) { ND = nd; }
    void setEgz(double e) { EGZ = e; }
    void setGalutinisVid(double g) { GalutinisVid = g; }
    void setGalutinisMed(double g) { GalutinisMed = g; }

    void addNd(double grade) { ND.push_back(grade); }
};

#endif // STUDENTAS_H
