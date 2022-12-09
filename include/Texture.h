//
// Created by jonathan on 12/7/22.
//

#ifndef CPT205_TEXTURE_H
#define CPT205_TEXTURE_H
#define FREEGLUT_STATIC

#include <GL/freeglut.h>
#include <cstdio>

#include "Assessment2/include/Helper.h"

class Texture {
public:
    Texture(const char *path);

    ~Texture();

    void Load();

    GLuint GetID();

private:
    GLuint id_;
    GLint width_, height_, channels_;
    unsigned char *data_;
};


#endif //CPT205_TEXTURE_H
