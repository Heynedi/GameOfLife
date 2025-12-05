//
// Created by Utilisateur on 05/12/2025.
//

#include "unit_test.h"

#include <fstream>

#include "grid.h"
#include "SFML/Audio/Music.hpp"

bool unit_test::compare_board(game* game_of_life) {
    for (int i = 0; i < game_of_life->get_row(); i++) {
        for (int j = 0; j < game_of_life->get_column(); j++) {
            if (!(end_board->get_cell(i,j)->get_state() == wanted_end_board->get_cell(i,j)->get_state())) {
                return false;
            }
        }
    }
    return true;
}

void unit_test::set_start_board(grid* start_board) {
    this->start_board = start_board;
}

void unit_test::set_end_board(grid* end_board) {
    this->end_board = end_board;
}

void unit_test::init_wanted_board_size(game* game_of_life) {
    this->column = game_of_life->get_column();
    this->row = game_of_life->get_row();
}

void unit_test::init_wanted_board_data() {
    ifstream file("../test_end_state.txt", ios::in);
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

    this->wanted_board_data = grid_data;
}

void unit_test::init_wanted_board() {
    wanted_end_board = new grid(row, column);
    wanted_end_board->grid_fill(wanted_board_data);
}

