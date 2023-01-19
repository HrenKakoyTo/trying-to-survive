//
// Created by Александр on 19.01.2023.
//

#ifndef UNTITLED_PROJECTILE_H
#define UNTITLED_PROJECTILE_H


class projectile {
private:
    int speed,damage;
    int time_to_live;
    int pen_count;
public:
    virtual void move();
    virtual void hit();
};


#endif //UNTITLED_PROJECTILE_H
