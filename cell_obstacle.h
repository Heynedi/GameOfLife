#ifndef GAMEOFLIFE_V2_CELL_OBSTACLE_H
#define GAMEOFLIFE_V2_CELL_OBSTACLE_H
#include "cell.h"

class cell_obstacle : public cell {
public:
    cell_obstacle();
    ~cell_obstacle() = default;
    void kill() override;
    void birth() override;
    void force_kill();
    void force_birth();
};


#endif //GAMEOFLIFE_V2_CELL_OBSTACLE_H