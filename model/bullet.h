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
    bullet(string type, int h, int w, int speed, int damage, double x, double y, double x_mult, double y_mult,int time_to_live, double angle);
    bool move() override;
    bool hit() override;
    bool hit(int damage) override {return true;}
};


#endif //UNTITLED_BULLET_H
