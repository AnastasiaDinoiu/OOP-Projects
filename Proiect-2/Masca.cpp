#include "Masca.h"

Masca::Masca(const string &tipProtectie) : tipProtectie(tipProtectie) {}

istream &operator>>(istream &is, Masca &masca) {
    masca.citire(is);
    return is;
}

ostream &operator<<(ostream &os, const Masca &masca) {
    masca.afisare(os);
    return os;
}

istream &Masca::citire(istream &is) {
    cout << "Tip protectie:";
    is >> tipProtectie;
    return is;
}

ostream &Masca::afisare(ostream &os) const {
    os << "Tip protectie: " << tipProtectie << "\n";
    return os;
}

int Masca::pret() {
    return 0;
}

