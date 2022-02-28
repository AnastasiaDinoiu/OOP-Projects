#include "Stoc.h"

Stoc *Stoc::_instance;

void Stoc::showOptions() {
    cout << "1. Adauga un nou dezinfectant in stoc" << "\n";
    cout << "2. Adauga o noua masca in stoc" << "\n";
    cout << "3. Adauga o noua achizitie" << "\n";
    cout << "4. Afiseaza dezinfectantul cel mai eficient" << "\n";
    cout << "5. Calculeaza venitul dintr-o anumita luna" << "\n";
    cout << "6. Calculeaza venitul obtinut din mastile chirurgicale cu model" << "\n";
    cout << "7. Modifica reteta unui dezinfectant, modificand unul sau mai multe ingrediente" << "\n";
    cout << "8. Afiseaza cel mai fidel client" << "\n";
    cout << "9. Afiseaza ziua cu cele mai slabe venituri, de la deschidere pana in prezent" << "\n";
    cout << "10.Calculeaza TVA-ul (19% din venituri) care trebuie returnat la ANAF pentru un anumit an" << "\n";
    cout << "0. Iesire" << "\n";
}

Stoc *Stoc::getInstance() {
    if (_instance == nullptr) {
        _instance = new Stoc();
    }
    return _instance;
}

Stoc::~Stoc() {
    for (auto &masca: masti) {
        delete masca;
    }
    for (auto &dezinfectant: dezinfectanti) {
        delete dezinfectant;
    }
    for (auto &achizitie: achizitii) {
        delete achizitie;
    }
}

void Stoc::adaugaDezinfectant(vector<Dezinfectant *> &dezinfectant) {
    cout << "Introduceti dezinfectantul dorit ";
    cout << "(1. DezinfectantBacterii; 2. DezinfectantVirusuri; 3. DezinfectantFungi):";

    int optiune2;
    cin >> optiune2;

    if (optiune2 == 1) {
        auto *temp = new DezinfectantBacterii;
        cin >> *temp;
        dezinfectanti.push_back(temp);
    } else if (optiune2 == 2) {
        auto *temp = new DezinfectantVirusuri;
        cin >> *temp;
        dezinfectanti.push_back(temp);
    } else if (optiune2 == 3) {
        auto *temp = new DezinfectantFungi;
        cin >> *temp;
        dezinfectanti.push_back(temp);
    }
}

void Stoc::adaugaMasca(vector<Masca *> &masca) {
    cout << "Introduceti masca dorita ";
    cout << "(1. MascaChirurgicala; 2. MascaPolicarbonat):";

    int optiune2;
    cin >> optiune2;

    if (optiune2 == 1) {
        auto *temp = new MascaChirurgicala;
        cin >> *temp;
        masti.push_back(temp);
    } else if (optiune2 == 2) {
        auto *temp = new MascaPolicarbonat;
        cin >> *temp;
        masti.push_back(temp);
    }

}

void Stoc::adaugaAchizitie(vector<Achizitie *> &achizitie) {
    auto *temp = new Achizitie;
    cin >> *temp;
    achizitii.push_back(temp);
}

void Stoc::dezinfectantEficient() {
    if (dezinfectanti.empty()) {
        cout << "Nu este inregistrat niciun dezinfectant!\n";
        return;
    }

    float max = 0.;
    int indice = 0, maxIndice = 0;

    for (auto &dezinfectant: dezinfectanti) {
        if (dezinfectant->eficienta() > max) {
            maxIndice = indice;
        }
        indice++;
    }
    cout << "Cel mai eficient dezinfectant din stoc:\n" << *dezinfectanti[maxIndice] << "\n";
}

void Stoc::venitLuna() {
    int luna;
    cout << "Introduceti luna (numar):";
    cin >> luna;

    if (achizitii.empty()) {
        cout << "Nu este inregistrata nicio achizitie!\n";
        return;
    }

    int venitLuna = 0;
    for (auto &achizitie: achizitii) {
        if (achizitie->getLuna() == luna) {
            for (auto &dezinfecant: achizitie->getDezinfectanti())
                venitLuna += dezinfecant->pret();
            for (auto &masca: achizitie->getMasti())
                venitLuna += masca->pret();
        }
    }
    cout << "Venitul din luna " << luna << " este de: " << venitLuna << "\n";
}

void Stoc::venitMastiChirurgicale() {
    if (masti.empty()) {
        cout << "Nu este inregistrata nicio masca!\n";
        return;
    }

    int venitMastiChirurgicale = 0;
    for (auto &masca: masti) {
        if (dynamic_cast<MascaChirurgicala *>(masca))
            venitMastiChirurgicale += masca->pret();
    }
    cout << "Venitul obtinut din mastile chirurgicale: " << venitMastiChirurgicale << "\n";
}

void Stoc::optiuniModificareIngredient() {
    cout << "1. Modificare ingredient\n";
    cout << "0. Iesire\n";
}

