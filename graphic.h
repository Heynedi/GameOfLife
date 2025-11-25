//
// Created by Utilisateur on 24/11/2025.
//

#ifndef GAMEOFLIFE_GRAPHIC_H
#define GAMEOFLIFE_GRAPHIC_H

#include <vector>

#include "cell.h"
#include "grid.h"

namespace sf {
    class RenderWindow;
}

using namespace std;

class graphic {
private:
    int cell_size = 20;
    int window_witdh;
    int window_height;
    bool stop = true;
public:
    graphic(int cell_size);
    void set_window_size(int window_witdh, int window_height);
    int get_cell_size();
    int get_window_witdh();
    int get_window_height();
    bool get_stop();
    void show_grid(sf::RenderWindow &window, int row, int column, vector<vector<cell> > cells);
    void click_cell(sf::RenderWindow &window, grid &main_board);
    void click_stop();
};


#endif //GAMEOFLIFE_GRAPHIC_H