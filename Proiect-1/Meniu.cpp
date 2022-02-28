#include "Meniu.h"

Meniu *Meniu::_instance;

void Meniu::arataOptiuni() {
    cout << "----------------------------\n";
    cout << "1. Adaugarea unui vaccin nou\n";
    cout << "2. Afisarea tuturor vaccinurilor pe care le detine\n";
    cout << "3. Numele producatorilor pentru toate vaccinurile\n";
    cout << "4. Adaugarea unei comenzi\n";
    cout << "5. Afisarea tuturor comenzilor\n";
    cout << "6. Valorea comenzilor dintr-o anumita zi\n";
    cout << "7. Afisarea schemei de vaccinare pentru un anumit tip de vaccin\n";
    cout << "8. Exportul comenzilor intr-un fisier .txt\n";
    cout << "0. Iesire\n";
}

Meniu *Meniu::getInstance() {
    if (_instance == nullptr)
        _instance = new Meniu;
    return _instance;
}

void Meniu::adaugareVaccin() {
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
            tempVaccin->citire(cin);
            vaccinuri.push_back(tempVaccin);
        }
        catch (...) {
            cout << "Optiunea este invalida!\n";
            citireValida = 0;
        }
    }
}

void Meniu::afisareVaccinuri() {
    if (vaccinuri.empty())
        cout << "Nu s-au inregistrat vaccinuri!\n";

    int i = 1;
    for (auto &vaccin: vaccinuri) {
        cout << "\n\tvaccinul " << i << " :\n" << *vaccin << "\n";
    }
}

void Meniu::afisareProducatori() {
    int i = 1;

    cout << "numele producatorilor:\n";
    for (auto &vaccin: vaccinuri) {
        cout << "vaccinul " << i << " : " << vaccin->getNumeProducator() << "\n";
    }
}

void Meniu::adaugareComanda() {
    shared_ptr<Comanda> tempComanda = make_shared<Comanda>();
    tempComanda->citire(cin);
    comenzi.push_back(tempComanda);
}

void Meniu::afisareComenzi() {
    if (comenzi.empty())
        cout << "Nu s-au inregistrat comenzi!\n";

    for (auto &comanda: comenzi) {
        cout << *comanda;
    }
}

void Meniu::comenziValoareZi() {
    cout << "introduceti ziua:";
    int zi;
    cin >> zi;

    float valoareZi = 0;

    for (auto &comanda: comenzi) {
        if (comanda->getData().zi == zi) {
            for (auto &vaccin: comanda->getVaccinuri()) {
                valoareZi += vaccin.vaccin->getPret() * (float) vaccin.cantitate;
            }
        }
    }

    cout << "Valoarea comenzilor din ziua " << zi << " este de " << valoareZi << " lei." << "\n";
}

void Meniu::afisareSchema() {
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
            tempVaccin->afisareSchemaVaccinare();
        }
        catch (...) {
            cout << "Optiunea este invalida!\n";
            citireValida = 0;
        }
    }
}

void Meniu::exportFisier() {
    ofstream fout("comenzi.txt");
    for (auto &comanda: comenzi) {
        fout << "idComanda: " << comanda->getIdComanda() << "\n";
        fout << "data: " << comanda->getData().zi << "/" << comanda->getData().luna << "/" << comanda->getData().an << "\n";
        fout << "numeClient: " << comanda->getNumeClient() << "\n";
        int i = 1;
        for (auto &vaccin: comanda->getVaccinuri()) {
            fout << "vaccinul " << i << " : " << vaccin.vaccin->getPret() << " lei, " << vaccin.cantitate
                 << " bucati\n";
        }
    }

    fout.close();
}

void Meniu::arataMeniu() {
    cout << "Introduceti o optiune din meniul de mai jos:\n";
    arataOptiuni();

    cout << "Optiune:";
    cin >> optiune;

    while (optiune) {
        if (optiune == 1) {
            adaugareVaccin();
        } else if (optiune == 2) {
            afisareVaccinuri();
        } else if (optiune == 3) {
            afisareProducatori();
        } else if (optiune == 4) {
            adaugareComanda();
        } else if (optiune == 5) {
            afisareComenzi();
        } else if (optiune == 6) {
            comenziValoareZi();
        } else if (optiune == 7) {
            afisareSchema();
        } else if (optiune == 8) {
            exportFisier();
        } else {
            cout << "Optiunea introdusa nu este corecta!\n";
        }
        arataOptiuni();
        cout << "Optiune:";
        cin >> optiune;
    }
}