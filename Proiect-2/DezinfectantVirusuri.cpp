#include "DezinfectantVirusuri.h"

DezinfectantVirusuri::DezinfectantVirusuri(int organismeUcise, const vector<string> &ingrediente,
                                           const vector<string> &tipuriSuprafata, double totalVirusuri) : Dezinfectant(
        organismeUcise, ingrediente, tipuriSuprafata), totalVirusuri(totalVirusuri) {}

istream &DezinfectantVirusuri::citire(istream &is) {
    return Dezinfectant::citire(is);
}

ostream &DezinfectantVirusuri::afisare(ostream &os) const {
    return Dezinfectant::afisare(os);
}

double DezinfectantVirusuri::eficienta() {
    return (double) organismeUcise / totalVirusuri;
}

int DezinfectantVirusuri::pret() {
    return Dezinfectant::pret();
}
