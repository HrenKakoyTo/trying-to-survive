//
// Created by Александр on 19.01.2023.
//
#include <string>
#include "projectile.h"
#include <list>
#include "creature.h"

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H

class hero: public creature{
public:
    virtual list<projectile> shot();
};


#endif //UNTITLED_HERO_H
