//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/Items.h"
#include "Assessment2/include/Helper.h"

Items::Items() = default;

Items::~Items() = default;

void Items::DrawBorder() {
/*    // Front wall
    glColor3f(toRGB(253), toRGB(203), toRGB(97));
    glBegin(GL_QUADS);
    glVertex3f(1, 1, DEPTH_START);
    glVertex3f(-1, 1, DEPTH_START);
    glVertex3f(-1, -1, DEPTH_START);
    glVertex3f(1, -1, DEPTH_START);
    glEnd();

    // Front door
    glColor3f(toRGB(255), toRGB(255), toRGB(255));
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->door_.GetID());
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.2, 0.3, DEPTH_START - 0.001);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-0.2, 0.3, DEPTH_START - 0.001);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-0.2, -0.995, DEPTH_START - 0.001);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.2, -0.995, DEPTH_START - 0.001);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // Back
    glColor3f(toRGB(253), toRGB(203), toRGB(97));
    glBegin(GL_QUADS);
    glVertex3f(1, 1, DEPTH_END);
    glVertex3f(-1, 1, DEPTH_END);
    glVertex3f(-1, -1, DEPTH_END);
    glVertex3f(1, -1, DEPTH_END);
    glEnd();

    // Ceiling
    glColor3f(toRGB(236), toRGB(240), toRGB(241));
    glBegin(GL_QUADS);
    glVertex3f(1, 1, DEPTH_START);
    glVertex3f(-1, 1, DEPTH_START);
    glVertex3f(-1, 1, DEPTH_END);
    glVertex3f(1, 1, DEPTH_END);
    glEnd();*/

    // Ground
    glColor3f(1.0, 1.0, 0.5);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->floor_.GetID());
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(1, -1, DEPTH_START);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(1, -1, DEPTH_END);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(-1, -1, DEPTH_END);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(-1, -1, DEPTH_START);
    glEnd();
    glDisable(GL_TEXTURE_2D);

/*    // Left
    glColor3f(toRGB(199), toRGB(236), toRGB(238));
//    glColor3f(1.0, 1.0, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-1, -1, DEPTH_START);
    glVertex3f(-1, -1, DEPTH_END);
    glVertex3f(-1, 1, DEPTH_END);
    glVertex3f(-1, 1, DEPTH_START);
    glEnd();

    // Right
    glColor3f(toRGB(199), toRGB(236), toRGB(238));
    glBegin(GL_QUADS);
    glVertex3f(1, -1, DEPTH_START);
    glVertex3f(1, 1, DEPTH_START);
    glVertex3f(1, 1, DEPTH_END);
    glVertex3f(1, -1, DEPTH_END);
    glEnd();*/

/*    // Right wall poster
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->poster_.GetID());
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.99, -0.5, DEPTH_START - 1.5);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.99, 0.5, DEPTH_START - 1.5);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.99, 0.5, DEPTH_END + 2.0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.99, -0.5, DEPTH_END + 2.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);*/

/*    // Right wall window
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->window_.GetID());
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(0.99, -0.5, DEPTH_END + 0.7);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(0.99, 0.5, DEPTH_END + 0.7);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.99, 0.5, DEPTH_END + 1.2);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.99, -0.5, DEPTH_END + 1.2);
    glEnd();
    glDisable(GL_TEXTURE_2D);*/
}

