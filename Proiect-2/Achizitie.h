#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_ACHIZITIE_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_ACHIZITIE_H

#include "MascaChirurgicala.h"
#include "MascaPolicarbonat.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantFungi.h"
#include "DezinfectantVirusuri.h"


class Achizitie {
private:
    int zi{}, luna{}, an{};
    string numeClient;
    vector<Dezinfectant *> dezinfectanti;
    vector<Masca *> masti;
    int totalComanda{};

public:
    Achizitie() = default;

    ~Achizitie() = default;

    Achizitie(int zi, int luna, int an, const string &numeClient, const vector<Dezinfectant *> &dezinfectanti,
              const vector<Masca *> &masti);

    Achizitie(int zi, int luna, int an, const string &numeClient);

    Achizitie(const Achizitie &) = default;

    Achizitie &operator=(const Achizitie &) = default;

    int getZi() const;

    int getLuna() const;

    int getAn() const;

    const string &getNumeClient() const;

    void setTotalComanda();

    int getTotalComanda() const;

    const vector<Dezinfectant *> &getDezinfectanti() const;

    const vector<Masca *> &getMasti() const;

    friend istream &operator>>(istream &is, Achizitie &achizitie);

    friend ostream &operator<<(ostream &os, const Achizitie &achizitie);

    virtual istream &citire(istream &is);

    virtual ostream &afisare(ostream &os) const;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_ACHIZITIE_H
