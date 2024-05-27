#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "Studentas.h"
#include <vector>
#include <deque>
#include <list>
#include <string>

double calculateHomeworkAverage(const std::vector<double>& paz);
double calculateMedian(std::vector<double> paz);
double calculateFinalGrade(double ND, double EGZ);

template <typename Container>
bool readDataFromFile(const std::string& filename, Container& studentai);

template <typename Container>
void readDataFromUser(Container& studentai);

inline void sortStudents(std::list<Studentas>& studentai);
template <typename Container>
void sortStudents(Container& studentai);

int RandomPazymys();
void FailuSukurimas(const std::vector<int>& dydziai);

template <typename Container>
void processStudents(const std::string& filename, double& sortTime, double& splitTime, double& writeTime, int strategy);

template <typename Container>
void LaikoMatavimas(const std::vector<int>& dydziai, int strategy);

template <typename Container>
void splitStrategy1(const Container& studentai, Container& vargsiai, Container& kietekai);

template <typename Container>
void splitStrategy2(Container& studentai, Container& vargsiai);

template <typename Container>
void splitStrategy3(Container& studentai, Container& vargsiai);

#include "Funkcijos_impl.h"

#endif