void Items::DrawLight() {
    // Light base
    glColor3f(0.55, 0.27, 0.07);
    glPushMatrix();
    glTranslatef(0.0, 0.99, -0.4);
    glScalef(0.6, 0.02, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    // Light
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.96, -0.4);
    glScalef(0.4, 0.06, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();
}

//void Items::DrawDesk() {
////    glColor3f(toRGB(205),toRGB(97),toRGB(51));
//    glColor3f(0.9, 0.8, 0.4);
//
//    // Middle support
//    glPushMatrix();
//    glTranslatef(0.0, -0.2, DEPTH_END + 0.4);
//    glScalef(1.6, 0.02, 0.5);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Teacup
//    glColor3f(toRGB(255), toRGB(255), toRGB(255));
//    glPushMatrix();
//    glTranslatef(-0.05, -0.16, DEPTH_END + 0.55);
//    glScalef(0.1, 0.1, 0.1);
//    glutSolidTeacup(1.0);
//    glPopMatrix();
//
//    // Top
//    glColor3f(0.9, 0.8, 0.4);
//    glPushMatrix();
//    glTranslatef(0.0, 0.3, DEPTH_END + 0.3);
//    glScalef(1.6, 0.02, 0.5);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Right
//    glPushMatrix();
//    glTranslatef(0.8, -0.25, DEPTH_END + 0.3);
//    glScalef(0.02, 1.5, 0.5);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Left
//    glPushMatrix();
//    glTranslatef(-0.8, -0.25, DEPTH_END + 0.3);
//    glScalef(0.02, 1.5, 0.5);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Back
//    glPushMatrix();
//    glTranslatef(0.0, -0.25, DEPTH_END + 0.3);
//    glScalef(1.64, 1.5, 0.02);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Items
//    glPushMatrix();
//    glTranslatef(-0.55, -0.6, DEPTH_END + 0.3);
//    glScalef(0.5, 0.8, 0.4);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    glColor3f(0.55, 0.27, 0.07);
//    glPushMatrix();
//    glTranslatef(-0.35, -0.6, DEPTH_END + 0.5);
//    glScalef(0.02, 0.15, 0.04);
//    glutSolidCube(1.0);
//    glPopMatrix();
//}
//
//void Items::DrawChair() {
//    // Chair Top
//    glColor3f(0.7, 0.8, 0.4);
//    glPushMatrix();
//    glTranslatef(0.3, -0.5, DEPTH_END + 0.6);
//    glScalef(0.45, 0.06, 0.3);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Chair Supporters
//    glPushMatrix();
//    glTranslatef(0.49, -0.75, DEPTH_END + 0.69);
//    glScalef(0.02, 0.5, 0.02);
//    glutSolidCylinder(0.5, 0.5, 32, 32);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0.49, -0.75, DEPTH_END + 0.51);
//    glScalef(0.02, 0.5, 0.02);
////    glutSolidCube(1.0);
//    glutSolidCylinder(0.5, 0.5, 32, 32);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0.11, -0.75, DEPTH_END + 0.69);
//    glScalef(0.02, 0.5, 0.02);
//    glutSolidCylinder(0.5, 0.5, 32, 32);
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0.11, -0.75, DEPTH_END + 0.51);
//    glScalef(0.02, 0.5, 0.02);
//    glutSolidCylinder(0.5, 0.5, 32, 32);
//    glPopMatrix();
//}
//
//void Items::DrawBooks() {
//    glColor3f(0.5, 0.5, 0.0);
//    glPushMatrix();
//    glTranslatef(-0.76, 0.45, DEPTH_END + 0.4);
//    glScalef(0.04, 0.3, 0.15);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    glColor3f(0.5, 0.0, 0.5);
//    glPushMatrix();
//    glTranslatef(-0.7, 0.4, DEPTH_END + 0.4);
//    glScalef(0.08, 0.2, 0.12);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    glColor3f(0.0, 0.5, 0.5);
//    glPushMatrix();
//    glTranslatef(-0.64, 0.43, DEPTH_END + 0.4);
//    glScalef(0.02, 0.26, 0.15);
//    glutSolidCube(1.0);
//    glPopMatrix();
//}
//
//void Items::DrawLaptop(bool display) {
//    // Keyboard
//    glColor3f(toRGB(50), toRGB(50), toRGB(50));
//    glPushMatrix();
//    glTranslatef(0.3, -0.16, DEPTH_END + 0.55);
//    glScalef(0.4, 0.02, 0.3);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Display
//    glColor3f(0.0, 0.0, 0.0);
//    glPushMatrix();
//    glTranslatef(0.3, 0.05, DEPTH_END + 0.4);
//    glScalef(0.4, 0.4, 0.01);
////    glRotatef(45, 1, 0, 0);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    if (display) {
//        // Display Screenshot 1
//        glColor3f(toRGB(255), toRGB(255), toRGB(255));
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D, this->screen_.GetID());
//        glBegin(GL_QUADS);
//        glTexCoord2f(0.0, 0.0);
//        glVertex3f(0.105, -0.14, DEPTH_END + 0.406);
//        glTexCoord2f(0.0, 1.0);
//        glVertex3f(0.105, 0.24, DEPTH_END + 0.406);
//        glTexCoord2f(1.0, 1.0);
//        glVertex3f(0.495, 0.24, DEPTH_END + 0.406);
//        glTexCoord2f(1.0, 0.0);
//        glVertex3f(0.495, -0.14, DEPTH_END + 0.406);
//        glEnd();
//        glDisable(GL_TEXTURE_2D);
//    } else {
//        // do nothing
//    }
//
//    // Keyboard
//    glColor3f(toRGB(255), toRGB(255), toRGB(255));
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, this->keyboard_.GetID());
//    glBegin(GL_QUADS);
////    glTranslatef(0.3, -0.16, DEPTH_END + 0.55);
////    glScalef(0.4, 0.02, 0.3);
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f(0.102, -0.149, DEPTH_END + 0.7);
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(0.102, -0.149, DEPTH_END + 0.42);
//    glTexCoord2f(1.0, 1.0);
//    glVertex3f(0.498, -0.149, DEPTH_END + 0.42);
//    glTexCoord2f(1.0, 0.0);
//    glVertex3f(0.498, -0.149, DEPTH_END + 0.7);
//    glEnd();
//    glDisable(GL_TEXTURE_2D);
//}
//
//void Items::DrawBed() {
//
//    glColor3f(toRGB(255), toRGB(193), toRGB(140));
//
//    // Bed base
//    glPushMatrix();
//    glTranslatef(-0.3, -0.86, DEPTH_END + 2.0);
//    glScalef(1.4, 0.25, 1.0);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Bed Supporter
//    glPushMatrix();
//    glTranslatef(-0.975, -0.4, DEPTH_END + 2.0);
//    glScalef(0.05, 0.7, 1.0);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    // Quilts
//    glColor3f(toRGB(255), toRGB(255), toRGB(255));
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, this->quilt_.GetID());
//    glBegin(GL_QUADS);
//    glTexCoord2f(1.0, 1.0);
//    glVertex3f(-0.95, -0.734, DEPTH_END + 2.5);
//    glTexCoord2f(1.0, 0.0);
//    glVertex3f(-0.95, -0.734, DEPTH_END + 1.5);
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f(0.4, -0.734, DEPTH_END + 1.5);
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(0.4, -0.734, DEPTH_END + 2.5);
//    glEnd();
//    glDisable(GL_TEXTURE_2D);
//
//    // Bedside
//    glColor3f(toRGB(255), toRGB(255), toRGB(255));
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, this->bedside_.GetID());
//    glBegin(GL_QUADS);
//    glTexCoord2f(1.0, 1.0);
//    glVertex3f(-0.949, -0.734, DEPTH_END + 2.5);
//    glTexCoord2f(1.0, 0.0);
//    glVertex3f(-0.949, -0.734, DEPTH_END + 1.5);
//    glTexCoord2f(0.0, 0.0);
//    glVertex3f(-0.949, -0.05, DEPTH_END + 1.5);
//    glTexCoord2f(0.0, 1.0);
//    glVertex3f(-0.949, -0.05, DEPTH_END + 2.5);
//    glEnd();
//    glDisable(GL_TEXTURE_2D);
//
//    // Pillow
//    glColor3f(toRGB(220), toRGB(220), toRGB(220));
//    glPushMatrix();
//    glTranslatef(-0.85, -0.75, DEPTH_END + 1.8);
//    glScalef(0.05, 0.08, 0.40);
//    glutSolidCylinder(2, 1, 32, 32);
//    glPopMatrix();
//
//}

void Items::LoadAll() {
    this->floor_.Load();
    this->poster_.Load();
    this->screen_.Load();
    this->door_.Load();
    this->keyboard_.Load();
    this->quilt_.Load();
    this->bedside_.Load();
    this->window_.Load();
}