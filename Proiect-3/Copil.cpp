#include "Copil.h"

int Copil::staticIdCopil = 0;

Copil::Copil(const string &nume, const string &prenume, const string &adresa, int varsta,
      int numarFapteBune, const vector<shared_ptr<Jucarie>> &jucarii) : idCopil(++staticIdCopil), nume(nume),
                                                                        prenume(prenume), adresa(adresa),
                                                                        varsta(varsta),
                                                                        numarFapteBune(numarFapteBune),
                                                                        jucarii(jucarii) {}

const int Copil::getIdCopil() const {
    return idCopil;
}

const string &Copil::getNume() const {
    return nume;
}

int Copil::getVarsta() const {
    return varsta;
}

int Copil::getNumarFapteBune() const {
    return numarFapteBune;
}

void Copil::setNumarFapteBune(int _numarFapteBune) {
    Copil::numarFapteBune = _numarFapteBune;
}

const vector<shared_ptr<Jucarie>> &Copil::getJucarii() const {
    return jucarii;
}

void Copil::setJucarii(const vector<shared_ptr<Jucarie>> &_jucarii) {
    Copil::jucarii = _jucarii;
}

istream &operator>>(istream &is, Copil &copil) {
    copil.citire(is);
    return is;
}

istream &Copil::citire(istream &is) {
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "nume: ";
    getline(is, nume);

    cout << "prenume: ";
    getline(is, prenume);

    cout << "adresa: ";
    getline(is, adresa);

    cout << "varsta: ";
    is >> varsta;

    cout << "numarFapteBune: ";
    is >> numarFapteBune;

    for (int i = 0; i < numarFapteBune; i++) {
        shared_ptr<Jucarie> tempJucarie;
        int opt, citireValida;
        cout << "Jucaria " << i + 1 << ":\n";

        citireValida = 0;
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

    return is;
}

ostream &operator<<(ostream &os, const Copil &copil) {
    copil.afisare(os);
    return os;
}

ostream &Copil::afisare(ostream &os) const {
    os << "idCopil: " << idCopil << "\n";
    os << "nume: " << nume << "\n";
    os << "prenume: " << prenume << "\n";
    os << "adresa: " << adresa << "\n";
    os << "varsta: " << varsta << "\n";
    os << "numarFapteBune: " << numarFapteBune << "\n";
    os << "jucarii:\n";
    int i = 0;
    for (auto &jucarie: jucarii) {
        i++;
        os << "\tjucaria " << i << " :\n";
        os << *jucarie;
    }

    return os;
}


