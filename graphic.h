#ifndef GAMEOFLIFE_V2_GRAPHIC_H
#define GAMEOFLIFE_V2_GRAPHIC_H

#include "game.h"

namespace sf {
    class RenderWindow;
}

class graphic {
protected:
    float cell_size;
    int window_width;
    int window_height;
public:
    graphic();
    ~graphic() = default;
    float get_cell_size();
    void set_cell_size(float cell_size);
    void set_window_size(game* game_of_life);
    int get_window_width();
    int get_window_height();
    void show_grid(sf::RenderWindow* window, int row, int column, vector<vector<cell*>> cells);
};


#endif //GAMEOFLIFE_V2_GRAPHIC_H