#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTFUNGI_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTFUNGI_H

#include "Dezinfectant.h"


class DezinfectantFungi : public Dezinfectant {
private:
    double totalFungi = 1.5 * pow(10, 6);
public:
    DezinfectantFungi() = default;

    ~DezinfectantFungi() override = default;

    DezinfectantFungi(int organismeUcise, const vector<string> &ingrediente, const vector<string> &tipuriSuprafata,
                      double totalFungi);

    DezinfectantFungi(const DezinfectantFungi &) = default;

    DezinfectantFungi &operator=(const DezinfectantFungi &) = default;

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    double eficienta() override;

    int pret() override;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTFUNGI_H
