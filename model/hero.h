//
// Created by Александр on 19.01.2023.
//
#include <string>

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H


class hero {
private:
    int xp, hp, level, speed, collection_radius;
    double armor, damage, luck;
    bool is_facing_right;
public:
    void hit(int damage);
    void move (std::string direction);
    bool level_up_check();
};


#endif //UNTITLED_HERO_H
