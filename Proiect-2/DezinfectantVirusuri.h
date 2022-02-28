#ifndef MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTVIRUSURI_H
#define MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTVIRUSURI_H

#include "Dezinfectant.h"


class DezinfectantVirusuri : public Dezinfectant {
private:
    double totalVirusuri = pow(10, 8);
public:
    DezinfectantVirusuri() = default;

    ~DezinfectantVirusuri() override = default;

    DezinfectantVirusuri(int organismeUcise, const vector<string> &ingrediente, const vector<string> &tipuriSuprafata,
                         double totalVirusuri);

    DezinfectantVirusuri(const DezinfectantVirusuri &) = default;

    DezinfectantVirusuri &operator=(const DezinfectantVirusuri &) = default;

    istream &citire(istream &is) override;

    ostream &afisare(ostream &os) const override;

    double eficienta() override;

    int pret() override;
};


#endif //MASTIDEZINFECTANTIACHIZITII_CPP_DEZINFECTANTVIRUSURI_H
