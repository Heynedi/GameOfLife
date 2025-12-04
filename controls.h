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
    void click_stop(sf::RenderWindow* window, bool* stop);
    //void click_cell_kill();
    //void click_stop();
};


#endif //GAMEOFLIFE_V2_CONTROLS_H