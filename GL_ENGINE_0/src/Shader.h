#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "GL/glew.h"
#include "Common.h"


class Shader
{
public:
	Shader(const char*  vertex_filename, const char*  fragment_filename);
	void UseProgram();
	virtual ~Shader();

private:
	GLuint m_program;
	GLuint m_vertex_shader;
	GLuint m_fragment_shader;


	std::string m_vertex_source;
	std::string m_fragment_source;


	bool Compile();
	bool Assemble();
};

