#ifndef GAMEOFLIFE_V2_RULES_H
#define GAMEOFLIFE_V2_RULES_H


class rules {
public:
    rules();
    ~rules() = default;
    bool apply_rules(int nbr_neighbours, bool state);
};


#endif //GAMEOFLIFE_V2_RULES_H