#ifndef JUCARIICOPII_CPP_MENIU_H
#define JUCARIICOPII_CPP_MENIU_H

#include "CopilCuminte.h"
#include "CopilNeastamparat.h"
#include <algorithm>

class Meniu {
private:
    static Meniu *_instance;

    unsigned int optiune{};
    vector<shared_ptr<Copil>> copii;

    Meniu() = default;

    static void showOptions();

public:
    static Meniu *getInstance();

    void adaugareCopii();

    void afisareCopii();

    void cautaCopil();

    void ordonareVarsta();

    void ordonareFapteBune();

    void adaugaFapteBune();

    void raportJucarii();

    void showMenu();

    void setCopii(const vector<shared_ptr<Copil>> &_copii);
};


#endif //JUCARIICOPII_CPP_MENIU_H
