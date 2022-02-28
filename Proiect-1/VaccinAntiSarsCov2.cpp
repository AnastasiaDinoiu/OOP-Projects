#include "VaccinAntiSarsCov2.h"

VaccinAntiSarsCov2::VaccinAntiSarsCov2(float pret, float temperaturaDepozitare, const vector<string> &substante,
                                       const string &numeProducator, const vector<string> &reactiiAdverse,
                                       float rataEficienta, const vector<string> &medicamenteContraindicate) : Vaccin(
        pret, temperaturaDepozitare, substante, numeProducator), reactiiAdverse(reactiiAdverse), rataEficienta(
        rataEficienta), medicamenteContraindicate(medicamenteContraindicate) {}

istream &VaccinAntiSarsCov2::citire(istream &is) {
    Vaccin::citire(is);
    cout << "numarul de reactii adverse:";
    int numarReactiiAdverse;
    is >> numarReactiiAdverse;

    for (int i = 0; i < numarReactiiAdverse; i++) {
        cout << "reactia adversa " << i + 1 << " :";
        string tempReactieAdversa;
        is >> tempReactieAdversa;
        reactiiAdverse.push_back(tempReactieAdversa);
    }

    cout << "rataEficienta:";
    is >> rataEficienta;

    cout << "numarul de medicamente contraindicate:";
    int numarMedContraindicate;
    is >> numarMedContraindicate;

    for (int i = 0; i < numarMedContraindicate; i++) {
        cout << "medicamentul contraindicat " << i + 1 << " :";
        string tempMedContraindicat;
        is >> tempMedContraindicat;
        medicamenteContraindicate.push_back(tempMedContraindicat);
    }

    return is;
}

ostream &VaccinAntiSarsCov2::afisare(ostream &os) const {
    Vaccin::afisare(os);
    os << "reactii adverse: ";
    for (auto &reactieAdversa: reactiiAdverse) {
        os << reactieAdversa << " ";
    }
    cout << "\n";

    os << "rataEficienta: " << rataEficienta << "\n";

    os << "medicamente contraindicate: ";
    for (auto &medContraindicat: medicamenteContraindicate) {
        os << medContraindicat << " ";
    }
    cout << "\n";

    return os;
}

void VaccinAntiSarsCov2::afisareSchemaVaccinare() {
Vaccin::afisareSchemaVaccinare();

cout << "Vaccinul anti Sars-Cov2 se administreaza persoanelor cu varsta de peste 16 ani, ";
cout << "2 doze la o perioada de 21 zile.\n";
}

