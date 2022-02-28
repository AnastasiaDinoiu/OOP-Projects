#include "Dezinfectant.h"

Dezinfectant::Dezinfectant(int organismeUcise, const vector<string> &ingrediente, const vector<string> &tipuriSuprafata)
        : organismeUcise(organismeUcise), ingrediente(ingrediente), tipuriSuprafata(tipuriSuprafata) {}

void Dezinfectant::setOrganismeUcise(int _organismeUcise) {
    Dezinfectant::organismeUcise = _organismeUcise;
}

const vector<string> &Dezinfectant::getIngrediente() const {
    return ingrediente;
}

void Dezinfectant::setIngrediente(const vector<string> &ingrediente) {
    Dezinfectant::ingrediente = ingrediente;
}

istream &operator>>(istream &is, Dezinfectant &dezinfectant) {
    dezinfectant.citire(is);
    return is;
}

ostream &operator<<(ostream &os, const Dezinfectant &dezinfectant) {
    dezinfectant.afisare(os);
    return os;
}

istream &Dezinfectant::citire(istream &is) {
    cout << "Organisme ucise:";
    is >> organismeUcise;

    string temp;
    int numarIngrediente;
    cout << "Numarul de ingrediente:";
    cin >> numarIngrediente;
    for (int i = 0; i < numarIngrediente; i++) {
        cout << "Ingredientul " << i + 1 << " :";
        is >> temp;
        ingrediente.push_back(temp);
    }

    int numarTipuriSuprafata;
    cout << "Numarul de tipuri de suprafata:";
    cin >> numarTipuriSuprafata;
    for (int i = 0; i < numarTipuriSuprafata; i++) {
        cout << "Tipul de suprafata " << i + 1 << " :";
        is >> temp;
        tipuriSuprafata.push_back(temp);
    }

    return is;
}

ostream &Dezinfectant::afisare(ostream &os) const {
    os << "Organisme ucise: " << organismeUcise << "\n";

    os << "Ingrediente: ";
    for (auto &ingredient: ingrediente)
        os << ingredient << " ";
    os << "\n";

    os << "Tipurile de suprafata: ";
    for (auto &tipSuprafata: tipuriSuprafata)
        os << tipSuprafata << " ";
    os << "\n";

    return os;
}

double Dezinfectant::eficienta() {
    return 0;
}

int Dezinfectant::pret() {
    if (eficienta() < 0.9)
        return 10;
    else if (eficienta() < 0.95)
        return 20;
    else if (eficienta() < 0.975)
        return 30;
    else if (eficienta() < 0.99)
        return 40;
    return 50;
}
