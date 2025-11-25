#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "grid.h"
#include "graphic.h"
#include "rules.h"

using namespace std;

int iteration = 1;
bool infinite_loop = true;

int main() {
    string file_path = "../initial_state_2.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir

    //instances de classes
    game game_of_life(file_path);
    rules rules;
    sf::Clock clock;
    graphic graphic(10);

    //iteration 0
    game_of_life.init_grid_size(file_path);
    game_of_life.init_grid_data(file_path);
    game_of_life.init_game_board();
    game_of_life.console_game_board(file_path);

    //initialisation de la fenêtre
    graphic.set_window_size(game_of_life.get_column() * graphic.get_cell_size(),game_of_life.get_row() * graphic.get_cell_size());
    cout<<graphic.get_window_witdh()<<endl;
    cout<<graphic.get_window_height()<<endl;


    sf::RenderWindow window(sf::VideoMode({                 // définition de la taille de la fenêtre
        static_cast<unsigned int>(graphic.get_window_witdh()),        // largeur = nombre de colonnes * taille d'une cellule
        static_cast<unsigned int>(graphic.get_window_height())        // lauteur = nombre de lignes * taille d'une cellule
    }), "Game of Life");                                        // nom de la fenêtre

    while (window.isOpen()) {
        // tant que la fenetre est ouverte
        while (const std::optional event = window.pollEvent()) {      // permet de gérer les évènements et le stocke dans event
            if (event->is<sf::Event::Closed>())                       // si l'event est de fermer la fenetre
                window.close();                                       // on ferme la fenetre
        }

        //for (int i = 0; i < iteration; i+=0) {
        sf::Time elapsed1 = clock.getElapsedTime();
        if (elapsed1 > sf::seconds(0.01f) && !graphic.get_stop()) {
            game_of_life.fill_next_board(rules);
            game_of_life.switch_board();
            clock.restart();
            //i++;
            //game_of_life.console_game_board(file_path);
        }

        //le plus vite possible
        graphic.show_grid(window,game_of_life.get_row(), game_of_life.get_column(), game_of_life.get_main_board().get_cells());
        graphic.click_cell(window,game_of_life.get_main_board());
        if (const auto* keyEvent = window.pollEvent()->getIf<sf::Event::KeyPressed>()) {
            if (keyEvent->code == sf::Keyboard::Key::Space) {
                graphic.click_stop(); // On appelle la fonction qui inverse juste le booléen
            }
        }
    }
    window.close();
        //que toute les x secondes
        //sf::sleep(sf::seconds(0.1f));
    return 0;
}