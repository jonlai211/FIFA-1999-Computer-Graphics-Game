//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/GameState.h"

void GameState::RenderScene() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    lighting_.Apply();
    camera_.Apply();

    glTranslatef(0.0, 0.0, 1.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    football_yaw_ = camera_.yaw_;
    football_pitch_ = camera_.pitch_;
    DisplayText(1105, 700, "FOV         : ", int(camera_.fov_));
    DisplayText(1105, 680, "Yaw   Angle : ", int(football_yaw_ * 180 / M_PI));
    DisplayText(1105, 660, "Pitch Angle : ", int(football_pitch_ * 180 / M_PI));

    InteractionScene();

    this->items_.DrawLawn();
    this->items_.DrawGoal();
    this->items_.DrawBorder();
    this->items_.DrawSeat();

    if (ShowTarget) {
        ScoreCheck();
        this->items_.DrawTarget1(target1);
        this->items_.DrawTarget2(target2);
        this->items_.DrawTarget3(target3);
        this->items_.DrawTarget4(target4);
        this->items_.DrawTarget5(target5);
    }

    DisplayText(600, 700, "Score: ", score);

    SpinControl(shoot_yaw_);
    this->football_.DrawFootball(football_x_, football_y_, football_z_, spin_x, spin_y, spin_z);
//    printf("football_x:%f, football_y:%f, football_z:%f\n", football_x_, football_y_, football_z_);

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void GameState::InteractionScene() {
    if (FreeMode) {
        DisplayTextOnly(20, 700, "Mode FreePlay On!");
    } else {
        DisplayTextOnly(20, 700, "Mode FreePlay Off!");
    }
    if (ShootingMode) {
        DisplayTextOnly(20, 680, "Mode Shooting On!");
    } else {
        DisplayTextOnly(20, 680, "Mode Shooting Off!");
    }
    if (PenaltyMode) {
        DisplayTextOnly(20, 660, "Mode FreePlay On!");
    } else {
        DisplayTextOnly(20, 660, "Mode FreePlay Off!");
    }

    if (ShootingMode and !FreeMode) {
        if (PenaltyMode) {
            InitPenalty();
            ShowTarget = true;
            PenaltyMode = false;
        }
        if (PowerAccumulate) {
            shoot_yaw_ = camera_.yaw_;
            shoot_pitch_ = camera_.pitch_;
            init_y_ = football_y_;
            init_x_ = football_x_;
            init_z_ = football_z_;
//            printf("init_x:%f, init_z:%f\n", init_x_, init_z_);
            VelocityCalculate(shoot_yaw_, shoot_pitch_);
            FinishAccumulate = true;
//            printf(("init_x:%f; init_y:%f, ini_z:%f\n"), init_x_, init_y_, init_z_);
        }
        LOGD("init_v_h:%f, init_v_v:%f", init_v_horizon, init_v_vertical);
        if ((!PowerAccumulate) and FinishAccumulate) {
            accumulate_t = 0;
            CollisionCheck(football_x_, football_z_);
            VerticalMovement(init_v_vertical);
            HorizonMovement(init_v_horizon, shoot_yaw_);
            if (init_v_horizon == 0 and init_v_vertical == 0) {
                FinishAccumulate = false;
            }
        }
    } else if (!ShootingMode and !FreeMode) {
        AlwaysForward(camera_.eye_x_, camera_.eye_z_, camera_.yaw_);
    }
}

void GameState::CollisionCheck(float x, float z) {
    if (z > 48) {
        collision_wall_num = 1; // hit front wall
    } else if (z < -48) {
        collision_wall_num = 2; // hit back wall
    } else if (x > 28) {
        collision_wall_num = 3; // hit left wall
    } else if (x < -28) {
        collision_wall_num = 4; // hit right wall
    } else {
        collision_wall_num = 0;
    }
}

void GameState::VelocityCalculate(float yaw, float pitch) {
    accumulate_t += 0.25;
    if (accumulate_t >= 60.f) {
        accumulate_t = 60.f;
    }
    DisplayAccumulateBar(1200, 360, accumulate_t);
    init_v = 2 * accumulate_t;     // accumulate_t = 0-60

    init_v_vertical = init_v * sin(pitch);
    init_v_horizon = init_v * cos(pitch);
//    printf("init_v_vertical:%f, init_v_horizon:%f\n", init_v_vertical, init_v_horizon);
    if (init_v_vertical >= 60) {
        init_v_vertical = 60;
    }
    if (init_v_horizon >= 80) {
        init_v_horizon = 80;
    }
}

void GameState::VerticalMovement(float vy) {
    float min_speed = 2;

//    printf("vy:%f\n", vy);
    if (vy < min_speed) {
        vy = 0;
        init_v_vertical = 0;
        football_y_ = 0.35f;
        VerticalMove = false;
    } else {
        VerticalMove = true;
    }

    if (VerticalMove) {
        ty += 0.016;
        relative_y_ = vy * ty - 0.5f * 80.0f * ty * ty;
        football_y_ = relative_y_ + init_y_;
//        printf("football_y:%f\n", football_y_);

        if (football_y_ < 0.35) {
            ty = 0;
            init_v_vertical = init_v_vertical * 0.5f;
            football_y_ = 0.35f;
        }
    }
}

void GameState::HorizonMovement(float v, float yaw) {
    float u = 10.0f;
    float vx, vz;

    if ((v - u * tx) < 0) {
        tx = 0;
        v = 0;
//        init_v_horizon = 0;
        init_x_ = football_x_;
        init_z_ = football_z_;
        HorizonMove = false;
    } else {
        HorizonMove = true;
    }

    if (HorizonMove) {
        tx += 0.016;
        relative_horizon_ = -(v * tx - 0.5f * u * tx * tx);
//        printf("v:%f\n", (v - u * tx));
        football_x_ = init_x_ + relative_horizon_ * sin(yaw);
        football_z_ = init_z_ + relative_horizon_ * cos(yaw);
//        printf("football_x_:%f\n", football_x_);

        switch (collision_wall_num) {
            case 1:
                init_v_horizon = -(init_v_horizon - u * tx);
                tx = 0;
                football_z_ = 48;
                init_z_ = 48;
                init_x_ = football_x_;
                Reflect = true;
                collision_wall_num = 0;
                break;
            case 2:
                init_v_horizon = -(init_v_horizon - u * tx);
                tx = 0;
                football_z_ = -48;
                init_z_ = -48;
                init_x_ = football_x_;
                Reflect = true;
                collision_wall_num = 0;
                break;
            case 3:
                init_v_horizon = -(init_v_horizon - u * tx);
                tx = 0;
                football_x_ = 28;
                init_x_ = 28;
                init_z_ = football_z_;
                Reflect = true;
                collision_wall_num = 0;
                break;
            case 4:
                init_v_horizon = -(init_v_horizon - u * tx);
                tx = 0;
                football_x_ = -28;
                init_x_ = -28;
                init_z_ = football_z_;
                Reflect = true;
                collision_wall_num = 0;
                break;
            case 0:
                break;
        }
    }
}

void GameState::AlwaysForward(float x, float z, float yaw) {
    football_x_ = x - sin(yaw) * 4;
    football_z_ = z - cos(yaw) * 4;
}

void GameState::ResetBallPosition() {
    AlwaysForward(camera_.eye_x_, camera_.eye_z_, camera_.yaw_);
}

void GameState::InitPenalty() {
    camera_.eye_x_ = 0.f;
    camera_.eye_y_ = 1.0f;
    camera_.eye_z_ = -31.f;
    football_x_ = 0.f;
    football_y_ = 0.35f;
    football_z_ = -37.5f;
}

void GameState::ScoreCheck() {
    if (football_x_ > -4.5 and football_x_ < -3.5
        and football_y_ > 3.5 and football_y_ < 4.5
        and football_z_ > -46 and football_z_ < -45) {
        target1 = true;
    }

    if (football_x_ > -4.5 and football_x_ < -3.5
        and football_y_ > 0 and football_y_ < 1
        and football_z_ > -46 and football_z_ < -45) {
        target2 = true;
    }

    if (football_x_ > -0.5 and football_x_ < 0.5
        and football_y_ > 0 and football_y_ < 1
        and football_z_ > -46 and football_z_ < -45) {
        target3 = true;
    }

    if (football_x_ > 3.5 and football_x_ < 4.5
        and football_y_ > 0 and football_y_ < 1
        and football_z_ > -46 and football_z_ < -45) {
        target4 = true;
    }

    if (football_x_ > 3.5 and football_x_ < 4.5
        and football_y_ > 3.5 and football_y_ < 4.5
        and football_z_ > -46 and football_z_ < -45) {
        target5 = true;
    }

    if (target1 or target2 or target3 or target4 or target5) {
        score = 1;
    }
    if ((target1 and target2) or (target1 and target3) or (target1 and target4) or (target1 and target5) or
        (target2 and target3) or (target2 and target4) or (target2 and target5) or (target3 and target4) or
        (target3 and target5) or (target4 and target5)) {
        score = 2;
    }
    if ((target1 and target2 and target3) or (target1 and target2 and target4) or
        (target1 and target2 and target5) or (target1 and target3 and target4) or
        (target1 and target3 and target5) or (target1 and target4 and target5) or
        (target2 and target3 and target4) or (target2 and target3 and target5) or
        (target2 and target4 and target5) or (target3 and target4 and target5)) {
        score = 3;
    }
    if ((target1 and target2 and target3 and target4) or (target1 and target2 and target3 and target5) or
        (target2 and target3 and target4 and target5)) {
        score = 4;
    }
    if (target1 and target2 and target3 and target4 and target5) {
        score = 5;
    }
}

void GameState::SpinControl(float yaw) {
    if (football_x_ > store_ball_x) spin_z -= 3;
    if (football_x_ < store_ball_x) spin_z += 3;
    if (football_z_ > store_ball_z) spin_x += 3;
    if (football_z_ < store_ball_z) spin_x -= 3;
    store_ball_x = football_x_;
    store_ball_y = football_y_;
    store_ball_z = football_z_;
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

void GameState::DisplayTextOnly(GLfloat x, GLfloat y, const std::string &message) const {
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0.0, INIT_WINDOW_WIDTH, 0.0, INIT_WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(10, 10);

    std::string output = message;
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
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

    glColor4f(0.45, 0.77, 1., 0);
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
    glColor4f(0.99, 0.92, 0.52, 0);
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