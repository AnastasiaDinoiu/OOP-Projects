#ifndef VACCINURICOMENZI_CPP_VACCINANTIHEPATIC_H
#define VACCINURICOMENZI_CPP_VACCINANTIHEPATIC_H

#include "Vaccin.h"


class VaccinAntihepatic : public Vaccin {
protected:
    string tipHepatita;
    string modVaccinare;

public:
    VaccinAntihepatic() = default;

    ~VaccinAntihepatic() override = default;

    VaccinAntihepatic(float pret, float temperaturaDepozitare, const vector<string> &substante,
                      const string &numeProducator, const string &tipHepatita, const string &modVaccinare);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    void afisareSchemaVaccinare() override;
};

#endif //VACCINURICOMENZI_CPP_VACCINANTIHEPATIC_H
