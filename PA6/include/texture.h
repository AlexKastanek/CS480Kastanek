//
// Created by mari on 10/3/18.
//
#ifndef PA6_TEXTURE_H
#define PA6_TEXTURE_H

#include <Magick++.h>
#include "graphics_headers.h"
#include <string>

using namespace std;
class Texture
{
public:
    Texture(GLenum TextureTarget, const string& FileName);
    bool Load();
    void Bind(GLenum TextureUnit);
};

#endif //PA6_TEXTURE_H