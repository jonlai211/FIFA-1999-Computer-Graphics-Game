//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/GameState.h"

void GameState::RenderScene() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    lighting_.Apply();

    glTranslatef(0.0, 0.0, 1.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    this->items_.DrawLawn();
    this->items_.DrawLight();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}