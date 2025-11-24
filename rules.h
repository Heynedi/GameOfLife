//
// Created by Utilisateur on 24/11/2025.
//

#ifndef GAMEOFLIFE_RULES_H
#define GAMEOFLIFE_RULES_H


class rules {
public:
    rules();
    bool apply_rules(int nbr_neighbours, bool state);
};


#endif //GAMEOFLIFE_RULES_H