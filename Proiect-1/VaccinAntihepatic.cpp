#include "VaccinAntihepatic.h"

VaccinAntihepatic::VaccinAntihepatic(float pret, float temperaturaDepozitare, const vector<string> &substante,
                                     const string &numeProducator, const string &tipHepatita,
                                     const string &modVaccinare) : Vaccin(pret, temperaturaDepozitare, substante,
                                                                          numeProducator), tipHepatita(tipHepatita),
                                                                   modVaccinare(modVaccinare) {}

istream &VaccinAntihepatic::citire(istream &is) {
    Vaccin::citire(is);
    cout << "tipHepatita:";
    is >> tipHepatita;

    cout << "modVaccinare:";
    is >> modVaccinare;

    return is;
}

ostream &VaccinAntihepatic::afisare(ostream &os) const {
    Vaccin::afisare(os);
    cout << "tipHepatita:" << tipHepatita << "\n";
    cout << "modVaccinare:" << modVaccinare << "\n";

    return os;
}

void VaccinAntihepatic::afisareSchemaVaccinare() {
Vaccin::afisareSchemaVaccinare();

cout << "Vaccinul antihepatita A si B, la copii cu varsta mai mica de 1 an se adminstreaza 2 ";
cout
<< "injectari la un interval de o luna, a treia injectare dupa 6 luni de la prima administrare, la adulti\n";
cout
<< "conform schemei de imunizare recomandata de medic; cel Antihepatita C doar la recomandarea medicului.\n";
}


