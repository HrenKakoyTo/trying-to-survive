//
// Created by Александр on 19.01.2023.
//

#include "game.h"


bool collision_check(bool x1, bool y1,int w1, int h1, bool x2, bool y2, int w2, int h2){
    return x1+w1 > x2 && x2+w2 > x1 && y1+h1 > y2 && y2+h2 > y1;
}