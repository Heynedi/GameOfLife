//
// Created by Utilisateur on 19/11/2025.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H
#include "grid.h"


class game {
private:
    grid main_game_board = grid(0,0);
    grid temp_game_board = grid(0,0);
    int generation = 0;
    string file_path;
    int row = 0;
    int column = 0;
    string grid_data;
public:
    game(string file_path);
    void init_game_board();
    void init_grid_size(string file_path);
    void init_grid_data(string file_path);
    void console_game_board();

    int get_column();
    int get_row();

};


#endif //GAMEOFLIFE_GAME_H