#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H


class cell {
private:
    bool is_alive;
    int x;
    int y;
public:
    cell(bool is_alive);

    void kill();
    void birth();
    bool get_state();

    void set_position(int x, int y);
    int get_position_x();
    int get_position_y();
};


#endif //GAMEOFLIFE_CELL_H