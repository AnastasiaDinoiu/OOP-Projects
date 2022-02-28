#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_STOC_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_STOC_H

#include "Achizitie.h"
#include <algorithm>


class Stoc {
private:
    static Stoc *_instance;

    Stoc() = default;

    vector<Masca *> masti;
    vector<Dezinfectant *> dezinfectanti;
    vector<Achizitie *> achizitii;

    unsigned int optiune{};

    static void showOptions();

public:
    static Stoc *getInstance();

    ~Stoc();

    void adaugaDezinfectant(vector<Dezinfectant *> &dezinfectant);

    void adaugaMasca(vector<Masca *> &masca);

    void adaugaAchizitie(vector<Achizitie *> &achizitie);

    void dezinfectantEficient();

    void venitLuna();

    void venitMastiChirurgicale();

    static void optiuniModificareIngredient();

    void moficaIngredient();

    void clientFidel();

    void ziVenitMic();

    void calculTVA();

    void afisareStoc();

    void showMenu();
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_STOC_H
