#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "game.h"
#include "grid.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
//SFML
    // Create the main window
    //sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    //music
    // Load a music to play
    //sf::Music music("nice_music.ogg");
    // Play the music
    //music.play();

    string file_path = "../initial_state.txt";  // je stocke dans la chaîne mon_fichier le nom du fichier à ouvrir

    //iteration 0
    game game_of_life(file_path);
    game_of_life.init_grid_size(file_path);
    game_of_life.init_grid_data(file_path);
    game_of_life.init_game_board();
    game_of_life.console_game_board();

    //autres iterations
    for (int i = 0; i < 20; i++) {
        game_of_life.fill_next_board();
        game_of_life.switch_board();
        cout<<endl;
        game_of_life.console_game_board();
    }

    return 0;
}