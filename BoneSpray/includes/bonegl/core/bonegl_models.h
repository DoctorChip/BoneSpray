#ifndef  DEFINE_BONEGLMODEL_H
#define  DEFINE_BONEGLMODEL_H

#include "glm\glm.hpp"

struct vertex_format_t
{
	glm::vec3 position;
	glm::vec4 color;

	vertex_format_t(const glm::vec3 &pos, const glm::vec4 &iColor)
	{
		position = pos;
		color = iColor;
	}
};

#endif