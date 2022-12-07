//
// Created by jonathan on 12/4/22.
//

#include "Assessment2/include/Mouse.h"
#include "Assessment2/include/GameState.h"

void GameState::MousePress(int button, int state, int x, int y) {
    mouse_.mouse_x_ = x;
    mouse_.mouse_y_ = y;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouse_.mouse_left_down_ = true;
        } else if (state == GLUT_UP)
            mouse_.mouse_left_down_ = false;
    }
}

void GameState::MouseControl(int x, int y) {
    if (mouse_.mouse_left_down_) {
        camera_.Rotate(x - mouse_.mouse_x_, y - mouse_.mouse_y_);
        mouse_.mouse_x_ = x;
        mouse_.mouse_y_ = y;
    }
}

Mouse::Mouse() {
    this->mouse_x_ = 0;
    this->mouse_y_ = 0;
    this->mouse_left_down_ = false;
    this->mouse_right_down_ = false;
}

//float Mouse::Move(int x, int y, float center_point_x, float center_point_y, float screen_rate_x, float screen_rate_y,
//                 float PI, float r, float look_x_temp, float look_z_temp, float look_x, float look_y, float look_z) {
//    float off_setx = float(x) - center_point_x;
//    float off_sety = float(y) - center_point_y;
//    screen_rate_x = off_setx / center_point_x * PI;
//    screen_rate_y = off_sety / center_point_y * PI / 2;
//    look_x_temp = r * std::sin(screen_rate_x);
//    look_z_temp = r * std::cos(screen_rate_x);
//    look_y = r * std::sin(-screen_rate_y);
//    float r_cast_length = std::abs(r * std::cos(screen_rate_y));
//    look_x = r_cast_length * look_x_temp / r;
//    look_z = r_cast_length * look_z_temp / r;
//    return center_point_x, center_point_y, screen_rate_x, screen_rate_y, look_x_temp, look_z_temp, look_x, look_y, look_z;
//}
