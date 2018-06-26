
#include "stdafx.h"
#include "bonegl_render_model.h"
#include "bonegl_models.h"
using namespace rm;

RenderModels::RenderModels()
{
}

RenderModels::~RenderModels()
{
	std::map<std::string, RenderModel>::iterator it;
	for (it = ModelList.begin(); it != ModelList.end(); ++it)
	{
		//delete VAO and VBOs (if many)
		unsigned int* p = &it->second.vao;
		glDeleteVertexArrays(1, p);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}
	ModelList.clear();
}

void RenderModels::CreateTriangleModel(const std::string& gameModelName)
{
	unsigned int vao;
	unsigned int vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<vertex_format_t> vertices;//our vertex positions
	vertices.push_back(vertex_format_t(glm::vec3(0.25, -0.25, 0.0),
		glm::vec4(1, 0, 0, 1))); //red
	vertices.push_back(vertex_format_t(glm::vec3(-0.25, -0.25, 0.0),
		glm::vec4(0, 1, 0, 1))); //green
	vertices.push_back(vertex_format_t(glm::vec3(0.25, 0.25, 0.0),
		glm::vec4(0, 0, 1, 1))); //blue

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_format_t) * 3, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_format_t), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex_format_t), (void*)12);

	RenderModel myModel;                            //is allocated on Stack
	myModel.vao = vao;                        //add vao
	myModel.vbos.push_back(vbo);              //add vbo
	ModelList[gameModelName] = myModel;  //add to std::map

}

void RenderModels::DeleteModel(const std::string& gameModelName)
{
	RenderModel model = ModelList[gameModelName];
	unsigned int p = model.vao;
	glDeleteVertexArrays(1, &p);
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);
	model.vbos.clear();
	ModelList.erase(gameModelName);

}

unsigned int RenderModels::GetModel(const std::string& gameModelName)
{
	return ModelList[gameModelName].vao;
}