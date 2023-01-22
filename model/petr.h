//
// Created by Александр on 22.01.2023.
//

#include "hero.h"

#ifndef UNTITLED_PETR_H
#define UNTITLED_PETR_H


class petr: public hero{
public:
    petr();
    list<projectile*> shot()override;
};


#endif //UNTITLED_PETR_H
