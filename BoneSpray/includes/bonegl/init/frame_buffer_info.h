#pragma once
#include "stdafx.h"
#include "GL/glew.h"
#include "GL/freeglut.h"

namespace core
{
	struct frame_buffer_info
	{
		unsigned int flags;
		bool msaa;

		frame_buffer_info()
		{
			flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
			msaa = false;
		}

		frame_buffer_info(bool color, bool depth, bool stencil, bool msaa)
		{
			flags = GLUT_DOUBLE;

			if (color)
				flags |= GLUT_RGBA | GLUT_ALPHA;
			if (depth)
				flags |= GLUT_DEPTH;
			if (stencil)
				flags |= GLUT_STENCIL;
			if (msaa)
				flags |= GLUT_MULTISAMPLE;
			
			this->msaa = msaa;
		}

		frame_buffer_info(const frame_buffer_info& info)
		{
			flags = info.flags;
			msaa = info.msaa;
		}

		void operator=(const frame_buffer_info& info)
		{
			flags = info.flags;
			msaa = info.msaa;
		}
	};
}