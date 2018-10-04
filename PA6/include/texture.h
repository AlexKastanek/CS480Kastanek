//
// Created by mari on 10/3/18.
//
#ifndef PA6_TEXTURE_H
#define PA6_TEXTURE_H

#include <Magick++.h>
#include "graphics_headers.h"
#include <vector>
#include <string>

using namespace std;

class Texture
{
public:
    Texture();
    ~Texture();

    bool LoadTexture(string filename);
    void Bind(GLenum TextureUnit);

private:
	Magick::Image* m_image;
	Magick::Blob m_blob;

	GLuint m_TB;
};

#endif //PA6_TEXTURE_H