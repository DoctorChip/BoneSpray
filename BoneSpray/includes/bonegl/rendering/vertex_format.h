#pragma once
#include "glm\glm.hpp"

namespace rendering
{
	struct vertex_format
	{
		glm::vec3 position;
		glm::vec4 color;

		vertex_format(const glm::vec3 &pos, const glm::vec4 &iColor)
		{
			position = pos;
			color = iColor;
		}

		vertex_format() {}
	};
}