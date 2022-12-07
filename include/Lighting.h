//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_LIGHTING_H
#define CPT205_LIGHTING_H


#include <GL/freeglut.h>

#include "Helper.h"

#define BRIGHTNESS_STEP 0.01
#define BRIGHTNESS_MAX 0.5
#define BRIGHTNESS_MIN -1.0

class Lighting {
public:
    Lighting();

    void Brighter();
    void Darker();
    LightingMode GetMode();
    void SetMode(LightingMode mode);
    float GetBrightness();
    void SetBrightness(float brightness);
    void Apply();

private:
    float brightness_;
    LightingMode mode_;

};


#endif //CPT205_LIGHTING_H
