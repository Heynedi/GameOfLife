#ifndef GAMEOFLIFE_GRILLE_H
#define GAMEOFLIFE_GRILLE_H
#include <vector>
#include "cell.h"
#import <string>

namespace sf {
    class RenderWindow;
}

using namespace std;


class grid {
private:
    int row;
    int column;
    vector<vector<cell>> cells;

public:
    grid(int row, int column);
    void grid_fill(string data);
    string print_grid();
    cell& get_cell(int x, int y);
    vector<vector<cell>> get_cells();
    void show_grid(sf::RenderWindow &window);
};

#endif //GAMEOFLIFE_GRILLE_H