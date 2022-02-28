#ifndef JUCARIICOPII_CPP_JUCARIEEDUCATIVA_H
#define JUCARIICOPII_CPP_JUCARIEEDUCATIVA_H

#include "Jucarie.h"


class JucarieEducativa : public virtual Jucarie {
protected:
    string abilitate;
public:
    JucarieEducativa() = default;

    ~JucarieEducativa() override = default;

    JucarieEducativa(const string &denumire, double dimensiune, const string &tip, const string &abilitate);

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;
};


#endif //JUCARIICOPII_CPP_JUCARIEEDUCATIVA_H
