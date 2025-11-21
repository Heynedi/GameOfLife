#include "grid.h"

#include <iostream>
using namespace std;

grid::grid(int row, int column) {
    this->row = row;
    this->column = column;
    this->cells = vector<vector<cell>>(row, vector<cell>(column));
}

void grid::grid_fill(string data) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (data[i*column+j] == '1') {
                cells[i][j].birth();
            }
        }
    }
}

void grid::print_grid() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << cells[i][j].get_state();
        }
        cout << endl;
    }
}

cell& grid::get_cell(int row, int column) {
    static cell dead_cell;
    if (row < 0 || row >= this->row || column < 0 || column >= this->column) {
        return dead_cell;
    }
    return cells[row][column];
}