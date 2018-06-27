#include "stdafx.h"
#include "bonegl/rendering/models/model.h"

using namespace rendering;
using namespace models;

model::model() {}

model::~model()
{
	destroy();
}

void model::draw() {}

void model::update() {}

void model::set_program(GLuint program)
{
	this -> program = program;
}

GLuint model::get_vao() const
{
	return vao;
}

const std::vector<GLuint>& model::get_vbos() const
{
	return vbos;
}

void model::destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}