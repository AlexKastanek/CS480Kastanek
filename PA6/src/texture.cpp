//
// Created by mari on 10/3/18.
//
#include "texture.h"

void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    //glBindTexture(m_textureTarget, m_textureObj);
}