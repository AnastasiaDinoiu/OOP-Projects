#ifndef VACCINURICOMENZI_CPP_VACCINANTISARSCOV2_H
#define VACCINURICOMENZI_CPP_VACCINANTISARSCOV2_H

#include "Vaccin.h"


class VaccinAntiSarsCov2 : public Vaccin {
private:
    vector<string> reactiiAdverse;
    float rataEficienta{};
    vector<string> medicamenteContraindicate;

public:
    VaccinAntiSarsCov2() = default;

    ~VaccinAntiSarsCov2() override = default;

    VaccinAntiSarsCov2(float pret, float temperaturaDepozitare, const vector<string> &substante,
                       const string &numeProducator, const vector<string> &reactiiAdverse, float rataEficienta,
                       const vector<string> &medicamenteContraindicate);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    void afisareSchemaVaccinare() override;
};

#endif //VACCINURICOMENZI_CPP_VACCINANTISARSCOV2_H
