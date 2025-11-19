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
    /*string grid_size;
    string grid_data;

    ifstream file(file_path.c_str(), ios::in);

    //on récupère le contenu de la première ligne
    getline(file, grid_size);
    stringstream ss(grid_size);
    int h, w;
    ss >> h >> w;
    //on récupère le contenu du reste du fichier
    string line;
    while (getline(file, line)) {
        grid_data += line;
    }

    grid game_board(h, w);

    //on enlève les espaces indésirables
    int tmp = 0;
    for (int i = 0; i < grid_data.size()-tmp; i++) {
        if (grid_data[i] == ' ') {
            grid_data.erase(i, 1);
        }
    }
    file.close();

    game_board.grid_fill(grid_data);
    game_board.print_grid();
    */
    game game_of_life(file_path);
    game_of_life.init_grid_size(file_path);
    game_of_life.init_grid_data(file_path);
    game_of_life.init_game_board();
    game_of_life.console_game_board();

    return 0;
}