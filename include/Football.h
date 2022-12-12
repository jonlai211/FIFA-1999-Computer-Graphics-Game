//
// Created by jonathan on 12/10/22.
//

#ifndef CPT205_FOOTBALL_H
#define CPT205_FOOTBALL_H
#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include "Assessment2/include/Vector3.h"
#include "Assessment2/include/Transform.h"
#include "Assessment2//include/Texture.h"
#include "Assessment2/include/Items.h"
#include "Assessment2/include/Camera.h"

class Football {
public:
    Football(float x, float y, float z);

    ~Football();

    bool CollisionCheck();

    void DrawFootball(float x, float y, float z);

    Vector3 ball_velocity, ball_acceleration;

    Transform transform;

private:
    Camera camera;
    GLUquadricObj *ball_quadric;
    Texture ball_texture_ = Texture("../Assessment2/images/football.jpg");
    float ball_radius = 1;
};


#endif //CPT205_FOOTBALL_H
