#include "Texture.h"
#include <cassert>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



Texture::Texture(const char * filename)
{
	int width, height,  num_component;
	unsigned char * image_data =  stbi_load(filename, &width, &height, &num_component, 4);

	if (image_data == NULL)
		std::cerr << "error while loading texture file...." << std::endl;

	glGenTextures(1, &(this->m_texture));
	glBindTexture(GL_TEXTURE_2D, this->m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, static_cast<void *>(image_data));
	glBindTexture(GL_TEXTURE_2D, 0);
	
	stbi_image_free(image_data);
}

void Texture::Bind(unsigned int texture_number)
{
	assert(texture_number >= 0 && texture_number <= 31);


	glActiveTexture(GL_TEXTURE0 + texture_number);
	glBindTexture(GL_TEXTURE_2D, this->m_texture);
}


Texture::~Texture()
{
	glDeleteTextures(1, &(this->m_texture));
}
