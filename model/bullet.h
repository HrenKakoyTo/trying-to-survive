//
// Created by Александр on 21.01.2023.
//
#include "projectile.h"

#ifndef UNTITLED_BULLET_H
#define UNTITLED_BULLET_H


class bullet: public projectile{
private:
    double x_multiplier;
    double y_multiplier;
public:
    void move() override;
    bool hit(creature* & creature) override;
};


#endif //UNTITLED_BULLET_H
