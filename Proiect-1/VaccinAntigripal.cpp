#include "VaccinAntigripal.h"

VaccinAntigripal::VaccinAntigripal(float pret, float temperaturaDepozitare, const vector<string> &substante,
                                   const string &numeProducator, const string &tulpina, bool respectaRecomandari)
        : Vaccin(pret, temperaturaDepozitare, substante, numeProducator), tulpina(tulpina),
          respectaRecomandari(respectaRecomandari) {}

istream &VaccinAntigripal::citire(istream &is) {
    Vaccin::citire(is);
    cout << "tulpina:";
    is >> tulpina;

    cout << "respectaRecomandari:";
    is >> respectaRecomandari;

    return is;
}

ostream &VaccinAntigripal::afisare(ostream &os) const {
    Vaccin::afisare(os);
    os << "tulpina: " << tulpina << "\n";
    os << "respectaRecomandari: " << boolalpha << respectaRecomandari << "\n";

    return os;
}

void VaccinAntigripal::afisareSchemaVaccinare() {
Vaccin::afisareSchemaVaccinare();

cout << "Vaccinul antigripal se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti o doza ";
cout << "de 0.3 ml, repetandu-se din 2 in 2 ani.\n";
}