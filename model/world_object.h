//
// Created by Александр on 19.01.2023.
//
#include <string>
using namespace std;

#ifndef UNTITLED_WORLD_OBJECT_H
#define UNTITLED_WORLD_OBJECT_H


class world_object {
private:
    string type;
    int x,y;
    int weight, height; // x, y
    float angle_of_rotation;
public:
    string get_type() const;
    void set_type(string type);
    int get_x() const;
    void set_x(int x);
    int get_y() const;
    void set_y(int y);
    int get_weight() const;
    void set_weight(int w);
    int get_height() const;
    void set_height(int h);
    int get_angle_of_rotation() const;
    void set_angle_of_rotation(float angle);
    virtual double hit(int damage);
};


#endif //UNTITLED_WORLD_OBJECT_H
