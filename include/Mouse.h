//
// Created by jonathan on 12/4/22.
//

#ifndef CPT205_MOUSE_H
#define CPT205_MOUSE_H

#include <GL/freeglut.h>
#include <cmath>

class Mouse {
public:
    Mouse();

    int mouse_x_, mouse_y_;
    bool mouse_left_down_, mouse_right_down_;
};


#endif //CPT205_MOUSE_H
