#pragma once
#include <GLM/glm.hpp>

class Vertex
{
public:
	Vertex(float pos_x, float pos_y, float pos_z);
	Vertex(
		float pos_x, float pos_y, float pos_z, 
		float color_r, float color_g, float color_b, float color_a
	);
	Vertex(
		float pos_x, float pos_y, float pos_z,
		float color_r, float color_g, float color_b, float color_a,
		float tex_u, float tex_v
	);
	virtual ~Vertex();

	float get_x() const { return x; }
	float get_y() const { return y; }
	float get_z() const { return z; }

	float get_r() const { return r; }
	float get_g() const { return g; }
	float get_b() const { return b; }
	float get_a() const { return a; }
	
	float get_u() const { return u; }
	float get_v() const { return v; }


private:
	float x, y, z, r, g, b, a, u, v;
};

