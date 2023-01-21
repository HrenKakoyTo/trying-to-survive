//
// Created by Александр on 19.01.2023.
//

#ifndef UNTITLED_PROJECTILE_H
#define UNTITLED_PROJECTILE_H


class projectile {
private:
    int speed,damage;
    int time_to_live;
public:
    virtual void move();
    virtual void hit(enemy & enemy);
};


#endif //UNTITLED_PROJECTILE_H
