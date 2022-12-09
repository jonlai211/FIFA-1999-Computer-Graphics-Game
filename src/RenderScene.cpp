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
//    this->items_.DrawDesk();
//    this->items_.DrawChair();
//    this->items_.DrawBooks();
//    if (lighting_.GetMode() == NIGHT_MODE || lighting_.GetBrightness() < 0.00) {
//        this->items_.DrawLaptop(false);
//    } else {
//        this->items_.DrawLaptop(true);
//    }
//    this->items_.DrawBed();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}