//
// Created by Utilisateur on 03/12/2025.
//

#ifndef GAMEOFLIFE_V2_CONTROLS_H
#define GAMEOFLIFE_V2_CONTROLS_H
#include "graphic.h"
#include "SFML/Window/WindowBase.hpp"


class controls {
public:
    controls();
    ~controls() = default;
    void click_cell_birth(sf::RenderWindow* window, graphic *gui, grid *main_board);
    void click_cell_kill(sf::RenderWindow* window, graphic *gui, grid *main_board);
    void click_key(sf::RenderWindow* window, graphic *gui, grid *main_board, bool* stop);
};


#endif //GAMEOFLIFE_V2_CONTROLS_H