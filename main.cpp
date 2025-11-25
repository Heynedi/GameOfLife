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
bool show_console = true;
float speed = 0.01;

int main() {
    string file_path = "../initial_state_2.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir

    //instances de classes
    game game_of_life(file_path);
    rules rules;
    sf::Clock clock;
    graphic graphic(10);

    //iteration 0
    game_of_life.init_grid_size(file_path);         // définit la valeur des attributs "row" et "column"
    game_of_life.init_grid_data(file_path);         // rempli un string avec les données du fichier texte
    game_of_life.init_game_board();                   // crée les tableaux main_game_board et next_game_board et rempli main_game_board avec la string contenant les données du fichier texte
    if (show_console) {
        game_of_life.console_game_board(file_path); // affiche l'itération initiale dans la console
    }


    int window_width = game_of_life.get_column() * graphic.get_cell_size();     //calcul de la largeur de la fenêtre
    int window_height = game_of_life.get_row() * graphic.get_cell_size();       //calcul de la hauteur de la fenêtre
    graphic.set_window_size(window_width,window_height);            // définit la valeur des attributs window_width et window_height

    sf::RenderWindow window(sf::VideoMode({                 // définition de la taille de la fenêtre
        static_cast<unsigned int>(graphic.get_window_witdh()),        // largeur = nombre de colonnes * taille d'une cellule
        static_cast<unsigned int>(graphic.get_window_height())        // lauteur = nombre de lignes * taille d'une cellule
    }), "Game of Life");                                        // nom de la fenêtre

    while (window.isOpen()) {                                         // tant que la fenetre est ouverte
        while (const std::optional event = window.pollEvent()) {      // permet de gérer les évènements et le stocke dans event
            if (event->is<sf::Event::Closed>())                       // si l'event est de fermer la fenetre
                window.close();                                       // on ferme la fenetre
        }

        // le bloc de code suivant doit être exécuté toutes les "speed" secondes pour ne pas que le jeu de la vie aille trop vite.
        sf::Time elapsed = clock.getElapsedTime();                    // on récupère le temps de l'horloge
        if (elapsed > sf::seconds(speed) && !graphic.get_stop()) {    // si le temps mesuré est superieur à "vitesse"
            game_of_life.fill_next_board(rules);                      // on calcul l'iteration suivante
            game_of_life.switch_board();                              // on échange le tableau actuel et le tableau suivant
            clock.restart();                                          // on remet l'horloge à 0
            if (show_console) {
                game_of_life.console_game_board(file_path);         // affiche l'itération dans la console
            }
        }

        // le bloc de code suivant doit être exécuté le plus vite possible pour que la manipulation de la souris et l'affichage soit fluide
        graphic.show_grid(                                  //on actualise l'affichage de la grille à l'écran
            window,game_of_life.get_row(),
            game_of_life.get_column(),
            game_of_life.get_main_board().get_cells()
        );
        graphic.click_cell_birth(window,game_of_life.get_main_board());     // on fait naître les cellules sur lesquels on fait clique gauche avec la souris
        graphic.click_cell_kill(window,game_of_life.get_main_board());      // on tue les cellules sur lesquels on fait clique droit avec la souris
        if (const auto* keyEvent = window.pollEvent()->getIf<sf::Event::KeyPressed>()) {
            if (keyEvent->code == sf::Keyboard::Key::Space) {
                graphic.click_stop(); // On appelle la fonction qui inverse juste l'attribut "stop"
            }
        }
    }
    window.close();
    return 0;
}