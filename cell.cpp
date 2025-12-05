#include "cell.h"

#include <ranges>

cell::cell() {
    state = false;
}

bool cell::get_state() {
    return state;
}

bool cell::get_is_obstacle() {
    return is_obstacle;
}

void cell::kill() {
    state = false;
}

void cell::birth() {
    state = true;
}

void cell::force_kill() {
    state = false;
}

void cell::force_birth() {
    state = true;
}
