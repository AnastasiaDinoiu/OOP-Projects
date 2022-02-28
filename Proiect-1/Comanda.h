#ifndef VACCINURICOMENZI_CPP_COMANDA_H
#define VACCINURICOMENZI_CPP_COMANDA_H

#include "VaccinAntiSarsCov2.h"
#include "VaccinAntigripal.h"
#include "VaccinAntihepatic.h"
#include <memory>


struct ComandaVaccin {
    shared_ptr<Vaccin> vaccin;
    int cantitate;
};

struct Data {
    int zi{};
    int luna{};
    int an{};
};

class Comanda {
private:
    static int staticIdComanda;
    const int idComanda{};
    Data data;
    string numeClient;
    vector<ComandaVaccin> vaccinuri;

public:
    Comanda() : idComanda(++staticIdComanda) {}

    ~Comanda() = default;

    Comanda(const int idComanda, const Data &data, const string &numeClient, const vector<ComandaVaccin> &vaccinuri);

    float valoareTotalaComanda();

    friend istream &operator>>(istream &is, Comanda &comanda);

    istream &citire(istream &is);

    friend ostream &operator<<(ostream &os, const Comanda &comanda);

    ostream &afisare(ostream &os) const;

    const int getIdComanda() const;

    const Data &getData() const;

    const string &getNumeClient() const;

    const vector<ComandaVaccin> &getVaccinuri() const;
};


#endif //VACCINURICOMENZI_CPP_COMANDA_H
