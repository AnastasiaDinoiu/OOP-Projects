#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANT_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANT_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Dezinfectant {
protected:
    int organismeUcise{};
    vector<string> ingrediente;
    vector<string> tipuriSuprafata;
public:
    Dezinfectant() = default;

    virtual ~Dezinfectant() = default;

    Dezinfectant(int organismeUcise, const vector<string> &ingrediente, const vector<string> &tipuriSuprafata);

    Dezinfectant(const Dezinfectant &) = default;

    Dezinfectant &operator=(const Dezinfectant &) = default;

    void setOrganismeUcise(int _organismeUcise);

    const vector<string> &getIngrediente() const;

    void setIngrediente(const vector<string> &ingrediente);

    friend istream &operator>>(istream &is, Dezinfectant &dezinfectant);

    friend ostream &operator<<(ostream &os, const Dezinfectant &dezinfectant);

    virtual istream &citire(istream &is);

    virtual ostream &afisare(ostream &os) const;

    virtual double eficienta();

    virtual int pret();
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANT_H
