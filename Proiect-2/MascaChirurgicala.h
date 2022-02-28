#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_MASCACHIRURGICALA_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_MASCACHIRURGICALA_H

#include "Masca.h"


class MascaChirurgicala : public Masca {
private:
    string culoare;
    unsigned int numarPliuri{};
public:
    MascaChirurgicala() = default;

    ~MascaChirurgicala() override = default;

    MascaChirurgicala(const string &culoare, unsigned int numarPliuri);

    MascaChirurgicala(const MascaChirurgicala &) = default;

    MascaChirurgicala &operator=(const MascaChirurgicala &) = default;

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    int pret() override;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_MASCACHIRURGICALA_H
