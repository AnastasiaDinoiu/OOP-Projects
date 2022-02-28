#ifndef JUCARIICOPII_CPP_JUCARIEMODERNA_H
#define JUCARIICOPII_CPP_JUCARIEMODERNA_H

#include "JucarieEducativa.h"
#include "JucarieElectronica.h"


class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    string brand;
    string model;
public:
    JucarieModerna() = default;

    ~JucarieModerna() override = default;

    JucarieModerna(const string &denumire, double dimensiune, const string &tip,
                   const string &brand, const string &model);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_JUCARIEMODERNA_H
