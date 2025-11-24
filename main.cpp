#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "game.h"
#include "grid.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "graphic.h"
#include "rules.h"

using namespace std;

int iteration = 1;

int main() {
    string file_path = "../initial_state.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir

    //iteration 0
    game game_of_life(file_path);
    game_of_life.init_grid_size(file_path);
    game_of_life.init_grid_data(file_path);
    game_of_life.init_game_board();
    game_of_life.console_game_board(file_path);

    graphic graphic(10);
    graphic.set_window_size(game_of_life.get_column() * graphic.get_cell_size(),game_of_life.get_row() * graphic.get_cell_size());
    cout<<graphic.get_window_witdh()<<endl;
    cout<<graphic.get_window_height()<<endl;

    rules rules;

    sf::RenderWindow window(sf::VideoMode({// sf::VideoMode définit la taille de la fenêtre (largeur, hauteur)
        static_cast<unsigned int>(graphic.get_window_witdh()), // Ici, on calcule dynamiquement la taille pour s'adapter à la grille Largeur = nombre de colonnes * taille d'une cellule ,Hauteur = nombre de lignes * taille d'une cellule
        static_cast<unsigned int>(graphic.get_window_height()) // on change en unsigned int car la fonction attend ceci
    }), "Jeu de la Vie - Grille");// nom qui est affiché dans le haut de la grille

    sf::Clock clock; //démarre le chrono

    while (window.isOpen()) { // boucle pour savoir quand la fenetre est encore ouverte
        while (const std::optional event = window.pollEvent()) { // permet de gérer les évènements (clicks ou autre...) et le stocke dans event
            if (event->is<sf::Event::Closed>())// si l'event est de fermer la fenetre alors on ferme la fenetre
                window.close();
        }

        for (int i = 0; i < iteration; i+=0) {
            sf::Time elapsed1 = clock.getElapsedTime(); //mesure le temps chrono
            if (elapsed1 > sf::seconds(0.1f) && !graphic.get_stop()) {
                game_of_life.fill_next_board(rules);
                game_of_life.switch_board();
                clock.restart();
                i++;

                game_of_life.console_game_board(file_path);

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



        //
    }


    return 0;
}