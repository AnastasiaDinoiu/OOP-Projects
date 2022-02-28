#ifndef VACCINURICOMENZI_CPP_VACCINANTIGRIPAL_H
#define VACCINURICOMENZI_CPP_VACCINANTIGRIPAL_H

#include "Vaccin.h"


class VaccinAntigripal : public Vaccin {
private:
    string tulpina;
    bool respectaRecomandari{};

public:
    VaccinAntigripal() = default;

    ~VaccinAntigripal() override = default;

    VaccinAntigripal(float pret, float temperaturaDepozitare, const vector<string> &substante,
                     const string &numeProducator, const string &tulpina, bool respectaRecomandari);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    void afisareSchemaVaccinare() override;
};

#endif //VACCINURICOMENZI_CPP_VACCINANTIGRIPAL_H
