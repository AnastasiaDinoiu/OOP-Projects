#include "JucarieClasica.h"

JucarieClasica::JucarieClasica(const string &denumire, double dimensiune, const string &tip, const string &material,
                               const string &culoare) : Jucarie(denumire, dimensiune, tip), material(material),
                                                        culoare(culoare) {}

istream &JucarieClasica::citire(istream &is) {
    Jucarie::citire(is);
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "material:";
    getline(is, material);

    cout << "culoare:";
    getline(is, culoare);

    return is;
}

ostream &JucarieClasica::afisare(ostream &os) const {
    Jucarie::afisare(os);
    os << "material: " << material << "\n";
    os << "culoare: " << culoare << "\n";

    return os;
}
