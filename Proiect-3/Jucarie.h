#ifndef JUCARIICOPII_CPP_JUCARIE_H
#define JUCARIICOPII_CPP_JUCARIE_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;


class Jucarie {
protected:
    string denumire;
    double dimensiune{};
    string tip;
public:
    Jucarie() = default;

    virtual ~Jucarie() = default;

    Jucarie(const string &denumire, double dimensiune, const string &tip);

    friend istream &operator>>(istream &is, Jucarie &jucarie);

    virtual istream &citire(istream &is);

    friend ostream &operator<<(ostream &os, const Jucarie &jucarie);

    virtual ostream &afisare(ostream &os) const;
};


#endif //JUCARIICOPII_CPP_JUCARIE_H
