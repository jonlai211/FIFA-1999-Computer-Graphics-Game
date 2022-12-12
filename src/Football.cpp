//
// Created by jonathan on 12/10/22.
//

#include "Assessment2/include/Items.h"

Football::Football(float x, float y, float z) : transform(x, y, z) {
//    transform.position.x = 0;
//    transform.position.y = -0.4;
//    transform.position.z = 0;

    transform.position.x = camera.eye_x_;
    transform.position.y = camera.eye_y_;
    transform.position.z = camera.eye_z_;
//    printf("football_x: %f, football_y: %f, football_z: %f", transform.position.x, transform.position.y, transform.position.z);
//    transform.scale.x = ball_radius;
//    transform.scale.y = ball_radius;
//    transform.scale.z = ball_radius;
}

Football::~Football() = default;

bool Football::CollisionCheck() {
    return false;
}

void Football::DrawFootball(float x, float y, float z) {
    glPushMatrix();
    glFrontFace(GL_CCW);
//    glTranslatef(transform.position.x, transform.position.y, transform.position.z);
    glTranslatef(0, 1.1, 0);
    glRotatef(transform.rotation.x, 1, 0, 0);
    glRotatef(transform.rotation.y, 0, 1, 0);
    glRotatef(transform.rotation.z, 0, 0, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->ball_texture_.GetID());
    ball_quadric = gluNewQuadric();
    gluQuadricDrawStyle(ball_quadric, GLU_FILL);
    gluQuadricNormals(ball_quadric, GLU_SMOOTH);
    gluQuadricOrientation(ball_quadric, GLU_OUTSIDE);
    gluQuadricTexture(ball_quadric, GL_TRUE);
    gluSphere(ball_quadric, ball_radius, 50, 35);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}