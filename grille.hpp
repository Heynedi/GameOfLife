#ifndef GRILLE_HPP
#define GRILLE_HPP
#include <vector>
#include <SFML/Graphics.hpp>

class Grille {
private:
    int lignes;
    int colonnes;
    std::vector<std::vector<bool>> matrice;  // Bool pour vivant (true) ou mort (false)
    const int cellSize = 20;  // Taille d'un carré en pixels

public:
    Grille(int lignes, int colonnes);
    void afficherSFML(sf::RenderWindow &window) const;
    int getLignes() const { return lignes; }
    int getColonnes() const { return colonnes; }
};

#endif
