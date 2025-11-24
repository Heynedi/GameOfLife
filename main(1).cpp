#include <iostream>
#include "grille.hpp"
#include <SFML/Graphics.hpp>

int main() {
    // Taille par défaut : 30 lignes, 31 colonnes
    const int lignes = 30;
    const int colonnes = 31;
    const int cellSize = 20;  // Doit correspondre à celle dans Grille et permet de mettre la taille de la case

    Grille grille(lignes, colonnes);

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode({// sf::VideoMode définit la taille de la fenêtre (largeur, hauteur)
        static_cast<unsigned int>(colonnes * cellSize), // Ici, on calcule dynamiquement la taille pour s'adapter à la grille Largeur = nombre de colonnes * taille d'une cellule ,Hauteur = nombre de lignes * taille d'une cellule
        static_cast<unsigned int>(lignes * cellSize) // on change en unsigned int car la fonction attend ceci
    }), "Jeu de la Vie - Grille");// nom qui est affiché dans le haut de la grille

    while (window.isOpen()) { // boucle pour savoir quand la fenetre est encore ouverte
        while (const std::optional event = window.pollEvent()) { // permet de gérer les évènements (clicks ou autre...) et le stocke dans event
            if (event->is<sf::Event::Closed>())// si l'event est de fermer la fenetre alors on ferme la fenetre
                window.close();
        }

        // Appel à la méthode d'affichage de la grille
        grille.afficherSFML(window);
    }

    return 0;
}
