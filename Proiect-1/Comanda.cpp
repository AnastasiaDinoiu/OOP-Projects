#include "Comanda.h"

int Comanda::staticIdComanda = 0;

Comanda::Comanda(const int idComanda, const Data &data, const string &numeClient,
                 const vector<ComandaVaccin> &vaccinuri) : idComanda(idComanda), data(data), numeClient(numeClient),
                                                           vaccinuri(vaccinuri) {}

float Comanda::valoareTotalaComanda() {
    float valoareTotalaComanda = 0;
    for (auto &vaccin: vaccinuri) {
        valoareTotalaComanda += vaccin.vaccin->getPret() * (float) vaccin.cantitate;
    }

    return valoareTotalaComanda;
}

istream &operator>>(istream &is, Comanda &comanda) {
    comanda.citire(is);
    return is;
}

istream &Comanda::citire(istream &is) {
    cout << "zi:";
    is >> data.zi;

    cout << "luna:";
    is >> data.luna;

    cout << "an";
    is >> data.an;

    cout << "numeClient:";
    is >> numeClient;

    cout << "Introduceti numarul de vaccinuri:";
    int numarVaccinuri;
    is >> numarVaccinuri;

    for (int i = 0; i < numarVaccinuri; i++) {
        cout << "vaccinul " << i + 1 << " :\n";
        int opt, citireValida = 0;

        shared_ptr<Vaccin> tempVaccin;
        while (!citireValida) {
            cout << "Introduceti optiunea dorita(1-VaccinAntigripal, 2-VaccinSarsCov2, 3-VaccinAntihepatic):";
            cin >> opt;
            citireValida = 1;
            try {
                if (opt == 1) {
                    tempVaccin = make_shared<VaccinAntigripal>();
                } else if (opt == 2) {
                    tempVaccin = make_shared<VaccinAntiSarsCov2>();
                } else if (opt == 3) {
                    tempVaccin = make_shared<VaccinAntihepatic>();
                } else {
                    throw opt;
                }
                tempVaccin->citire(is);
                cout << "cantitatea:";
                int cantitate;
                cin >> cantitate;
                vaccinuri.push_back({tempVaccin, cantitate});
            }
            catch (...) {
                cout << "Optiunea este invalida!\n";
                citireValida = 0;
            }
        }
    }

    return is;
}

ostream &operator<<(ostream &os, const Comanda &comanda) {
    comanda.afisare(os);
    return os;
}

ostream &Comanda::afisare(ostream &os) const {
    os << "idComanda: " << idComanda << "\n";
    os << "data: " << data.zi << "/" << data.luna << "/" << data.an << "\n";
    os << "numeClient: " << numeClient << "\n";
    int i = 0;
    for (auto &vaccin: vaccinuri) {
        i++;
        os << "\tvaccinul " << i << ":\n" << *vaccin.vaccin << "cantitate:" << vaccin.cantitate << "\n";
    }

    return os;
}

const int Comanda::getIdComanda() const {
    return idComanda;
}

const Data &Comanda::getData() const {
    return data;
}

const string &Comanda::getNumeClient() const {
    return numeClient;
}

const vector<ComandaVaccin> &Comanda::getVaccinuri() const {
    return vaccinuri;
}


