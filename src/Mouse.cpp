//
// Created by jonathan on 12/4/22.
//

#include "Assessment2/include/Mouse.h"
#include "Assessment2/include/GameState.h"

void GameState::MousePress(int button, int state, int x, int y) {
    mouse_.mouse_x_ = x;
    mouse_.mouse_y_ = y;
//    printf("mouse_.mouse_x_:%d; mouse_.mouse_y_:%d\n", mouse_.mouse_x_, mouse_.mouse_y_);

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouse_.mouse_left_down_ = true;
        } else if (state == GLUT_UP)
            mouse_.mouse_left_down_ = false;
    }

    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            if (ShootingMode){
                PowerAccumulate = not PowerAccumulate;
            }
        }
    }
}

void GameState::MouseControl(int x, int y) {
    if (mouse_.mouse_left_down_) {
//        printf("MouseControl_x:%d; MouseControl_y:%d\n", x, y);
        camera_.Rotate(x - mouse_.mouse_x_, y - mouse_.mouse_y_);
//        printf("RotateX:%d; Rotate:%d\n", x - mouse_.mouse_x_, y - mouse_.mouse_y_);
        mouse_.mouse_x_ = x;
        mouse_.mouse_y_ = y;
    }
}

void GameState::MouseWheelCallback(int button, int dir, int x, int y) {
    if (dir > 0) {
        camera_.fov_ += 2;
    } else {
        camera_.fov_ -= 2;
    }
//    if (dir > 0) {
//        lighting_.Brighter();
//    } else {
//        lighting_.Darker();
//    }
}

Mouse::Mouse() {
    this->mouse_x_ = 0;
    this->mouse_y_ = 0;
    this->mouse_left_down_ = false;
    this->mouse_right_down_ = false;
}
