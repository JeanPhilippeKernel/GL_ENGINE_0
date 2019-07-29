#pragma once
#include <vector> 
#include <algorithm>
#include <GL/glew.h>
#include <GLM/vec3.hpp>

#include "Vertex.h"


class Mesh
{
public:
	Mesh(const std::vector<Vertex>& vertices);
	void Draw();
	virtual ~Mesh();


private:
	GLuint m_vertex_buffer_object;
	GLuint m_vertex_array_object;

	std::vector<Vertex> m_vertices;
};

