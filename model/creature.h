//
// Created by Александр on 21.01.2023.
//

#include "world_object.h"

#ifndef UNTITLED_CREATURE_H
#define UNTITLED_CREATURE_H


class creature: public world_object{
private:
    int hp;
    int speed;
public:
    creature();
    int get_speed();
    int get_hp();
    void set_speed(int speed);
    void set_hp(int hp);
    bool hit(int damage) override;
};


#endif //UNTITLED_CREATURE_H
