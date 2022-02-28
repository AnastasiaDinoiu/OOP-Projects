#ifndef JUCARIICOPII_CPP_COPILNEASTAMPARAT_H
#define JUCARIICOPII_CPP_COPILNEASTAMPARAT_H

#include "Copil.h"


class CopilNeastamparat : public Copil {
private:
    int numarCarbuni{};

public:
    CopilNeastamparat() = default;

    ~CopilNeastamparat() override = default;

    CopilNeastamparat(const string &nume, const string &prenume, const string &adresa, int varsta,
                      int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii, int numarCarbuni);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_COPILNEASTAMPARAT_H
