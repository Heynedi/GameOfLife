#include <iostream>
#include <optional>

#include "cell.h"
#include "controls.h"
#include "game.h"
#include "graphic.h"
#include "grid.h"
#include "rules.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "cell_obstacle.h"

int main() {

    string file_path = "../initial_state_2.txt";
    float speed = 0.1;
    bool show_console = false;
    bool stop = false;

    //instance de classe
    game* game_of_life = new game(file_path);
    graphic* gui = new graphic();
    rules* rule = new rules();
    gui->set_cell_size(10);
    sf::Clock clock;
    controls* control = new controls();

    //iteration 0
    game_of_life->init_grid_size();         // définit la valeur des attributs "row" et "column"
    game_of_life->init_grid_data();         // rempli un string avec les données du fichier texte
    game_of_life->init_game_board();        // crée les tableaux main_game_board et next_game_board et rempli main_game_board avec la string contenant les données du fichier texte

    gui->set_window_size(game_of_life);     // définit la valeur des attributs window_width et window_height

    sf::RenderWindow window(sf::VideoMode({                 // définition de la taille de la fenêtre
        static_cast<unsigned int>(gui->get_window_width()),        // largeur = nombre de colonnes * taille d'une cellule
        static_cast<unsigned int>(gui->get_window_height())        // lauteur = nombre de lignes * taille d'une cellule
    }), "Game of Life");                                        // nom de la fenêtre

    while (window.isOpen()) {                                         // tant que la fenetre est ouverte
        while (const std::optional event = window.pollEvent()) {      // permet de gérer les évènements et le stocke dans event
            if (event->is<sf::Event::Closed>())                       // si l'event est de fermer la fenetre
                window.close();                                       // on ferme la fenetre
        }

        // le bloc de code suivant doit être exécuté toutes les "speed" secondes pour ne pas que le jeu de la vie aille trop vite.
        sf::Time elapsed = clock.getElapsedTime();                    // on récupère le temps de l'horloge
        if (elapsed > sf::seconds(speed) && stop) {       // si le temps mesuré est superieur à "vitesse"
            game_of_life->fill_next_board(rule);                      // on calcul l'iteration suivante
            game_of_life->swap_board();                              // on échange le tableau actuel et le tableau suivant
            clock.restart();                                          // on remet l'horloge à 0
            if (show_console) {
                game_of_life->console_game_board(file_path);         // affiche l'itération dans la console
            }
        }

        // le bloc de code suivant doit être exécuté le plus vite possible pour que la manipulation de la souris et l'affichage soit fluide
        gui->show_grid(                                  //on actualise l'affichage de la grille à l'écran
            &window,
            game_of_life->get_row(),
            game_of_life->get_column(),
            *game_of_life->get_main_board()->get_cells()
        );

        //utilisation du clavier et de la souris
        control->click_cell_birth(&window, gui, game_of_life->get_main_board());     // on fait naître les cellules sur lesquels on fait clique gauche avec la souris
        control->click_cell_kill(&window, gui, game_of_life->get_main_board());      // on tue les cellules sur lesquels on fait clique droit avec la souris
        control->click_stop(&window, &stop);
    }

    window.close();

    return 0;
}