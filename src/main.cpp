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

void MouseWheelCallback(int wheel, int direction, int x, int y) {
    gameState.MouseWheelCallback(wheel, direction, x, y);
}

void KeyboardCallback(unsigned char key, int x, int y) {
    gameState.KeyboardControl(key, x, y);
}

void SpecialKeyCallback(int key, int x, int y) {
    gameState.KeyboardSpecialCallback(key, x, y);
}

void ReshapeCallback(int width, int height) {
    gameState.ReshapeCallback(width, height);
}

void IdleCallback() {
    gameState.IdleCallback();
}

void TimerFunc(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, TimerFunc, 1);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    /* Setup OpenGL */
    gameState.Setup();

    glutDisplayFunc(RenderCallback);
    glutReshapeFunc(ReshapeCallback);
    glutKeyboardFunc(KeyboardCallback);
    glutSpecialFunc(SpecialKeyCallback);
    glutMouseFunc(MouseCallback);
    glutMotionFunc(MouseMotionCallback);
    glutMouseWheelFunc(MouseWheelCallback);
//    glutIdleFunc(IdleCallback);
    glutTimerFunc(1000/60, TimerFunc, 1);

    /* Start rendering */
    gameState.Loop();
}