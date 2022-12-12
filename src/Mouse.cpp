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
//        printf("RotateX:%d; Rotate:%d\n", x - mouse_.mouse_x_, y - mouse_.mouse_y_);
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
