#include "Vaccin.h"

Vaccin::Vaccin(float pret, float temperaturaDepozitare, const vector<string> &substante, const string &numeProducator)
        : pret(pret), temperaturaDepozitare(temperaturaDepozitare), substante(substante),
          numeProducator(numeProducator) {}

istream &operator>>(istream &is, Vaccin &vaccin) {
    vaccin.citire(is);
    return is;
}

istream &Vaccin::citire(istream &is) {
    cout << "pret:";
    is >> pret;

    cout << "temperaturaDepozitare:";
    is >> temperaturaDepozitare;

    cout << "numarul de substante:";
    int numarSubstante;
    is >> numarSubstante;

    for (int i = 0; i < numarSubstante; i++) {
        cout << "substanta " << i + 1 << " :";
        string tempSubstanta;
        is >> tempSubstanta;
        substante.push_back(tempSubstanta);
    }

    cout << "numele producatorului:";
    is >> numeProducator;

    return is;
}

ostream &operator<<(ostream &os, const Vaccin &vaccin) {
    vaccin.afisare(os);
    return os;
}

ostream &Vaccin::afisare(ostream &os) const {
    os << "pret: " << pret << "\n";
    os << "temperaturaDepozitare: " << temperaturaDepozitare << "\n";
    os << "substante: ";
    for (auto &substanta: substante) {
        os << substanta << " ";
    }
    os << "\n";
    os << "numeProducator: " << numeProducator << "\n";

    return os;
}

float Vaccin::getPret() const {
    return pret;
}

const string &Vaccin::getNumeProducator() const {
    return numeProducator;
}



