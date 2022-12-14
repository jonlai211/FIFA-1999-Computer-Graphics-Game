//
// Created by jonathan on 12/10/22.
//

#ifndef CPT205_FOOTBALL_H
#define CPT205_FOOTBALL_H
#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include "vector"

#include "Assessment2/include/Vector3.h"
#include "Assessment2/include/Transform.h"
#include "Assessment2//include/Texture.h"
#include "Assessment2/include/Items.h"
#include "Assessment2/include/Camera.h"

using namespace std;

class Football {
public:
    Football(float x, float y, float z);

    ~Football();

    bool CollisionCheck();

    void DrawFootball(float x, float y, float z);

    Vector3 ball_velocity, ball_acceleration;

    Transform transform;

    Texture football_texture_ = Texture("../Assessment2/images/football.bmp");
private:
    Camera camera;
    GLUquadricObj *ball_quadric;
    float ball_radius = 0.35;
};


#endif //CPT205_FOOTBALL_H
