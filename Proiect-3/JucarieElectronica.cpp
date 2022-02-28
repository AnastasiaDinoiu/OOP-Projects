#include "JucarieElectronica.h"

JucarieElectronica::JucarieElectronica(const string &denumire, double dimensiune, const string &tip, int numarBaterii)
        : Jucarie(denumire, dimensiune, tip), numarBaterii(numarBaterii) {}

istream &JucarieElectronica::citire(istream &is) {
    Jucarie::citire(is);
    cout << "numar baterii:";
    is >> numarBaterii;

    return is;
}

ostream &JucarieElectronica::afisare(ostream &os) const {
    Jucarie::afisare(os);
    os << "numar baterii: " << numarBaterii << "\n";
    return os;
}

