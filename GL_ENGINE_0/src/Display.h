#pragma once
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Display
{
public:
	Display();
	Display(int width, int height, const std::string& title);
	virtual ~Display();


	bool IsClosed();
	void Update();
	void ClearDisplay(float red, float green, float blue, float alpha);

	int GetHeight() const { return m_height; }
	int GetWidth() const { return m_width; }


private:
	Display(const Display& rhs);
	Display& operator=(const Display& display) {}
	
	GLFWwindow * m_window;

	std::string m_title;
	bool m_isClosed;
	int m_width;
	int m_height;
};

