//
// Created by Utilisateur on 24/11/2025.
//

#include "rules.h"
#include "game.h"
rules::rules() {

}
bool rules::apply_rules(int nbr_neighbours, bool state) {
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
