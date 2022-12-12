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
#include "Assessment2/include/Transform.h"
#include "Assessment2/include/Vector3.h"

class GameState {
public:
    std::string window_title_;

    explicit GameState(bool debug_mode);
    ~GameState();
    void Setup();
    static void Loop();
    void ShootCheck();

    // Callback functions
    void KeyboardControl (unsigned char key, int x, int y);
    void MousePress(int button, int state, int x, int y);
    void MouseControl (int x, int y);

    // Rendering functions
    void RenderScene();

    void ReshapeCallback(int width, int height);

    void IdleCallback();

private:
    Camera camera_;
    Mouse mouse_;
    Lighting lighting_;
    Items items_;
    Football football_ = Football(0, 0, 0);

    bool debug_mode_;
    bool Shooting = false;
    float football_x, football_y, football_z;
    float friction_force;
    float air_resistance_x, air_resistance_y, air_resistance_xyz, air_resistance_zyx, air_resistance_yzx;
    float U = 5, M = 0.2, G = -0.098, W;
    float L = 0.01, K = 0.4, P = 1.225, R = 5,Pi = 3.14, Spin_Multiplier = 3, SMM;
    float magnus_effect_x, magnus_effect_y, magnus_effect_z;

    Vector3 init_velocity = {0, 2, 2};
    Vector3 gravity = {0, G, 0};
    Vector3 ball_velocity;
    Vector3 wind_speed = {0, 0, 0};
    Vector3 Magnus_effect;
    Vector3 external_force;

    float v0 = 10, f = 0.01, v;
};


#endif //CPT205_GAMESTATE_H