void Stoc::moficaIngredient() {
    //afisare dezinfectanti
    int indice = 0;
    for (auto &dezinfectant: dezinfectanti) {
        cout << "\tDezinfectantul " << indice + 1 << ":\n" << *dezinfectant;
        indice++;
    }

    //aflarea dezinfectantului care va fi modificat
    cout << "\nIntroduceti numarul dezinfectantului care va fi modificat:";
    cin >> indice;
    indice--;
    optiuniModificareIngredient();
    cin >> optiune;

    //cat timp se doreste sa se modifice reteta dezinfectantului
    while (optiune) {

        //afisarea dezinfectantului care va fi modificat
        if (optiune == 1) {
            cout << "\tDezinfectantul selectat:\n" << *dezinfectanti[indice] << "\n";

            //aflarea ingredientului care va fi sters
            cout << "Introduceti numarul ingredientului care va fi sters (numerotarea incepe de la 1):";
            int numarIngredient;
            cin >> numarIngredient;
            numarIngredient--;

            //sterg ingredientul
            vector<string> tempIngrediente = dezinfectanti[indice]->getIngrediente();
            tempIngrediente.erase(tempIngrediente.begin() + numarIngredient);
            dezinfectanti[indice]->setIngrediente(tempIngrediente);

            //modific numarul de ingrediente ucise
            cout << "Noul numar de organisme ucise:";
            int numarOrganismeUcise;
            cin >> numarOrganismeUcise;
            dezinfectanti[indice]->setOrganismeUcise(numarOrganismeUcise);

            //daca s-a ales o alta optiune, in afara de 0 sau 1
        } else {
            cout << "Optiunea aleasa nu este corecta!\n";
        }
        cout << "\n";
        optiuniModificareIngredient();
        cin >> optiune;
    }
}

void Stoc::clientFidel() {
    if (achizitii.empty()) {
        cout << "Nu este inregistrata nicio achizitie!\n";
        return;
    }

    int numarMaxAchizitii = 0, indiceClientFidel;
    int numarTempAchizitii;
    for (int i = 0; i < achizitii.size() - 1; i++) {
        numarTempAchizitii = 1;
        for (int j = i + 1; j < achizitii.size(); j++) {
            if (achizitii[i]->getNumeClient() == achizitii[j]->getNumeClient()) {
                numarTempAchizitii++;
            }
            if (numarTempAchizitii > numarMaxAchizitii) {
                numarMaxAchizitii = numarTempAchizitii;
                indiceClientFidel = j;
            }
        }
    }
    cout << "Cel mai fidel client este: " << achizitii[indiceClientFidel]->getNumeClient() << "\n";
}

void Stoc::ziVenitMic() {
    if (achizitii.empty()) {
        cout << "Nu este inregistrata nicio achizitie!\n";
        return;
    }

    sort(achizitii.begin(), achizitii.end(), [](const Achizitie *a, const Achizitie *b) {
        return a->getZi() < b->getZi();
    });

    int venitZilnic = 0, venitZilnicMinim = 0, indiceMinim;
    int zi = achizitii[0]->getZi();
    for (int i = 0; i < achizitii.size(); i++) {

        //se opreste cand ajunge la alta zi
        while (zi == achizitii[i]->getZi() && i < achizitii.size()) {
            achizitii[i]->setTotalComanda();
            venitZilnic += achizitii[i]->getTotalComanda();
            i++;
        }
        if (venitZilnic < venitZilnicMinim) {
            venitZilnicMinim = venitZilnic;
            indiceMinim = i - 1;
        }
        venitZilnic = 0;
        zi = achizitii[i]->getZi();
    }
    cout << "Ziua cu cele mai slabe venituri: " << achizitii[indiceMinim]->getZi() << "\n";
}

void Stoc::calculTVA() {
    int an;
    cout << "Introduceti anul:";
    cin >> an;

    if (achizitii.empty()) {
        cout << "Nu este inregistrata nicio achizitie!\n";
        return;
    }

    int venitAn = 0;
    for (auto &achizitie: achizitii) {
        if (an == achizitie->getAn()) {
            achizitie->setTotalComanda();
            venitAn += achizitie->getTotalComanda();
        }
    }
    double TVA = 0.19 * venitAn;
    cout << "TVA-ul din anul " << an << ": " << TVA;
}

void Stoc::afisareStoc() {
    cout << "Masti:\n";
    int i = 0;
    for (auto &masca: masti) {
        i++;
        cout << "\tMasca " << i << " :\n" << *masca << "\n";
    }

    cout << "Dezinfectante:\n";
    i = 0;
    for (auto &dezinfectant: dezinfectanti) {
        i++;
        cout << "\tDezinfectantul " << i << " :\n" << *dezinfectant << "\n";
    }
}

void Stoc::showMenu() {
    cout << "Alegeti o optiune din meniul de mai jos:\n";
    showOptions();

    cout << "\nOptiunea:";
    cin >> optiune;

    vector<string> ingrediente;
    vector<string> tipuriSuprafata;

    while (optiune) {
        if (optiune == 1) {
            adaugaDezinfectant(dezinfectanti);
        } else if (optiune == 2) {
            adaugaMasca(masti);
        } else if (optiune == 3) {
            adaugaAchizitie(achizitii);
        } else if (optiune == 4) {
            dezinfectantEficient();
        } else if (optiune == 5) {
            venitLuna();
        } else if (optiune == 6) {
            venitMastiChirurgicale();
        } else if (optiune == 7) {
            moficaIngredient();
        } else if (optiune == 8) {
            clientFidel();
        } else if (optiune == 9) {
            ziVenitMic();
        } else if (optiune == 10) {
            calculTVA();
        } else {
            cout << "Optiunea aleasa nu este corecta!\n";
        }

        cout << "\n";
        showOptions();
        cout << "\nOptiunea:";
        cin >> optiune;
    }
}