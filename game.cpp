//
// Created by Utilisateur on 19/11/2025.
//

#include "game.h"

#include <fstream>
#include <iostream>
#include <sstream>

game::game(string file_path) {
    this->file_path = file_path;
}

void game::init_grid_size(string file_path) {
    ifstream file(file_path.c_str(), ios::in);
    string grid_size;
    getline(file, grid_size);
    stringstream ss(grid_size);
    cout<<grid_size<<endl;
    int row, column;
    ss >> row >> column;
    this->column = column;
    this->row = row;
}

void game::init_grid_data(string file_path) {
    ifstream file(file_path.c_str(), ios::in);
    string line;

    if (getline(file, line)) {} //on ignore la première ligne qui contient la taille de la grille

    string grid_data;
    while (getline(file, line)) {
        grid_data += line;
    }

    //on enlève les espaces indesirables
    for (int i = 0; i < grid_data.size(); i++) {
        if (grid_data[i] == ' ') {
            grid_data.erase(i, 1);
        }
    }

    this->grid_data = grid_data;
}

void game::init_game_board() {
    main_game_board = grid(this->row, this->column);
    next_game_board = grid(this->row, this->column);
    main_game_board.grid_fill(this->grid_data);
}

void game::console_game_board() {
    main_game_board.print_grid();
}

int game::get_column() {
    return this->column;
}

int game::get_row() {
    return this->row;
}

int game::alive_cell_around(int row, int column) {
    int alive_cell_around = 0;

    if (main_game_board.get_cell(row,column).get_state()) {
        alive_cell_around = -1;
    }

    for (int i = row - 1; i <= row + 1; i++) { // pour chacune des 9 cellules autour de la cellule
        for (int j = column -1; j <= column + 1; j++) {// si la case fait bien parti de la matrice
            alive_cell_around += main_game_board.get_cell(i, j).get_state();
        }
    }
    return alive_cell_around;
}

void game::fill_next_board() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int neighbors = alive_cell_around(i,j);
            bool is_alive = main_game_board.get_cell(i,j).get_state();
            int is_alive2 = main_game_board.get_cell(i,j).get_state();
            if (is_alive) {
                if (neighbors == 2 || neighbors == 3) {
                    next_game_board.get_cell(i,j).birth();
                }
            }
            else {
                if (neighbors == 3) {
                    next_game_board.get_cell(i,j).birth();
                }
            }
        }
    }
}


bool game::verify_same_board() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (main_game_board.get_cell(i,j).get_state() != next_game_board.get_cell(i,j).get_state()) {
                return false;
            }
        }
    }
    return true;
}

bool game::verify_no_evolution(int nbr_evolution) {
    int static same_grid_counter = 0;
    if (verify_same_board()) {
        same_grid_counter++;
    }
    else {
        same_grid_counter = 0;
    }

    if (same_grid_counter == nbr_evolution) {
        return true;
    }
    else {
        return false;
    }
}

void game::switch_board() {
    main_game_board = next_game_board;
    next_game_board = grid(row, column);
}

grid& game::get_main_board() {
    return main_game_board;
}