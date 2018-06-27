#include "stdafx.h"
#include "bonegl/init/init_glew.h"
#include <iostream>

using namespace core;

void init_glew::init()
{
	glewExperimental = true;

	if (glewInit() == GLEW_OK)
	{
		std::cout << "GLEW initalised..." << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_3"))
	{
		std::cout << "GLEW version is 4.3..." << std::endl;
	}
	else
	{
		std::cout << "GLEW version 4.3 is not supported!" << std::endl;
	}
}