#pragma once
#include <map>
#include "stdafx.h"
#include "bonegl_shader_manager.h"
#include "bonegl/rendering/render_object.h"
#include "bonegl/rendering/models/triangle.h"

using namespace rendering;

namespace man
{
	class models_manager
	{
	public:
		models_manager();
		~models_manager();

		void draw();
		void update();
		void delete_model(const std::string& model_name);
		const render_object& get_model(const std::string& model_name) const;

	private:
		std::map<std::string, render_object*> model_list;
	};
}