#include "CopilCuminte.h"

CopilCuminte::CopilCuminte(const string &nume, const string &prenume, const string &adresa, int varsta,
                           int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii, int numarDulciuri)
        : Copil(nume, prenume, adresa, varsta, numarFapteBune, jucarii),
          numarDulciuri(numarDulciuri) {}

istream &CopilCuminte::citire(istream &is) {
    Copil::citire(is);
    cout << "numarDulciuri:";
    is >> numarDulciuri;

    return is;
}

ostream &CopilCuminte::afisare(ostream &os) const {
    Copil::afisare(os);
    os << "numarDulciuri: " << numarDulciuri << "\n";

    return os;
}