#include "stdafx.h"
#include "bonegl/core/bonegl_model_manager.h"

using namespace man;
using namespace rendering;

models_manager::models_manager()
{
	models::triangle* triangle = new models::triangle();
	triangle -> set_program(shader_manager::get_shader("colorShader"));
	triangle -> create();
	model_list["triangle"] = triangle;

	models::quad* quad = new models::quad();
	quad -> set_program(shader_manager::get_shader("colorShader"));
	quad ->create();
	model_list["quad"] = quad;
}

models_manager::~models_manager()
{
	for (auto model : model_list)
	{
		delete model.second;
	}

	model_list.clear();
}

void models_manager::delete_model(const std::string& model_name)
{
	render_object* model = model_list[model_name];
	model->destroy();
	model_list.erase(model_name);
}

const render_object& models_manager::get_model(const std::string& model_name) const
{
	return (*model_list.at(model_name));
}

void models_manager::update()
{
	for (auto model : model_list)
	{
		model.second->update();
	}
}

void models_manager::draw()
{
	for (auto model : model_list)
	{
		model.second->draw();
	}
}