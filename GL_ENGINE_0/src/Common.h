#pragma once
#include <iostream>
#include <GL/glew.h>


inline bool check_shader_source_compilation(GLuint shader, const char*  message, GLuint flag = GL_COMPILE_STATUS)
{
	GLint state;
	GLchar error[1024] = { 0 };

	glGetShaderiv(shader, flag, &state);
	if (state == GL_FALSE)
	{
		glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		std::cerr << message << ". " << error << std::endl;
	}
	return state; 
}


inline bool check_shader_program_linking(GLuint program, const char*  message, GLuint flag = GL_LINK_STATUS)
{
	GLint state;
	GLchar error[1024] = { 0 };

	glGetProgramiv(program, flag, &state);
	if (state == GL_FALSE)
	{
		glGetProgramInfoLog(program, sizeof(error), NULL, error);
		std::cerr << message << ". " << error << std::endl;
	}
	return state;
}

inline bool check__shader_program_validation(GLuint program, const char*  message, GLuint flag = GL_VALIDATE_STATUS)
{
	GLint state;
	GLchar error[1024] = { 0 };

	glGetProgramiv(program, flag, &state);
	if (state == GL_FALSE)
	{
		glGetProgramInfoLog(program, sizeof(error), NULL, error);
		std::cerr << message << ". " << error << std::endl;
	}
	return state;
}

