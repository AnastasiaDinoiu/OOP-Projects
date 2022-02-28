#include "JucarieEducativa.h"

JucarieEducativa::JucarieEducativa(const string &denumire, double dimensiune, const string &tip,
                                   const string &abilitate) : Jucarie(denumire, dimensiune, tip),
                                                              abilitate(abilitate) {}

istream &JucarieEducativa::citire(istream &is) {
    Jucarie::citire(is);
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "abilitate: ";
    getline(is, abilitate);

    return is;
}

ostream &JucarieEducativa::afisare(ostream &os) const {
    Jucarie::afisare(os);
    os << "abilitate: " << abilitate << "\n";

    return os;
}
