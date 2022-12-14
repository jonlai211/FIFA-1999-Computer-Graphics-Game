//
// Created by jonathan on 12/7/22.
//

#define STB_IMAGE_IMPLEMENTATION
#include "Assessment2/include/stb_image.h"
#include "Assessment2/include/Texture.h"

Texture::Texture(const char *path) {
    stbi_set_flip_vertically_on_load(true);
    data_ = stbi_load(path, &width_, &height_, &channels_, 0 );
}


void Texture::Load() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);

    // Set texture processing methods
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data_) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, data_);
    } else {
        LOGE("Failed to load texture");
        return;
    }
    stbi_image_free(data_);
    glDisable(GL_TEXTURE_2D);
}

GLuint Texture::GetID() {
    return id_;
}

Texture::~Texture() {
    glDeleteTextures(1, &id_);
}