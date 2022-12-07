/**
 * @file main.cpp
 *
 * @brief Main function of CPT205 assessment2.
 *
 * @author Kaijie Lai 2034675
 *
 * @email Kaijie.Lai20@student.xjtlu.edu.cn
 */

#include "Assessment2/include/main.h"

GameState gameState(true);

void RenderCallback() {
    gameState.RenderScene();
}

void MouseCallback(int button, int state, int x, int y) {
    gameState.MousePress(button, state, x, y);
}

void MouseMotionCallback(int x, int y) {
    gameState.MouseControl(x, y);
}

void KeyboardCallback(unsigned char key, int x, int y) {
    gameState.KeyboardControl(key, x, y);
}

void ReshapeCallback(int width, int height) {
    gameState.ReshapeCallback(width, height);
}

void IdleCallback() {
    gameState.IdleCallback();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    /* Setup OpenGL */
    gameState.Setup();

    glutDisplayFunc(RenderCallback);
    glutReshapeFunc(ReshapeCallback);
    glutKeyboardFunc(KeyboardCallback);
    glutMouseFunc(MouseCallback);
    glutMotionFunc(MouseMotionCallback);
    glutIdleFunc(IdleCallback);

    /* Start rendering */
    gameState.Loop();
}