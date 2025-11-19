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
    this->main_game_board = grid(this->row, this->column);
    this->temp_game_board = grid(this->row, this->column);
    this->main_game_board.grid_fill(this->grid_data);
}

void game::console_game_board() {
    this->main_game_board.print_grid();
}

int game::get_column() {
    return this->column;
}

int game::get_row() {
    return this->row;
}
