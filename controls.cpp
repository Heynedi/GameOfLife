//
// Created by Utilisateur on 03/12/2025.
//

#include "controls.h"

#include <iostream>

#include "cell_obstacle.h"
#include "cell_standard.h"
#include "graphic.h"
#include "grid.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"

namespace sf {
    class RenderWindow;
}

controls::controls() {}

void controls::click_cell_birth(sf::RenderWindow* window, graphic *gui, grid *main_board) {
    sf::Vector2i positionSouris = sf::Mouse::getPosition(*window);
    int x_mouse = positionSouris.x;         // coordonnée x de la souris
    int y_mouse = positionSouris.y;         // coordonnée y de la souris
    int cell_size = gui->get_cell_size();   // taille d'une cellule
    int width = gui->get_window_width();
    int height = gui->get_window_height();
    if (x_mouse > 0 && y_mouse > 0 && x_mouse < width && y_mouse < height) { //si la souris est dans la fenetre
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { // si la souris est cliqué
            main_board->get_cell(y_mouse / cell_size, x_mouse / cell_size)->force_birth();
        }
    }
}

void controls::click_cell_kill(sf::RenderWindow* window, graphic *gui, grid *main_board) {
    sf::Vector2i positionSouris = sf::Mouse::getPosition(*window);
    int x_mouse = positionSouris.x;         // coordonnée x de la souris
    int y_mouse = positionSouris.y;         // coordonnée y de la souris
    int cell_size = gui->get_cell_size();   // taille d'une cellule
    int width = gui->get_window_width();
    int height = gui->get_window_height();
    if (x_mouse > 0 && y_mouse > 0 && x_mouse < width && y_mouse < height) { //si la souris est dans la fenetre
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) { // si la souris est cliqué
            main_board->get_cell(y_mouse / cell_size, x_mouse / cell_size)->force_kill();
        }
    }
}

void controls::click_key(sf::RenderWindow* window, graphic *gui, grid *main_board, bool* stop) {
    sf::Vector2i positionSouris = sf::Mouse::getPosition(*window);
    int x_mouse = positionSouris.x;         // coordonnée x de la souris
    int y_mouse = positionSouris.y;         // coordonnée y de la souris
    int cell_size = gui->get_cell_size();   // taille d'une cellule

    // on calcule donc la cellule visée par la souris
    int x = x_mouse / cell_size;
    int y = y_mouse / cell_size;

    // on récupère la taille de la fenêtre
    int width = gui->get_window_width();
    int height = gui->get_window_height();

    // si une touche du clavier est appuyé
    if (const auto* keyEvent = window->pollEvent()->getIf<sf::Event::KeyPressed>()) {
        if (x_mouse > 0 && y_mouse > 0 && x_mouse < width && y_mouse < height) {
            //si la souris est dans la fenetre
            if (keyEvent->code == sf::Keyboard::Key::LControl) { // si cette touche est LControl on crée une cellule obstacle là où pointe la souris
                *main_board->get_cell(y,x) = cell_obstacle();
                main_board->get_cell(y,x)->force_birth();
                std::cout << main_board->get_cell(y,x)->get_is_obstacle() << std::endl;
                cout<<"LControl"<<endl;
            }
            else if (keyEvent->code == sf::Keyboard::Key::LAlt) { // si cette touche est LAlt on crée une cellule obstacle là où pointe la souris
                *main_board->get_cell(x,y) = cell_standard();
                cout<<"LAlt"<<endl;
            }

            else if (keyEvent->code == sf::Keyboard::Key::Space) { // si cette touche est espace on inverse le booléen stop ce qui permet d'arrêter ou de relancer le jeu
                *stop = !*stop;
            }
        }
    }
}