#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_MASCA_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_MASCA_H

#include <iostream>
#include <string>

using namespace std;


class Masca {
protected:
    string tipProtectie;
public:
    Masca() = default;

    virtual ~Masca() = default;

    Masca(const string &tipProtectie);

    Masca(const Masca &) = default;

    Masca &operator=(const Masca &) = default;

    friend istream &operator>>(istream &is, Masca &masca);

    friend ostream &operator<<(ostream &os, const Masca &masca);

    virtual istream &citire(istream &is);

    virtual ostream &afisare(ostream &os) const;

    virtual int pret();
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_MASCA_H
