//
// Created by Utilisateur on 03/12/2025.
//

#include "controls.h"

#include <iostream>

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
    int x_mouse = positionSouris.x;
    int y_mouse = positionSouris.y;
    int cell_size = gui->get_cell_size();
    int width = gui->get_window_width();
    int height = gui->get_window_height();
    if (x_mouse > 0 && y_mouse > 0 && x_mouse < width && y_mouse < height) { //si la souris est dans la fenetre
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { // si la souris est cliqué
            main_board->get_cell(y_mouse / cell_size, x_mouse / cell_size)->birth();
        }
    }
}

void controls::click_cell_kill(sf::RenderWindow* window, graphic *gui, grid *main_board) {
    sf::Vector2i positionSouris = sf::Mouse::getPosition(*window);
    int x_mouse = positionSouris.x;
    int y_mouse = positionSouris.y;
    int cell_size = gui->get_cell_size();
    int width = gui->get_window_width();
    int height = gui->get_window_height();
    if (x_mouse > 0 && y_mouse > 0 && x_mouse < width && y_mouse < height) { //si la souris est dans la fenetre
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) { // si la souris est cliqué
            main_board->get_cell(y_mouse / cell_size, x_mouse / cell_size)->kill();
        }
    }
}

void controls::click_stop(sf::RenderWindow* window, bool* stop) {
    if (const auto* keyEvent = window->pollEvent()->getIf<sf::Event::KeyPressed>()) {
        if (keyEvent->code == sf::Keyboard::Key::Space) {
            *stop = !*stop;
        }
    }
}
