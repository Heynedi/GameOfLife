//
// Created by Utilisateur on 24/11/2025.
//

#include "graphic.h"
#include "cell.h"
#include "grid.h"


#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using namespace std;

namespace sf {
    class RenderWindow;
}

graphic::graphic(int cell_size) {
    this->cell_size = cell_size;
}

void graphic::set_window_size(int window_witdh, int window_height) {
    this->window_witdh = window_witdh;
    this->window_height = window_height;
}


int graphic::get_cell_size() {
    return cell_size;
}

int graphic::get_window_witdh() {
    return window_witdh;
}

int graphic::get_window_height() {
    return window_height;
}

void graphic::show_grid(sf::RenderWindow &window, int row, int column, vector<vector<cell>> cells) {
    // Efface la fenêtre avec du blanc donc efficace lorsqu'on affichera à la suite les grilles
    window.clear(sf::Color::Black);

    // configure un carré de taille cellSize , le -1 sert à mettre les contours entre les cases
    sf::RectangleShape cell(sf::Vector2f(cell_size - 1.0f, cell_size - 1.0f));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {// permet de parcourir entièrement la mactrice
            // permet de mettre la couleur donc si c'est true cela colorie la case en blanc sinon en noir
            cell.setFillColor(cells[i][j].get_state() ? sf::Color::White : sf::Color::Black);

            // permet de savoir la position de la case
            cell.setPosition(sf::Vector2f(
                static_cast<float>(j * cell_size),// permet de transformer le int en float car la fonction Vector2f() demande un float
                static_cast<float>(i * cell_size)
            ));

            window.draw(cell);// permert de dessiner les cases dans la fenetre
        }
    }
    window.display(); // permet d'afficher la fenetre
}

void graphic::click_cell(sf::RenderWindow &window, grid &main_board) {
    sf::Vector2i positionSouris = sf::Mouse::getPosition(window);
    int x_mouse = positionSouris.x;
    int y_mouse = positionSouris.y;

    if (x_mouse > 0 && y_mouse > 0 && x_mouse < window_witdh && y_mouse < window_height) { //si la souris est dans la fenetre
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { // si la souris est cliqué
            main_board.get_cell(y_mouse / cell_size, x_mouse / cell_size).birth();
        }
    }
}

bool graphic::get_stop() {
    return stop;
}

void graphic::click_stop() {
    stop = !stop;
}

