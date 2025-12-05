//
// Created by Utilisateur on 05/12/2025.
//

#ifndef GAMEOFLIFE_V2_UNIT_TEST_H
#define GAMEOFLIFE_V2_UNIT_TEST_H
#include "game.h"
#include "grid.h"


class unit_test {
protected:
    grid* start_board;
    grid* end_board;
    grid* wanted_end_board;
    string wanted_board_data;
    int row;
    int column;
public:
    bool compare_board(game*);
    void set_start_board(grid*);
    void set_end_board(grid*);
    void set_wanted_end_board();
    void init_wanted_board_size(game*);
    void init_wanted_board_data();
    void init_wanted_board();
};


#endif //GAMEOFLIFE_V2_UNIT_TEST_H