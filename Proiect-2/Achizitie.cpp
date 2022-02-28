#include "Achizitie.h"

Achizitie::Achizitie(int zi, int luna, int an, const string &numeClient, const vector<Dezinfectant *> &dezinfectanti,
          const vector<Masca *> &masti) : zi(zi), luna(luna), an(an), numeClient(numeClient),
                                          dezinfectanti(dezinfectanti), masti(masti) {}

Achizitie::Achizitie(int zi, int luna, int an, const string &numeClient) : zi(zi), luna(luna), an(an),
                                                                numeClient(numeClient) {}

int Achizitie::getZi() const {
    return zi;
}

int Achizitie::getLuna() const {
    return luna;
}

int Achizitie::getAn() const {
    return an;
}

const string &Achizitie::getNumeClient() const {
    return numeClient;
}

void Achizitie::setTotalComanda() {
    int _totalComanda = 0;
    for (auto &dezinfecant: dezinfectanti)
        _totalComanda += dezinfecant->pret();
    for (auto &masca: masti)
        _totalComanda += masca->pret();

    this->totalComanda = _totalComanda;
}

int Achizitie::getTotalComanda() const {
    return totalComanda;
}

const vector<Dezinfectant *> &Achizitie::getDezinfectanti() const {
    return dezinfectanti;
}

const vector<Masca *> &Achizitie::getMasti() const {
    return masti;
}

istream &operator>>(istream &is, Achizitie &achizitie) {
    achizitie.citire(is);
    return is;
}

ostream &operator<<(ostream &os, const Achizitie &achizitie) {
    achizitie.afisare(os);
    return os;
}

istream &Achizitie::citire(istream &is) {
    cout << "Zi:";
    is >> zi;
    cout << "Luna:";
    is >> luna;
    cout << "An:";
    is >> an;

    cout << "Nume client:";
    is >> numeClient;

    int numarDezinfectanti;
    cout << "Numarul de dezinfectanti:";
    is >> numarDezinfectanti;
    for (int i = 0; i < numarDezinfectanti; i++) {
        cout << "Dezinfectantul " << i + 1 << " :";
        cout << "Introduceti dezinfectantul dorit ";
        cout << "(1. DezinfectantBacterii; 2. DezinfectantVirusuri; 3. DezinfectantFungi):";

        int optiune2;
        is >> optiune2;

        if (optiune2 == 1) {
            auto *temp = new DezinfectantBacterii;
            is >> *temp;
            dezinfectanti.push_back(temp);
        } else if (optiune2 == 2) {
            auto *temp = new DezinfectantVirusuri;
            is >> *temp;
            dezinfectanti.push_back(temp);
        } else if (optiune2 == 3) {
            auto *temp = new DezinfectantFungi;
            is >> *temp;
            dezinfectanti.push_back(temp);
        }
    }

    int numarMasti;
    cout << "Numarul de masti:";
    is >> numarMasti;
    for (int i = 0; i < numarMasti; i++) {
        cout << "Masca " << i + 1 << " :";
        cout << "Introduceti masca dorita ";
        cout << "(1. MascaChirurgicala; 2. MascaPolicarbonat):";

        int optiune2;
        is >> optiune2;

        if (optiune2 == 1) {
            auto *temp = new MascaChirurgicala;
            is >> *temp;
            masti.push_back(temp);
        } else if (optiune2 == 2) {
            auto *temp = new MascaPolicarbonat;
            is >> *temp;
            masti.push_back(temp);
        }
    }

    return is;
}

ostream &Achizitie::afisare(ostream &os) const {
    os << "Data: " << zi << "/" << luna << "/" << an << "\n";

    os << "Nume client: " << numeClient << "\n";

    for (auto &dezinfectant: dezinfectanti)
        os << dezinfectant << " ";
    os << "\n";

    for (auto &masca: masti)
        os << masca << " ";
    os << "\n";

    return os;
}