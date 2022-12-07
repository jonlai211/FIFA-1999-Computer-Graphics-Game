//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_CAMERA_H
#define CPT205_CAMERA_H


#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "Helper.h"

#define Z_NEAR_MIN 3.0f
#define Z_NEAR_MAX 3.9f
#define Z_NEAR_STEP 0.01f

#define EYE_X_MIN (-1.0f)
#define EYE_X_MAX 1.0f
#define EYE_X_STEP 0.01f

#define EYE_Y_MIN (-1.0f)
#define EYE_Y_MAX 1.0f
#define EYE_Y_STEP 0.01f

#define EYE_Z_MIN (-1.0f)
#define EYE_Z_MAX 1.88f
#define EYE_Z_STEP 0.01f
#define EYE_STEP 0.01f

#define CENTER_X_STEP EYE_X_STEP
#define CENTER_Y_STEP EYE_Y_STEP
#define CENTER_Z_STEP EYE_Z_STEP


class Camera {
public:
    Camera();

    ~Camera();

    void ZoomIn();

    void ZoomOut();

    void MoveForward();

    void MoveBackward();

    void MoveDown();

    void MoveUp();

    void MoveLeft();

    void MoveRight();

    void Rotate(int dt_x, int dt_y);

    void Reset();

    void Apply();

private:
    float fov_;
    float eye_x_, eye_y_, eye_z_;
    float aspect_ratio_;
    float z_near_, z_far_;
    float center_x_, center_y_, center_z_;
    float yaw_, pitch_;

    void MoveForwardBackward(float velocity);
};


#endif //CPT205_CAMERA_H
