#include "Mesh.h"


Mesh::Mesh(const std::vector<Vertex>& vertices)
	:m_vertices(vertices)
{
	std::vector<float> raw_vertice;
	std::for_each(
		this->m_vertices.begin(),
		this->m_vertices.end(), [&raw_vertice](const Vertex& v) { 
			raw_vertice.push_back(v.get_x()); 
			raw_vertice.push_back(v.get_y()); 
			raw_vertice.push_back(v.get_z()); 

			raw_vertice.push_back(v.get_r());
			raw_vertice.push_back(v.get_g());
			raw_vertice.push_back(v.get_b());
			raw_vertice.push_back(v.get_a());

			raw_vertice.push_back(v.get_u());
			raw_vertice.push_back(v.get_v());
		});

	glGenVertexArrays(1, &(this->m_vertex_array_object));
	glBindVertexArray(this->m_vertex_array_object);

	glGenBuffers(1, &(this->m_vertex_buffer_object));
	glBindBuffer(GL_ARRAY_BUFFER, this->m_vertex_buffer_object);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * raw_vertice.size(), raw_vertice.data(),  GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void *)0);


	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void *)(sizeof(float) * 3));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void *)(sizeof(float) * 7));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::Draw()
{
	glBindVertexArray(this->m_vertex_array_object);
	glDrawArrays(GL_TRIANGLES, 0, this->m_vertices.size());
	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &(this->m_vertex_array_object));
}
