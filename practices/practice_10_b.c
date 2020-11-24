#include "stdio.h"

struct Vector{
    float _x,_y;
};

float skalar(struct Vector v1,struct Vector v2){
    return v1._x*v2._x + v1._y*v2._y;
}

int main(){
    struct Vector v1,v2;
    v1._x = 4;
    v1._y = 4;
    v2._x = 8;
    v2._y = 12;
}