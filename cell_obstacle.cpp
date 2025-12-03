#include "cell_obstacle.h"

cell_obstacle::cell_obstacle() {}

void cell_obstacle::kill() {} //on empeche une cellule obstacle de pouvoir mourrir comme une cellule normale
void cell_obstacle::birth() {} //on empeche une cellule obstacle de pouvoir naitre comme une cellule normale

void cell_obstacle::force_kill() { //on permet à une cellule obstacle de pouvoir mourrir avec une méthode spécifique
    state = false;
}

void cell_obstacle::force_birth() { //on permet à une cellule obstacle de pouvoir naitre avec une méthode spécifique
    state = true;
}