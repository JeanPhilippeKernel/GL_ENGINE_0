#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"



int main(int argc, const char* argv[])
{

	std::unique_ptr<Display> display_ptr(
		new Display(1000, 700, "OPENGL ENGINE")
	);

	Shader shader("shaders\\triangle\\basic_vertex.vert", "shaders\\triangle\\basic_fragment.frag");
	

	std::vector<Vertex> vertices{
		Vertex(0.0f, 0.5f, 0.0f,	0.0f, 0.0f, 0.0f, 0.0f,		1.0f, 1.0f),
		Vertex(0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 0.0f, 0.0f,		0.0f, 1.0f),
		Vertex(-0.5f, -0.5f, 0.0f,	0.0f, 0.0f, 0.0f, 0.0f,		0.0f, 0.0f),
	};
											
	Mesh triangle(vertices);
	Texture texture("assets\\bricks.jpg");


	while (!display_ptr->IsClosed())
	{
		display_ptr->ClearDisplay(0.0f, .2f, 0.23f, 1.0f);
		
		
		shader.UseProgram();
		texture.Bind();
		triangle.Draw();
		
		
		display_ptr->Update();
	}

	return EXIT_SUCCESS;
}