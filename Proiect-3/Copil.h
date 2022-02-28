#ifndef JUCARIICOPII_CPP_COPIL_H
#define JUCARIICOPII_CPP_COPIL_H

#include "JucarieElectronica.h"
#include "JucarieEducativa.h"
#include "JucarieClasica.h"
#include "JucarieModerna.h"
#include <vector>
#include <memory>


class Copil {
protected:
    static int staticIdCopil;
    const int idCopil{};
    string nume;
    string prenume;
    string adresa;
    int varsta{};
    int numarFapteBune{};
    vector<shared_ptr<Jucarie>> jucarii;
public:
    Copil() : idCopil(++staticIdCopil) {}

    virtual ~Copil() = default;

    Copil(const string &nume, const string &prenume, const string &adresa, int varsta,
          int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii);

    const int getIdCopil() const;

    const string &getNume() const;

    int getVarsta() const;

    int getNumarFapteBune() const;

    void setNumarFapteBune(int _numarFapteBune);

    const vector<shared_ptr<Jucarie>> &getJucarii() const;

    void setJucarii(const vector<shared_ptr<Jucarie>> &jucarii);

    friend istream &operator>>(istream &is, Copil &copil);

    virtual istream &citire(istream &is);

    friend ostream &operator<<(ostream &os, const Copil &copil);

    virtual ostream &afisare(ostream &os) const;
};


#endif //JUCARIICOPII_CPP_COPIL_H
