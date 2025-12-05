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
#include "unit_test.h"

int main() {

    //variables nécessaires au fonctionnement du jeu de la vie
    string file_path = "../initial_state.txt";
    float speed = 0.1;
    cout << "entrez la vitesse de chaque itération (en seconde):";
    cin >> speed;
    bool show_console = false;
    cout << "Souhaitez vous activer l'enregistrement dans un fichier _out ? (0/1):";
    cin >> show_console;
    bool stop = true;

    //variables nécessaires pour basculer entre le mode infini et le mode fini.

    int nbr_iteration = 20;
    bool activate_game_done = false;
    bool game_done = false;
    cout << "Souhaitez vous mettre le jeu en mode fini ? (0/1)";
    cin >> activate_game_done;
    if (activate_game_done) {
        cout << "Combiens d'itération voulez vous réaliser ?";
        cin >> nbr_iteration;
    }

    //passe le jeu en mode "fini" et met le bon nombre d'itération pour pouvoir réaliser le test unitaire
    bool test = false;
    cout << "Souhaitez vous faire un test unitaire ? (0/1)";
    cin >> test;
    if (test) {
        file_path = "../test_start_state.txt";
        nbr_iteration = 20;
        activate_game_done = true;
    }

    //instance de classe
    game* game_of_life = new game(file_path);
    graphic* gui = new graphic();
    rules* rule = new rules();
    gui->set_cell_size(10);
    sf::Clock clock;
    controls* control = new controls();
    unit_test* test_unitaire = new unit_test();

    //iteration 0
    game_of_life->init_grid_size();         // définit la valeur des attributs "row" et "column"
    game_of_life->init_grid_data();         // rempli un string avec les données du fichier texte
    game_of_life->init_game_board();        // crée les tableaux main_game_board et next_game_board et rempli main_game_board avec la string contenant les données du fichier texte

    //on prépare les talbeaux nécessaire pour le test unitaire
    if (test) {
        test_unitaire->set_start_board(game_of_life->get_main_board());
        test_unitaire->init_wanted_board_size(game_of_life);
        test_unitaire->init_wanted_board_data();
        test_unitaire->init_wanted_board();
    }

    //ajout d'une cellule obstacle de démonstration
    if (!test) {
        auto* grid_cells = game_of_life->get_main_board()->get_cells();
        delete (*grid_cells)[2][2];
        (*grid_cells)[2][2] = new cell_obstacle();
        (*grid_cells)[2][2]->force_birth();
    }

    gui->set_window_size(game_of_life);     // définit la valeur des attributs window_width et window_height

    sf::RenderWindow window(sf::VideoMode({                 // définition de la taille de la fenêtre
        static_cast<unsigned int>(gui->get_window_width()),           // largeur = nombre de colonnes * taille d'une cellule
        static_cast<unsigned int>(gui->get_window_height())           // lauteur = nombre de lignes * taille d'une cellule
    }), "Game of Life");                                        // nom de la fenêtre

    while (window.isOpen() && !game_done) {                           // tant que la fenetre est ouverte et qu'il reste des itération à faire
        while (const std::optional event = window.pollEvent()) {      // permet de gérer les évènements et le stocke dans event
            if (event->is<sf::Event::Closed>())                       // si l'event est de fermer la fenetre
                window.close();                                       // on ferme la fenetre
        }
        // le bloc de code suivant doit être exécuté toutes les "speed" secondes pour ne pas que le jeu de la vie aille trop vite.
        sf::Time elapsed = clock.getElapsedTime();                    // on récupère le temps de l'horloge
        if (elapsed > sf::seconds(speed) && !stop) {                  // si le temps mesuré est superieur à "vitesse"
            game_of_life->fill_next_board(rule);                      // calcule l'itération suivante
            game_of_life->swap_board();                               // on échange les tableaux pour passer à l'itération suivante
            clock.restart();                                          // on remet l'horloge à 0
            game_of_life->increment_iteration();
            if (activate_game_done && game_of_life->get_iteration()>nbr_iteration) {
                game_done = true;
                stop = true;
            }
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
        control->click_key(&window, gui, game_of_life->get_main_board(), &stop);;
    }

    // si toutes les itérations sont finies
    if (game_done) {
        if (test) {
            test_unitaire->set_end_board(game_of_life->get_main_board());
            if (test_unitaire->compare_board(game_of_life)) {
                cout << "le test unitaire affirme que la grille obtenu a partir de la grille de test initale est correct" <<endl;
            }
        }
    }
    window.close();

    return 0;
}