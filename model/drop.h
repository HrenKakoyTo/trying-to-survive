//
// Created by Александр on 19.01.2023.
//
#include "world_object.h"
#include "hero.h"

#ifndef UNTITLED_DROP_H
#define UNTITLED_DROP_H


class drop: public world_object{
public:
    virtual bool try_to_pickup (hero &hero);
};


#endif //UNTITLED_DROP_H
