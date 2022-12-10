//
// Created by jonathan on 12/10/22.
//

#ifndef CPT205_TRANSFORM_H
#define CPT205_TRANSFORM_H

#include "Vector3.h"


class Transform {
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    Transform();

    Transform(float x, float y, float z);
};


#endif //CPT205_TRANSFORM_H
