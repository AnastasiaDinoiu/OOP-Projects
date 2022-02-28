#include "DezinfectantFungi.h"

DezinfectantFungi::DezinfectantFungi(int organismeUcise, const vector<string> &ingrediente,
                                     const vector<string> &tipuriSuprafata, double totalFungi) : Dezinfectant(
        organismeUcise, ingrediente, tipuriSuprafata), totalFungi(totalFungi) {}

istream &DezinfectantFungi::citire(istream &is) {
    return Dezinfectant::citire(is);
}

ostream &DezinfectantFungi::afisare(ostream &os) const {
    return Dezinfectant::afisare(os);
}

double DezinfectantFungi::eficienta() {
    return (double) organismeUcise / totalFungi;
}

int DezinfectantFungi::pret() {
    return Dezinfectant::pret();
}
