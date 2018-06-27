#pragma once
#include "stdafx.h"
#include <string>

namespace core
{
	struct window_info
	{
		char* name;
		int width, height;
		int position_x, position_y;
		bool is_reshapable;

		window_info()
		{
			name = (char*)"OpenGL";
			width = 800; height = 600;
			position_x = 300;
			position_y = 300;
			is_reshapable = true;
		}

		window_info(char * name, int start_position_x, int start_position_y, int width, int height, bool is_reshapable)
		{
			this->name = name;
			this->position_x = start_position_x;
			this->position_y = start_position_y;

			this->width = width;
			this->height = height;
			this->is_reshapable = is_reshapable;
		}

		window_info(const window_info& windowInfo)
		{
			name = windowInfo.name;
			position_x = windowInfo.position_x;
			position_y = windowInfo.position_y;

			width = windowInfo.width;
			height = windowInfo.height;
			is_reshapable = windowInfo.is_reshapable;
		}

		void operator=(const window_info& windowInfo)
		{
			name = windowInfo.name;

			position_x = windowInfo.position_x;
			position_y = windowInfo.position_y;

			width = windowInfo.width;
			height = windowInfo.height;
			is_reshapable = windowInfo.is_reshapable;
		}
	};
}