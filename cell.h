#ifndef GAMEOFLIFE_V2_CELL_H
#define GAMEOFLIFE_V2_CELL_H

class cell {
protected:
    bool state;
    bool is_obstacle;
public:
    cell();
    ~cell() = default;
    bool get_state();
    bool get_is_obstacle();
    virtual void kill();
    virtual void birth();
    virtual void force_kill();
    virtual void force_birth();
};


#endif //GAMEOFLIFE_V2_CELL_H