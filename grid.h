#ifndef GAMEOFLIFE_V2_GRID_H
#define GAMEOFLIFE_V2_GRID_H
#include <string>
#include <vector>

#include "cell.h"

using namespace std;


class grid {
protected:
    int row;
    int column;
    vector<vector<cell*>> cells;
public:

    grid(int row, int column);
    ~grid() = default;
    void copy_grid_shape(grid* grid_to_copy);
    cell* get_cell(int x, int y);
    vector<vector<cell*>>* get_cells();
    void grid_fill(string data);
    string print_grid();
    void reset();
};


#endif //GAMEOFLIFE_V2_GRID_H