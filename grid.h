#ifndef GAMEOFLIFE_GRILLE_H
#define GAMEOFLIFE_GRILLE_H
#include <vector>


class grid {
private:
    int longueur;
    int largeur;
    std::vector<std::vector<cell>> cells;

public:
    grid(int longueur, int largeur);
    void fill_grid();
};


#endif //GAMEOFLIFE_GRILLE_H