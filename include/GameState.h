//
// Created by jonathan on 12/4/22.
//

#ifndef CPT205_GAMESTATE_H
#define CPT205_GAMESTATE_H

#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include <algorithm>

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

    // Callback functions
    void KeyboardControl(unsigned char key, int x, int y);

    void KeyboardSpecialCallback(int key, int x, int y);

    void MousePress(int button, int state, int x, int y);

    void MouseControl(int x, int y);

    void ReshapeCallback(int width, int height);

    void IdleCallback();

    // Rendering functions
    void RenderScene();

    void InteractionScene();

    void DisplayText(GLfloat x, GLfloat y, const std::string& message, int num) const;

    static void DisplayAccumulateBar(GLfloat x, GLfloat y, float t);

    // Others

    void VelocityCalculate(float yaw, float pitch);

    void VerticalMovement(float vy);

    void HorizonMovement(float v, float yaw);

    void *font = GLUT_BITMAP_9_BY_15;

private:
    Camera camera_;
    Mouse mouse_;
    Lighting lighting_;
    Items items_;
    Football football_ = Football(0, 1.1, 0);

    bool debug_mode_;
    bool FPS_mode = false;

    bool ShootingMode = false, FreeMode = false;
    bool PowerAccumulate = false;
    bool FinishAccumulate = false;
    bool HorizonMove = false, VerticalMove = false;
    float shoot_yaw_ = 0, shoot_pitch_ = 0;
    float init_v_vertical, init_v_horizon;
    float relative_x_, relative_y_, relative_z_, relative_horizon_;


    bool y_move_ = false, z_move_ = false;
    float football_x_, football_y_ = 1.1f, football_z_;
    float football_yaw_, football_pitch_;
    float ty = 0.0f, tx =0.0f;
    float init_y_ = 1.1f, init_x_ = 0.f, init_z_ = 0.f;
    float temp_y_ = 0.0f, temp_z_ = 0.0f;
    float accumulate_t = 0.f;   // 0-60
    float init_v = 0;

    Vector3 init_velocity;
//    Vector3 init_velocity = {0, 100, 80};
    Vector3 ball_velocity;
};


#endif //CPT205_GAMESTATE_H
