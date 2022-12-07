//
// Created by jonathan on 12/4/22.
//

#include "Assessment2/include/GameState.h"

GameState::GameState(bool debug_mode) {
    this->debug_mode_ = debug_mode;
    LOGI("Game object created");
}

GameState::~GameState() = default;

void GameState::Setup() {

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

    /* Set window properties */
    glutInitWindowSize(INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT);
    glutInitWindowPosition(INIT_WINDOW_X, INIT_WINDOW_Y);
    glutCreateWindow(WINDOW_TITLE);

    // Initial Content and Setup
    glClearColor(toRGB(255), toRGB(255), toRGB(255), 1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_MULTISAMPLE);
    glEnable(GLUT_MULTISAMPLE);
    glutSetOption(GLUT_MULTISAMPLE, 8);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);

    LOGI("OpenGL initialized");

    this->items_.LoadAll();
    LOGI("Texture loaded");
}

void GameState::Loop() {
    LOGI("Rendering started");
    glutMainLoop();
}

void GameState::ReshapeCallback(int width, int height) {
    // Prevent a divide by zero, when window is too short
    if (height == 0) {
        height = 1;
    }

    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    camera_.Apply();
}

void GameState::IdleCallback() {
    glutPostRedisplay();
}

//void GameState::KeyboardControl(unsigned char key, int x, int y) const {
//    if (key == 'w' or key == 's' or key == 'a' or key == 'd') {
//        keyboard.Move(key, look_x_temp, look_z_temp, camera_pos_x, camera_pos_z);
//        std::cout << "camera_pos_x: " << camera_pos_x << " camera_pos_z: " << camera_pos_z << std::endl;
//    }
//}

//void GameState::MouseControl(int button, int state, int x, int y) {
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//        mouse.Move(x, y, center_point_x, center_point_y, screen_rate_x, screen_rate_y,
//                   PI, r, look_x_temp, look_z_temp, look_x, look_y, look_z);
//    }
//}