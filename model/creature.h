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
    virtual void move();
};


#endif //UNTITLED_CREATURE_H
