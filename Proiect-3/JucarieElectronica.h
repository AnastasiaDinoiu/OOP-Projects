#ifndef JUCARIICOPII_CPP_JUCARIEELECTRONICA_H
#define JUCARIICOPII_CPP_JUCARIEELECTRONICA_H

#include "Jucarie.h"


class JucarieElectronica : public virtual Jucarie {
protected:
    int numarBaterii{};
public:
    JucarieElectronica() = default;

    ~JucarieElectronica() override = default;

    JucarieElectronica(const string &denumire, double dimensiune, const string &tip, int numarBaterii);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_JUCARIEELECTRONICA_H
