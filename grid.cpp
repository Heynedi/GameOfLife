#include "grid.h"

#include <iostream>
#include <string>

#include "cell_standard.h"

grid::grid(int row, int column) { // constructeur qui rempli uune grille de cellule standard
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

void grid::grid_fill(string data) { // modifie les état des cellules d'une grille en fonction des données d'un string
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (data[i*column+j] == '1') {
                cells[i][j]->birth();
            }
        }
    }
}

cell* grid::get_cell(int x, int y) { // getter d'une cellule du tableau cells
    return cells[x][y];
}

vector<vector<cell*>>* grid::get_cells() { // getter du tableau cells
    return &cells;
}

string grid::print_grid() { // crée un string qui contient les états des cellules de cells
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

void grid::reset() { // tue toutes les cellules du tableau cells
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cells[i][j]->kill();
        }
    }
}
