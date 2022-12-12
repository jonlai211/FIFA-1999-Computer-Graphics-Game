//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_ITEMS_H
#define CPT205_ITEMS_H

#define DEPTH_END (-50)
#define DEPTH_START 50
#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <cstdio>

#define USE_MATH_DEFINES

#include <cmath>

#include "Assessment2/include/Texture.h"
#include "Assessment2/include/Football.h"
#include "Assessment2/include/Vector3.h"
#include "Assessment2/include/Transform.h"

class Items {
public:
    Items();

    ~Items();

    void LoadAll();

    void DrawLawn();

    void DrawLight();

    void DrawFootball();

    Texture football_ = Texture("../Assessment2/images/football.jpg");

private:
    Texture lawn_ = Texture("../Assessment2/images/lawn.jpg");
};

#endif //CPT205_ITEMS_H
