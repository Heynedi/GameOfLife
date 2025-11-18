#include "grille.hpp"
#include <iostream>

// Constructeur : initialise la matrice avec des points '.' qui sont affiché dans la console
Grille::Grille(int l, int c) : lignes(l), colonnes(c) { // constructeur puis initialise les attributs avec les valeurs reçues
    matrice.resize(lignes, std::vector<char>(colonnes, '.')); //crée une matrice 2D de taille demandée remplie de .
}

void Grille::afficher() const {
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            std::cout << matrice[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
