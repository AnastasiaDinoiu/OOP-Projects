#include "Jucarie.h"

Jucarie::Jucarie(const string &denumire, double dimensiune, const string &tip) : denumire(denumire),
                                                                                 dimensiune(dimensiune), tip(tip) {}

istream &operator>>(istream &is, Jucarie &jucarie) {
    jucarie.citire(is);
    return is;
}

istream &Jucarie::citire(istream &is) {
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "denumire:";
    getline(is, denumire);

    cout << "dimensiune:";
    is >> dimensiune;

    cout << "tip:";
    getline(is, tip);

    return is;
}

ostream &operator<<(ostream &os, const Jucarie &jucarie) {
    jucarie.afisare(os);
    return os;
}

ostream &Jucarie::afisare(ostream &os) const {
    os << "denumire: " << denumire << "\n";
    os << "dimensiune: " << dimensiune << "\n";
    os << "tip: " << tip << "\n";

    return os;
}
