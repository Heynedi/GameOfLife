#include "grid.h"
#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace sf {
    class RenderWindow;
}

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

string grid::print_grid() {
    string string_grid;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << cells[i][j].get_state();
            string_grid += (cells[i][j].get_state() + '0');
            string_grid += " ";
        }
        cout << endl;
        string_grid += "\r\n";
    }
    cout<<endl;
    string_grid += "\r\n";
    return string_grid;
}

cell& grid::get_cell(int row, int column) {
    return cells[row][column];
}

vector<vector<cell>> grid::get_cells() {
    return cells;
}