#pragma once
#include "stdafx.h"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "vertex_format.h"
#include <vector>
#include <iostream>

namespace rendering
{
	class render_object
	{

	public:
		virtual ~render_object() = 0;

		virtual void draw() = 0;

		virtual void update() = 0;

		virtual void set_program(GLuint shaderName) = 0;

		virtual void destroy() = 0;

		virtual GLuint get_vao() const = 0;

		virtual const std::vector<GLuint>& get_vbos() const = 0;
	};

	inline render_object::~render_object() {}
}