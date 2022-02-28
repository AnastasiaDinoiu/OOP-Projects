#include "JucarieModerna.h"

JucarieModerna::JucarieModerna(const string &denumire, double dimensiune, const string &tip, const string &brand,
                               const string &model) : Jucarie(denumire, dimensiune, tip),
                                                      JucarieEducativa(denumire, dimensiune, tip, "generala"),
                                                      JucarieElectronica(denumire, dimensiune, tip, 1),
                                                      brand(brand), model(model) {}

istream &JucarieModerna::citire(istream &is) {
    cout << "denumire:";
    is >> denumire;

    cout << "dimensiune:";
    is >> dimensiune;

    cout << "tip:";
    is >> tip;

    cout << "brand:";
    is >> brand;

    cout << "model:";
    is >> model;

    abilitate = "generala";
    numarBaterii = 1;

    return is;
}

ostream &JucarieModerna::afisare(ostream &os) const {
    JucarieEducativa::afisare(os);
    os << "numarBaterii: " << numarBaterii << "\n";
    os << "brand: " << brand << "\n";
    os << "model: " << model << "\n";

    return os;
}
