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

#include <cmath>

#include "Assessment2/include/Texture.h"
#include "Assessment2/include/Football.h"
#include "Assessment2/include/Vector3.h"
#include "Assessment2/include/Transform.h"


class Items {
public:
    Items(const Football &football);

    ~Items();

    void LoadAll();

    void DrawLawn();

    static void DrawGoal();

    static void DrawBorder();

    static void DrawSeat();

    static void DrawTarget1(bool show);
    static void DrawTarget2(bool show);
    static void DrawTarget3(bool show);
    static void DrawTarget4(bool show);
    static void DrawTarget5(bool show);

private:
    Football football;
    Texture lawn_ = Texture("../Assessment2/images/lawn.jpg");
    Texture barca_ = Texture("../Assessment2/images/barca.jpg");
};

#endif //CPT205_ITEMS_H
