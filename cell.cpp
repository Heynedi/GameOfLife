#include "cell.h"

cell::cell() {
}

void cell::kill() {
    this->is_alive = false;
}

void cell::birth() {
    this->is_alive = true;
}

bool cell::get_state() {
    return is_alive;
}

void cell::set_position(int x, int y) {
    this->x = x;
    this->y = y;
}

int cell::get_position_x() {
    return this->x;
}

int cell::get_position_y() {
    return this->y;
}