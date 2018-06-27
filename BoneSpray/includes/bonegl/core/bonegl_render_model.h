#ifndef DEFINE_RENDER_MODELS_H
#define DEFINE_RENDER_MODELS_H

#pragma once
#include "stdafx.h"
#include "GL/glew.h"
#include "GL/freeglut.h"
#include "bonegl_models.h"
#include <vector>
#include <map>

namespace rm 
{
	struct RenderModel
	{
		unsigned int vao;

		std::vector<unsigned int> vbos;

		RenderModel() {}
	};

	class RenderModels
	{
	public:

		RenderModels();

		~RenderModels();

		void CreateTriangleModel(const std::string& gameModelName);

		void DeleteModel(const std::string& gameModelName);

		unsigned int GetModel(const std::string& gameModelName);

	private:
		std::map<std::string, RenderModel> ModelList;
	};
}

#endif