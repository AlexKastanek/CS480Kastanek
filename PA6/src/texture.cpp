//
// Created by mari on 10/3/18.
//
#include "texture.h"

Texture::Texture()
{
	//m_image = new Magick::Image(filename);
}

Texture::~Texture()
{

}

bool Texture::LoadTexture(string filename)
{

	Magick::Image* image;

	try
	{
		image = new Magick::Image(filename);
	}
	catch (Magick::Error& error)
	{
		cout << "ERROR: Could not load texture '" 
			 << filename << "': " << error.what()
			 << endl;
		return false;
	}

	image->flop();
	image->write(&m_blob, "RGBA");

	glGenTextures(1, &m_TB);
	glBindTexture(GL_TEXTURE_2D, m_TB);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		image->columns(),
		image->rows(),
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		m_blob.data());

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	delete image;

	return true;
}

void Texture::Bind(GLenum TextureUnit)
{
    glActiveTexture(TextureUnit);
    glBindTexture(GL_TEXTURE_2D, m_TB);
}