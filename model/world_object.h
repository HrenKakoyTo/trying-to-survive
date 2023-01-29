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
    double x,y;
    int width, height; // x, y
    double angle_of_rotation;
public:
    string get_type() const;
    void set_type(string type);
    double get_x() const;
    void set_x(int x);
    double get_y() const;
    void set_y(int y);
    int get_width() const;
    void set_width(int w);
    int get_height() const;
    void set_height(int h);
    double get_angle_of_rotation() const;
    void set_angle_of_rotation(float angle);
    virtual bool hit(int damage) = 0;
};


#endif //UNTITLED_WORLD_OBJECT_H
