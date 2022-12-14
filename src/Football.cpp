//
// Created by jonathan on 12/10/22.
//

#include "Assessment2/include/Items.h"
#include "Assessment2/include/Football.h"


Football::Football(float x, float y, float z) : transform(x, y, z) {
    transform.position.x = camera.eye_x_;
    transform.position.y = 1.1f;
    transform.position.z = camera.eye_z_ - 10;
}

Football::~Football() = default;

bool Football::CollisionCheck() {
    return false;
}

void Football::DrawFootball(float x, float y, float z) {
    glPushMatrix();
    glFrontFace(GL_CCW);
//    glTranslatef(transform.position.x, transform.position.y, transform.position.z);
    glTranslatef(x, y, z);
    glRotatef(transform.rotation.x, 1, 0, 0);
    glRotatef(transform.rotation.y, 0, 1, 0);
    glRotatef(transform.rotation.z, 0, 0, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->football_texture_.GetID());
    ball_quadric = gluNewQuadric();
    gluQuadricDrawStyle(ball_quadric, GLU_FILL);
    gluQuadricNormals(ball_quadric, GLU_SMOOTH);
    gluQuadricOrientation(ball_quadric, GLU_OUTSIDE);
    gluQuadricTexture(ball_quadric, GL_TRUE);
    gluSphere(ball_quadric, ball_radius, 50, 35);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
