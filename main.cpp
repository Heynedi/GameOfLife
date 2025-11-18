#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "grid.h"
using namespace std;

int main() {
    string file_path = "../initial_state.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir
    string grid_size;

    ifstream file(file_path.c_str(), ios::in);
    if(file)  // si l'ouverture a réussi
    {
        //on récupère le contenu de la première ligne
        getline(file, grid_size);
        file.close();
    }

    grid game_board(grid_size[0], grid_size[2]);
    game_board.fill_grid();
    return 0;
}

