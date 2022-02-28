#include "Meniu.h"

using namespace std;


int main() {
    Meniu *meniu = Meniu::getInstance();
    meniu->showMenu();

    return 0;
}
