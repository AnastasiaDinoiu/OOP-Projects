#include "MascaChirurgicala.h"

MascaChirurgicala::MascaChirurgicala(const string &culoare, unsigned int numarPliuri) : culoare(culoare),
                                                                                        numarPliuri(numarPliuri) {}

istream &MascaChirurgicala::citire(istream &is) {
    Masca::citire(is);

    cout << "Culoare:";
    is >> culoare;

    cout << "Numar pliuri";
    is >> numarPliuri;

    return is;
}

ostream &MascaChirurgicala::afisare(ostream &os) const {
    Masca::afisare(os);

    os << "Culoare: " << culoare << "\n";
    os << "Numar pliuri: " << numarPliuri << "\n";

    return os;
}

int MascaChirurgicala::pret() {
    if (tipProtectie == "ffp1")
        return 5;
    else if (tipProtectie == "ffp2")
        return 10;
    else if (tipProtectie == "ffp3")
        return 15;
}