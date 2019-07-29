#include "Display.h"



Display::Display()
	:m_window(NULL), m_isClosed(true), m_height(0), m_width(0), m_title("")
{
}


Display::Display(int width, int height, const std::string & title)
	:m_window(NULL), m_isClosed(true) , m_height(height), m_width(width), m_title(title)
{
	int initialized = glfwInit();
	if (initialized != GLFW_TRUE) 
		std::cerr << "Unable to create display, error while initialize glfw library" << std::endl;

	else
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(this->m_window);

		GLenum statut = glewInit();
		if (statut != GLEW_OK)
		{
			std::cerr << "Unable to create display, error while glew library" << std::endl;
			glfwDestroyWindow(this->m_window);
			glfwTerminate();

			this->m_window = NULL;
			this->m_height = 0;
			this->m_width = 0;
			this->m_isClosed = true;
			this->m_title = "";
		}
		
	}
}

Display::Display(const Display & rhs)
{
		 //todo
}



bool Display::IsClosed() 
{
	if (this->m_window != NULL)
		this->m_isClosed = glfwWindowShouldClose(this->m_window) != 0 ? true : false;
	
	return this->m_isClosed;
}

void Display::Update()
{
	glfwGetFramebufferSize(this->m_window, &(this->m_width), &(this->m_height));
	glViewport(0, 0, this->m_width, this->m_height);
	glfwSwapBuffers(this->m_window);
	glfwPollEvents();
}

void Display::ClearDisplay(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}



Display::~Display()
{
	glfwDestroyWindow(this->m_window);
	glfwTerminate();
}