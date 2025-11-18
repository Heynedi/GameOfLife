#ifndef GRILLE_HPP
#define GRILLE_HPP

#include <vector>
#include <SFML/Graphics.hpp>
class Grille {
private:
    int lignes;
    int colonnes;
    std::vector<std::vector<char>> matrice; // Je crée une matrice composée de plusieurs lignes et chaque ligne contient plusieurs caractères.”

public:
    // Constructeur
    Grille(int lignes, int colonnes);

    // Affichage
    void afficher() const;
// le const : Cette méthode n’a pas le droit de modifier les attributs de l’objet.
    // Accesseurs
    int getLignes() const { return lignes; }
    int getColonnes() const { return colonnes; }
};

#endif
