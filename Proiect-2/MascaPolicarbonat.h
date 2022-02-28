#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_MASCAPOLICARBONAT_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_MASCAPOLICARBONAT_H

#include "Masca.h"


class MascaPolicarbonat : public Masca {
private:
    string tipPrindere;
public:
    MascaPolicarbonat() = default;

    ~MascaPolicarbonat() override = default;

    MascaPolicarbonat(const string &tipPrindere);

    MascaPolicarbonat(const MascaPolicarbonat &) = default;

    MascaPolicarbonat &operator=(const MascaPolicarbonat &) = default;

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    int pret() override;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_MASCAPOLICARBONAT_H
