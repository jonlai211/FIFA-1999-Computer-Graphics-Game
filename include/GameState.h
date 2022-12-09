//
// Created by jonathan on 12/4/22.
//

#ifndef CPT205_GAMESTATE_H
#define CPT205_GAMESTATE_H

#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

#include "Assessment2/include/Keyboard.h"
#include "Assessment2/include/Mouse.h"
#include "Assessment2/include/Camera.h"
#include "Assessment2/include/Lighting.h"
#include "Assessment2/include/Items.h"

class GameState {
public:
    // Basic window properties
    int window_width_{}, window_height_{};
    int window_x_{}, window_y_{};
    std::string window_title_;

    explicit GameState(bool debug_mode);
    ~GameState();
    void Setup();
    static void Loop();

    // Callback functions
    void KeyboardControl (unsigned char key, int x, int y);
    void MousePress(int button, int state, int x, int y);
    void MouseControl (int x, int y);

    // Rendering functions
    void RenderScene();

    void ReshapeCallback(int width, int height);

    void IdleCallback();

private:
    bool debug_mode_;
    Camera camera_;
//    Keyboard keyboard_;
    Mouse mouse_;
    Lighting lighting_;
    Items items_;

};


#endif //CPT205_GAMESTATE_H
