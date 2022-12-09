//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_ITEMS_H
#define CPT205_ITEMS_H

#define DEPTH_END -3
#define DEPTH_START 1
#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <cstdio>
#define USE_MATH_DEFINES
#include <cmath>

#include "Assessment2/include//Texture.h"

class Items {
public:
    Items();
    ~Items();

    void LoadAll();
    void DrawLawn();
    void DrawLight();
//    void DrawDesk();
//    void DrawChair();
//    void DrawBooks();
//    void DrawLaptop(bool display);
//    void DrawBed();

private:
    Texture lawn_ = Texture("../Assessment2/images/lawn.jpg");
//    Texture poster_ = Texture("images/poster.jpg");
//    Texture screen_ = Texture("images/screen_ide.jpg");
//    Texture door_ = Texture("images/door.jpg");
//    Texture keyboard_ = Texture("images/keyboard.jpg");
//    Texture quilt_ = Texture("images/quilt.jpg");
//    Texture bedside_ = Texture("images/bedside.jpg");
//    Texture window_ = Texture("images/window.jpg");
};

#endif //CPT205_ITEMS_H
