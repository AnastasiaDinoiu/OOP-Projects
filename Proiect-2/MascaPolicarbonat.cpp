#include "MascaPolicarbonat.h"

MascaPolicarbonat::MascaPolicarbonat(const string &tipPrindere) : tipPrindere(tipPrindere) {
    this->tipProtectie = "ffp0";
}

istream &MascaPolicarbonat::citire(istream &is) {
    tipProtectie = "ffp0";
    cout << "Tip prindere:";
    is >> tipPrindere;
    return is;
}

ostream &MascaPolicarbonat::afisare(ostream &os) const {
    Masca::afisare(os);

    os << "Tip prindere: " << tipPrindere << "\n";
    return os;
}

int MascaPolicarbonat::pret() {
    return 20;
}