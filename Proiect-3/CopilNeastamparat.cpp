#include "CopilNeastamparat.h"

CopilNeastamparat::CopilNeastamparat(const string &nume, const string &prenume, const string &adresa, int varsta,
                                     int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii, int numarCarbuni)
        : Copil(nume, prenume, adresa, varsta, numarFapteBune, jucarii),
          numarCarbuni(numarCarbuni) {}

istream &CopilNeastamparat::citire(istream &is) {
    Copil::citire(is);
    cout << "numarCarbuni:";
    is >> numarCarbuni;

    return is;
}

ostream &CopilNeastamparat::afisare(ostream &os) const {
    Copil::afisare(os);
    os << "numarCarbuni: " << numarCarbuni << "\n";

    return os;
}
