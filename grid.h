#ifndef GAMEOFLIFE_GRILLE_H
#define GAMEOFLIFE_GRILLE_H
#include <vector>
#include "cell.h"
#import <string>
using namespace std;


class grid {
private:
    int row;
    int column;
    vector<vector<cell>> cells;

public:
    grid(int row, int column);
    void grid_fill(string data);
    void print_grid();
};

#endif //GAMEOFLIFE_GRILLE_H