#include "cell_standard.h"

cell_standard::cell_standard() {}

void cell_standard::kill() {
    state = false;
}

void cell_standard::birth() {
    state = true;
}