//
// Created by jonathan on 12/10/22.
//

#include "Assessment2/include/Transform.h"

Transform::Transform() : position(0,0,0), rotation(0, 0, 0), scale(1, 1, 1){}

Transform::Transform(float x, float y, float z): position(x, y, z), rotation(0, 0, 0), scale(1, 1, 1){}