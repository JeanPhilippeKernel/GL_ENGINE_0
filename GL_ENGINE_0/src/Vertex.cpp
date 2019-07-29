#include "Vertex.h"


Vertex::Vertex(float pos_x, float pos_y, float pos_z)
	:x(pos_x), y(pos_y), z(pos_z)
{
}

Vertex::Vertex(float pos_x, float pos_y, float pos_z, float color_r, float color_g, float color_b, float color_a)
	:Vertex(pos_x, pos_y, pos_z)
{
	r = color_r;
	g = color_g;
	b = color_b;
	a = color_a;
}

Vertex::Vertex(float pos_x, float pos_y, float pos_z, float color_r, float color_g, float color_b, float color_a, float tex_u, float tex_v)
	:Vertex(pos_x, pos_y, pos_z, color_r, color_g, color_b, color_a)
{
	u = tex_u;
	v = tex_v;
}

Vertex::~Vertex()
{
}
