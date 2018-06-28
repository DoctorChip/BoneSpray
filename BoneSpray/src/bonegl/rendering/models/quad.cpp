#include "stdafx.h"
#include "bonegl/rendering/models/quad.h"

using namespace rendering;
using namespace models;

quad::quad() {}

quad::~quad() {}

void quad::create()
{
	GLuint vao;
	GLuint vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<vertex_format> vertices;
	vertices.push_back(vertex_format(glm::vec3(-0.25, 0.5, 0.0),//pos
		glm::vec4(1, 0, 0, 1)));   //color
	vertices.push_back(vertex_format(glm::vec3(-0.25, 0.75, 0.0),//pos
		glm::vec4(0, 0, 0, 1)));   //color
	vertices.push_back(vertex_format(glm::vec3(0.25, 0.5, 0.0),  //pos
		glm::vec4(0, 1, 0, 1)));   //color
								   //4th vertex
	vertices.push_back(vertex_format(glm::vec3(0.25, 0.75, 0.0),//pos
		glm::vec4(0, 0, 1, 1)));   //color

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);            //here we have 4
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_format) * 4, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(vertex_format), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(vertex_format),
		(void*)(offsetof(vertex_format, vertex_format::color)));
	glBindVertexArray(0);

	this->vao = vao;
	this->vbos.push_back(vbo);
}

void quad::update()
{
}

void quad::draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}