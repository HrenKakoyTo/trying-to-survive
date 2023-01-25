//
// Created by Александр on 19.01.2023.
//

#include "world_object.h"
#include "creature.h"

#ifndef UNTITLED_PROJECTILE_H
#define UNTITLED_PROJECTILE_H


class projectile: public world_object {
private:
    int speed,damage;
    int time_to_live;
public:
    int get_speed() const;
    int get_damage() const;
    int get_time_to_live() const;

    void set_speed(int speed);
    void set_damage(int damage);
    void set_time_to_live(int tics);

    virtual void move() = 0;
    virtual bool hit() = 0;
};


#endif //UNTITLED_PROJECTILE_H
