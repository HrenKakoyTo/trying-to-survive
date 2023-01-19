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
public:
    string get_type();
    int get_x();
    int get_y();
    int get_weight();
    int get_height();
};


#endif //UNTITLED_WORLD_OBJECT_H
