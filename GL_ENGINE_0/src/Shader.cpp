#include "Shader.h"



Shader::Shader(const char * vertex_filename, const char * fragment_filename)
{
	std::ifstream vertex_file_stream, fragment_file_stream;
	std::stringstream ss;

	vertex_file_stream.exceptions(std::fstream::failbit | std::fstream::badbit);
	fragment_file_stream.exceptions(std::fstream::failbit | std::fstream::badbit);

	try
	{
		vertex_file_stream.open(vertex_filename, std::fstream::_Nocreate | std::fstream::_Noreplace);
		fragment_file_stream.open(fragment_filename, std::fstream::_Nocreate | std::fstream::_Noreplace);

		ss << vertex_file_stream.rdbuf();
		this->m_vertex_source =  ss.str();
		
		ss.str(std::string());
		ss << fragment_file_stream.rdbuf();
		this->m_fragment_source = ss.str();

		vertex_file_stream.close();
		fragment_file_stream.close();

		if (this->Compile())
			if (!this->Assemble())
				throw std::exception("Cannot assemble shader program");

	}
	catch (const std::fstream::failure& e)
	{
		std::cerr << "Error while open shader file" << std::endl
			<< e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}




bool Shader::Compile()
{
	bool compile_vertex_status, compile_fragment_status;

	
	this->m_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	this->m_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vs = this->m_vertex_source.c_str();
	const char* fs = this->m_fragment_source.c_str();


	int vs_length = this->m_vertex_source.length();
	int fs_length = this->m_fragment_source.length();

	glShaderSource(this->m_vertex_shader, 1, &vs, &vs_length);
	glShaderSource(this->m_fragment_shader, 1, &fs, &fs_length);

	glCompileShader(this->m_vertex_shader);
	compile_vertex_status = check_shader_source_compilation(this->m_vertex_shader, "Error while compiling vertex shader");

	glCompileShader(this->m_fragment_shader);
	compile_fragment_status = check_shader_source_compilation(this->m_fragment_shader, "Error while compiling fragment shader");
	
	return   compile_fragment_status && compile_vertex_status;
}


bool Shader::Assemble() 
{
	bool link_program_status, validate_program_status;


	this->m_program = glCreateProgram();
	glAttachShader(this->m_program, this->m_vertex_shader);
	glAttachShader(this->m_program, this->m_fragment_shader);

	glLinkProgram(this->m_program);
	link_program_status = check_shader_program_linking(this->m_program, "Error while linking program/shader");


	glValidateProgram(this->m_program);
	validate_program_status = check__shader_program_validation(this->m_program, "Error while validating program");

	return link_program_status && validate_program_status;
}	


void Shader::UseProgram()
{
	glUseProgram(this->m_program);
}

Shader::~Shader()
{
	glDetachShader(this->m_program, this->m_vertex_shader);
	glDetachShader(this->m_program, this->m_fragment_shader);


	glDeleteShader(this->m_vertex_shader);
	glDeleteShader(this->m_fragment_shader);
	glDeleteProgram(this->m_program);
}
