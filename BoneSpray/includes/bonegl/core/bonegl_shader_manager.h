#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "stdafx.h"
#include "GL/glew.h"
#include "GL/freeglut.h"

namespace man 
{

	class shader_manager
	{

	public:

		shader_manager(void);

		~shader_manager(void);

		void create_program(const std::string& shader_name,	const std::string& vertex_shader_filename, const std::string& fragment_shader_filename);

		static const GLuint get_shader(const std::string&);

	private:

		std::string read_shader(const std::string& filename);

		GLuint create_shader(GLenum shader_type,	const std::string& source, const std::string& shader_name);

		static std::map<std::string, GLuint> programs;
	};
}