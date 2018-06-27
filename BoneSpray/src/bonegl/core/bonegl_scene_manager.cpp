#include "stdafx.h"
#include "bonegl/core/bonegl_scene_manager.h"
#include "bonegl/core/bonegl_shader_manager.h"

using namespace man;

scene_manager::scene_manager()
{
	glEnable(GL_DEPTH_TEST);

	shader_man = new shader_manager();

	shader_man -> create_program(
		"colorShader",
		"Shaders\\Vertex_Shader.glsl",
		"Shaders\\Fragment_Shader.glsl");
	
	models_man = new models_manager();
}

scene_manager::~scene_manager()
{
	delete shader_man;
	delete models_man;
}

void scene_manager::notify_begin_frame()
{
	models_man -> update();
}

void scene_manager::notify_display_frame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	models_man -> draw();
}

void scene_manager::notify_end_frame()
{
}

void scene_manager::notify_reshape(int width, int height, int previous_width, int previous_height)
{
}