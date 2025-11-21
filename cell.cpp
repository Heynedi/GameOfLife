#include "cell.h"

cell::cell() {
}

void cell::kill() {
    is_alive = false;
}

void cell::birth() {
    is_alive = true;
}

bool cell::get_state() {
    return is_alive;
}

void cell::set_position(int x, int y) {
    this->x = x;
    this->y = y;
}

int cell::get_position_x() {
    return x;
}

int cell::get_position_y() {
    return y;
}