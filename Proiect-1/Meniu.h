#ifndef VACCINURICOMENZI_CPP_MENIU_H
#define VACCINURICOMENZI_CPP_MENIU_H

#include "Comanda.h"
#include <fstream>


class Meniu {
private:
    Meniu() = default;

    static Meniu *_instance;

    unsigned int optiune{};
    vector<shared_ptr<Vaccin>> vaccinuri;
    vector<shared_ptr<Comanda>> comenzi;

    static void arataOptiuni();

public:
    static Meniu *getInstance();

    void adaugareVaccin();

    void afisareVaccinuri();

    void afisareProducatori();

    void adaugareComanda();

    void afisareComenzi();

    void comenziValoareZi();

    static void afisareSchema();

    void exportFisier();

    void arataMeniu();
};


#endif //VACCINURICOMENZI_CPP_MENIU_H
