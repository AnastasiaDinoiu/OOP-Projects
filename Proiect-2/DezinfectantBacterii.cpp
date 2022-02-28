#include "DezinfectantBacterii.h"

DezinfectantBacterii::DezinfectantBacterii(int organismeUcise, const vector<string> &ingrediente,
                                           const vector<string> &tipuriSuprafata, double totalBacterii) : Dezinfectant(
        organismeUcise, ingrediente, tipuriSuprafata), totalBacterii(totalBacterii) {}

istream &DezinfectantBacterii::citire(istream &is) {
    return Dezinfectant::citire(is);
}

ostream &DezinfectantBacterii::afisare(ostream &os) const {
    return Dezinfectant::afisare(os);
}

double DezinfectantBacterii::eficienta() {
    return (double) organismeUcise / totalBacterii;
}

int DezinfectantBacterii::pret() {
    return Dezinfectant::pret();
}
