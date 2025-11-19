#include "grille.hpp"
#include <iostream>
#include <random>  // Pour la génération aléatoire

Grille::Grille(int l, int c) : lignes(l), colonnes(c) {
    matrice.resize(lignes, std::vector<bool>(colonnes, false));

    // Génération aléatoire : environ 50% de true (vivantes)
    std::random_device rd;  // Source d'entropie
    std::mt19937 gen(rd());  // Générateur Mersenne Twister
    std::uniform_int_distribution<> dis(0, 1);  // Distribution 0 ou 1

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = dis(gen) == 1;  // true si 1, false si 0
        }
    }
}

void Grille::afficherSFML(sf::RenderWindow &window) const {
    // Efface la fenêtre avec du blanc donc efficace lorsqu'on affichera à la suite les grilles
    window.clear(sf::Color::Black);

    // configure un carré de taille cellSize , le -1 sert à mettre les contours entre les cases
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {// permet de parcourir entièrement la mactrice
            // permet de mettre la couleur donc si c'est true cela colorie la case en blanc sinon en noir
            cell.setFillColor(matrice[i][j] ? sf::Color::White : sf::Color::Black);

            // permet de savoir la position de la case
            cell.setPosition(sf::Vector2f(
                static_cast<float>(j * cellSize),// permet de transformer le int en float car la fonction Vector2f() demande un float
                static_cast<float>(i * cellSize)
            ));

            window.draw(cell);// permert de dessiner les cases dans la fenetre
        }
    }
    window.display(); // permet d'afficher la fenetre
}
