#include <iostream>
#include "grille.hpp"

int main() {
    int l, c;

    std::cout << "Entrez le nombre de lignes : ";
    std::cin >> l;

    std::cout << "Entrez le nombre de colonnes : ";
    std::cin >> c;

    Grille grille(l, c);

    std::cout << "\nVoici votre grille :\n";
    grille.afficher();

    return 0;
}
