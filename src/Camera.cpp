//
// Created by jonathan on 12/7/22.
//

#include "Assessment2/include/Camera.h"

Camera::Camera() {
    this->fov_ = 60;
    this->z_near_ = 0.1f;
    this->z_far_ = 100;
    this->aspect_ratio_ = (float) (INIT_WINDOW_WIDTH / INIT_WINDOW_HEIGHT);

    this->eye_x_ = 0.0f;
    this->eye_y_ = -0.2f;
    this->eye_z_ = 1.5f;

    this->center_x_ = 0.0f;
    this->center_y_ = 0.0f;
    this->center_z_ = 0.0f;

    this->yaw_ = 0.0f;
    this->pitch_ = 0.f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov_, aspect_ratio_, z_near_, z_far_);
    LOGD("Camera initialized with: \n"
         "\t fov: %.3f, aspect_ratio: %.3f, z_near: %.3f, z_far: %.3f \n"
         "\t eye_x: %.3f, eye_y: %.3f, eye_z: %.3f \n"
         "\t center_x_: %.3f, center_y_: %.3f, center_z_: %.3f",
         fov_, aspect_ratio_, z_near_, z_far_,
         eye_x_, eye_y_, eye_z_,
         center_x_, center_y_, center_z_);
}

Camera::~Camera() = default;

void Camera::ZoomIn() {
    if (this->z_near_ < Z_NEAR_MAX) {
        this->z_near_ += Z_NEAR_STEP;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(fov_, aspect_ratio_, z_near_, z_far_);
        LOGD("Camera Zoomed in with: fov: %f, aspect_ratio: %f, z_near: %f, z_far: %f", fov_, aspect_ratio_, z_near_,
             z_far_);
    } else {
        LOGE("Camera: z_near_ is already at max value: %f", Z_NEAR_MAX);
    }
}

void Camera::ZoomOut() {
    if (this->z_near_ > Z_NEAR_MIN) {
        this->z_near_ -= Z_NEAR_STEP;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(fov_, aspect_ratio_, z_near_, z_far_);
        LOGD("Camera Zoomed out with: fov: %f, aspect_ratio: %f, z_near: %f, z_far: %f", fov_, aspect_ratio_, z_near_,
             z_far_);
    } else {
        LOGE("Camera: z_near_ is already at min value: %f", Z_NEAR_MIN);
    }
}

void Camera::MoveForwardBackward(float velocity) {
    this->eye_y_ += std::sin(pitch_) * velocity;
    this->eye_x_ -= std::cos(pitch_) * std::sin(yaw_) * velocity;
    this->eye_z_ -= std::cos(pitch_) * std::cos(yaw_) * velocity;
    this->Apply();
    LOGD("Camera moved with: eye_x_: %.3f, eye_y_: %.3f, eye_z_: %.3f", eye_x_, eye_y_, eye_z_);
}

void Camera::MoveForward() {
    MoveForwardBackward(EYE_STEP);
}

void Camera::MoveBackward() {
    MoveForwardBackward(-EYE_STEP);
}

void Camera::MoveDown() {
    this->eye_y_ -= EYE_Y_STEP;
    Apply();
}

void Camera::MoveUp() {
    this->eye_y_ += EYE_Y_STEP;
    Apply();
}

void Camera::MoveLeft() {
    this->eye_x_ -= EYE_X_STEP;
    this->Apply();
}

void Camera::MoveRight() {
    this->eye_x_ += EYE_X_STEP;
    this->Apply();
}

void Camera::Rotate(int dt_x, int dt_y) {
    this->yaw_ += (float) dt_x / 800;
    this->pitch_ += (float) dt_y / 800;
    this->Apply();
}

void Camera::Apply() {
    if (pitch_ < -1.5) pitch_ = -1.5;
    if (pitch_ > 1.5) pitch_ = 1.5;

    if (eye_x_ < EYE_X_MIN) eye_x_ = EYE_X_MIN;
    if (eye_x_ > EYE_X_MAX) eye_x_ = EYE_X_MAX;

    if (eye_y_ < EYE_Y_MIN) eye_y_ = EYE_Y_MIN;
    if (eye_y_ > EYE_Y_MAX) eye_y_ = EYE_Y_MAX;

    if (eye_z_ < EYE_Z_MIN) eye_z_ = EYE_Z_MIN;
    if (eye_z_ > EYE_Z_MAX) eye_z_ = EYE_Z_MAX;

    this->center_x_ = eye_x_ - std::sin(this->yaw_);
    this->center_z_ = eye_z_ - std::cos(this->yaw_);
    this->center_y_ = eye_y_ + std::tan(this->pitch_);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov_, aspect_ratio_, z_near_, z_far_);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x_, eye_y_, eye_z_, center_x_, center_y_, center_z_, 0.0f, 1.0f, 0.0f);
}

void Camera::Reset() {
    this->fov_ = 60;
    this->z_near_ = 0.1f;
    this->z_far_ = 100;

    this->eye_x_ = 0.0f;
    this->eye_y_ = -0.2f;
    this->eye_z_ = 1.5f;

    this->center_x_ = 0.0f;
    this->center_y_ = 0.0f;
    this->center_z_ = 0.0f;

    this->yaw_ = 0.0f;
    this->pitch_ = 0.f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov_, aspect_ratio_, z_near_, z_far_);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x_, eye_y_, eye_z_, center_x_, center_y_, center_z_, 0.0f, 1.0f, 0.0f);
}
