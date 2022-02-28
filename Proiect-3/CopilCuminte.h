#ifndef JUCARIICOPII_CPP_COPILCUMINTE_H
#define JUCARIICOPII_CPP_COPILCUMINTE_H

#include "Copil.h"


class CopilCuminte : public Copil {
private:
    int numarDulciuri{};
public:
    CopilCuminte() = default;

    ~CopilCuminte() override = default;

    CopilCuminte(const string &nume, const string &prenume, const string &adresa, int varsta,
                 int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii, int numarDulciuri);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_COPILCUMINTE_H
