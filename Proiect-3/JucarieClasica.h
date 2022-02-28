#ifndef JUCARIICOPII_CPP_JUCARIECLASICA_H
#define JUCARIICOPII_CPP_JUCARIECLASICA_H

#include "Jucarie.h"


class JucarieClasica : public Jucarie {
private:
    string material;
    string culoare;
public:
    JucarieClasica() = default;

    ~JucarieClasica() override = default;

    JucarieClasica(const string &denumire, double dimensiune, const string &tip, const string &material,
                   const string &culoare);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_JUCARIECLASICA_H
