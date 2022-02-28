#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTBACTERII_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTBACTERII_H

#include "Dezinfectant.h"


class DezinfectantBacterii : public Dezinfectant {
private:
    double totalBacterii = pow(10, 9);
public:
    DezinfectantBacterii() = default;

    ~DezinfectantBacterii() override = default;

    DezinfectantBacterii(int organismeUcise, const vector<string> &ingrediente, const vector<string> &tipuriSuprafata,
                         double totalBacterii);

    DezinfectantBacterii(const DezinfectantBacterii &) = default;

    DezinfectantBacterii &operator=(const DezinfectantBacterii &) = default;

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    double eficienta() override;

    int pret() override;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTBACTERII_H
