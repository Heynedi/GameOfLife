#ifndef GAMEOFLIFE_V2_CELL_H
#define GAMEOFLIFE_V2_CELL_H

class cell {
protected:
    bool state;
public:
    cell();
    ~cell() = default;
    bool get_state();
    virtual void kill();
    virtual void birth();
    virtual void force_kill();
    virtual void force_birth();
};


#endif //GAMEOFLIFE_V2_CELL_H