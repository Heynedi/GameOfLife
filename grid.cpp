#include "grid.h"

#include <iostream>
#include <string>

#include "cell_obstacle.h"
#include "cell_standard.h"

grid::grid(int row, int column) {
    this->row = row;
    this->column = column;
    for (int i = 0; i < row; i++) {
        cells.resize(row);
        for (int j = 0; j < column; j++) {
            cells[i].resize(column);
            cells[i][j] = new cell_standard();
        }
    }
}

void grid::grid_fill(string data) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (data[i*column+j] == '1') {
                cells[i][j]->birth();
            }
        }
    }
}

cell* grid::get_cell(int x, int y) {
    return cells[x][y];
}

vector<vector<cell*>>* grid::get_cells() {
    return &cells;
}

string grid::print_grid() {
    string string_grid;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << cells[i][j]->get_state();
            string_grid += (cells[i][j]->get_state() + '0');
            string_grid += " ";
        }
        cout << endl;
        string_grid += "\r\n";
    }
    cout<<endl;
    string_grid += "\r\n";
    return string_grid;
}

void grid::reset() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cells[i][j]->kill();
        }
    }
}