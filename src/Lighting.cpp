//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/Lighting.h"

Lighting::Lighting() {
    brightness_ = 0.25;
}

void Lighting::Apply() {
    GLfloat light_0_pos[] = {0.0, 100.0, -300.0, 1.0};
    GLfloat light_0_ambient[] = {0.2, 0.2, 0.2, 0.3f};
    GLfloat light_0_diffuse[] = {1.0, 1.0, 1.0, 0.3};

    glLightfv(GL_LIGHT0, GL_POSITION, light_0_pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_ambient);

    GLfloat light_1_pos[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_1_ambient[] = {0.1, 0.1, 0.1, 0.3};
    GLfloat light_1_diffuse[] = {0.1, 0.1, 0.1, 0.3};

    glLightfv(GL_LIGHT1, GL_POSITION, light_1_pos);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_diffuse);

    GLfloat material[] = {brightness_, brightness_, brightness_, 1.0};

    glMaterialfv(GL_FRONT, GL_EMISSION, material);
}

LightingMode Lighting::GetMode() {
    return mode_;
}

void Lighting::Brighter() {
    if (brightness_ < BRIGHTNESS_MAX) {
        brightness_ += BRIGHTNESS_STEP;
    }
}

void Lighting::Darker() {
    if (brightness_ > BRIGHTNESS_MIN) {
        brightness_ -= BRIGHTNESS_STEP;
    }
}

void Lighting::SetMode(LightingMode mode) {
    mode_ = mode;
    if (mode_ == DAY_MODE) {
        brightness_ = 0.25;
    } else if (mode_ == NIGHT_MODE) {
        brightness_ = 0.0;
    }
}

float Lighting::GetBrightness() {
    return this->brightness_;
}

void Lighting::SetBrightness(float brightness) {
    this->brightness_ = brightness;
}
