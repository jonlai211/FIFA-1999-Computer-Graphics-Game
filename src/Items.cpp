//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/Items.h"

Items::Items(const Football& football) : football(football) {};

Items::~Items() = default;

void Items::DrawLawn() {
    glColor3f(0, 0, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->lawn_.GetID());
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(30, -0, DEPTH_START);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(30, -0, DEPTH_END);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-30, -0, DEPTH_END);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-30, -0, DEPTH_START);
    glDisable(GL_TEXTURE_2D);
    glEnd();
}

void Items::DrawLight() {
//    // Light base
//    glColor3f(0.55, 0.27, 0.07);
//    glPushMatrix();
//    glTranslatef(0.0, 0.99, -0.4);
//    glScalef(0.6, 1.02, 0.4);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Light
//    glColor3f(1.0, 1.0, 1.0);
//    glPushMatrix();
//    glTranslatef(0.0, 0.96, -0.4);
//    glScalef(0.4, 1.06, 0.2);
//    glutSolidCube(1.0);
//    glPopMatrix();
}

void Items::LoadAll() {
    this->lawn_.Load();
    this->football.football_texture_.Load();
}