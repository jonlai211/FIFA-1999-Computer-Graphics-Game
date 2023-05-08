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

    void MouseWheelCallback(int button, int dir, int x, int y);

    void ReshapeCallback(int width, int height);

    void IdleCallback();

    // Rendering functions
    void RenderScene();

    void InteractionScene();

    void DisplayText(GLfloat x, GLfloat y, const std::string& message, int num) const;

    void DisplayTextOnly(GLfloat x, GLfloat y, const std::string& message) const;

    static void DisplayAccumulateBar(GLfloat x, GLfloat y, float t);

    // Others
    void AlwaysForward(float x, float z, float yaw);

    void ResetBallPosition();

    void CollisionCheck(float x, float z);

    void VelocityCalculate(float yaw, float pitch);

    void VerticalMovement(float vy);

    void HorizonMovement(float v, float yaw);

    void InitPenalty();

    void SpinControl(float yaw);

    void ScoreCheck();

    void *font = GLUT_BITMAP_9_BY_15;

private:
    Camera camera_;
    Mouse mouse_;
    Lighting lighting_;
    Items items_;
//    Football football_ = Football(0, 1.1, 0);
    Football football_ = Football(0, 0.35, 0);

    bool debug_mode_;
    bool ShootingMode = false, FreeMode = false;
    bool PowerAccumulate = false;
    bool FinishAccumulate = false;
    bool PenaltyMode = false;
    bool HorizonMove = false, VerticalMove = false;
    bool ShowTarget = false;
    bool y_move_ = false, z_move_ = false;
    bool Reflect = false;
    bool target1 = false, target2 = false, target3 = false, target4 = false, target5 = false;

    float shoot_yaw_ = 0, shoot_pitch_ = 0;
    float init_v_vertical, init_v_horizon;
    float relative_x_, relative_y_, relative_z_, relative_horizon_;
    float store_ball_x = 0, store_ball_y = 0, store_ball_z = 0;
    float spin_x = 0, spin_y = 0, spin_z = 0, rotate_x, rotate_y, rotate_z;
    float football_x_, football_y_ = 0.35f, football_z_;
    float football_yaw_, football_pitch_;
    float ty = 0.0f, tx =0.0f;
    float init_y_ = 0.35f, init_x_ = 0.f, init_z_ = 0.f;
    float temp_y_ = 0.0f, temp_z_ = 0.0f;
    float accumulate_t = 0.f;   // 0-60
    float init_v = 0;

    int score = 0;
    int collision_wall_num = 0;

    Vector3 init_velocity;
    Vector3 ball_velocity;
};


#endif //CPT205_GAMESTATE_H
