#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"

class _cube:public _object3D
{
public:

    vector<_vertex4ui> Sides;
    _cube(float Size=1.0);

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
};

#endif // CUBE_H

