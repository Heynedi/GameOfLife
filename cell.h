#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H


class cell {
private:
    bool is_alive = 0;
    int x;
    int y;
public:
    cell();

    void kill();
    void birth();
    bool get_state();

    void set_position(int x, int y);
    int get_position_x();
    int get_position_y();
};


#endif //GAMEOFLIFE_CELL_H