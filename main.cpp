#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "game.h"
#include "grid.h"
using namespace std;

int main() {
    string file_path = "../initial_state.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir

    //iteration 0
    game game_of_life(file_path);
    game_of_life.init_grid_size(file_path);
    game_of_life.init_grid_data(file_path);
    game_of_life.init_game_board();
    game_of_life.console_game_board();


    for (int i = 0; i < 10; i++) {
        game_of_life.fill_next_board();
        game_of_life.switch_board();
        cout<<endl;
        game_of_life.console_game_board();
    }
    
    return 0;
}