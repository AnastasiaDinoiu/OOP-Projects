#ifndef VACCINURICOMENZI_CPP_VACCIN_H
#define VACCINURICOMENZI_CPP_VACCIN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Vaccin {
protected:
    float pret{};
    float temperaturaDepozitare{};
    vector<string> substante;
    string numeProducator;

public:
    Vaccin() = default;

    virtual ~Vaccin() = default;

    Vaccin(float pret, float temperaturaDepozitare, const vector<string> &substante, const string &numeProducator);

    friend istream &operator>>(istream &is, Vaccin &vaccin);

    virtual istream &citire(istream &is);

    friend ostream &operator<<(ostream &os, const Vaccin &vaccin);

    virtual ostream &afisare(ostream &os) const;

    float getPret() const;

    const string &getNumeProducator() const;

    virtual void afisareSchemaVaccinare() {}
};

#endif //VACCINURICOMENZI_CPP_VACCIN_H
