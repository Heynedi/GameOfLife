//
// Created by Utilisateur on 03/12/2025.
//

#include "rules.h"

rules::rules() {}

bool rules::apply_rules(int nbr_neighbours, bool state) { // applique les règles du jeu de la vie pour une cellule
    if (state) {
        if (nbr_neighbours == 2 || nbr_neighbours == 3) {
            return true;
        }
    }
    else {
        if (nbr_neighbours == 3) {
            return true;
        }
    }
    return false;
}