#include "stdafx.h"
#include "bonegl/core/bonegl_shader_manager.h"
#include <iostream>

using namespace man;

std::map<std::string, GLuint> shader_manager::programs;

shader_manager::shader_manager(void)
{
}

shader_manager::~shader_manager(void)
{
	std::map<std::string, GLuint>::iterator i;

	for (i = programs.begin(); i != programs.end(); ++i)
	{
		GLuint pr = i->second;
		glDeleteProgram(pr);
	}

	programs.clear();
}

std::string shader_manager::read_shader(const std::string& filename)
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (!file.good())
	{
		std::cout << "Can't read file " << filename.c_str() << std::endl;
		std::terminate();
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();
	return shaderCode;
}

GLuint shader_manager::create_shader(GLenum shader_type, const std::string& source, const std::string& shader_name)
{
	int compile_result = 0;

	GLuint shader = glCreateShader(shader_type);
	const char *shader_code_ptr = source.c_str();
	const int shader_code_size = source.size();

	glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);

	if (compile_result == GL_FALSE)
	{

		int info_log_length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> shader_log(info_log_length);
		glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
		std::cout << "ERROR compiling shader: " << shader_name.c_str() << std::endl << &shader_log[0] << std::endl;
		return 0;
	}
	return shader;
}

void shader_manager::create_program(const std::string& shaderName, const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename)
{
	//read the shader files and save the code
	std::string vertex_shader_code = read_shader(vertexShaderFilename);
	std::string fragment_shader_code = read_shader(fragmentShaderFilename);

	GLuint vertex_shader = create_shader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
	GLuint fragment_shader = create_shader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

	int link_result = 0;
	//create the program handle, attatch the shaders and link it
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_result);

	//check for link errors
	if (link_result == GL_FALSE)
	{

		int info_log_length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
		std::vector<char> program_log(info_log_length);
		glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
		std::cout << "Shader Loader : LINK ERROR" << std::endl << &program_log[0] << std::endl;
		return;
	}
	programs[shaderName] = program;
}

const GLuint shader_manager::get_shader(const std::string& shader_name)
{
	return programs.at(shader_name);
}