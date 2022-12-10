//
// Created by jonathan on 12/10/22.
//

#ifndef CPT205_FOOTBALL_H
#define CPT205_FOOTBALL_H
#define FREEGLUT_STATIC

#include <GL/freeglut.h>

class Football {
public:

private:
    GLUquadricObj* ball_quadric;
    GLuint ball_texture;
    float ball_radius;

};


#endif //CPT205_FOOTBALL_H
