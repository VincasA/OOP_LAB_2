#include <iostream>
#include <vector>
#include "Studentas.h"

int main() {
    std::vector<double> pazymiai = {10, 9, 7};
    Studentas s1("Jonas", "Jonaitis", pazymiai, 9);

    //Panaudojamas copy constructor
    std::cout << "Pradinis studentas: " << s1.getVardas() << " " << s1.getPavarde() << " " << std::endl;
    Studentas s2 = s1;
    std::cout << "Kopijuotas studentas: " << s2.getVardas() << " " << s2.getPavarde() << std::endl;

    //Panaudojamas copy assignment operator
    Studentas s3;
    s3 = s1;
    std::cout << "Assigned student: " << s3.getVardas() << " " << s3.getPavarde() << std::endl;

    //Panaudojamas move constructor
    Studentas s4 = std::move(s1);
    std::cout << "Moved student: " << s4.getVardas() << " " << s4.getPavarde() << std::endl;

    //Panaudojamas move assignment operator
    Studentas s5;
    s5 = std::move(s2);
    std::cout << "Move assigned student: " << s5.getVardas() << " " << s5.getPavarde() << std::endl;

    return 0;
}