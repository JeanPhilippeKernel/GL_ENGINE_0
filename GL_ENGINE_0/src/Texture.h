#pragma once
#include <GL/glew.h>




class Texture
{
public:
	Texture(const char * filename);
	void Bind(unsigned int texture_number = 0);
	virtual ~Texture();

private :
	GLuint m_texture;
};

