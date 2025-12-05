//
// Created by Utilisateur on 02/12/2025.
//

#include "game.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "cell_obstacle.h"

game::game(string file_path) {
    this->file_path = file_path;
}


void game::init_grid_size() {
    ifstream file(file_path.c_str(), ios::in);
    string grid_size;
    getline(file, grid_size);
    stringstream ss(grid_size);
    int row, column;
    ss >> row >> column;
    this->column = column;
    this->row = row;
}

void game::init_grid_data() {
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
    main_game_board = new grid(row, column);
    next_game_board = new grid(row, column);
    main_game_board->grid_fill(grid_data);
}

int game::get_row() {
    return row;
}

int game::get_column() {
    return column;
}

int game::alive_cell_around(int row, int column) {
    int alive_cell_around = 0;

    if (main_game_board->get_cell(row,column)->get_state()) {
        alive_cell_around = -1;
    }

    for (int i = row - 1; i <= row + 1; i++) { // pour chacune des 9 cellules autour de la cellule
        for (int j = column -1; j <= column + 1; j++) {// si la case fait bien parti de la matrice
            int wrapped_row = (i % this->row + this->row) % this->row; // faire simplement i%this->row ne fonctionne pas car parfois i = -1 et -1 % n = -1. On utilise donc une formule "plus complète" qui permet bien de récuperer le reste de la division
            int wrapped_column = (j % this->column + this->column) % this->column;

            alive_cell_around += main_game_board->get_cell(wrapped_row, wrapped_column)->get_state();
        }
    }
    return alive_cell_around;
}

void game::fill_next_board(rules* rules) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int neighbors = alive_cell_around(i,j);
            bool state = main_game_board->get_cell(i,j)->get_state();
            if (main_game_board->get_cell(i,j)->get_is_obstacle()) {
                auto* next_cells = next_game_board->get_cells();
                delete (*next_cells)[i][j];
                (*next_cells)[i][j] = new cell_obstacle();
                if (main_game_board->get_cell(i,j)->get_state()) {
                    next_game_board->get_cell(i,j)->force_birth();
                }
            }
            if (rules->apply_rules(neighbors, state)) {
                next_game_board->get_cell(i,j)->birth();
            }
            else {
                next_game_board->get_cell(i,j)->kill();
            }
        }
    }
}

void game::swap_board() {
    std::swap(main_game_board, next_game_board);
    next_game_board->reset();
}

grid* game::get_main_board() {
    return main_game_board;
}

void game::console_game_board(string file_path) {
    string string_grid = main_game_board->print_grid();
    string_grid += "\n";
    string string_size = to_string(row) + " " + to_string(column);

    string string_data = string_size + "\n" + string_grid;

    // --- ÉTAPE 1 : Création du nouveau nom de fichier ---
    std::string new_file_path = file_path;

    // On cherche la position du dernier point '.' (pour l'extension)
    size_t point_position = new_file_path.find_last_of('.');

    if (point_position != std::string::npos) {
        // Si on a trouvé un point (ex: "fichier.txt"), on insère "_out" juste avant
        // Résultat : "fichier_out.txt"
        new_file_path.insert(point_position, "_out");
    } else {
        // Si pas d'extension (ex: "fichier"), on ajoute à la fin
        // Résultat : "fichier_out"
        new_file_path += "_out";
    }

    // --- ÉTAPE 2 : Ouverture et Écriture ---
    // std::ios::app (Append) fait exactement ce que vous voulez :
    // - Si le fichier n'existe pas -> Il le crée.
    // - Si le fichier existe -> Il garde le contenu et se place à la fin.
    std::ofstream fichier(new_file_path, std::ios::app);
    fichier << string_data << std::endl; // On ajoute le texte + saut de ligne
}

int game::get_iteration() {
    return iteration;
}

void game::increment_iteration() {
    iteration++;
}void init_grid_size();
void init_grid_data();
void init_game_board();
