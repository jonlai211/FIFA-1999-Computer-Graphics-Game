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

    football_yaw_ = camera_.yaw_;
    football_pitch_ = camera_.pitch_;

//    PowerCalculate(1, football_yaw_, football_pitch_);

    ShootScene();

    this->items_.DrawLawn();
    this->items_.DrawLight();
    this->football_.DrawFootball(football_x_, football_y_, football_z_);

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void GameState::ShootScene() {
    if (!FPS_mode) {
        if (Shoot_Accumulate) {
            accumulate_t += 0.25;
            DisplayText(50, 650, "Argentina: ", 1);
            DisplayAccumulateBar(1200, 360, accumulate_t);
            if (accumulate_t >= 60.f) {
                accumulate_t = 60.f;
            }
        } else {
            accumulate_t = 0;
        }
    }

    if (!Shooting) {
        football_x_ = camera_.eye_x_ - 10.f;
        football_z_ = camera_.eye_z_ - 10.f;
    } else {
        if (y_move_) {
            ty += 0.016;
            football_y_ = init_y_ + init_velocity.y * ty - 0.5f * 80.0f * ty * ty;
            if (football_y_ < 0) {
                ty = 0.0f;
                init_velocity.y = init_velocity.y * 0.8f;
            }
            if (init_velocity.y < 10) {
                init_velocity.y = 0;
                football_y_ = 1.1f;
                y_move_ = not y_move_;
            }
        }
        if (z_move_) {
            tz += 0.016;
            football_z_ = -(init_z_ + init_velocity.z * tz - 0.5f * 5.0f * tz * tz);
            if ((init_velocity.z - 5.0f * tz) < 0) {
                z_move_ = not z_move_;
            }
        }
    }
}

void GameState::DisplayText(GLfloat x, GLfloat y, const std::string &message, int num) const {

    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, INIT_WINDOW_WIDTH, 0.0, INIT_WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(10, 10);


    std::string output = message + std::to_string(num);
    glPushMatrix();
    if (num < 0) { glColor3f(1.0, 0.0, 0.0); } // Red
    else { glColor3f(0.0, 0.0, 0.0); } // Green
    glRasterPos2i(int(x), int(y));

    for (std::string::iterator i = output.begin(); i != output.end(); ++i) // Iterator for message.
    {
        char c = *i;
        glutBitmapCharacter(font, c);
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
}

void GameState::DisplayAccumulateBar(GLfloat x, GLfloat y, float t) {

    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, INIT_WINDOW_WIDTH, 0.0, INIT_WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(10, 10);

    float base_PI = 3.14;
    float base_PI_HALF = base_PI / 2;
    float base_divide = 100.0;            //high value point high precision
    float tx, ty;

    glColor4f(0.45, 0.77, 1., 1);
    glBegin(GL_POLYGON);
    int opX[4] = {1, -1, -1, 1};
    int opY[4] = {1, 1, -1, -1};        //counting times in operation by four Quadrants
    float base_x = 0;
    float base_part = 1 / base_divide;
    int w_size = 40 / 2 - 10;       // cirR = 1
    int h_size = 250 / 2 - 10;
    for (base_x = 0; base_x < 4; base_x += base_part) {
        float rad = base_PI_HALF * base_x;    //calculate arc
        tx = 10 * cos(rad) + opX[(int) base_x] * w_size + x;
        ty = 10 * sin(rad) + opY[(int) base_x] * h_size + y;
        glVertex2f(tx, ty);
    }
    glEnd();

    float tx_2, ty_2;
    glColor4f(0.99, 0.92, 0.52, 1);
    glBegin(GL_POLYGON);
    int opX_2[4] = {1, -1, -1, 1};
    int opY_2[4] = {1, 1, -1, -1};        //counting times in operation by four Quadrants
    float base_x_2 = 0;
    float base_part_2 = 1 / base_divide;
    int w_size_2 = 30 / 2 - 10;     // cirR = 10
    int h_size_2 = (20 + 3.6 * t) / 2 - 10;    // max = 240
    for (base_x_2 = 0; base_x_2 < 4; base_x_2 += base_part_2) {
        float rad_2 = base_PI_HALF * base_x_2;    //calculate arc
        tx_2 = 10 * cos(rad_2) + opX_2[(int) base_x_2] * w_size_2 + x;
        ty_2 = 10 * sin(rad_2) + opY_2[(int) base_x_2] * h_size_2 + y - 110 + 1.83 * t;
        glVertex2f(tx_2, ty_2);
    }
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
}

void GameState::PowerCalculate(float t, float yaw, float pitch) {
    init_v = 0.5f * t + 400;
    init_velocity.x = init_v * sin(pitch);
    init_velocity.y = init_v * sin(pitch) * cos(yaw);
    init_velocity.z = init_v * sin(pitch) * sin(yaw);
    float angle_pitch = std::asin(pitch);
    float angle_yaw = std::acos(yaw);

//    printf("pitch:%f; yaw:%f; vx:%f; vy:%f; vz:%f\n",angle_pitch,  init_velocity.x, init_velocity.y, init_velocity.z);
}