//
// Created by Utilisateur on 02/12/2025.
//

#include "graphic.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/VertexArray.hpp"

namespace sf {
    class RenderWindow;
}

graphic::graphic() {}

float graphic::get_cell_size() { // getter de cell_size
    return cell_size;
}

void graphic::set_cell_size(float cell_size) { // setter de cell_size
    graphic::cell_size = cell_size;
}

void graphic::set_window_size(game* game_of_life) { // setter de window_width et window_height
    this->window_width = game_of_life->get_column() * cell_size;;
    this->window_height = game_of_life->get_row() * cell_size;
}

int graphic::get_window_width() { // getter de window_width
    return window_width;
}

int graphic::get_window_height() { // getter de window_height
    return window_height;
}

void graphic::show_grid(sf::RenderWindow* window, int row, int column, vector<vector<cell*>> cells) { // affiche les cellules dans la fenêtre
    window->clear(sf::Color::Black); //on colore la fenetre en noir

    sf::VertexArray triangles(sf::PrimitiveType::Triangles, row * column * 6);      //on créée une liste de vertices de taille row * column * 6 car il y a 3 vertices par triangle, et 2 triangle par carrés.

    int current_vertex = 0;
    float x;
    float y;
    float size = cell_size - 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) { //pour chaque cellule

            if (cells[i][j]->get_state()) { // Si la cellule est vivante on la dessine

                // position de la cellule en pixels
                x = static_cast<float>(j * cell_size);
                y = static_cast<float>(i * cell_size);
                size = static_cast<float>(cell_size - 1); // -1 pour la bordure
                sf::Color color = sf::Color::White; // couleur blanche

                // premier triangle
                triangles[current_vertex + 0].position = sf::Vector2f(x, y);          // haut-gauche
                triangles[current_vertex + 1].position = sf::Vector2f(x + size, y);   // haut-droite
                triangles[current_vertex + 2].position = sf::Vector2f(x, y + size);   // bas-gauche

                triangles[current_vertex + 0].color = color;
                triangles[current_vertex + 1].color = color;
                triangles[current_vertex + 2].color = color;

                // deuxieme triangle
                triangles[current_vertex + 3].position = sf::Vector2f(x + size, y);        // haut-droite
                triangles[current_vertex + 4].position = sf::Vector2f(x + size, y + size); // bas-droite
                triangles[current_vertex + 5].position = sf::Vector2f(x, y + size);        // bas-gauche

                triangles[current_vertex + 3].color = color;
                triangles[current_vertex + 4].color = color;
                triangles[current_vertex + 5].color = color;

                current_vertex += 6; // On avance de 6 sommets pour la prochaine case
            }
        }
    }
    triangles.resize(current_vertex); //on réduit la taille de la grille pour l'optimisation (on a ignoré les cellules mortes donc pas besoin de les garder)
    window->draw(triangles); // on dessine les vertex
    window->display();
}

