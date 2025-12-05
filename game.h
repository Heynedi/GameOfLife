//
// Created by Utilisateur on 02/12/2025.
//

#ifndef GAMEOFLIFE_V2_GAME_H
#define GAMEOFLIFE_V2_GAME_H
#include <string>

#include "grid.h"
#include "rules.h"


class game {
protected:
    grid* main_game_board = new grid(0,0);
    grid*next_game_board = new grid(0,0);
    string file_path;
    string grid_data;
    int row;
    int column;
    int iteration;
public:
    game(string file_path);
    ~game() = default;
    void init_grid_size();
    void init_grid_data();
    void init_game_board();

    int get_row();
    int get_column();
    grid* get_main_board();
    int get_iteration();

    void increment_iteration();
    int alive_cell_around(int row, int column);
    void fill_next_board(rules*);
    void swap_board();

    void console_game_board(string file_path);
};


#endif //GAMEOFLIFE_V2_GAME_H