//
// Created by Utilisateur on 02/12/2025.
//

#ifndef GAMEOFLIFE_V2_CELL_STANDARD_H
#define GAMEOFLIFE_V2_CELL_STANDARD_H

#include "cell.h"

class cell_standard : public cell {
public:
    cell_standard();
    ~cell_standard() = default;
    void kill();
    void birth();
};


#endif //GAMEOFLIFE_V2_CELL_STANDARD_H