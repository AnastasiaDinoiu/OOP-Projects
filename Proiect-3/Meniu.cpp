#include "Meniu.h"

Meniu *Meniu::_instance;

void Meniu::showOptions() {
    cout << "----------------------------\n";
    cout << "1. Adauga copii\n";
    cout << "2. Afisare copii\n";
    cout << "3. Gaseste copil dupa nume\n";
    cout << "4. Ordoneaza copiii dupa varsta\n";
    cout << "5. Ordoneaza copiii dupa numarul de fapte bune\n";
    cout << "6. Adauga fapte bune unui copil\n";
    cout << "7. Afisare raport jucarii\n";
    cout << "0. Iesire\n";
}

Meniu *Meniu::getInstance() {
    if (_instance == nullptr) {
        _instance = new Meniu();
    }
    return _instance;
}

void Meniu::adaugareCopii() {
    int opt, citireValida;

    cout << "Numarul de copii:";
    int numarCopii;
    cin >> numarCopii;

    shared_ptr<Copil> tempCopil;

    for (int i = 0; i < numarCopii; i++) {
        citireValida = 0;
        while (!citireValida) {
            cout << "Introduceti tipul copilului(1-cuminte, 2-neastamparat):";
            cin >> opt;
            citireValida = 1;

            try {
                if (opt == 1) {
                    tempCopil = make_shared<CopilCuminte>();
                } else if (opt == 2) {
                    tempCopil = make_shared<CopilNeastamparat>();
                } else {
                    throw opt;
                }
                tempCopil->citire(cin);
                copii.push_back(tempCopil);
            }
            catch (...) {
                cout << "Optiunea aleasa nu este corecta!\n";
                citireValida = 0;
            }
        }
    }
}

void Meniu::afisareCopii() {
    for (auto &copil: copii) {
        copil->afisare(cout);
    }
}

void Meniu::cautaCopil() {
    cout << "Introduceti numele cautat:";
    string nume;
    cin >> nume;

    size_t found;
    for (auto &copil: copii) {
        found = copil->getNume().find(nume);
        if (found != string::npos) {
            copil->afisare(cout);
        }
    }
}

void Meniu::ordonareVarsta() {
    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil> &a, const shared_ptr<Copil> &b) -> bool {
        return a->getVarsta() > b->getVarsta();
    });
}

void Meniu::ordonareFapteBune() {
    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil> &a, const shared_ptr<Copil> &b) -> bool {
        return a->getNumarFapteBune() < b->getNumarFapteBune();
    });
}

void Meniu::adaugaFapteBune() {
    int idCopil, numarFapteBuneNoi;
    cout << "ID-ul copilului:";
    cin >> idCopil;
    cout << "Numarul de fapte bune:";
    cin >> numarFapteBuneNoi;
    numarFapteBuneNoi = 2;

    //caut copilul cu ID-ul dat
    for (auto &copil: copii) {
        if (copil->getIdCopil() == idCopil) {
            copil->setNumarFapteBune(copil->getNumarFapteBune() + numarFapteBuneNoi);
            vector<shared_ptr<Jucarie>> jucarii = copil->getJucarii();

            //adaug numarFapteBuneNoi jucarii
            for (int i = 0; i < numarFapteBuneNoi; i++) {
                //creez o noua jucarie
                shared_ptr<Jucarie> tempJucarie;

                int opt, citireValida = 0;
                while (!citireValida) {
                    cout << "Introduceti tipul jucariei(1-clasica, 2-educativa, 3-electronica, 4-moderna):";
                    cin >> opt;
                    citireValida = 1;

                    try {
                        if (opt == 1) {
                            tempJucarie = make_shared<JucarieClasica>();
                        } else if (opt == 2) {
                            tempJucarie = make_shared<JucarieEducativa>();
                        } else if (opt == 3) {
                            tempJucarie = make_shared<JucarieElectronica>();
                        } else if (opt == 4) {
                            tempJucarie = make_shared<JucarieModerna>();
                        } else {
                            throw opt;
                        }
                        tempJucarie->citire(cin);
                        jucarii.push_back(tempJucarie);
                    }
                    catch (...) {
                        citireValida = 0;
                        cout << "Optiunea aleasa nu este corecta!\n";
                    }
                }
            }
            copil->setJucarii(jucarii);
        }
    }
}

void Meniu::raportJucarii() {
    int numarJucarii = 0;
    int frecventaJucarii[4] = {0, 0, 0, 0};

    for (auto &copil: copii) {
        vector<shared_ptr<Jucarie>> jucarii = copil->getJucarii();
        numarJucarii += jucarii.size();

        for (auto &jucarie: jucarii) {
            if (dynamic_pointer_cast<JucarieClasica>(jucarie))
                frecventaJucarii[0]++;
            if (dynamic_pointer_cast<JucarieEducativa>(jucarie))
                frecventaJucarii[1]++;
            if (dynamic_pointer_cast<JucarieElectronica>(jucarie))
                frecventaJucarii[2]++;
            if (dynamic_pointer_cast<JucarieModerna>(jucarie))
                frecventaJucarii[3]++;
        }
    }
    cout << "Numarul total de jucarii este " << numarJucarii << " dintre care " << frecventaJucarii[0] << " sunt clasice, "
         << frecventaJucarii[1] << " sunt educative, " << frecventaJucarii[2] << " sunt electronice, " << frecventaJucarii[3]
         << " sunt moderne.\n";
}

void Meniu::showMenu() {
    cout << "Alegeti o optiune din meniul de mai jos:\n";
    showOptions();

    cout << "\nOptiune:";
    cin >> optiune;

    while (optiune) {
        if (optiune == 1) {
            adaugareCopii();
        } else if (optiune == 2) {
            afisareCopii();
        } else if (optiune == 3) {
            cautaCopil();
        } else if (optiune == 4) {
            ordonareVarsta();
        } else if (optiune == 5) {
            ordonareFapteBune();
        } else if (optiune == 6) {
            adaugaFapteBune();
        } else if (optiune == 7) {
            raportJucarii();
        } else {
            cout << "Optiunea aleasa nu este corecta!\n";
        }

        cout << "\n";
        showOptions();
        cout << "\nOptiune:";
        cin >> optiune;
    }
}

void Meniu::setCopii(const vector<shared_ptr<Copil>> &_copii) {
    Meniu::copii = _copii;
}