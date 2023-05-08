//
// Created by jonathan on 12/10/22.
//

#include "Assessment2/include/Items.h"
#include "Assessment2/include/Football.h"

Football::Football(float x, float y, float z) : transform(x, y, z) {
    transform.position.x = camera.eye_x_;
//    transform.position.y = 1.1f;
    transform.position.y = 0.35f;
    transform.position.z = camera.eye_z_ + 4;
}

Football::~Football() = default;

bool Football::CollisionCheck(float x, float z) {
    return false;
}

void Football::DrawFootball(float x, float y, float z, float rotate_x, float rotate_y, float rotate_z) {
    if (x > 28) { x = 28; } else if (x < -28) { x = -28; } else if (z > 48) { z = 48; } else if (z < -48) { z = -48; }

    glPushMatrix();
    glFrontFace(GL_CCW);
    glTranslatef(x, y, z);
//    SpinFootball(w, s, a, d);
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);
    glRotatef(rotate_z, 0, 0, 1);
    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->football_texture_.GetID());
    ball_quadric = gluNewQuadric();
    gluQuadricDrawStyle(ball_quadric, GLU_FILL);
    gluQuadricNormals(ball_quadric, GLU_SMOOTH);
    gluQuadricOrientation(ball_quadric, GLU_OUTSIDE);
    gluQuadricTexture(ball_quadric, GL_TRUE);
    gluSphere(ball_quadric, ball_radius, 50, 35);
    glPopMatrix();
    glEnd();
    glDisable(GL_TEXTURE_2D);
}