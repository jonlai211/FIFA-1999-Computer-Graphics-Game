//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/Items.h"

Items::Items(const Football &football) : football(football) {};

Items::~Items() = default;

void Items::DrawLawn() {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->lawn_.GetID());
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(30, -0, 50);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(30, -0, -50);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-30, -0, -50);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-30, -0, 50);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.84, 0.62, 0.54);
    glPushMatrix();
    glTranslatef(0, -2, 0);
    glScalef(90, 2, 130);
    glutSolidCube(1);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->barca_.GetID());
    glColor3f(0.15, 0.78, 0.43);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(29.3, 0.1, -1.3);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(29.3, 0.1, 1.3);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(26.7, 0.1, 1.3);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(26.7, 0.1, -1.3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Items::DrawGoal() {
    glColor3f(1, 1, 1);

    // back ball frame
    glPushMatrix();
    glTranslatef(-5, 0, -45.5);
    glScalef(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 0, -45.5);
    glScalef(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, -45.5);
    glScalef(10.5, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // front ball frame
    glPushMatrix();
    glTranslatef(-5, 0, 45.5);
    glScalef(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 0, 45.5);
    glScalef(0.5, 10, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, 45.5);
    glScalef(10.5, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();
}

void Items::DrawBorder() {
    glColor3f(0.5, 0.5, 0.5);

    glPushMatrix();
    glTranslatef(0, 0, 50);
    glScalef(60, 5, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -50);
    glScalef(60, 5, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, 0);
    glScalef(0.5, 5, 100);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, 0, 0);
    glScalef(0.5, 5, 100);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 60);
    glScalef(80, 31, 5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -60);
    glScalef(80, 31, 5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40, 0, 0);
    glScalef(5, 31, 125);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40, 0, 0);
    glScalef(5, 31, 125);
    glutSolidCube(1);
    glPopMatrix();
}

void Items::DrawSeat() {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 5; j++) {
            glPushMatrix();
            if (i == 0) { glTranslatef(float(10 * j - 25), 8, 54); } else { glTranslatef(float(10 * j - 25), 8, -54); }
            if (j % 2 == 0) {
                glColor3f(0, 0.3, 0.59);
            } else {
                glColor3f(0.84, 0, 0.18);
            }
            if (i == 0) { glRotatef(30, 1, 0, 0); } else { glRotatef(-30, 1, 0, 0); }
            glScalef(10, 15, 0.5);
            glutSolidCube(1);
            glPopMatrix();
        }
    }

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 9; j++) {
            glPushMatrix();
            if (i == 0) { glTranslatef(-34, 8, float(10 * j - 45)); } else { glTranslatef(34, 8, float(10 * j - 45)); }
            if (j % 2 == 0) {
                glColor3f(0, 0.3, 0.59);
            } else {
                glColor3f(0.84, 0, 0.18);
            }
            if (i == 0) { glRotatef(30, 0, 0, 1); } else { glRotatef(-30, 0, 0, 1); }
            glScalef(0.5, 15, 10);
            glutSolidCube(1);
            glPopMatrix();
        }
    }
}

void Items::DrawTarget1(bool show) {
    if (!show) {
        glColor4f(0.92, 0.73, 0.f, 1.f);

        glPushMatrix();
        glTranslatef(-4, 4, -45.5);
        glScalef(1, 1, 0.5);
        glutSolidTorus(0.05, 0.5, 30, 30);
        glPopMatrix();
    }
}

void Items::DrawTarget2(bool show) {
    if (!show) {
        glColor4f(0.92, 0.73, 0.f, 1.f);

        glPushMatrix();
        glTranslatef(-4, 0.5, -45.5);
        glScalef(1, 1, 0.5);
        glutSolidTorus(0.05, 0.5, 30, 30);
        glPopMatrix();
    }
}

void Items::DrawTarget3(bool show) {
    if (!show) {
        glColor4f(0.92, 0.73, 0.f, 1.f);

        glPushMatrix();
        glTranslatef(0, 0.5, -45.5);
        glScalef(1, 1, 0.5);
        glutSolidTorus(0.05, 0.5, 30, 30);
        glPopMatrix();
    }
}

void Items::DrawTarget4(bool show) {
    if (!show) {
        glColor4f(0.92, 0.73, 0.f, 1.f);

        glPushMatrix();
        glTranslatef(4, 0.5, -45.5);
        glScalef(1, 1, 0.5);
        glutSolidTorus(0.05, 0.5, 30, 30);
        glPopMatrix();
    }
}

void Items::DrawTarget5(bool show) {
    if (!show) {
        glColor4f(0.92, 0.73, 0.f, 1.f);

        glPushMatrix();
        glTranslatef(4, 4, -45.5);
        glScalef(1, 1, 0.5);
        glutSolidTorus(0.05, 0.5, 30, 30);
        glPopMatrix();
    }

}

void Items::LoadAll() {
    this->lawn_.Load();
    this->barca_.Load();
    this->football.football_texture_.Load();
}