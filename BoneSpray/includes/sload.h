#ifndef DEFINE_SLOADER_H
#define DEFINE_SLOADER_H

#include "stdafx.h"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>

namespace bonegl
{

	class SLoader
	{
		private:

			std::string ReadShader(const char *filename);

			GLuint CreateShader(GLenum shaderType, std::string source, const char* shaderName);

		public:

			SLoader(void);

			~SLoader(void);

			GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);

	};
}

#endif