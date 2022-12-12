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

    ShootCheck();

    this->items_.DrawLawn();
    this->items_.DrawLight();
    this->football_.DrawFootball(football_x, football_y, football_z);

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void GameState::ShootCheck() {
    if (!Shooting) {
        football_x = camera_.eye_x_;
        football_y = -0.4f;
        football_z = camera_.eye_z_ - 1.5f;
    } else {
        if (ball_velocity.y < 0.2) {
            friction_force = U * M * G;
        } else {
            friction_force = 0;
        }
        W = M * G;
        air_resistance_xyz = -0.5f * L * K * P * 4 * Pi * (R * 5 * L) * (5 * L * R) * ball_velocity.x * ball_velocity.x;
        air_resistance_zyx = -0.5f * L * K * P * 4 * Pi * (R * 5 * L) * (5 * L * R) * ball_velocity.z * ball_velocity.z;
        air_resistance_yzx = -0.5f * L * K * P * 4 * Pi * (R * 5 * L) * (5 * L * R) * ball_velocity.y * ball_velocity.y;
        air_resistance_x = -0.5f * K * P * 4 * Pi * (R * 5 * L) * (5 * L * R) * wind_speed.x * wind_speed.x;
        air_resistance_y = -0.5f * K * P * 4 * Pi * R * R * wind_speed.y * wind_speed.y * 0.0025;
        if (wind_speed.x < 0) { air_resistance_x = -air_resistance_x; }
        if (wind_speed.y < 0) { air_resistance_y = -air_resistance_y; }
        magnus_effect_x =
                -0.5f * 4 * L * Pi * (R * 5 * L) * (5 * L * R) * ball_velocity.x * ball_velocity.x * ball_velocity.x /
                R;
        Magnus_effect = {magnus_effect_y, magnus_effect_x, magnus_effect_z};
        external_force = {air_resistance_x, W, friction_force + air_resistance_y};

        ball_velocity = ball_velocity + gravity + external_force;
        football_.transform.position = football_.transform.position + ball_velocity;
        football_.transform.rotation.x += ball_velocity.z * Spin_Multiplier;

        if (football_.transform.position.y > 2) {
            ball_velocity.y = ball_velocity.y + W;
            football_.transform.position = football_.transform.position + ball_velocity;
            football_.transform.rotation.x += ball_velocity.z * Spin_Multiplier;
            printf("1.football_.transform.position.y:%.f\n", football_.transform.position.y);
        } else if (init_velocity.y < 0.6){
            friction_force = U * M * G;
            football_.transform.position.y = 0;
            football_.transform.position.z = football_.transform.position.z + ball_velocity.z + friction_force - 0.1f;
            printf("2.football_.transform.position.y:%.f\n", football_.transform.position.y);
        } else{
            ball_velocity.y = (ball_velocity.y + W + (init_velocity.y) * 0.6f);
            ball_velocity.y = (ball_velocity.y * 0.8f);
            football_.transform.position.y = ball_velocity.x * SMM;
            football_.transform.position.z += ball_velocity.z - 0.001;
            printf("3.football_.transform.position.y:%.f\n", football_.transform.position.y);
        }

//        if (v0 == 10) {
//            v0 -= f;
//            v = v0;
//        }else{
//            v0 = v;
//            v0 -= f;
//            v = v0;
//        }
//        football_z -= 0.05;
//        if (v0 < 0){
//            Shooting = false;
//        }
    }
}